#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <chrono>

class ProcesadorThreaded {
public:
	ProcesadorThreaded(const std::string& input_nombre, const std::string& output_nombre, const int& numero_threads);
	void procesar_imagen();
private:
	cv::Mat im;
	std::string output;
	int n_threads;
	int width;
	void computar_thread(int inicio, int fin);
	void pixel_a_gris(int c, int r); 
};
