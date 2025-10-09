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

// PREDECLARACION DEL TAD GENERICO coleccionInterdep (inicio INTERFAZ)

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
template <typename Ident, typename Val>
struct colecInterdep;

/**
 * @brief Inicializa una coleccion vacia, sin elementos.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[out] c Coleccion a inicializar.
 */
template <typename Ident, typename Val>
void crear(colecInterdep<Ident, Val> &c);

/**
 * @brief Devuelve el numero de elementos de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos.
 * @returns Numero de elementos de la coleccion.
 */
template <typename Ident, typename Val>
int tamanyo(const colecInterdep<Ident, Val> &c);

/**
 * @brief Devuelve `true` si la coleccion esta vacia, `false` en caso contrario.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar si esta vacia.
 * @returns `true` si la coleccion esta vacia, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool esVacia(const colecInterdep<Ident, Val> &c);

/**
 * @brief Comprueba si existe un elemento con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento con identificador `id`.
 * @returns `true` si existe un elemento con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existe(Ident id, const colecInterdep<Ident, Val> &c);

/**
 * @brief Comprueba si existe un elemento dependiente con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento dependiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento dependiente con identificador `id`.
 * @returns `true` si existe un elemento dependiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeDependiente(Ident id, const colecInterdep<Ident, Val> &c);

/**
 * @brief Comprueba si existe un elemento independiente con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento independiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento independiente con identificador `id`.
 * @returns `true` si existe un elemento independiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeIndependiente(Ident id, const colecInterdep<Ident, Val> &c);

/**
 * @brief Añade un elemento dependiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento dependiente.
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
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento independiente.
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
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en dependiente.
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
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en independiente.
 * @param id Identificador del elemento que se quiere convertir en independiente.
 */
template <typename Ident, typename Val>
void hacerIndependiente(const colecInterdep<Ident, Val> &c, Ident id);

/**
 * @brief Actualiza el valor del elemento con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere actualizar.
 * @param id Identificador del elemento que se quiere actualizar.
 * @param nuevo Nuevo valor que se quiere asignar al elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
void actualizarVal(const colecInterdep<Ident, Val> &c, Ident id, Val nuevo, bool &error);

/**
 * @brief Obtiene el valor del elemento con identificador `id` de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el valor.
 * @param[in] c Coleccion de la que se quiere obtener el valor del elemento con identificador `id`.
 * @returns Valor del elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
void obtenerVal(Ident id, const colecInterdep<Ident, Val> &c, Val &v, bool &error);

/**
 * @brief Obtiene el identificador del supervisor del elemento con identificador `id` de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el identificador de su supervisor.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del elemento con identificador `id`.
 * @returns Identificador del supervisor del elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
void obtenerSupervisor(Ident id, const colecInterdep<Ident, Val> &c, Ident &sup, bool &error);

/**
 * @brief Obtiene el numero de elementos dependientes del elemento con identificador `id` de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el numero de elementos dependientes.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del elemento con identificador `id`.
 * @returns Numero de elementos dependientes del elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
void obtenerNumDependientes(Ident id, const colecInterdep<Ident, Val> &c, int &num, bool &error);

/**
 * @brief Elimina el elemento con identificador `id` de la coleccion.
 * En caso de que el elemento con identificador `id` no exista en la coleccion, no se realiza ningun cambio.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere eliminar de la coleccion.
 * @param[in, out] c Coleccion de la que se quiere eliminar el elemento con identificador `id`.
 */
template <typename Ident, typename Val>
void borrar(Ident id, colecInterdep<Ident, Val> &c);

/**
 * @brief Inicializa el iterador de la coleccion para recorrer sus elementos de menor a mayor identificador
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion cuyo iterador se quiere inicializar.
 */
template <typename Ident, typename Val>
void iniciarIterador(colecInterdep<Ident, Val> &c);

