/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include<iostream>
#include<string>
#include<vector>
#include"eventohistorico.h"

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un objeto
  * compuestos por un array del tipo de dato abstracto @c EventoHistorico  que representan
  * un conjunto de eventos históricos. Lo representamos
  *
  * { EventoHistorico1,EventoHistorico2,... }
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Jose Manuel Martínez de la Insua
  * @date Octubre 2016
  */

class Cronologia {
	private:
		/**
		  * @page repC Rep del TDA Cronologia
		  *
		  * @section invC Invariante de la representación
		  *
		  * El conjunto lo representa un array de EventoHistorico,luego 
		  * debe de seguir las restricciones de la clase EventoHistorico.
		  * 
		  *
		  * @section faC Función de abstracción
		  * 
		  * El array de EventoHistorico es un vector<EventoHistorico>. 
		  *
		  * Un objeto válido @e rep del TDA Cronologia representa al valor
		  *
		  * (rep.eventos)
		  *
		  */
		vector<EventoHistorico> eventos; /**< eventos */
	public:
		/**
		 * @brief Obtiene el vector de EventoHistorico.
		 *
		 * @return Retorna un vector de EventoHistorico.
		 */
		vector<EventoHistorico> GetEventos();


		/**
		 * @brief Obtiene los eventos correspondientes a una fecha dada.
		 *
		 * @param fecha El año del cual queremos conocer el(los) evento(s).
		 * @return Retorna un vector de cadenas de caracteres con el(los) evento(s).
		 */
		vector<string> GetEventos(int fecha);

		/**
		 * @brief Obtiene la fecha correspondientes a un evento dado.
		 *
		 * @param evento El evento acerca del cual queremos conocer la fecha.
		 * @return Retorna un entero con la fecha.
		 */
		int GetFecha(string evento);

		/**
		  * @brief Entrada de una instancia de Cronologia desde istream
		  * @param is stream de entrada
		  * @param c Cronologia que recibe el valor
		  * @return La referencia al istream
		  * @pre La entrada es un fichero con varias líneas. Cada línea está separada por "#"  
		  * con una fecha al principio y un(unos) evento(s) a continuación hasta el fin de línea.
		  */
		friend istream& operator>> (istream& is,Cronologia& c);
};

#endif
