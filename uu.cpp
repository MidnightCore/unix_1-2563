#include <omp.h>
#include <stdio.h>

int main(){

#pragma omp parallel
{
	printf("naja %d: %d\n",omp_get_thread_num(),omp_get_num_threads());
}
	return 0;
}
