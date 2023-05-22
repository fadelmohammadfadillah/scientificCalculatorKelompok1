#include <stdio.h>
#ifndef adi_h
#define adi_h

//modul
double pangkat(double angka, double pangkat);
double akar(double angka, double pangkatAkar);
int faktorial(int angka);
//end modul

double pangkat(double angka, double pangkat){
	/* Modul ini merupakan implementasi fungsi pangkat untuk menghitung hasil pangkat dari suatu angka.
	Fungsi pangkat menerima dua parameter bertipe double yaitu "angka" yang merupakan angka yang akan dipangkatkan, dan "pangkat" yang merupakan nilai pangkatnya.
	Variabel "hasil" digunakan untuk menyimpan hasil pangkat.*/
	int i; /* Variabel "i" digunakan sebagai penghitung iterasi dalam loop.*/
	double hasil = 1; /* Menginisialisasi variabel "hasil" dengan nilai awal 1*/
	/* Pangkat Bulat*/
	if (pangkat == (int) pangkat){ /* Mengecek apakah nilai "pangkat" merupakan bilangan bulat atau bukan. Jika iya, maka akan masuk kondisi ini*/
		for (i = 1; i <= pangkat; i++){ /* Akan menggunakan loop "for" untuk mengulang dari 1 hingga "i" kurang dari sama dengan "pangkat".*/
			hasil *= angka; /* Pada setiap iterasi, variabel "hasil" akan dikalikan dengan nilai "angka" dan hasilnya akan disimpan kembali di variabel "hasil".*/
		}
	}
	/* Pangkat Desimal*/
	else { /* Jika "pangkat" bukan bilangan bulat, maka akan masuk kondisi ini*/
		pangkat = pangkat * 10; /* Variabel "pangkat" akan dikalikan dengan 10 agar nilai pangkat menjadi pangkat bulat.*/
		for (i = 1; i <= pangkat; i++){ /* Akan menggunakan loop "for" untuk mengulang dari 1 hingga "i" kurang dari sama dengan "pangkat".*/
			hasil *= angka; /* Pada setiap iterasi, variabel "hasil" akan dikalikan dengan nilai "angka" dan hasilnya akan disimpan kembali di variabel "hasil".*/
		}
		hasil = akar(hasil, 10); /* Dilakukan perhitungan akar pangkat pada nilai "hasil" dengan pangkat 10 kemudian di simpan di variabel "hasil"*/
	}
	return hasil; /* Nilai "hasil" akan dikembalikan sebagai hasil pangkat.*/
}

double akar(double angka, double pangkatAkar){ /* Metode Newthon-Raphson*/
	/* Modul ini merupakan implementasi fungsi akar untuk menghitung akar dari suatu angka dengan menggunakan metode iterasi.
	Fungsi akar menerima dua parameter bertipe double "angka" dan "pangkatAkar" yang merupakan angka yang akan dihitung akarnya dan pangkat akar yang diinginkan.
	Variabel "hasil" digunakan untuk menyimpan hasil perhitungan akar.*/
    double hasil = 1; /* Menginisialisasi variabel "hasil" dengan nilai awal 1*/
    double pangkatAkarN = 1/pangkatAkar; /* Menghitung nilai pangkat akar invers (1/pangkatAkar) dan menyimpannya di variabel "pangkatAkarN".*/
    int i; /* Variabel "i" digunakan sebagai penghitung iterasi dalam loop.*/
    for (i = 0; i < 100; i++){ /* Menggunakan loop "for" untuk melakukan iterasi sebanyak 100 kali. (semakin banyak iterasi yang di lakukan maka akan mendapatkan nilai yang semakin mendekati hasil sebenarnya)*/ 
        hasil = (((pangkatAkar - 1) * hasil + angka / pangkat(hasil, pangkatAkar - 1)) * pangkatAkarN); /* Pada setiap iterasi, variabel "hasil" diupdate dengan rumus ((pangkatAkar - 1) * hasil + angka / pangkat(hasil, pangkatAkar - 1) * pangkatAkarN).*/
    }
    return hasil; /* Nilai "hasil" akan dikembalikan sebagai hasil akar.*/
}


int faktorial(int angka){
	/* Modul ini merupakan implementasi fungsi faktorial untuk menghitung faktorial dari suatu angka.
	Fungsi faktorial menerima satu parameter bertipe integer "angka" yang merupakan angka yang akan dihitung faktorialnya.
	Variabel "hasil" digunakan untuk menyimpan hasil faktorial.*/
	int hasil = 1; /* Menginisialisasi variabel "hasil" dengan nilai awal 1.*/
	int i; /* Variabel "i" digunakan sebagai penghitung iterasi dalam loop.*/
    for(i = 1; i <= angka; i++){ /* Menggunakan loop "for" untuk mengulang dari 1 hingga kurang dari sama dengan "angka". */
        hasil *= i; /* Pada setiap iterasi, variabel "hasil" akan dikalikan dengan nilai "i" dan hasilnya akan disimpan kembali di variabel "hasil".*/
    }
	return hasil; /* Nilai "hasil" akan dikembalikan sebagai hasil faktorial.*/
}

#endif
