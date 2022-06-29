#include "Menu.h"

int menu()
{
    int opcion;
    system("cls");
	printf("****************************\n");
	printf("Menu:\n\n");
	printf(" 1. Cargar archivo.\n");
	printf(" 2. Imprimir lista.\n");
	printf(" 3. Asignar rating.\n");
	printf(" 4. Asignar genero.\n");
	printf(" 5. Filtrar por genero.\n");
	printf(" 6. Ordenar peliculas.\n");
	printf(" 7. Guardar peliculas.\n");
	printf(" 8. Salir.\n\n");
	printf("****************************\n");

	if(Utn_GetInt(&opcion, "\nElija una opcion : ","\nError,dato invalido ingrese de 1 a 8.\n", MIN_OPTION,MAX_OPTION,ATTEMPTS) == ERROR)
	{
		opcion = ERROR;
	}

	return opcion;
}

int menuGenero()
{
    int opcion;
    system("cls");
	printf("*******************\n");
	printf("Menu:\n\n");
	printf(" 1. Drama.\n");
	printf(" 2. Accion.\n");
	printf(" 3. Comedia.\n");
	printf(" 4. Terror.\n");
	printf(" 5. Salir.\n");
	printf("******************\n");

	if(Utn_GetInt(&opcion, "\nElija de que tipo de genero quiere filtrar: ","\nError,dato invalido ingrese de 1 a 5.\n", MIN_OPTION,MAX_OPTION_G,ATTEMPTS) == ERROR)
	{
		opcion = ERROR;
	}

	return opcion;
}
