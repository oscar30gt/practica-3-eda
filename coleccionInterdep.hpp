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
template<typename Ident, typename Val> struct colecInterdep;

/**
 * @brief Inicializa una coleccion vacia, sin elementos.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion a inicializar.
 */
template <typename Ident, typename Val>
void crear(colecInterdep<Ident, Val> &c);

/**
 * @brief Devuelve el numero de elementos de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el numero de elementos.
 * @returns Numero de elementos de la coleccion.
 */
template <typename Ident, typename Val>
int tamanyo(const colecInterdep<Ident, Val> &c);

/**
 * @brief Devuelve `true` si la coleccion esta vacia, `false` en caso contrario.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion que se quiere comprobar si esta vacia.
 * @returns `true` si la coleccion esta vacia, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool esVacia(const colecInterdep<Ident, Val> &c);

/**
 * @brief Comprueba si existe un elemento con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere buscar en la coleccion.
 * @param c Coleccion en la que se quiere buscar el elemento con identificador `id`.
 * @returns `true` si existe un elemento con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existe(Ident id, const colecInterdep<Ident, Val> &c);

/**
 * @brief Comprueba si existe un elemento dependiente con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento dependiente que se quiere buscar en la coleccion.
 * @param c Coleccion en la que se quiere buscar el elemento dependiente con identificador `id`.
 * @returns `true` si existe un elemento dependiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeDependiente(Ident id, const colecInterdep<Ident, Val> &c);

/**
 * @brief Comprueba si existe un elemento independiente con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento independiente que se quiere buscar en la coleccion.
 * @param c Coleccion en la que se quiere buscar el elemento independiente con identificador `id`.
 * @returns `true` si existe un elemento independiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeIndependiente(Ident id, const colecInterdep<Ident, Val> &c);

/**
 * @brief Añade un elemento dependiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion a la que se quiere añadir el elemento dependiente.
 * @param id Identificador del elemento dependiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento dependiente que se quiere añadir a la coleccion.
 */
template <typename Ident, typename Val>
void anyadirIndependiente(colecInterdep<Ident, Val> &c, Ident id, Val v);

/**
 * @brief Añade un elemento independiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion a la que se quiere añadir el elemento independiente.
 * @param id Identificador del elemento independiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento independiente que se quiere añadir a la coleccion.
 * @param super Identificador del elemento independiente que sera el supervisor del nuevo elemento dependiente.
 */
template <typename Ident, typename Val>
void anyadirDependiente(colecInterdep<Ident, Val> &c, Ident id, Val v, Ident super);

/**
 * @brief Convierte el elemento con identificador `id` en dependiente del elemento con identificador `super`.
 * En caso de que el elemento con identificador `id` ya sea dependiente, no se realiza ningun cambio.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion en la que se encuentra el elemento que se quiere convertir en dependiente.
 * @param id Identificador del elemento que se quiere convertir en dependiente.
 * @param super Identificador del elemento que sera el supervisor del elemento que se quiere convertir en dependiente.
 */
template <typename Ident, typename Val>
void hacerDependiente(const colecInterdep<Ident, Val> &c, Ident id, Ident super);

/**
 * @brief Convierte el elemento con identificador `id` en independiente.
 * En caso de que el elemento con identificador `id` ya sea independiente, no se realiza ningun cambio.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion en la que se encuentra el elemento que se quiere convertir en independiente.
 * @param id Identificador del elemento que se quiere convertir en independiente.
 */
template <typename Ident, typename Val>
void hacerIndependiente(const colecInterdep<Ident, Val> &c, Ident id);

/**
 * @brief Actualiza el valor del elemento con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion en la que se encuentra el elemento que se quiere actualizar.
 * @param id Identificador del elemento que se quiere actualizar.
 * @param nuevo Nuevo valor que se quiere asignar al elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
void actualizarVal(colecInterdep<Ident, Val> &c, Ident id, Val nuevo);

/**
 * @brief Obtiene el valor del elemento con identificador `id` de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el valor.
 * @param c Coleccion de la que se quiere obtener el valor del elemento con identificador `id`.
 * @returns Valor del elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
Val obtenerVal(Ident id, const colecInterdep<Ident, Val> &c);

/**
 * @brief Obtiene el identificador del supervisor del elemento con identificador `id` de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el identificador de su supervisor.
 * @param c Coleccion de la que se quiere obtener el identificador del supervisor del elemento con identificador `id`.
 * @returns Identificador del supervisor del elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
Ident obtenerSupervisor(Ident id, const colecInterdep<Ident, Val> &c);

/**
 * @brief Obtiene el numero de elementos dependientes del elemento con identificador `id` de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el numero de elementos dependientes.
 * @param c Coleccion de la que se quiere obtener el numero de elementos dependientes del elemento con identificador `id`.
 * @returns Numero de elementos dependientes del elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
int obtenerNumDependientes(Ident id, const colecInterdep<Ident, Val> &c);

/**
 * @brief Elimina el elemento con identificador `id` de la coleccion.
 * En caso de que el elemento con identificador `id` no exista en la coleccion, no se realiza ningun cambio.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere eliminar de la coleccion.
 * @param c Coleccion de la que se quiere eliminar el elemento con identificador `id`.
 */
