#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 8;
    std::vector<int> vec(N);

    // Reparte las 8 iteraciones entre los hilos disponibles
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        vec[i] = i * 2; // Operación independiente en cada iteración
        
        #pragma omp critical
        {
            std::cout << "Hilo " << omp_get_thread_num() << " procesó el índice " << i << std::endl;
        }
    }
    return 0;
}