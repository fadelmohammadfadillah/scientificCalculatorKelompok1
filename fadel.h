#ifndef fadel_h
#define fadel_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#define info(P) (P)->num
#define next(P) (P)->next

/*MODUL-MODUL STACK LINKED LIST*/
typedef struct tStackNum* addressNum;
typedef double infoNum;
typedef struct tStackNum {
	infoNum num;
	addressNum next;
}stackNum;

void pushNum(addressNum *top, infoNum value){
	addressNum P;
	P = (addressNum) malloc (sizeof(stackNum));/*alokasi memori sebesar adt stack*/
	if (P==NULL){//jika alokasi tidak berhasil
		return;
	}
	info(P) = value;
	next(P) = NULL;
	if(*top ==NULL){ /*push jika stack kosong*/
		*top = P;
	}else{/*push jika stack tidak kosong*/
		next(P) = *top;
		*top = P;
	}
	

}

void popNum(addressNum *top,infoNum *value){
	/*top adalah param i/o dibutuhkan untuk mengakses data pada stack*/
	/*value adalah param output digunakan untuk mengembalikan nilai yang dikeluarkan ke pemanggil*/
	if (*top == NULL){/*bila stack kosong maka akhiri*/
		printf("\n--Stack Kosong--\n");
		return;
	}
	addressNum temp = *top;
	if (next(*top) != NULL){/*Cek apabila elemen stack > 1*/
		*top = next(*top);
		*value = info(temp);
		free(temp);
	}else{/*Jika elemen stack = 1*/
		top = NULL;
		*value = info(temp);
		free(temp);
	}
}

//void tampil(address top){
//	if (top != NULL){
//		address temp = top;
//		while (temp!= NULL){
//			printf("%c ", info(temp));
//			temp = next(temp);
//		}
//		printf("\n");
//	}else {
//		printf("--Stack Kosong--");
//	}
//
//}

/*MODUL-MODUL ARITMATIKA DAN LAINNYA*/
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

bool isDigit(char str){
	if (str < '0' || str > '9'){
		return false;
	}else{
		return true;
	}
}

#endif
