#ifndef reno_h
#define reno_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double kilometer, hektometer,dekameter,meter,desimeter,centimeter,milimeter;
double celcius, fahrenheit, reamur, kelvin;
int pilih;
double kilogram,hektogram,dekagram,gram,desigram,centigram,miligram;

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

double reamur_to_celcius (double reamur){
	return (reamur*5/4);
}

double reamur_to_fahrenheit(double reamur){
	return ((reamur * 9/4)+32);
}

double reamur_to_kelvin(double reamur){
	return ((reamur * 5/4)+273.15);
}

double kelvin_to_celcius(double kelvin){
	return  (kelvin - 273);
}

double kelvin_to_reamur(double kelvin){
	return ((kelvin-273) * 0.8);
}

double kelvin_to_fahrenheit(double kelvin){
	return ((kelvin-273)*(1.8) + 32);
}

void menu_pilih_celcius (){
	printf("Masukkan nilai celcius : ");
	scanf("%lf", &celcius);
	printf("silahkan memilih ingin mengkonversi celcius menjadi : \n");
	printf("1. Reamur\n2. Fahrenheit\n3. kelvin");
	tampil_hasil_konversi_celcius();
}

void tampil_hasil_konversi_celcius() {
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

void menu_pilih_reamur(){
	printf("masukkan nilai reamur: ");
	scanf("%lf", &reamur);
	printf("silahkan pilih ingin mengkonversi reamur menjadi : \n");
	printf("1. Celcius\n2. Fahrenheit\n3. Kelvin");
	tampil_hasil_konversi_reamur();
}

void tampil_hasil_konversi_reamur(){

	int pilih;
	double hasil_konversi;
	printf("\npilihan : ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1 :{
			hasil_konversi = reamur_to_celcius(reamur);
			printf("Hasil konversinya adalah\n%.3lf Reamur = %.3lf Celcius", reamur, hasil_konversi);
			break;
		} case 2 : {
		hasil_konversi = reamur_to_fahrenheit(reamur);
		printf("Hasil konversinya adalah\n%.3lf Reamur = Fahrenheit");
		break ; 
		} case 3 :{
		hasil_konversi = reamur_to_kelvin(reamur);
		printf("Hasil konversinya adalah\n%.3lf Reamur = Kelvin");
		break; 
		}
	}
}

void menu_pilih_kelvin(){

	printf("masukkan nilai kelvin: ");
	scanf("%lf", &kelvin);
	printf("silahkan memilih ingin mengkonversi kelvin menjadi : \n");
	printf("1. Reamur\n2. Celcius\n3. Fahrenheit");
	tampil_hasil_konversi_kelvin();
}


void tampil_hasil_konversi_kelvin(){

	int pilih;
	double hasil_konversi;
	printf("\npilihan : ");
	scanf("%d", &pilih);
	switch (pilih){
		case 1 : {
		hasil_konversi = kelvin_to_reamur(kelvin);
			printf("Hasil konversinya adalah \n%.3lf Fahrenheit = %.3lf Reamur", kelvin, hasil_konversi);
			break;
		}case 2 : {
		hasil_konversi = kelvin_to_celcius(kelvin);
			printf("Hasil konversinya adalah \n%.3lf Fahrenheit = %.3lf Celcius", kelvin, hasil_konversi);
			break;
		}case 3 : {
		hasil_konversi = kelvin_to_fahrenheit(kelvin);
		printf("Hasil konversinya adalah\n%.3lf Fahrenheit = %.3lf Kelvin", kelvin, hasil_konversi);
		break;
		}
	}
}

void menu_pilih_tipe_suhu ()
{
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
			menu_pilih_reamur();
			break;
		}
		case 4:{
			menu_pilih_kelvin();
			break;
		}
	}
}



//konversi km ke h
double KM_to_H(double kilometer){
	return (kilometer * 10);	
}


//konversi km ke dam 
double KM_to_DAM(double kilometer){
	return (kilometer *100);
}

//konversi km ke m
double KM_to_M(double kilometer){
	return (kilometer * 1000);
}

//konversi km ke cm
double KM_to_CM(double kilometer){
	return (kilometer * 100000);
}

//konversi km ke dm 
double KM_to_DM(double desimeter){
	return (kilometer * 10000);
}

//konversi km ke mm 
double KM_to_MM(double kilometer){
	return (kilometer * 1000000);
}


//konversi hm ke km
double HM_to_KM(double hektometer){
	return (hektometer / 10);
}

