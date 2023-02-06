#ifndef adrian_h
#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int pembilang;
	int penyebut;
}pecahan;



pecahan sumP(pecahan p1, pecahan p2){
	pecahan jumlah;
	jumlah.penyebut = p1.penyebut * p2.penyebut;
	jumlah.pembilang = ((jumlah.penyebut/p1.penyebut) * p1.pembilang) + ((jumlah.penyebut/p2.penyebut) * p2.pembilang);
	int i;
	while(jumlah.pembilang % 2 == 0  && jumlah.penyebut % 2 == 0){
		jumlah.pembilang = jumlah.pembilang/2;
		jumlah.penyebut = jumlah.penyebut/2;
	}
	while(jumlah.pembilang % 3 == 0  && jumlah.penyebut % 3 == 0){
		jumlah.pembilang = jumlah.pembilang/3;
		jumlah.penyebut = jumlah.penyebut/3;
	}
	return jumlah;
}
pecahan input(){
	pecahan p;
	printf("\nSilahkan input pembilang : ");
	scanf("%d", &p.pembilang);
	printf("\nSilahkan input penyebut : ");
	scanf("%d", &p.penyebut);
	return p;
}

void output(pecahan p1){
	printf("%d/%d", p1.pembilang, p1.penyebut);
}


void menuPecahan(){
	pecahan p1, p2,hasil;
	p1 = input();
	output(p1);
	p2 = input();
	output(p2);
	printf("\n");
	hasil = sumP(p1, p2);
	output(p1);printf("+");output(p2);printf("=");output(hasil);
}
#endif
