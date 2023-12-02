#include "image_processing.h"
#include <iostream>
#include <chrono>
#include "/usr/include/opencv4/opencv2/opencv.hpp"
#include <thread>
#include <vector>

void process_image(const std::string& input_image, const std::string& output_image, int num_threads) {
    // Iniciar la medición del tiempo
    auto start_time = std::chrono::high_resolution_clock::now();

    // Cargar la imagen a color usando OpenCV
    cv::Mat image = cv::imread(input_image, cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cerr << "Error al cargar la imagen: " << input_image << std::endl;
        return;
    }

    // Obtener las dimensiones de la imagen
    int rows = image.rows;
    int cols = image.cols;

    // Crear una nueva imagen en escala de grises
    cv::Mat gray_image(rows, cols, CV_8UC1);

    // Calcular el número de filas que cada hebra procesará
    int rows_per_thread = rows / num_threads;

    // Vector para almacenar las hebras
    std::vector<std::thread> threads;

    // Función para convertir RGB a escala de grises utilizando el método de luminosidad
    auto rgb_to_gray = [](const cv::Vec3b& pixel) {
        return 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
    };

    // Bucle para crear y lanzar las hebras
    for (int i = 0; i < num_threads; ++i) {
        int start_row = i * rows_per_thread;
        int end_row = (i == num_threads - 1) ? rows : (start_row + rows_per_thread);

        // Función lambda para el procesamiento de cada hebra
        auto thread_function = [&, start_row, end_row, rgb_to_gray]() {
            // Procesar la parte asignada de la imagen
            for (int r = start_row; r < end_row; ++r) {
                for (int c = 0; c < cols; ++c) {
                    // Aplicar el método de luminosidad para convertir a escala de grises
                    gray_image.at<uchar>(r, c) = static_cast<uchar>(rgb_to_gray(image.at<cv::Vec3b>(r, c)));
                }
            }
        };

        // Crear y almacenar la hebra en el vector
        threads.emplace_back(thread_function);
    }

    // Esperar a que todas las hebras terminen su ejecución
    for (auto& thread : threads) {
        thread.join();
    }

    // Detener la medición del tiempo
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    // Guardar la nueva imagen en escala de grises
    cv::imwrite(output_image, gray_image);

    // Imprimir el tiempo tomado para procesar la imagen
    std::cout << "Tiempo transcurrido: " << duration << " milisegundos" << std::endl;

    // Mostrar la nueva imagen en una ventana llamada "Output"
    cv::imshow("Output", gray_image);
    cv::waitKey(0); // Esperar hasta que el usuario presione una tecla antes de cerrar la ventana
}
