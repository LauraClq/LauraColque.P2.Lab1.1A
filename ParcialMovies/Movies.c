#include "Movies.h"
#include <time.h>

eMovie* new_Movie()
{
    eMovie* nuevaMovie = (eMovie*) calloc(1,sizeof(eMovie));
    return nuevaMovie;
}

eMovie* new_MovieParam(char* idStr, char* titulo, char* genero, char* ratingStr)
{
    eMovie* nuevaMovie = new_Movie();

    int id;
    float rating;
    id = atoi(idStr);
    rating = atof(ratingStr);

    if(nuevaMovie != NULL)
    {
        if(!(movieSetId(nuevaMovie, id) && movieSetTitulo(nuevaMovie, titulo) &&
            movieSetGenero(nuevaMovie, genero) && movieSetRating(nuevaMovie, rating)))
        {
            moviesDestroy(nuevaMovie);
            nuevaMovie = NULL;
        }
    }

    return nuevaMovie;
}

void moviesDestroy(eMovie* movie)
{
    if(movie != NULL)
    {
        free(movie);
    }
}

int movieSetId(eMovie* movie, int id)
{
    int retorno = ERROR;

    if(movie != NULL && id >= MIN_ID)
    {
        movie->id = id;
        retorno = OK;
    }

    return retorno;
}

int movieSetTitulo(eMovie* movie, char* titulo)
{
    int retorno = ERROR;

    if(movie != NULL && titulo != NULL && strlen(titulo) < MAX_T && strlen(titulo) > MIN)
    {
        strcpy(movie->titulo, titulo);
        strlwr(movie->titulo);
        (movie->titulo)[0] = toupper((movie->titulo)[0]);

        retorno = OK;
    }

    return retorno;
}

int movieSetGenero(eMovie* movie, char* genero)
{
    int retorno = ERROR;

    if(movie != NULL && genero != NULL && strlen(genero) < MAX_G && strlen(genero) > MIN)
    {
        strcpy(movie->genero, genero);
        strlwr(movie->genero);
        (movie->genero)[0] = toupper((movie->genero)[0]);

        retorno = OK;
    }

    return retorno;
}

int movieSetRating(eMovie* movie, float rating)
{
    int retorno = ERROR;

    if(movie != NULL && rating >= MIN_R && rating <= MAX_R)
    {
        movie->rating = rating;
        retorno = OK;
    }

    return retorno;
}

int movieGetId(eMovie* movie, int* id)
{
    int retorno = ERROR;

    if(movie != NULL && id != NULL)
    {
        *id = movie->id;
        retorno = OK;
    }

    return retorno;
}

int movieGetTitulo(eMovie* movie, char* titulo)
{
    int retorno = ERROR;

    if(movie != NULL && titulo != NULL)
    {
        strcpy(titulo, movie->titulo);
        retorno = OK;
    }

    return retorno;
}

int movieGetGenero(eMovie* movie, char* genero)
{
    int retorno = ERROR;

    if(movie != NULL && genero != NULL)
    {
        strcpy(genero, movie->genero);
        retorno = OK;
    }

    return retorno;
}

int movieGetRating(eMovie* movie, float* rating)
{
    int retorno = ERROR;

    if(movie != NULL && rating != NULL)
    {
        *rating = movie->rating;
        retorno = OK;
    }

    return retorno;
}

void movie_printOne(eMovie* oneMovie)
{
    int id;
    char titulo[30];
    char genero[30];
    float rating;

    if(oneMovie != NULL)
    {
        movieGetId(oneMovie,&id);
        movieGetTitulo(oneMovie,titulo);
        movieGetGenero(oneMovie,genero);
        movieGetRating(oneMovie,&rating);

        printf(" | %-3d | %-30s | %-12s |   %-1.1f  |\n",id,titulo,genero,rating);
    }
}

void* asignarRatingsAleatorios(void* pElemento)
{
    float rating;
    int min = 10;
    int max = 100;

    eMovie* pMovie = (eMovie*) pElemento;

    if(pElemento != NULL)
    {
        rating = (float) (rand() % (max - min + 1))/10;
        movieSetRating(pMovie,rating);
    }

    return pMovie;
}

void* asignarGeneros(void* pElemento)
{
    int aleatorio;
    char genero[30];
    int min = 1;
    int max = 4;

    eMovie* pMovie = (eMovie*) pElemento;

    if(pElemento != NULL)
    {
        aleatorio = rand() % (max - min + 1) + min;

        switch(aleatorio)
        {
        case 1:
            strcpy(genero,"Drama");
            break;
        case 2:
            strcpy(genero,"Comedia");
            break;
        case 3:
            strcpy(genero,"Accion");
            break;
        case 4:
            strcpy(genero,"Terror");
            break;
        }
        movieSetGenero(pMovie,genero);
    }

    return pMovie;
}

int filtroDrama(void* pElemento)
{
    int retorno = ERROR;
    eMovie* pMovie = (eMovie*) pElemento;
    char genero[20];

    if(pElemento != NULL)
    {
        movieGetGenero(pMovie,genero);

        if(!strcmp(genero,"Drama"))
        {
            retorno = OK;
        }
    }

    return retorno;
}

int filtroComedia(void* pElemento)
{
    int retorno = ERROR;
    eMovie* pMovie = (eMovie*) pElemento;
    char genero[20];

    if(pElemento != NULL)
    {
        movieGetGenero(pMovie,genero);

        if(!strcmp(genero,"Comedia"))
        {
            retorno = OK;
        }
    }

    return retorno;
}

int filtroAccion(void* pElemento)
{
    int retorno = ERROR;
    eMovie* pMovie = (eMovie*) pElemento;
    char genero[20];

    if(pElemento != NULL)
    {
        movieGetGenero(pMovie,genero);

        if(!strcmp(genero,"Accion"))
        {
            retorno = OK;
        }
    }

    return retorno;
}

int filtroTerror(void* pElemento)
{
    int retorno = ERROR;
    eMovie* pMovie = (eMovie*) pElemento;
    char genero[20];

    if(pElemento != NULL)
    {
        movieGetGenero(pMovie,genero);

        if(!strcmp(genero,"Terror"))
        {
            retorno = OK;
        }
    }

    return retorno;
}

int movie_sortGeneroRating(void* movie1, void* movie2)
{
    int retorno = ERROR;

    char genero1[20];
    char genero2[20];
    float rating1;
    float rating2;

    eMovie* auxMovie1 = (eMovie*) movie1;
    eMovie* auxMovie2 = (eMovie*) movie2;

    if(movie1 != NULL && movie2 != NULL)
    {
        movieGetGenero(auxMovie1,genero1);
        movieGetGenero(auxMovie2,genero2);

        movieGetRating(auxMovie1,&rating1);
        movieGetRating(auxMovie2,&rating2);

        if((strcmp(genero1,genero2) == 0 && rating1 < rating2) || strcmp(genero1,genero2) > 0)
        {
            retorno = OK;
        }
    }

    return retorno;

}
