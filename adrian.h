#ifndef adrian_h
#include <stdio.h>
#include <stdlib.h>
#include "reno.h"
#include <math.h> 
#define iterasiLog 0.00001

double logBase10(double angka){
	/*
	Modul ini berfungsi untuk menghitung logaritma basis 10 dengan metode perulangan, 
	Modul ini menerima inputan(parameter) angka yang bertipe double
	Modul ini akan memberikan output berupa hasil logaritma basis 10 dari var angka, outputnya bertipe double
	temp : var untuk penampungan hasil sementara untuk mencari pangkat yang mendekati angka yang ada di parameter
	hasil : var untuk menampung untuk hasil
	j : var untuk menampung looping dari pangkat koma
	x : var untuk menampung angka yang dimasukan user agar var angka tidak berubah saat membagi dengan 10(basis)
	*/
	double hasil = 0, temp = 0, j=0, x;
	if(angka<=0){//Jika angka negatif atau 0
		printf("Error ");
		return 0;
	}
	x=angka;
	while (x >= 10) {//perulangan selama x lebih dari atau sama dengan 10(basis)
        x = x/10;//x dibagi 10(basis)
        hasil++;//maka hasil ditambah 1	
    }
    if(x != 1){//Jika setelah dibagi masih ada sisa
	    while(temp < angka){//maka lakukan perulangan hingga var temp lebih atau sama dengan var angka
	    	j = j+iterasiLog;//setiap looping j ditambahkan dengan iterasi
	    	temp = pow(10, hasil+j);//temp diisi dengan hasil dari 10 pangkat hasil+j
//	    	printf("j:%f,temp:%f ", j+hasil,temp);
		}
		return hasil += j - iterasiLog;//hasil dikurangi iterasiLog agar hasil tetap akurat
	}else{//Jika setelah dibagi x == 1(hasil dari log tidak memiliki koma)
		return hasil;
	}
	
}

double logBase(double angka, double basis){
	/*
	Modul ini berfungsi untuk menghitung logaritma basis bebas dengan metode perulangan, 
	Modul ini menerima inputan(parameter) angka dan basis yang bertipe double
	Modul ini akan memberikan output berupa hasil logaritma basis bebas dari var angka, outputnya bertipe double
	temp : var untuk penampungan hasil sementara untuk mencari pangkat yang mendekati angka yang dimasukan user
	hasil : var untuk menampung untuk hasil
	j : var untuk menampung pangkat yang mendekati angka yang dimasukan user
	x : var untuk menampung angka yang dimasukan user agar angka tidak berubah saat membagi dengan base
	*/
	if(angka<=0 || basis<=0){//Jika angka atau basis kurang dari sama dengan 0
		printf("Error ");
		return 0;
	}
	double x, temp = 0, hasil = 0, j = 0.0;
	x=angka;
	if(angka == basis){//Jika value dari angka dan basis sama, maka return 1
		return 1;
	}else if(angka > basis){
		while (x >= basis) {//perulangan selama x lebih dari atau sama dengan basis
        x = x/basis;//x dibagi basis
        hasil++;//maka hasil ditambah 1
    	}
    }
    if(x != 1){//Jika setelah dibagi masih ada sisa
	    while(temp < angka){//maka lakukan perulangan hingga var hingga temp lebih atau sama dengan var angka
	    	j = j+iterasiLog;//setiap looping j ditambahkan dengan iterasi
	    	temp = pow(basis, hasil+j);//temp diisi dengan hasil dari base pangkat hasil+j
//	    	printf("j:%f,temp:%f ", j,temp);
		}
		return hasil += j - iterasiLog;//hasil dikurangi iterasiLog agar hasil tetap akurat
	}else{//Jika setelah dibagi x == 1(hasil dari log tidak memiliki koma)
		return hasil;
	}
}

