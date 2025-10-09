/**
 * @file colecInterdep.hpp
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 */

#ifndef COLECCIONINTERDEP_HPP
#define COLECCIONINTERDEP_HPP

using namespace std;

// PREDECLARACION DEL TAD GENERICO colecInterdep (inicio INTERFAZ)

/**
 *  @struct TAD colecInterdep.
 *  @brief Los valores del TAD representan colecciones de elementos formados como tuplas
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
bool existe(I id, const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion y es dependiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento dependiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento dependiente con identificador `id`.
 * @returns `true` si existe un elemento dependiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename I, typename V>
bool existeDependiente(I id, const colecInterdep<I, V> &c);

/**
 * @brief Comprueba si el elemento con identificador `id` existe en la coleccion y es independiente.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento independiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento independiente con identificador `id`.
 * @returns `true` si existe un elemento independiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename I, typename V>
bool existeIndependiente(I id, const colecInterdep<I, V> &c);

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
void anyadirIndependiente(colecInterdep<I, V> &c, I id, V v);

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
void anyadirDependiente(colecInterdep<I, V> &c, I id, V v, I super);

/**
 * @brief Convierte el elemento con identificador `id` en dependiente del elemento con identificador `super`.
 * En caso de que el elemento con identificador `id` ya sea dependiente, no se realiza ningun cambio.
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
void obtenerVal(I id, const colecInterdep<I, V> &c, V &v, bool &error);

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
void obtenerSupervisor(I id, const colecInterdep<I, V> &c, I &sup, bool &error);

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
void obtenerNumDependientes(I id, const colecInterdep<I, V> &c, int &num, bool &error);

/**
 * @brief Elimina el elemento con identificador `id` de la coleccion.
 * En caso de que el elemento con identificador `id` no exista en la coleccion, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere eliminar de la coleccion.
 * @param[in, out] c Coleccion de la que se quiere eliminar el elemento con identificador `id`.
 */
template <typename I, typename V>
void borrar(I id, colecInterdep<I, V> &c);

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

// IMPLEMENTACION DEL TAD GENERICO coleccionInterdep (inicio IMPLEMENTACION)

template <typename I, typename V>
void insertarOrdenado(
    colecInterdep<I, V> &c,
    typename colecInterdep<I, V>::nodo *nuevoNodo);

/**
 * @brief Estructura que representa una coleccion de elementos interdependientes.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 *
 * @note Especificación completa en la sección de predeclaración del TAD.
 */
template <typename I, typename V>
struct colecInterdep
{
private:
    /**
     * @brief Nodo que constituye la lista enlazada que representa la coleccion.
     * Cada elemento de la coleccion se representa como un nodo en la lista enlazada.
     */
    struct nodo
    {
        /**
         * Identificador
         */
        I ident;

        /**
         * Valor del elemento.
         */
        V val;

        /**
         * Elemento del que es directamente dependiente este elemento.
         * Si el elemento es independiente, `nullptr`.
         */
        nodo *super = nullptr;

        /**
         * Numero de elementos que dependen directamente de este elemento.
         */
        int numDepend = 0;

        /**
         * Puntero al siguiente nodo en la coleccion.
         */
        nodo *sig = nullptr;
    };

    /**
     * Numero de elementos en la coleccion.
     */
    int tam = 0;

    /**
     * Puntero al primer nodo de la coleccion. Si la coleccion esta vacia, `nullptr`.
     */
    nodo *primero = nullptr;

