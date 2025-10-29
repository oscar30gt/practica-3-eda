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
 * @struct colecInterdep
 * @brief Representa una colección de elementos, cada uno definido como una tupla con la forma:
 *        - (ident, val, -, NumDepend) para elementos independientes.
 *        - (ident, val, identSup, NumDepend) para elementos dependientes.
 *
 * Los elementos independientes son aquellos con la forma (ident, val, -, NumDepend), mientras que
 * los elementos dependientes tienen la forma (ident, val, identSup, NumDepend). No pueden existir
 * dos elementos en la colección con el mismo identificador `ident`.
 *
 * Para los elementos dependientes, el campo `identSup` representa el identificador del elemento del
 * que dependen directamente. Ningún elemento en la colección puede depender directamente de sí mismo,
 * y cada elemento dependiente debe depender de otro elemento existente en la colección (que puede ser
 * independiente o dependiente).
 *
 * El campo `NumDepend` en la tupla de cada elemento representa el número total de elementos en la colección
 * que dependen directamente del elemento con el identificador dado (`ident`). Si no hay elementos que dependan
 * de él, `NumDepend` será 0.
 */
template <typename I, typename V>
struct colecInterdep;

/**
 * @brief Inicializa una coleccion vacia, sin elementos.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[out] c Coleccion a inicializar.
 */
template <typename I, typename V>
void crear(colecInterdep<I, V> &c);

/**
 * @brief Devuelve el numero de elementos de la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos.
 * @returns Numero de elementos de la coleccion.
 */
