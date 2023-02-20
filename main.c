#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fadel.h"
#include "reno.h"
#include "adi.h"
#include "adrian.h"
#include "alya1.h"
#include "rafi.h"

int main (){
	int is_on = 1;
	while (is_on == 1){
		int pilihan;
	 	printf("Menu Kalkulator: \n");
		printf("1. Operasi Trigonometri\n");
		printf("2. Konversi Suhu\n");
	    	printf("3. Operasi Eksponen\n");
	    printf("4. Operasi Aritmatika\n");
	    printf("5. Operasi Statistika\n");
	    printf("6. Operasi Pecahan\n");
	    printf("7. Konversi Jarak\n");
	    printf("8. Operasi Matrix\n");
	    printf("9. Faktorial, Kombinasi dan Permutasi\n");
	    printf("0. Exit Program\n");
	    printf("pilihan : ");
	    scanf("%d", &pilihan);
	    switch(pilihan){
	    	case 1: {system("cls");
			MenuTrigonometri();
			break;
			}
			case 2: {system("cls");
			menu_pilih_tipe_suhu ();
			break;
			}
			case 3: {system("cls");
			menuEksponen();
			break;
			}
			case 4: {system("cls");
			MenuAritmatika();
			break;
			}
			case 5: {system("cls");
			ProgramStatistika();
			break;
			}
			case 6: {system("cls");
			menuPecahan();
			break;
			}
			case 7:{system("cls");
			memilih_tipe_jarak();
			break;
			}
			case 8: {system("cls");
			Matrix();
			break;
			}
			case 9:{system("cls");
			menuFaktorialPermutasiKombinasi();
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
    return 0;
}