    /**
     * Nodo actual del iterador.
     */
    nodo *actual = nullptr;

public:
    // Funciones de interfaz
    friend void crear<I, V>(colecInterdep<I, V> &c);
    friend int tamanyo<I, V>(const colecInterdep<I, V> &c);
    friend bool esVacia<I, V>(const colecInterdep<I, V> &c);
    friend bool existe<I, V>(I id, const colecInterdep<I, V> &c);
    friend bool existeDependiente<I, V>(I id, const colecInterdep<I, V> &c);
    friend bool existeIndependiente<I, V>(I id, const colecInterdep<I, V> &c);
    friend void anyadirIndependiente<I, V>(colecInterdep<I, V> &c, I id, V v);
    friend void anyadirDependiente<I, V>(colecInterdep<I, V> &c, I id, V v, I super);
    friend void hacerDependiente<I, V>(const colecInterdep<I, V> &c, I id, I super);
    friend void hacerIndependiente<I, V>(const colecInterdep<I, V> &c, I id);
    friend void actualizarVal<I, V>(const colecInterdep<I, V> &c, I id, V nuevo, bool &error);
    friend void obtenerVal<I, V>(I id, const colecInterdep<I, V> &c, V &v, bool &error);
    friend void obtenerSupervisor<I, V>(I id, const colecInterdep<I, V> &c, I &sup, bool &error);
    friend void obtenerNumDependientes<I, V>(I id, const colecInterdep<I, V> &c, int &num, bool &error);
    friend void borrar<I, V>(I id, colecInterdep<I, V> &c);
    friend void iniciarIterador<I, V>(colecInterdep<I, V> &c);
    friend bool existeSiguiente<I, V>(const colecInterdep<I, V> &c);
    friend void siguienteIdent<I, V>(const colecInterdep<I, V> &c, I &id, bool &error);
    friend void siguienteVal<I, V>(const colecInterdep<I, V> &c, V &v, bool &error);
    friend void siguienteDependiente<I, V>(const colecInterdep<I, V> &c, bool &dep, bool &error);
    friend void siguienteSuperior<I, V>(const colecInterdep<I, V> &c, I &sup, bool &error);
    friend void siguienteNumDependientes<I, V>(const colecInterdep<I, V> &c, int &num, bool &error);
    friend void avanzarIterador<I, V>(colecInterdep<I, V> &c, bool &error);

    // Funciones auxiliares
    friend void insertarOrdenado<I, V>(colecInterdep<I, V> &c, nodo *nuevoNodo);
};

/**
 * @brief Inicializa una coleccion vacia, sin elementos.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[out] c Coleccion a inicializar.
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
 */
