#ifndef jarak_h
#define jarak_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jarak.h"

double kilometer, hektometer,dekameter,meter,desimeter,centimeter,milimeter;

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

#endif
