/* 
 * Óscar Grimal Torres, 926897
 * Hugo García Sánchez, 930108
*/

#include "evento.hpp"

/**
 * @brief Devuelve un evento compuesto con descripción descrip y con prioridad prio.
 * @param descrip Descripción del evento.
 * @param prio Prioridad del evento.
 * @param e Evento a crear.
*/
void crearEvento(string descrip, int prio, Evento& e) {
    e.descripcion = descrip;
    e.prioridad = prio;
}

/**
 * @brief Dado un evento e formado como (D,P) devuelve la cadena D, i.e. la descripción en el evento e.
 * @param e Evento del que se quiere obtener la descripción.
 * @return Descripción del evento.
 */
string descripcion(const Evento& e) {
    return e.descripcion;
}
/**
 * @brief Dado un evento e formado como (D,P) devuelve un evento igual al compuesto como (nueva,P).
 * @param e Evento del que se quiere cambiar la descripción.
 * @param nueva Nueva descripción del evento.
 */
void cambiarDescripcion(Evento& e, const string nueva) {
    e.descripcion = nueva;
}

/**
 * @brief Dado un evento e formado como (D,P), devuelve P, i.e. la prioridad en el evento e.
 * @param e Evento del que se quiere obtener la prioridad.
 * @return Prioridad del evento.
 */
int suPrioridad(const Evento& e) {
    return e.prioridad;
}

/**
 * @brief Dado un evento e formado como (D,P) y un natural pri, devuelve un evento igual al compuesto como (D,pri).
 * @param e Evento del que se quiere cambiar la prioridad.
 * @param pri Nueva prioridad del evento.
 */
void cambiarPrioridad(Evento& e, const int pri) {
    e.prioridad = pri;
}