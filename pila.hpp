/**
 * @file colecInterdep.hpp
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 */

#ifndef PILA_HPP
#define PILA_HPP

using namespace std;

// PREDECLARACION DEL TAD GENERICO pila (inicio INTERFAZ)

/**
 * @brief Representa una pila de elementos de tipo T.
 *
 * @tparam T Tipo de los elementos de la pila.
 */
template <typename T>
struct pila;

/**
 * @brief Crea una pila vacia.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in, out] p Pila a crear.
 */
template <typename T>
void crearPila(pila<T> &p);

/**
 * @brief Tamaño de la pila `p`.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener el tamaño.
 */
template <typename T>
int size(const pila<T> &p);

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
 * @tparam T Tipo de los elementos de la pila.
 * @param[in, out] p Pila a desapilar.
 * @param[out] error Indica si se ha producido un error (pila vacia).
 */
template <typename T>
void pop(pila<T> &p, bool &error);

/**
 * @brief Devuelve el elemento que esta en la cima de la pila `p` sin desapilarlo.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener el elemento de la cima.
 * @returns Elemento que esta en la cima de la pila `p`.
 */
template <typename T>
T cima(const pila<T> &p);

// FIN PREDECLARACION DEL TAD GENERICO pila (fin INTERFAZ)

// DECLARACION DEL TAD GENERICO pila (inicio IMPLEMENTACION)

/**
 * @brief Representa una pila de elementos de tipo T.
 *
 * @tparam T Tipo de los elementos de la pila.
 */
template <typename T>
struct pila
{
    /* Funciones amigas para permitir el acceso a los campos privados del TAD, asi como su modificacion. */
    friend void crearPila<T>(pila<T> &p);
    friend int size<T>(const pila<T> &p);
    friend void push<T>(pila<T> &p, const T &e);
    friend void pop<T>(pila<T> &p, bool &error);
    friend T cima<T>(const pila<T> &p);

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

    /**< Tamaño de la pila. */
    int tam = 0;
};

/**
 * @brief Crea una pila vacia.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in, out] p Pila a crear.
 *
 * Post: la pila `p` esta vacia (campo `cima` apunta a nullptr
 *       y campo `tam` vale 0).
 */
template <typename T>
void crearPila(pila<T> &p)
{
    p.cima = nullptr;
    p.tam = 0;
}

/**
 * @brief Tamaño de la pila `p`.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener el tamaño.
 */
template <typename T>
int size(const pila<T> &p)
{
    return p.tam;
}

/**
 * @brief Apila el elemento `e` en la pila `p`.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in, out] p Pila en la que se apilara el elemento.
 * @param[in] e Elemento a apilar.
 *
 * Post: se ha insertado un nuevo nodo al comienzo de la lista enlazada
 *       y el campo `tam` de la pila `p` se ha incrementado en 1.
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
 * @tparam T Tipo de los elementos de la pila.
 * @param[in, out] p Pila a desapilar.
 * @param[out] e Elemento desapilado.
 * @param[out] error Indica si se ha producido un error (pila vacia).
 *
 * Post: si la pila `p` no esta vacia, `e` contiene el campo `valor`
 *       del nodo que estaba en la cima de la pila y error=false. El
 *       nodo se ha eliminado de la lista enlazada y el campo `tam`
 *       de la pila `p` se ha decrementado en 1. En caso contrario,
 *       error=true (operacion parcial).
 */
template <typename T>
void pop(pila<T> &p, bool &error)
{
    error = p.tam == 0;

    // Si hay elementos en la pila, se desapila el elemento de la cima
    if (!error)
    {
        p.cima = p.cima->sig;
        delete p.cima;
        p.tam--;
    }
}

/**
 * @brief Devuelve el elemento que esta en la cima de la pila `p` sin desapilarlo.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener el elemento de la cima.
 * @returns Elemento que esta en la cima de la pila `p`.
 */
template <typename T>
T cima(const pila<T> &p)
{
    return p.cima->valor;
}

// FIN DECLARACION DEL TAD GENERICO pila (fin IMPLEMENTACION)

#endif // PILA_HPP