#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	int pi;
	if (low < high)
	{
		pi = partition(arr, low, high);

#pragma omp task
		{
			(void)quickSort(arr, low, pi - 1);
		}
#pragma omp task
		{
			(void)quickSort(arr, pi + 1, high);
		}
#pragma omp taskwait
	}
}

int main()
{
	int N;
	printf("\nInput Size Array: ");
	scanf("%d", &N);
	srand(time(NULL));
	int a[N], i;
	printf("------------Sequential------------\n");
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 10;
		printf("%d ", a[i]);
	}
	printf("\n");
	int n = sizeof(a) / sizeof(a[0]);
	double start = omp_get_wtime();
	quickSort(a, 0, n - 1);
	printf("Sorted array: \n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	double end = omp_get_wtime();
	printf("Work took %f seconds\n", end - start);
	return 0;
}
