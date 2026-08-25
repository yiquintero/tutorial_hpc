#include <iostream>
#include <omp.h>

int main() {
    // Inicia la región paralela
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        #pragma omp critical // Garantiza que solo un hilo imprima a la vez
        {
            std::cout << "Hola desde el hilo " << id << std::endl;
        }
    } // Join automático: los hilos se sincronizan y terminan aquí
    return 0;
}



/* 
Compilar y ejecutar en Linux:
    g++ -fopenmp openmp_1.cpp -o openmp_1
    OMP_NUM_THREADS=4 ./openmp_1

Compilar y ejecutar en macOS:
1. Instalar gcc: 
    brew install gcc
2. Revisar qué version de gcc tenemos instalada (probar con g++-15, g++-16, etc. si es necesario):
    which g++-14
3. Compilar:
    g++-16 -fopenmp openmp_1.cpp -o openmp_1
4. Ejecutar:
    OMP_NUM_THREADS=4 ./openmp_1
*/