//konversi hm ke dam
double HM_to_DAM(double hektometer){
	return (hektometer * 10);
}

//konversi hm ke m
double HM_to_M(double hektometer){
	return (hektometer * 100);
}

//konversi hm ke dm
double HM_to_DM(double hektometer){
	return (hektometer * 1000);
}

//konversi hm ke cm
double HM_to_CM(double hektometer){
	return (hektometer * 10000);
}

//konversi hm ke mm
double HM_to_MM(double hektometer){
	return (hektometer * 100000);
}

//konversi dam ke km
double DAM_to_KM(double dekameter){
	return (dekameter / 100);
}

//konversi dam ke hm
double DAM_to_HM(double dekameter){
	return (dekameter / 10);
}

//konversi dam ke m
double DAM_to_M(double dekameter){
	return (dekameter * 10);
}

//konversi dam ke dm
double DAM_to_DM(double dekameter){
	return (dekameter * 100);
}

//konversi dam ke cm
double DAM_to_CM(double dekameter){
	return (dekameter * 1000);
}

//konversi dam ke mm
double DAM_to_MM(double dekameter){
	return (dekameter * 10000);
}

//konversi m ke km
double M_to_KM(double meter){
	return (meter / 1000);
}

//konversi m ke hm
double M_to_HM(double meter){
	return (meter / 100);
}

//konversi m ke dam
double M_to_DAM(double meter){
	return (meter / 10);
}

//konversi m ke dm
double M_to_DM(double meter){
	return (meter * 10);
}

//konversi m ke cm
double M_to_CM(double meter){
	return (meter * 100);
}

//konversi m ke mm
double M_to_MM(double meter){
	return (meter * 1000);
}

//konversi dm ke km
double DM_to_KM(double desimeter){
	return (desimeter / 10000);
}

//konversi dm ke hm
double DM_to_HM(double desimeter){
	return (desimeter / 1000);
}

//konversi dm ke dam
double DM_to_DAM(double desimeter){
	return (desimeter / 100);
}

//konversi dm ke m
double DM_to_M(double desimeterr){
	return (desimeter / 10);
}

//konversi dm ke cm
double DM_to_CM(double desimeterr){
	return (desimeter * 10);
}

//konversi dm ke mm
double DM_to_MM(double desimeter){
	return (desimeter * 100);
}

//konversi cm ke km
double CM_to_KM(double centimeter){
	return (centimeter / 100000);
}

//konversi cm ke hm
double CM_to_HM(double centimeter){
	return (centimeter / 10000);
}

//konversi cm ke dam
double CM_to_DAM(double centimeter){
	return (centimeter / 1000);
}

//konversi cm ke m
double CM_to_M(double centimeter){
	return (centimeter / 100);
}

//konversi cm ke dm
double CM_to_DM(double centimeter){
	return (centimeter / 10);
}

//konversi cm ke mm
double CM_to_MM(double desimeterr){
	return (centimeter * 10);
}

//konversi mm ke km
double MM_to_KM(double milimeter){
	return (milimeter / 1000000);
}

//konversi mm ke hm
double MM_to_HM(double milimeter){
	return (milimeter / 100000);
}

//konversi mm ke dam
double MM_to_DAM(double milimeter){
	return (milimeter / 10000);
}

//konversi mm ke m
double MM_to_M(double milimeter){
	return (milimeter / 1000);
}

//konversi mm ke dm
double MM_to_DM(double milimeter){
	return (milimeter / 100);
}

//konversi mm ke cm
double MM_to_CM(double milimeter){
	return (milimeter / 10);
}

void memilih_tipe_jarak(){
	int pilihan;
	printf("!!!Note!!!\nTanda '.' (titik) menunjukan koma bukan sebagai pembatas satuan, puluhan, ribuan dst.\n\n");
	printf("Pilih konversi : \n");
	printf("1. Kilometer\n");
	printf("2. Hektometer\n");
	printf("3. Dekameter\n");
	printf("4. Meter\n");
	printf("5. Desimeter\n");
	printf("6. Centimeter\n");
	printf("7. Milimeter\n");
	printf("Masukkan Pilihan : ");
	scanf("%d", &pilihan);
	
	switch(pilihan){
		case 1:
			konversi_km();
			break;
		case 2:
			konversi_hm();
			break;
		case 3:
			konversi_dam();
			break;
		case 4:
			konversi_m();
			break;
		case 5:
			konversi_dm();
			break;
		case 6:
			konversi_cm();
			break;
		case 7:
			konversi_mm();
			break;
		defaults:
			printf("pilihan tidak tersedia");
	}
		
} 

