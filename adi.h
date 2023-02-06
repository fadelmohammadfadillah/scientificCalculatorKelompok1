#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef adi
#define adi

long pangkat(int angka, int pangkat){
	int i;
	int hasil = 0;
	for (i = 0; i < pangkat;i++){
		hasil = pow(angka, pangkat);
	}
	return hasil;
}

double akar(int angka, int akar){
	int i;
	double hasil = 0;
	for (i = 0; i < akar;i++){
		hasil = pow(angka, 1.0/akar);
	}
	return hasil;
}


void inputAngka (int *angka, int *angka2, char *jenisEksponen){
	printf("Masukan angka : ");
	scanf("%d", &(*angka));
	printf("Masukan %s : ", jenisEksponen);
	scanf("%d", &(*angka2));
}


void outputPangkat(int hasil){
	printf("Hasil dari pangkat adalah %d\n", hasil);
}

void outputAkar(double hasil){
	printf("Hasil dari akar adalah %.5f\n", hasil);
}

void menuEksponen(){
	int angka = 0;
	int angka2 = 0;
	int pilihOperasi;
	long hasilPangkat = 0;
	double hasilAkar = 0;
	printf("Operasi\n");
	printf("1. Pangkat\n");
	printf("2. Akar\n");
	printf("3. Back home\n");
	printf("Silahkan pilih operasi : ");
	scanf("%d",&pilihOperasi);
	if(pilihOperasi == 1){
		system("cls");
		printf("Operasi pangkat\n");
		inputAngka(&angka, &angka2,"pangkat");
		hasilPangkat = pangkat(angka, angka2);
		outputPangkat(hasilPangkat);
		system("pause");
		system("cls");
		menuEksponen();
	}
	else if(pilihOperasi == 2){
		system("cls");
		printf("Operasi pangkat\n");
		inputAngka(&angka, &angka2,"akar");
		hasilAkar = akar(angka, angka2);
		outputAkar(hasilAkar);
		system("pause");
		system("cls");
		menuEksponen();
	}
	else if (pilihOperasi == 3){
		main();
	}
	else {
		printf("Silahkan pilih dengan benar");
	}
}

#endif
