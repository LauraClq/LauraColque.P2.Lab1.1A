/*
 * Input.h
 *
 *  Created on: 28 may 2022
 *      Author: Laura
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Defines.h"

/// @brief validates that the data is an int number.
///
/// @param refInt pointer that receives the number if the function is OK.
/// @param message message that the user receives.
/// @param errorMessage message if the user makes a mistake.
/// @param min minimum possible number.
/// @param max maximum possible number.
/// @param attempts attempts that the user has if they make a mistake.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int Utn_GetInt(int* refInt,char message[], char errorMessage[], int min ,int max, int attempts);

/// @brief validates that the data is a float number.
///
/// @param refFloat pointer that receives the number if the function is OK.
/// @param message message that the user receives.
/// @param errorMessage message if the user makes a mistake.
/// @param min minimum possible number.
/// @param max maximum possible number.
/// @param attempts attempts that the user has if they make a mistake.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int Utn_GetFloat(float* refFloat,char message[], char errorMessage[], int min ,int max, int attempts);

/// @brief receives a string that does not exceed the entered limit.
///
/// @param refAux the pointer where the string will be saved.
/// @param limit limit that the string cannot exceed.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int GetString(char* refAux, int limit);

/// @brief Gets the number that the user entered.
///
/// @param refAux the pointer where the number will be saved.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int GetInt(int* refAux);

/// @brief validates that the received string does not contain non-numeric characters.
///
/// @param refAux string to validate.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int IsInt(char* refAux);

/// @brief validates that the string is an int or a float number.
///
/// @param refAux pointer to validate.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int IsFloat(char* refAux);

/// @brief transform a string of characters to a float number.
///
/// @param refAux the pointer where the number will be saved.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int GetFloat(float* refAux);

/// @brief validates that the string only contains non-numeric characters.
///
/// @param refAux the pointer where the string will be saved.
/// @param limit limit of characters that the string can contain.
/// @param message message that the user receives.
/// @param errorMessage message if the user makes a mistake.
/// @param attempts attempts that the user has if they make a mistake.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int Utn_GetString(char* refAux, int limit, char message[], char errorMessage[], int attempts);

/// @brief validates that the string only contains non-numeric characters.
///
/// @param refAux pointer to validate.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int IsChar(char* refAux);

/// @brief validates do not exceed the limit of characters that the string can contain
///
/// @param refAux the pointer where the string will be saved.
/// @param limit limit of characters that the string can contain.
/// @param message message that the user receives.
/// @param errorMessage message if the user makes a mistake.
/// @param attempts attempts that the user has if they make a mistake.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int Utn_GetStringAlphanumeric(char* refAux, int limit, char message[], char errorMessage[], int attempts);

/// @brief validates that the string contains numeric and characters
///
/// @param str pointer to validate.
/// @return ERROR(-1) if error or FUNCIONO(0) if OK.
int esAlfaNumerico(char str[]);

/// @brief validates that the char contains s or n
///
/// @param mensaje message that the user receives.
/// @return variable of type char s (yes) or n (no)
char confirmacion(char mensaje[]);

#endif /* INPUT_H_ */