void konversi_km(){
	printf("\nSilahkan masukkan nilai Kilometer terlebih dahulu\n");
	printf("Nilai Kilometer : ");
	scanf("%lf", &kilometer);
	printf("Pilih konversi Km ke : \n");
	printf("1. Hm\n");
	printf("2. Dam\n");
	printf("3. M\n");
	printf("4. Dm\n");
	printf("5. Cm\n");
	printf("6. MM\n");
	tampil_hasil_konversi_Km();
}

void tampil_hasil_konversi_Km(double jarak){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = KM_to_H(kilometer);
			printf("Hasil konversinya adalah %.3lf Km = %.2lf Hm", kilometer, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = KM_to_DAM(kilometer);
			printf("Hasil konversinya adalah %.3lf Km = %.2lf Dkm", kilometer, hasil_konversi);
		break;
		case 3:
			hasil_konversi = KM_to_M(kilometer);
			printf("Hasil konversinya adalah %.3lf Km = %.2lf M", kilometer, hasil_konversi);
		break;
		case 4:
			hasil_konversi = KM_to_DM(kilometer);
			printf("Hasil konversinya adalah %.3lf Km = %.2lf Dm", kilometer, hasil_konversi);
		break;
		case 5:
			hasil_konversi = KM_to_CM(kilometer);
			printf("Hasil konversinya adalah %.3lf Km = %.2lf Cm", kilometer, hasil_konversi);
		break;
		case 6:
			hasil_konversi = KM_to_MM(kilometer);
			printf("Hasil konversinya adalah %.3lf Km = %.2lf MM", kilometer, hasil_konversi);
		break;
	}
}

void konversi_hm(){
	printf("\nSilahkan masukkan nilai Hektometer terlebih dahulu\n");
	printf("Nilai Hektometer : ");
	scanf("%lf", &hektometer);
	printf("Pilih konversi Hm ke : \n");
	printf("1. Km\n");
	printf("2. Dam\n");
	printf("3. M\n");
	printf("4. Dm\n");
	printf("5. Cm\n");
	printf("6. MM\n");
	tampil_hasil_konversi_Hm();
}

void tampil_hasil_konversi_Hm(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = HM_to_KM(hektometer);
			printf("Hasil konversinya adalah %.3lf Hm = %.3lf Km", hektometer, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = HM_to_DAM(hektometer);
			printf("Hasil konversinya adalah %.3lf Hm = %.3lf Dkm", hektometer, hasil_konversi);
		break;
		case 3:
			hasil_konversi = HM_to_M(hektometer);
			printf("Hasil konversinya adalah %.3lf Hm = %.3lf M", hektometer, hasil_konversi);
		break;
		case 4:
			hasil_konversi = HM_to_DM(hektometer);
			printf("Hasil konversinya adalah %.3lf Hm = %.3lf Dm", hektometer, hasil_konversi);
		break;
		case 5:
			hasil_konversi = HM_to_CM(hektometer);
			printf("Hasil konversinya adalah %.3lf Hm = %.3lf Cm", hektometer, hasil_konversi);
		break;
		case 6:
			hasil_konversi = HM_to_MM(hektometer);
			printf("Hasil konversinya adalah %.3lf Hm = %.3lf MM", hektometer, hasil_konversi);
		break;
	}
}

void konversi_dam(){
	printf("\nSilahkan masukkan nilai Dekameter terlebih dahulu\n");
	printf("Nilai Dekameter : ");
	scanf("%lf", &dekameter);
	printf("Pilih konversi Dam ke : \n");
	printf("1. Km\n");
	printf("2. Hm\n");
	printf("3. M\n");
	printf("4. Dm\n");
	printf("5. Cm\n");
	printf("6. MM\n");
	tampil_hasil_konversi_dam();
}

void tampil_hasil_konversi_dam(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = DAM_to_KM(dekameter);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf Km", dekameter, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = DAM_to_HM(dekameter);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf Hm", dekameter, hasil_konversi);
		break;
		case 3:
			hasil_konversi = DAM_to_M(dekameter);
			printf("Hasil konversinya adalah %.3lf Dam = %.33lf M", dekameter, hasil_konversi);
		break;
		case 4:
			hasil_konversi = DAM_to_DM(dekameter);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf Dm", dekameter, hasil_konversi);
		break;
		case 5:
			hasil_konversi = DAM_to_CM(dekameter);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf Cm", dekameter, hasil_konversi);
		break;
		case 6:
			hasil_konversi = DAM_to_MM(dekameter);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf MM", dekameter, hasil_konversi);
		break;
	}
}

