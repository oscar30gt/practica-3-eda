/**
 * @file tarea.hpp
 *
 * @authors
 * Hugo García Sánchez (930108)
 * Óscar Grimal Torres (926897)
 */

#ifndef TAREA_HPP
#define TAREA_HPP

#include <string>

using namespace std;

// PREDECLARACION DEL TAD tarea (inicio INTERFAZ)

/**
 * @brief Representa un tarea, la cual se define por un nombre y una descripcion, ademas
 * de un tiempo estimado y un tiempo empleado de realizacion.
 */
struct tarea;

/**
 * @brief Inicializa una tarea `t` con los valores dados.
 * @param[out] t Tarea a inicializar.
 * @param[in] nom Nombre de la tarea.
 * @param[in] desc Descripcion de la tarea.
 * @param[in] uni Unidad de tiempo en la que se miden los tiempos de la tarea.
 * @param[in] esti Tiempo estimado para completar la tarea. Debe ser mayor que 0.
 * @param[out] error Indica si se ha producido un error (esti <= 0).
 */
void crearTarea(tarea &t, const string &nom, const string &desc, const string &uni, const double &esti, bool &error);

/**
 * @brief Obtiene el nombre de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene el nombre.
 * @returns Nombre de la tarea.
 */
string nombre(const tarea &t);

/**
 * @brief Obtiene la descripcion de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene la descripcion.
 * @returns Descripcion de la tarea.
 */
string descripcion(const tarea &t);

/**
 * @brief Obtiene la unidad de tiempo de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene la unidad de tiempo.
 * @returns Unidad de tiempo de la tarea.
 */
string unidad(const tarea &t);

/**
 * @brief Obtiene el tiempo estimado de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene el tiempo estimado.
 * @returns Tiempo estimado de la tarea.
 */
double estimacion(const tarea &t);

/**
 * @brief Obtiene el tiempo invertido de la tarea `t`.
 * @param[in] t Tarea de la que se obtiene el tiempo invertido.
 * @returns Tiempo invertido de la tarea.
 */
double invertido(const tarea &t);

/**
 * @brief Cambia el nombre de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] n2 Nuevo nombre de la tarea.
 */
void cambiarNombre(tarea &t, const string &n2);

/**
 * @brief Cambia la descripcion de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] d2 Nueva descripcion de la tarea.
 */
void cambiarDescripcion(tarea &t, const string &d2);

/**
 * @brief Cambia la unidad de tiempo de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] u2 Nueva unidad de tiempo de la tarea.
 */
void cambiarUnidad(tarea &t, const string &u2);

/**
 * @brief Cambia el tiempo estimado de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] estiNuevo Nuevo tiempo estimado de la tarea. Debe ser mayor que 0.
 * @param[out] error Indica si se ha producido un error (estiNuevo <= 0).
 */
void cambiarTiempoEstimado(tarea &t, const double &estiNuevo, bool &error);

/**
 * @brief Cambia el tiempo invertido de la tarea `t`.
 * @param[in, out] t Tarea a modificar.
 * @param[in] inverNuevo Nuevo tiempo invertido de la tarea. Debe ser mayor o igual que 0.
 * @param[out] error Indica si se ha producido un error (inverNuevo <= 0).
 */
void cambiarTiempoInvertido(tarea &t, const double &inverNuevo, bool &error);

// FIN PREDECLARACION DEL TAD tarea (fin INTERFAZ)

// DECLARACION DEL TAD tarea

/**
 * @brief Representa un tarea, la cual se define por un nombre y una descripcion, ademas
 * de un tiempo estimado y un tiempo empleado de realizacion.
 */
struct tarea
{
    friend void crearTarea(tarea &t, const string &nom, const string &desc, const string &uni, const double &esti, bool &error);
    friend string nombre(const tarea &t);
    friend string descripcion(const tarea &t);
    friend string unidad(const tarea &t);
    friend double estimacion(const tarea &t);
    friend double invertido(const tarea &t);
    friend void cambiarNombre(tarea &t, const string &n2);
    friend void cambiarDescripcion(tarea &t, const string &d2);
    friend void cambiarUnidad(tarea &t, const string &u2);
    friend void cambiarTiempoEstimado(tarea &t, const double &estiNuevo, bool &error);
    friend void cambiarTiempoInvertido(tarea &t, const double &inverNuevo, bool &error);
    /* El TAD tarea esta implementado como una tupla simple con cinco campos privados:
       `nombre`, `descripcion`, `unidadTiempo`, `tiempoEstimado` y `tiempoEmpleado`. */

private:
    /** Nombre de la tarea */
    string nombre;

    /** Descripcion de la tarea */
    string descripcion;

    /** Unidad de tiempo en la que se miden `tiempoEstimado` y `tiempoEmpleado` */
    string unidadTiempo;

    /** Tiempo estimado para completar la tarea (en `unidadTiempo`) */
    double tiempoEstimado;

    /** Tiempo ya empleado en la tarea (en `unidadTiempo`) */
    double tiempoEmpleado;
};

// FIN DECLARACION DEL TAD tarea

#endif // TAREA_HPP