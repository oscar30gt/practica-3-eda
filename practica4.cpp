/**
 * @file practica4.cpp
 * Practica 4 - Estructuras de Datos y Algoritmos
 * Grupo 422 - Curso 2025/2026
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 *
 * Programa principal de la práctica 4.
 *
 * Repositorio
 * https://github.com/oscar30gt/practica-3-eda (rama practica-4)
 */

#include <iostream>
#include <fstream>
#include <string>

#include "colecInterdep.hpp"
#include "evento.hpp"

using namespace std;

/*
 * Funciones que implementan las instrucciones del programa.
 * Cada función lee los argumentos necesarios de un flujo de
 * entrada `i` (si los necesita), actualiza la colección `c`
 * y escribe los resultados de la operación en un flujo de
 * salida `o`.
 */
void A(colecInterdep<string, evento> &c, ifstream &i, ofstream &o);
void C(colecInterdep<string, evento> &c, ifstream &i, ofstream &o);
void O(colecInterdep<string, evento> &c, ifstream &i, ofstream &o);
void E(colecInterdep<string, evento> &c, ifstream &i, ofstream &o);
void I(colecInterdep<string, evento> &c, ifstream &i, ofstream &o);
void D(colecInterdep<string, evento> &c, ifstream &i, ofstream &o);
void B(colecInterdep<string, evento> &c, ifstream &i, ofstream &o);
void LD(colecInterdep<string, evento> &c, ifstream &i, ofstream &o);
void LT(colecInterdep<string, evento> &c, ofstream &o);

/**
 * @brief Programa principal de la práctica 4.
 *
 * Lee las instrucciones de un fichero de entrada y las ejecuta sobre una
 * colección de eventos `colecInterdep<string, evento>`. Escribe de forma
 * formateada los resultados de las instrucciones en un fichero de salida.
 */
int main()
{
    // Inicializa la coleccion
    colecInterdep<string, evento> c;
    crear(c);

    // Abre el fichero de entrada
    ifstream entrada("entrada.txt");
    if (!entrada.is_open())
    {
        cerr << "Error al abrir el fichero de entrada." << endl;
        return 1;
    }

    // Abre el fichero de salida
    ofstream salida("salida.txt");
    if (!salida.is_open())
    {
        cerr << "Error al abrir el fichero de salida." << endl;
        return 1;
    }

    // Lee las instrucciones del fichero de entrada y las ejecuta
    string instruccion, salto;
    while (entrada >> instruccion)
    {
        getline(entrada, salto); // Ignorar el resto de la línea

        if (instruccion == "A")
        {
            A(c, entrada, salida);
        }
        else if (instruccion == "C")
        {
            C(c, entrada, salida);
        }
        else if (instruccion == "O")
        {
            O(c, entrada, salida);
        }
        else if (instruccion == "E")
        {
            E(c, entrada, salida);
        }
        else if (instruccion == "I")
        {
            I(c, entrada, salida);
        }
        else if (instruccion == "D")
        {
            D(c, entrada, salida);
        }
        else if (instruccion == "B")
        {
            B(c, entrada, salida);
        }
        else if (instruccion == "LD")
        {
            LD(c, entrada, salida);
        }
        else if (instruccion == "LT")
        {
            LT(c, salida);
        }
    }

    entrada.close();
    return 0;
}

// A: Añadir nuevo evento (5 argumentos: id del evento, descripción, prioridad,
// tipo (INDependiente/DEPendiente) e id del supervisor (si es dependiente))
void A(colecInterdep<string, evento> &c, ifstream &i, ofstream &o)
{
    string id, desc, dep, sup;
    int prio, tamInicial = tamanyo(c);

    getline(i, id);
    getline(i, desc);
    i >> prio;
    i.ignore(); // Ignorar el salto de línea después de leer prio
    getline(i, dep);
    getline(i, sup);

    evento e;
    crearEvento(desc, prio, e);

    if (dep == "INDependiente")
    {
        anyadirIndependiente(c, id, e);
    }
    else
    {
        anyadirDependiente(c, id, e, sup);
    }

    if (tamanyo(c) > tamInicial)
    {
        o << "INTRODUCIDO: [ " << id;
        if (dep == "DEPendiente")
        {
            o << " -de-> " << sup;
        }
        o << " ] --- " << desc << " --- ( " << prio << " )" << endl;
    }
    else
    {
        o << "NO INTRODUCIDO: [ " << id;
        if (dep == "DEPendiente")
        {
            o << " -de-> " << sup;
        }
        o << " ] --- " << desc << " --- ( " << prio << " )" << endl;
    }
}

