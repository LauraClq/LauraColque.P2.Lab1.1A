#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Defines.h"

typedef struct
{
	int id;
	char titulo[30];
	char genero[30];
	float rating;

}eMovie;

// Constructores
 /** \brief Inicializa una nueva pelicula
 * \return eMovie* La dirección de memoria de la nueva pelicula creada
 */
eMovie* new_Movie();

/** \brief Asigna valores a una pelicula
 * \param idStr tipo char* Cadena de caracteres del ID de la pelicula
 * \param titulo tipo char* Cadena de caracteres del titulo de la pelicula
 * \param genero tipo char* Cadena de caracteres del genero de la pelicula
 * \param ratingS tipo char* Cadena de caracteres del rating de la pelicula
 * \return eMovie* La dirección de memoria de la pelicula hardcodeada
 */
eMovie* new_MovieParam(char* idStr, char* titulo, char* genero, char* ratingStr);

//Destructor
/** \brief Libera la memoria dinámica donde se guardaba una pelicula
 * \return void No retorna nada
 */
void moviesDestroy(eMovie* movie);

//Setters
/** \brief Asigna el valor del id a la pelicula
 * \param  movie Puntero a estructura eMovie a la cual se asignará el id
 * \param id int El valor del id a asignar
 * \return int 0 ERROR, 1 si OK
 */
int movieSetId(eMovie* movie, int id);

/** \brief Asigna el valor del titutlo a la pelicula
 * \param movie Puntero a estructura eMovie a la cual se asignará el titulo
 * \param titulo char El valor del titulo a asignar
 * \return int 0 ERROR, 1 si OK
 */
int movieSetTitulo(eMovie* movie, char* titulo);

/** \brief Asigna el valor del genero a la pelicula
 * \param movie Puntero a estructura eMovie a la cual se asignará el titulo
 * \param genero char El valor del genreo a asignar
 * \return int 0 ERROR, 1 si OK
 */
int movieSetGenero(eMovie* movie, char* genero);

/** \brief Asigna el valor del rating a la pelicula
 * \param movie Puntero a estructura eMovie a la cual se asignará el titulo
 * \param rating float El valor del rating a asignar
 * \return int 0 ERROR, 1 si OK
 */
int movieSetRating(eMovie* movie, float rating);

//Getters
/** \brief Busca y obtiene el valor del id de una pelicula
 * \param movie Puntero a estructura eMovie de la cual se obtiene el id
 * \param id int* Puntero a entero del ID de la pelicula
 * \return int 0 ERROR, 1 si OK
 */
int movieGetId(eMovie* movie, int* id);

/** \brief Busca y obtiene el valor del titulo de una pelicula
 * \param movie Puntero a estructura eMovie de la cual se obtiene el titulo
 * \param titulo char* Puntero a char titulo de la pelicula
 * \return int 0 ERROR, 1 si OK
 */
int movieGetTitulo(eMovie* movie, char* titulo);

/** \brief Busca y obtiene el valor del genero de una pelicula
 * \param movie Puntero a estructura eMovie de la cual se obtiene el genreo
 * \param genero char* Puntero a un char genero de la pelicula
 * \return int 0 ERROR, 1 si OK
 */
int movieGetGenero(eMovie* movie, char* genero);

/** \brief Busca y obtiene el valor del rating de una pelicula
 * \param movie Puntero a estructura eMovie de la cual se obtiene el genreo
 * \param rating float8 Puntero a un flota rating de la pelicula
 * \return int 0 ERROR, 1 si OK
 */
int movieGetRating(eMovie* movie, float* rating);

//Imprimir lista
/** \brief Lista una unica pelicula
 * \param oneMovie La pelicula a listar
 * \return void No retorna nada
 */
void movie_printOne(eMovie* oneMovie);

//Asignar ratings
/** \brief Asigna ratings random flotantes de 1 decimal entre 1 y 10
 * \param pElemento void* Puntero a void de película que luego se castea
 * \return void* Retorna puntero a void con la pelicula con el rating ya asignado
 */
void* asignarRatingsAleatorios(void* pElemento);

//Asignar Generos
/** \brief Asigna ratings random flotantes de 1 decimal entre 1 y 4
 * \param pElemento void* Puntero a void de película que luego se castea
 * \return void* Retorna puntero a void con la pelicula con el rating ya asignado
 */
void* asignarGeneros(void* pElemento);

//Filtros Tipo Genero
/** \brief Filtra las peliculas de genero drama
 * \param pElementoa void* Puntero a void de la pelicula que luego se castea
 * \return int 0 ERROR, 1 si OK
 */
int filtroDrama(void* pElemento);

/** \brief Filtra las peliculas de genero comedia
 * \param pElementoa void* Puntero a void de la pelicula que luego se castea
 * \return int 0 ERROR, 1 si OK
 */
int filtroComedia(void* pElemento);

/** \brief Filtra las peliculas de genero acccion
 * \param pElementoa void* Puntero a void de la pelicula que luego se castea
 * \return int 0 ERROR, 1 si OK
 */
int filtroAccion(void* pElemento);

/** \brief Filtra las peliculas de genero terror
 * \param pElementoa void* Puntero a void de la pelicula que luego se castea
 * \return int 0 ERROR, 1 si OK
 */
int filtroTerror(void* pElemento);

//Sort genero y rating
/** \brief los ordena por genreo y ratonf
 * \param movie1 y movie2 elemtos a castaer
 * \return int 0 ERROR, 1 si OK
 */
int movie_sortGeneroRating(void* movie1, void* movie2);

#endif // MOVIES_H_INCLUDED
