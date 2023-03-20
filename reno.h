#include <stdio.h>
#include "adi.h"

double logBase(double angka) // modul log natural, fungsi ini menerima sebuah argumen berupa bilangan yang akan dihitung logaritma basis e nya, dengan parameter angka berjenis input
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
    	temp = -(temp);
	}
     while (temp > 1e-10) { // hingga suku terakhir sudah sangat kecil
        hasil += temp;
        i++;
        temp = pangkat((angka - 1) / angka, i) / i; //menggunakan fungsi pangkat yang ada pada adi.h
    }
     return hasil;
}