/**
 * @brief Comprueba queda algún elemento por visitar con el iterador de la colección.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar.
 * @returns `true` si existe un siguiente elemento, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeSiguiente(const colecInterdep<Ident, Val> &c);

/**
 * @brief Obtiene el identificador del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del siguiente elemento.
 * @returns Identificador del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void siguienteIdent(const colecInterdep<Ident, Val> &c, Ident &id, bool &error);

/**
 * @brief Obtiene el valor del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el valor del siguiente elemento.
 * @returns Valor del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void siguienteVal(const colecInterdep<Ident, Val> &c, Val &v, bool &error);

/**
 * @brief Indica si el siguiente elemento a visitar en la coleccion es dependiente.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere comprobar si el siguiente elemento es dependiente.
 * @returns `true` si el siguiente elemento es dependiente, `false` en caso contrario.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void siguienteDependiente(const colecInterdep<Ident, Val> &c, bool &dep, bool &error);

/**
 * @brief Obtiene el supervisor del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del siguiente elemento.
 * @returns Identificador del supervisor del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c)) o si el siguiente elemento es independiente (no siguienteDependiente(c))
 */
template <typename Ident, typename Val>
void siguienteSuperior(const colecInterdep<Ident, Val> &c, Ident &sup, bool &error);

/**
 * @brief Obtiene el numero de elementos que dependen del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del siguiente elemento.
 * @returns Numero de elementos dependientes del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void siguienteNumDependientes(const colecInterdep<Ident, Val> &c, int &num, bool &error);

/**
 * @brief Avanza el iterador de la coleccion al siguiente elemento.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion
 * @param[in, out] c Coleccion cuyo iterador se quiere avanzar.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void avanzarIterador(colecInterdep<Ident, Val> &c, bool &error);

// FIN PREDECLARACION DEL TAD GENERICO coleccionInterdep (fin INTERFAZ)

// IMPLEMENTACION DEL TAD GENERICO coleccionInterdep (inicio IMPLEMENTACION)

template <typename Ident, typename Val>
void insertarOrdenado(
    colecInterdep<Ident, Val> &c,
    typename colecInterdep<Ident, Val>::nodo *nuevoNodo);

/**
 * @brief Estructura que representa una coleccion de elementos interdependientes.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 */
template <typename Ident, typename Val>
struct colecInterdep
{
private:
    /**
     * Nodo que constituye la lista enlazada que representa la coleccion.
     * Cada nodo representa un elemento.
     */
    struct nodo
    {
        Ident ident;
        Val val;
        bool esDependiente;
        Ident indentSup;
        int numDepend = 0;

        /** Puntero al siguiente nodo en la coleccion. */
        nodo *sig = nullptr;
    };

    /** Primer nodo de la coleccion. */
    nodo *primero = nullptr;

    /** Numero de elementos en la coleccion. */
    int tam = 0;

    /** Nodo actual del iterador. */
    nodo *actual = nullptr;

public:
    // Funciones de interfaz
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
    friend void actualizarVal<Ident, Val>(const colecInterdep<Ident, Val> &c, Ident id, Val nuevo, bool &error);
    friend void obtenerVal<Ident, Val>(Ident id, const colecInterdep<Ident, Val> &c, Val &v, bool &error);
    friend void obtenerSupervisor<Ident, Val>(Ident id, const colecInterdep<Ident, Val> &c, Ident &sup, bool &error);
    friend void obtenerNumDependientes<Ident, Val>(Ident id, const colecInterdep<Ident, Val> &c, int &num, bool &error);
    friend void borrar<Ident, Val>(Ident id, colecInterdep<Ident, Val> &c);
    friend void iniciarIterador<Ident, Val>(colecInterdep<Ident, Val> &c);
    friend bool existeSiguiente<Ident, Val>(const colecInterdep<Ident, Val> &c);
    friend void siguienteIdent<Ident, Val>(const colecInterdep<Ident, Val> &c, Ident &id, bool &error);
    friend void siguienteVal<Ident, Val>(const colecInterdep<Ident, Val> &c, Val &v, bool &error);
    friend void siguienteDependiente<Ident, Val>(const colecInterdep<Ident, Val> &c, bool &dep, bool &error);
    friend void siguienteSuperior<Ident, Val>(const colecInterdep<Ident, Val> &c, Ident &sup, bool &error);
    friend void siguienteNumDependientes<Ident, Val>(const colecInterdep<Ident, Val> &c, int &num, bool &error);
    friend void avanzarIterador<Ident, Val>(colecInterdep<Ident, Val> &c, bool &error);