// C: Cambiar la información de un evento (3 argumentos: id del evento, nueva
// descripción y nueva prioridad)
void C(colecInterdep<string, evento> &c, ifstream &i, ofstream &o)
{
    string id, desc;
    int prio;

    getline(i, id);
    getline(i, desc);
    i >> prio;
    i.ignore(); // Ignorar el salto de línea después de leer prio

    evento e;
    bool error;
    obtenerVal(id, c, e, error);

    if (error) // El elemento no existe
    {
        o << "NO CAMBIADO: " << id << endl;
    }
    else
    {
        cambiarDescripcion(e, desc);
        cambiarPrioridad(e, prio);
        actualizarVal(c, id, e, error);

        int numDep;
        obtenerNumDependientes(id, c, numDep, error);
        // El elemento siempre existe (comprobado antes)

        string sup;
        obtenerSupervisor(id, c, sup, error);

        if (error) // El elemento es independiente
        {
            o << "CAMBIADO: [ " << id << " --- " << numDep << " ]"
              << " --- " << desc << " --- ( " << prio << " )" << endl;
        }
        else // El elemento es dependiente
        {
            o << "CAMBIADO: [ " << id << " -de-> " << sup << " ;;; " << numDep << " ]"
              << " --- " << desc << " --- ( " << prio << " )" << endl;
        }
    }
}

// O: Obtener información de un evento (1 argumento: id del evento)
void O(colecInterdep<string, evento> &c, ifstream &i, ofstream &o)
{
    string id;
    getline(i, id);

    evento e;
    bool error;
    obtenerVal(id, c, e, error);

    if (error) // El elemento no existe
    {
        o << "NO LOCALIZADO: " << id << endl;
    }
    else
    {
        int numDep;
        obtenerNumDependientes(id, c, numDep, error);

        string sup;
        obtenerSupervisor(id, c, sup, error);

        if (error) // El elemento es independiente
        {
            o << "LOCALIZADO: [ " << id << " --- " << numDep << " ]"
              << " --- " << descripcion(e) << " --- ( " << suPrioridad(e) << " )"
              << endl;
        }
        else // El elemento es dependiente
        {
            o << "LOCALIZADO: [ " << id << " -de-> " << sup << " ;;; " << numDep
              << " ]"
              << " --- " << descripcion(e) << " --- ( " << suPrioridad(e) << " )"
              << endl;
        }
    }
}

// E: Existe el evento? (1 argumento: id del evento)
void E(colecInterdep<string, evento> &c, ifstream &i, ofstream &o)
{
    string id;
    getline(i, id);

    if (existeIndependiente(id, c))
    {
        o << "INDEPendiente: " << id << endl;
    }
    else if (existeDependiente(id, c))
    {
        o << "DEPendiente: " << id << endl;
    }
    else // No existe
    {
        o << "DESCONOCIDO: " << id << endl;
    }
}

// I: Hacer evento independiente (1 argumento: id del evento)
void I(colecInterdep<string, evento> &c, ifstream &i, ofstream &o)
{
    string id;
    getline(i, id);

    if (existeDependiente(id, c))
    {
        o << "INDEPENDIZADO: ";
        hacerIndependiente(c, id);
    }
    else if (existeIndependiente(id, c))
    {
        o << "YA ERA INDepend.: ";
    }
    else // No existe
    {
        o << "NO INDEPENDIZADO: ";
    }

    o << id << endl;
}

// D: Hacer dependiente (2 argumentos: id del evento e id del evento supervisor)
void D(colecInterdep<string, evento> &c, ifstream &i, ofstream &o)
{
    string dep, sup;
    getline(i, dep);
    getline(i, sup);

    if (existe(dep, c) && existe(sup, c))
    {
        o << "INTENTANDO hacer depend.: ";
        hacerDependiente(c, dep, sup);
    }
    else // No existe algun evento
    {
        o << "IMPOSIBLE hacer depend.: ";
    }

    o << dep << " -de-> " << sup << endl;
}

