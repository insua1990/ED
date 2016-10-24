#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "eventohistorico.h"

using namespace std;


// Asignación de fecha para evento
void EventoHistorico::SetFecha(int fec){ if(fec>0) fecha = fec;return;}

// Retorno de fecha de evento
int EventoHistorico::GetFecha(){return fecha;}

// Retorno de eventos 
vector<string> EventoHistorico::GetEventos(){return eventos;}

// Operador >>
istream& operator>> (istream& is, EventoHistorico& e){
	
	// Recogemos la línea y la almacenamos 
	// en 'evento_temp'.
	string evento_temp;	
	getline(is, evento_temp ,'\n');
	stringstream ss;
	ss.str(evento_temp);
	
	// Cogemos fecha de 'evento_temp'.
	string fecha_str;
	getline(ss, fecha_str, '#');
	e.SetFecha( atoi( fecha_str.c_str() ) );


	// Cogemos eventos de 'evento_temp'.
	string item;
	while (getline(ss, item,'#')) 
		e.eventos.push_back(item);
	
	// Retorno de flujo.
	return is;
}