void konversi_m(){
	printf("\nSilahkan masukkan nilai Meter terlebih dahulu\n");
	printf("Nilai Meter : ");
	scanf("%lf", &meter);
	printf("Pilih konversi M ke : \n");
	printf("1. Km\n");
	printf("2. Hm\n");
	printf("3. Dam\n");
	printf("4. Dm\n");
	printf("5. Cm\n");
	printf("6. MM\n");
	tampil_hasil_konversi_m();
}

void tampil_hasil_konversi_m(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = M_to_KM(meter);
			printf("Hasil konversinya adalah %.3lf M = %.3lf Km", meter, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = M_to_HM(meter);
			printf("Hasil konversinya adalah %.3lf M = %.3lf Hm", meter, hasil_konversi);
		break;
		case 3:
			hasil_konversi = M_to_DAM(meter);
			printf("Hasil konversinya adalah %.3lf M = %.3lf Dam", meter, hasil_konversi);
		break;
		case 4:
			hasil_konversi = M_to_DM(meter);
			printf("Hasil konversinya adalah %.3lf M = %.3lf Dm", meter, hasil_konversi);
		break;
		case 5:
			hasil_konversi = M_to_CM(meter);
			printf("Hasil konversinya adalah %.3lf M = %.3lf Cm", meter, hasil_konversi);
		break;
		case 6:
			hasil_konversi = M_to_MM(meter);
			printf("Hasil konversinya adalah %.3lf M = %.3lf MM", meter, hasil_konversi);
		break;
	}
}

void konversi_dm(){
	printf("\nSilahkan masukkan nilai Desimeter terlebih dahulu\n");
	printf("Nilai Desimeter : ");
	scanf("%lf", &desimeter);
	printf("Pilih konversi Dm ke : \n");
	printf("1. Km\n");
	printf("2. Hm\n");
	printf("3. Dam\n");
	printf("4. M\n");
	printf("5. Cm\n");
	printf("6. MM\n");
	tampil_hasil_konversi_dm();
}

void tampil_hasil_konversi_dm(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = DM_to_KM(desimeter);
			printf("Hasil konversinya adalah %.3lf Dm = %.3lf Km", desimeter, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = DM_to_HM(desimeter);
			printf("Hasil konversinya adalah %.3lf Dm = %.3lf Hm", desimeter, hasil_konversi);
		break;
		case 3:
			hasil_konversi = DM_to_DAM(desimeter);
			printf("Hasil konversinya adalah %.3lf Dm = %.3lf Dam", desimeter, hasil_konversi);
		break;
		case 4:
			hasil_konversi = DM_to_M(desimeter);
			printf("Hasil konversinya adalah %.3lf Dm = %.3lf M", desimeter, hasil_konversi);
		break;
		case 5:
			hasil_konversi = DM_to_CM(desimeter);
			printf("Hasil konversinya adalah %.3lf Dm = %.3lf Cm", desimeter, hasil_konversi);
		break;
		case 6:
			hasil_konversi = DM_to_MM(desimeter);
			printf("Hasil konversinya adalah %.3lf Dm = %.3lf MM", desimeter, hasil_konversi);
		break;
	}
}

void konversi_cm(){
	printf("\nSilahkan masukkan nilai Centimeter terlebih dahulu\n");
	printf("Nilai Centimeter : ");
	scanf("%lf", &centimeter);
	printf("Pilih konversi Cm ke : \n");
	printf("1. Km\n");
	printf("2. Hm\n");
	printf("3. Dam\n");
	printf("4. M\n");
	printf("5. Dm\n");
	printf("6. MM\n");
	tampil_hasil_konversi_cm();
}

void tampil_hasil_konversi_cm(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = CM_to_KM(centimeter);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf Km", centimeter, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = CM_to_HM(centimeter);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf Hm", centimeter, hasil_konversi);
		break;
		case 3:
			hasil_konversi = CM_to_DAM(centimeter);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf Dam", centimeter, hasil_konversi);
		break;
		case 4:
			hasil_konversi = CM_to_M(centimeter);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf M", centimeter, hasil_konversi);
		break;
		case 5:
			hasil_konversi = CM_to_DM(centimeter);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf Dm", centimeter, hasil_konversi);
		break;
		case 6:
			hasil_konversi = CM_to_MM(centimeter);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf MM", centimeter, hasil_konversi);
		break;
	}
}

