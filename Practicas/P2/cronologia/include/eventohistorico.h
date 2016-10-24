/**
  * @file eventohistorico.h
  * @brief Fichero cabecera del TDA EventoHistorico
  *
  */
#ifndef __EVENTOHISTORICO
#define __EVENTOHISTORICO

#include <iostream>
#include <string>
#include <vector>


using namespace std;

/**
  *  @brief T.D.A. EventoHistorico
  *
  * Una instancia @e e del tipo de datos abstracto @c EventoHistorico es un objeto
  * compuestos por un valor entero y un array de cadenas de caracteres que representan,
  * respectivamente, fecha y eventos de una instancia. Lo representamos: 
  *
  * fecha , { evento1,evento2,... } 
  *
  * Un ejemplo de su uso:
  * @include cronologia.cpp
  *
  * @author Jose Manuel Martínez de la Insua
  * @date Octubre 2016
  */

class EventoHistorico {

	private:
		/**
		  * @page repConjunto Rep del TDA EventoHistorico
		  *
		  * @section invConjunto Invariante de la representación
		  *
		  * Los eventos se representan en inglés, no puede tener la letra 'ñ'.
		  * La fecha se representa únicamente por el año, luego no puede ser un valor negativo.
		  *
		  * @section faConjunto Función de abstracción
		  * 
		  * La fecha es un int.
		  * El array de cadenas de caracteres es un vector<string>. 
		  *
		  * Un objeto válido @e rep del TDA EventoHistorico representa al valor
		  *
		  * (rep.fecha,rep.eventos)
		  *
		  */

		int fecha; /**< fecha */ 
		vector<string> eventos;/**< eventos */ 

	public:
		/**
		 * @brief Asigna una año a la variable 'fecha'.
		 * @param fec Año que se asigna a la variable 'fecha'.
		 * @return void.
		 */
		void SetFecha(int fec);
		
		
		/**
		 * @brief Obtiene la fecha correspondientes a la instancia de la clase (Objeto this).
		 *
		 * @return Retorna un entero con la fecha.
		 */
		int GetFecha();
		

		/**
		 * @brief Obtiene los eventos correspondientes a la instancia de la clase (Objeto this).
		 *
		 * @return Retorna un vector de cadenas de caracteres con el(los) evento(s).
		 */
		vector<string> GetEventos();


		/**
		  * @brief Entrada de una instancia de EventoHistorico desde istream
		  * @param is stream de entrada
		  * @param e EventoHistorico que recibe el valor
		  * @return La referencia al istream
		  * @pre La entrada es una línea separado por "#" con una fecha al principio y un(unos) 
		  * evento(s) a continuación hasta el fin de línea.
		  */
		friend istream& operator>> (istream& is, EventoHistorico& e);

};

#endif
