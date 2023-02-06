#include <stdio.h>
#include <stdlib.h>
#include "fadel.h"
#include "reno.h"
#include "adi.h"
#include "adrian.h"
#include "alya1.h"
#include "rafi.h"

int main (){
	for (;;){
		int pilihan;
		printf("Menu Kalkulator: \n");
		printf("1. Operasi Trigonometri\n");
		printf("2. Konversi Suhu\n");
	    printf("3. Operasi Eksponen\n");
	    printf("4. Operasi Aritmatika\n");
	    printf("5. Operasi Statistika\n");
	    printf("6. Operasi Pecahan\n");
	    printf("pilihan : ");
	    scanf("%d", &pilihan);
	    switch(pilihan){
	    	case 1: {MenuTrigonometri();
				break;
			}
			case 2: {menu_pilih_tipe_suhu ();
				break;
			}
			case 3: {menuEksponen();
				break;
			}
			case 4: {aritmatika();
				break;
			}
			case 5: {ProgramStatistika();
				break;
			}
			case 6: {menuPecahan();
				break;
			}
			case 0: {
				exit(0);
			}
		}
	}
    return 0;
}
