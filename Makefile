LIBS = 'pkg-config --cflags --libs opencv'


all: threaded secuencial

secuencial:
	g++ -m64 -o main_secuencial main_secuencial.cpp -I/usr/include/opencv4 -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui
	chmod +x main_secuencial

threaded:
	g++ -m64 -o main_threaded procesador_threaded.cpp main_threaded.cpp  -I/usr/include/opencv4 -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui
	chmod +x main_threaded


clean:
	rm main_secuencial.cpp


