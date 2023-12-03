# Tarea_S.O_GRUPO_18
INTEGRANTES: -JORGE MARTINEZ &amp; LUKAS SANHUEZA
# ProcesadorThreaded README

## Introducción

Este es un procesador de imágenes en C++ utilizando la biblioteca OpenCV y multihilos para mejorar la eficiencia del procesamiento. El código está organizado en dos archivos: `procesador_threaded.h` y `procesador_threaded.cpp`. La clase `ProcesadorThreaded` se encarga de cargar una imagen, aplicar un filtro de escala de grises y guardar la imagen resultante.

## Uso

1. **Incluir bibliotecas**: Asegúrate de tener OpenCV instalado y las bibliotecas necesarias incluidas al principio del programa.

```cpp
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <chrono>
```

2. **Definir la clase `ProcesadorThreaded`**: La clase se inicializa con el nombre del archivo de entrada, el nombre del archivo de salida y el número de hilos a utilizar.

```cpp
ProcesadorThreaded procesador("input.jpg", "output.jpg", 4);
```

3. **Procesar la imagen**: Llama al método `procesar_imagen()` para aplicar el filtro de escala de grises utilizando múltiples hilos.

```cpp
procesador.procesar_imagen();
```

4. **Resultados**: La imagen procesada se guardará con el nombre de archivo especificado en la instancia de la clase.

## Detalles de implementación

- La clase `ProcesadorThreaded` carga la imagen en color desde el archivo de entrada utilizando OpenCV.
- Divide la imagen en secciones para que cada hilo procese una parte específica.
- Se utiliza la fórmula estándar para convertir un píxel de color a escala de grises.
- Se mide el tiempo de ejecución para evaluar el rendimiento.

## Compilación

Asegúrate de compilar el programa con el soporte de C++11 o superior para habilitar las características de multihilo. Un ejemplo de compilación con g++ sería:

```bash
g++ -std=c++11 procesador_threaded.cpp -o procesador_threaded -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui
```

## Ejecución

Ejecuta el programa compilado:

```bash
./procesador_threaded
```

Observa la salida que indica el progreso y el tiempo de ejecución. La imagen procesada se guardará con el nombre especificado.

Este README proporciona una visión general del código y cómo usarlo. Personaliza según tus necesidades y requisitos específicos. ¡Disfruta procesando imágenes de manera eficiente con hilos!
