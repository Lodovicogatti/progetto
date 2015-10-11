//applicativo 8
#include "applicativo 8.h"

void confronto_img(sio *paziente){
	char parametro;
		
	printf("Premere:\n\t");
	printf("p: per eseguire un confronto tra immagini dello stesso paziente\n\t");
	printf("l: per eseguire un confronto tra immagini con stesso livello\n");
	scanf("%c",&parametro);
	fflush(stdin);
	
	if(parametro=='p'){
		
		char nome_img_confronto[DIM];
		int i=0;
		
		printf("inserire il nome dell'immagine da confrontare:\n");
		scanf("%s", nome_img_confronto);
		strcat(nome_img_confronto, ".bmp");
		
		while((!strcmp(nome_img_confronto, paziente->scheda_paziente[paziente->numero_pazienti].archivio[i].nome))&&(i<=paziente->scheda_paziente[paziente->numero_pazienti].numero_img));		
			i++;
			
		if(i>paziente->scheda_paziente[paziente->numero_pazienti].numero_img)
			printf("l'immagine cercata non e' presente in archivio.");
		
		else{
			calcola_diff(&paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[i].img , &paziente->scheda_paziente[paziente->numero_pazienti-1].archivio[paziente->scheda_paziente[paziente->numero_pazienti-1].numero_img].img , &area_app_8 );
		}
				
	}//chiusura if
	
	else if(parametro=='l'){
		int ID_confronto;
		int i=0, j=0;
		char nome_img_confronto[DIM];
		
		printf("\n\ninserire l'ID del paziente con cui si vuole fare il confronto");
		scanf("%d", &ID_confronto);
		
		while((ID_confronto!=paziente->scheda_paziente[i].paziente.ID_paziente)&&(i<=paziente->numero_pazienti))
			i++;
		
		if(i>paziente->numero_pazienti)
			printf("error: il paziente non è registrato");
		else if(i<=paziente->numero_pazienti){
			printf("inserire il nome dell'immagine da confrontare:\n");
			scanf("%s", nome_img_confronto);
			strcat(nome_img_confronto, ".bmp");
		
			while((!strcmp(nome_img_confronto, paziente->scheda_paziente[i].archivio[j].nome))&&(j<=paziente->scheda_paziente[i].numero_img))
				j++;
			if(j>paziente->scheda_paziente[i].numero_img)
				printf("l'immagine cercata non e' presente in archivio.");
			else {
				calcola_diff(&paziente->scheda_paziente[i].archivio[j].img , &paziente->scheda_paziente[paziente->numero_pazienti].archivio[paziente->scheda_paziente[paziente->numero_pazienti].numero_img].img , &area_app_8 );
			}
	
		}

	
	}
}
