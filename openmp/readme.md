## Colección de ejemplos de OpenMP

Para compilar y ejecutar el primer ejemplo en el clúster `mulatona.ccad.unc.edu.ar`, corra los siguientes comandos desde uno de lo nodos de acceso del clúster:

```bash
# Cargar el compilador
module load gcc/12.2.0

# Compilar
cd e1_hola_mundo
g++ -fopenmp openmp_e1.cpp -o openmp_e1

# Ejecutar el script en uno de los nodos de cómputo
sbatch slurm_script.sh
```

Corra los mismos comandos para compilar y ejecutar los demás ejemplos. Para cada uno, reemplace
- `cd e1_hola_mundo` con el nombre de la carpeta donde se encuentra el ejemplo, e.g. `cd e3_bucles`
- `g++ -fopenmp openmp_e1.cpp -o openmp_e1` con el nombre del archivo del ejemplo, e.g. `g++ -fopenmp openmp_e3.cpp -o openmp_e3`