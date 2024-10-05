#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    const int NUM_POINTS = 1000000; // 定义点的数量
    int inside_circle = 0;
    double x, y;

    #pragma omp parallel for reduction(+:inside_circle) private(x, y)
    for (int i = 0; i < NUM_POINTS; i++) {
        x = (double)rand() / RAND_MAX * 2 - 1;
        y = (double)rand() / RAND_MAX * 2 - 1;
        if (x * x + y * y <= 1) {
            inside_circle++;
        }
    }

    double pi_estimate = (double)inside_circle / NUM_POINTS * 4;
    printf("Estimated PI value: %f\n", pi_estimate);

    return 0;
}