template <typename Ident, typename Val>
void borrar(Ident id, colecInterdep<Ident, Val> &c);

/**
 * @brief Inicializa el iterador de la coleccion para recorrer sus elementos de menor a mayor identificador
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion cuyo iterador se quiere inicializar.
 */
template <typename Ident, typename Val>
void iniciarIterador(colecInterdep<Ident, Val> &c);

/**
 * @brief Comprueba queda algún elemento por visitar con el iterador de la colección.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion que se quiere comprobar.
 * @returns `true` si existe un siguiente elemento, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeSiguiente(const colecInterdep<Ident, Val> &c);

/**
 * @brief Obtiene el identificador del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el identificador del siguiente elemento.
 * @returns Identificador del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
Ident siguienteIdent(colecInterdep<Ident, Val> &c);

/**
 * @brief Obtiene el valor del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el valor del siguiente elemento.
 * @returns Valor del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
Val siguienteVal(colecInterdep<Ident, Val> &c);

/**
 * @brief Indica si el siguiente elemento a visitar en la coleccion es dependiente.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere comprobar si el siguiente elemento es dependiente.
 * @returns `true` si el siguiente elemento es dependiente, `false` en caso contrario.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
bool siguienteDependiente(const colecInterdep<Ident, Val> &c);

/**
 * @brief Obtiene el supervisor del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el identificador del supervisor del siguiente elemento.
 * @returns Identificador del supervisor del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c)) o si el siguiente elemento es independiente (no siguienteDependiente(c))
 */
template <typename Ident, typename Val>
Ident siguienteSuperior(colecInterdep<Ident, Val> &c);

/**
 * @brief Obtiene el numero de elementos que dependen del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el numero de elementos dependientes del siguiente elemento.
 * @returns Numero de elementos dependientes del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
int siguienteNumDependientes(colecInterdep<Ident, Val> &c);

/**
 * @brief Avanza el iterador de la coleccion al siguiente elemento.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion
 * @param c Coleccion cuyo iterador se quiere avanzar.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void avanzarIterador(colecInterdep<Ident, Val> &c);

/**
 * @brief Estructura que representa una coleccion de elementos interdependientes.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 */
template <typename Ident, typename Val>
struct colecInterdep
{
    friend void crear<Ident, Val>(colecInterdep<Ident, Val> &c);
    friend int tamanyo<Ident, Val>(const colecInterdep<Ident, Val> &c);
    friend bool esVacia<Ident, Val>(const colecInterdep<Ident, Val> &c);
    friend bool existe<Ident, Val>(Ident id, const colecInterdep<Ident, Val> &c);
    friend bool existeDependiente<Ident, Val>(Ident id, const colecInterdep<Ident, Val> &c);
    friend bool existeIndependiente<Ident, Val>(Ident id, const colecInterdep<Ident, Val> &c);
    friend void anyadirIndependiente<Ident, Val>(colecInterdep<Ident, Val> &c, Ident id, Val v);
    friend void anyadirDependiente<Ident, Val>(colecInterdep<Ident, Val> &c, Ident id, Val v, Ident super);
    friend void hacerDependiente<Ident, Val>(const colecInterdep<Ident, Val> &c, Ident id, Ident super);
    friend void hacerIndependiente<Ident, Val>(const colecInterdep<Ident, Val> &c, Ident id);
    friend void actualizarVal<Ident, Val>(colecInterdep<Ident, Val> &c, Ident id, Val nuevo);
    friend Val obtenerVal<Ident, Val>(Ident id, const colecInterdep<Ident, Val> &c);
    friend Ident obtenerSupervisor<Ident, Val>(Ident id, const colecInterdep<Ident, Val> &c);
    friend int obtenerNumDependientes<Ident, Val>(Ident id, const colecInterdep<Ident, Val> &c);
    friend void borrar<Ident, Val>(Ident id, colecInterdep<Ident, Val> &c);
    friend void iniciarIterador<Ident, Val>(colecInterdep<Ident, Val> &c);
    friend bool existeSiguiente<Ident, Val>(const colecInterdep<Ident, Val> &c);
    friend Ident siguienteIdent<Ident, Val>(colecInterdep<Ident, Val> &c);
    friend Val siguienteVal<Ident, Val>(colecInterdep<Ident, Val> &c);
    friend bool siguienteDependiente<Ident, Val>(const colecInterdep<Ident, Val> &c);
    friend Ident siguienteSuperior<Ident, Val>(colecInterdep<Ident, Val> &c);
    friend int siguienteNumDependientes<Ident, Val>(colecInterdep<Ident, Val> &c);
    friend void avanzarIterador<Ident, Val>(colecInterdep<Ident, Val> &c);

private:
    /** Primer nodo de la coleccion. */
    nodo *primero = nullptr;

