#ifndef alya1_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define PI 3.14159

//program untuk invers trigonometri

double sinus(double x) { //berupa sudut dalam bentuk radian
    double hasil = x;	//akan menyimpan hasil perhitungan sinus nantinya
    double pangkat = x;		//menyimpan nilai pangkat dari x dalam perhitungan deret tylor
    double faktorial = 1;	//menyimpan nilai faktorial pada perhitungan deret tylor
    int i;	/*merepresentasikan bilangan ganjil dalam iterasi, untuk menghitung 
	faktorial dari bilangan tersebut dan bilangan sebelumnya*/
    int tanda = -1;		//digunakan untuk mengubah tanda dari setiap suku deret
    for ( i = 3; i <= 19; i += 2) {
        pangkat *= x * x;
        faktorial *= i * (i - 1);
        hasil += tanda * (pangkat / faktorial);
        tanda *= -1;	//nilai akan bergantian positif dan negatif saat iterasi agar hasil lebih akurat
    }
    return hasil;
}

double kosinus(double x) {
    double hasil = 1;
    double pangkat = 1;
    double faktorial = 1;
    int i;
    int tanda = -1;
    /*batasan 2 sampai 18 dengan increment 2 karena dalam kosinus deret taylor hanya mengandung
	bilangan genap pada faktorial di penyebutnya*/
    for ( i = 2; i <= 18; i += 2) {
        pangkat *= x * x;
        faktorial *= i * (i - 1);
        hasil += tanda * (pangkat / faktorial);
        tanda *= -1;
    }
    return hasil;
}
//
//double Tangen(double x) { // fungsi tangen dalam radian
//    return Sinus(x) / Cosinus(x);
//}

double tangen(double x) {
    double hasil = x; //menyimpan hasil perhitungan tangen nantinya
    double pangkat = x; //menyimpan nilai pangkat dari x dalam perhitungan deret tylor
    double faktorial = 1; //menyimpan nilai faktorial pada perhitungan deret tylor
    double tambahan = x; //nilai tambahan dari setiap suku deret
    int i; /*merepresentasikan bilangan ganjil dalam iterasi, untuk menghitung 
        faktorial dari bilangan tersebut dan bilangan sebelumnya*/
    int tanda = -1; //digunakan untuk mengubah tanda dari setiap suku deret
    for (i = 3; i <= 19; i += 2) {
        pangkat *= x * x;
        faktorial *= i * (i - 1);
        tambahan = tanda * (pangkat / faktorial);
        hasil += tambahan;
        tanda *= -1; //nilai akan bergantian positif dan negatif saat iterasi agar hasil lebih akurat
    }
    return hasil;
}

double HitungCosec(double derajat) { //fungsi cosec dalam derajat
    double rad = derajat * PI / 180;
    return 1 / sinus(rad);
}

double HitungSec(double derajat) { //fungsi sec dalam derajat
    double rad = derajat * PI / 180;
    return 1 / kosinus(rad);
}

double HitungCotan(double derajat) { //fungsi cot dalam derajat
    double rad = derajat * PI / 180;
    return 1 / tangen(rad);
}

double Inverse_Sin(double angka) {
    double batas_bawah = -1.0;
    double batas_atas = 1.0;
    double toleransi = 0.00001;
    double tebakan = (batas_atas + batas_bawah) / 2.0;
    double nilai = sinus(tebakan);

    while ((nilai - angka) > toleransi || (angka - nilai) > toleransi) {
        if (nilai > angka) {
            batas_atas = tebakan;
        } else {
            batas_bawah = tebakan;
        }
        tebakan = (batas_atas + batas_bawah) / 2.0;
        nilai = sinus(tebakan);
    }

    return tebakan * 180.0 / PI;
}

double Inverse_Cos(double angka) {
    double batas_bawah = 0.0;
    double batas_atas = 1.0;
    double toleransi = 0.00001;
    double tebakan = (batas_atas + batas_bawah) / 2.0;
    double nilai = kosinus(tebakan);
    //terlalu banyak iterasi membuat programlebih lambat
    int max_iterasi = 100;
    int iterasi = 0;

    while ((nilai - angka) > toleransi || (angka - nilai) > toleransi) {
        if (nilai > angka) {
            batas_atas = tebakan;
        } else {
            batas_bawah = tebakan;
        }
        tebakan = (batas_atas + batas_bawah) / 2.0;
        nilai = kosinus(tebakan);
        iterasi++;
    }

    return tebakan * 180.0 / PI;
}

