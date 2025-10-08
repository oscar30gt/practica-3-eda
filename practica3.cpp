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

void A(colecInterdep<string, evento> &c, ifstream &f);
void C(colecInterdep<string, evento> &c, ifstream &f);
void O(colecInterdep<string, evento> &c, ifstream &f);
void E(colecInterdep<string, evento> &c, ifstream &f);
void I(colecInterdep<string, evento> &c, ifstream &f);
void D(colecInterdep<string, evento> &c, ifstream &f);
void B(colecInterdep<string, evento> &c, ifstream &f);
void LD(colecInterdep<string, evento> &c, ifstream &f);
void LT(colecInterdep<string, evento> &c);

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
        if (instruccion == "A")
            A(c, f);
        else if (instruccion == "C")
            C(c, f);
        else if (instruccion == "O")
            O(c, f);
        else if (instruccion == "E")
            E(c, f);
        else if (instruccion == "I")
            I(c, f);
        else if (instruccion == "D")
            D(c, f);
        else if (instruccion == "B")
            B(c, f);
        else if (instruccion == "LD")
            LD(c, f);
        else if (instruccion == "LT")
            LT(c);
    }

    f.close();
    return 0;
}

void A(colecInterdep<string, evento> &c, ifstream &f)
{
}

void C(colecInterdep<string, evento> &c, ifstream &f)
{
}

void O(colecInterdep<string, evento> &c, ifstream &f)
{
}

void E(colecInterdep<string, evento> &c, ifstream &f)
{
}

void I(colecInterdep<string, evento> &c, ifstream &f)
{
}

void D(colecInterdep<string, evento> &c, ifstream &f)
{
}

void B(colecInterdep<string, evento> &c, ifstream &f)
{
}

void LD(colecInterdep<string, evento> &c, ifstream &f)
{
}

// LT: Listar todos los eventos de la coleccion
void LT(colecInterdep<string, evento> &c)
{
    cout << "-----LISTADO: " << tamanyo(c) << endl;
    iniciarIterador(c);
    while (existeSiguiente(c))
    {
        evento ev = siguienteVal(c);
        cout << "[ " << siguienteIdent(c) << " --- " << siguienteNumDependientes(c) << " ] --- "
             << descripcion(ev)
             << " --- ( " << suPrioridad(ev) << " ) " << endl;
        avanzarIterador(c);
    }
}