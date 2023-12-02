#include "image_processing.h"
#include <iostream>
#include <chrono>

int main(int argc, char* argv[]) {

    std::string input_image = "Prueba23.png";  // Nombre del archivo de la imagen en color
    std::string output_image = "mi_imagen_gris.png";  // Nombre del archivo para la imagen en escala de grises

    int num_threads = 4;  // Número de hilos para el procesamiento

    process_image(input_image, output_image, num_threads);
    std::cout << "Loading image..." << std::endl;

    // Inicia el cronómetro
    auto start_time = std::chrono::high_resolution_clock::now();

    // Llama a la función de procesamiento de imágenes
    process_image(input_image, output_image, num_threads);

    // Detiene el cronómetro
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

    std::cout << "Total time spent in seconds is " << duration.count() << std::endl;
     if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " <imagen_color> <imagen_grises> <num_hebras>" << std::endl;
        return 1;
    }

    return 0;
}
