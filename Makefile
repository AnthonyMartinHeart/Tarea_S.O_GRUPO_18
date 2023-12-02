CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -pedantic -O3
LIBS=`pkg-config --cflags --libs opencv4`

all: main

main: main.cpp image_processing.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f main