template <typename I, typename V>
int tamanyo(const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si la coleccion esta vacia.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar si esta vacia.
 * @returns `true` si la coleccion esta vacia, `false` en caso contrario.
 */
template <typename I, typename V>
bool esVacia(const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento con identificador `id`.
 * @returns `true` si existe un elemento con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename I, typename V>
bool existe(const I id, const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion y es dependiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento dependiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento dependiente con identificador `id`.
 * @returns `true` si existe un elemento dependiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename I, typename V>
bool existeDependiente(const I id, const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion y es independiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento independiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento independiente con identificador `id`.
 * @returns `true` si existe un elemento independiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename I, typename V>
bool existeIndependiente(const I id, const colecInterdep<I, V> &c);

/**
 * @brief Añade un elemento dependiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento dependiente.
 * @param id Identificador del elemento dependiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento dependiente que se quiere añadir a la coleccion.
 */
template <typename I, typename V>
void anyadirIndependiente(colecInterdep<I, V> &c, const I id, const V v);

/**
 * @brief Añade un elemento independiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento independiente.
 * @param id Identificador del elemento independiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento independiente que se quiere añadir a la coleccion.
 * @param super Identificador del elemento independiente que sera el supervisor del nuevo elemento dependiente.
 */
template <typename I, typename V>
void anyadirDependiente(colecInterdep<I, V> &c, const I id, const V v, const I super);

/**
 * @brief Convierte el elemento con identificador `id` en dependiente del elemento con identificador `super`.
 * En caso de que el elemento con identificador `id` ya sea dependiente, actualiza su supervisor a `super`.
 * Si no existe alguno de los dos elementos con identificadores `id` o `super`, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en dependiente.
 * @param id Identificador del elemento que se quiere convertir en dependiente.
 * @param super Identificador del elemento que sera el supervisor del elemento que se quiere convertir en dependiente.
 */
template <typename I, typename V>
void hacerDependiente(const colecInterdep<I, V> &c, I id, I super);

/**
 * @brief Convierte el elemento con identificador `id` en independiente.
 * En caso de que el elemento con identificador `id` ya sea independiente, no se realiza ningun cambio.
 * Si el elemento con identificador `id` no existe, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en independiente.
 * @param id Identificador del elemento que se quiere convertir en independiente.
 */
template <typename I, typename V>
void hacerIndependiente(const colecInterdep<I, V> &c, I id);

/**
 * @brief Actualiza el valor del elemento con identificador `id` en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere actualizar.
 * @param id Identificador del elemento que se quiere actualizar.
 * @param nuevo Nuevo valor que se quiere asignar al elemento.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename I, typename V>
void actualizarVal(const colecInterdep<I, V> &c, I id, V nuevo, bool &error);

/**
 * @brief Obtiene el valor del elemento con identificador `id` de la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el valor.
 * @param[in] c Coleccion de la que se quiere obtener el valor del elemento con identificador `id`.
 * @param[out] v Valor del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename I, typename V>
void obtenerVal(const I id, const colecInterdep<I, V> &c, V &v, bool &error);

/**
 * @brief Obtiene el identificador del supervisor del elemento con identificador `id` de la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el identificador de su supervisor.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del elemento con identificador `id`.
 * @param[out] sup Identificador del supervisor del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado o elemento independiente).
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion o el elemento no es dependiente, el comportamiento es indefinido.
 */
template <typename I, typename V>
void obtenerSupervisor(const I id, const colecInterdep<I, V> &c, I &sup, bool &error);

/**
 * @brief Obtiene el numero de elementos dependientes del elemento con identificador `id` de la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el numero de elementos dependientes.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del elemento con identificador `id`.
 * @param[out] num Numero de elementos dependientes del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename I, typename V>
void obtenerNumDependientes(const I id, const colecInterdep<I, V> &c, int &num, bool &error);

/**
 * @brief Elimina el elemento con identificador `id` de la coleccion.
 * En caso de que el elemento con identificador `id` no exista en la coleccion, no se realiza ningun cambio.
 * Solo se puede eliminar un elemento si no tiene elementos que dependan de él.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere eliminar de la coleccion.
 * @param[in, out] c Coleccion de la que se quiere eliminar el elemento con identificador `id`.
 */
template <typename I, typename V>
void borrar(const I id, colecInterdep<I, V> &c);

/**
 * @brief Inicializa el iterador de la coleccion para recorrer sus elementos de menor a mayor identificador
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion cuyo iterador se quiere inicializar.
 */
template <typename I, typename V>
void iniciarIterador(colecInterdep<I, V> &c);

/**
 * @brief Comprueba queda algún elemento por visitar con el iterador de la colección.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar.
 * @returns `true` si existe un siguiente elemento, `false` en caso contrario.
 */
template <typename I, typename V>
bool existeSiguiente(const colecInterdep<I, V> &c);

/**
 * @brief Obtiene el identificador del siguiente elemento a visitar en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del siguiente elemento.
 * @param[out] id Identificador del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`).
 */
template <typename I, typename V>
void siguienteIdent(const colecInterdep<I, V> &c, I &id, bool &error);

/**
 * @brief Obtiene el valor del siguiente elemento a visitar en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el valor del siguiente elemento.
 * @param[out] v Valor del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`).
 */
template <typename I, typename V>
void siguienteVal(const colecInterdep<I, V> &c, V &v, bool &error);

/**
 * @brief Indica si el siguiente elemento a visitar en la coleccion es dependiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere comprobar si el siguiente elemento es dependiente.
 * @param[out] dep Si el siguiente elemento a visitar es dependiente. `true` si es dependiente, `false` si es independiente.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`).
 */
template <typename I, typename V>
void siguienteDependiente(const colecInterdep<I, V> &c, bool &dep, bool &error);

/**
 * @brief Obtiene el supervisor del siguiente elemento a visitar en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del siguiente elemento.
 * @param[out] sup Identificador del supervisor del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`) o si el siguiente elemento es independiente (no `siguienteDependiente(c)`).
 */
template <typename I, typename V>
void siguienteSuperior(const colecInterdep<I, V> &c, I &sup, bool &error);

/**
 * @brief Obtiene el numero de elementos que dependen del siguiente elemento a visitar en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del siguiente elemento.
 * @param[out] num Numero de elementos dependientes del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`)
 */
template <typename I, typename V>
void siguienteNumDependientes(const colecInterdep<I, V> &c, int &num, bool &error);

/**
 * @brief Avanza el iterador de la coleccion al siguiente elemento.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion
 * @param[in, out] c Coleccion cuyo iterador se quiere avanzar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`)
 */
template <typename I, typename V>
void avanzarIterador(colecInterdep<I, V> &c, bool &error);

// FIN PREDECLARACION DEL TAD GENERICO colecInterdep (fin INTERFAZ)

// DECLARACION DEL TAD GENERICO coleccionInterdep (inicio IMPLEMENTACION)

/**
 * @brief Estructura que representa una coleccion de elementos interdependientes.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 *
 * @note Especificación completa en la sección de predeclaración del TAD.
 *
 * El struct colecInterdep, además de las funciones declaradas como `friend`, tiene los siguientes campos privados:
 * - `tam`: Número de elementos en la colección
 * - `primero`: Puntero al primer nodo de la colección
 * - `actual`: Puntero al nodo actual del iterador
 *
 * Adicionalmente, declara un struct anidado `nodo`, que representa cada elemento de la colección.
 */
template <typename I, typename V>
struct colecInterdep
{
    // Funciones de interfaz
    friend void crear<I, V>(colecInterdep<I, V> &c);
    friend int tamanyo<I, V>(const colecInterdep<I, V> &c);
    friend bool esVacia<I, V>(const colecInterdep<I, V> &c);
    friend bool existe<I, V>(const I id, const colecInterdep<I, V> &c);
    friend bool existeDependiente<I, V>(const I id, const colecInterdep<I, V> &c);
    friend bool existeIndependiente<I, V>(const I id, const colecInterdep<I, V> &c);
    friend void anyadirIndependiente<I, V>(colecInterdep<I, V> &c, const I id, const V v);
    friend void anyadirDependiente<I, V>(colecInterdep<I, V> &c, const I id, const V v, const I super);
    friend void hacerDependiente<I, V>(const colecInterdep<I, V> &c, const I id, const I super);
    friend void hacerIndependiente<I, V>(const colecInterdep<I, V> &c, const I id);
    friend void actualizarVal<I, V>(const colecInterdep<I, V> &c, const I id, const V nuevo, bool &error);
    friend void obtenerVal<I, V>(const I id, const colecInterdep<I, V> &c, V &v, bool &error);
    friend void obtenerSupervisor<I, V>(const I id, const colecInterdep<I, V> &c, I &sup, bool &error);
    friend void obtenerNumDependientes<I, V>(const I id, const colecInterdep<I, V> &c, int &num, bool &error);
    friend void borrar<I, V>(const I id, colecInterdep<I, V> &c);
    friend void iniciarIterador<I, V>(colecInterdep<I, V> &c);
    friend bool existeSiguiente<I, V>(const colecInterdep<I, V> &c);
    friend void siguienteIdent<I, V>(const colecInterdep<I, V> &c, I &id, bool &error);
    friend void siguienteVal<I, V>(const colecInterdep<I, V> &c, V &v, bool &error);
    friend void siguienteDependiente<I, V>(const colecInterdep<I, V> &c, bool &dep, bool &error);
    friend void siguienteSuperior<I, V>(const colecInterdep<I, V> &c, I &sup, bool &error);
    friend void siguienteNumDependientes<I, V>(const colecInterdep<I, V> &c, int &num, bool &error);
    friend void avanzarIterador<I, V>(colecInterdep<I, V> &c, bool &error);

private:
    /**
     * @brief Nodo que constituye la lista enlazada que representa la coleccion.
     * Cada elemento de la coleccion se representa como un nodo en la lista enlazada.
     *
     * El struct nodo contiene los siguientes campos:
     * - `ident`: Identificador del elemento
     * - `val`: Valor del elemento
     * - `super`: Puntero al nodo del que depende el elemento. Si el elemento es independiente, super=nullptr
     * - `numDepend`: Numero de elementos que dependen del elemento
     * - `sig`: Puntero al siguiente nodo en la coleccion
     */
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
 * @brief Inicializa una coleccion vacia, sin elementos.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[out] c Coleccion a inicializar.
 *
 * Post: La coleccion `c` tiene asignados los valores correspondientes a una coleccion vacia
 */
template <typename I, typename V>
void crear(colecInterdep<I, V> &c)
{
    c.tam = 0;
    c.primero = nullptr;
    c.actual = nullptr;
}

/**
 * @brief Devuelve el numero de elementos de la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos.
 * @returns Numero de elementos de la coleccion.
 *
 * Post: Devuelve el campo `tam` de la coleccion `c`
 */
template <typename I, typename V>
int tamanyo(const colecInterdep<I, V> &c)
{
    return c.tam;
}

/**
 * @brief Comprueba si la coleccion esta vacia.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar si esta vacia.
 * @returns `true` si la coleccion esta vacia, `false` en caso contrario.
 *
 * Post: Devuelve `true` si el campo `tam` de la coleccion `c` es 0, `false` en caso contrario
 */
template <typename I, typename V>
bool esVacia(const colecInterdep<I, V> &c)
{
    return c.tam == 0;
}

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento con identificador `id`.
 * @returns `true` si existe un elemento con identificador `id` en la coleccion, `false` en caso contrario.
 *
 * Post: devuelve `true` si existe un nodo en la coleccion `c` cuyo campo `ident` es igual a `id`, `false` en caso contrario
 */
template <typename I, typename V>
bool existe(const I id, const colecInterdep<I, V> &c)
{
    bool encontrado = false;

    // Itera la coleccion desde el primer nodo hasta la posicion donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && nodo->ident <= id;
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
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion y es dependiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento dependiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento dependiente con identificador `id`.
 * @returns `true` si existe un elemento dependiente con identificador `id` en la coleccion, `false` en caso contrario.
 *
 * Post: Devuelve `true` si existe un nodo en la coleccion `c` cuyo campo `ident` es igual a `id` y cuyo campo `super` no es `nullptr`,
 *       `false` en caso contrario
 */
template <typename I, typename V>
bool existeDependiente(const I id, const colecInterdep<I, V> &c)
{
    bool esDep = false;

    // Itera la coleccion desde el primer nodo hasta la posicion donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && nodo->ident <= id;
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
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion y es independiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento independiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento independiente con identificador `id`.
 * @returns `true` si existe un elemento independiente con identificador `id` en la coleccion, `false` en caso contrario.
 *
 * Post: Devuelve `true` si existe un nodo en la coleccion `c` cuyo campo `ident` es igual a `id` y cuyo campo `super` es `nullptr`,
 *       `false` en caso contrario
 */
template <typename I, typename V>
bool existeIndependiente(const I id, const colecInterdep<I, V> &c)
{
    bool esInd = false;

    // Itera la coleccion desde el primer nodo hasta la posicion donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && nodo->ident <= id;
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
 * @brief Añade un elemento dependiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento dependiente.
 * @param id Identificador del elemento dependiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento dependiente que se quiere añadir a la coleccion.
 *
 * Post: Si no existe un elemento con identificador `id` en la coleccion `c`, se añade un nuevo nodo con los campos `ident` y `val`
 *       igual a `id` y `v`, el campo `super` igual a `nullptr` y el campo `numDepend` igual a 0. Este nodo se añade en la posicion
 *       que le corresponde para mantener el orden creciente de los identificadores. En caso contrario, no se añade nada
 */
template <typename I, typename V>
void anyadirIndependiente(colecInterdep<I, V> &c, const I id, const V v)
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
    else if (nodoActual == nullptr || nodoActual->ident != id)
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
 * @brief Añade un elemento independiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion o el supervisor no exista, no se añade nada.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento independiente.
 * @param id Identificador del elemento independiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento independiente que se quiere añadir a la coleccion.
 * @param super Identificador del elemento independiente que sera el supervisor del nuevo elemento dependiente.
 *
 * Post: Si no existe un elemento con identificador `id` en la coleccion `c` y existe un elemento con identificador `super`,
 *       se añade un nuevo nodo con los campos `ident` y `val` igual a `id` y `v`, el campo `super` apuntando al nodo con
 *       identificador `super` y el campo `numDepend` igual a 0. Este nodo se añade en la posicion que le corresponde para mantener
 *       el orden creciente de los identificadores. En caso contrario, no se añade nada
 */
template <typename I, typename V>
void anyadirDependiente(colecInterdep<I, V> &c, const I id, const V v, const I super)
{
    // A diferencia de `anyadirIndependiente()`, aqui no podemos un nodo a una coleccion vacia, ya que seguro que no existe el supervisor.
    // Ademas, ya que un elemento no puede depender de si mismo, `id` y `super` deben ser distintos.
    if (c.tam > 0 && id != super)
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
            while (nodoSuper != nullptr && nodoSuper->ident != super)
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
            else if (nodoActual == nullptr || nodoActual->ident != id)
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
 * @param id Identificador del elemento que se quiere convertir en dependiente.
 * @param super Identificador del elemento que sera el supervisor del elemento que se quiere convertir en dependiente.
 *
 * Post: Si existen los elementos con identificadores `id` y `super` en la coleccion `c`, el elemento con identificador `id`
 *       pasa a depender del elemento con identificador `super`. En caso contrario, no se realiza ningun cambio
 */
template <typename I, typename V>
void hacerDependiente(const colecInterdep<I, V> &c, const I id, const I super)
{
    // Un elemento no puede depender de si mismo
    if (id != super)
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
            while (sup != nullptr && sup->ident != super)
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
 * @param id Identificador del elemento que se quiere convertir en independiente.
 *
 * Post: Si existe el elemento con identificador `id` en la coleccion `c`, el elemento con identificador `id`
 *       pasa a ser independiente. En caso contrario, no se realiza ningun cambio
 */
template <typename I, typename V>
void hacerIndependiente(const colecInterdep<I, V> &c, const I id)
{
    // Itera la coleccion hasta el punto donde deberia estar el elemento con identificador `id`
    for (
        typename colecInterdep<I, V>::nodo *nodo = c.primero;
        nodo != nullptr && nodo->ident <= id;
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
 * @brief Actualiza el valor del elemento con identificador `id` en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere actualizar.
 * @param id Identificador del elemento que se quiere actualizar.
 * @param nuevo Nuevo valor que se quiere asignar al elemento.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 *
 * Post: Si existe un elemento con identificador `id` en la coleccion `c`, su campo `val` se actualiza al valor `nuevo` y error=false.
 *       En caso contrario, error=true (operación parcial)
 */
template <typename I, typename V>
void actualizarVal(const colecInterdep<I, V> &c, const I id, const V nuevo, bool &error)
{
    error = true;

    // Itera la coleccion hasta el punto donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && nodo->ident <= id;
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
 * @brief Obtiene el valor del elemento con identificador `id` de la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el valor.
 * @param[in] c Coleccion de la que se quiere obtener el valor del elemento con identificador `id`.
 * @param[out] v Valor del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 *
 * Post: Si existe un elemento con identificador `id` en la coleccion `c`, se le asigna a `v` su campo `val` y error=false.
 *       En caso contrario, error=true (operación parcial)
 */
template <typename I, typename V>
void obtenerVal(const I id, const colecInterdep<I, V> &c, V &v, bool &error)
{
    error = true;

    // Itera la coleccion hasta el punto donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && nodo->ident <= id;
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
 * @brief Obtiene el identificador del supervisor del elemento con identificador `id` de la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el identificador de su supervisor.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del elemento con identificador `id`.
 * @param[out] sup Identificador del supervisor del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado o elemento independiente).
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion o el elemento no es dependiente, el comportamiento es indefinido.
 *
 * Post: Si existe un elemento con identificador `id` en la coleccion `c` y es dependiente, se le asigna a `sup` el identificador de su supervisor
 *       y error=false. En caso contrario, error=true (operación parcial)
 */
template <typename I, typename V>
void obtenerSupervisor(const I id, const colecInterdep<I, V> &c, I &sup, bool &error)
{
    error = true;

    // Itera la coleccion hasta el punto donde deberia estar el elemento con identificador `id`
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && nodo->ident <= id;
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
 * @brief Obtiene el numero de elementos dependientes del elemento con identificador `id` de la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el numero de elementos dependientes.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del elemento con identificador `id`.
 * @param[out] num Numero de elementos dependientes del elemento con identificador `id`.
 * @param[out] error Indica si se ha producido un error (elemento no encontrado).
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 *
 * Post: Si existe un elemento con identificador `id` en la coleccion `c`, se le asigna a `num` su campo `numDepend` y error=false.
 *       En caso contrario, error=true (operación parcial)
 */
template <typename I, typename V>
void obtenerNumDependientes(const I id, const colecInterdep<I, V> &c, int &num, bool &error)
{
    error = true;

    // Busca el nodo con identificador `id` y devuelve su numero de dependientes
    for (typename colecInterdep<I, V>::nodo *nodo = c.primero;
         nodo != nullptr && nodo->ident <= id;
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
 * @brief Elimina el elemento con identificador `id` de la coleccion.
 * En caso de que el elemento con identificador `id` no exista en la coleccion, no se realiza ningun cambio.
 * Solo se puede eliminar un elemento si no tiene elementos que dependan de él.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere eliminar de la coleccion.
 * @param[in, out] c Coleccion de la que se quiere eliminar el elemento con identificador `id`.
 *
 * Post: Si existe un elemento con identificador `id` en la coleccion `c` y no tiene elementos que dependan de él,
 *       se elimina ese elemento de la coleccion. En caso contrario, no se realiza ningún cambio
 */
template <typename I, typename V>
void borrar(const I id, colecInterdep<I, V> &c)
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
 * @brief Inicializa el iterador de la coleccion para recorrer sus elementos de menor a mayor identificador
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion cuyo iterador se quiere inicializar.
 *
 * Post: Se inicializa el iterador de la coleccion `c`, apuntando al primer elemento de la coleccion
 */
template <typename I, typename V>
void iniciarIterador(colecInterdep<I, V> &c)
{
    c.actual = c.primero;
}

/**
 * @brief Comprueba queda algún elemento por visitar con el iterador de la colección.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar.
 * @returns `true` si existe un siguiente elemento, `false` en caso contrario.
 *
 * Post: Devuelve `true` si el campo `actual` de la coleccion `c` no es `nullptr`, `false` en caso contrario
 */
template <typename I, typename V>
bool existeSiguiente(const colecInterdep<I, V> &c)
{
    return c.actual != nullptr;
}

/**
 * @brief Obtiene el identificador del siguiente elemento a visitar en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del siguiente elemento.
 * @param[out] id Identificador del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`).
 *
 * Post: Si existe un siguiente elemento en la coleccion `c`, se le asigna a `id` el campo `ident` del nodo actual y error=false.
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
 * @brief Obtiene el valor del siguiente elemento a visitar en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el valor del siguiente elemento.
 * @param[out] v Valor del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`).
 *
 * Post: Si existe un siguiente elemento en la coleccion `c`, se le asigna a `v` el campo `val` del nodo actual y error=false.
 *       En caso contrario, error=true (operación parcial)
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
 * @brief Indica si el siguiente elemento a visitar en la coleccion es dependiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere comprobar si el siguiente elemento es dependiente.
 * @param[out] dep Si el siguiente elemento a visitar es dependiente. `true` si es dependiente, `false` si es independiente.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`).
 *
 * Post: Si existe un siguiente elemento en la coleccion `c`, se le asigna a `dep` el resultado de comprobar si el campo `super`
 *       del nodo actual es distinto de `nullptr` y error=false. En caso contrario, error=true (operación parcial)
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
 * @brief Obtiene el supervisor del siguiente elemento a visitar en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del siguiente elemento.
 * @param[out] sup Identificador del supervisor del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`) o si el siguiente elemento es
 *       independiente (no `siguienteDependiente(c)`).
 *
 * Post: Si existe un siguiente elemento en la coleccion `c` y es dependiente, se le asigna a `sup` el campo `ident` del nodo
 *       apuntado por el campo `super` del nodo actual y error=false. En caso contrario, error=true (operación parcial)
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
 * @brief Obtiene el numero de elementos que dependen del siguiente elemento a visitar en la coleccion.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del siguiente elemento.
 * @param[out] num Numero de elementos dependientes del siguiente elemento a visitar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`)
 *
 * Post: Si existe un siguiente elemento en la coleccion `c`, se le asigna a `num` el campo `numDepend` del nodo actual y error=false.
 *       En caso contrario, error=true (operación parcial)
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
 * @brief Avanza el iterador de la coleccion al siguiente elemento.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion
 * @param[in, out] c Coleccion cuyo iterador se quiere avanzar.
 * @param[out] error Indica si se ha producido un error (no quedan elementos por visitar).
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`)
 *
 * Post: Si existe un siguiente elemento en la coleccion `c`, el campo `actual` del iterador se actualiza al siguiente nodo
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