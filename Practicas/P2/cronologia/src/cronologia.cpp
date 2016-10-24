#include<cstdlib>
#include<iostream>
#include<iomanip>
#include "cronologia.h"

using namespace std;


// Retorno de array de EventoHistorico
vector<EventoHistorico> Cronologia::GetEventos(){return eventos;}


// Retorno de eventos para un fecha
vector<string> Cronologia::GetEventos(int fecha){
	
	vector<string> resultado;
	
	bool encontrado = false;
	int tam = eventos.size();
	
	for(int i = 0; i < tam && !encontrado; i++){ // --> array EventoHistorico
		if( eventos.at(i).GetFecha() == fecha ){ // --> búsqueda fecha
			encontrado = true;
			resultado = eventos.at(i).GetEventos();
		}	
	}

	return resultado;
}


// Retorno de fecha para un evento
int Cronologia::GetFecha(string evento){

	int resultado;
		
	bool encontrado = false;
	int tami = eventos.size();
	
	
	for(int i = 0; i < tami && !encontrado; i++){ // --> array EventoHistorico
		int tamj = eventos.at(i).GetEventos().size();
		for(int j = 0; j < tamj && !encontrado; i++){ // --> array eventos
			if( eventos.at(i).GetEventos().at(j) == evento ){  // --> búsqueda evento
				encontrado = true;
				resultado = eventos.at(i).GetFecha();
			}
		}	
	}
	
	return resultado;
}


// Operador >> 
istream& operator>> (istream& is,Cronologia& c){
	
	// Mientras no llegue al final de fichero
	while(!is.eof()){
		// Creación y almacenamiento en array
		EventoHistorico e;
		is >> e;
		c.eventos.push_back(e);
	}
	
	// Retorno de flujo
	return is;
}



