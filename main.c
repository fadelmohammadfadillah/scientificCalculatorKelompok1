#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "fadel.h"
#include "reno.h"
#include "adi.h"
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
	}else if(strcmp(opr, "^(")==0){
		return pangkat(num,2);
	}
	else {
		printf("Invalid expression : %s \n", opr);
		printf("seharusnya %s()\nError ", opr);
	}
}

void MenuAritmatika(){
	char str[100], stackOpr[50];
	int i, topNum=-1,topOpr=-1;
	double  stackNum[100];
	printf("Masukkan Ekspresi Matematika: ");
	fflush(stdin);
	scanf("%s", str);
	for (i=0;i<strlen(str);i++){
		//cek apakah angka dan digit angka tersebut agar disatukan menjadi sebuah kesatuan angka dalam array
		if(isDigit(str[i]) || (isNegative(str, i)&&stackOpr[topOpr] == '(') ){
			bool is_negative =false;
   			if (str[i] == '-'){
   				is_negative =true;
   				i++;
			   }
			char tempNum[10];
			int tempNumTop=0;
			while (isDigit(str[i]) || str[i] == '.'){
				tempNum[tempNumTop] = str[i];
				i++;
				tempNumTop++;
			}
			topNum++;
			//mengganti operator dengan character null
			tempNum[tempNumTop] = '\0';
			stackNum[topNum] = strtod(tempNum, NULL);
			if (is_negative){
				stackNum[topNum] *= -1;
			}
			i--;
		}else if (str[i] == '('){
			topOpr++;
			stackOpr[topOpr] = str[i];
		} else if (str[i] == ')'){
			while (stackOpr[topOpr] != '('){
				double num2 = stackNum[topNum];
				topNum--;
				double num1 = stackNum[topNum];
				char opr = stackOpr[topOpr];
				topOpr--;
				stackNum[topNum] = Operation(num1,num2,opr);
			}
			//untuk mengarahkan sebelum index operator '(' sehingga akan ter-overwrite pada iterasi berikutnya
			topOpr--;
		}else if(str[i] == 's' ||str[i] == 't' ||str[i] == 'c' ||str[i] == 'a'|| str[i] == 'l'){
			//untuk operasi non-aritmatik menggunakan cara infix
			char tempChar[10];
			int tempCharTop = 0;
			char tempNum[10];
			int tempNumTop=0;
			bool beforeIsNumber = false;
			if (isDigit(str[i-1])){
				//jika ekspresi matematika sebelum log adalah angka
				//maka dianggap logaritma basis bebas
				beforeIsNumber = true;
			}
			while(!(isDigit(str[i]))){
				tempChar[tempCharTop] = str[i];
				i++;
				tempCharTop++;
			}
			tempChar[tempCharTop] = '\0';
			while (isDigit(str[i]) || str[i] == '.'){
				tempNum[tempNumTop] = str[i];
				i++;
				tempNumTop++;
			}
			topNum++;
			//mengganti operator dengan character null
			tempNum[tempNumTop] = '\0';
			//Pengecekan apakah operasi infix atau prefix
			if (beforeIsNumber && strcmp(tempChar, "log(")==0){
				//operasi logaritma basis bebas
				double x = strtod(tempNum,NULL);
				topNum--;
				double b = stackNum[topNum];
				stackNum[topNum] = logNature(x)/logNature(b);
			}
			else{
				stackNum[topNum] = nonArithmeticOperation(strtod(tempNum, NULL), tempChar);
			}
		}else if (str[i] =='!'){
			if(isDigit(str[i+1])){
				//jika setelah ! ada angka maka invalid expression
				printf("setelah '!' harus berupa operator\n");
				return;
			}
			stackNum[topNum] = (double) faktorial(stackNum[topNum]);
		}
		else {
			//jika operator sebelumnya memiliki hierarki lebih tinggi maka akan dioperasikan terlebih dahulu
        	// '()' memiliki hierarki lebih rendah karena tidak akan dioperasikan pada blok kode ini
			while (topOpr >=0 && operatorPriority(stackOpr[topOpr]) >= operatorPriority(str[i])){
				double num2 = stackNum[topNum];
				topNum--;
				double num1 = stackNum[topNum];
				char opr = stackOpr[topOpr];
				topOpr--;
				stackNum[topNum] = Operation(num1,num2,opr);
			}
			if(isDigit(str[i+1]) == false && str[i+1] != '(' && str[i+1] != 'l' && str[i+1] != 's' && str[i+1] != 't' && str[i+1] != 'c' && str[i+1] != 'a'){
				//jika setelah operator ada operator maka tidak valid
				printf("ekspresi matematika tidak valid karena setelah '%c' ada '%c'\n", str[i], str[i+1]);
				return;
			}
			topOpr++;
			stackOpr[topOpr] = str[i];
		}
	}
	while(topOpr>=0){
		double num2 = stackNum[topNum];
		topNum--;
		double num1 = stackNum[topNum];
		char opr = stackOpr[topOpr];
		topOpr--;
		stackNum[topNum] = Operation(num1,num2,opr);
	}
	printf("result = %g\n", stackNum[0]);
}


int main (){
	char choice = 'Y';
//	printf("choise: %d", isDigit(choice));
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




