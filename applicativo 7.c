MAIN

area diff_7;

if ((scheda_paziente).numero_img > 1) {

	diff_7= calcola_diff_7 (&scheda_paziente.archivio[(scheda_paziente).numero_img].img, &scheda_paziente.archivio[(scheda_paziente).numero_img - 1].img, &diff_7);

	printf("La differenza di area chiara tra le due immagini è di %d pixel\n", diff_7.c);
	printf("La differenza di area scura tra le due immagini è di %d pixel\n", diff_7.s);
}
	else  
	{	
		printf("Inserire il nome del file di confronto:\n");
	 	scanf("%s", nome_img);
	 	strcat(nome_img, ".bmp");


		come si incrementa 'numero:img'
		/* tramite "scheda_paziente->numero_img++;" oppure richiamando la funzione per l'assegnazione a paziente che andrebbe usata lo stesso per assegnare l'immagine*/
		una volta aggiunta un'ulteriore immagine, l'elemento in posizione [numero_img] dovrebbe essere il nuovo elemento inserito (questo ovviamente dipende strettamente dal modo in cui si incrementa 'numero_img')?
		//si, sarebbe il nuovo elemento inserito
		In tal caso posso utilizzare gli stessi parametri..
		//che parametri?
		questa funzione potrei farla tranquillamente anche void.. dimmi se la preferisci; io probabilmente si
		//qua il problema è se potrebbe servire in seguito il calcolo del valore oppure se ti serve in locale, tanto stai lavorando su strutture e per ritornala lo fai come hai fatto per l'altro applicativo

		diff_7= calcola_diff_7 (&scheda_paziente.archivio[(scheda_paziente).numero_img].img, &scheda_paziente.archivio[(scheda_paziente).numero_img - 1].img, &diff_7);

	printf("La differenza di area chiara tra le due immagini è di %d pixel\n", diff_7.c);
	printf("La differenza di area scura tra le due immagini è di %d pixel\n", diff_7.s);

}

FUNZIONE

area calcola_diff_7 (BMP_Image* immagine1, BMP_Image* immagine2, area* diff_7) {

	area a_pixel1, a_pixel2;

	a_pixel1= calcola_area_C_S( immagine1, &a_pixel1);
	a_pixel2= calcola_area_C_S( immagine2, &a_pixel2);
	
	diff_7->c=a_pixel1.c-a_pixel2.c;
	diff_7->s=a_pixel1.s-a_pixel2.s;

	return* diff_7;
}
	

