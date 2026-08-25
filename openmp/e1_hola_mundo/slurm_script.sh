#!/bin/bash
#SBATCH --job-name="openmp-e1"              # nombre del trabajo para fácil identificación en la cola de trabajos de Slurm
#SBATCH --partition=short                   # particion para trabajos pequeños (diferente en cada cluster)
#SBATCH --time=00:02:00                     # hh:mm:ss
#SBATCH --ntasks=1                          # número de procesadores (e.g. ranks en MPI). Siempre 1 para OpenMP
#SBATCH --cpus-per-task=4                   # número de cpus-por-procesador; Slurm le asignará 1 hilo a cada cpu

# Importar las variables de entorno compartida por todos los usuarios (depende del clúster, muchas veces no es necesario)
. /etc/profile

# Definir el numero de hilos disponibles (mediante la variable de entorno OMP_NUM_THREADS)
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

# Ejecutar: asume que el programa ya fue compilado a un ejecutable llamado openmp_e1
srun openmp_e1
