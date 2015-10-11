#define DIM 5

typedef struct{
	char nome[DIM];
	char cognome[DIM];
	int ID_paziente;	
}persona;

typedef struct{
	int giorno;
	int mese;
	int anno;
}date;

typedef struct{
	BMP_Image img;
	date date;
	char nome[DIM];
}archivio_img;

typedef struct{
	archivio_img archivio[DIM];
	int numero_img;
	persona paziente; 
}scheda;

typedef struct{
	scheda scheda_paziente[DIM];
	int numero_pazienti;
}sio;			//sistema informativo ospedaliero



//creazione scheda_paziente
void assegnazione_a_paziente(sio *);


