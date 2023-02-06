#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define alya1.H
#ifndef alya1.H

float ProgramStatistika(int n);
void sort(int num[100], int n);
void swap(int *a, int *b);

#endif



float ProgramStatistika(n){
	int i;
	int d;
	float sum=0.0, mean;
	float num[100];
printf("pilihan anda :\n");
printf("1.Mean\n 2.Median\n ");
scanf("%d",&d);
switch(d){
	//mean
	case 1:

	for(i=0; i<n; i++){
		printf("%d. Masukan : ", i+1);
		scanf("%f", &num[i]);
		sum += num[i];	
	}
	mean = sum / n;
	printf("mean = %.2f", mean);
	system ("\npause");
	break;
	
	
	//median
	case 2:
	for(i=0; i<n; i++){
	printf("%d. Masukan : ", i+1);
	scanf("%f", &num[i]);
	}
	sort(num, n);
	int tengah = n/2;
	if(n%2==0){
		printf("median : %.2f\n",(float)(num[tengah-1]+ num[tengah])/2);
	}else {
		printf("Median : %d\n", num[tengah]);
	}
	system("\npause");
	break;
	
}
}


void sort(int num[100], int n){
	int j,k;
	 for (int j = 0; j < n-1; j++) {
        for (int k = 0; k < n-j-1; k++) {
            if (num[k] > num[k+1]) {
                swap(&num[k], &num[k+1]);
            }
        }
    }
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}