template <typename I, typename V>
bool existe(I id, const colecInterdep<I, V> &c)
{
    bool encontrado = false, salir = false;

    // Empieza desde el primer nodo
    typename colecInterdep<I, V>::nodo *nodoActual = c.primero;
    while (nodoActual != nullptr && !salir)
    {
        // Si encuentra el identificador, deja de buscar
        if (nodoActual->ident == id)
        {
            encontrado = true;
            salir = true;
        }

        // Si se ha pasado la posicion donde deberia estar el identificador, deja de buscar
        else if (nodoActual->ident > id)
        {
            salir = true;
        }

        // Avanza al siguiente nodo
        else
        {
            nodoActual = nodoActual->sig;
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
 */
template <typename I, typename V>
bool existeDependiente(I id, const colecInterdep<I, V> &c)
{
    bool esDep = false, salir = false;

    // Empieza desde el primer nodo
    typename colecInterdep<I, V>::nodo *nodoActual = c.primero;
    while (nodoActual != nullptr && !salir)
    {
        // Si encuentra el identificador, guarda si es dependiente o no
        if (nodoActual->ident == id)
        {
            // No existen identificadores repetidos, por lo que el resultado depende de si ese nodo es dependiente o no
            esDep = nodoActual->esDependiente;
            salir = true;
        }

        // Si se ha pasado la posicion donde deberia estar el identificador, deja de buscar
        else if (nodoActual->ident > id)
        {
            salir = true;
        }

        // Avanza al siguiente nodo
        else
        {
            nodoActual = nodoActual->sig;
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
 */
template <typename I, typename V>
bool existeIndependiente(I id, const colecInterdep<I, V> &c)
{
    bool esDep = false, salir = false;

    // Empieza desde el primer nodo
    typename colecInterdep<I, V>::nodo *nodoActual = c.primero;
    while (nodoActual != nullptr && !salir)
    {
        // Si encuentra el identificador, guarda si es dependiente o no
        if (nodoActual->ident == id)
        {
            // No existen identificadores repetidos, por lo que el resultado depende de si ese nodo es dependiente o no
            esDep = nodoActual->esDependiente;
            salir = true;
        }

        // Si se ha pasado la posicion donde deberia estar el identificador, deja de buscar
        else if (nodoActual->ident > id)
        {
            salir = true;
        }

        // Avanza al siguiente nodo
        else
        {
            nodoActual = nodoActual->sig;
        }
    }

    return !esDep;
}

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
void anyadirIndependiente(colecInterdep<I, V> &c, I id, V v)
{
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
    else if (nodoActual->ident != id)
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
 */
template <typename I, typename V>
void anyadirDependiente(colecInterdep<I, V> &c, I id, V v, I super)
{
    typename colecInterdep<I, V>::nodo *nodoActual = c.primero;
    typename colecInterdep<I, V>::nodo *nodoAnterior = nullptr;
    typename colecInterdep<I, V>::nodo *nodoSuper = nullptr;

    // Itera la coleccion para encontrar la posicion donde insertar el nuevo nodo
    while (nodoActual != nullptr && nodoActual->ident <= id)
    {
        // Busca el supervisor mientras itera
        if (nodoActual->ident == super)
        {
            nodoSuper = nodoActual;
        }
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sig;
    }

    if (nodoActual != nullptr) // Si la coleccion esta vacia, no se puede añadir un dependiente, ya que seguro que no existe el supervisor
    {
        // Si aun no se ha encontrado el supervisor, sigue buscando desde el punto
        // donde se ha quedado, pero sin avanzar el nodoActual
        nodoSuper = nodoActual;
        while (nodoSuper->ident != super && nodoSuper != nullptr)
        {
            nodoSuper = nodoSuper->sig;
        }

        // Añadir al principio
        if (nodoSuper != nullptr && nodoAnterior == nullptr)
        {
            typename colecInterdep<I, V>::nodo *nuevoNodo = new typename colecInterdep<I, V>::nodo;
            nuevoNodo->ident = id;
            nuevoNodo->val = v;
            nuevoNodo->super = nodoSuper;
            nuevoNodo->sig = c.primero;
            c.primero = nuevoNodo;
            c.tam++;
            nodoSuper->numDepend++;
        }

        // Añadir en medio o al final
        else if (nodoAnterior->ident < id)
        {
            typename colecInterdep<I, V>::nodo *nuevoNodo = new typename colecInterdep<I, V>::nodo;
            nuevoNodo->ident = id;
            nuevoNodo->val = v;
            nuevoNodo->super = nodoSuper;
            nuevoNodo->sig = nodoActual;
            nodoAnterior->sig = nuevoNodo;
            c.tam++;
            nodoSuper->numDepend++;
        }

        // Si el identificador ya existe o no se ha encontrado el supervisor, no se añade nada
    }
}

/**
 * @brief Convierte el elemento con identificador `id` en dependiente del elemento con identificador `super`.
 * En caso de que el elemento con identificador `id` ya sea dependiente, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en dependiente.
 * @param id Identificador del elemento que se quiere convertir en dependiente.
 * @param super Identificador del elemento que sera el supervisor del elemento que se quiere convertir en dependiente.
 */
template <typename I, typename V>
void hacerDependiente(const colecInterdep<I, V> &c, I id, I super)
{
    // Si no existe el elemento o ya es dependiente, no se realiza ningun cambio
    if (existeIndependiente(id, c))
    {
        bool encontrado = false;
        // Busca el nodo con identificador `id` y lo convierte en dependiente
        for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
        {
            if (nodo->ident == id)
            {
                nodo->esDependiente = true;
                nodo->indentSup = super;
                encontrado = true;
            }
        }

        encontrado = false;
        // Actualiza el número de dependientes del supervisor
        for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
        {
            if (nodo->ident == super)
            {
                nodo->numDepend++;
                encontrado = true;
            }
        }
    }
}

/**
 * @brief Convierte el elemento con identificador `id` en independiente.
 * En caso de que el elemento con identificador `id` ya sea independiente, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en independiente.
 * @param id Identificador del elemento que se quiere convertir en independiente.
 */
template <typename I, typename V>
void hacerIndependiente(const colecInterdep<I, V> &c, I id)
{
    I super;
    bool encontrado = false;

    // Busca el nodo con identificador `id` y lo convierte en independiente
    for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
    {
        if (nodo->esDependiente && nodo->ident == id)
        {
            super = nodo->indentSup;
            nodo->esDependiente = false;
            encontrado = true;
        }
    }

    encontrado = false;
    // Actualiza el número de dependientes del antiguo supervisor
    for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
    {
        if (nodo->ident == super)
        {
            nodo->numDepend--;
            encontrado = true;
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
 */
template <typename I, typename V>
void actualizarVal(const colecInterdep<I, V> &c, I id, V nuevo, bool &error)
{
    bool encontrado = false;
    // Busca el nodo con identificador `id` y actualiza su valor
    for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
    {
        if (nodo->ident == id)
        {
            nodo->val = nuevo;
            encontrado = true;
        }
    }

    error = !encontrado;
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
 */
template <typename I, typename V>
void obtenerVal(I id, const colecInterdep<I, V> &c, V &v, bool &error)
{
    bool encontrado = false;
    // Busca el nodo con identificador `id` y devuelve su valor
    for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
    {
        if (nodo->ident == id)
        {
            encontrado = true;
            v = nodo->val;
        }
    }

    error = !encontrado;
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
 */
template <typename I, typename V>
void obtenerSupervisor(I id, const colecInterdep<I, V> &c, I &sup, bool &error)
{
    if (existeDependiente(id, c))
    {
        bool encontrado = false;
        error = false;
        // Busca el nodo con identificador `id` y devuelve su supervisor
        for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
        {
            if (nodo->ident == id)
            {
                sup = nodo->indentSup;
                encontrado = true;
            }
        }
    }
    else
    {
        error = true;
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
 */
template <typename I, typename V>
void obtenerNumDependientes(I id, const colecInterdep<I, V> &c, int &num, bool &error)
{
    bool encontrado = false;
    // Busca el nodo con identificador `id` y devuelve su numero de dependientes
    for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
    {
        if (nodo->ident == id)
        {
            encontrado = true;
            num = nodo->numDepend;
        }
    }

    error = !encontrado;
}

/**
 * @brief Elimina el elemento con identificador `id` de la coleccion.
 * En caso de que el elemento con identificador `id` no exista en la coleccion, no se realiza ningun cambio.
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere eliminar de la coleccion.
 * @param[in, out] c Coleccion de la que se quiere eliminar el elemento con identificador `id`.
 */
template <typename I, typename V>
void borrar(I id, colecInterdep<I, V> &c)
{
    typename colecInterdep<I, V>::nodo *nodoActual = c.primero;
    typename colecInterdep<I, V>::nodo *nodoAnterior = nullptr;

    while (nodoActual != nullptr && nodoActual->ident != id)
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sig;
    }

    // Si no encuentra el identificador o tiene nodos que dependen de él, no se realiza ningun cambio
    if (nodoActual != nullptr && nodoActual->numDepend == 0)
    {
        // Si el nodo a borrar es dependiente, actualiza el numero de dependientes del supervisor
        if (nodoActual->esDependiente)
        {
            bool encontrado = false;
            for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
            {
                if (nodo->ident == nodoActual->indentSup)
                {
                    nodo->numDepend--;
                    encontrado = true;
                }
            }
        }
        // Si el nodo a borrar tiene dependientes, los convierte en independientes
        if (nodoActual->numDepend > 0)
        {
            for (typename colecInterdep<I, V>::nodo nodo = c.primero; nodo != nullptr; nodo = nodo->sig)
            {
                if (nodo->esDependiente && nodo->indentSup == id)
                    nodo->esDependiente = false;
            }
        }
        // Borra el nodo y actualiza los enlaces de la lista
        if (nodoAnterior == nullptr)
            // El nodo a borrar es el primero
            c.primero = nodoActual->sig;
        else
            // El nodo a borrar no es el primero
            nodoAnterior->sig = nodoActual->sig;

        delete nodoActual;
        c.tam--;
    }
}

/**
 * @brief Inicializa el iterador de la coleccion para recorrer sus elementos de menor a mayor identificador
 * @tparam I Tipo del identificador de los elementos de la coleccion.
 * @tparam V Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion cuyo iterador se quiere inicializar.
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
 */
template <typename I, typename V>
void siguienteIdent(const colecInterdep<I, V> &c, I &id, bool &error)
{
    if (existeSiguiente(c))
    {
        error = false;
        id = c.actual->ident;
    }
    else
    {
        error = true;
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
 */
template <typename I, typename V>
void siguienteVal(const colecInterdep<I, V> &c, V &v, bool &error)
{
    if (existeSiguiente(c))
    {
        error = false;
        v = c.actual->val;
    }
    else
    {
        error = true;
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
 */
template <typename I, typename V>
void siguienteDependiente(const colecInterdep<I, V> &c, bool &dep, bool &error)
{
    if (existeSiguiente(c))
    {
        error = false;
        dep = c.actual->esDependiente;
    }
    else
    {
        error = true;
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
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no `existeSiguiente(c)`) o si el siguiente elemento es independiente (no `siguienteDependiente(c)`).
 */
template <typename I, typename V>
void siguienteSuperior(const colecInterdep<I, V> &c, I &id, bool &error)
{
    if (!existeSiguiente(c) || !siguienteDependiente(c))
    {
        error = true;
    }
    else
    {
        error = false;
        id = c.actual->indentSup;
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
 */
template <typename I, typename V>
void siguienteNumDependientes(const colecInterdep<I, V> &c, int &num, bool &error)
{
    if (existeSiguiente(c))
    {
        error = false;
        num = c.actual->numDepend;
    }
    else
    {
        error = true;
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
 */
template <typename I, typename V>
void avanzarIterador(colecInterdep<I, V> &c, bool &error)
{
    if (existeSiguiente(c))
    {
        error = false;
        c.actual = c.actual->sig;
    }
    else
    {
        error = true;
    }
}

// FIN IMPLEMENTACION DEL TAD GENERICO coleccionInterdep (fin IMPLEMENTACION)

#endif // COLECINTERDEP_HPP