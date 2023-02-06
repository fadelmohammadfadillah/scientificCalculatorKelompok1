#include <stdio.h>
#include <stdlib.h>
#include "trigonometri.h"

int main (){
	for (;;){
		int pilihan;
		printf("Menu Kalkulator: \n");
		printf("1. Operasi Trigonometri\n");
		printf("2. Konversi Suhu\n");
	    printf("3. Operasi Eksponen\n");
	    printf("4. Operasi Aritmatika\n");
	    printf("5. Operasi Trigonometri\n");
	    printf("6. Operasi Pecahan\n");
	    printf("pilihan : ");
	    scanf("%d", &pilihan);
	    switch(pilihan){
	    	case 1: {printf("ini menu 1");
				break;
			}
			case 2: {printf("ini menu 2");
				break;
			}
			case 3: {printf("ini menu 3");
				break;
			}
			case 4: {printf("ini menu 4");
				break;
			}
			case 5: {printf("ini menu 5");
				break;
			}
			case 6: {printf("ini menu 6");
				break;
			}
			case 0: {
				exit(0);
			}
		}
	}
    return 0;
}
