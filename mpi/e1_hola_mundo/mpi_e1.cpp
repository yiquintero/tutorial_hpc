#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {
    // Iniciar el entorno de MPI
    MPI_Init(&argc, &argv);

    // Obetner el numero de procesadores en el comunicador
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Obtener el rank (ID) del proceso actual
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Imprimir mensaje
    std::cout << "Hello world from rank " << world_rank 
              << " out of " << world_size << " processors\n";

    // Finalizar el entorno MPI
    MPI_Finalize();
    return 0;
}

// mpicxx mpi_1.cpp -o mpi_1
// mpirun -np 4 mpi_1