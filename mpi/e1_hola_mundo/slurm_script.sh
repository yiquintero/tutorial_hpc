#!/bin/bash
#SBATCH --job-name="mpi_e1"              # nombre del trabajo para fácil identificación en la cola de trabajos de Slurm
#SBATCH --partition=short               # particion para trabajos pequeños (diferente en cada cluster)
#SBATCH --time=00:05:00                 # hh:mm:ss
#SBATCH --ntasks=4                      # número de procesadores, i.e. MPI ranks
#SBATCH --cpus-per-task=1               # número de cpus-por-procesador; aumentar número si se utiliza un sistema hibrido MPI + OpenMp

# Importar las variables de entorno compartida por todos los usuarios (depende del clúster, muchas veces no es necesario)
. /etc/profile

# Ejecutar: asume que el programa ya fue compilado a un ejecutable llamado mpi_e1
srun mpi_e1
