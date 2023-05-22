#ifndef fadel_h
#define fadel_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

bool isDigit(char str){
	/*cek apakah char adalah digit*/
	if (str < '0' || str > '9'){
		return false;
	}else{
		return true;
	}
}
bool isDigitString(char str[]){
	/*cek apakah string tersebut adalah digit*/
	if (str[0] < '0' || str[0] > '9'){
		if (str[1] < '0' || str[1] > '9'){
			return false;
		}
	}else{
		return true;
	}
}

bool isNegative(char string[], int i){
	/*cek apakah char adalah negatif*/
	if (string[i] == '-' && !isDigit(string[i-1])){
		return true;
	} else {
		return false;
	}
}


/*Binary Tree*/
#define data(P) (P)->data
#define left(P) (P)->left
#define right(P) (P)->right
#define parent(P) (P)->parent

typedef struct tNode *address;
typedef char infotype[20];
typedef struct tNode{
	infotype data;
	address left, right, parent;
}BTNode;


void CreateNode(address *btr, infotype X){
	/*alokasi node baru*/
	address tr;
	tr = (address) malloc (sizeof(BTNode));
	if (tr != NULL){
		strcpy(data(tr), X);
		left(tr) = NULL;
		right(tr) = NULL;
		parent(tr) = NULL;
		*btr = tr;
	}
}

void GetPosNum (address *root, address *newNode){
	/*jika root NULL, maka Node saat ini menjadi root*/
	if (*root == NULL){
		*root = *newNode;
		return;
	}
	/*jika root tidak kosong, maka loop hingga right son
	NULL, newNode menjadi rightson*/
	address temp = *root;
	while (right(temp) != NULL){
		temp = right(temp);
	}
	if(isDigitString(temp->data)){
		printf("Setelah angka masukan operator terlebih dahulu!\n");
		printf("ERROR ");
		return;
	}
	right(temp) = *newNode;
	parent(*newNode) = temp;
}

void GetPosOpr (address *root, address *newOpr) {
	/*jika root adalah digit, maka newOpr menjadi root*/
	if (isDigitString(data(*root))){
		left(*newOpr) =*root;
		parent(*root) = *newOpr;
		*root = *newOpr;
		return;
	}
	/*jika root tidak kosong, maka loop hingga right son
	NULL, kemudian ubah right son dari parent terakhir
	menjadi newOpr, kemudian right son tersebut menjadi left
	son newOpr*/
	address temp = *root;
	while(temp->right != NULL){
		temp = temp->right;
	}
	parent(*newOpr) = temp->parent;
	temp->parent->right = *newOpr;
	left(*newOpr) = temp;
	temp->parent = *newOpr;
	
}

void deallocNode(address *node){
	/*mendealokasi node tree dari memori*/
	left(*node) = NULL;
	right(*node) = NULL;
	parent(*node) = NULL;
	free(*node);
}






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
	/*
	memilihkan prioritas operator berdasarkan aturan matematika
	*/
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



bool checkOperatorTree(address root, char str){
	/*check operator paling bawah, karena jika operator paling bawah
	adalah operator yang paling besar priority nya.
	Jika operator tersebut belum di kalkulasi, maka dibandingkan dengan
	operator sekarang prioritynya, jika lebih besar maka return true
	untuk kemudian di operasikan.
	Jika lebih kecil maka return false, untuk kemudian di bikin node baru
	untuk operator yang lebih besar tersebut*/
    char tempOpr[3];
	address temp = root;
	while(temp->right != NULL){
		temp = temp->right;
	}
	//jika root, maka parentnya NULL
	if (temp->parent != NULL){
		temp = temp->parent;
	}
	if (!isDigitString(data(temp))){
    	strcpy(tempOpr, data(temp));
		if (operatorPriority(tempOpr[0]) >= operatorPriority(str)){
			return true;
		}else{
			return false;
		}
	}
}

double enumNegativeNumberString(char str[]){
	/*
	enumerasi untuk string yang berisikan negatif number
	maka return hasil dari number dikali negatif
	AUTHOR: FADEL
	
	*/
	int i=1, n=0;
	char tempNum[10];
	double num;
	while(i<strlen(str)){
		tempNum[n++] = str[i++];
	}
	num = strtod(tempNum, NULL);
	return num *= -1;
}


#endif