// B: Borrar evento (1 argumento: id del evento)
void B(colecInterdep<string, evento> &c, ifstream &i, ofstream &o)
{
    string id;
    getline(i, id);

    int tamAntes = tamanyo(c);
    borrar(id, c);

    if (tamanyo(c) < tamAntes)
    {
        o << "BORRADO: " << id << endl;
    }
    else // No se ha podido borrar
    {
        o << "NO BORRADO: " << id << endl;
    }
}

// LD: Listar eventos dependientes de un evento dado (1 argumento: id del
// evento)
void LD(colecInterdep<string, evento> &c, ifstream &i, ofstream &o)
{
    string id;
    getline(i, id);

    // Encabezado
    o << "****DEPENDIENTES: " << id << endl;

    evento ev;
    bool error;
    obtenerVal(id, c, ev, error);

    if (error) // No existe el evento
    {
        o << "****DESCONOCIDO" << endl;
        return;
    }
    else
    {
        // ==== Evento padre ====
        int numDep;
        obtenerNumDependientes(id, c, numDep, error);
        // El elemento siempre existe (comprobado antes)

        string sup;
        obtenerSupervisor(id, c, sup, error);

        if (error) // El elemento es independiente
        {
            o << "[ " << id << " --- " << numDep << " ] --- " << descripcion(ev)
              << " --- ( " << suPrioridad(ev) << " ) ****" << endl;
        }
        else // El elemento es dependiente
        {
            o << "[ " << id << " -de-> " << sup << " ;;; " << numDep << " ] --- "
              << descripcion(ev) << " --- ( " << suPrioridad(ev) << " ) ****" << endl;
        }

        // ==== Lista de dependientes ====
        iniciarIterador(c);
        int i = 1;
        while (existeSiguiente(c))
        {
            bool dep;
            siguienteDependiente(c, dep, error);
            // Dado que existe siguiente, no hay error

            if (dep) // Es dependiente
            {
                string sup;
                siguienteSuperior(c, sup, error);
                // Dado que es dependiente, no hay error

                if (sup == id) // Es dependiente del evento buscado
                {
                    evento evDep;
                    string idDep;
                    int numDepDep;
                    siguienteVal(c, evDep, error);
                    siguienteIdent(c, idDep, error);
                    siguienteNumDependientes(c, numDepDep, error);
                    // Dado que existe siguiente, no hay errores

                    o << "[" << i++ << " -> " << idDep << " -de-> " << id << " ;;; "
                      << numDepDep << " ] --- " << descripcion(evDep) << " --- ( "
                      << suPrioridad(evDep) << " ) ;;;;" << endl;
                }
            }

            avanzarIterador(c, error);
            // if (error) break; -> no hay siguiente
        }
    }

    o << "****FINAL dependientes -de-> " << id << endl;
}

// LT: Listar todos los eventos de la coleccion (0 argumentos)
void LT(colecInterdep<string, evento> &c, ofstream &o)
{
    o << "-----LISTADO: " << tamanyo(c) << endl;
    int i = 0;
    iniciarIterador(c);
    while (existeSiguiente(c))
    {
        i++;
        if (i>20)break;
        bool error;
        int numDep;
        evento ev;
        string id;

        siguienteVal(c, ev, error);
        siguienteIdent(c, id, error);
        siguienteNumDependientes(c, numDep, error);
        // Dado que existe siguiente, no hay errores

        string sup;
        siguienteSuperior(c, sup, error);

        if (error) // El elemento es independiente
        {
            o << "[ " << id << " --- " << numDep << " ] --- " << descripcion(ev)
              << " --- ( " << suPrioridad(ev) << " )" << endl;
        }
        else // El elemento es dependiente
        {
            o << "[ " << id << " -de-> " << sup << " ;;; " << numDep << " ] --- "
              << descripcion(ev) << " --- ( " << suPrioridad(ev) << " )" << endl;
        }

        avanzarIterador(c, error);
        // if (error) break; -> no hay siguiente
    }

    o << "-----" << endl;
}