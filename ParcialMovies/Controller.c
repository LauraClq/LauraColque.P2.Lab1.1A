#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pListaMovies)
{
    int retorno = ERROR;
    FILE* pFile;

    if(path != NULL && pListaMovies)
    {
        pFile = fopen(path,"r");
        if(pFile != NULL)
        {
            if(parser_MovieFromText(pFile,pListaMovies))
            {
                retorno = OK;
            }
            else
            {
                printf("Ocurrio un error en el parseo.\n");
            }
        }
        else
        {
            printf("Ocurrio un error al abrir el archivo.\n");
        }
        fclose(pFile);
    }

    return retorno;
}

int controller_ListMovies(LinkedList* pListaMovies)
{
    int retorno = ERROR;
    int tam;
    eMovie* pMovies = NULL;

    if(pListaMovies != NULL)
    {
        tam = ll_len(pListaMovies);

        printf("\n                 *** LISTA DE PELICULAS ***\n");
        printf(" ----------------------------------------------------------------\n");
        printf(" | ID  |              TITULO            |    GENERO    | RATING |\n");
        printf(" ----------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            pMovies = (eMovie*) ll_get(pListaMovies,i);
            if(pMovies != NULL)
            {
                movie_printOne(pMovies);
                retorno = OK;
            }
        }
        printf(" |_____|________________________________|______________|________|\n");
        printf("\n\n");

    }
    else
    {
        printf("Ocurrio un error en mostrar las peliculas.\n");
    }

    return retorno;
}

int controller_asignarRatings(LinkedList* pListaMovies)
{
    int retorno = ERROR;
    LinkedList* listaRatings = NULL;

    if(pListaMovies != NULL)
    {
        listaRatings = ll_map(pListaMovies,asignarRatingsAleatorios);

        if(listaRatings != NULL)
        {
            retorno = OK;
            controller_ListMovies(listaRatings);
        }
    }
    return retorno;
}

int controller_asignarGeneros(LinkedList* pListaMovies)
{
    int retorno = ERROR;
    LinkedList* listaGeneros = NULL;

    if(pListaMovies != NULL)
    {
        listaGeneros = ll_map(pListaMovies,asignarGeneros);

        if(listaGeneros != NULL)
        {
            retorno = OK;
            controller_ListMovies(listaGeneros);
        }
    }
    return retorno;
}

int controler_filtrarPorGenero(LinkedList* pListaMovies)
{
    int retorno = ERROR;
    int opcion;
    LinkedList* listaGenero = NULL;

    if(pListaMovies != NULL)
    {
        listaGenero = ll_newLinkedList();

        if(listaGenero != NULL)
        {
                opcion = menuGenero();
                switch(opcion)
                {
                case 1:
                    if(archivo_filtroDrama(pListaMovies,listaGenero))
                    {
                        printf("Archivo filtrado por drama con exito.\n");
                    }
                    else
                    {
                        printf("Ocurrio un error en los parametros.\n");
                    }
                    break;
                case 2:
                    if(archivo_filtroAccion(pListaMovies,listaGenero))
                    {
                        printf("Archivo filtrado por accion con exito.\n");
                    }
                    else
                    {
                        printf("Ocurrio un error en los parametros.\n");
                    }
                    break;
                case 3:
                    if(archivo_filtroComedia(pListaMovies,listaGenero))
                    {
                        printf("Archivo filtrado por comedia con exito.\n");
                    }
                    else
                    {
                        printf("Ocurrio un error en los parametros.\n");
                    }
                    break;
                case 4:
                    if(archivo_filtroTerror(pListaMovies,listaGenero))
                    {
                        printf("Archivo filtrado por terror con exito.\n");
                    }
                    else
                    {
                        printf("Ocurrio un error en los parametros.\n");
                    }
                    break;
                case 5:
                    printf("Se cancela el filtrado.\n");
                    break;
                default:
                    printf("Opcion incorrecta solo elija de 1 al 5.\n");
                    break;
                }
            retorno = OK;
        }
    }

    return retorno;
}

int archivo_filtroDrama(LinkedList* pListaMovies, LinkedList* pListaGenero)
{
    int retorno = ERROR;

    if(pListaMovies != NULL && pListaGenero != NULL)
    {
        pListaGenero = ll_filter(pListaMovies,filtroDrama);
        controller_ListMovies(pListaGenero);
        if(controller_saveAsText("generoDrama.csv",pListaGenero))
        {
            printf("Guardando el archivo drama...\n");
            retorno = OK;
        }
    }

    return retorno;
}

int archivo_filtroComedia(LinkedList* pListaMovies, LinkedList* pListaGenero)
{
    int retorno = ERROR;

    if(pListaMovies != NULL && pListaGenero != NULL)
    {
        pListaGenero = ll_filter(pListaMovies,filtroComedia);
        controller_ListMovies(pListaGenero);
        if(controller_saveAsText("generoComedia.csv",pListaGenero))
        {
            printf("Guardando el archivo comedia...\n");
            retorno = OK;
        }
    }

    return retorno;
}

int archivo_filtroAccion(LinkedList* pListaMovies, LinkedList* pListaGenero)
{
    int retorno = ERROR;

    if(pListaMovies != NULL && pListaGenero != NULL)
    {
        pListaGenero = ll_filter(pListaMovies,filtroAccion);
        controller_ListMovies(pListaGenero);
        if(controller_saveAsText("generoAccion.csv",pListaGenero))
        {
           printf("Guardando el archivo acccion...\n");
           retorno = OK;
        }
    }

    return retorno;
}

int archivo_filtroTerror(LinkedList* pListaMovies, LinkedList* pListaGenero)
{
    int retorno = ERROR;

    if(pListaMovies != NULL && pListaGenero != NULL)
    {
        pListaGenero = ll_filter(pListaMovies,filtroTerror);
        controller_ListMovies(pListaGenero);
        if(controller_saveAsText("generoTerror.csv",pListaGenero))
        {
            printf("Guardando el archivo terror...\n");
            retorno = OK;
        }
    }

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pListaMovies)
{
    int retorno = ERROR;
    int tam;
    eMovie* pMovies = NULL;

    int id;
    char titulo[30];
    char genero[20];
    float rating;

    if(path != NULL && pListaMovies != NULL)
    {
        FILE* pFile = fopen(path,"w");
        tam = ll_len(pListaMovies);
        pMovies = new_Movie();

        fprintf(pFile,"id_peli,titulo,genero,rating\n");

        for(int i=0; i<tam; i++)
        {
            pMovies = ll_get(pListaMovies,i);

            if(pMovies != NULL)
            {
                movieGetId(pMovies,&id);
                movieGetTitulo(pMovies,titulo);
                movieGetGenero(pMovies,genero);
                movieGetRating(pMovies,&rating);

                fprintf(pFile,"%d,%s,%s,%.1f\n",id,titulo,genero,rating);
                retorno = OK;
            }
        }
        fclose(pFile);
    }

    return retorno;
}

LinkedList* controller_sortGeneroRating(LinkedList* pListaMovies)
{
    LinkedList* auxMovie = NULL;

    if(pListaMovies != NULL)
    {
        auxMovie = ll_clone(pListaMovies);

        printf("\n\n             Peliculas ordenas por genero y rating \n");
        printf("          ---------------------------------------------\n");

        if(!ll_sort(auxMovie,movie_sortGeneroRating,1))
        {
            controller_ListMovies(auxMovie);
        }
        else
        {
            printf("Ocurrio un error en ordenar.\n");
        }

    }

    return auxMovie;
}