void konversi_mm(){
	printf("\nSilahkan masukkan nilai Miliimeter terlebih dahulu\n");
	printf("Nilai Milimeter : ");
	scanf("%lf", &milimeter);
	printf("Pilih konversi mm ke : \n");
	printf("1. Km\n");
	printf("2. Hm\n");
	printf("3. Dam\n");
	printf("4. M\n");
	printf("5. Dm\n");
	printf("6. Cm\n");
	tampil_hasil_konversi_mm();
}

void tampil_hasil_konversi_mm(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = MM_to_KM(milimeter);
			printf("Hasil konversinya adalah %.3lf mm = %.3lf Km", milimeter, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = MM_to_HM(milimeter);
			printf("Hasil konversinya adalah %.3lf mm = %.3lf Hm", milimeter, hasil_konversi);
		break;
		case 3:
			hasil_konversi = MM_to_DAM(milimeter);
			printf("Hasil konversinya adalah %.3lf mm = %.3lf Dam", milimeter, hasil_konversi);
		break;
		case 4:
			hasil_konversi = MM_to_M(milimeter);
			printf("Hasil konversinya adalah %.3lf mm = %.3lf M", milimeter, hasil_konversi);
		break;
		case 5:
			hasil_konversi = MM_to_DM(milimeter);
			printf("Hasil konversinya adalah %.3lf mm = %.3lf Dm", milimeter, hasil_konversi);
		break;
		case 6:
			hasil_konversi = MM_to_CM(milimeter);
			printf("Hasil konversinya adalah %.3lf mm = %.3lf CM", milimeter, hasil_konversi);
		break;
	}
}


//konversi kg ke hg
double kg_to_hg(double kilogram){
	return (kilogram * 10);	
}

//konversi kg ke dag 
double kg_to_dag(double kilogram){
	return (kilogram *100);
}

//konversi kg ke g
double kg_to_g(double kilogram){
	return (kilogram * 1000);
}

//konversi kg ke dg 
double kg_to_dg(double kilogram){
	return (kilogram * 10000);
}

//konversi kg ke cg
double kg_to_cg(double kilogram){
	return (kilogram * 100000);
}

//konversi kg ke mg 
double kg_to_mg(double kilogram){
	return (kilogram * 1000000);
}


//konversi hg ke kg
double hg_to_kg(double hektogram){
	return (hektogram / 10);
}

//konversi hg ke dag
double hg_to_dag(double hektogram){
	return (hektogram * 10);
}

//konversi hg ke g
double hg_to_g(double hektogram){
	return (hektogram * 100);
}

//konversi hg ke dg
double hg_to_dg(double hektogram){
	return (hektogram * 1000);
}

//konversi hg ke cg
double hg_to_cg(double hektogram){
	return (hektogram * 10000);
}

//konversi hg ke mg
double hg_to_mg(double hektogram){
	return (hektogram * 100000);
}


//konversi dag ke kg
double dag_to_kg(double dekagram){
	return (dekagram / 100);
}

//konversi dag ke hg
double dag_to_hg(double dekagram){
	return (dekagram / 10);
}

//konversi dag ke g
double dag_to_g(double dekagram){
	return (dekagram * 10);
}

//konversi dag ke dg
double dag_to_dg(double dekagram){
	return (dekagram * 100);
}

//konversi dag ke cg
double dag_to_cg(double dekagram){
	return (dekagram * 1000);
}

//konversi dag ke mg
double dag_to_mg(double dekagram){
	return (dekagram * 10000);
}

//konversi g ke kg
double g_to_kg(double gram){
	return (gram / 1000);
}

//konversi g ke hg
double g_to_hg(double gram){
	return (gram / 100);
}

//konversi g ke dag
double g_to_dag(double gram){
	return (gram / 10);
}

//konversi g ke dg
double g_to_dg(double gram){
	return (gram * 10);
}

//konversi g ke cg
double g_to_cg(double gram){
	return (gram * 100);
}

//konversi g ke mg
double g_to_mg(double gram){
	return (gram * 1000);
}

//konversi dg ke kg
double dg_to_kg(double desigram){
	return (desigram / 10000);
}

//konversi dg ke hg
double dg_to_hg(double desigram){
	return (desigram / 1000);
}

