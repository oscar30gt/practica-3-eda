/**
 * @file coleccionInterdep.hpp
 * 
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897) 
 */

#ifndef COLECCIONINTERDEP_HPP
#define COLECCIONINTERDEP_HPP

/**
 * @brief Crea una coleccion vacia, sin elementos.
 * @tparam T Tipo de los elementos de la coleccion.
 * @param coleccion Coleccion cuyo valor se quiere inicializar al de una coleccion vacia.
 */
template <typename T>
void crear(coleccionInterdep<T> &coleccion);

/**
 * @brief Devuelve el numero de elementos de la coleccion.
 * @tparam T Tipo de los elementos de la coleccion.
 * @param coleccion Coleccion de la que se quiere obtener el numero de elementos.
 * @return Numero de elementos de la coleccion.
 */
template <typename T>
int tamanyo(coleccionInterdep<T> &coleccion);

/**
 * @brief Devuelve `true` si la coleccion esta vacia, `false` en caso contrario.
 * @tparam T Tipo de los elementos de la coleccion.
 * @param coleccion Coleccion que se quiere comprobar si esta vacia.
 * @return `true` si la coleccion esta vacia, `false` en caso contrario.
 */
template <typename T>
bool esVacia(const coleccionInterdep<T> &coleccion);

template <typename T>
bool existe( const coleccionInterdep<T> &coleccion);

/**
 * @brief Estructura que representa una coleccion de elementos interdependientes.
 * @tparam T Tipo de los elementos de la coleccion.
 */
template <typename T>
struct coleccionInterdep
{
    friend void crear<T>(coleccionInterdep<T> &coleccion);
};

#endif // COLECCIONINTERDEP_HPP