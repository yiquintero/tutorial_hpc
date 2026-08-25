## Colección de ejemplos de MPI

Para compilar y ejecutar el primer ejemplo en el clúster `mulatona.ccad.unc.edu.ar`, corra los siguientes comandos desde uno de lo nodos de acceso del clúster:

```bash
# Cargar el módulo del compilador
module load gcc/12.2.0

# Cargar el módulo de la librería OpenMP
module load openmpi

# Compilar
cd e1_hola_mundo
mpicxx mpi_e1.cpp -o mpi_e1

# Ejecutar el script en uno de los nodos de cómputo
sbatch slurm_script.sh
```

Corra los mismos comandos para compilar y ejecutar los demás ejemplos. Para cada uno, reemplace
- `cd e1_hola_mundo` con el nombre de la carpeta donde se encuentra el ejemplo, e.g. `cd e3_comunicacion_colectiva`
- `mpicxx mpi_e1.cpp -o mpi_e1` con el nombre del archivo del ejemplo, e.g. `mpicxx mpi_e3.cpp -o mpi_e3`