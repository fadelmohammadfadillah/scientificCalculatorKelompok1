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
		return sinus(x) / kosinus(x);		
}
double HitungCosec(double derajat) {
    double rad = derajat * PI / 180;
    double sin_val = sinus(rad);

    // Memeriksa kondisi tak terdefinisi
    if (sin_val == 0) {
        printf("Nilai tak terdefinisi (undefined) untuk cosec(%lf)\n", derajat);
        return 0.0;
    } else {
        if (derajat == 180 || derajat == 360){
        	printf("Nilai tak terdefenisi (undefined) untuk cosec(%lf)\n", derajat);
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
        return 0.0;
    } else {
    	if (derajat == 90 || derajat == 270){
        	printf("Nilai tak terdefenisi (undefined) untuk secan(%lf)\n", derajat);
		}else{
			return 1 / cos_val;
		}
    }
}
double HitungCotan(double derajat) {
    double rad = derajat * PI / 180;
    double tan_val = tangen(rad);

    // Memeriksa kondisi tak terdefinisi
    if (tan_val == 0) {
        printf("Nilai tak terdefinisi (undefined) untuk cotan(%lf)\n", derajat);
        return 0.0;
    } else {
    	if (derajat == 180 || derajat == 360){
        	printf("Nilai tak terdefenisi (undefined) untuk cosec(%lf)\n", derajat);
		}else{
			return 1 / tan_val;
		}
    }
}

//program untuk invers trigonometri

double Inverse_Sin(double angka) {
    double batas_bawah = -1.0;
    double batas_atas = 1.0;
    double toleransi = 0.00001;
    double tebakan = (batas_atas + batas_bawah) / 2.0;
    double nilai = sinus(tebakan);

	//penggunaan binary search dimana dibagi dua kategori
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

	//penggunaan binary search dimana dibagi dua kategori
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
    double batas_atas = PI / 2.0;
    double batas_bawah = -PI / 2.0;
    double inverse = (batas_atas + batas_bawah) / 2.0;
    int iterations = 10;	//10 kali iterasi pencarian nilai 
    int i;

	//penggunaan binary search dimana dibagi dua kategori
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

#endif