    // Funciones auxiliares
    friend void insertarOrdenado<Ident, Val>(colecInterdep<Ident, Val> &c, nodo *nuevoNodo);
};

/**
 * @brief Inicializa una coleccion vacia, sin elementos.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[out] c Coleccion a inicializar.
 */
template <typename Ident, typename Val>
void crear(colecInterdep<Ident, Val> &c)
{
    c.primero = nullptr;
    c.tam = 0;
    c.actual = 0;
}

/**
 * @brief Devuelve el numero de elementos de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos.
 * @returns Numero de elementos de la coleccion.
 */
template <typename Ident, typename Val>
int tamanyo(const colecInterdep<Ident, Val> &c)
{
    return c.tam;
}

/**
 * @brief Devuelve `true` si la coleccion esta vacia, `false` en caso contrario.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar si esta vacia.
 * @returns `true` si la coleccion esta vacia, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool esVacia(const colecInterdep<Ident, Val> &c)
{
    return c.tam == 0;
}

/**
 * @brief Comprueba si existe un elemento con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento con identificador `id`.
 * @returns `true` si existe un elemento con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existe(Ident id, const colecInterdep<Ident, Val> &c)
{
    bool encontrado = false;

    // Empieza desde el primer nodo
    typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
    while (nodoActual != nullptr && !encontrado)
    {
        // Si encuentra el identificador, se actualiza encontrado a `true`
        if (nodoActual->ident == id)
        {
            encontrado = true;
        }

        // Avanza al siguiente nodo
        nodoActual = nodoActual->sig;
    }

    // Si no encuentra el identificador, devuelve `false`
    return encontrado;
}

/**
 * @brief Comprueba si existe un elemento dependiente con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento dependiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento dependiente con identificador `id`.
 * @returns `true` si existe un elemento dependiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeDependiente(Ident id, const colecInterdep<Ident, Val> &c)
{
    bool encontrado = false;
    bool esDep = false;
    // Empieza desde el primer nodo
    typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
    while (nodoActual != nullptr && !encontrado)
    {
        // Si encuentra el identificador, guarda si es dependiente o no
        if (nodoActual->ident == id)
        {
            encontrado = true;
            // No existen identificadores repetidos, por lo que el resultado depende de si ese nodo es dependiente o no
            esDep = nodoActual->esDependiente;
        }
        // Avanza al siguiente nodo
        nodoActual = nodoActual->sig;
    }

    // Si no encuentra el identificador o no es dependiente, devuelve `false`
    if(!encontrado) {
        return false;
    }
    return esDep;
}

/**
 * @brief Comprueba si existe un elemento independiente con identificador `id` en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento independiente que se quiere buscar en la coleccion.
 * @param[in] c Coleccion en la que se quiere buscar el elemento independiente con identificador `id`.
 * @returns `true` si existe un elemento independiente con identificador `id` en la coleccion, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeIndependiente(Ident id, const colecInterdep<Ident, Val> &c)
{
    bool encontrado = false;
    bool esIndep = false;
    // Empieza desde el primer nodo
    typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
    while (nodoActual != nullptr && !encontrado)
    {
        // Si encuentra el identificador, guarda si es independiente o no
        if (nodoActual->ident == id)
        {
            encontrado = true;
            // No existen identificadores repetidos, por lo que el resultado depende de si ese nodo es independiente o no
            esIndep = !nodoActual->esDependiente;
        }
        // Avanza al siguiente nodo
        nodoActual = nodoActual->sig;
    }

    // Si no encuentra el identificador o es dependiente, devuelve `false`
    if(!encontrado) {
        return false;
    }
    return esIndep;
}

/**
 * @brief Inserta un nuevo nodo en la coleccion de forma ordenada por identificador.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo del identificador de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se quiere insertar el nuevo nodo.
 * @param[in, out] nuevoNodo Nodo que se quiere insertar en la coleccion.
 *
 * @note Funcion auxiliar, no forma parte de la interfaz pública.
 */
template <typename Ident, typename Val>
void insertarOrdenado(
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

    c.tam++;
}

