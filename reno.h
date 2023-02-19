#ifndef reno_h
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

double celcius, fahrenheit, reamur, kelvin;
int pilih;


double celcius_to_reamur(double celcius){
	return (celcius * 4 / 5);
}

double celcius_to_fahrenheit(double celcius){

	return ((celcius * 9/5) + 32);
}

double celcius_to_kelvin(double celcius){
	return (celcius + 273.15);
}

double fahrenheit_to_celcius(double fahrenheit){
	return ((fahrenheit * 5 / 9) + 32);
}

double fahrenheit_to_reamur(double fahrenheit){
	return ((fahrenheit * 4/9 )+32);
}

double fahrenheit_to_kelvin (double fahrenheit){
	return ((fahrenheit + 459.67)*(5/9));
}




void menu_pilih_celcius (){
	printf("Masukkan nilai celcius : ");
	scanf("%lf", &celcius);
	printf("silahkan memilih ingin mengkonversi celcius menjadi : \n");
	printf("1. Reamur\n2. Fahrenheit\n3. kelvin");
	tampil_hasil_konversi_celcius();
}

void tampil_hasil_konversi_celcius(){
	int pilih;
	double hasil_konversi;
	printf("\npilihan : ");
	scanf("%d", &pilih);
	switch (pilih){
		case 1 : {
		hasil_konversi = celcius_to_reamur(celcius);
			printf("Hasil konversinya adalah \n%.3lf Celcius = %.3lf Reamur", celcius, hasil_konversi);
			break;
		}case 2 : {
		hasil_konversi = celcius_to_fahrenheit(celcius);
			printf("Hasil konversinya adalah \n%.3lf Celcius = %.3lf Fahrenheit", celcius, hasil_konversi);
			break;
		}case 3 : {
		hasil_konversi = celcius_to_kelvin(celcius);
		printf("Hasil konversinya adalah\n%.3lf Celcius = %.3lf Kelvin", celcius, hasil_konversi);
		break;
		}
	}
}

void menu_pilih_fahrenheit(){
	printf("masukkan nilai Fahrenheit: ");
	scanf("%lf", &fahrenheit);
	printf("silahkan memilih ingin mengkonversi fahrenheit menjadi : \n");
	printf("1. Reamur\n2. Celcius\n3. Kelvin");
	tampil_hasil_konversi_fahrenheit();
}

void tampil_hasil_konversi_fahrenheit(){
	int pilih;
	double hasil_konversi;
	printf("\npilihan : ");
	scanf("%d", &pilih);
	switch (pilih){
		case 1 : {
		hasil_konversi = fahrenheit_to_reamur(fahrenheit);
			printf("Hasil konversinya adalah \n%.3lf Fahrenheit = %.3lf Reamur", fahrenheit, hasil_konversi);
			break;
		}case 2 : {
		hasil_konversi = fahrenheit_to_celcius(fahrenheit);
			printf("Hasil konversinya adalah \n%.3lf Fahrenheit = %.3lf Celcius", fahrenheit, hasil_konversi);
			break;
		}case 3 : {
		hasil_konversi = fahrenheit_to_kelvin(fahrenheit);
		printf("Hasil konversinya adalah\n%.3lf Fahrenheit = %.3lf Kelvin", fahrenheit, hasil_konversi);
		break;
		}
	}
}


void menu_pilih_tipe_suhu (){
	printf("anda ingin mengkonversi suhu : \n1. Celcius \n2. Fahrenheit \n3. Reamur \n4. Kelvin\n Pilih: ");
	scanf("%d", &pilih);
	switch (pilih){
		case 1 :{
			menu_pilih_celcius();
			break;
		}
		case 2:{
			menu_pilih_fahrenheit();
			break;
		}
		case 3: {
		//	menu_pilih_reamur();
			break;
		}
		case 4:{
		//	menu_pilih_kelvin();
			break;
		}
	}
}
#endif
