/**
 * @file coleccionInterdep.hpp
 * 
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897) 
 */

#ifndef COLECCIONINTERDEP_HPP
#define COLECCIONINTERDEP_HPP

using namespace std;

// PREDECLARACION DEL TAD GENERICO coleccionInterdep (inicio INTERFAZ)

/*
 *  Los valores del TAD representan colecciones de elementos formados como tuplas
 *  de la forma (ident, val, -, NumDepend) o bien (ident, val, identSup, NumDepend). A los elementos
 *  con forma (ident, val, -, NumDepend) los llamaremos en general ‘elementos independientes’,
 *  mientras que a los elementos con forma (ident, val, identSup, NumDepend), los llamaremos en
 *  general ‘elementos dependientes’. En la colección no podrá haber dos elementos con el mismo
 *  ident.
 *  En las tuplas que representan elementos dependientes, la información identSup será la 
 *  identificación del elemento del que es directamente dependiente el elemento con identificación
 *  ident. Ningún elemento de la colección podrá ser directamente dependiente de sí mismo, y todo
 *  elemento dependiente debe serlo de otro elemento que exista en la colección (que a su vez puede
 *  ser un elemento independiente o dependiente).
 *  En cada elemento, la información NumDepend de su tupla representará el número total de elementos
 *  en la colección que son directamente dependientes del elemento con identificador ident, y que
 *  será 0 si ningún elemento de la colección depende de dicho elemento.}
*/
template<typename T> struct colecInterdep;

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