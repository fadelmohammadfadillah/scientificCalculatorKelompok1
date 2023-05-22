#ifndef alya1_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define PI 3.14159

//Program yang membantu perhitungan invers
double sinus(double x) { // x dalam bentuk radian
    double hasil = x;
    double pangkat = x;    // Menyimpan nilai pangkat dari x dalam deret taylor
    double faktorial = 1;  // Menyimpan nilai faktorial pada perhitungan deret taylor
    int i;
    int tanda = -1;        // Digunakan untuk mengubah tanda dari setiap suku deret

    // Pendekatan menggunakan perhitungan deret taylor
    for (i = 3; i <= 19; i += 2) {
        pangkat *= x * x;
        faktorial *= i * (i - 1);
        hasil += tanda * (pangkat / faktorial);
        tanda *= -1;        // Nilai akan bergantian positif dan negatif saat iterasi agar hasil lebih akurat
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

double tangen(double x) { // fungsi tangen dalam radian
	if ( x == PI / 2 || x == 3*PI /2){
		printf("Nilai tak terdefinisi (undefined) \n");
		printf("ERROR " );
		return 0;
	}else{
		return sinus(x) / kosinus(x);
	}		
}

double HitungCosec(double derajat) {
    double rad = derajat * PI / 180;
    double sin_val = sinus(rad);

    // Memeriksa kondisi tak terdefinisi
    if (sin_val == 0) {
        printf("Nilai tak terdefinisi (undefined) untuk cosec(%lf)\n", derajat);
        printf("ERROR " );
		return 0;
    } else {
        if (derajat == 180 || derajat == 360){
        	printf("Nilai tak terdefenisi (undefined) untuk cosec(%lf)\n", derajat);
			printf("ERROR " );
			return 0;
		}else{
			return 1 / sin_val;
		}
    }
    
}
double HitungSec(double derajat) {
    double rad = derajat * PI / 180;
    double cos_val = kosinus(rad);

    // Memeriksa kondisi tak terdefinisi
    if (cos_val == 0) {
        printf("Nilai tak terdefinisi (undefined) untuk sec(%lf)\n", derajat);
        printf("ERROR " );
		return 0;
    } else {
    	if (derajat == 90 || derajat == 270){
        	printf("Nilai tak terdefenisi (undefined) untuk secan(%lf)\n", derajat);
			printf("ERROR " );
			return 0;
		}else{
			return 1 / cos_val;
		}
    }
}
double HitungCotan(double derajat) {
    double rad = derajat * PI / 180;
    double tan_val = sinus(rad) / kosinus(rad);

    // Memeriksa kondisi tak terdefinisi
    if (tan_val == 0) {
        printf("Nilai tak terdefinisi (undefined) untuk cotan(%lf)\n", derajat);
        printf("ERROR " );
		return 0;
    } else {
    	if (derajat == 180 || derajat == 360){
        	printf("Nilai tak terdefenisi (undefined) untuk cosec(%lf)\n", derajat);
			printf("ERROR " );
			return 0;
		}else{
			return 1 / tan_val;
		}
    }
}

// Fungsi untuk menghitung invers sinus
double Inverse_Sin(double angka) {
    double batas_bawah = -PI / 2.0; // Batas bawah dalam radian
    double batas_atas = PI / 2.0; // Batas atas dalam radian
    double toleransi = 0.00001; // Toleransi perbedaan nilai
    double tebakan = (batas_atas + batas_bawah) / 2.0; // Tebakan awal
    double nilai = sinus(tebakan); // Nilai sinus dari tebakan

    // Metode binary search
    while ((nilai - angka) > toleransi || (angka - nilai) > toleransi) {
        if (nilai > angka) {
            batas_atas = tebakan;
        } else {
            batas_bawah = tebakan;
        }
        tebakan = (batas_atas + batas_bawah) / 2.0;
        nilai = sinus(tebakan);
    }

    return tebakan * 180.0 / PI; // Mengembalikan hasil dalam derajat
}

// Fungsi untuk menghitung invers kosinus
double Inverse_Cos(double angka) {
    double batas_bawah = -PI / 2.0; // Batas bawah dalam radian
    double batas_atas = PI / 2.0; // Batas atas dalam radian
    double toleransi = 0.00001; // Toleransi perbedaan nilai
    double tebakan = (batas_atas + batas_bawah) / 2.0; // Tebakan awal
    double nilai = kosinus(tebakan); // Nilai kosinus dari tebakan

    // Metode binary search
    while ((nilai - angka) > toleransi || (angka - nilai) > toleransi) {
        if (nilai > angka) {
            batas_atas = tebakan;
        } else {
            batas_bawah = tebakan;
        }
        tebakan = (batas_atas + batas_bawah) / 2.0;
        nilai = kosinus(tebakan);
    }

    return tebakan * 180.0 / PI; // Mengembalikan hasil dalam derajat
}

double Inverse_Tan(double angka) {
    double tol = 0.00001; // Toleransi perbedaan nilai
    double batas_bawah = -PI / 2.0;
    double batas_atas = PI / 2.0;
    double tebakan = (batas_atas + batas_bawah) / 2.0; // Tebakan awal
    double delta = tebakan - angka;
    int iterasi = 0; // Jumlah iterasi

    while (delta > tol || delta < -tol) {
        double tan_val = tangen(tebakan);
        if (tan_val > angka) {
            batas_atas = tebakan;
        } else {
            batas_bawah = tebakan;
        }
        tebakan = (batas_atas + batas_bawah) / 2.0;
        delta = tebakan - angka;

        iterasi++;
		if (iterasi >= 1000) {
            printf("");
            break;
        }
    }

    return tebakan * 180.0 / PI;
}



#endif


