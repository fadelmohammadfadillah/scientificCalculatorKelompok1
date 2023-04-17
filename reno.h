#include <stdio.h>
#include "adi.h"

double logNature(double angka) // modul log natural, fungsi ini menerima sebuah argumen berupa bilangan yang akan dihitung logaritma basis e nya, dengan parameter angka berjenis input
	{
     if (angka <= 0) {
        return NAN; // NaN (Not a Number) jika angka negatif atau nol
	}
	 //deklarasi variabel hasil dan term yang akan digunakan sebagai penampung.
     double hasil = 0.0;
	 //hasil digunakan untuk menyimpan hasil perhitungan log berbasis e
     double temp = (angka - 1) / angka; 
	 //term menyimpan nilai suku deret taylor
     double i = 1;
     
     if(temp < 0)//untuk mengganti FABS yang ada pada liblary math.h agar hasil tetap positif
	{
    	temp = -(temp); //agar nilai yang negatif diubah menjadi positif
	}
     while (temp > 0.0000000001) { // hingga suku terakhir sudah sangat kecil
        hasil = hasil + temp;
        i++;
        temp = pangkat((angka - 1) / angka, i) / i; //menggunakan fungsi pangkat yang ada pada adi.h
    }
     return hasil;
}

double Nilai_Euler(double angka){
	
	double hasil;
	double e = 2.71828; //definisi nilai euler
	hasil = angka * e;
	printf("%5f", hasil);
}
