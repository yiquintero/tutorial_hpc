#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <omp.h>

int main() {
    const size_t N = 10000000;
    std::vector<double> data(N);

    std::cout << "Ejecutando con " << omp_get_max_threads() << " hilos...\n";

    // Inicio de la medición de tiempo
    auto inicio = std::chrono::high_resolution_clock::now();

    // Paralelización del cálculo intensivo
    #pragma omp parallel for
    for (size_t i = 0; i < N; ++i) {
        data[i] = std::sin(i) * std::cos(i) + std::sqrt(i);
    }

    // Fin de la medición de tiempo
    auto final = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = final - inicio;

    std::cout << "Tiempo de ejecucion: " << duracion.count() << " segundos.\n";

    return 0;
}