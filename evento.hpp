/**
 * @file evento.hpp
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
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
 * @brief Inicializa un evento compuesto con descripción `descrip` y con prioridad `prio`.
 * @param descrip Descripción del evento.
 * @param prio Prioridad del evento.
 * @param[out] e Evento cuyo valor se quiere inicializar.
 */
void crearEvento(string descrip, int prio, Evento &e);

/**
 * @brief Dado un evento `e`, devuelve la descripción en el evento.
 * @param[in] e Evento del que se quiere obtener la descripción.
 * @return Descripción del evento.
 */
string descripcion(const Evento &e);

/**
 * @brief Dado un evento `e`, cambia su descripción a `nueva`.
 * @param[in, out] e Evento del que se quiere cambiar la descripción.
 * @param nueva Nueva descripción del evento.
 */
void cambiarDescripcion(Evento &e, const string nueva);

/**
 * @brief Dado un evento `e`, obtiene su prioridad `p`.
 * @param[in] e Evento del que se quiere obtener la prioridad.
 * @returns Prioridad del evento.
 */
int suPrioridad(const Evento &e);

/**
 * @brief Dado un evento `e`, y un natural `pri`, cambia la prioridad del evento `e` a `pri`.
 * @param[in, out] e Evento del que se quiere cambiar la prioridad.
 * @param pri Nueva prioridad del evento.
 */
void cambiarPrioridad(Evento &e, const int pri);

// FIN de la PREDECLARACION DEL TAD evento (fin INTERFAZ)

// DECLARACION DEL TAD evento

/**
 * @brief Estructura que representa un evento.
 */
struct Evento
{
	friend void crearEvento(string descrip, int prio, Evento &e);
	friend string descripcion(const Evento &e);
	friend void cambiarDescripcion(Evento &e, const string nueva);
	friend int suPrioridad(const Evento &e);
	friend void cambiarPrioridad(Evento &e, const int pri);

private:

	/** Descripcion del evento */
	string descripcion;
	
	/** Prioridad del evento */
	int prioridad;
};

// FIN de la DECLARACION DEL TAD evento

#endif // EVENTO_HPP