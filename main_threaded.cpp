#include <iostream>
#include "procesador_threaded.h"	

int main(int const argc, char const** argv){
	int numero_hebras = std::stoi(argv[3]);

	ProcesadorThreaded procesador(argv[1],argv[2],numero_hebras);
	procesador.procesar_imagen();
}
