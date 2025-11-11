/**
 * @file colecInterdep.hpp
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 */

#ifndef COLECINTERDEP_HPP
#define COLECINTERDEP_HPP

#include "pila.hpp"

using namespace std;

// PREDECLARACION DEL TAD GENERICO colecInterdep (inicio INTERFAZ)

/**
 * @brief Representa una colección de elementos con dependencias entre ellos. Los elementos tienen la forma:
 *      - (ident, val, -, NumDepend) para elementos independientes.
 *      - (ident, val, identSup, NumDepend) para elementos dependientes.
 *
 * @tparam I Tipo del identificador de los elementos de la coleccion. Debe tener definidos los operadores de comparacion `<` y `==`.
 * @tparam V Tipo de los elementos de la coleccion.
 *
 * No pueden existir dos elementos en la colección con el mismo identificador.
 * Ningún elemento en la colección puede depender directamente de sí mismo.
 */
template <typename I, typename V>
struct colecInterdep;

/**
 * @brief Inicializa `c` como una coleccion vacia, sin elementos.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[out] c Coleccion a inicializar.
 */
template <typename I, typename V>
void crear(colecInterdep<I, V> &c);

/**
 * @brief Devuelve el numero de elementos de la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos.
 * @returns Numero de elementos de la coleccion.
 */
