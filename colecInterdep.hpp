/**
 * @file colecInterdep.hpp
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 */

#ifndef COLECINTERDEP_HPP
#define COLECINTERDEP_HPP

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

    /* El TAD colecInterdep se implementa como una lista enlazada ordenada simple
       en la que cada elemento es del tipo `colecInterdep::nodo` y cuyo orden se
       define en funcion del campo `ident` de cada uno de ellos.

       Una lista vacia tiene el puntero `primero` a `nullptr` y un tamaño `tam` igual a 0. En cualquier
         otro caso, `primero` apunta al primer nodo de la lista y `tam` indica el numero total de nodos que contiene.

       Para iterar la lista externamente, se emplean las funciones de iterador definidas en la interfaz, que
         utilizan el puntero `actual` para llevar la cuenta del nodo actual en la iteracion. Si la lista se modifica
         durante una iteracion, el comportamiento de las funciones de iterador es indefinido.*/

private:
    /* Representacion de un nodo de la lista enlazada que implementa la coleccion.

       Un nodo contiene un identificador `ident` que es unico en la coleccion y un valor `val` que es el valor
         asociado a ese identificador.

       El campo `super` define la dependencia del elemento representado por el nodo:
         - Si `super` es `nullptr`, el elemento es independiente.
         - Si `super` apunta a otro nodo de la coleccion, el elemento es dependiente y depende directamente
           del elemento representado por el nodo al que apunta `super`.

       De igual forma, el campo `numDepend` indica el numero de elementos que dependen directamente del elemento
         representado por el nodo.

       `sig` es un puntero al siguiente nodo en la lista enlazada. */
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

        /** Puntero al siguiente nodo en la coleccion. */
        nodo *sig = nullptr;
    };

    /** Numero de elementos en la coleccion.*/
    int tam = 0;

    /** Puntero al primer nodo de la coleccion. Si la coleccion esta vacia, `nullptr`. */
    nodo *primero = nullptr;

    /** Nodo actual del iterador. */
    nodo *actual = nullptr;
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
    c.primero = nullptr;
    c.actual = nullptr;
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
    bool encontrado = false;

    // Itera la coleccion desde el primer nodo hasta la posicion donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && (nodo->ident < id || nodo->ident == id);
         nodo = nodo->sig)
    {
        if (nodo->ident == id)
        {
            encontrado = true;
        }
    }

    return encontrado;
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
    bool esDep = false;

    // Itera la coleccion desde el primer nodo hasta la posicion donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && (nodo->ident < id || nodo->ident == id);
         nodo = nodo->sig)
    {
        if (nodo->ident == id)
        {
            // No existen identificadores repetidos, por lo que el resultado depende de si este nodo es dependiente o no
            esDep = nodo->super != nullptr;
        }
    }

    return esDep;
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
    bool esInd = false;

    // Itera la coleccion desde el primer nodo hasta la posicion donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && (nodo->ident < id || nodo->ident == id);
         nodo = nodo->sig)
    {
        if (nodo->ident == id)
        {
            // No existen identificadores repetidos, por lo que el resultado depende de si este nodo es dependiente o no
            esInd = nodo->super == nullptr;
        }
    }

    return esInd;
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
 *       iguales a `id` y `v`, el campo `super` igual a `nullptr` y `numDepend`, 0. Este nodo se inserta en la posicion
 *       que mantiene el orden creciente de los identificadores en la coleccion. En caso contrario, no se añade nada.
 */
template <typename I, typename V>
void anyadirIndependiente(colecInterdep<I, V> &c, const I &id, const V &v)
{
    // Se insertara justo antes del `nodoActual`, y despues del `nodoAnterior`
    typename colecInterdep<I, V>::nodo *nodoActual = c.primero;
    typename colecInterdep<I, V>::nodo *nodoAnterior = nullptr;

    // Itera la coleccion para encontrar la posicion donde insertar el nuevo nodo
    while (nodoActual != nullptr && nodoActual->ident < id)
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sig;
    }

    // Añadir al principio
    if (nodoAnterior == nullptr)
    {
        typename colecInterdep<I, V>::nodo *nuevoNodo = new typename colecInterdep<I, V>::nodo;
        nuevoNodo->ident = id;
        nuevoNodo->val = v;
        nuevoNodo->sig = c.primero;
        c.primero = nuevoNodo;
        c.tam++;
    }

    // Añadir en medio o al final
    else if (nodoActual == nullptr || !(nodoActual->ident == id))
    {
        typename colecInterdep<I, V>::nodo *nuevoNodo = new typename colecInterdep<I, V>::nodo;
        nuevoNodo->ident = id;
        nuevoNodo->val = v;
        nuevoNodo->sig = nodoActual;
        nodoAnterior->sig = nuevoNodo;
        c.tam++;
    }

    // Si el identificador ya existe, no se añade nada
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
 *       identificador `super` y el campo `numDepend`, 0. Este nodo se inserta en la posicion que mantiene el orden 
 *       creciente de los identificadores en la coleccion. En caso contrario, no se añade nada.
 */
