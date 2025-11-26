
/**
 * @file practica5.cpp
 * Practica 5 - Estructuras de Datos y Algoritmos
 * Grupo 422 - Curso 2025/2026
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 *
 * Programa principal de la práctica 5.
 *
 * Repositorio
 * https://github.com/oscar30gt/practica-3-eda (rama practica-5)
 */

#include <string>
#include <iostream>

#include "colecInterdep.hpp"
#include "tarea.hpp"

using namespace std;

int optionsScreen()
{
    cout << "Introduzca el numero correspondiente a la operación que deseas realizar:" << endl
         << "1. Crear una nueva tarea" << endl
         << "2. Hacer a una tarea prerrequisito de otra" << endl
         << "3. Hacer que una tarea no sea prerrequisito de ninguna otra" << endl
         << "4. Actualizar información de una tarea" << endl
         << "5. Mostrar información de una tarea" << endl
         << "6. Borrar una tarea" << endl
         << "7. Mostrar todas las tareas" << endl
         << "8. Salir del programa" << endl;
    int i;
    cin >> i;
    return i;
}

void C()
{
}

void P()
{
}

void NP()
{
}

void A()
{
}

void I()
{
}

void B()
{
}

void M()
{
}

int main()
{
    colecInterdep<string, tarea> c;
    crear(c);
    int op = 0;

    while (op != 8)
    {
        op = optionsScreen();

        if (op != 8)
        {
            switch (op)
            {
            case 1:
                C();
                break;
            case 2:
                P();
                break;
            case 3:
                NP();
                break;
            case 4:
                A();
                break;
            case 5:
                I();
                break;
            case 6:
                B();
                break;
            case 7:
                M();
                break;
            default:
                cout << "ERROR. La operación introducida no es válida." << endl;
            }
        }
    }
}