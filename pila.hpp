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
 * @brief Inicializa la pila `p` como una pila vacia.
 * @tparam T Tipo de los elementos de la pila.
 * @param[out] p Pila a inicializar.
 */
template <typename T>
void crearPila(pila<T> &p);

/**
 * @brief Tamaño de la pila `p`.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener el tamaño.
 */
template <typename T>
int altura(const pila<T> &p);

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
 * @param[out] e Elemento desapilado.
 * @param[out] error Indica si se ha producido un error (pila vacia).
 */
template <typename T>
void pop(pila<T> &p, T &e, bool &error);

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
    friend int altura<T>(const pila<T> &p);
    friend void push<T>(pila<T> &p, const T &e);
    friend void pop<T>(pila<T> &p, T &e, bool &error);

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
void crearPila(pila<T> &p)
{
    // Libera la memoria de los nodos existentes
    while (p.tam > 0)
    {
        T aux;
        bool error;
        pop(p, aux, error);
    }

    p.cima = nullptr;
    p.tam = 0;
}

/**
 * @brief Tamaño de la pila `p`.
 * @tparam T Tipo de los elementos de la pila.
 * @param[in] p Pila de la que se quiere obtener el tamaño.
 * 
 * Post: devuelve el campo `tam` de la pila `p`.
 */
template <typename T>
int altura(const pila<T> &p)
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
void pop(pila<T> &p, T &e, bool &error)
{
    error = p.tam == 0;

    // Si hay elementos en la pila, se desapila el elemento de la cima
    if (!error)
    {
        e = p.cima->valor;
        p.cima = p.cima->sig;
        delete p.cima;
        p.tam--;
    }
}

// FIN DECLARACION DEL TAD GENERICO pila (fin IMPLEMENTACION)

#endif // PILA_HPP