/**
 * @brief Añade un elemento independiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento independiente.
 * @param id Identificador del elemento independiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento independiente que se quiere añadir a la coleccion.
 * @param super Identificador del elemento independiente que sera el supervisor del nuevo elemento dependiente.
 */
template <typename Ident, typename Val>
void anyadirIndependiente(colecInterdep<Ident, Val> &c, Ident id, Val v)
{
    if (!existe(id, c))
    {
        typename colecInterdep<Ident, Val>::nodo *nuevoNodo = new typename colecInterdep<Ident, Val>::nodo;
        nuevoNodo->ident = id;
        nuevoNodo->val = v;
        nuevoNodo->esDependiente = false;
        nuevoNodo->numDepend = 0;
        nuevoNodo->sig = nullptr;

        insertarOrdenado(c, nuevoNodo);
    }
}
/**
 * @brief Añade un elemento dependiente con identificador `id` y valor `v` a la coleccion.
 * En caso de que el elemento con identificador `id` ya exista en la coleccion, no se añade nada.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion a la que se quiere añadir el elemento dependiente.
 * @param id Identificador del elemento dependiente que se quiere añadir a la coleccion.
 * @param v Valor del elemento dependiente que se quiere añadir a la coleccion.
 */
template <typename Ident, typename Val>
void anyadirDependiente(colecInterdep<Ident, Val> &c, Ident id, Val v, Ident super)
{
    if (!existe(id, c) && existe(super, c))
    {
        typename colecInterdep<Ident, Val>::nodo *nuevoNodo = new typename colecInterdep<Ident, Val>::nodo;
        nuevoNodo->ident = id;
        nuevoNodo->val = v;
        nuevoNodo->indentSup = super;
        nuevoNodo->esDependiente = true;
        nuevoNodo->numDepend = 0;
        nuevoNodo->sig = nullptr;

        insertarOrdenado(c, nuevoNodo);

        bool encontrado = false;
        // Actualiza el número de dependientes del supervisor
        for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
            if (nodo->ident == super)
            {
                nodo->numDepend++;
                encontrado = true;
            }
        }
}

/**
 * @brief Convierte el elemento con identificador `id` en dependiente del elemento con identificador `super`.
 * En caso de que el elemento con identificador `id` ya sea dependiente, no se realiza ningun cambio.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en dependiente.
 * @param id Identificador del elemento que se quiere convertir en dependiente.
 * @param super Identificador del elemento que sera el supervisor del elemento que se quiere convertir en dependiente.
 */
