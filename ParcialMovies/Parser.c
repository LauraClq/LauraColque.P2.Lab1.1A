#include "Parser.h"

int parser_MovieFromText(FILE* pFile, LinkedList* pListaMovies)
{
    int retorno = ERROR;
    int flagLectura = NADA;
    char buffer[4][40];
    int cant;
    eMovie* pMovie = NULL;

    pFile = fopen("movies.csv","r");
    if(pFile == NULL)
    {
        printf("Error en abrir el archivo.\n");
    }

    if(pFile != NULL && pListaMovies != NULL)
    {
        do
        {
            if(!flagLectura)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]);
                flagLectura = CARGO;
            }

            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cant == 4)
            {
                pMovie = new_MovieParam(buffer[0],buffer[1],buffer[2],buffer[3]);

                if(pMovie != NULL)
                {
                    ll_add(pListaMovies,pMovie);
                    retorno = 1;
                }
            }
            else
            {
                moviesDestroy(pMovie);
                break;
            }

        }
        while(!feof(pFile));
    }
    fclose(pFile);

    return retorno;
}
