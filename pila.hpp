/**
 * @file pila.hpp
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 */

#ifndef PILA_HPP
#define PILA_HPP

// PREDECLARACION DEL TAD GENERICO pila (inicio INTERFAZ)

/**
 * @brief Representa una pila de elementos basica con operaciones de apilar y desapilar.
 * @tparam T Tipo de los elementos de la pila.
 */
template <typename T>
struct pila;

/**
 * @brief Inicializa la pila `p` como una pila vacia.
 * @tparam T Tipo de los elementos de la pila.
 * @param[out] p Pila a inicializar.
 */
template <typename T>
void crear(pila<T> &p);

/**
 * @brief Apila el elemento `e` en la pila `p`.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in, out] p Pila en la que se apilara el elemento.
 * @param[in] e Elemento a apilar.
 */
template <typename T>
void push(pila<T> &p, const T &e);

/**
 * @brief Desapila un elemento de la pila `p` si no esta vacia.
 * En caso contrario, no realiza ningun cambio.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in, out] p Pila a desapilar.
 */
template <typename T>
void pop(pila<T> &p);

/**
 * @brief Obtiene si la pila `p` esta vacia.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener si esta vacia.
 * @returns `true` si la pila `p` esta vacia, false en caso contrario.
 */
template <typename T>
bool esVacia(const pila<T> &p);

/**
 * @brief Obtiene el elemento que esta en la cima de la pila `p` sin desapilarlo.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener el elemento de la cima.
 * @param[out] e Elemento en la cima de la pila.
 * @param[out] error Indica si se ha producido un error (pila vacia).
 */
template <typename T>
void cima(const pila<T> &p, T &e, bool &error);

// FIN PREDECLARACION DEL TAD GENERICO pila (fin INTERFAZ)

// DECLARACION DEL TAD GENERICO pila (inicio IMPLEMENTACION)

/**
 * @brief Representa una pila de elementos basica con operaciones de apilar y desapilar.
 * @tparam T Tipo de los elementos de la pila.
 */
template <typename T>
struct pila
{
    /* Funciones amigas para permitir el acceso a los campos privados del TAD, asi como su modificacion. */
    friend void crear<T>(pila<T> &p);
    friend void push<T>(pila<T> &p, const T &e);
    friend void pop<T>(pila<T> &p);
    friend bool esVacia<T>(const pila<T> &p);
    friend void cima<T>(const pila<T> &p, T &e, bool &error);

    /* El TAD pila se implementa como una lista enlazada,
       en el que cada elemento es del tipo `pila::nodo`. */

private:
    /** Nodo de la pila. */
    struct nodo
    {
        /** Valor del nodo. */
        T valor;

        /** Puntero al siguiente nodo. */
        nodo *sig;
    };

    /** Puntero al nodo que esta en la cima de la pila. */
    nodo *cima = nullptr;

    /** Tamaño de la pila. */
    int tam = 0;
};

/**
 * @brief Inicializa la pila `p` como una pila vacia.
 * @tparam T Tipo de los elementos de la pila.
 * @param[out] p Pila a inicializar.
 *
 * Post: la pila `p` tiene asignados a sus campos los valores correspondientes a una pila vacia.
 *       En caso de que la pila ya contuviera elementos, se libera la memoria ocupada por dichos elementos.
 */
template <typename T>
void crear(pila<T> &p)
{
    // Libera la memoria de los nodos existentes
    while (p.tam > 0)
    {
        pop(p);
    }

    p.cima = nullptr;
    p.tam = 0;
}

/**
 * @brief Apila el elemento `e` en la pila `p`.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in, out] p Pila en la que se apilara el elemento.
 * @param[in] e Elemento a apilar.
 *
 * Post: se ha insertado un nuevo nodo al comienzo de la lista enlazada
 *       y el campo `tam` de la pila `p` se ha incrementado en 1. `p.cima`
 *       apunta al nuevo nodo.
 */
template <typename T>
void push(pila<T> &p, const T &e)
{
    // Se inserta un nuevo nodo al comienzo de la lista enlazada
    typename pila<T>::nodo *nuevoNodo = new typename pila<T>::nodo;
    nuevoNodo->valor = e;
    nuevoNodo->sig = p.cima;
    p.cima = nuevoNodo;
    p.tam++;
}

/**
 * @brief Desapila un elemento de la pila `p` si no esta vacia.
 * En caso contrario, no realiza ningun cambio.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in, out] p Pila a desapilar.
 *
 * Post: si la pila `p` no esta vacia, se elimina el nodo (liberando memoria)
 *       que esta en la cima de la misma y el campo `tam` de la pila `p` se
 *       decrementa en 1. En caso contrario, no se realiza ningun cambio.
 */
template <typename T>
void pop(pila<T> &p)
{
    // Si hay elementos en la pila, se desapila el elemento de la cima
    if (p.tam > 0)
    {
        // Se actualizan los punteros de la lista enlazada
        typename pila<T>::nodo *aux = p.cima;
        p.cima = p.cima->sig;

        // Libera la memoria del nodo desapilado
        delete aux;
        p.tam--;
    }
}

/**
 * @brief Obtiene si la pila `p` esta vacia.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener si esta vacia.
 * @returns `true` si la pila `p` esta vacia, false en caso contrario.
 *
 * Post: devuelve `true` si el campo `tam` de la pila `p` es 0, `false` en caso contrario.
 */
template <typename T>
bool esVacia(const pila<T> &p)
{
    return p.tam == 0;
}

/**
 * @brief Obtiene el elemento que esta en la cima de la pila `p` sin desapilarlo.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener el elemento de la cima.
 * @param[out] e Elemento en la cima de la pila.
 * @param[out] error Indica si se ha producido un error (pila vacia).
 *
 * Post: si la pila `p` no esta vacia, `e` contiene el campo `valor`
 *       del nodo que esta en la cima de la pila y error=false. En caso
 *       contrario, error=true (operacion parcial).
 */
template <typename T>
void cima(const pila<T> &p, T &e, bool &error)
{
    error = p.tam == 0;

    // Si hay elementos en la pila, se obtiene el elemento de la cima
    if (!error)
    {
        e = p.cima->valor;
    }
}

// FIN DECLARACION DEL TAD GENERICO pila (fin IMPLEMENTACION)

#endif // PILA_HPP