template <typename Ident, typename Val>
void hacerDependiente(const colecInterdep<Ident, Val> &c, Ident id, Ident super)
{
    // Si no existe el elemento o ya es dependiente, no se realiza ningun cambio
    if (existeIndependiente(id, c))
    {
        bool encontrado = false;
        // Busca el nodo con identificador `id` y lo convierte en dependiente
        for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
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
        for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en independiente.
 * @param id Identificador del elemento que se quiere convertir en independiente.
 */
template <typename Ident, typename Val>
void hacerIndependiente(const colecInterdep<Ident, Val> &c, Ident id)
{
    Ident super;
    bool encontrado = false;

    // Busca el nodo con identificador `id` y lo convierte en independiente
    for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
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
    for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
    {
        if (nodo->ident == super)
        {
            nodo->numDepend--;
            encontrado = true;
        }
    }
}

/**
 * @brief Convierte el elemento con identificador `id` en independiente.
 * En caso de que el elemento con identificador `id` ya sea independiente, no se realiza ningun cambio.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion en la que se encuentra el elemento que se quiere convertir en independiente.
 * @param id Identificador del elemento que se quiere convertir en independiente.
 * 
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
void actualizarVal(const colecInterdep<Ident, Val> &c, Ident id, Val nuevo, bool &error)
{
    bool encontrado = false;
    // Busca el nodo con identificador `id` y actualiza su valor
    for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el valor.
 * @param[in] c Coleccion de la que se quiere obtener el valor del elemento con identificador `id`.
 * @returns Valor del elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
void obtenerVal(Ident id, const colecInterdep<Ident, Val> &c, Val &v, bool &error)
{
    bool encontrado = false;
    // Busca el nodo con identificador `id` y devuelve su valor
    for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el identificador de su supervisor.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del elemento con identificador `id`.
 * @returns Identificador del supervisor del elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion o el elemento no es dependiente, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
Ident obtenerSupervisor(Ident id, const colecInterdep<Ident, Val> &c, Ident &sup, bool &error)
{
    if(existeDependiente(id, c))
    {
        bool encontrado = false;
        error = false;
        // Busca el nodo con identificador `id` y devuelve su supervisor
        for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
        {
            if (nodo->ident == id)
            {
                sup = nodo->indentSup;
                encontrado = true;
            }
        }
    } else {
        error = true;
    }
}

/**
 * @brief Obtiene el numero de elementos dependientes del elemento con identificador `id` de la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento del que se quiere obtener el numero de elementos dependientes.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del elemento con identificador `id`.
 * @returns Numero de elementos dependientes del elemento con identificador `id`.
 *
 * @note Parcial: Si no existe un elemento con identificador `id` en la coleccion, el comportamiento es indefinido.
 */
template <typename Ident, typename Val>
int obtenerNumDependientes(Ident id, const colecInterdep<Ident, Val> &c, int &num, bool &error)
{
    bool encontrado = false;
    // Busca el nodo con identificador `id` y devuelve su numero de dependientes
    for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param id Identificador del elemento que se quiere eliminar de la coleccion.
 * @param[in, out] c Coleccion de la que se quiere eliminar el elemento con identificador `id`.
 */
template <typename Ident, typename Val>
void borrar(Ident id, colecInterdep<Ident, Val> &c)
{
    typename colecInterdep<Ident, Val>::nodo *nodoActual = c.primero;
    typename colecInterdep<Ident, Val>::nodo *nodoAnterior = nullptr;

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
            for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr && !encontrado; nodo = nodo->sig)
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
            for (typename colecInterdep<Ident, Val>::nodo nodo = c.primero; nodo != nullptr; nodo = nodo->sig)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in, out] c Coleccion cuyo iterador se quiere inicializar.
 */
template <typename Ident, typename Val>
void iniciarIterador(colecInterdep<Ident, Val> &c)
{
    c.actual = c.primero;
}

/**
 * @brief Comprueba queda algún elemento por visitar con el iterador de la colección.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion que se quiere comprobar.
 * @returns `true` si existe un siguiente elemento, `false` en caso contrario.
 */
template <typename Ident, typename Val>
bool existeSiguiente(const colecInterdep<Ident, Val> &c)
{
    return c.actual != nullptr;
}

/**
 * @brief Obtiene el identificador del siguiente elemento a visitar en la coleccion.
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del siguiente elemento.
 * @returns Identificador del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void siguienteIdent(const colecInterdep<Ident, Val> &c, Ident &id, bool &error)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el valor del siguiente elemento.
 * @returns Valor del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void siguienteVal(const colecInterdep<Ident, Val> &c, Val &v, bool &error)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere comprobar si el siguiente elemento es dependiente.
 * @returns `true` si el siguiente elemento es dependiente, `false` en caso contrario.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void siguienteDependiente(const colecInterdep<Ident, Val> &c, bool &dep, bool &error)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el identificador del supervisor del siguiente elemento.
 * @returns Identificador del supervisor del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c)) o si el siguiente elemento es independiente (no siguienteDependiente(c))
 */
template <typename Ident, typename Val>
void siguienteSuperior(const colecInterdep<Ident, Val> &c, Ident &id, bool &error)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion.
 * @param[in] c Coleccion de la que se quiere obtener el numero de elementos dependientes del siguiente elemento.
 * @returns Numero de elementos dependientes del siguiente elemento.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void siguienteNumDependientes(const colecInterdep<Ident, Val> &c, int &num, bool &error)
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
 * @tparam Ident Tipo del identificador de los elementos de la coleccion.
 * @tparam Val Tipo de los elementos de la coleccion
 * @param[in, out] c Coleccion cuyo iterador se quiere avanzar.
 *
 * @note Parcial: La operación no está definida si no quedan elementos por visitar (no existeSiguiente?(c))
 */
template <typename Ident, typename Val>
void avanzarIterador(colecInterdep<Ident, Val> &c, bool &error)
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