//konversi dg ke dag
double dg_to_dag(double desigram){
	return (desigram / 100);
}

//konversi dg ke g
double dg_to_g(double desigram){
	return (desigram / 10);
}

//konversi dg ke cg
double dg_to_cg(double desigram){
	return (desigram * 10);
}

//konversi dg ke mg
double dg_to_mg(double desigram){
	return (desigram * 100);
}

//konversi cg ke kg
double cg_to_kg(double centigram){
	return (centigram / 100000);
}

//konversi cg ke hg
double cg_to_hg(double centigram){
	return (centigram / 10000);
}

//konversi cg ke dag
double cg_to_dag(double centigram){
	return (centigram / 1000);
}

//konversi cg ke g
double cg_to_g(double centigram){
	return (centigram / 100);
}

//konversi cg ke dg
double cg_to_dg(double centigram){
	return (centigram / 10);
}

//konversi cg ke mg
double cg_to_mg(double centigram){
	return (centigram * 10);
}

//konversi mg ke kg
double mg_to_kg(double miligram){
	return (miligram / 1000000);
}

//konversi mg ke hg
double mg_to_hg(double miligram){
	return (miligram / 100000);
}

//konversi mg ke dag
double mg_to_dag(double miligram){
	return (miligram / 10000);
}

//konversi mg ke g
double mg_to_g(double miligram){
	return (miligram / 1000);
}

//konversi mg ke dg
double mg_to_dg(double miligram){
	return (miligram / 100);
}

//konversi mg ke cg
double mg_to_cg(double miligram){
	return (miligram / 10);
}

void memilih_tipe_massa(){
	int pilihan;
	printf("!!!Note!!!\nTanda '.' (titik) menunjukan koma bukan sebagai pembatas satuan, puluhan, ribuan dst.\n\n");
	printf("Pilih konversi : \n");
	printf("1. Kilogram\n");
	printf("2. Hektogram\n");
	printf("3. Dekagram\n");
	printf("4. gram\n");
	printf("5. Desigram\n");
	printf("6. Centigram\n");
	printf("7. Miligram\n");
	printf("Masukkan Pilihan : ");
	scanf("%d", &pilihan);
	
	switch(pilihan){
		case 1:
			konversi_kg();
			break;
		case 2:
			konversi_hg();
			break;
		case 3:
			konversi_dag();
			break;
		case 4:
			konversi_g();
			break;
		case 5:
			konversi_dg();
			break;
		case 6:
			konversi_cg();
			break;
		case 7:
			konversi_mg();
			break;
		defaults:
			printf("pilihan tidak tersedia");
		}
	}
	
void konversi_kg(){
	printf("\nSilahkan masukkan nilai Kilogram terlebih dahulu\n");
	printf("Nilai Kilogram : ");
	scanf("%lf", &kilogram);
	printf("Pilih konversi Kg ke : \n");
	printf("1. Hg\n");
	printf("2. Dag\n");
	printf("3. g\n");
	printf("4. Dg\n");
	printf("5. Cg\n");
	printf("6. Mg\n");
	tampil_hasil_konversi_Kg();
}

void tampil_hasil_konversi_Kg(double massa){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = kg_to_hg(kilogram);
			printf("Hasil konversinya adalah %.3lf Kg = %.2lf Hg", kilogram, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = kg_to_dag(kilogram);
			printf("Hasil konversinya adalah %.3lf Kg = %.2lf Dkg", kilogram, hasil_konversi);
		break;
		case 3:
			hasil_konversi = kg_to_g(kilogram);
			printf("Hasil konversinya adalah %.3lf Kg = %.2lf G", kilogram, hasil_konversi);
		break;
		case 4:
			hasil_konversi = kg_to_dg(kilogram);
			printf("Hasil konversinya adalah %.3lf Kg = %.2lf Dg", kilogram, hasil_konversi);
		break;
		case 5:
			hasil_konversi = kg_to_cg(kilogram);
			printf("Hasil konversinya adalah %.3lf Kg = %.2lf Cg", kilogram, hasil_konversi);
		break;
		case 6:
			hasil_konversi = kg_to_mg(kilogram);
			printf("Hasil konversinya adalah %.3lf Kg = %.2lf Mg", kilogram, hasil_konversi);
		break;
	}
}

