#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <bits/stdc++.h> //รวม standard library หลายๆตัว เช่น sort
using namespace std;     //เพื่อใช้ฟังก์ชันในlib namespace std โดยไม่ต้องมีstd:prefix
int main()
{
    int N;
    printf("\nEnter size array : ");
    scanf("%d", &N);
    int randArray[N];
    printf("\n---------Sequential----------\n");
    srand(time(NULL)); /*เรียกใช้งานฟังก์ชัน time(NULL) เพื่อรับเอาค่าเวลาปัจจุบันมาเป็น
                         ค่าของ random เนื่องจากเวลานั้นจะเปลี่ยนแปลงไป
                         ในการรันโปรแกรมแต่ละครั้ง จึงทำให้ตัวเลขที่สุ่มออกมาไม่ซ้ำกัน*/
    double start;
    double end;
    start = omp_get_wtime();
    for (int i = 0; i < N; i++)
        randArray[i] = rand() % 10;

    for (int i = 0; i < N; i++)
        printf("Array no.%d : %d\n", i + 1, randArray[i]);

    sort(randArray, randArray + N);
    /*sort เป็นไลบรารี่มาตรฐาน ซึงจะผสมระหว่าง QuickSort,HeapSort,InsertionSort
    โดยจะใช้ QuickSort เป็นค่าเริ่มต้น แต่ถ้าใช้เวลามากกว่า N*logN ก็จะไปใช้ HeapSort 
    โดยถ้าอาเรย์มีขนาดเล็ก ถึงจะไปใช้ InsertionSort*/
    printf("Array after sorting : ");

    for (int i = 0; i < N; ++i)
        printf("%d ", randArray[i]);

    end = omp_get_wtime();
    printf("\nTime use : %f seconds\n\n", end - start);




    printf("---------Parallel----------\n");
    srand(time(NULL));
    double start2;
    double end2;
#pragma omp parallel
    start2 = omp_get_wtime();
    for (int i = 0; i < N; i++)
        randArray[i] = rand() % 10;

    for (int i = 0; i < N; i++)
        printf("Array no.%d : %d\n", i + 1, randArray[i]);

    sort(randArray, randArray + N);
    printf("Array after sorting : ");
    for (int i = 0; i < N; ++i)
        printf("%d ", randArray[i]);

    end2 = omp_get_wtime();
    printf("\nTime use : %f seconds\n\n", end2 - start2);
    return 0;
}
