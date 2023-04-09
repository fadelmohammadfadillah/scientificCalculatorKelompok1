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

double tangen(double x) { // fungsi tangen dalam radian
    return sinus(x) / kosinus(x);
}

//double tangen(double x) {
//    double hasil = x; //menyimpan hasil perhitungan tangen nantinya
//    double pangkat = x; //menyimpan nilai pangkat dari x dalam perhitungan deret tylor
//    double faktorial = 1; //menyimpan nilai faktorial pada perhitungan deret tylor
//    double tambahan = x; //nilai tambahan dari setiap suku deret
//    int i; /*merepresentasikan bilangan ganjil dalam iterasi, untuk menghitung 
//        faktorial dari bilangan tersebut dan bilangan sebelumnya*/
//    int tanda = -1; //digunakan untuk mengubah tanda dari setiap suku deret
//    for (i = 3; i <= 19; i += 2) {
//        pangkat *= x * x;
//        faktorial *= i * (i - 1);
//        tambahan = tanda * (pangkat / faktorial);
//        hasil += tambahan;
//        tanda *= -1; //nilai akan bergantian positif dan negatif saat iterasi agar hasil lebih akurat
//    }
//    return hasil;
//}

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

#endif


