#ifndef fadel_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double Operation(double num1, double num2, char opr) {
    switch (opr) {
        case '^':
            return pow(num1, num2);
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        default:
            printf("Invalid operator: %c", opr);
            exit(1);
    }
}

int operatorPriority(char opr){
	switch (opr) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
		case '(':
			return 0;
        default:
            printf("Invalid operator: %c", opr);
            exit(1);
    }
}

void MenuAritmatika(){
	char str[100], stackOpr[50];
	int i, topNum=-1,topOpr=-1;
	double  stackNum[100];
	printf("Masukkan Ekspresi aritmatika: ");
	scanf("%s", str);
	for (i=0;i<strlen(str);i++){
		//cek apakah angka dan digit angka tersebut agar disatukan menjadi sebuah kesatuan angka dalam array
		if(isdigit(str[i])){
			char tempNum[10];
			int tempNumTop=0;
			while (isdigit(str[i]) || str[i] == '.'){
				tempNum[tempNumTop] = str[i];
				i++;
				tempNumTop++;
			}
			topNum++;
			//mengganti operator dengan character null
			tempNum[tempNumTop] = '\0';
			stackNum[topNum] = strtod(tempNum, NULL);
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
		}else {
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
#endif
