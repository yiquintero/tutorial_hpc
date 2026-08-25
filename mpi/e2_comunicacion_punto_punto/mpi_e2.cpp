#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        int mensaje = 42; // Dato a enviar
        std::cout << "Proceso 0: Enviando el numero " << mensaje << " al proceso 1...\n";
        
        // MPI_Send(buffer, conteo, tipo_dato, destino (rank), etiqueta, comunicador)
        MPI_Send(&mensaje, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

    } else if (rank == 1) {
        int mensaje_recibido = 0;
        
        // MPI_Recv(buffer, conteo, tipo_dato, origen (rank), etiqueta, comunicador, estado)
        MPI_Recv(&mensaje_recibido, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        std::cout << "Proceso 1: Recibi el numero " << mensaje_recibido << " exitosamente!\n";
    }

    MPI_Finalize();
    return 0;
}