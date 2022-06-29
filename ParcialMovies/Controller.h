#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Movies.h"
#include "Parser.h"
#include "Menu.h"
#include "Defines.h"

/** \brief Carga los datos
 * \param path char* nombre del archivo a cargar
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList donde se crea la lista de peliculas
 * \return int 0 ERROR, 1 si OK
 */
int controller_loadFromText(char* path, LinkedList* pListaMovies);

/** \brief Listar peliculas
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList donde muestra las peliculas
 * \return int 0 ERROR, 1 si OK
 */
int controller_ListMovies(LinkedList* pListaMovies);

/** \brief Asigna valores flotantes random entre 1 y 10 como rating de cada pelicula
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 0 ERROR, 1 si OK
 */
int controller_asignarRatings(LinkedList* pListaMovies);

/** \brief Asigna valores de cadena de caracteres segun el numero random del 1 al 4 como genero de cada pelicula
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 0 ERROR, 1 si OK
 */
int controller_asignarGeneros(LinkedList* pListaMovies);

/** \brief Muestra un menuGenero y le pide al usuario que seleccione un genero a filtrar, y luego genera un archivo de esa lista de peliculas filtradas
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 0 ERROR, 1 si OK
 */
int controler_filtrarPorGenero(LinkedList* pListaMovies);

//Filtros por genero

/** \brief Filtra el genero drama, lo muestra y lo guarda un nuevo archivo
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 0 ERROR, 1 si OK
 */
int archivo_filtroDrama(LinkedList* pListaMovies, LinkedList* pListaGenero);

/** \brief Filtra el genero comedia, lo muestra y lo guarda un nuevo archivo
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 0 ERROR, 1 si OK
 */
int archivo_filtroComedia(LinkedList* pListaMovies, LinkedList* pListaGenero);

/** \brief Filtra el genero accion, lo muestra y lo guarda un nuevo archivo
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \return int 0 ERROR, 1 si OK
 */
int archivo_filtroAccion(LinkedList* pListaMovies, LinkedList* pListaGenero);

/** \brief Filtra el genero terror, lo muestra y lo guarda un nuevo archivo
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList con la lista de peliculas
 * \param pListaGenero LinkedList* Puntero a estructura LinkedList
 * \return int 0 ERROR, 1 si OK
 */
int archivo_filtroTerror(LinkedList* pListaMovies, LinkedList* pListaGenero);

//Guarda el archvio de texto
/** \brief Guarda los datos de las peliculas en un archivo
 * \param path char* nombre del archivo donde se guardarán los datos
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList donde se crea la lista de peliculas
 * \return int 0 ERROR, 1 si OK
 */
int controller_saveAsText(char* path, LinkedList* pListaMovies);

//Ordenamiento de genero y es el mismo por rating
/** \brief Ordenar peliculas por genero y ante igualdad lo ordena por rating descendente
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList donde se ordenan peliculas
 * \return LinkedList* Puntero a LinkedList con la nueva lista ordenada
 */
LinkedList* controller_sortGeneroRating(LinkedList* pListaMovies);

#endif // CONTROLLER_H_INCLUDED
