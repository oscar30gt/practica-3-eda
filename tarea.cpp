/**
 * @file tarea.cpp
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 */

#include <string>
#include "tarea.hpp"

using namespace std;

/**
 * @brief Inicializa una tarea `t` con los valores dados.
 * @param[out] t Tarea a inicializar.
 * @param[in] nom Nombre de la tarea.
 * @param[in] desc Descripcion de la tarea.
 * @param[in] uni Unidad de tiempo en la que se miden los tiempos de la tarea.
 * @param[in] esti Tiempo estimado para completar la tarea. Debe ser mayor que 0.
 * @param[out] error Indica si se ha producido un error (esti <= 0).
 */
void crearTarea(tarea &t, const string &nom, const string &desc, const string &uni, const double &esti, bool &error)
{
    error = esti <= 0;
    if (!error)
    {
        t.nombre = nom;
        t.descripcion = desc;
        t.unidadTiempo = uni;
        t.tiempoEstimado = esti;
        t.tiempoEmpleado = 0.0;
    }
}

/**
 * @brief Obtiene el nombre de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene el nombre.
 * @returns Nombre de la tarea.
 */
string nombre(const tarea &t)
{
    return t.nombre;
}

/**
 * @brief Obtiene la descripcion de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene la descripcion.
 * @returns Descripcion de la tarea.
 */
string descripcion(const tarea &t)
{
    return t.descripcion;
}

/**
 * @brief Obtiene la unidad de tiempo de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene la unidad de tiempo.
 * @returns Unidad de tiempo de la tarea.
 */
string unidad(const tarea &t)
{
    return t.unidadTiempo;
}

/**
 * @brief Obtiene el tiempo estimado de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene el tiempo estimado.
 * @returns Tiempo estimado de la tarea.
 */
double estimacion(const tarea &t)
{
    return t.tiempoEstimado;
}

/**
 * @brief Obtiene el tiempo invertido de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene el tiempo invertido.
 * @returns Tiempo invertido de la tarea.
 */
double invertido(const tarea &t)
{
    return t.tiempoEmpleado;
}

/**
 * @brief Cambia el nombre de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] n2 Nuevo nombre de la tarea.
 */
void cambiarNombre(tarea &t, const string &n2)
{
    t.nombre = n2;
}

/**
 * @brief Cambia la descripcion de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] d2 Nueva descripcion de la tarea.
 */
void cambiarDescripcion(tarea &t, const string &d2)
{
    t.descripcion = d2;
}

/**
 * @brief Cambia la unidad de tiempo de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] u2 Nueva unidad de tiempo de la tarea.
 */
void cambiarUnidad(tarea &t, const string &u2)
{
    t.unidadTiempo = u2;
}

/**
 * @brief Cambia el tiempo estimado de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] estiNuevo Nuevo tiempo estimado de la tarea. Debe ser mayor que 0.
 * @param[out] error Indica si se ha producido un error (estiNuevo <= 0).
 */
void cambiarTiempoEstimado(tarea &t, const double &estiNuevo, bool &error)
{
    error = estiNuevo <= 0;
    if (!error)
    {
        t.tiempoEstimado = estiNuevo;
    }
}

/**
 * @brief Cambia el tiempo invertido de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] inverNuevo Nuevo tiempo invertido de la tarea. Debe ser mayor o igual que 0.
 * @param[out] error Indica si se ha producido un error (inverNuevo <= 0).
 */
void cambiarTiempoInvertido(tarea &t, const double &inverNuevo, bool &error)
{
    error = inverNuevo <= 0;
    if (!error)
    {
        t.tiempoEmpleado = inverNuevo;
    }
}