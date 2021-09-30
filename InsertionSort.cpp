#include<stdio.h>
#include<time.h>
#include<sys/time.h>

int main() {
	int l,i,j,max,temp, flag=0;
	struct timeval start, end;
	
	printf("enter length of array:- ");
	scanf("%d", &l);
	
	int arr[l];
	printf("enter the array elements:- ");
	for(i=0; i<l; i++) {
		scanf("%d", &arr[i]);
	}
	gettimeofday(&start, NULL);
	
	for(i=1; i<= l-1 ; i++) {
		temp = arr[i];
		for(j=i-1; j>=0; j--) {
			if(arr[i]>temp) {
				arr[j+1] = arr[j];
				flag = 1;
			}
			else
				break;
		}
		if (flag)
		arr[j+1] = temp;
	}
	gettimeofday(&end, NULL);
	
	printf("sorted array:- ");
	for(i=0; i<l ; i++) {
		printf("%d" , arr[i]);
	}
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	
	printf("\nthe elapsed time is %d seconds and %d micros\n", seconds, micros);
	
}
