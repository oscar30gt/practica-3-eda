/* 
  Óscar Grimal Torres, 926897
  Hugo García Sánchez, 930108
*/

#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <string>

using namespace std;

// PREDECLARACION DEL TAD evento (inicio INTERFAZ)

/* 
 * Los valores del TAD evento representarán tuplas formadas como:
 * (descripción, prioridad) siendo la descripción una cadena y la 
 * prioridad un número natural.
*/
struct Evento;

/**
 * @brief Devuelve un evento compuesto con descripción descrip y con prioridad prio.
 * @param descrip Descripción del evento.
 * @param prio Prioridad del evento.
 * @param e Evento a crear.
*/
void crearEvento(string descrip, int prio, Evento& e);

/**
 * @brief Dado un evento e formado como (D,P) devuelve la cadena D, i.e. la descripción en el evento e.
 * @param e Evento del que se quiere obtener la descripción.
 * @return Descripción del evento.
 */
string descripcion(const Evento& e);

/**
 * @brief Dado un evento e formado como (D,P) devuelve un evento igual al compuesto como (nueva,P).
 * @param e Evento del que se quiere cambiar la descripción.
 * @param nueva Nueva descripción del evento.
 */
void cambiarDescripcion(Evento& e, const string nueva);

/**
 * @brief Dado un evento e formado como (D,P), devuelve P, i.e. la prioridad en el evento e.
 * @param e Evento del que se quiere obtener la prioridad.
 * @return Prioridad del evento.
 */
int suPrioridad(const Evento& e);

/**
 * @brief Dado un evento e formado como (D,P) y un natural pri, devuelve un evento igual al compuesto como (D,pri).
 * @param e Evento del que se quiere cambiar la prioridad.
 * @param pri Nueva prioridad del evento.
 */
void cambiarPrioridad(Evento& e, const int pri);

// FIN de la PREDECLARACION DEL TAD evento (fin INTERFAZ)

// DECLARACION DEL TAD evento

struct Evento {
  friend void crearEvento(string descrip, int prio, Evento& e);
  friend string descripcion(const Evento& e);
  friend void cambiarDescripcion(Evento& e, const string nueva);
  friend int suPrioridad(const Evento& e);
  friend void cambiarPrioridad(Evento& e, const int pri);
  private:  //declaracion de la representacion interna del tipo
            //descripcion: cadena de caracteres con la descripcion del evento
            //prioridad: entero con la prioridad del evento
    string descripcion;
    int prioridad;

};

#endif