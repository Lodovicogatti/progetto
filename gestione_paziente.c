#include "gestione_paziente.h"
#include "check_paziente.c"

void assegnazione_a_paziente(sio* paziente)
{//assegnazione della scheda ad un paziente
 printf("\ninserire l'ID del paziente:\t");
 scanf("%d", &paziente->scheda_paziente[paziente->numero_pazienti].paziente.ID_paziente);
 
 if(check_paziente(paziente->scheda_paziente[paziente->numero_pazienti].paziente.ID_paziente, paziente))
 	paziente->scheda_paziente[paziente->numero_pazienti].numero_img+1;
 
 else{
 	printf("\ninserire il nome del paziente a cui e' collegata l'immagine:\t");
 	scanf("%s", paziente->scheda_paziente[paziente->numero_pazienti-1].paziente.nome);
 	printf("\ninserire il cognome del paziente a cui e' collegata l'immagine:\t");
 	scanf("%s", paziente->scheda_paziente[paziente->numero_pazienti-1].paziente.cognome);
 
  
 	//gestione storicizzazione immagine
 
 	//ANNO
 	do{
 		printf("\n\ninserire l'anno in cui e' stata presa l'immagine(aaaa):\t\t");
 		scanf("%d", &paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.anno);
 	}while(paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.anno<2015);
 
 
 	//MESE
 	do{
 		printf("\n\ninserire il mese in cui e' stata presa l'immagine(mm):\t\t");
 		scanf("%d", &paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese);
 	}while((paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese>13)&&(&paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese<0));
 
 	//GIORNO
 	//febbraio
 	if(paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==2){
 		do{
 			printf("\n\ninserire il giorno in cui e' stata presa l'immagine(gg):\t");
 			scanf("%d", &paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.giorno);
 		 }while((paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.giorno>29)&&(&paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.giorno<0));
 	}	
 	//aprile, giugno, settembre, novembre
 	else if((paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==4)||(paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==9)||(paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==11)){
 		do{
 			printf("\n\ninserire il giorno in cui e' stata presa l'immagine(gg):\t");
 			scanf("%d", &paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.giorno);
 		 }while((paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.giorno>31)&&(&paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.giorno<0));
 	}
 	
 	//altri mesi
 	else if((paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==1)||(paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==5)||(paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==7)||(paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==8)||(paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==10)||(paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.mese==12)){
 		do{
 			printf("\n\ninserire il giorno in cui e' stata presa l'immagine(gg):\t");
 			scanf("%d", &paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.giorno);
 		 }while((paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.giorno>32)&&(&paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].date.giorno<0));
 	} 
 
 	//incremento della dimensione dell'archivio
	paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img++;	
	}
		
}