    /** Numero de elementos en la coleccion. */
    int tamanyo = 0;

    /** Nodo actual del iterador. */
    int actual = 0;

    /**
     * Nodo que constituye la lista enlazada que representa la coleccion.
     * Cada nodo representa un elemento.
     */
    struct nodo
    {
        Ident ident;
        Val val;
        Ident indentSup = nullptr;
        int numDepend = 0;

        /** Puntero al siguiente nodo en la coleccion. */
        nodo *sig = nullptr;
    };
};

/**
 * @brief Inicializa una coleccion vacia, sin elementos.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion a inicializar.
 */
template <typename Ident, typename Val>
void crear(colecInterdep<Ident, Val> &c)
{
    c.primero = nullptr;
    c.tamanyo = 0;
    c.actual = 0;
}

/**
 * @brief Devuelve el numero de elementos de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el numero de elementos.
 * @returns Numero de elementos de la coleccion.
 */
template <typename Ident, typename Val>
int tamanyo(const colecInterdep<Ident, Val> &c)
{
    return c.tamanyo;
}

/**
 * @brief Devuelve `true` si la coleccion esta vacia, `false` en caso contrario.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion que se quiere comprobar si esta vacia.
 * @returns `true` si la coleccion esta vacia, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool esVacia(const colecInterdep<Ident, Val> &c)
{
    return c.tamanyo == 0;
}

/**
 * @brief Comprueba si existe un elemento con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere buscar en la coleccion.
 * @param c Coleccion en la que se quiere buscar el elemento con identificador `id`.
 * @returns `true` si existe un elemento con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existe(Ident id, const colecInterdep<Ident, Val> &c)
{
    // Empieza desde el primer nodo
    typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
    while (nodoActual != nullptr)
    {
        // Si encuentra el identificador, devuelve `true`
        if (nodoActual->ident == id)
            return true;

        // Avanza al siguiente nodo
        nodoActual = nodoActual->sig;
    }

    // Si no encuentra el identificador, devuelve `false`
    return false;
}

/**
 * @brief Comprueba si existe un elemento dependiente con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento dependiente que se quiere buscar en la coleccion.
 * @param c Coleccion en la que se quiere buscar el elemento dependiente con identificador `id`.
 * @returns `true` si existe un elemento dependiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeDependiente(Ident id, const colecInterdep<Ident, Val> &c)
{
    // Empieza desde el primer nodo
    typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
    while (nodoActual != nullptr)
    {
        // Si encuentra el identificador y es dependiente, devuelve `true`
        if (nodoActual->ident == id)

            // No existen identificadores repetidos, por lo que el resultado depende de si ese nodo es dependiente o no
            return nodoActual->indentSup != nullptr;

        // Avanza al siguiente nodo
        nodoActual = nodoActual->sig;
    }

    // Si no encuentra el identificador o no es dependiente, devuelve `false`
    return false;
}

/**
 * @brief Comprueba si existe un elemento independiente con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento independiente que se quiere buscar en la coleccion.
 * @param c Coleccion en la que se quiere buscar el elemento independiente con identificador `id`.
 * @returns `true` si existe un elemento independiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeIndependiente(Ident id, const colecInterdep<Ident, Val> &c)
{
    // Empieza desde el primer nodo
    typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
    while (nodoActual != nullptr)
    {
        // Si encuentra el identificador y es independiente, devuelve `true`
        if (nodoActual->ident == id)

            // No existen identificadores repetidos, por lo que el resultado depende de si ese nodo es independiente o no
            return nodoActual->indentSup == nullptr;

        // Avanza al siguiente nodo
        nodoActual = nodoActual->sig;
    }

    // Si no encuentra el identificador o no es independiente, devuelve `false`
    return false;
}

template <typename Ident, typename Val>
typename colecInterdep<Ident, Val>::nodo *insertarOrdenado(
    colecInterdep<Ident, Val> &c,
    typename colecInterdep<Ident, Val>::nodo *nuevoNodo)
{
    // Si la colección está vacía, el nuevo nodo es el primero
    if (c.primero == nullptr)
    {
        c.primero = nuevoNodo;
    }
    else
    {
        typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
        typename colecInterdep<Ident, Val>::nodo *nodoAnterior = nullptr;

        while (nodoActual != nullptr && nodoActual->ident < nuevoNodo->ident)
        {
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->sig;
        }

        if (nodoAnterior == nullptr)
        {
            // Insertar al principio
            nuevoNodo->sig = c.primero;
            c.primero = nuevoNodo;
        }
        else
        {
            // Insertar en medio o al final
            nuevoNodo->sig = nodoActual;
            nodoAnterior->sig = nuevoNodo;
        }
    }

    c.tamanyo++;
    return nuevoNodo;
}

/**
 * @brief Añade un elemento independiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion a la que se quiere añadir el elemento independiente.
 * @param id Identificador del elemento independiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento independiente que se quiere añadir a la coleccion.
 * @param super Identificador del elemento independiente que sera el supervisor del nuevo elemento dependiente.
 */
