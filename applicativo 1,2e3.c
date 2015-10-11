//gestione primo, secondo e terzo applicativo
#include "applicativo 1,2e3.h"


char livelli_di_grigio(BMP_Image *immagine, int scelta){
	int i,j;
	
	for(i=0; i<DATA_DIM; i++)
		for(j=0; j<DATA_DIM; j++)
			immagine->color_table[immagine->data[i][j].grey]++;
		
	
	if(scelta==1){
		unsigned char n_grigi=0;
		
		for(i=0; i<DATA_DIM; i++)
			if(immagine->color_table[i]!=0)
				n_grigi++;
				
	 	return n_grigi;
	}
	
	else if(scelta==2){
		for(i=0; i<DATA_DIM; i++)
			printf("Ho: %d grigi\t di gradazione %d \n", immagine->color_table[i], i);
	}
				
	else if(scelta==3){		//riduzione a 10 livelli
		for(i=0;i<DATA_DIM;i++)
			for(j=0;j<DATA_DIM;j++)
				immagine->data[i][j].grey=(immagine->data[i][j].grey/26);
	}
		
}
