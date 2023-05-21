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
#endif