void konversi_hg(){
	printf("\nSilahkan masukkan nilai Hektogram terlebih dahulu\n");
	printf("Nilai Hektogram : ");
	scanf("%lf", &hektogram);
	printf("Pilih konversi Hg ke : \n");
	printf("1. Kg\n");
	printf("2. Dag\n");
	printf("3. G\n");
	printf("4. Dg\n");
	printf("5. Cg\n");
	printf("6. Mg\n");
	tampil_hasil_konversi_Hg();
}

void tampil_hasil_konversi_Hg(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = hg_to_kg(hektogram);
			printf("Hasil konversinya adalah %.3lf Hg = %.3lf Kg", hektogram, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = hg_to_dag(hektogram);
			printf("Hasil konversinya adalah %.3lf Hg = %.3lf Dag", hektogram, hasil_konversi);
		break;
		case 3:
			hasil_konversi = hg_to_g(hektogram);
			printf("Hasil konversinya adalah %.3lf Hg = %.3lf G", hektogram, hasil_konversi);
		break;
		case 4:
			hasil_konversi = hg_to_dg(hektogram);
			printf("Hasil konversinya adalah %.3lf Hg = %.3lf Dg", hektogram, hasil_konversi);
		break;
		case 5:
			hasil_konversi = hg_to_cg(hektogram);
			printf("Hasil konversinya adalah %.3lf Hg = %.3lf Cg", hektogram, hasil_konversi);
		break;
		case 6:
			hasil_konversi = hg_to_mg(hektogram);
			printf("Hasil konversinya adalah %.3lf Hg = %.3lf Mg", hektogram, hasil_konversi);
		break;
	}
}

void konversi_dag(){
	printf("\nSilahkan masukkan nilai Dekagram terlebih dahulu\n");
	printf("Nilai Dekagram : ");
	scanf("%lf", &dekagram);
	printf("Pilih konversi Dag ke : \n");
	printf("1. Kg\n");
	printf("2. Hg\n");
	printf("3. G\n");
	printf("4. Dg\n");
	printf("5. Cg\n");
	printf("6. Mg\n");
	tampil_hasil_konversi_dag();
}

void tampil_hasil_konversi_dag(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = dag_to_kg(dekagram);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf Km", dekagram, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = dag_to_hg(dekagram);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf Hm", dekagram, hasil_konversi);
		break;
		case 3:
			hasil_konversi = dag_to_g(dekagram);
			printf("Hasil konversinya adalah %.3lf Dam = %.33lf M", dekagram, hasil_konversi);
		break;
		case 4:
			hasil_konversi = dag_to_mg(dekagram);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf Dm", dekagram, hasil_konversi);
		break;
		case 5:
			hasil_konversi = dag_to_mg(dekagram);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf Cm", dekagram, hasil_konversi);
		break;
		case 6:
			hasil_konversi = dag_to_mg(dekagram);
			printf("Hasil konversinya adalah %.3lf Dam = %.3lf MM", dekagram, hasil_konversi);
		break;
	}
}

void konversi_g(){
	printf("\nSilahkan masukkan nilai gram terlebih dahulu\n");
	printf("Nilai gram : ");
	scanf("%lf", &gram);
	printf("Pilih konversi g ke : \n");
	printf("1. Kg\n");
	printf("2. Hg\n");
	printf("3. Dag\n");
	printf("4. Dg\n");
	printf("5. Cg\n");
	printf("6. Mg\n");
	tampil_hasil_konversi_g();
}

void tampil_hasil_konversi_g(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = g_to_kg(gram);
			printf("Hasil konversinya adalah %.3lf g = %.3lf Kg", gram, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = g_to_hg(gram);
			printf("Hasil konversinya adalah %.3lf g = %.3lf Hg", gram, hasil_konversi);
		break;
		case 3:
			hasil_konversi = g_to_dag(gram);
			printf("Hasil konversinya adalah %.3lf g = %.3lf Dag", gram, hasil_konversi);
		break;
		case 4:
			hasil_konversi = g_to_dg(gram);
			printf("Hasil konversinya adalah %.3lf g = %.3lf Dg", gram, hasil_konversi);
		break;
		case 5:
			hasil_konversi = g_to_cg(gram);
			printf("Hasil konversinya adalah %.3lf g = %.3lf Cg", gram, hasil_konversi);
		break;
		case 6:
			hasil_konversi = g_to_mg(gram);
			printf("Hasil konversinya adalah %.3lf g = %.3lf Mg", gram, hasil_konversi);
		break;
	}
}