template <typename I, typename V>
void anyadirDependiente(colecInterdep<I, V> &c, const I &id, const V &v, const I &super)
{
    // A diferencia de `anyadirIndependiente()`, aqui no podemos un nodo a una coleccion vacia, ya que seguro que no existe el supervisor.
    // Ademas, ya que un elemento no puede depender de si mismo, `id` y `super` deben ser distintos.
    if (c.tam > 0 && !(id == super))
    {
        // Se insertara justo antes del `nodoActual`, y despues del `nodoAnterior`, con dependencia del `nodoSuper`
        typename colecInterdep<I, V>::nodo *nodoActual = c.primero;
        typename colecInterdep<I, V>::nodo *nodoAnterior = nullptr;
        typename colecInterdep<I, V>::nodo *nodoSuper = nullptr;

        // Itera la coleccion para encontrar la posicion donde insertar el nuevo nodo
        while (nodoActual != nullptr && nodoActual->ident < id)
        {
            // Busca el supervisor mientras itera
            if (nodoActual->ident == super)
            {
                nodoSuper = nodoActual;
            }
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->sig;
        }

        // Si aun no se ha encontrado el supervisor, sigue buscando desde el punto
        // donde se ha quedado, manteniendo un coste O(n), pero sin avanzar `nodoActual`
        if (nodoSuper == nullptr)
        {
            nodoSuper = nodoActual;
            while (nodoSuper != nullptr && !(nodoSuper->ident == super))
            {
                nodoSuper = nodoSuper->sig;
            }
        }

        // Debe haber encontrado el supervisor para poder añadir el nuevo nodo
        if (nodoSuper != nullptr)
        {
            // Añadir al principio
            if (nodoAnterior == nullptr)
            {
                typename colecInterdep<I, V>::nodo *nuevoNodo = new typename colecInterdep<I, V>::nodo;
                nuevoNodo->ident = id;
                nuevoNodo->val = v;
                nuevoNodo->sig = nodoActual;
                nuevoNodo->super = nodoSuper;
                c.primero = nuevoNodo;
                nodoSuper->numDepend++;
                c.tam++;
            }

            // Añadir en medio o al final
            else if (nodoActual == nullptr || !(nodoActual->ident == id))
            {
                typename colecInterdep<I, V>::nodo *nuevoNodo = new typename colecInterdep<I, V>::nodo;
                nuevoNodo->ident = id;
                nuevoNodo->val = v;
                nuevoNodo->sig = nodoActual;
                nuevoNodo->super = nodoSuper;
                nodoAnterior->sig = nuevoNodo;
                nodoSuper->numDepend++;
                c.tam++;
            }
        }

        // Si el identificador ya existe o no se ha encontrado el supervisor, no se añade nada
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
        typename colecInterdep<I, V>::nodo *dep = c.primero;
        typename colecInterdep<I, V>::nodo *sup = nullptr;

        // Itera la coleccion usando `dep` como iterador, pero buscando `sup` al mismo tiempo
        while (dep != nullptr && dep->ident < id)
        {
            // Busca el supervisor mientras itera
            if (dep->ident == super)
            {
                sup = dep;
            }
            dep = dep->sig;
        }

        // Si aun no se ha encontrado el supervisor, sigue buscando desde el punto
        // donde se ha quedado, manteniendo un coste O(n), pero sin avanzar `dep`
        if (sup == nullptr)
        {
            sup = dep;
            while (sup != nullptr && !(sup->ident == super))
            {
                sup = sup->sig;
            }
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
    // Itera la coleccion hasta el punto donde deberia estar el elemento con identificador `id`
    for (
        typename colecInterdep<I, V>::nodo *nodo = c.primero;
        nodo != nullptr && (nodo->ident < id || nodo->ident == id);
        nodo = nodo->sig)
    {
        // Si encuentra el identificador, lo hace independiente (si no lo era antes)
        if (nodo->ident == id)
        {
            if (nodo->super != nullptr)
            {
                nodo->super->numDepend--;
            }
            nodo->super = nullptr;
        }
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

    // Itera la coleccion hasta el punto donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && (nodo->ident < id || nodo->ident == id);
         nodo = nodo->sig)
    {
        // Si encuentra el identificador, actualiza su valor
        if (nodo->ident == id)
        {
            nodo->val = nuevo;
            error = false;
        }
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

    // Itera la coleccion hasta el punto donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && (nodo->ident < id || nodo->ident == id);
         nodo = nodo->sig)
    {
        // Si encuentra el identificador, guarda su valor
        if (nodo->ident == id)
        {
            v = nodo->val;
            error = false;
        }
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

    // Itera la coleccion hasta el punto donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && (nodo->ident < id || nodo->ident == id);
         nodo = nodo->sig)
    {
        // Si encuentra el identificador, comprueba si es dependiente y guarda su supervisor
        // Solo se puede obtener el supervisor si el nodo es dependiente
        if (nodo->ident == id && nodo->super != nullptr)
        {
            sup = nodo->super->ident;
            error = false;
        }
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

    // Busca el nodo con identificador `id` y devuelve su numero de dependientes
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && (nodo->ident < id || nodo->ident == id);
         nodo = nodo->sig)
    {
        // Si encuentra el identificador, guarda su numero de dependientes
        if (nodo->ident == id)
        {
            num = nodo->numDepend;
            error = false;
        }
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
 *       - se elimina dicho elemento de la lista enlazada, actualizando los punteros correspondientes.
 *       - se decrementa el contador de dependientes del supervisor si existe.
 *       - se decrementa el tamaño de la coleccion.
 *       - se libera la memoria ocupada por el nodo eliminado.
 *       En caso contrario, no se realiza ningun cambio.
 */
template <typename I, typename V>
void borrar(const I &id, colecInterdep<I, V> &c)
{
    // Se borrara el nodoActual, que esta despues del nodoAnterior
    typename colecInterdep<I, V>::nodo *nodoActual = c.primero;
    typename colecInterdep<I, V>::nodo *nodoAnterior = nullptr;

    // Itera la coleccion en busca del nodo con identificador `id`
    while (nodoActual != nullptr && nodoActual->ident < id)
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sig;
    }

    // Si no encuentra el identificador o tiene elementos que dependen de él, no se realiza ningun cambio
    if (nodoActual != nullptr && nodoActual->ident == id && nodoActual->numDepend == 0)
    {
        // Si el nodo a borrar es dependiente, actualiza el numero de dependientes del supervisor
        if (nodoActual->super != nullptr)
        {
            nodoActual->super->numDepend--;
        }

        // Se actualizan los punteros de la lista enlazada
        if (nodoAnterior == nullptr)
        {
            c.primero = nodoActual->sig;
        }
        else
        {
            nodoAnterior->sig = nodoActual->sig;
        }

        // Se libera la memoria del nodo y se decrementa el tamaño de la coleccion
        delete nodoActual;
        c.tam--;
    }
}

/**
 * @brief Inicializa el iterador de la coleccion `c` para recorrer sus elementos de menor a mayor identificador
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion cuyo iterador se quiere inicializar.
 *
 * Post: se inicializa el iterador de la coleccion `c`, apuntando `c.actual` al primer elemento de la coleccion.
 */
template <typename I, typename V>
void iniciarIterador(colecInterdep<I, V> &c)
{
    c.actual = c.primero;
}

/**
 * @brief Comprueba queda algún elemento por visitar en la colección `c`.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar.
 * @returns `true` si existe un siguiente elemento, `false` en caso contrario.
 *
 * Post: devuelve `true` si el campo `actual` de la coleccion `c` no es `nullptr`, `false` en caso contrario.
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
 * Post: si `existeSiguiente(c)`, se le asigna a `id` el campo `ident` de `c.actual` y error=false.
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
 * Post: si `existeSiguiente(c)`, se le asigna a `v` el campo `val` de `c.actual` y error=false.
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
 * Post: si `existeSiguiente(c)`, se le asigna a `dep` el resultado de comprobar si el campo `super`
 *       de `c.actual` es distinto de `nullptr` y error=false. En caso contrario, error=true (operación parcial).
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
 * Post: si `siguienteDependiente(c)`, se le asigna a `sup` el campo `ident` del supervisor de `c.actual` (`c.actual->super`)
 *       y error=false. En caso contrario, error=true (operación parcial).
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
 * Post: si `existeSiguiente(c)`, se le asigna a `num` el campo `numDepend` de `c.actual` y error=false.
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
        c.actual = c.actual->sig;
    }
}

// FIN DECLARACION DEL TAD GENERICO coleccionInterdep (fin IMPLEMENTACION)

#endif // COLECINTERDEP_HPP