#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <chrono>
#include <omp.h>
using namespace cv;
using namespace std;
using namespace std::chrono;

void procesar_openmp(const string& input_nombre, const  string& output_nombre, int cant_threads){
	cout << "Cargando imagen... " << endl;
	Mat img = imread(input_nombre, IMREAD_COLOR);
	if(img.empty()){
		cout << "No se encontró imagen " << endl;
		return;
	}
	auto t1 = steady_clock::now();
	cout << "Ejecutando... " << endl;

	#pragma omp parallel num_threads(cant_threads)
	{
		#pragma omp for
        	for(int c=0; c<img.size().height;c++){
                	for(int r=0; r<img.size().width;r++){
                        	// pasar por cada pixel en imagen
				Vec3b pixel = img.at<Vec3b>(c,r);
                        	int gris = pixel[0]*0.114 + pixel[1]*0.587 + pixel[2]*0.299;
				img.at<Vec3b>(c,r) = Vec3b(gris,gris,gris);
			}
        	}
	}

	auto t2 = steady_clock::now();
	cout << "Tiempo de ejecucion: " << duration_cast<milliseconds>(t2-t1).count() << "ms" << endl;
	imwrite(output_nombre, img);
}

int main(int const argc, char const** argv){

	int cant_threads = stoi(argv[3]);
	procesar_openmp(argv[1],argv[2], cant_threads);
}
