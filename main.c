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
            printf("Invalid operator: %c", opr);
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
		return logBase(num);
	}else {
		printf("Invalid operator : %s", opr);
		system("pause");
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
		if(isdigit(str[i]) || (isNegative(str, i)&&stackOpr[topOpr] == '(') ){
			bool is_negative =false;
   			if (str[i] == '-'){
   				is_negative =true;
   				i++;
			   }
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
			//untuk operasi non-aritmatik
			char tempChar[10];
			int tempCharTop = 0;
			char tempNum[10];
			int tempNumTop=0;
			while(!(isdigit(str[i]))){
				tempChar[tempCharTop] = str[i];
				i++;
				tempCharTop++;
			}
			while (isdigit(str[i]) || str[i] == '.'){
				tempNum[tempNumTop] = str[i];
				i++;
				tempNumTop++;
			}
			topNum++;
			//mengganti operator dengan character null
			tempNum[tempNumTop] = '\0';
			stackNum[topNum] = nonArithmeticOperation(strtod(tempNum, NULL), tempChar);
		}else if (str[i] =='!'){
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
	system("pause");
	system("cls");
}

void MenuLain(){
	int is_on = 1;
	while (is_on == 1){
		int pilihan;
	 	printf("Menu Kalkulator: \n");
  		printf("1. Konversi Suhu\n");
	    printf("2. Operasi Statistika\n");
	    printf("3. Operasi Pecahan\n");
	    printf("4. Konversi Jarak\n");
	    printf("5. Operasi Matrix\n");
	    printf("6. Kombinasi dan Permutasi\n");
		printf("7. Konversi Massa\n");
	    printf("0. Kembali ke menu awal\n");
	    printf("pilihan : ");
	    scanf("%d", &pilihan);
	    switch(pilihan){
	    	case 1: {system("cls");
			menu_pilih_tipe_suhu ();
			break;
			}
			case 2: {system("cls");
			ProgramStatistika();
			break;
			}
			case 3: {system("cls");
			menuPecahan();
			break;
			}
			case 4: {system("cls");
			memilih_tipe_jarak();
			break;
			}
			case 5: {system("cls");
			Matrix();
			break;
			}
			case 6: {system("cls");
			menuKombinasiPermutasi();
			break;
			}
			case 7: {system("cls");
			memilih_tipe_massa();
			break;
			}
			case 0: {
			is_on = 0;
			break;
			}
			default: {
				printf("\n\n---Invalid Input---\n\n---Mohon Ulangi---\n");
				system("pause");
				system("cls");
				main();
				break;
			}
		}

	}
	system("cls");
	main();
}

int main (){
	char choice = 'Y';
	do{
	    MenuAritmatika();
		printf("Apakah anda ingin melanjutkan? Y/T \n");
		scanf(" %c",&choice);
		getchar();
		}while(choice == 'Y' || choice == 'y');
	return 0;
	}


//end




