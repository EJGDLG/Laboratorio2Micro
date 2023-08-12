#include <stdio.h>
#include <omp.h>
#include <sys/time.h>

double get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

int main() {
    int n = 10000;
    double sum_paralelo = 0.0, sum_secuencial = 0.0;
    int num_threads;

    printf("Ingrese la cantidad de hilos a utilizar: ");
    scanf("%d", &num_threads);

    // Cálculo paralelo
    double start_paralelo = get_wall_time();
    #pragma omp parallel for num_threads(num_threads) reduction(+:sum_paralelo)
    for (int i = 1; i <= n; i++) {
        sum_paralelo += (double)i / n;
    }
    double end_paralelo = get_wall_time();

    // Cálculo secuencial
    double start_secuencial = get_wall_time();
    for (int i = 1; i <= n; i++) {
        sum_secuencial += (double)i / n;
    }
    double end_secuencial = get_wall_time();

    printf("Sumatoria paralela: %.15f\n", sum_paralelo);
    printf("Tiempo paralelo: %.6f segundos\n", end_paralelo - start_paralelo);

    printf("Sumatoria secuencial: %.15f\n", sum_secuencial);
    printf("Tiempo secuencial: %.6f segundos\n", end_secuencial - start_secuencial);

    return 0;
}
