#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
int main()
{
    int N ;
    printf("\nInput Size Matrix: ");
    scanf("%d", &N);

    int a[N][N], sum[N][N], b[N][N], sums[N][N], c[N][N], d[N][N] ;
    int i, j, k, co = 0 ;
    srand(time(NULL));
    printf("\n---------------Parallel------------------");
    double start = omp_get_wtime();
    printf("\n\nMatrix 1:\n");

    for (i = 0; i < N; i++)
    {
#pragma omp for
        for (j = 0; j < N; j++)
        {
            a[i][j] = rand() % 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matrix 2:\n");
    for (i = 0; i < N; i++)
    {
#pragma omp for
        for (j = 0; j < N; j++)
        {
            b[i][j] = rand() % 10;
            printf("%d ", b[i][j]);
        }

        printf("\n");
    }

    printf("\n");
    printf("Matrix 1*2 :\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N; k++)
            {
                co += a[i][k] * b[k][j];
            }
            sum[i][j] = co;
            printf("%d ", sum[i][j]);
            co = 0;
        }
        printf("\n");
    }
    double end = omp_get_wtime();
    printf("\nParallel : Work took %f seconds\n", end - start);



    printf("\n-----------------Sequential------------------");
    double starts = omp_get_wtime();
    printf("\n\nMatrix 1:\n");

    for (i = 0; i < N; i++)
    {

        for (j = 0; j < N; j++)
        {
            c[i][j] = rand() % 10;
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matrix 2:\n");

    for (i = 0; i < N; i++)
    {

        for (j = 0; j < N; j++)
        {
            d[i][j] = rand() % 10;
            printf("%d ", d[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    printf("Matrix 1*2 :\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {

            for (k = 0; k < N; k++)
            {
                co += (c[i][k] * d[k][j]);
            }

            sums[i][j] = co;
            printf("%d ", sums[i][j]);
            co = 0;
        }
        printf("\n");
    }
    double ends = omp_get_wtime();
    printf("\nSequential : Work took %f seconds\n", ends - starts);
    return 0;
}