template <typename Ident, typename Val>
void anyadirIndependiente(colecInterdep<Ident, Val> &c, Ident id, Val v)
{
    // Si el elemento ya existe, no se añade nada
    if (existe(id, c))
        return;

    // Crea un nuevo nodo
    typename colecInterdep<Ident, Val>::nodo *nuevoNodo = new typename colecInterdep<Ident, Val>::nodo;
    nuevoNodo->ident = id;
    nuevoNodo->val = v;
    nuevoNodo->indentSup = nullptr; // Es independiente
    nuevoNodo->numDepend = 0;
    nuevoNodo->sig = nullptr;

    // Si la coleccion esta vacia, el nuevo nodo es el primero
    if (c.primero == nullptr)
    {
        c.primero = nuevoNodo;
    }
    else
    {
        // Si no, busca la posicion correcta para insertar el nuevo nodo
        typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
        typename colecInterdep<Ident, Val>::nodo *nodoAnterior = nullptr;

        while (nodoActual != nullptr && nodoActual->ident < id)
        {
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->sig;
        }

        // Inserta el nuevo nodo en la posicion correcta
        if (nodoAnterior == nullptr)
        {
            // Insertar al principio
            nuevoNodo->sig = c.primero;
            c.primero = nuevoNodo;
        }
        else
        {
            // Insertar en medio o al final
            nuevoNodo->sig = nodoActual;
            nodoAnterior->sig = nuevoNodo;
        }
    }

    // Incrementa el tamaño de la colección
    c.tamanyo++;
}
/**
 * @brief Añade un elemento dependiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion a la que se quiere añadir el elemento dependiente.
 * @param id Identificador del elemento dependiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento dependiente que se quiere añadir a la coleccion.
 */
template <typename Ident, typename Val>
void anyadirDependiente(colecInterdep<Ident, Val> &c, Ident id, Val v, Ident super)
{
    // Si el elemento ya existe o el supervisor no existe, no se añade nada
    if (existe(id, c) || !existe(super, c))
        return;

    // Crea un nuevo nodo
    typename colecInterdep<Ident, Val>::nodo *nuevoNodo = new typename colecInterdep<Ident, Val>::nodo;
    nuevoNodo->ident = id;
    nuevoNodo->val = v;
    nuevoNodo->indentSup = super; // Es dependiente del supervisor
    nuevoNodo->numDepend = 0;
    nuevoNodo->sig = nullptr;

    // Si la coleccion esta vacia, el nuevo nodo es el primero
    if (c.primero == nullptr)
    {
        c.primero = nuevoNodo;
    }
    else
    {
        // Si no, busca la posicion correcta para insertar el nuevo nodo
        typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
        typename colecInterdep<Ident, Val>::nodo *nodoAnterior = nullptr;

        while (nodoActual != nullptr && nodoActual->ident < id)
        {
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->sig;
        }

        // Inserta el nuevo nodo en la posicion correcta
        if (nodoAnterior == nullptr)
        {
            // Insertar al principio
            nuevoNodo->sig = c.primero;
            c.primero = nuevoNodo;
        }
        else
        {
            // Insertar en medio o al final
            nuevoNodo->sig = nodoActual;
            nodoAnterior->sig = nuevoNodo;
        }
    }

    // Incrementa el numero de dependientes del supervisor
    typename colecInterdep<Ident, Val>::nodo *nodoSupervisor = c.primero;
    while (nodoSupervisor != nullptr)
    {
        if (nodoSupervisor->ident == super)
        {
            nodoSupervisor->numDepend++;
            break;
        }
        nodoSupervisor = nodoSupervisor->sig;
    }

    // Incrementa el tamaño de la colección
    c.tamanyo++;
}

