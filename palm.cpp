#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define N 100000000
int main()
{
    int sum = 0;
    int *a = (int *)malloc(sizeof(int) * N);
    srand(time(NULL));

    double start;
    double end;
    start = omp_get_wtime();
        for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 10;
        sum = sum + a[i];
    }
    end = omp_get_wtime();
    printf("Sum is : %d\n",sum);
    printf("Time use : %f seconds\n", end - start);
    return 0;
}
