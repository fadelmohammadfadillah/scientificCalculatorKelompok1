#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "fadel.h"
//#include "reno.h"
//#include "adi.h"
#include "adrian.h"
//#include "alya1.h"
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

double MenuAritmatika(char str[]){
	int i, flag = 0;
	address root = NULL, temp;
	for (i=0;i<strlen(str);i++){
		//cek apakah angka dan digit angka tersebut agar disatukan menjadi sebuah kesatuan angka dalam array
		if(isDigit(str[i]) || str[i] == '(' && str[i+1] == '-'){
			char numNode[10];
			int  numNodeTop=0;
   			if (str[i+1] == '-' && str[i] == '('){
   				numNode[numNodeTop++]=str[i+1];
   				i = i+2;
			}
			while (isDigit(str[i]) || str[i] == '.'){ 
			/*jika angka lebih dari 1 digit maka akan ditampung kedalam sebuah array of char*/
			/*yang kemudian akan di typecast menggunakan strtod (string to double)*/
				numNode[numNodeTop++] = str[i];//untuk string node tree
				i++;
			}
			//mengganti operator dengan character null
			//error saat bilangan adalah negatif
			numNode[numNodeTop] = '\0';
			CreateNode(&temp, numNode);
			GetPosNum(&root, &temp);
			if(str[i] != ')'){
				i--;
			}
		}else if (str[i] == '('){
			int flagPr = 0, flagPr2 = 0;
			i++;
			char tempStr[100];
			int topTempStr =0;
			while(str[i] != ')' || flagPr>0 && i < strlen(str)){
				if(str[i] == '('){
					flagPr += 1;
				}
				if(str[i] == ')'){
					flagPr -= 1;
				}
				tempStr[topTempStr++] = str[i++];
			}
			if (flagPr != 0){
				printf("ekspresi matematika tidak valid karena setelah '(' ada ')'\n");
				return;
			}
			tempStr[topTempStr] = '\0';
			double tempRes = 0;
			tempRes = MenuAritmatika(tempStr);
//			printf("hasil dalam kurung: %f\n",tempRes);
			char tempNum[10];
			sprintf(tempNum, "%f", tempRes);
			CreateNode(&temp, tempNum);
			GetPosNum(&root, &temp);
			
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
				i = strlen(str);
				return;
			}
			//Pengecekan apakah operasi infix atau prefix
			if (beforeIsNumber && strcmp(tempChar, "log(")==0){
				//operasi logaritma basis bebas
				sprintf(result, "%f", logBase(strtod(tempNum, NULL), strtod(temp->data, NULL)));
				strcpy(temp->data, result);
			}else if (beforeIsNumber && strcmp(tempChar, "log(") != 0){
				//selain log, tidak boleh ada angka sebelum operator
				printf("\t-- %s) adalah operator prefix, tidak boleh ada angka sebelum operator tersebut--\n", tempChar);
				i = strlen(str);
				return;
			}
			else{
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
			sprintf(result, "%f", (double)faktorial(strtod(temp->data, NULL)));
			strcpy(temp->data, result);
		}
		else {
			//jika operator sebelumnya memiliki hierarki lebih tinggi maka akan dioperasikan terlebih dahulu
        	// '()' memiliki hierarki lebih rendah karena tidak akan dioperasikan pada blok kode ini
//        	printf("root: %s", data(root));
       		while (!isDigitString(data(root)) || flag == 0) {
       			if (!checkOperatorTree(root, str[i]) || root->left == NULL){
       				break;
				}
				temp = root;
				while (temp->right != NULL){
					temp = temp->right;
				}
				if (isDigitString(data(temp))){
					address num2 = temp;
					address opr = temp->parent;
					address num1 = opr->left;
					char tempOpr[3];
					strcpy(tempOpr, data(opr));
					double dnum1, dnum2;
					if (data(num1)[0]=='-'){
						dnum1 = enumNegativeNumberString(data(num1));
					}else{
						dnum1 = strtod(data(num1), NULL);
					}
					if (data(num2)[0]=='-'){
						dnum2 = enumNegativeNumberString(data(num2));
					}else{
						dnum2 = strtod(data(num2), NULL);
					}
					double result = Operation(dnum1, dnum2, (char)tempOpr[0]);
					sprintf(data(opr), "%f", result);
					deallocNode(&num1);
					deallocNode(&num2);
					opr->right = NULL;
					opr->left = NULL;
				}
			}

			if(!isDigit(str[i+1]) && str[i+1] != '(' && str[i+1] != 'l' && str[i+1] != 's' && str[i+1] != 't' && str[i+1] != 'c' && str[i+1] != 'a'){
				//jika setelah operator ada operator maka tidak valid
				printf("ekspresi matematika tidak valid karena setelah '%c' ada '%c'\n", str[i], str[i+1]);
				return;
			}
			char opr[2];
			opr[0] = str[i];
			opr[1] = '\0';
			CreateNode(&temp, opr);
			GetPosOpr(&root, &temp);
			flag = 1;
		}
	}
	while(isDigitString(data(root)) == false){
		temp = root;
		while (temp->right != NULL){
			temp = temp->right;
		}
		if (temp == root){
			break;
		}
		if(isDigitString(temp->data)){
			address num2 = temp;
			address opr = temp->parent;
			address num1 = opr->left;
			double dnum1,dnum2;
			if (data(num1)[0]=='-'){
				dnum1 = enumNegativeNumberString(data(num1));
			}else{
				dnum1 = strtod(data(num1), NULL);
			}
			if (data(num2)[0]=='-'){
				dnum2 = enumNegativeNumberString(data(num2));
			}else{
				dnum2 = strtod(data(num2), NULL);
			}
			double result = Operation(dnum1, dnum2, data(opr)[0]);
			sprintf(data(opr), "%f", result);
			deallocNode(&num1);
			deallocNode(&num2);
			opr->right = NULL;
			opr->left = NULL;
		}
	}
	double res;
	res = strtod(data(root),NULL);
	return res;
}


int main (){
	char choice = 'Y', str[100];
	double result = 0;
	do{
		printf("Masukkan Ekspresi Matematika: ");
		fflush(stdin);
		scanf("%s", str);
	    result = MenuAritmatika(str);
	    printf("result = %f\n", result);
		printf("Apakah anda ingin melanjutkan? Y/T \n");
		scanf(" %c",&choice);
		getchar();
		system("cls");
		}while(choice == 'Y' || choice == 'y');
	return 0;
	}


//end