template <typename I, typename V>
int tamanyo(const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si la coleccion `c` esta vacia.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar si esta vacia.
 * @returns `true` si la coleccion esta vacia, `false` en caso contrario.
 */
template <typename I, typename V>
bool esVacia(const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento con identificador `id`.
 * @returns `true` si existe un elemento con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename I, typename V>
bool existe(const I &id, const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion `c` y es dependiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento dependiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento dependiente con identificador `id`.
 * @returns `true` si existe un elemento dependiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename I, typename V>
bool existeDependiente(const I &id, const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion `c` y es independiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento independiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento independiente con identificador `id`.
 * @returns `true` si existe un elemento independiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename I, typename V>
bool existeIndependiente(const I &id, const colecInterdep<I, V> &c);

/**
 * @brief Añade un elemento dependiente con identificador `id` y valor `v` a la coleccion `c`.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento dependiente.
 * @param[in] id Identificador del elemento dependiente que se quiere añadir a la coleccion.
 * @param[in] v Valor del elemento dependiente que se quiere añadir a la coleccion.
 */
template <typename I, typename V>
void anyadirIndependiente(colecInterdep<I, V> &c, const I &id, const V &v);

/**
 * @brief Añade un elemento independiente con identificador `id` y valor `v` a la coleccion `c`.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento independiente.
 * @param[in] id Identificador del elemento independiente que se quiere añadir a la coleccion.
 * @param[in] v Valor del elemento independiente que se quiere añadir a la coleccion.
 * @param[in] super Identificador del elemento independiente que sera el supervisor del nuevo elemento dependiente.
 */
template <typename I, typename V>
void anyadirDependiente(colecInterdep<I, V> &c, const I &id, const V &v, const I &super);

/**
 * @brief Convierte el elemento con identificador `id` en dependiente del elemento con identificador `super`.
 * En caso de que el elemento con identificador `id` ya sea dependiente, actualiza su supervisor a `super`.
 * Si no existe alguno de los dos elementos con identificadores `id` o `super`, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en dependiente.
 * @param[in] id Identificador del elemento que se quiere convertir en dependiente.
 * @param[in] super Identificador del elemento que sera el supervisor del elemento que se quiere convertir en dependiente.
 */
template <typename I, typename V>
void hacerDependiente(const colecInterdep<I, V> &c, const I &id, const I &super);

/**
 * @brief Convierte el elemento con identificador `id` en independiente.
 * En caso de que el elemento con identificador `id` ya sea independiente, no se realiza ningun cambio.
 * Si el elemento con identificador `id` no existe, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en independiente.
 * @param[in] id Identificador del elemento que se quiere convertir en independiente.
 */
template <typename I, typename V>
void hacerIndependiente(const colecInterdep<I, V> &c, const I &id);

/**
 * @brief Actualiza el valor del elemento con identificador `id` en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere actualizar.
 * @param[in] id Identificador del elemento que se quiere actualizar.
 * @param[in] nuevo Nuevo valor que se quiere asignar al elemento.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 */
template <typename I, typename V>
void actualizarVal(const colecInterdep<I, V> &c, const I &id, const V &nuevo, bool &error);

/**
 * @brief Obtiene el valor del elemento con identificador `id` de la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento del que se quiere obtener el valor.
 * @param[in] c Coleccion de la que se quiere obtener el valor del elemento con identificador `id`.
 * @param[out] v Valor del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 */
template <typename I, typename V>
void obtenerVal(const I &id, const colecInterdep<I, V> &c, V &v, bool &error);

/**
 * @brief Obtiene el identificador del supervisor del elemento con identificador `id` de la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento del que se quiere obtener el identificador de su supervisor.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del elemento con identificador `id`.
 * @param[out] sup Identificador del supervisor del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado o elemento independiente).
 */
template <typename I, typename V>
void obtenerSupervisor(const I &id, const colecInterdep<I, V> &c, I &sup, bool &error);

/**
 * @brief Obtiene el numero de elementos dependientes del elemento con identificador `id` de la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento del que se quiere obtener el numero de elementos dependientes.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del elemento con identificador `id`.
 * @param[out] num Numero de elementos dependientes del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 */
template <typename I, typename V>
void obtenerNumDependientes(const I &id, const colecInterdep<I, V> &c, int &num, bool &error);

/**
 * @brief Elimina el elemento con identificador `id` de la coleccion `c`.
 * En caso de que el elemento con identificador `id` no exista en la coleccion, no se realiza ningun cambio.
 * Solo se puede eliminar un elemento si no tiene elementos que dependan de él.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento que se quiere eliminar de la coleccion.
 * @param[in, out] c Coleccion de la que se quiere eliminar el elemento con identificador `id`.
 */
template <typename I, typename V>
void borrar(const I &id, colecInterdep<I, V> &c);

/**
 * @brief Inicializa el iterador de la coleccion `c`, para recorrer sus elementos de menor a mayor identificador.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion cuyo iterador se quiere inicializar.
 */
template <typename I, typename V>
void iniciarIterador(colecInterdep<I, V> &c);

/**
 * @brief Comprueba queda algún elemento por visitar en la colección `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar.
 * @returns `true` si existe un siguiente elemento, `false` en caso contrario.
 */
template <typename I, typename V>
bool existeSiguiente(const colecInterdep<I, V> &c);

/**
 * @brief Obtiene el identificador del siguiente elemento a visitar en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del siguiente elemento.
 * @param[out] id Identificador del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 */
template <typename I, typename V>
void siguienteIdent(const colecInterdep<I, V> &c, I &id, bool &error);

/**
 * @brief Obtiene el valor del siguiente elemento a visitar en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el valor del siguiente elemento.
 * @param[out] v Valor del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 */
template <typename I, typename V>
void siguienteVal(const colecInterdep<I, V> &c, V &v, bool &error);

/**
 * @brief Indica si el siguiente elemento a visitar en la coleccion `c` es dependiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere comprobar si el siguiente elemento es dependiente.
 * @param[out] dep Si el siguiente elemento a visitar es dependiente. `true` si es dependiente, `false` si es independiente.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 */
template <typename I, typename V>
void siguienteDependiente(const colecInterdep<I, V> &c, bool &dep, bool &error);

/**
 * @brief Obtiene el supervisor del siguiente elemento a visitar en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del siguiente elemento.
 * @param[out] sup Identificador del supervisor del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar o el elemento es independiente).
 */
template <typename I, typename V>
void siguienteSuperior(const colecInterdep<I, V> &c, I &sup, bool &error);

/**
 * @brief Obtiene el numero de elementos que dependen del siguiente elemento a visitar en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del siguiente elemento.
 * @param[out] num Numero de elementos dependientes del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 */
template <typename I, typename V>
void siguienteNumDependientes(const colecInterdep<I, V> &c, int &num, bool &error);

/**
 * @brief Avanza el iterador de la coleccion `c` al siguiente elemento.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion
 * @param[in, out] c Coleccion cuyo iterador se quiere avanzar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 */
template <typename I, typename V>
void avanzarIterador(colecInterdep<I, V> &c, bool &error);

// FIN PREDECLARACION DEL TAD GENERICO colecInterdep (fin INTERFAZ)

// DECLARACION DEL TAD GENERICO coleccionInterdep (inicio IMPLEMENTACION)

/**
 * @brief Representa una colección de elementos con dependencias entre ellos. Los elementos tienen la forma:
 *      - (ident, val, -, NumDepend) para elementos independientes.
 *      - (ident, val, identSup, NumDepend) para elementos dependientes.
 *
 * @tparam I Tipo del identificador de los elementos de la coleccion. Debe tener definidos los operadores de comparacion `<` y `==`.
 * @tparam V Tipo de los elementos de la coleccion.
 *
 * No pueden existir dos elementos en la colección con el mismo identificador.
 * Ningún elemento en la colección puede depender directamente de sí mismo.
 */
template <typename I, typename V>
struct colecInterdep
{
    /* Funciones amigas para permitir el acceso a los campos privados del TAD, asi como su modificacion.
       Por especificacion, dichas funciones emplean unicamente en su implementacion los operadores de
       comparacion de igualdad (`==`) y de orden (`<`) a la hora de comparar identificadores. */
    friend void crear<I, V>(colecInterdep<I, V> &c);
    friend int tamanyo<I, V>(const colecInterdep<I, V> &c);
    friend bool esVacia<I, V>(const colecInterdep<I, V> &c);
    friend bool existe<I, V>(const I &id, const colecInterdep<I, V> &c);
    friend bool existeDependiente<I, V>(const I &id, const colecInterdep<I, V> &c);
    friend bool existeIndependiente<I, V>(const I &id, const colecInterdep<I, V> &c);
    friend void anyadirIndependiente<I, V>(colecInterdep<I, V> &c, const I &id, const V &v);
    friend void anyadirDependiente<I, V>(colecInterdep<I, V> &c, const I &id, const V &v, const I &super);
    friend void hacerDependiente<I, V>(const colecInterdep<I, V> &c, const I &id, const I &super);
    friend void hacerIndependiente<I, V>(const colecInterdep<I, V> &c, const I &id);
    friend void actualizarVal<I, V>(const colecInterdep<I, V> &c, const I &id, const V &nuevo, bool &error);
    friend void obtenerVal<I, V>(const I &id, const colecInterdep<I, V> &c, V &v, bool &error);
    friend void obtenerSupervisor<I, V>(const I &id, const colecInterdep<I, V> &c, I &sup, bool &error);
    friend void obtenerNumDependientes<I, V>(const I &id, const colecInterdep<I, V> &c, int &num, bool &error);
    friend void borrar<I, V>(const I &id, colecInterdep<I, V> &c);
    friend void iniciarIterador<I, V>(colecInterdep<I, V> &c);
    friend bool existeSiguiente<I, V>(const colecInterdep<I, V> &c);
    friend void siguienteIdent<I, V>(const colecInterdep<I, V> &c, I &id, bool &error);
    friend void siguienteVal<I, V>(const colecInterdep<I, V> &c, V &v, bool &error);
    friend void siguienteDependiente<I, V>(const colecInterdep<I, V> &c, bool &dep, bool &error);
    friend void siguienteSuperior<I, V>(const colecInterdep<I, V> &c, I &sup, bool &error);
    friend void siguienteNumDependientes<I, V>(const colecInterdep<I, V> &c, int &num, bool &error);
    friend void avanzarIterador<I, V>(colecInterdep<I, V> &c, bool &error);

    /* El TAD colecInterdep se implementa como una arbol binario de busqueda,
       en el que cada elemento es del tipo `colecInterdep::nodo` y cuyo orden se
       define en funcion del campo `ident` de cada uno de ellos.

       Un arbol vacio tiene el puntero `raiz` a `nullptr` y un tamaño `tam` igual a 0. En cualquier
         otro caso, `raiz` apunta al nodo raiz del arbol y `tam` indica el numero total de nodos que contiene.

       Para iterar el arbol externamente, se emplean las funciones de iterador definidas en la interfaz, que
         utilizan el puntero `actual` para llevar la cuenta del nodo actual en la iteracion. Si el arbol se modifica
         durante una iteracion, el comportamiento de las funciones de iterador es indefinido.*/

private:
    /* Representacion de un nodo del arbol que implementa la coleccion.

       Un nodo contiene un identificador `ident` que es unico en la coleccion y un valor `val` que es el valor
         asociado a ese identificador.

       El campo `super` define la dependencia del elemento representado por el nodo:
         - Si `super` es `nullptr`, el elemento es independiente.
         - Si `super` apunta a otro nodo de la coleccion, el elemento es dependiente y depende directamente
           del elemento representado por el nodo al que apunta `super`.

       De igual forma, el campo `numDepend` indica el numero de elementos que dependen directamente del elemento
         representado por el nodo.

       `izda` y `dcha` son punteros a los nodos hijos del arbol izquierdo y derecho, respectivamente. */
    struct nodo
    {
        /** Identificador */
        I ident;

        /** Valor del elemento. */
        V val;

        /** Elemento del que es directamente dependiente este elemento. Si el elemento es independiente, `nullptr`. */
        nodo *super = nullptr;

        /** Numero de elementos que dependen directamente de este elemento. */
        int numDepend = 0;

        /** Rama izquierda del nodo. */
        nodo *izda = nullptr;

        /** Rama derecha del nodo. */
        nodo *dcha = nullptr;
    };

    /** Numero de elementos en la coleccion.*/
    int tam = 0;

    /** Puntero a la raiz del arbol. Si la coleccion esta vacia, `nullptr`. */
    nodo *raiz = nullptr;

    /** Pila de punteros a nodos que ha recorrido el iterador desde la raiz hasta su posicion actual. */
    pila<nodo *> recorridoIterador;

    /** Puntero al nodo actual del iterador. */
    nodo *actual = nullptr;

    /** Cuantos desvíos a la izquierda hay desde la raiz hasta la posicion actual del iterador */
    int desviosIzda = 0;
};

/**
 * @brief Inicializa `c` como una coleccion vacia, sin elementos.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[out] c Coleccion a inicializar.
 *
 * Post: la coleccion `c` tiene asignados a sus campos los valores correspondientes a una coleccion vacia.
 */
template <typename I, typename V>
void crear(colecInterdep<I, V> &c)
{
    c.tam = 0;
    c.raiz = nullptr;
    c.actual = nullptr;
    crear(c.recorridoIterador);
    c.desviosIzda = 0;
}

/**
 * @brief Devuelve el numero de elementos de la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos.
 * @returns Numero de elementos de la coleccion.
 *
 * Post: Devuelve el campo `tam` de la coleccion `c`.
 */
template <typename I, typename V>
int tamanyo(const colecInterdep<I, V> &c)
{
    return c.tam;
}

/**
 * @brief Comprueba si la coleccion `c` esta vacia.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar si esta vacia.
 * @returns `true` si la coleccion esta vacia, `false` en caso contrario.
 *
 * Post: devuelve `true` si el campo `tam` de la coleccion `c` es 0, `false` en caso contrario.
 */
template <typename I, typename V>
bool esVacia(const colecInterdep<I, V> &c)
{
    return c.tam == 0;
}

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento con identificador `id`.
 * @returns `true` si existe un elemento con identificador `id` en la coleccion, `false` en caso contrario.
 *
 * Post: devuelve `true` si existe un nodo en la coleccion `c` cuyo campo `ident` es igual a `id`, `false` en caso contrario.
 */
template <typename I, typename V>
bool existe(const I &id, const colecInterdep<I, V> &c)
{
    typename colecInterdep<I, V>::nodo *nodo = c.raiz;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (nodo != nullptr && !(nodo->ident == id))
    {
        // Navega por el arbol segun corresponda hacia la izquierda o derecha en
        // busca del nodo con identificador `id`
        nodo = (id < nodo->ident) ? nodo->izda : nodo->dcha;
    }

    return nodo != nullptr;
}

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion `c` y es dependiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento dependiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento dependiente con identificador `id`.
 * @returns `true` si existe un elemento dependiente con identificador `id` en la coleccion, `false` en caso contrario.
 *
 * Post: devuelve `true` si existe un nodo en la coleccion `c` cuyo campo `ident` es igual a `id` y cuyo campo `super` no es `nullptr`,
 *       `false` en caso contrario.
 */
template <typename I, typename V>
bool existeDependiente(const I &id, const colecInterdep<I, V> &c)
{
    typename colecInterdep<I, V>::nodo *nodo = c.raiz;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (nodo != nullptr && !(nodo->ident == id))
    {
        // Navega por el arbol segun corresponda hacia la izquierda o derecha en
        // busca del nodo con identificador `id`
        nodo = (id < nodo->ident) ? nodo->izda : nodo->dcha;
    }

    if (nodo == nullptr)
    {
        // No existe un nodo con identificador `id`
        return false;
    }

    // El nodo existe, y es dependiente si su campo `super` es otro nodo (no es `nullptr`)
    return nodo->super != nullptr;
}

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion `c` y es independiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento independiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento independiente con identificador `id`.
 * @returns `true` si existe un elemento independiente con identificador `id` en la coleccion, `false` en caso contrario.
 *
 * Post: devuelve `true` si existe un nodo en la coleccion `c` cuyo campo `ident` es igual a `id` y cuyo campo `super` es `nullptr`,
 *       `false` en caso contrario.
 */
template <typename I, typename V>
bool existeIndependiente(const I &id, const colecInterdep<I, V> &c)
{
    typename colecInterdep<I, V>::nodo *nodo = c.raiz;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (nodo != nullptr && !(nodo->ident == id))
    {
        // Navega por el arbol segun corresponda hacia la izquierda o derecha en
        // busca del nodo con identificador `id`
        nodo = (id < nodo->ident) ? nodo->izda : nodo->dcha;
    }

    if (nodo == nullptr)
    {
        // No existe un nodo con identificador `id`
        return false;
    }

    // El nodo existe, y es independiente si su campo `super` es `nullptr`
    return nodo->super == nullptr;
}

/**
 * @brief Añade un elemento dependiente con identificador `id` y valor `v` a la coleccion `c`.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento dependiente.
 * @param[in] id Identificador del elemento dependiente que se quiere añadir a la coleccion.
 * @param[in] v Valor del elemento dependiente que se quiere añadir a la coleccion.
 *
 * Post: si no existe un elemento con identificador `id` en la coleccion `c`, se añade un nuevo nodo con los campos `ident` y `val`
 *       iguales a `id` y `v`, el campo `super` igual a `nullptr` y `numDepend`, 0. Este nodo se inserta como hoja en la posicion
 *       que corresponde para satisfacer la definicion de arbol binario de busqueda ordenado por identificadores.
 *       En caso contrario, no se añade nada.
 */
template <typename I, typename V>
void anyadirIndependiente(colecInterdep<I, V> &c, const I &id, const V &v)
{
    // Buscamos `nodoActual`. Si no existe, se insertara como hijo de `nodoAnterior`
    typename colecInterdep<I, V>::nodo *nodoActual = c.raiz;
    typename colecInterdep<I, V>::nodo *nodoAnterior = nullptr;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (nodoActual != nullptr && !(nodoActual->ident == id))
    {
        // Guarda una referencia al nodo padre
        nodoAnterior = nodoActual;

        // Navega por el arbol segun corresponda hacia la izquierda o derecha en
        // busca del nodo con identificador `id`
        nodoActual = (id < nodoActual->ident) ? nodoActual->izda : nodoActual->dcha;
    }

    // Si no se ha encontrado un elemento, lo añade
    if (nodoActual == nullptr)
    {
        // Nuevo nodo a añadir (hoja, sin ramas izda ni dcha)
        typename colecInterdep<I, V>::nodo *nuevoNodo = new typename colecInterdep<I, V>::nodo;
        nuevoNodo->ident = id;
        nuevoNodo->val = v;

        // Arbol vacio => añadir como raiz
        if (c.tam++ == 0)
        {
            c.raiz = nuevoNodo;
        }

        // Añadir en la rama izquierda o derecha segun corresponda
        else if (id < nodoAnterior->ident)
        {
            nodoAnterior->izda = nuevoNodo;
        }
        else
        {
            nodoAnterior->dcha = nuevoNodo;
        }
    }
}

/**
 * @brief Añade un elemento independiente con identificador `id` y valor `v` a la coleccion `c`.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion o el supervisor no exista, no se añade nada.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento independiente.
 * @param[in] id Identificador del elemento independiente que se quiere añadir a la coleccion.
 * @param[in] v Valor del elemento independiente que se quiere añadir a la coleccion.
 * @param[in] super Identificador del elemento independiente que sera el supervisor del nuevo elemento dependiente.
 *
 * Post: si no existe un elemento con identificador `id` en la coleccion `c` y existe un elemento con identificador `super`,
 *       se añade un nuevo nodo con los campos `ident` y `val` igual a `id` y `v`, el campo `super` apuntando al nodo con
 *       identificador `super` y el campo `numDepend`, 0. Este nodo se inserta como hoja en la posicion que corresponde
 *       para satisfacer la definicion de arbol binario de busqueda ordenado por identificadores.
 *       En caso contrario, no se añade nada.
 */
template <typename I, typename V>
void anyadirDependiente(colecInterdep<I, V> &c, const I &id, const V &v, const I &super)
{
    // A diferencia de `anyadirIndependiente()`, aqui no podemos un nodo a una coleccion vacia, ya que seguro que no existe el supervisor.
    // Ademas, ya que un elemento no puede depender de si mismo, `id` y `super` deben ser distintos.
    if (c.tam > 0 && !(id == super))
    {
        // Se insertara como hijo de `nodoAnterior`, y con dependencia de `nodoSuper`
        typename colecInterdep<I, V>::nodo *nodoActual = c.raiz;
        typename colecInterdep<I, V>::nodo *nodoAnterior = nullptr;
        typename colecInterdep<I, V>::nodo *nodoSuper = c.raiz;

        // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
        while (nodoActual != nullptr && !(nodoActual->ident == id))
        {
            // Guarda una referencia al nodo padre
            nodoAnterior = nodoActual;

            // Navega por el arbol segun corresponda hacia la izquierda o derecha en
            // busca del nodo con identificador `id`
            nodoActual = (id < nodoActual->ident) ? nodoActual->izda : nodoActual->dcha;
        }

        // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `super`
        while (nodoSuper != nullptr && !(nodoSuper->ident == super))
        {
            // Navega por el arbol segun corresponda hacia la izquierda o derecha en
            // busca del nodo con identificador `super`
            nodoSuper = (super < nodoSuper->ident) ? nodoSuper->izda : nodoSuper->dcha;
        }

        // Si ha encontrado el supervisor y el identificador no existe, añade el nuevo nodo
        if (nodoActual == nullptr && nodoSuper != nullptr && nodoSuper->ident == super)
        {
            // Nuevo nodo a añadir (hoja, sin ramas izda ni dcha)
            typename colecInterdep<I, V>::nodo *nuevoNodo = new typename colecInterdep<I, V>::nodo;
            nuevoNodo->ident = id;
            nuevoNodo->val = v;
            nuevoNodo->super = nodoSuper;
            nodoSuper->numDepend++;
            c.tam++;

            // Añadir en la rama izquierda o derecha segun corresponda
            if (id < nodoAnterior->ident)
            {
                nodoAnterior->izda = nuevoNodo;
            }
            else
            {
                nodoAnterior->dcha = nuevoNodo;
            }
        }
    }
}

/**
 * @brief Convierte el elemento con identificador `id` en dependiente del elemento con identificador `super`.
 * En caso de que el elemento con identificador `id` ya sea dependiente, actualiza su supervisor a `super`.
 * Si no existe alguno de los dos elementos con identificadores `id` o `super`, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en dependiente.
 * @param[in] id Identificador del elemento que se quiere convertir en dependiente.
 * @param[in] super Identificador del elemento que sera el supervisor del elemento que se quiere convertir en dependiente.
 *
 * Post: si existen los elementos con identificadores `id` y `super` en la coleccion `c`, se establece el campo `super`
 *       del nodo con identificador `id` para que apunte al nodo con identificador `super`, independientemente del estado
 *       de dependencia previo del nodo con identificador `id`, y se actualizan los contadores de dependientes de los nodos
 *       afectados. En caso contrario, no se realiza ningun cambio.
 */
template <typename I, typename V>
void hacerDependiente(const colecInterdep<I, V> &c, const I &id, const I &super)
{
    // Un elemento no puede depender de si mismo
    if (!(id == super))
    {
        // Se busca el nodo `dep`, que dependera de `sup`
        typename colecInterdep<I, V>::nodo *dep = c.raiz;
        typename colecInterdep<I, V>::nodo *sup = c.raiz;

        // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
        while (dep != nullptr && !(dep->ident == id))
        {
            // Navega por el arbol segun corresponda hacia la izquierda o derecha
            // en busca del nodo con identificador `id`
            dep = (id < dep->ident) ? dep->izda : dep->dcha;
        }

        // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `super`
        while (sup != nullptr && !(sup->ident == super))
        {
            // Navega por el arbol segun corresponda hacia la izquierda o derecha
            // en busca del nodo con identificador `super`
            sup = (super < sup->ident) ? sup->izda : sup->dcha;
        }

        // Si ha encontrado ambos nodos, actualiza los campos correspondientes
        if (dep != nullptr && sup != nullptr)
        {
            // Si `dep` ya era dependiente, se decrementa el contador de su antiguo supervisor
            if (dep->super != nullptr)
            {
                dep->super->numDepend--;
            }

            dep->super = sup;
            sup->numDepend++;
        }
    }
}

/**
 * @brief Convierte el elemento con identificador `id` en independiente.
 * En caso de que el elemento con identificador `id` ya sea independiente, no se realiza ningun cambio.
 * Si el elemento con identificador `id` no existe, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en independiente.
 * @param[in] id Identificador del elemento que se quiere convertir en independiente.
 *
 * Post: si existe el elemento con identificador `id` en la coleccion `c`, a dicha elemento se le asigna
 *       el valor `nullptr` en su campo `super`, convirtiendolo en independiente, y se decrementa el contador
 *       de dependientes del antiguo supervisor si existe. En caso contrario, no se realiza ningun cambio.
 */
template <typename I, typename V>
void hacerIndependiente(const colecInterdep<I, V> &c, const I &id)
{
    // Se busca el nodo `dep`, que sera convertido en independiente
    typename colecInterdep<I, V>::nodo *dep = c.raiz;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (dep != nullptr && !(dep->ident == id))
    {
        // Navega por el arbol segun corresponda hacia la izquierda o derecha
        // en busca del nodo con identificador `id`
        dep = (id < dep->ident) ? dep->izda : dep->dcha;
    }

    // Si ha encontrado el nodo, actualiza los campos correspondientes
    if (dep != nullptr)
    {
        // Si `dep` era dependiente, se decrementa el contador de su antiguo supervisor
        if (dep->super != nullptr)
        {
            dep->super->numDepend--;
        }

        dep->super = nullptr;
    }
}

/**
 * @brief Actualiza el valor del elemento con identificador `id` en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere actualizar.
 * @param[in] id Identificador del elemento que se quiere actualizar.
 * @param[in] nuevo Nuevo valor que se quiere asignar al elemento.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 *
 * Post: si existe el elemento con identificador `id` en la coleccion `c`, su campo `val` se actualiza con el
 *       valor `nuevo` y error=false. en caso contrario, error=true (operación parcial).
 */
template <typename I, typename V>
void actualizarVal(const colecInterdep<I, V> &c, const I &id, const V &nuevo, bool &error)
{
    error = true;
    typename colecInterdep<I, V>::nodo *nodo = c.raiz;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (nodo != nullptr && !(nodo->ident == id))
    {
        // Navega por el arbol segun corresponda hacia la izquierda o derecha
        // en busca del nodo con identificador `id`
        nodo = (id < nodo->ident) ? nodo->izda : nodo->dcha;
    }

    // Si ha encontrado el nodo, actualiza los campos correspondientes
    if (nodo != nullptr)
    {
        nodo->val = nuevo;
        error = false;
    }
}

/**
 * @brief Obtiene el valor del elemento con identificador `id` de la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento del que se quiere obtener el valor.
 * @param[in] c Coleccion de la que se quiere obtener el valor del elemento con identificador `id`.
 * @param[out] v Valor del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 *
 * Post: si existe el elemento con identificador `id` en la coleccion `c`, se le asigna a `v` el campo `val`
 *       de dicho elemento y error=false. En caso contrario, error=true (operación parcial).
 */
template <typename I, typename V>
void obtenerVal(const I &id, const colecInterdep<I, V> &c, V &v, bool &error)
{
    error = true;
    typename colecInterdep<I, V>::nodo *nodo = c.raiz;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (nodo != nullptr && !(nodo->ident == id))
    {
        // Navega por el arbol segun corresponda hacia la izquierda o derecha
        // en busca del nodo con identificador `id`
        nodo = (id < nodo->ident) ? nodo->izda : nodo->dcha;
    }

    // Si ha encontrado el nodo, obtiene su valor
    if (nodo != nullptr)
    {
        v = nodo->val;
        error = false;
    }
}

/**
 * @brief Obtiene el identificador del supervisor del elemento con identificador `id` de la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento del que se quiere obtener el identificador de su supervisor.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del elemento con identificador `id`.
 * @param[out] sup Identificador del supervisor del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado o elemento independiente).
 *
 * Post: si existe el elemento con identificador `id` en la coleccion `c` y es dependiente, se le asigna a `sup`
 *       el identificador de su supervisor y error=false. En caso contrario, error=true (operación parcial).
 */
template <typename I, typename V>
void obtenerSupervisor(const I &id, const colecInterdep<I, V> &c, I &sup, bool &error)
{
    error = true;
    typename colecInterdep<I, V>::nodo *nodo = c.raiz;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (nodo != nullptr && !(nodo->ident == id))
    {
        // Navega por el arbol segun corresponda hacia la izquierda o derecha
        // en busca del nodo con identificador `id`
        nodo = (id < nodo->ident) ? nodo->izda : nodo->dcha;
    }

    // Si ha encontrado el nodo, obtiene su supervisor
    if (nodo != nullptr && nodo->super != nullptr)
    {
        sup = nodo->super->ident;
        error = false;
    }
}

/**
 * @brief Obtiene el numero de elementos dependientes del elemento con identificador `id` de la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento del que se quiere obtener el numero de elementos dependientes.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del elemento con identificador `id`.
 * @param[out] num Numero de elementos dependientes del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 *
 * Post: si existe el elemento con identificador `id` en la coleccion `c`, se le asigna a `num` el campo `numDepend`
 *       de dicho elemento y error=false. En caso contrario, error=true (operación parcial).
 */
template <typename I, typename V>
void obtenerNumDependientes(const I &id, const colecInterdep<I, V> &c, int &num, bool &error)
{
    error = true;
    typename colecInterdep<I, V>::nodo *nodo = c.raiz;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (nodo != nullptr && !(nodo->ident == id))
    {
        // Navega por el arbol segun corresponda hacia la izquierda o derecha
        // en busca del nodo con identificador `id`
        nodo = (id < nodo->ident) ? nodo->izda : nodo->dcha;
    }

    // Si ha encontrado el nodo, obtiene su numero de dependientes
    if (nodo != nullptr)
    {
        num = nodo->numDepend;
        error = false;
    }
}

/**
 * @brief Elimina el elemento con identificador `id` de la coleccion `c`.
 * En caso de que el elemento con identificador `id` no exista en la coleccion, no se realiza ningun cambio.
 * Solo se puede eliminar un elemento si no tiene elementos que dependan de él.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] id Identificador del elemento que se quiere eliminar de la coleccion.
 * @param[in, out] c Coleccion de la que se quiere eliminar el elemento con identificador `id`.
 *
 * Post: si existe el elemento con identificador `id` en la coleccion `c` y no tiene elementos que dependan de él:
 *       - se elimina dicho elemento del arbol, manteniendo la propiedad de arbol binario de busqueda. (el elemento
 *         eliminado se reemplaza por el de menor valor en su subrama derecha).
 *       - se decrementa el contador de dependientes del supervisor si existe.
 *       - se decrementa el tamaño de la coleccion.
 *       - se libera la memoria ocupada por el nodo eliminado.
 *       En caso contrario, no se realiza ningun cambio.
 */
template <typename I, typename V>
void borrar(const I &id, colecInterdep<I, V> &c)
{
    // Se borrara `nodoActual`, que es hijo de `nodoAnterior`
    typename colecInterdep<I, V>::nodo *nodoActual = c.raiz;
    typename colecInterdep<I, V>::nodo *nodoAnterior = nullptr;

    // Realiza una busqueda binaria en el arbol para encontrar el nodo con identificador `id`
    while (nodoActual != nullptr && !(nodoActual->ident == id))
    {
        // Guarda una referencia al nodo padre
        nodoAnterior = nodoActual;

        // Navega por el arbol segun corresponda hacia la izquierda o derecha en
        // busca del nodo con identificador `id`
        nodoActual = (id < nodoActual->ident) ? nodoActual->izda : nodoActual->dcha;
    }

    // Si no encuentra el identificador o tiene elementos que dependen de él, no se realiza ningun cambio
    if (!(nodoActual == nullptr) && nodoActual->numDepend == 0)
    {
        // Nodo de reemplazo que sustituira al nodo a borrar, dependiendo de los casos posibles,
        // lo hara de una forma u otra
        typename colecInterdep<I, V>::nodo *reemplazo;

        // Caso 1: el nodo a borrar es una hoja. Simplemente se elimina
        if (nodoActual->izda == nullptr && nodoActual->dcha == nullptr)
        {
            reemplazo = nullptr; // No hay nodo de reemplazo
        }

        // Caso 2: el nodo a borrar tiene una sola rama (izda o dcha). Se conecta la rama del nodo a borrar
        // con el padre del nodo a borrar
        else if (nodoActual->izda == nullptr || nodoActual->dcha == nullptr)
        {
            // Se reemplazara por la rama nula
            reemplazo = (nodoActual->izda != nullptr) ? nodoActual->izda : nodoActual->dcha;
        }

        // Caso 3: el nodo a borrar tiene dos ramas. Se busca el nodo de menor valor en la subrama derecha.
        else
        {
            // Se reemplazara el nodo a borrar por `reemplazo`, que es el de menor valor en la subrama derecha
            typename colecInterdep<I, V>::nodo *reemplazoAnterior = nodoActual;
            reemplazo = reemplazoAnterior->dcha;

            // Una vez en el subarbol derecho, se navega por la rama izquierda hasta encontrar el nodo de menor valor
            while (reemplazo->izda != nullptr)
            {
                reemplazoAnterior = reemplazo;
                reemplazo = reemplazo->izda;
            }

            // Enazar la rama izquierda del nodo padre del reemplazo con la rama derecha del reemplazo, como en el caso 2.
            reemplazoAnterior->izda = reemplazo->dcha;

            // Copiar las ramas del nodo a borrar al nodo de reemplazo
            reemplazo->izda = nodoActual->izda;
            reemplazo->dcha = nodoActual->dcha;
        }
        
        // Conectar el nodo de reemplazo con el padre del nodo a borrar
        // El elemento a borrar era la raiz
        if (nodoAnterior == nullptr)
        {
            c.raiz = reemplazo;
        }

        // El elemento a borrar era hijo de otro nodo
        else if (nodoAnterior->izda == nodoActual)
        {
            nodoAnterior->izda = reemplazo;
        }
        else
        {
            nodoAnterior->dcha = reemplazo;
        }

        // Actualizar el contador de dependientes del supervisor si existe
        if (nodoActual->super != nullptr)
        {
            nodoActual->super->numDepend--;
        }

        // Liberar la memoria ocupada por el nodo eliminado y decrementar el tamaño de la coleccion
        delete nodoActual;
        c.tam--;
    }
}
#include <type_traits>
#include <string>
/**
 * @brief Inicializa el iterador de la coleccion `c` para recorrer sus elementos de menor a mayor identificador
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion cuyo iterador se quiere inicializar.
 *
 * Post: se inicializa el iterador de la coleccion `c`, inicializando la pila `c.recorridoIterador` y se recorre la rama izquierda
 *       en busca del nodo de menor identificador, apilando los nodos recorridos. El puntero `c.actual` apunta al nodo de menor
 *       identificador encontrado (o a `nullptr` si la coleccion esta vacia).
 */
template <typename I, typename V>
void iniciarIterador(colecInterdep<I, V> &c)
{
    // Coloca inicialmente el puntero `actual` en la raiz.
    c.actual = c.raiz;
    c.desviosIzda = 0;
    crear(c.recorridoIterador);

    // Recorre la rama izquierda desde la raiz hasta el nodo de menor id, apilando los nodos encontrados
    while (c.actual != nullptr && c.actual->izda != nullptr)
    {
        push(c.recorridoIterador, c.actual);
        c.actual = c.actual->izda;
        c.desviosIzda++;
    }
}

/**
 * @brief Comprueba queda algún elemento por visitar en la colección `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar.
 * @returns `true` si existe un siguiente elemento, `false` en caso contrario.
 *
 * Post: devuelve `true` si el `c.actual` no es `nullptr`, `false` en caso contrario.
 */
template <typename I, typename V>
bool existeSiguiente(const colecInterdep<I, V> &c)
{
    return c.actual != nullptr;
}

/**
 * @brief Obtiene el identificador del siguiente elemento a visitar en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del siguiente elemento.
 * @param[out] id Identificador del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * Post: si `existeSiguiente(c)`, se le asigna a `id` el campo `ident` del nodo apuntado por `c.actual` y error=false.
 *       En caso contrario, error=true (operación parcial)
 */
template <typename I, typename V>
void siguienteIdent(const colecInterdep<I, V> &c, I &id, bool &error)
{
    error = !existeSiguiente(c);
    if (!error)
    {
        id = c.actual->ident;
    }
}

/**
 * @brief Obtiene el valor del siguiente elemento a visitar en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el valor del siguiente elemento.
 * @param[out] v Valor del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * Post: si `existeSiguiente(c)`, se le asigna a `v` el campo `val` del nodo apuntado por `c.actual` y error=false.
 *       En caso contrario, error=true (operación parcial).
 */
template <typename I, typename V>
void siguienteVal(const colecInterdep<I, V> &c, V &v, bool &error)
{
    error = !existeSiguiente(c);
    if (!error)
    {
        v = c.actual->val;
    }
}

/**
 * @brief Indica si el siguiente elemento a visitar en la coleccion `c` es dependiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere comprobar si el siguiente elemento es dependiente.
 * @param[out] dep Si el siguiente elemento a visitar es dependiente. `true` si es dependiente, `false` si es independiente.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * Post: si `existeSiguiente(c)`, se le asigna a `dep` el resultado de comprobar si el campo `super` del nodo apuntado por `c.actual`
 *       es distinto de `nullptr` y error=false. En caso contrario, error=true (operación parcial).
 */
template <typename I, typename V>
void siguienteDependiente(const colecInterdep<I, V> &c, bool &dep, bool &error)
{
    error = !existeSiguiente(c);
    if (!error)
    {
        dep = c.actual->super != nullptr;
    }
}

/**
 * @brief Obtiene el supervisor del siguiente elemento a visitar en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del siguiente elemento.
 * @param[out] sup Identificador del supervisor del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar o el elemento es independiente).
 *
 * Post: si `siguienteDependiente(c)`, se le asigna a `sup` el campo `ident` del supervisor del nodo apuntado por `c.actual` y error=false.
 *       En caso contrario, error=true (operación parcial).
 */
template <typename I, typename V>
void siguienteSuperior(const colecInterdep<I, V> &c, I &id, bool &error)
{
    error = !existeSiguiente(c) || c.actual->super == nullptr;
    if (!error)
    {
        id = c.actual->super->ident;
    }
}

/**
 * @brief Obtiene el numero de elementos que dependen del siguiente elemento a visitar en la coleccion `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del siguiente elemento.
 * @param[out] num Numero de elementos dependientes del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * Post: si `existeSiguiente(c)`, se le asigna a `num` el campo `numDepend` del nodo apuntado por `c.actual` y error=false.
 *       En caso contrario, error=true (operación parcial).
 */
template <typename I, typename V>
void siguienteNumDependientes(const colecInterdep<I, V> &c, int &num, bool &error)
{
    error = !existeSiguiente(c);
    if (!error)
    {
        num = c.actual->numDepend;
    }
}

/**
 * @brief Avanza el iterador de la coleccion `c` al siguiente elemento.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion
 * @param[in, out] c Coleccion cuyo iterador se quiere avanzar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * Post: si `existeSiguiente(c)`, el campo `c.actual` se actualiza con el valor del siguiente nodo (c.actual->sig)
 *       y error=false. En caso contrario, error=true (operación parcial)
 */
template <typename I, typename V>
void avanzarIterador(colecInterdep<I, V> &c, bool &error)
{

    error = !existeSiguiente(c);
    if (!error)
    {
        // Seguir bajando por la rama derecha si existe
        if (c.actual->dcha != nullptr)
        {
            // Baja un nivel por la rama derecha
            push(c.recorridoIterador, c.actual);
            c.actual = c.actual->dcha;

            // Si hay rama izquierda, bajar por ella hasta el nodo de menor id
            while (c.actual != nullptr && c.actual->izda != nullptr)
            {
                push(c.recorridoIterador, c.actual);
                c.actual = c.actual->izda;
                c.desviosIzda++;
            }
        }

        // Si no existe rama derecha y no hay mas nodos por visitar por la derecha, finalizamos
        else if (c.desviosIzda == 0)
        {
            // No hay mas nodos por visitar
            c.actual = nullptr;
        }

        // Si no existe rama derecha, retroceder por la pila hasta encontrar un nodo con rama derecha no visitada
        // No comprobamos la rama izquierda, ya que si la hubiera, habriamos bajado por ella antes
        else
        {
            bool e;

            // Obtener el padre del nodo actual
            typename colecInterdep<I, V>::nodo *padre;
            pop(c.recorridoIterador, padre, e);

            // Mientras venimos por la derecha, seguir subiendo
            while (padre->dcha == c.actual)
            {
                c.actual = padre;
                pop(c.recorridoIterador, padre, e);
            }

            // El ultimo salto hacia arriba ha sido por la rama izquierda de `padre`,
            // Su valor es mayor a todo lo que hemos visitado hasta ahora
            c.actual = padre;
            c.desviosIzda--;
        }
    }
}

// FIN DECLARACION DEL TAD GENERICO coleccionInterdep (fin IMPLEMENTACION)

#endif // COLECINTERDEP_HPP