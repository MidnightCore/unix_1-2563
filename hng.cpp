#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define N 100000000
int main()
{
    printf("\n---------Parallel----------\n");
    int sum = 0;
    int *a = (int *)malloc(sizeof(int) * N); //ใช้mallocจองพื้นที่ แล้วใช้sizeofบอกขนาด
    srand(time(NULL));
    double start;
    double end;
    start = omp_get_wtime();
//#pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 10; //mod 10 จะได้เป็นเลขหลักเดียว คือ 0 - 9
        // sum = sum + a[i];
    }
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++)
    {
        sum = sum + a[i];
    } 
    end = omp_get_wtime();
    printf("Sum is : %d\n", sum);
    printf("Time use : %f seconds\n", end - start);


    printf("\n---------Sequential----------\n");
    int sum2 = 0;
    int *b = (int *)malloc(sizeof(int) * N);
    srand(time(NULL));
    double start2;
    double end2;
    start2 = omp_get_wtime();
    for (int i = 0; i < N; i++)
    {
        b[i] = rand() % 10;
        sum2 = sum2 + b[i];
    }
    end2 = omp_get_wtime();
    printf("Sum is : %d\n", sum2);
    printf("Time use : %f seconds\n\n", end2 - start2);
    return 0;
}
