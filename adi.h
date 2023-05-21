#include <stdio.h>
#ifndef adi_h
#define adi_h

//modul
double pangkat(double angka, double pangkat);
double akar(double angka, double pangkatAkar);
int faktorial(int angka);
//end modul

double pangkat(double angka, double pangkat){
	int i;
	double hasil = 1;
	if (pangkat == (int) pangkat){
		for (i = 1; i <= pangkat; i++) { //Loop sampai "i" kurang dari atau sama dengan nilai "pangkat".
			hasil *= angka; //var "hasil" akan dikalikan dengan "angka" dan hasilnya di simpan di var "hasil".c
		}
	}
	else {
		pangkat = pangkat * 10;
		for (i = 1; i <= pangkat; i++) { //pangkat desimal
			hasil *= angka;
		}
		hasil = akar(hasil, 10);
	}
	return hasil;
}

double akar(double angka, double pangkatAkar) {
    double hasil = 1.0;
    double pangkatAkarN = 1.0/pangkatAkar;
    int i;
    for (i = 0; i < 100; i++) {
        hasil = (pangkatAkar - 1) * hasil + angka / pangkat(hasil, pangkatAkar - 1);
        hasil *= pangkatAkarN;
    }
    return hasil;
}


int faktorial(int angka){
	int hasil = 1; //untuk menyimpan hasil faktorial
	int i;
    for(i = 1; i <= angka; i++){ //Loop sampai "i" kurang dari atau sama dengan nilai "angka".
        hasil *= i; //var "hasil" akan dikalikan dengan "i" dan hasilnya di simpan di var "hasil".
    }
	return hasil;	
}

#endif
