#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Menu.h"
#include "Defines.h"

int main()
{
    LinkedList* listaMovies = ll_newLinkedList();
    LinkedList* listaOrdenada = ll_newLinkedList();
    char archivo[TAM];
    int flagCarga = NADA;
    int opcion;
    char salir;
    int flagRating = NADA;
    int flagGenero = NADA;
    int flagOrdenado = NADA;

    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            //cargar archivo
            if(!flagCarga)
            {
                printf("Ingrese el nombre del archivo (movies.csv): ");
                fflush(stdin);
                gets(archivo);

                if(controller_loadFromText(archivo,listaMovies))
                {
                    printf("Se cargo el archivo exitosamente.\n");
                    flagCarga = CARGO;
                }
                else
                {
                    printf("Ocurrio un error en la carga del archivo.\n");
                }
            }
            break;
        case 2:
            //imprimir lista
            if(!ll_isEmpty(listaMovies))
            {
                controller_ListMovies(listaMovies);
            }
            else
            {
                printf("No se puede mostrar las peliculas si no se cargo el archivo.\n");
            }
            break;
        case 3:
            //asignar ratings
            if(!ll_isEmpty(listaMovies))
            {
                if(controller_asignarRatings(listaMovies))
                {
                    flagRating = CARGO;
                }
                else
                {
                    printf("Ocurrio un error en los parametros.\n");
                }
            }
            else
            {
                printf("No se puede asignar tiempos si no se cargo el archivo.\n");
            }
            break;
        case 4:
            //asignar generos
            if(!ll_isEmpty(listaMovies))
            {
                if(controller_asignarGeneros(listaMovies))
                {
                    flagGenero = CARGO;
                }
                else
                {
                    printf("Ocurrio un error en los parametros.\n");
                }
            }
            else
            {
                printf("No se puede asignar ratings si no se cargo el archivo.\n");
            }
            break;
        case 5:
            //filtrar por genero
            if(!ll_isEmpty(listaMovies))
            {
                if(flagGenero)
                {
                    controler_filtrarPorGenero(listaMovies);
                }
                else
                {
                    printf("No se puede filtrar los generos si no se asigno generos.\n");
                }
            }
            else
            {
                printf("No se puede filtrar los tipos de genero si no se cargo el archivo.\n");
            }
            break;
        case 6:
            //Ordenar peliculas
            if(!ll_isEmpty(listaMovies))
            {
                if(flagRating && flagGenero)
                {
                    listaOrdenada = controller_sortGeneroRating(listaMovies);
                    flagOrdenado = CARGO;
                }
                else
                {
                    printf("No se puede mostrar la lista ordenada si no se asigno los ratings y los generos.\n");
                }
            }
            else
            {
                printf("No se puede mostrar la lista ordenada si no se cargo el archivo\n");
            }
            break;
        case 7:
            //Guradar en un archivo de texto la lista anterior
            if(!ll_isEmpty(listaMovies))
            {
                if(flagOrdenado)
                {
                    controller_saveAsText("movieOrdenas.csv",listaOrdenada);
                    printf("Guardando lista...\n");
                }
                else
                {
                    printf("No se pueder guardar la lista ordenada si no genero una en la opcion 6.\n");
                }
            }
            else
            {
                printf("No se puede guardar la lista ordenada si no se cargo el archivo\n");
            }
            break;
        case 8:
            salir = confirmacion("Desea salir del programa? s - n: ");
            if(salir == 's')
            {
                printf("Salida exitosa!\n");
                ll_deleteLinkedList(listaMovies);
            }
            break;
        default:
            printf("Opcion invalida elija una opcion de 1 al 8\n");
            break;
        }
        system("pause");
    }
    while(salir != 's');

    return 0;
}
