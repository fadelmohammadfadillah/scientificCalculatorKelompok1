#ifndef adrian_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int pembilang;//bagian atas pecahan
	int penyebut;//bagian bawah pecahan
}pecahan;

//deklarasi modul
pecahan sederhana(pecahan p1);
pecahan sumP(pecahan p1, pecahan p2);
pecahan minP(pecahan p1, pecahan p2);
pecahan multiplyP(pecahan p1, pecahan p2);
pecahan divideP(pecahan p1, pecahan p2);
pecahan inputP();
void outputP(pecahan p1);
double logBase10(double angka);

pecahan sederhana(pecahan p1){
	pecahan hasil;
	hasil = p1;
	while(hasil.pembilang % 5 == 0  && hasil.penyebut % 5 == 0){
		hasil.pembilang = hasil.pembilang/5;
		hasil.penyebut = hasil.penyebut/5;
	}
	while(hasil.pembilang % 3 == 0  && hasil.penyebut % 3 == 0){
		hasil.pembilang = hasil.pembilang/3;
		hasil.penyebut = hasil.penyebut/3;
	}
	while(hasil.pembilang % 2 == 0  && hasil.penyebut % 2 == 0){
		hasil.pembilang = hasil.pembilang/2;
		hasil.penyebut = hasil.penyebut/2;
	}
	return hasil;
}

pecahan sumP(pecahan p1, pecahan p2){
	pecahan jumlah;
	jumlah.penyebut = p1.penyebut * p2.penyebut;
	jumlah.pembilang = ((jumlah.penyebut/p1.penyebut) * p1.pembilang) + ((jumlah.penyebut/p2.penyebut) * p2.pembilang);
	jumlah = sederhana(jumlah);
	return jumlah;
}

pecahan minP(pecahan p1, pecahan p2){
	pecahan hasil;
	hasil.penyebut = p1.penyebut * p2.penyebut;
	hasil.pembilang = ((hasil.penyebut/p1.penyebut) * p1.pembilang) - ((hasil.penyebut/p2.penyebut) * p2.pembilang);
	hasil = sederhana(hasil);
	return hasil;
}

pecahan multiplyP(pecahan p1, pecahan p2){
	pecahan hasil;
	hasil.penyebut = p1.penyebut * p2.penyebut;
	hasil.pembilang = p1.pembilang * p2.pembilang;
	hasil = sederhana(hasil);
	return hasil;
}

pecahan divideP(pecahan p1, pecahan p2){
	pecahan hasil;
	hasil.penyebut = p1.penyebut * p2.pembilang;
	hasil.pembilang = p1.pembilang * p2.penyebut;
	hasil = sederhana(hasil);
	return hasil;
}

pecahan inputP(){
	pecahan p;
	printf("\nSilahkan input pembilang : ");
	scanf("%d", &p.pembilang);
	printf("\nSilahkan input penyebut : ");
	scanf("%d", &p.penyebut);
	return p;
}

void outputP(pecahan p1){
	printf("%d/%d", p1.pembilang, p1.penyebut);
}

void menuPecahan(){
	pecahan p1, p2,hasil;
	p1 = inputP();
	outputP(p1);
	p2 = inputP();
	outputP(p2);
	printf("\n");
	hasil = sumP(p1, p2);
	outputP(p1);printf("+");outputP(p2);printf("=");outputP(hasil);printf("\n");
	hasil = minP(p1, p2);
	outputP(p1);printf("-");outputP(p2);printf("=");outputP(hasil);printf("\n");
	hasil = multiplyP(p1, p2);
	outputP(p1);printf("*");outputP(p2);printf("=");outputP(hasil);printf("\n");
	hasil = divideP(p1, p2);
	outputP(p1);printf(":");outputP(p2);printf("=");outputP(hasil);printf("\n");
}

double logBase10(double angka){
	return log10(angka);
}
#endif
