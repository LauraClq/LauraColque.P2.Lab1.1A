#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"
#include "Input.h"

/** \brief Muetra un menu
 * \return retorna la opcion elegida o 0 de ERROR
 */
int menu();

/** \brief Muestra un menu de genero para filtrar
 * \return retorna la opcion elegida o 0 de ERROR
 */
int menuGenero();

#endif // MENU_H_INCLUDED
