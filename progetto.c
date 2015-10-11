#include <stdio.h>
#include <string.h>
#include "bmp.c"
#include "gestione_paziente.c"
#include "applicativo 1,2e3.c"
#include "applicativo 4e5.c"
#include "applicativo 6e7.c"
#include "applicativo 8.c"

int main() {
    
     char nome_img[20];
	 int scelta;
	 sio clinica;
	 char choise='n';	
	 int i=0;
     
	 clinica.numero_pazienti=0;					//inizializzazione numero pazienti 
	 for(i=0; i<DIM; i++)
	 	clinica.scheda_paziente[i].numero_img=0;  	//inizializzazione numero immagine del paziente   
	 
	 do{
	 	if(choise=='n'){
	 		printf("Inserire il nome del file da trattare:\n");
	 		scanf("%s", nome_img);
	 		strcat(nome_img, ".bmp");
		 }	
	 	if(!loadBMP(nome_img, &clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img))
	  		{if(choise!='a'){
				assegnazione_a_paziente(&clinica);				//assegna l'immagine ad un paziente specifico
	  	 		strcpy(clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].nome, nome_img);		//salvataggio nominativo immagine nella struttura designata
		 	}
		 	//gestione applicativi
		 	printf("\n\ninserire:\n");
		 		printf("1 - Calcolare il numero di grigi presenti nell'immagine\n");
		 		printf("2 - Calcolare la distribuzione dei livelli di grigio\n");
		 		printf("3 - Ridurre i livelli di grigio a 10\n");
	 	 		printf("4 - Definire il contorno della parte informativa dell’immagine\n");
	 	 		printf("5 - Calcolare l' area inclusa nel contorno evidenziato precedentemente, in termini di pixel e in mm2\n");
	 	 		printf("6 - Calcolare l' area totale delle zone molto scure e molto chiare all'interno dell'area informativa\n");
	 	 		printf("7 - Calcolare la variazione delle due aree fra due immagini successive\n");
	 	 		printf("8 - Calcolare la variazione delle due aree fra due immagini a scelta\n");
	 	 	
	 	 	scanf("%d", &scelta);
	 	 	fflush(stdin);
	 	 	
	 	 	switch(scelta){
	 	 		case 1:
	 	 			printf("\n\n\tCalcolo del numero di grigi presenti nell'immagine.\n\n");
	 	 			grigi=livelli_di_grigio(&clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img, scelta);
	 	 			printf("il numero di grigi presenti nell'immagine e': %d", grigi);
	 	 			break;
	 	 		case 2:
	 	 			printf("\n\n\tCalcolo della distribuzione dei livelli di grigio.\n\n");
	 	 			livelli_di_grigio(&clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img, scelta);
	 	 			break;
	 	 		case 3:
	 	 			printf("\n\n\tRiduzione dei livelli di grigio a 10 livelli.\n\n");
	 	 			livelli_di_grigio(&clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img, scelta);
	 	 			break;
	 	 		case 4:
	 	 			printf("\n\n\tDefinizione del contorno della parte informativa dell'immagine.\n\n");
	 	 			contorno(&clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img);
	 	 			break;
	 	 		case 5:
	 	 			printf("\n\n\tCalcolo dell area inclusa nel contorno in pixel e cm2.\n\n");
	 	 			Area_cm(&clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img);
	 	 			break;
			    case 6:
	 	 			printf("\n\n\tCalcolo dell area totale delle zone molto scure e molto chiare.\n\n");
                    calcola_area_C_S(&clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img, &a_pixel);
                    mm_c = (a_pixel.c)*2.5*2.5;
                    mm_s = (a_pixel.s)*2.5*2.5;
                    
                    printf ("L'area molto chiara e' di %d pixel e %f mm2\n", a_pixel.c, mm_c);
                    printf ("L'area molto scura e' di %d pixel e %f mm2\n", a_pixel.s, mm_s);
                    
                    break;
	 	 		case 7:
	 	 			printf("\n\n\tCalcolo della variazione delle due aree fra due immagini successive.\n\n");
	 	 			if(clinica.scheda_paziente[clinica.numero_pazienti].numero_img>1){
	 	 				calcola_diff(&clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img, &clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img-1].img, &diff_7);
	 	 				printf("La differenza di area chiara tra le due immagini è di %d pixel\n", diff_7.c);
						printf("La differenza di area scura tra le due immagini è di %d pixel\n", diff_7.s);
					  }
					else{
						printf("Inserire il nome del file da confrontare:\n");
	 					scanf("%s", nome_img);
	 					strcat(nome_img, ".bmp");
						if(!loadBMP(nome_img, &clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img)){
							assegnazione_a_paziente(&clinica);				//assegna l'immagine ad un paziente specifico
	  	 					strcpy(clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].nome, nome_img);		//salvataggio nominativo immagine nella struttura designata
	  	 					
							calcola_diff(&clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img, &clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img-1].img, &diff_7);
						}
					printf("La differenza di area chiara tra le due immagini è di %d pixel\n", diff_7.c);
					printf("La differenza di area scura tra le due immagini è di %d pixel\n", diff_7.s);
					}		
	 	 			break;
	 	 		case 8:
	 	 			printf("\n\n\tCalcolo della variazione delle due aree fra due immagini a scelta.\n\n");
	 	 			printf("la variazione di area tra le due immagini e':");
	 	 			break;
			    default:
			    	printf("ERRORE! La scelta non è eseguibile perchè non contemplata");
			  }//chiusura switch
		}//chiusura if
		
		clinica.scheda_paziente[clinica.numero_pazienti-1].numero_img++;
		
		fflush(stdin);
		printf("\n\nPremere:\n\t");
		printf("c - chiusura programma.\n\t");
		printf("a - analisi di una diversa caratteristica della stessa immagine.\n\t");
		printf("n - analisi nuova immagine.\n");
		scanf("%c", &choise);
	 }while(choise!='c');
	 
	 if((choise=='c')||(choise=='n'))
	 	saveBMP(clinica.scheda_paziente[clinica.numero_pazienti].archivio[clinica.scheda_paziente[clinica.numero_pazienti].numero_img].img, nome_img);	
	 return 0;
}

