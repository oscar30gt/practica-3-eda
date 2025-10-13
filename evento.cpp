/**
 * @file evento.cpp
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 */

#include "evento.hpp"

/**
 * @brief Inicializa un evento compuesto con descripción `descrip` y con prioridad `prio`.
 * @param descrip Descripción del evento.
 * @param prio Prioridad del evento.
 * @param[out] e Evento cuyo valor se quiere inicializar.
 */
void crearEvento(string descrip, int prio, evento& e) {
    e.desc = descrip;
    e.pri = prio;
}

/**
 * @brief Dado un evento `e`, devuelve la descripción en el evento.
 * @param[in] e Evento del que se quiere obtener la descripción.
 * @return Descripción del evento.
 */
string descripcion(const evento& e) {
    return e.desc;
}

/**
 * @brief Dado un evento `e`, cambia su descripción a `nueva`.
 * @param[in, out] e Evento del que se quiere cambiar la descripción.
 * @param nueva Nueva descripción del evento.
 */
void cambiarDescripcion(evento& e, const string nueva) {
    e.desc = nueva;
}

/**
 * @brief Dado un evento `e`, obtiene su prioridad `p`.
 * @param[in] e Evento del que se quiere obtener la prioridad.
 * @returns Prioridad del evento.
 */
int suPrioridad(const evento& e) {
    return e.pri;
}

/**
 * @brief Dado un evento `e`, y un natural `pri`, cambia la prioridad del evento `e` a `pri`.
 * @param[in, out] e Evento del que se quiere cambiar la prioridad.
 * @param pri Nueva prioridad del evento.
 */
void cambiarPrioridad(evento& e, const int pri) {
    e.pri = pri;
}