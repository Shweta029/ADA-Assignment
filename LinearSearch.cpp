#include<stdio.h>
#include<time.h>
#include<sys/time.h>

int main() {
	int l,i,x, flag=1;
	struct timeval start, end;
	
	printf("enter length of array:- ");
	scanf("%d", &l);
	
	int arr[l];
	printf("enter the array elements:- ");
	for(i=0; i<l; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("enter element to search :- ");
	scanf("%d", &x);
	
	gettimeofday(&start, NULL);
	
	for(i=0; i<l; i++)
		if(arr[i] == x) {
			printf("element found at position number %d.", i+1);
			flag = 0;
		}
		
	if(flag)
		printf("element not found");
		
	gettimeofday(&end, NULL);
	
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	
	printf("\nthe elapsed time is %d seconds and %d micros\n", seconds, micros);
}
