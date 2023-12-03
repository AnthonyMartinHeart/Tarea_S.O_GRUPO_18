#include <iostream>
#include <cmath>
#include <thread>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "procesador_threaded.h"
#include <chrono>
using namespace cv;
using namespace std;
using namespace chrono;


ProcesadorThreaded::ProcesadorThreaded(const string& input_nombre, const  string& output_nombre, const int& numero_threads){
	this->output = output_nombre;
	this->n_threads = numero_threads;
	this->im = imread(input_nombre, IMREAD_COLOR);
	this->width = im.size().width; // size[0]
}

void ProcesadorThreaded::procesar_imagen(){
	vector<thread> threads; // crear un array de threads
	int lineas_por_thread = ceil(im.size().width / n_threads); // calcular cuantas lineas cada threads procesara
	auto tiempo_inicial = steady_clock::now();
	for(int i=0; i < n_threads; i++){
		int inicio = i * lineas_por_thread;  // calcular inicio y fin del rango de procesamiento de cada thread
		int fin =  inicio + lineas_por_thread;
		if(fin>im.size[0]-1){
			fin = im.size[0]-1;
		}
		threads.emplace_back(&ProcesadorThreaded::computar_thread,this, inicio, fin); // inicializar cada thread
	}
	for(auto& t : threads){
		t.join(); // juntar todas las threads cuando terminen
	}
	cout << lineas_por_thread << endl;
	auto tiempo_final = steady_clock::now();
        cout << "Tiempo de ejecucion: " << duration_cast<milliseconds>(tiempo_final-tiempo_inicial).count() << "ms" << endl;
        imwrite(output, im);

}


void ProcesadorThreaded::computar_thread(int inicio, int fin){ // inicio y fin de columna
	for(int c=inicio;c<fin;c++){
		for(int r=0;r<width;r++ ){
			pixel_a_gris(c,r);
		}
	}
}

void ProcesadorThreaded::pixel_a_gris(int c,int r){
	Vec3b pixel = im.at<Vec3b>(c,r);
	int gris = pixel[0]*0.114 + pixel[1]*0.587 + pixel[2]*0.299;
	im.at<Vec3b>(c,r) = Vec3b(gris,gris,gris);
}

