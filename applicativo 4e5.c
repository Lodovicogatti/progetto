#include "applicativo 4e5.h"


void contorno (BMP_Image *img) {
    int i,j;
    char val_o, val_v;

    for(i=0;i<DATA_DIM;i++) {
        j=0;
        while ((!(img->data[i][j].grey))&&(j<=DATA_DIM))
			j++;
        if (j!=255)
			img->data[i][j].grey=255;         //saturo al massimo, in modo da avere il contorno evidente e riconoscibile, controllando di non essere alla fine dell'immagine
        }

    for(i=DATA_DIM;i>0;i++) {
        j=DATA_DIM;
        while (!(img->data[i][j].grey)&&(j>=0))
			j--;
		if (j!=0)
        	img->data[i][j].grey=255;                         //stessa cosa, dalla parte opposta
        }

}

void Area_cm (BMP_Image *img) {

    int i,j, sx, dx, area_pix=0, area_cm;

    for (i=0;i<DATA_DIM;i++) {
        j=0;
        while((!(img->data[i][j].grey))&&(j<=DATA_DIM)) j++;
        if (j!=DATA_DIM) {
            sx=j;
            j=(DATA_DIM-1);
            while((!(img->data[i][j].grey))&&(j>0)) j--;
            if (j!=sx) dx=j;
            else {
                dx=sx;
                sx=0;
            }
        }
        else {
            dx=0;
            sx=0;
        }
        area_pix=(area_pix+(dx-sx));

    }
    area_cm=area_pix*0.0625;

    printf ("\n\nDimensione area contenente informazione: \n\t %d cm^2 \n\t %d pixel", area_cm, area_pix);

}
