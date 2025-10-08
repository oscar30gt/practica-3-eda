/**
 * @file practica3.cpp
 * Practica 3 - Estructuras de Datos y Algoritmos
 * Grupo 422 - Curso 2025/2026
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 *
 * Programa principal de la práctica 3.
 */

#include <iostream>
#include <string>

#include "evento.hpp"
#include "coleccionInterdep.hpp"

using namespace std;

// Para debug
// Borrar antes de entregar :)
void mostrar(colecInterdep<int, string> &c)
{
    cout << "Coleccion (tamanyo=" << tamanyo(c) << "):" << endl;
    if (esVacia(c))
    {
        cout << "  <vacia>" << endl;
        return;
    }

    iniciarIterador(c);
    while (existeSiguiente(c))
    {
        cout << "===================================================" << endl
             << "  Identificador:   " << siguienteIdent(c) << endl
             << "  Valor:           " << siguienteVal(c) << endl
             << "  Es dependiente?: " << (siguienteDependiente(c) ? "si" : "no") << endl
             << "  Supervisor:      " << (siguienteDependiente(c) ? to_string(siguienteSuperior(c)) : "-") << endl
             << "  NumDependientes: " << siguienteNumDependientes(c) << endl;
        avanzarIterador(c);
    }
}

int main()
{
    return 0;
}