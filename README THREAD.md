# ProcesadorThreaded README y Comentarios

## Descripción general

Este conjunto de archivos implementa un procesador de imágenes en C++ utilizando la biblioteca OpenCV. La clase `ProcesadorThreaded` aplica un filtro de escala de grises a una imagen de manera concurrente utilizando múltiples hilos. El programa principal, `main.cpp`, instancia esta clase y realiza el procesamiento con los parámetros proporcionados por el usuario.

## Clase `ProcesadorThreaded` (procesador_threaded.h y procesador_threaded.cpp)

### Constructor
```cpp
ProcesadorThreaded(const std::string& input_nombre, const std::string& output_nombre, const int& numero_threads);
```
- **Descripción:** Crea una instancia de `ProcesadorThreaded` con los nombres de archivo de entrada y salida, y la cantidad de hilos especificada.
- **Entradas:**
  - `input_nombre`: Nombre del archivo de entrada (debe tener una extensión válida, como .jpg, .png, etc.).
  - `output_nombre`: Nombre del archivo de salida (debe tener una extensión válida, como .jpg, .png, etc.).
  - `numero_threads`: Número de hilos a utilizar.

### Métodos
```cpp
void procesar_imagen();
```
- **Descripción:** Inicia el procesamiento de la imagen utilizando hilos. Divide la imagen en secciones y asigna cada sección a un hilo.

```cpp
void computar_thread(int inicio, int fin);
```
- **Descripción:** Método privado que realiza el procesamiento de una sección de la imagen en un hilo específico.

```cpp
void pixel_a_gris(int c, int r);
```
- **Descripción:** Método privado que convierte un píxel de color a escala de grises.

## Programa principal (main.cpp)

### Función principal
```cpp
int main(int const argc, char const** argv);
```
- **Descripción:** Lee los parámetros de entrada, instancia `ProcesadorThreaded` y realiza el procesamiento de la imagen.

- **Parámetros de línea de comandos:**
  - `argv[1]`: Nombre del archivo de entrada (debe tener una extensión válida, como .jpg, .png, etc.).
  - `argv[2]`: Nombre del archivo de salida (debe tener una extensión válida, como .jpg, .png, etc.).
  - `argv[3]`: Número de hilos.

### Comentarios y Validaciones
- Se verifica la cantidad correcta de argumentos de línea de comandos.
- Se valida que los nombres de archivo tengan extensiones válidas.
- La cantidad de hilos se convierte a un entero y se utiliza como parámetro para la instancia de `ProcesadorThreaded`.
- Se realiza el procesamiento y se generan comentarios en la consola, incluido el tiempo de ejecución.

## Compilación

Asegúrate de compilar el programa con el soporte de C++11 o superior y vincula las bibliotecas de OpenCV. Un ejemplo de compilación con g++ sería:

```bash
g++ -std=c++11 main.cpp procesador_threaded.cpp -o procesador_threaded -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui
```

## Ejecución

Ejecuta el programa compilado:

```bash
./procesador_threaded input.jpg output.jpg 4
```

Donde `input.jpg` es el nombre del archivo de entrada, `output.jpg` es el nombre del archivo de salida y `4` es el número de hilos.
 