#ifndef fadel_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159

double HitungSin(double rad){
    return sin(rad);
}
double HitungCos(double rad){
    return cos(rad);
}
double HitungTan(double rad){
    return tan(rad);
}
void MenuTrigonometri(){
    double numInDegree, numInRad, jawaban;
    int pilihan;

    printf("1. Hitung Sin\n");
    printf("2. Hitung Cos\n");
    printf("3. Hitung Tan\n");
    scanf("%d", &pilihan);

    printf("Masukkan angka dalam derajat: ");
    scanf("%lf", &numInDegree);
    numInRad = numInDegree * PI / 180;
    if (pilihan == 1){
        jawaban=HitungSin(numInRad);
        printf("%lf", jawaban);
    } else if (pilihan == 2){
        jawaban=HitungCos(numInRad);
        printf("%lf", jawaban);
    }else if (pilihan == 3){
        jawaban=HitungTan(numInRad);
        printf("%lf", jawaban);
    }
}
#endif
