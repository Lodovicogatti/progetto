#include "applicativo 6e7.h"

void calcola_area_C_S (BMP_Image* immagine, area* a_pixel) {
    a_pixel->s=0;
    a_pixel->c=0;
    int i, j;
    
    for(i=0; i<DATA_DIM; i++)
        for(j=0; j<DATA_DIM; j++) {
            if ((immagine->data[i][j].grey<50) && (immagine->data[i][j].grey != 0)){
                a_pixel->c++;
            }
            else if ((immagine->data[i][j].grey>205) && (immagine->data[i][j].grey!= 255)){
                a_pixel->s++; 
            }
        }
    
    
}

void calcola_diff (BMP_Image* immagine1, BMP_Image* immagine2, area* diff_7) {
    
    area a_pixel1, a_pixel2;
    
    calcola_area_C_S( immagine1, &a_pixel1);
    calcola_area_C_S( immagine2, &a_pixel2);
    
    diff_7->c=a_pixel1.c-a_pixel2.c;
    diff_7->s=a_pixel1.s-a_pixel2.s;    
}
