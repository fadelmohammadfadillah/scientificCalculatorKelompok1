#ifndef fadel_h
#define fadel_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double Sum(double num1, double num2){
	return num1+num2;
}
double Sub(double num1, double num2){
	return num1-num2;
}
double Mul(double num1, double num2){
	return num1*num2;
}
double Div(double num1, double num2){
	return num1/num2;
}
double Mod(double num1, double num2){
	return (int)num1%(int)num2;
}

int operatorPriority(char opr){
	switch (opr) {
        case '^':
		case 'v':
            return 3;
        case '*':
        case '/':
		case '%':
            return 2;
        case '+':
        case '-':
            return 1;
		case '(':
			return 0;
        default:
            printf("Invalid operator: %c", opr);
			system("pause");
    }
}

bool isNegative(char string[], int i){
	if (string[i] == '-' && (string[i-1] != '+' || string[i-1] != '/' ||string[i-1] != '*' ||string[i-1] != '^')){
		return true;
	} else {
		return false;
	}
}

#endif
