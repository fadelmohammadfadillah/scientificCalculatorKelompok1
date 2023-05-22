#include <stdio.h>
#include <math.h>

double LogNature(double angka) // modul log natural, fungsi ini menerima sebuah argumen berupa bilangan yang akan dihitung logaritma basis e nya, dengan parameter angka berjenis input
	{ 
	 if (angka <= 0) {
     	printf("[ERROR]: Argumen harus lebih dari 0");
        return -1; // NaN (Not a Number) jika angka negatif atau nol
	}
	 //deklarasi variabel hasil dan term yang akan digunakan sebagai penampung.
     double hasil = 0.0;
	 //hasil digunakan untuk menyimpan hasil perhitungan log berbasis e
     double temp = (angka - 1) / angka; 
	 //term menyimpan nilai suku deret taylor
     double i = 1;
     while (temp > 0.000000000000000001) { // hingga suku terakhir sudah sangat kecil
        hasil = hasil + temp;
        temp = temp * -1;
        i++;
        temp = pow ((angka - 1) / angka , i) / i; //menggunakan fungsi pangkat yang ada pada adi.h
    }
     return hasil;
}

int main() {
    double angka, hasil;

    printf("Masukkan angka: ");
    scanf("%lf", &angka);

    hasil = LogNature(angka);

    if (hasil != -1) {
        printf("Hasil log natural dari %.2f adalah %.8lf\n", angka, hasil);
    }

    return 0;
}
