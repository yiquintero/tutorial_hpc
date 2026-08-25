#include <iostream>
#include <omp.h>

int main() {
    int c = 100;    // Todos los hilos tienen acceso a la variable
    int p = 0;      // Se creará una copia para cada hilo

    #pragma omp parallel shared(c) private(p)
    {
        int id = omp_get_thread_num();
        p = id + c;
        #pragma omp critical
        {
            std::cout << "Hola desde el hilo " << id << "; p = " << p << std::endl;
        }
    }
    std::cout << "Fuera de region paralela, p = " << p << std::endl; 
    return 0;
}

