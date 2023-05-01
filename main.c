#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "fadel.h"
//#include "reno.h"
//#include "adi.h"
#include "adrian.h"
#include "alya1.h"
#include "rafi.h"

double Operation(double num1, double num2, char opr) {
    switch (opr) {
        case '^':
            return pangkat(num1, num2);
		case 'v':
			return akar(num2,num1);
        case '*':
            return Mul(num1,num2);
        case '/':
            return Div(num1,num2);
        case '+':
            return Sum(num1,num2);
        case '-':
            return Sub(num1,num2);
		case '%':
			return Mod(num1,num2);
        default:
            printf("Invalid expression: %c \n", opr);
			system("pause");
    }
}

double nonArithmeticOperation(double num, char opr[]){
	if (strcmp(opr, "sin(") == 0){
		return HitungSin(num);
	} else if (strcmp(opr, "cos(")==0){
		return HitungCos(num);
	}else if (strcmp(opr, "tan(")==0){
		return HitungTan(num);
	}else if (strcmp(opr, "asin(")==0){
		return Inverse_Sin(num);
	}else if (strcmp(opr, "acos(")==0){
		return Inverse_Cos(num);
	}else if (strcmp(opr, "atan(")==0){
		return Inverse_Tan(num);
	}else if (strcmp(opr, "log(") == 0){
		return logBase10(num);
	}else if (strcmp(opr, "ln(") == 0){
		return logNature(num);
	}else if (strcmp(opr, "cosec(")==0){
		return HitungCosec(num);
	}else if(strcmp(opr, "secan(")==0){
		return HitungSec(num);
	}else if(strcmp(opr, "cotan(")==0){
		return HitungCotan(num);
	}else {
		printf("Invalid expression : %s \n", opr);
		printf("seharusnya %s()\nError ", opr);
	}
}

