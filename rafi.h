#ifndef rafi_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "alya1.h"
#define PI 3.14159

double HitungSin(double derajat){
	double rad =derajat * PI / 180;
    return sin(rad);
}
double HitungCos(double derajat){
	double rad =derajat * PI / 180;
    return cos(rad);
}
double HitungTan(double derajat){
	double rad =derajat * PI / 180;
    return tangen(rad);
}
void MenuTrigonometri(){
    double numInDegree, numInRad, jawaban;
    int pilihan, is_on = 1;

    while(is_on == 1){
    	printf("1. Hitung Sin\n");
	    printf("2. Hitung Cos\n");
	    printf("3. Hitung Tan\n");
	    printf("4. Kembali ke menu\n");
	    scanf("%d", &pilihan);
	    fflush(stdin);
	    numInRad = numInDegree * PI / 180;
	    switch (pilihan){
			case 1: {printf("Masukkan angka dalam derajat: ");
	    	scanf("%lf", &numInDegree);
			fflush(stdin);
	        jawaban=HitungSin(numInRad);
	        printf("sin %.2lf adalah: %.3lf\n", numInDegree, jawaban);
	        system("pause");
			system("cls");
			break;
			}
			case 2: {printf("Masukkan angka dalam derajat: ");
	    	scanf("%lf", &numInDegree);
			fflush(stdin);
	        jawaban=HitungCos(numInRad);
	        printf("cos %.2lf adalah: %.3lf\n", numInDegree, jawaban);
	        system("pause");
			system("cls");
			break;
			}
			case 3: {printf("Masukkan angka dalam derajat: ");
		    scanf("%lf", &numInDegree);
			fflush(stdin);
	        jawaban=HitungTan(numInRad);
	        printf("tan %.2lf adalah: %.3lf\n", numInDegree, jawaban);
	        system("pause");
			system("cls");
			break;
			}
			case 4: {fflush(stdin);
			system("cls");
			is_on = 0;
			break;
			}
			default: {
				printf("\n\n---Invalid Input---\n\n---Mohon Ulangi---\n");
				system("pause");
				system("cls");
				MenuTrigonometri();
				break;
			}
		}
	}
}
#endif
