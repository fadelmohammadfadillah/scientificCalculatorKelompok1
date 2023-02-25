#ifndef alya1_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define PI 3.14159

float Mean(float num[], int n);
float Median(float num[], int n);
float Modus(float num[], int n);
float StandarDeviasi(float num[], int n);
float Variansi(float num[], int n);
int Matrix();
int inputMatrix(int m, int n, int matriks[10][10]);
int displayMatrix(int m, int n, int mattriks[10][10]);
int addMatrix(int m, int n, int matriks1[10][10], int matriks2[10][10], int hasil[10][10]);
int subtractMatrix(int m, int n, int matriks1[10][10], int matriks2[10][10], int hasil[10][10]);
int multiplyMatrix(int m, int n, int p, int matriks1[10][10], int matriks2[10][10], int hasil[10][10]);
float Inverse_Trigonometri();

float ProgramStatistika(){
	int i,d,n;
	float num[100];
	
	printf("Masukkan Jumlah Data :\n");
	scanf("\n\n %d", &n);
	printf("Masukkan Data Anda (dipisahkan oleh enter) :\n");
	for(i=0; i<n; i++)
	{
		scanf("%f", &num[i]);
	}
	
	return Mean(num, n),Median(num, n),Modus(num, n),Variansi(num, n),StandarDeviasi(num, n);
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

float Variansi(float num[], int n) {
    float mean = Mean(num, n);
    float variance = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        variance += pow(num[i] - mean, 2);
    }

    variance /= n;

    printf("Variansi dari data tersebut adalah: %.2f\n", variance);
    return variance;
}

float StandarDeviasi(float num[], int n) {
    float mean = Mean(num, n);
    float variance = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        variance += pow(num[i] - mean, 2);
    }

    variance /= n;
    float sd = sqrt(variance);

    printf("Standar Deviasi dari data tersebut adalah: %.2f\n", sd);
    return sd;
}

int Matrix(){
	int i, j, m, n, p;
	int matriks1[10][10], matriks2[10][10],hasil[10][10];
	char repeat='Y';
  do{
  //diasumsikan dimensi matrix satu dan dua sama

  printf("Masukkan jumlah baris matriks (max 10) : ");
  scanf("%d", &m);
  printf("Masukkan jumlah kolom matriks (max 10) : ");
  scanf("%d", &n);
  
	inputMatrix(m, n, matriks1);
	inputMatrix(m, n, matriks2);
  		addMatrix(m, n, matriks1, matriks2, hasil);
  		printf("Hasil penjumlahan: \n");
  		displayMatrix(m, n, hasil);
  
  		subtractMatrix(m, n, matriks1, matriks2, hasil);
  		printf("Hasil pengurangan: \n");
  		displayMatrix(m, n, hasil);
  	
  		printf("Jumlah kolom matriks pertama harus sama dengan jumlah baris matrix kedua\n");
  		printf("Masukkan jumlah baris matrix kedua: \n");
  		scanf("%d", &p);
  		
  		if(n != p){
  			printf("Tidak dapat melakukan perkalian\n\n\n");
		  }
		else {
  		multiplyMatrix(m, n, p, matriks1, matriks2, hasil);
  		printf("Hasil perkalian: \n");
  		displayMatrix(m, p, hasil);
  	}
  	
  printf("Apakah anda ingin menjalankan program lagi (Y/T)");
  getchar();
  scanf("%c", &repeat);
}
while (repeat == 'Y' || repeat == 'y');
system("pause");
system("cls");
main();
	return 0;
}

int inputMatrix(int m, int n, int matriks[10][10]) {
  int i, j;
  printf("Masukkan elemen matrix (dipisahkan dengan spasi): \n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      char input[10];
      int isValid = 0;
      int k;
      while (!isValid) {
        scanf("%s", input);
        isValid = 1;
        for (k = 0; k < strlen(input); k++) {
          if (!isdigit(input[k])) {
            isValid = 0;
            break;
          }
        }
        if (!isValid) {
          printf("Input tidak valid, harap masukkan bilangan bulat.\n");
          getchar();
        }
      }
      matriks[i][j] = atoi(input);
    }
  }
  return 0;
}

int displayMatrix(int m, int n, int matriks[10][10]) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d \t", matriks[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int addMatrix(int m, int n, int matriks1[10][10], int matriks2[10][10], int hasil[10][10]) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      hasil[i][j] = matriks1[i][j] + matriks2[i][j];
    }
  }
  return 0;
}

int subtractMatrix(int m, int n, int matriks1[10][10], int matriks2[10][10], int hasil[10][10]) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      hasil[i][j] = matriks1[i][j] - matriks2[i][j];
    }
  }
  return 0;
}

//berjalan ketiga jumlah kolom pertama sama dengan baris matrix kedua
int multiplyMatrix(int m, int n, int p, int matriks1[10][10], int matriks2[10][10], int hasil[10][10]) {
  int i, j, k;
  for (i = 0; i < m; i++) {
    for (j = 0; j < p; j++) {
      hasil[i][j] = 0;
      for (k = 0; k < n; k++) {
        hasil[i][j] += matriks1[i][k] * matriks2[k][j];
      }
    }
  }
  return 0;
}

double Inverse_Sin(double angka){
	return asin(angka)*180/PI;
}
double Inverse_Cos(double angka){
	return acos(angka)*180/PI;
}
double Inverse_Tan(double angka){
	return atan(angka)*180/PI;
}

float Inverse_Trigonometri(){
	float angka,Isin,Icos,Itan;
	printf("Masukkan nilai (Radian); ");
	scanf("%f", &angka);
	Isin = asin(angka);
	Icos = acos(angka);
	Itan = atan(angka);
	//untuk sin
	printf("Radian sin(%.3f) = %3f\n",angka,Isin);
	Isin = (Isin*180)/3.14;
	printf("Degree sin(%.3f) = %.3f\n",angka,Isin);
	//untuk cos
	printf("Radian cos(%.3f) = %3f\n",angka,Icos);
	Icos = (Icos*180)/3.14;
	printf("Degree cos(%.3f) = %.3f\n",angka,Icos);
	//untuk tan
	printf("Radian tan(%.3f) = %3f\n",angka,Itan);
 	Itan = (Itan*180)/3.14;
    printf("Degree tan(%.3f) = %.3f\n",angka,Itan);
	
	system("pause");
	system("cls");
	main();		
	return 0;
}
#endif


