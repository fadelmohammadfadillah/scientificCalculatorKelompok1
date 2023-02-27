#include <stdio.h>
#include <math.h>
#include <string.h>
#ifndef adi_h
#define adi_h

//modul
double pangkat(double angka, double pangkat);
double akar(double angka, double pangkatAkar);
void menuKombinasiPermutasi();
int faktorial(int angka);
int permutasi(int n, int r);
int kombinasi(int n, int r);
//end modul

double pangkat(double angka, double pangkat){
	double hasil = 0;
	hasil = pow(angka, pangkat);
	return hasil;
}

double akar(double angka, double pangkatAkar){
	double hasil = 0;
	hasil = pow(angka, 1.0/pangkatAkar);
	return hasil;
}

//fitur lain-lain
void menuKombinasiPermutasi(){
	int pilihMenu, n, r, hasil;
	printf("Menu\n");
	printf("1. Kombinasi\n");
	printf("2. Permutasi\n");
	printf("3. Back to home\n");
	printf("Silahkan pilih menu : ");
	scanf("%d",&pilihMenu);
	switch (pilihMenu){
		case 1:
			printf("n harus lebih dari atau sama dengan r\n");
			printf("Masukan n: ");
		    scanf("%d", &n);
		    printf("Masukan r: ");
		    scanf("%d", &r);
		    hasil = kombinasi(n,r);
		    printf ("Kombinasi dari n = %d! dan r = %d! adalah %d\n",n, r, hasil);
			system("pause");
			system("cls");
			menuKombinasiPermutasi();
		break;
		case 2:
			printf("n harus lebih dari atau sama dengan r\n");
			printf("Masukan n: ");
		    scanf("%d", &n);
		    printf("Masukan r: ");
		    scanf("%d", &r);
		    hasil = permutasi(n,r);
		    printf ("Permutasi dari n = %d! dan r = %d! adalah %d\n",n, r, hasil);
			system("pause");
			system("cls");
			menuKombinasiPermutasi();
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

int faktorial(int angka){
	int fac;
	int i;
    fac = 1;
    for(i = 1; i <= angka; i++){
        fac *= i;
    }
	return fac;
}

int permutasi(int n, int r){
	int hasil;
    if((n >= r) && (n > 0) && (r >= 0)){
	    hasil = faktorial(n) / faktorial(n - r);
    }
    else{
    	printf("Error! n harus >= r\n");
    }
    return hasil;
}

int kombinasi(int n, int r){
	int hasil;
    if((n >= r) && (n > 0) && (r >= 0)){
	    hasil = faktorial(n) / (faktorial(r) * faktorial(n - r));
    }
    else{
    	printf("Error! n harus >= r\n");
    }
    return hasil;
}
//end fitur lain-lain

#endif
