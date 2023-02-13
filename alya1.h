#ifndef alya1_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>




void statistika();
float Mean(float num[], int n);
float Median(float num[], int n);
float Modus(float num[], int n);




void ProgramStatistika(){
	int i,d,n;
	float num[100];
	
	printf("Masukkan Jumlah Data :\n");
	scanf("\n\n %d", &n);
	
	printf("Masukkan Data Anda (dipisahkan oleh enter) :\n");
	for(i=0; i<n; i++){
		scanf("%f", &num[i]);
	}
	
	printf("Masukkan Pilihan Anda :");
	printf("\n\t1.Mean\n\t 2.Median\n\t 3.Modus\n");
	scanf("\n\n %d", &d);
	getchar();
	switch(d){
		case 1: //mean
			Mean(num, n);
			break;
		case 2: //Median
			Median(num, n);
			break;
		case 3:
			Modus(num, n);
			break;
	}
	}
	


float Mean(float num[], int n){
	int i;
	float sum=0.0, mean;
	
	for(i=0; i<n; i++){
		sum += num[i];
	}
	mean = sum/n;
	
	printf("Mean dari data tersebut adalah: %.2f\n", mean);
	return mean;
}

float Median(float num[], int n){
	int i,j;
	float median;
	
	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){
			if(num[j] > num[j+1]){
				float temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}
	
	if(n%2 == 0){
		median = (num[(n-1)/2] + num[n/2])/2.0;
	} else {
		median = num[n/2];
	}
	
	printf("Median dari data tersebut adalah: %.2f\n", median);
	
	return median;
	}



float Modus(float num[], int n){
  int i, j, max=0, index=0;
  float modus;
  int freq[100];

  for(i=0; i<n; i++){
    freq[i] = 1;
    for(j=0; j<i; j++){
      if(num[i] == num[j]){
        freq[j]++;
        break;
      }
    }
  }

  for(i=0; i<n; i++){
    if(freq[i] > max){
      max = freq[i];
      index = i;
    }
  }

  modus = num[index];

  if(max == 1)
    printf("Data tidak memiliki modus\n");
  else
    printf("Modus dari data tersebut adalah: %.2f\n", modus);

  return modus;
}


#endif

