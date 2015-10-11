int check_paziente(int , sio *);

int check_paziente(int ID, sio *schedario)
	{int i=0;
	
	while((ID!=schedario->scheda_paziente[i].paziente.ID_paziente)&&(i<=schedario->numero_pazienti))
		i++;
	
	if(i>=schedario->numero_pazienti){
		schedario->numero_pazienti++;
		return 0;
	}
	else{
		return 1;
	}
		
}
