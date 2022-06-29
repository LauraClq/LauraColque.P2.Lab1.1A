#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"
#include "Movies.h"
#include "Defines.h"

/** \brief Parsea los datos de las peliculas desde el archivo movies.csv (modo texto).
 * \param pFile FILE* archivo a parsear
 * \param pListaMovies LinkedList* Puntero a estructura LinkedList donde se crea la lista de peliculas
 * \return int 0 ERROR, 1 si OK
 */
int parser_MovieFromText(FILE* pFile , LinkedList* pListaMovies);

#endif // PARSER_H_INCLUDED
