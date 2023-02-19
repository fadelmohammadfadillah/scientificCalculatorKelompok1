#include <stdio.h>
#include <math.h>
#include <string.h>
#define String char*

#ifndef adi
#define adi

//modul
long pangkat(int angka, int pangkat);
double akar(int angka, int akar);
void inputAngka (int *angka, int *angka2, char *jenisEksponen);
void outputPangkat(int angka, int angka2, long hasil);
void outputAkar(int angka, int angka2, double hasil);
void menuEksponen();
void menuFaktorialPermutasiKombinasi();
long faktorial(long angka);
long permutasi(long n, long r);
long kombinasi(long n, long r);
//end modul

//fitur 3
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


void outputPangkat(int angka, int angka2, long hasil){
	printf("Hasil dari %d pangkat %d adalah %ld\n", angka, angka2, hasil);
	system("pause");
	system("cls");
	menuEksponen();
}

void outputAkar(int angka, int angka2, double hasil){
	printf("Hasil dari %d akar %d  adalah %.5f\n", angka, angka2, hasil);
	system("pause");
	system("cls");
	menuEksponen();
}

void menuEksponen(){
	int angka = 0;
	int angka2 = 0;
	int pilihMenu;
	long hasilPangkat = 0;
	double hasilAkar = 0;
	printf("Menu\n");
	printf("1. Pangkat\n");
	printf("2. Akar\n");
	printf("3. Back to home\n");
	printf("Silahkan pilih menu : ");
	scanf("%d",&pilihMenu);
	switch (pilihMenu){
		case 1:
			system("cls");
			printf("Operasi pangkat\n");
			inputAngka(&angka, &angka2,"pangkat");
			hasilPangkat = pangkat(angka, angka2);
			outputPangkat(angka, angka2, hasilPangkat);
		break;
		case 2:
			system("cls");
			printf("Operasi pangkat\n");
			inputAngka(&angka, &angka2,"akar");
			hasilAkar = akar(angka, angka2);
			outputAkar(angka, angka2, hasilAkar);
		break;
		case 3:
			system("cls");
			main();
		break;
		default:
			printf("Kesalahan inputan!");
		break;	
	}
}
//end fitur 3

//fitur 8
void menuFaktorialPermutasiKombinasi(){
	int pilihMenu = 0;
	long n, r, hasil;
	printf("Menu\n");
	printf("1. Faktorial\n");
	printf("2. Permutasi\n");
	printf("3. Kombinasi\n");
	printf("4. Back to home\n");
	printf("Silahkan pilih menu : ");
	scanf("%d",&pilihMenu);
	switch (pilihMenu){
		case 1:
		    printf("\nMasukan n: ");
		    scanf("%ld", &n);
			hasil = faktorial(n);
			printf ("Faktorial dari %ld! adalah %ld\n",n, hasil);
			system("pause");
			system("cls");
			menuFaktorialPermutasiKombinasi();
		break;
		case 2:
		    printf("\nMasukan n: ");
		    scanf("%ld", &n);
		    printf("\nMasukan r: ");
		    scanf("%ld", &r);
		    hasil = permutasi(n,r);
		    printf ("Permutasi dari n = %ld! dan r = %ld! adalah %ld\n",n, r, hasil);
			system("pause");
			system("cls");
			menuFaktorialPermutasiKombinasi();
		break;
		case 3:
			printf("\nMasukan n: ");
		    scanf("%ld", &n);
		    printf("\nMasukan r: ");
		    scanf("%ld", &r);
		    hasil = kombinasi(n,r);
		    printf ("Kombinasi dari n = %ld! dan r = %ld! adalah %ld\n",n, r, hasil);
			system("pause");
			system("cls");
			menuFaktorialPermutasiKombinasi();
		break;
		case 4:
			system("cls");
			main();
		break;
		default:
			printf("Kesalahan inputan!");
		break;
	}
}

long faktorial(long angka){
	long fac, i;
    fac = 1;
    for(i = 1; i <= angka; i++){
        fac *= i;
    }
	return fac;
}

long permutasi(long n, long r){
	long hasil;
    if(n >= r && n > 0 && r >= 0){
	    hasil = faktorial(n) / faktorial(n - r);
    }
    else{
    	printf("Error! n harus >= r\n");
    }
    return hasil;
}

long kombinasi(long n, long r){
	long hasil;
    if((n >= r) && (n > 0) && (r >= 0)){
	    hasil = faktorial(n) / (faktorial(r) * faktorial(n - r));
    }
    else{
    	printf("Error! n harus >= r\n");
    }
    return hasil;
}
//end fitur 8

#endif
