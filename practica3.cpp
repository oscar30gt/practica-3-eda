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

// Añadir la información de un nuevo nombre y evento a la colección
void A(colecInterdep<string, evento> &c, ifstream &f)
{
    int tamIn = tamanyo(c);
    string id, desc, dep, sup;
    int prio;

    getline(f, id);
    getline(f, desc);
    f >> prio;
    f.ignore(); // Ignorar el salto de línea después de leer prio
    getline(f, dep);
    getline(f, sup);

    evento e;
    crearEvento(desc, prio, e);

    if(dep == "INDependiente")
    {
        anyadirIndependiente(c, id, e);
    }
    else
    {
        anyadirDependiente(c, id, e, sup);
    }

    int tamFin = tamanyo(c);

    if(tamFin > tamIn)
    {
        cout << "INTRODUCIDO: [ " << id;
        if(dep == "DEPendiente")
        {
            cout << " -de-> " << sup; 
        }
        cout << " ] --- " << desc << " --- ( " << prio << " )" << endl;
        
    }
    else
    {
        cout << "NO INTRODUCIDO: [ " << id;
        if(dep == "DEPendiente")
        {
            cout << " -de-> " << sup; 
        }
        cout << " ] --- " << desc << " --- ( " << prio << " )" << endl;
    }
}

// Cambiar la información de un evento en la colección para un nombre dado
void C(colecInterdep<string, evento> &c, ifstream &f)
{
    string id, desc;
    int prio;

    getline(f, id);
    getline(f, desc);
    f >> prio;
    f.ignore(); // Ignorar el salto de línea después de leer prio

    if(!existe(id, c))
    {
        cout << "NO CAMBIADO: " << id << endl;
    }
    else
    {
        evento e = obtenerVal(id, c);
        cambiarDescripcion(e, desc);
        cambiarPrioridad(e, prio);
        
        if(existeIndependiente(id, c))
        {
            cout << "CAMBIADO: [ " << id << " --- " << obtenerNumDependientes(id, c) << " ]"
                 << " --- " << desc << " --- ( " << prio << " )" << endl;
        }
        else
        {
            cout << "CAMBIADO: [ " << id << " -de-> " << obtenerSupervisor(id, c) << " ;;; " << obtenerNumDependientes(id, c) << " ]"
                 << " --- " << desc << " --- ( " << prio << " )" << endl;
        }
    }
}

// Obtener toda la información relativa al evento de la colección correspondiente a un nombre dado
void O(colecInterdep<string, evento> &c, ifstream &f)
{
    string id;
    getline(f, id);

    if(!existe(id, c))
    {
        cout << "NO LOCALIZADO: " << id << endl;
    }
    else
    {
        evento e = obtenerVal(id, c);

        if(existeIndependiente(id, c))
        {
            cout << "CAMBIADO: [ " << id << " --- " << obtenerNumDependientes(id, c) << " ]"
                 << " --- " << descripcion(e) << " --- ( " << suPrioridad(e) << " )" << endl;
        }
        else
        {
            cout << "CAMBIADO: [ " << id << " -de-> " << obtenerSupervisor(id, c) << " ;;; " << obtenerNumDependientes(id, c) << " ]"
                 << " --- " << descripcion(e) << " --- ( " << suPrioridad(e) << " )" << endl;
        }
    }
}

// Existe algún evento relativo a un nombre dado
void E(colecInterdep<string, evento> &c, ifstream &f)
{
    string id;
    getline(f, id);

    if(existe(id, c))
    {
        if(existeIndependiente(id, c))
        {
            cout << "INDependiente: " << id << endl;
        }
        else
        {
            cout << "DEPendiente: " << id << endl;
        }
    }
    else{
        cout << "DESCONOCIDO: " << id << endl;
    }
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