//
//typedef struct{
//	int pembilang;//bagian atas pecahan
//	int penyebut;//bagian bawah pecahan
//}pecahan;
//
////deklarasi modul
//pecahan sederhana(pecahan p1);
//pecahan sumP(pecahan p1, pecahan p2);
//pecahan minP(pecahan p1, pecahan p2);
//pecahan multiplyP(pecahan p1, pecahan p2);
//pecahan divideP(pecahan p1, pecahan p2);
//pecahan inputP();
//void outputP(pecahan p1);
//double logBase10(double angka);
//
//pecahan sederhana(pecahan p1){
//	pecahan hasil;
//	hasil = p1;
//	while(hasil.pembilang % 5 == 0  && hasil.penyebut % 5 == 0){
//		hasil.pembilang = hasil.pembilang/5;
//		hasil.penyebut = hasil.penyebut/5;
//	}
//	while(hasil.pembilang % 3 == 0  && hasil.penyebut % 3 == 0){
//		hasil.pembilang = hasil.pembilang/3;
//		hasil.penyebut = hasil.penyebut/3;
//	}
//	while(hasil.pembilang % 2 == 0  && hasil.penyebut % 2 == 0){
//		hasil.pembilang = hasil.pembilang/2;
//		hasil.penyebut = hasil.penyebut/2;
//	}
//	return hasil;
//}
//
//pecahan sumP(pecahan p1, pecahan p2){
//	pecahan jumlah;
//	jumlah.penyebut = p1.penyebut * p2.penyebut;
//	jumlah.pembilang = ((jumlah.penyebut/p1.penyebut) * p1.pembilang) + ((jumlah.penyebut/p2.penyebut) * p2.pembilang);
//	jumlah = sederhana(jumlah);
//	return jumlah;
//}
//
//pecahan minP(pecahan p1, pecahan p2){
//	pecahan hasil;
//	hasil.penyebut = p1.penyebut * p2.penyebut;
//	hasil.pembilang = ((hasil.penyebut/p1.penyebut) * p1.pembilang) - ((hasil.penyebut/p2.penyebut) * p2.pembilang);
//	hasil = sederhana(hasil);
//	return hasil;
//}
//
//pecahan multiplyP(pecahan p1, pecahan p2){
//	pecahan hasil;
//	hasil.penyebut = p1.penyebut * p2.penyebut;
//	hasil.pembilang = p1.pembilang * p2.pembilang;
//	hasil = sederhana(hasil);
//	return hasil;
//}
//
//pecahan divideP(pecahan p1, pecahan p2){
//	pecahan hasil;
//	hasil.penyebut = p1.penyebut * p2.pembilang;
//	hasil.pembilang = p1.pembilang * p2.penyebut;
//	hasil = sederhana(hasil);
//	return hasil;
//}
//
//pecahan inputP(){
//	pecahan p;
//	printf("\nSilahkan input pembilang : ");
//	scanf("%d", &p.pembilang);
//	printf("\nSilahkan input penyebut : ");
//	scanf("%d", &p.penyebut);
//	return p;
//}
//
//void outputP(pecahan p1){
//	printf("%d/%d", p1.pembilang, p1.penyebut);
//}
//
//void menuPecahan(){
//	pecahan p1, p2,hasil;
//	p1 = inputP();
//	outputP(p1);
//	p2 = inputP();
//	outputP(p2);
//	printf("\n");
//	hasil = sumP(p1, p2);
//	outputP(p1);printf("+");outputP(p2);printf("=");outputP(hasil);printf("\n");
//	hasil = minP(p1, p2);
//	outputP(p1);printf("-");outputP(p2);printf("=");outputP(hasil);printf("\n");
//	hasil = multiplyP(p1, p2);
//	outputP(p1);printf("*");outputP(p2);printf("=");outputP(hasil);printf("\n");
//	hasil = divideP(p1, p2);
//	outputP(p1);printf(":");outputP(p2);printf("=");outputP(hasil);printf("\n");
//}

#endif
