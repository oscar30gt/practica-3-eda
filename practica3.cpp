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
#include <fstream>
#include <string>

#include "evento.hpp"
#include "colecInterdep.hpp"

using namespace std;

void A(ifstream &f, colecInterdep<string, evento> &c);
void C(ifstream &f, colecInterdep<string, evento> &c);
void O(ifstream &f, colecInterdep<string, evento> &c);
void E(ifstream &f, colecInterdep<string, evento> &c);
void I(ifstream &f, colecInterdep<string, evento> &c);
void D(ifstream &f, colecInterdep<string, evento> &c);
void BI(ifstream &f, colecInterdep<string, evento> &c);
void DI(ifstream &f, colecInterdep<string, evento> &c);
void T(ifstream &f, colecInterdep<string, evento> &c);

int main()
{
    // Inicializa la coleccion
    colecInterdep<string, evento> c;
    crear(c);

    // Abre el fichero de entrada
    ifstream f("entrada.txt");
    if (!f.is_open())
    {
        cerr << "Error al abrir el fichero de entrada." << endl;
        return 1;
    }

    // Lee las instrucciones del fichero de entrada y las ejecuta
    string instruccion;
    while (getline(f, instruccion))
    {
        if (instruccion == "A") A(f, c);
        else if (instruccion == "C") C(f, c);
        else if (instruccion == "O") O(f, c);
        else if (instruccion == "E") E(f, c);
        else if (instruccion == "I") I(f, c);
        else if (instruccion == "D") D(f, c);
        else if (instruccion == "BI") BI(f, c);
        else if (instruccion == "DI") DI(f, c);
        else if (instruccion == "T") T(f, c);
    }

    f.close();
    return 0;
}

void A(ifstream &f, colecInterdep<string, evento> &c)
{
}

void C(ifstream &f, colecInterdep<string, evento> &c)
{
}

void O(ifstream &f, colecInterdep<string, evento> &c)
{
}

void E(ifstream &f, colecInterdep<string, evento> &c)
{
}

void I(ifstream &f, colecInterdep<string, evento> &c)
{
}

void D(ifstream &f, colecInterdep<string, evento> &c)
{
}

void BI(ifstream &f, colecInterdep<string, evento> &c)
{
}

void DI(ifstream &f, colecInterdep<string, evento> &c)
{
}

void T(ifstream &f, colecInterdep<string, evento> &c)
{
}