void MenuAritmatika(){
	char str[100];
	int i, flagpr = 0;
	bool is_negative =false;
	addressOpr topOpr;
	addressNum topNum;
	address root = NULL, temp;
	topNum = NULL;
	topOpr = NULL;
	printf("Masukkan Ekspresi Matematika: ");
	fflush(stdin);
	scanf("%s", str);
	for (i=0;i<strlen(str);i++){
		is_negative = false;
		//cek apakah angka dan digit angka tersebut agar disatukan menjadi sebuah kesatuan angka dalam array
		if(isDigit(str[i]) || (isNegative(str, i)&& infoOp(topOpr) == '(') ){
			char tempNum[10];
			char numNode[10];
			int tempNumTop=0, numNodeTop=0;
   			if (str[i] == '-'){
   				is_negative = true;
   				numNode[numNodeTop++]=str[i];
   				i++;
			}
			while (isDigit(str[i]) || str[i] == '.'){ 
			/*jika angka lebih dari 1 digit maka akan ditampung kedalam sebuah array of char*/
			/*yang kemudian akan di typecast menggunakan strtod (string to double)*/
				tempNum[tempNumTop] = str[i];
				numNode[numNodeTop++] = str[i];//untuk string node tree
				i++;
				tempNumTop++;
			}
			//mengganti operator dengan character null
			//error saat bilangan adalah negatif
			tempNum[tempNumTop] = '\0';
			numNode[numNodeTop] = '\0';
			if (is_negative){
				infoNum num = strtod(tempNum, NULL);
				pushNum(&topNum, num*-1);
				CreateNode(&temp, numNode);
			}else{
				pushNum(&topNum, strtod(tempNum, NULL));
				CreateNode(&temp, numNode);
			}
			GetPosNum(&root, &temp);
			i--;
		}else if (str[i] == '('){
			pushOpr(&topOpr, str[i]);
			flagpr = 1;
		} else if (str[i] == ')'){
			/*Cek apakah pada ekspresi terdapat '('*/
			if (flagpr == 0){
				printf("\t--Invalid expression : ')' tidak ada operator '(' sebelumnya--\n");
				topOpr = NULL;
				i = strlen(str);
				return;
			}
			infoOpr opr;
			infoNum num1;
			infoNum num2;
			while (infoOp(topOpr) != '('){
				//operasi stack
				popNum(&topNum, &num2);
				popNum(&topNum, &num1);
				popOpr(&topOpr, &opr);
				pushNum(&topNum, Operation(num1,num2,opr));
				
				//operasi tree
				char tempOpr[5];
				strcpy(tempOpr, data(right(root)));
				if (!isDigit(tempOpr[0])){
					double dnum1, dnum2;
					int angka = 1, n=0;
					char tempNum[10];
					//operasi jika right son root adalah operator
					address opr = right(root);
					address num1 = left(opr), num2 = right(opr);
					strcpy(tempOpr, data(opr));
					if (data(num1)[0]=='-'){
						while(data(num1)[angka] != '\0'){
							tempNum[n++] = data(num1)[angka++];
						}
						strcpy(data(num1),tempNum);
						angka = 1;
						n=0;
						dnum1 = strtod(data(num1), NULL);
						dnum1 *= -1;
					}else{
						dnum1 = strtod(data(num1), NULL);
					}
					if (data(num2)[0]=='-'){
						while(data(num2)[angka] != '\0'){
							tempNum[n++] = data(num2)[angka++];
						}
						strcpy(data(num2),tempNum);
						angka = 1;
						n=0;
						dnum2 = strtod(data(num2), NULL);
						dnum2 *= -1;
					}else{
						dnum2 = strtod(data(num2), NULL);
					}
					double result = Operation(dnum1, dnum2, (char)tempOpr[0]);
					sprintf(data(opr), "%f", result);
				}else{
					double dnum1, dnum2;
					int angka = 1, n=0;
					char tempNum[10];
					//operasi jika operator lebih besar dari yang di string
					address opr = root;
					address num1 = left(opr), num2 = right(opr);
					strcpy(tempOpr, data(opr));
					if (data(num1)[0]=='-'){
						while(data(num1)[angka] != '\0'){
							tempNum[n++] = data(num1)[angka++];
						}
						strcpy(data(num1),tempNum);
						angka = 1;
						n=0;
						dnum1 = strtod(data(num1), NULL);
						dnum1 *= -1;
					}else{
						dnum1 = strtod(data(num1), NULL);
					}
					if (data(num2)[0]=='-'){
						while(data(num2)[angka] != '\0'){
							tempNum[n++] = data(num2)[angka++];
						}
						strcpy(data(num2),tempNum);
						angka = 1;
						n=0;
						dnum2 = strtod(data(num2), NULL);
						dnum2 *= -1;
					}else{
						dnum2 = strtod(data(num2), NULL);
					}
					double result = Operation(dnum1, dnum2, (char)tempOpr[0]);
					sprintf(data(opr), "%f", result);
				}
			}
			popOpr(&topOpr,&opr); //pop opr '('
		}else if(str[i] == 's' ||str[i] == 't' ||str[i] == 'c' ||str[i] == 'a'|| str[i] == 'l'){
			char tempChar[10];
			int tempCharTop = 0;
			char tempNum[10];
			int tempNumTop=0;
			bool beforeIsNumber = false;
			char result[10];
			//untuk operasi non-aritmatik menggunakan cara infix
			if (isDigit(str[i-1])){
				//jika ekspresi matematika sebelum operator adalah angka
				//maka dianggap operasi infix
				beforeIsNumber = true;
			}
			//loop untuk mendapatkan string operator
			while(!(isDigit(str[i]))){
				tempChar[tempCharTop] = str[i];
				i++;
				tempCharTop++;
			}
			tempChar[tempCharTop] = '\0';
			//loop untuk mendapatkan string number
			while (isDigit(str[i]) || str[i] == '.'){
				tempNum[tempNumTop] = str[i];
				i++;
				tempNumTop++;
			}
			tempNum[tempNumTop] = '\0';
			//pengecekan apakah cara penulisan operator sudah benar
			if(str[i] != ')'){
				printf("\t--penulisan operator salah, seharusnya %s)--\n", tempChar);
				topOpr = NULL;
				i = strlen(str);
				return;
			}
			//Pengecekan apakah operasi infix atau prefix
			if (beforeIsNumber && strcmp(tempChar, "log(")==0){
				//operasi logaritma basis bebas
				infoNum x = strtod(tempNum,NULL);
				infoNum b;
				popNum(&topNum, &b);
				pushNum(&topNum, logBase(x, b));
				sprintf(result, "%f", logBase(strtod(tempNum, NULL), strtod(temp->data, NULL)));
				strcpy(temp->data, result);
			}else if (beforeIsNumber && strcmp(tempChar, "log(") != 0){
				//selain log, tidak boleh ada angka sebelum operator
				printf("\t-- %s) adalah operator prefix, tidak boleh ada angka sebelum operator tersebut--\n", tempChar);
				topOpr = NULL;
				i = strlen(str);
				return;
			}
			else{
				pushNum(&topNum, nonArithmeticOperation(strtod(tempNum, NULL), tempChar));
				sprintf(result, "%f", nonArithmeticOperation(strtod(tempNum, NULL), tempChar));
				CreateNode(&temp, result);
				//nyambungin tree
				GetPosNum(&root, &temp);
			}
		}else if (str[i] =='!'){
			if(isDigit(str[i+1])){
				//jika setelah ! ada angka maka invalid expression
				printf("setelah '!' harus berupa operator\n");
				return;
			}
			char result[10];
			infoNum num;
			popNum(&topNum, &num);
			pushNum(&topNum,(infoNum) faktorial(num) ) ;
			sprintf(result, "%f", (double)faktorial(strtod(temp->data, NULL)));
			strcpy(temp->data, result);
		}
		else {
			//jika operator sebelumnya memiliki hierarki lebih tinggi maka akan dioperasikan terlebih dahulu
        	// '()' memiliki hierarki lebih rendah karena tidak akan dioperasikan pada blok kode ini
       		while (topOpr != NULL && operatorPriority(infoOp(topOpr)) >= operatorPriority(str[i])){
				//ketika posisi 5 node
				char tempOpr[5];
				strcpy(tempOpr, data(right(root)));
				if (!isDigit(tempOpr[0])){
					double dnum1, dnum2;
					int angka = 1, n=0;
					char tempNum[10];
					//operasi jika right son root adalah operator
					address opr = right(root);
					address num1 = left(opr), num2 = right(opr);
					strcpy(tempOpr, data(opr));
					if (data(num1)[0]=='-'){
						while(data(num1)[angka] != '\0'){
							tempNum[n++] = data(num1)[angka++];
						}
						strcpy(data(num1),tempNum);
						angka = 1;
						n=0;
						dnum1 = strtod(data(num1), NULL);
						dnum1 *= -1;
					}else{
						dnum1 = strtod(data(num1), NULL);
					}
					if (data(num2)[0]=='-'){
						while(data(num2)[angka] != '\0'){
							tempNum[n++] = data(num2)[angka++];
						}
						strcpy(data(num2),tempNum);
						angka = 1;
						n=0;
						dnum2 = strtod(data(num2), NULL);
						dnum2 *= -1;
					}else{
						dnum2 = strtod(data(num2), NULL);
					}
					double result = Operation(dnum1, dnum2, (char)tempOpr[0]);
					sprintf(data(opr), "%f", result);
				}else{
					double dnum1, dnum2;
					int angka = 1, n=0;
					char tempNum[10];
					//operasi jika operator lebih besar dari yang di string
					address opr = root;
					address num1 = left(opr), num2 = right(opr);
					strcpy(tempOpr, data(opr));
					if (data(num1)[0]=='-'){
						while(data(num1)[angka] != '\0'){
							tempNum[n++] = data(num1)[angka++];
						}
						strcpy(data(num1),tempNum);
						angka = 1;
						n=0;
						dnum1 = strtod(data(num1), NULL);
						dnum1 *= -1;
					}else{
						dnum1 = strtod(data(num1), NULL);
					}
					if (data(num2)[0]=='-'){
						while(data(num2)[angka] != '\0'){
							tempNum[n++] = data(num2)[angka++];
						}
						strcpy(data(num2),tempNum);
						angka = 1;
						n=0;
						dnum2 = strtod(data(num2), NULL);
						dnum2 *= -1;
					}else{
						dnum2 = strtod(data(num2), NULL);
					}
					double result = Operation(dnum1, dnum2, (char)tempOpr[0]);
					sprintf(data(opr), "%f", result);
				}
				infoNum num2, num1;
				popNum(&topNum, &num2);
				popNum(&topNum, &num1);
				infoOpr op;
				popOpr(&topOpr, &op);
				pushNum(&topNum, Operation(num1,num2,op));
			}

			if(isDigit(str[i+1]) == false && str[i+1] != '(' && str[i+1] != 'l' && str[i+1] != 's' && str[i+1] != 't' && str[i+1] != 'c' && str[i+1] != 'a'){
				//jika setelah operator ada operator maka tidak valid
				printf("ekspresi matematika tidak valid karena setelah '%c' ada '%c'\n", str[i], str[i+1]);
				return;
			}
			char opr[2];
			pushOpr(&topOpr, str[i]);
			opr[0] = str[i];
			opr[1] = '\0';
			CreateNode(&temp, opr);
			if (isDigit(data(root)[0]) || data(root)[0] == '-' && isDigit(data(root)[1])){
				//jika root adalah digit / angka
				parent(root) = temp;
				left(temp) = root;
				root = temp;
			}else{
				//kondisi jika operator di root lebih kecil dari operator yg akan ditambah
				//misal opr root = '+', opr saat ini = '*'
				//maka tree 5 node
				//misalnya 1+2*3
				parent(right(root)) = temp;
				left(temp) = right(root);
				right(root) = temp;
				parent(temp) = root;
			}
		}
	}
	while(topOpr != NULL){
		if (!isDigit(data(right(root))[0])){
			int angka = 1, n=0;
			char tempNum[10];
			double dnum1,dnum2;
			//operasi jika right son root adalah operator
			address opr = right(root);
			address num1 = left(opr), num2 = right(opr);
			if (data(num1)[0]=='-'){
				while(data(num1)[angka] != '\0'){
					tempNum[n++] = data(num1)[angka++];
				}
				strcpy(data(num1),tempNum);
				angka = 1;
				n=0;
				dnum1 = strtod(data(num1), NULL);
				dnum1 *= -1;
			}else{
				dnum1 = strtod(data(num1), NULL);
			}
			if (data(num2)[0]=='-'){
				while(data(num2)[angka] != '\0'){
					tempNum[n++] = data(num2)[angka++];
				}
				strcpy(data(num2),tempNum);
				angka = 1;
				n=0;
				dnum2 = strtod(data(num2), NULL);
				dnum2 *= -1;
			}else{
				dnum2 = strtod(data(num2), NULL);
			}
			double result = Operation(dnum1, dnum2, data(opr)[0]);
			sprintf(data(opr), "%f", result);
		}else{
			int angka = 1, n=0;
			char tempNum[10];
			double dnum1, dnum2;
			//operasi jika operator lebih besar dari yang di string
			address opr = root;
			address num1 = left(opr), num2 = right(opr);
			if (data(num1)[0]=='-'){
				while(data(num1)[angka] != '\0'){
					tempNum[n++] = data(num1)[angka++];
				}
				strcpy(data(num1),tempNum);
				angka = 1;
				n=0;
				dnum1 = strtod(data(num1), NULL);
				dnum1 *= -1;
			}else{
				dnum1 = strtod(data(num1), NULL);
			}
			if (data(num2)[0]=='-'){
				while(data(num2)[angka] != '\0'){
					tempNum[n++] = data(num2)[angka++];
				}
				strcpy(data(num2),tempNum);
				angka = 1;
				n=0;
				dnum2 = strtod(data(num2), NULL);
				dnum2 *= -1;
			}else{
				dnum2 = strtod(data(num2), NULL);
			}
			double result = Operation(dnum1, dnum2, data(opr)[0]);
			sprintf(data(opr), "%f", result);
		}
		infoNum num2, num1;
		popNum(&topNum, &num2);
		popNum(&topNum, &num1);
		infoOpr op;
		popOpr(&topOpr, &op);
		pushNum(&topNum, Operation(num1,num2,op));
	}
	printf("result = %g\n", info(topNum));
	printf("result tree = %s\n", data(root));
}


int main (){
	char choice = 'Y';
	do{
	    MenuAritmatika();
		printf("Apakah anda ingin melanjutkan? Y/T \n");
		scanf(" %c",&choice);
		getchar();
		system("cls");
		}while(choice == 'Y' || choice == 'y');
	return 0;
	}


//end




