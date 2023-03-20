#include <stdio.h>
#ifndef adi_h
#define adi_h

//modul
double pangkat(double angka, double pangkat);
double akar(double angka, double pangkatAkar);
int faktorial(int angka);
//end modul

double pangkat(double angka, double pangkat){
	double hasil = 1; //untuk menyimpan hasil perpangkatan.
	int i;
	for (i = 1; i <= pangkat; i++) { //Loop sampai "i" kurang dari atau sama dengan nilai "pangkat".
	  hasil *= angka; //var "hasil" akan dikalikan dengan "angka" dan hasilnya di simpan di var "hasil".
	}
	return hasil;
}

double fabsolute(double angka){ //modul pengganti fabs dari math.h yang digunakan untuk mengecek jika negatif maka akan di kali negatif agar nilai abolute (tetap positif)
	if (angka < 0){
		return angka *- 1;
	}else{
		return angka;
	}
	
}

double akar(double angka, double pangkatAkar) { //menggunakan metode bisection
    double rendah = 0.0;
    double tinggi = angka;
    double tengah = (rendah + tinggi) / 2.0;
    double hasil = tengah;

    // loop sampai selisih hasil akar pangkat dengan angka kurang dari 0.0001
	while (fabsolute(hasil - angka) >= 0.0001) {
		double temp;
	    // hitung nilai tengah berdasarkan nilai rendah dan tinggi
	    tengah = (rendah + tinggi) / 2.0;
	    // hitung hasil akar pangkat dari nilai tengah
	    hasil = 1.0;
	    hasil = pangkat(tengah, pangkatAkar);
	    // jika selisih antara hasil dan angka kurang dari 0.0001
	    // kembalikan nilai tengah
	    if (fabsolute(hasil - angka) < 0.0001){ //jika negatif maka akan di ubah menjadi positif
	        return tengah;
	    }
	    // jika hasil kurang dari angka, naikkan nilai rendah menjadi nilai tengah
	    if (hasil < angka) {
	        rendah = tengah;
	    }
	    // jika hasil lebih dari angka, turunkan nilai tinggi menjadi nilai tengah
	    else {
	        tinggi = tengah;
	    }
	}
	// kembalikan nilai tengah jika selisih antara hasil dan angka kurang dari 0.0001
	return tengah;
}

int faktorial(int angka){
	int fac = 1; //untuk menyimpan hasil faktorial
	int i;
    for(i = 1; i <= angka; i++){ //Loop sampai "i" kurang dari atau sama dengan nilai "angka".
        fac *= i; //var "fac" akan dikalikan dengan "i" dan hasilnya di simpan di var "fac".
    }
	return fac;
}

#endif