void konversi_dg(){
	printf("\nSilahkan masukkan nilai Desigram terlebih dahulu\n");
	printf("Nilai Desigram : ");
	scanf("%lf", &desigram);
	printf("Pilih konversi Dg ke : \n");
	printf("1. Kg\n");
	printf("2. Hg\n");
	printf("3. Dag\n");
	printf("4. G\n");
	printf("5. Cg\n");
	printf("6. Mg\n");
	tampil_hasil_konversi_dg();
}

void tampil_hasil_konversi_dg(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = dg_to_kg(desigram);
			printf("Hasil konversinya adalah %.3lf Dg = %.3lf Kg", desigram, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = dg_to_hg(desigram);
			printf("Hasil konversinya adalah %.3lf Dg = %.3lf Hg", desigram, hasil_konversi);
		break;
		case 3:
			hasil_konversi = dg_to_dag(desigram);
			printf("Hasil konversinya adalah %.3lf Dg = %.3lf Dag", desigram, hasil_konversi);
		break;
		case 4:
			hasil_konversi = dg_to_g(desigram);
			printf("Hasil konversinya adalah %.3lf Dg = %.3lf G", desigram, hasil_konversi);
		break;
		case 5:
			hasil_konversi = dg_to_cg(desigram);
			printf("Hasil konversinya adalah %.3lf Dg = %.3lf Cg", desigram, hasil_konversi);
		break;
		case 6:
			hasil_konversi = dg_to_mg(desigram);
			printf("Hasil konversinya adalah %.3lf Dg = %.3lf Mg", desigram, hasil_konversi);
		break;
	}
}


void konversi_cg(){
	printf("\nSilahkan masukkan nilai Centigram terlebih dahulu\n");
	printf("Nilai Centigram : ");
	scanf("%lf", &centigram);
	printf("Pilih konversi Cg ke : \n");
	printf("1. Kg\n");
	printf("2. Hg\n");
	printf("3. Dag\n");
	printf("4. G\n");
	printf("5. Dg\n");
	printf("6. Mg\n");
	tampil_hasil_konversi_cg();
}

void tampil_hasil_konversi_cg(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = cg_to_kg(centigram);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf Km", centigram, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = cg_to_kg(centigram);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf Hm", centigram, hasil_konversi);
		break;
		case 3:
			hasil_konversi = cg_to_dag(centigram);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf Dam", centigram, hasil_konversi);
		break;
		case 4:
			hasil_konversi = cg_to_g(centigram);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf M", centigram, hasil_konversi);
		break;
		case 5:
			hasil_konversi = cg_to_dg(centigram);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf Dm", centigram, hasil_konversi);
		break;
		case 6:
			hasil_konversi = cg_to_mg(centigram);
			printf("Hasil konversinya adalah %.3lf Cm = %.3lf MM", centigram, hasil_konversi);
		break;
	}
}


void konversi_mg(){
	printf("\nSilahkan masukkan nilai Miligram terlebih dahulu\n");
	printf("Nilai Miligram : ");
	scanf("%lf", &miligram);
	printf("Pilih konversi mg ke : \n");
	printf("1. Kg\n");
	printf("2. Hg\n");
	printf("3. Dag\n");
	printf("4. G\n");
	printf("5. Dg\n");
	printf("6. Cg\n");
	tampil_hasil_konversi_mg();
}

void tampil_hasil_konversi_mg(){
	int pilih;
	double hasil_konversi;
	printf("Pilihan: ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			hasil_konversi = mg_to_kg(miligram);
			printf("Hasil konversinya adalah %.3lf mg = %.3lf kg", miligram, hasil_konversi);
		break;
		case 2: 
			hasil_konversi = mg_to_hg(miligram);
			printf("Hasil konversinya adalah %.3lf mg = %.3lf Hg", miligram, hasil_konversi);
		break;
		case 3:
			hasil_konversi = mg_to_dag(miligram);
			printf("Hasil konversinya adalah %.3lf mg = %.3lf Dag", miligram, hasil_konversi);
		break;
		case 4:
			hasil_konversi = mg_to_g(miligram);
			printf("Hasil konversinya adalah %.3lf mg = %.3lf g", miligram, hasil_konversi);
		break;
		case 5:
			hasil_konversi = mg_to_dg(miligram);
			printf("Hasil konversinya adalah %.3lf mg = %.3lf dg", miligram, hasil_konversi);
		break;
		case 6:
			hasil_konversi = mg_to_cg(miligram);
			printf("Hasil konversinya adalah %.3lf mg = %.3lf cg", miligram, hasil_konversi);
		break;
	}
}




#endif
