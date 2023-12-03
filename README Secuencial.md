# Procesamiento Secuencial README

# Uso

1. **Incluir bibliotecas**: Asegúrate de tener OpenCV instalado y las bibliotecas necesarias incluidas al principio del programa.

```cpp
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <chrono>
```

2. **Definir y llamar la función `procesar_secuencial`**: La función toma el nombre del archivo de entrada y el nombre del archivo de salida como parámetros.

```cpp
procesar_secuencial("input.jpg", "output.jpg");
```

3. **Resultados**: La imagen procesada se guardará con el nombre de archivo especificado.

## Detalles de implementación

- La función `procesar_secuencial` carga la imagen en color desde el archivo de entrada utilizando OpenCV.
- Itera sobre cada píxel de la imagen y aplica la fórmula estándar para convertir un píxel de color a escala de grises.
- Mide el tiempo de ejecución para evaluar el rendimiento.
- Opcionalmente, se puede visualizar la imagen en escala de grises utilizando las funciones comentadas `imshow` y `waitKey`.

## Compilación

Asegúrate de compilar el programa con el soporte de C++11 o superior y vincula las bibliotecas de OpenCV. Un ejemplo de compilación con g++ sería:

```bash
g++ -std=c++11 procesamiento_secuencial.cpp -o procesamiento_secuencial -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui
```

## Ejecución

Ejecuta el programa compilado:

```bash
./procesamiento_secuencial input.jpg output.jpg
```

Observa la salida que indica el progreso y el tiempo de ejecución. La imagen procesada se guardará con el nombre especificado.