/**
 * @brief Inicializa el iterador de la coleccion para recorrer sus elementos de menor a mayor identificador
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion cuyo iterador se quiere inicializar.
 */
template <typename Ident, typename Val>
void iniciarIterador(colecInterdep<Ident, Val> &c)
{
    c.actual = 0;
}

/**
 * @brief Comprueba queda algún elemento por visitar con el iterador de la colección.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion que se quiere comprobar.
 * @returns `true` si existe un siguiente elemento, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeSiguiente(const colecInterdep<Ident, Val> &c)
{
    return c.actual < c.total;
}

/**
 * @brief Obtiene el identificador del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el identificador del siguiente elemento.
 * @returns Identificador del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
Ident siguienteIdent(colecInterdep<Ident, Val> &c)
{
    if(!existeSiguiente(c)) {
        throw runtime_error("Error: no quedan elementos por visitar.");
    }

    auto *nodoActual = c.primero;
    int i = 0;
    while (nodoActual != nullptr && i < c.actual)
    {
        nodoActual = nodoActual->sig;
        i++;
    }

    return nodoActual->ident;
}

/**
 * @brief Obtiene el valor del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el valor del siguiente elemento.
 * @returns Valor del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
Val siguienteVal(colecInterdep<Ident, Val> &c)
{
    if(!existeSiguiente(c)) {
        throw runtime_error("Error: no quedan elementos por visitar.");
    }

    auto *nodoActual = c.primero;
    int i = 0;
    while (nodoActual != nullptr && i < c.actual)
    {
        nodoActual = nodoActual->sig;
        i++;
    }

    return nodoActual->val;
}

/**
 * @brief Indica si el siguiente elemento a visitar en la coleccion es dependiente.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere comprobar si el siguiente elemento es dependiente.
 * @returns `true` si el siguiente elemento es dependiente, `false` en caso contrario.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
bool siguienteDependiente(const colecInterdep<Ident, Val> &c)
{
    if(!existeSiguiente(c)) {
        throw runtime_error("Error: no quedan elementos por visitar.");
    }

    auto *nodoActual = c.primero;
    int i = 0;
    while (nodoActual != nullptr && i < c.actual)
    {
        nodoActual = nodoActual->sig;
        i++;
    }

    return nodoActual->indentSup != nullptr;
}


/**
 * @brief Obtiene el supervisor del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el identificador del supervisor del siguiente elemento.
 * @returns Identificador del supervisor del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c)) o si el siguiente elemento es independiente (no siguienteDependiente(c))
 */
template <typename Ident, typename Val>
Ident siguienteSuperior(colecInterdep<Ident, Val> &c)
{
    if(!existeSiguiente(c)) {
        throw runtime_error("Error: no quedan elementos por visitar.");
    }

    if(!siguienteDependiente(c)) {
        throw runtime_error("Error: el siguiente elemento es independiente.");
    }

    auto *nodoActual = c.primero;
    int i = 0;
    while (nodoActual != nullptr && i < c.actual)
    {
        nodoActual = nodoActual->sig;
        i++;
    }

    return nodoActual->indentSup;
}

/**
 * @brief Obtiene el numero de elementos que dependen del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param c Coleccion de la que se quiere obtener el numero de elementos dependientes del siguiente elemento.
 * @returns Numero de elementos dependientes del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
int siguienteNumDependientes(colecInterdep<Ident, Val> &c)
{
    if(!existeSiguiente(c)) {
        throw runtime_error("Error: no quedan elementos por visitar.");
    }

    auto *nodoActual = c.primero;
    int i = 0;
    while (nodoActual != nullptr && i < c.actual)
    {
        nodoActual = nodoActual->sig;
        i++;
    }

    return nodoActual->numDepend;
}

/**
 * @brief Avanza el iterador de la coleccion al siguiente elemento.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion
 * @param c Coleccion cuyo iterador se quiere avanzar.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void avanzarIterador(colecInterdep<Ident, Val> &c)
{
    if(!existeSiguiente(c)) {
        throw runtime_error("Error: no quedan elementos por visitar.");
    }

    c.actual++;
}
#endif // COLECCIONINTERDEP_HPP