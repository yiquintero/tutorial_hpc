#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // 1. COMUNICACIÓN PUNTO A PUNTO (Solo entre Proceso 0 y 1)
    if (rank == 0) {
        int mensaje = 42;
        std::cout << "[Punto a Punto] Proceso 0 enviando " << mensaje << " al proceso 1...\n";
        MPI_Send(&mensaje, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

    } else if (rank == 1) {
        int mensaje_recibido = 0;
        MPI_Recv(&mensaje_recibido, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "[Punto a Punto] Proceso 1 recibio " << mensaje_recibido << "\n";
    }

    // 2. COMUNICACIÓN COLECTIVA (Broadcast a TODOS los procesos)
    int dato_colectivo;

    if (rank == 0) {
        dato_colectivo = 99; // Solo el Proceso 0 define o carga el dato inicial
    }

    // MPI_Bcast(buffer, conteo, tipo_dato, raiz, comunicador)
    // TODOS los procesos deben llamar a esta función colectiva
    MPI_Bcast(&dato_colectivo, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Todos los procesos (0, 1, 2, 3...) ahora tienen dato_colectivo = 99
    std::cout << "[Broadcast] Proceso " << rank 
              << " tiene el dato: " << dato_colectivo << std::endl;

    MPI_Finalize();
    return 0;
}