double Inverse_Tan(double angka){
	//penggunaan binary search dimana dibagi dua kategori
    double batas_atas = PI / 2.0;
    double batas_bawah = -PI / 2.0;
    double inverse = (batas_atas + batas_bawah) / 2.0;
    int iterations = 10;	//10 kali iterasi pencarian nilai 
    int i;

    for (i = 0; i < iterations; i++) {
        double tan_val = tan(inverse * PI / 180.0);
        /*jika nilai tangent lebih besar dr angka yg ingin dicari maka batas atas diganti*/
        if (tan_val > angka) {
            batas_atas = inverse;
        } else { //jika sebalikaya batas bawah diganti
            batas_bawah = inverse;
        }
        inverse = (batas_atas + batas_bawah) / 2.0;
        //nilai invers rata rata dari batas bawah dan atas
    }
	//mengembalikan dalam bentuk derajat
    return inverse * 180.0 / PI;
}



/*program untuk menu lainnya*/
//
//float ProgramStatistika(){
//	int i,d,n;
//	float num[100];
//	
//	printf("Masukkan Jumlah Data :\n");
//	scanf("\n\n %d", &n);
//	printf("Masukkan Data Anda (dipisahkan oleh enter) :\n");
//	for(i=0; i<n; i++)
//	{
//		scanf("%f", &num[i]);
//	}
//	
//	return Mean(num, n),Median(num, n),Modus(num, n),Variansi(num, n),StandarDeviasi(num, n);
//	}
//	
//float Mean(float num[], int n){
//	int i;
//	float sum=0.0, mean;
//	
//	for(i=0; i<n; i++){
//		sum += num[i];
//	}
//	mean = sum/n;
//	
//	printf("Mean dari data tersebut adalah: %.2f\n", mean);
//	return mean;
//}
//
//float Median(float num[], int n){
//	int i,j;
//	float median;
//	
//	for(i=0; i<n; i++){
//		for(j=0; j<n-i-1; j++){
//			if(num[j] > num[j+1]){
//				float temp = num[j];
//				num[j] = num[j+1];
//				num[j+1] = temp;
//			}
//		}
//	}
//	
//	if(n%2 == 0){
//		median = (num[(n-1)/2] + num[n/2])/2.0;
//	} else {
//		median = num[n/2];
//	}
//	
//	printf("Median dari data tersebut adalah: %.2f\n", median);
//	
//	return median;
//	}
//
//float Modus(float num[], int n){
//  int i, j, max=0, index=0;
//  float modus;
//  int freq[100];
//
//  for(i=0; i<n; i++){
//    freq[i] = 1;
//    for(j=0; j<i; j++){
//      if(num[i] == num[j]){
//        freq[j]++;
//        break;
//      }
//    }
//  }
//
//  for(i=0; i<n; i++){
//    if(freq[i] > max){
//      max = freq[i];
//      index = i;
//    }
//  }
//
//  modus = num[index];
//
//  if(max == 1)
//    printf("Data tidak memiliki modus\n");
//  else
//    printf("Modus dari data tersebut adalah: %.2f\n", modus);
//
//  return modus;
//}
//
//float Variansi(float num[], int n) {
//    float mean = Mean(num, n);
//    float variance = 0.0;
//    int i;
//
//    for (i = 0; i < n; i++) {
//        variance += pow(num[i] - mean, 2);
//    }
//
//    variance /= n;
//
//    printf("Variansi dari data tersebut adalah: %.2f\n", variance);
//    return variance;
//}
//
//float StandarDeviasi(float num[], int n) {
//    float mean = Mean(num, n);
//    float variance = 0.0;
//    int i;
//
//    for (i = 0; i < n; i++) {
//        variance += pow(num[i] - mean, 2);
//    }
//
//    variance /= n;
//    float sd = sqrt(variance);
//
//    printf("Standar Deviasi dari data tersebut adalah: %.2f\n", sd);
//    return sd;
//}
//
//int Matrix(){
//	int i, j, m, n, p;
//	int matriks1[10][10], matriks2[10][10],hasil[10][10];
//	char repeat='Y';
//  do{
//  //diasumsikan dimensi matrix satu dan dua sama
//
//  printf("Masukkan jumlah baris matriks (max 10) : ");
//  scanf("%d", &m);
//  printf("Masukkan jumlah kolom matriks (max 10) : ");
//  scanf("%d", &n);
//  
//	inputMatrix(m, n, matriks1);
//	inputMatrix(m, n, matriks2);
//  		addMatrix(m, n, matriks1, matriks2, hasil);
//  		printf("Hasil penjumlahan: \n");
//  		displayMatrix(m, n, hasil);
//  
//  		subtractMatrix(m, n, matriks1, matriks2, hasil);
//  		printf("Hasil pengurangan: \n");
//  		displayMatrix(m, n, hasil);
//  	
//  		printf("Jumlah kolom matriks pertama harus sama dengan jumlah baris matrix kedua\n");
//  		printf("Masukkan jumlah baris matrix kedua: \n");
//  		scanf("%d", &p);
//  		
//  		if(n != p){
//  			printf("Tidak dapat melakukan perkalian\n\n\n");
//		  }
//		else {
//  		multiplyMatrix(m, n, p, matriks1, matriks2, hasil);
//  		printf("Hasil perkalian: \n");
//  		displayMatrix(m, p, hasil);
//  	}
//  	
//  printf("Apakah anda ingin menjalankan program lagi (Y/T)");
//  getchar();
//  scanf("%c", &repeat);
//}
//while (repeat == 'Y' || repeat == 'y');
//system("pause");
//system("cls");
//main();
//	return 0;
//}
//
//int inputMatrix(int m, int n, int matriks[10][10]) {
//  int i, j;
//  printf("Masukkan elemen matrix (dipisahkan dengan spasi): \n");
//  for (i = 0; i < m; i++) {
//    for (j = 0; j < n; j++) {
//      char input[10];
//      int isValid = 0;
//      int k;
//      while (!isValid) {
//        scanf("%s", input);
//        isValid = 1;
//        for (k = 0; k < strlen(input); k++) {
//          if (!isdigit(input[k])) {
//            isValid = 0;
//            break;
//          }
//        }
//        if (!isValid) {
//          printf("Input tidak valid, harap masukkan bilangan bulat.\n");
//          getchar();
//        }
//      }
//      matriks[i][j] = atoi(input);
//    }
//  }
//  return 0;
//}
//
//int displayMatrix(int m, int n, int matriks[10][10]) {
//  int i, j;
//  for (i = 0; i < m; i++) {
//    for (j = 0; j < n; j++) {
//      printf("%d \t", matriks[i][j]);
//    }
//    printf("\n");
//  }
//  return 0;
//}
//
//int addMatrix(int m, int n, int matriks1[10][10], int matriks2[10][10], int hasil[10][10]) {
//  int i, j;
//  for (i = 0; i < m; i++) {
//    for (j = 0; j < n; j++) {
//      hasil[i][j] = matriks1[i][j] + matriks2[i][j];
//    }
//  }
//  return 0;
//}
//
//int subtractMatrix(int m, int n, int matriks1[10][10], int matriks2[10][10], int hasil[10][10]) {
//  int i, j;
//  for (i = 0; i < m; i++) {
//    for (j = 0; j < n; j++) {
//      hasil[i][j] = matriks1[i][j] - matriks2[i][j];
//    }
//  }
//  return 0;
//}
//
////berjalan ketiga jumlah kolom pertama sama dengan baris matrix kedua
//int multiplyMatrix(int m, int n, int p, int matriks1[10][10], int matriks2[10][10], int hasil[10][10]) {
//  int i, j, k;
//  for (i = 0; i < m; i++) {
//    for (j = 0; j < p; j++) {
//      hasil[i][j] = 0;
//      for (k = 0; k < n; k++) {
//        hasil[i][j] += matriks1[i][k] * matriks2[k][j];
//      }
//    }
//  }
//  return 0;
//}
//

#endif


