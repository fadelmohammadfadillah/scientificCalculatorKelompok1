#define rafi_h
#ifndef rafi_h
#include<stdio.h>

void pilihOperasi(int *pilih);

void input(int *var1, int *var2);

int penjumlahan(int var1,int var2,int *hasil);

int pengurangan(int var1,int var2,int *hasil); 

int perkalian(int var1,int var2,int *hasil);

int pembagian(int var1,int var2,int *hasil);

void hasil(int hasil);

int aritmatika();


#endif

void pilihOperasi(int *pilih){
	printf("Masukkan Operasi Aritmatika Yang Ingin Anda Jalankan");
	printf("\n_____________________________________________________");
	
	printf("\n\n1. Penjumblahan");
	printf("\n2. Pengurangan");
	printf("\n3. Perkalian");
	printf("\n4. Pembagian");
	
	printf("\nMasukkan Operasi: ");
	scanf("%d",&*pilih);
}


// Modul untuk menginputkan angka
void input(int *var1, int *var2){
	printf("\nMasukkan Angka Pertama: ");
	scanf("%d",&*var1);
	
	printf("\nMasukkan Angka Kedua: ");
	scanf("%d",&*var2);
}

// Modul utuk penjumlahan
int penjumlahan(int var1,int var2,int *hasil){
	*hasil = var1+var2;
}

// Modul untuk pengurangan
int pengurangan(int var1,int var2,int *hasil){
	*hasil = var1-var2;
}

// Modul untuk perkalian
int perkalian(int var1,int var2,int *hasil){
	*hasil = var1*var2;
}

// Modul untuk pembagian
int pembagian(int var1,int var2,int *hasil){
	*hasil = var1/var2;
}

// Modul untuk menampilkan hasil
void hasil(int hasil){
	printf("Hasilnya Adalah %d",hasil);
}

// Modul utama
int aritmatika(){
	int choose,a,b,c;
	pilihOperasi(&choose);
	input(&a,&b);
	if(choose==1){
		penjumlahan(a,b,&c);
		hasil(c);
	}else if(choose==2){
		pengurangan(a,b,&c);
		hasil(c);
	}else if(choose==3){
		perkalian(a,b,&c);
		hasil(c);
	}else if(choose==4){
		pembagian(a,b,&c);
		hasil(c);
	}
}
