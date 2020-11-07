#include <omp.h>
#include <stdio.h>

int main(){
	const int N =100 ;
	int a[N];
	int i;
	int sum=0;
	for(i=0;i<N;i++){
	a[i] = i;
	}

#pragma omp parallel for reduction(+:sum)
	for(i=0;i<N;i++){
		sum=sum+a[i];
	}
	printf("%d ",sum);
	return 0;
}
