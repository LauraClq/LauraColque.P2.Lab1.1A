#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    //SIEMPRE VALIDAR DISTINTO DE NULL
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNodo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNodo = this->pFirstNode;
        //me paro en la locomotora
        for(int i=0; i< nodeIndex; i++)
        {
            pNodo = pNodo->pNextNode;
            //a partir de cada empiezo a saltar
            //porque el for recorre cada vagon es decir
            //cada i del for esta consiguiendo
            //la direccion de memoria de cada elemento
        }
        /* otra forma
        while(nodeIndex > 0)
        {
            pNodo = pNodo->pNextNode;
            nodeIndex--;
        }
        */
    }
    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodo = NULL;
    Node* pAnteriorNodo;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNodo = (Node*) malloc(sizeof(Node));
        if(pNodo != NULL)
        {
            pNodo->pElement = pElement;

            if(nodeIndex == 0)
            {
                pNodo->pNextNode = this->pFirstNode;
                this->pFirstNode = pNodo;
            }
            else
            {
                pAnteriorNodo = getNode(this,nodeIndex - 1);
                pNodo->pNextNode = pAnteriorNodo->pNextNode;
                pAnteriorNodo->pNextNode = pNodo;
            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this,ll_len(this),pElement);
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    //Retorna un puntero al elemento que se encuentra en el índice especificado.
    //recupera el elemento de un puntero a nodeIndex
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        returnAux = getNode(this,index)->pElement;
        //getNode me devuelve el nodo es dcir la direccion de memoria de cada elemento en este caso en la posicion index
        //especificado
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;


    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        //pisar un elemento existente por eso debe existir en nodo a ese indice
        //Inserta un elemento en el LinkedList, en el índice especificado
        getNode(this,index)->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    //Elimina UN elemento del LinkedList, en el índice especificado
    Node* auxNode;
    Node* preAuxNode;
    int returnAux = -1;

    //el inidice simpre empieza en 0
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this, index);
        if(auxNode != NULL)
        {
            if(index == 0)
            {
                this->pFirstNode = auxNode->pNextNode;
            }
            else
            {
                preAuxNode = getNode(this,index - 1);
                preAuxNode->pNextNode = auxNode->pNextNode;
            }
        }
        free(auxNode);
        returnAux = 0;
        this->size--;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    //Borra todos los elementos de LinkedList.
    int returnAux = -1;
    int tam;

    if(this != NULL)
    {
        tam = ll_len(this);
        for(int i=tam-1; i>=0; i--)
        {
            ll_remove(this,i);
        }
        returnAux = 0;
    }
    /*
    miestras halla vagones enganchados en la locomotora lo elemina
    while(this->pFirstNode != NULL)
    {
        ll_remove(this,0);
        returnAux = 0;
    }
    */
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    //liberar las memorias de los nodos y despues liberar la memoria de lista es decir liberar todos los elemento
    //porque no basta con solo borrar la locomotora ya que en la memoria dinamica queda estacionda, por eso liberar toda la memoria del linkestllist
    //es decir bsicamente borro todo
    //primero hacer un claer a los elementos de la locomotora para que borre todos los elementos y despues un frre a la locomotora
    int returnAux = -1;

    if(this != NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            this = NULL;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    //Retorna el índice de la primera aparición de un elemento (element) en el LinkedList
    int returnAux = -1;
    //void* auxElement;
    int tam;

    if(this != NULL)
    {
        tam = ll_len(this);
        for(int i=0; i<tam; i++)
        {
            //esta bien pero no tambien podri adevolver -2 i=tam porque no sabemos si el -1 es del inidice o del this != NULL
            //auxElement = ll_get(this,i); //Retorna un puntero al elemento que se encuentra en el índice especificado
            if(pElement == ll_get(this,i)) //busco la ocurrencia de ese elemento que conincida
            {
                returnAux = 0;
                break;
            }
        }

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    //Retorna cero si contiene elementos y uno si no los tiene
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 1;
        if(ll_len(this) > 0 ) //porque si es igual a 0 esp poruqe hay 0 elementos en la lista
        {
            returnAux = 0;
        }
    }
    /*
    while(!ll_isEmpty(this)) //mientras no este vacia la lista
    {
        if(ll_remove(this,0)==-1) //voy a ir removiendo
        {
        flag = 0;
        break;
        }
    }
    if(flag)
    {
        returnAux = 0;
    }
    */
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    //Agrega un nuevo elemento en alguna ubicacion del array
    //es como la fila del banco, uno se fue al banio y al volver quiere estar en misma ubicacion que habia estado
    return addNode(this,index,pElement); //RECORDAR QUE ADDNODE no podemos llamarla desde afuera como en una func privada
    //solo podemos usarlo a traves de cualquier func de ll_..
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)) //no pnemos index <= ll_len(this), poruqr no existe una posicion igual al tamanio
    {
        returnAux = ll_get(this,index); //guardo en returnAux la direccion de memoria del elemento que se encuentra en el índice especificado.
        ll_remove(this,index); //la borro
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    //verifica que el elemento este en lista por lo menos una vez.
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;
        if(!ll_indexOf(this,pElement)) //Busca el indice de la primer ocurrencia del elemento pasado como parametro si existe es como buscarID
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    //Comprueba su contienen los mismos elementos el this2 y this
    int returnAux = -1;
    int len;
    //void* pElement;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        len = ll_len(this2);
        for(int i=0; i<len; i++)
        {
            //pElement = ll_get(this2,i); //a la primer recorrida del for tomo el primer elemento
            if(ll_contains(this,ll_get(this2,i)) != 1) //verifico si esta en el this si es distinto de 1(es que lo enocntro) o posibles valores -1 o 0 pero no lo encontro
            {
                returnAux = 0; //caigo aca si no esta entonces dejo de buscar, salgo con el break
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    //Generamos un nuevo linkedList que va apuntar a los elementos del linkedlist original->this
    //from (desde) y to (hasta)
    LinkedList* cloneArray = NULL;
    void* pElement;

    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(int i=from; i<to; i++)
            {
                pElement = ll_get(this,i);
                ll_add(cloneArray,pElement);
                //ll_add(cloneArray,ll_get(this,i)); otra forma de hacerlo
            }
        }

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    //nos devuelve una copia del array original
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this,0,ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    void* pElement1;
    void* pElement2;
    int len;
    int validFuc;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        len = ll_len(this);
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                pElement1 = ll_get(this, i);
                pElement2 = ll_get(this, j);
                validFuc = pFunc(pElement1, pElement2);

                if((validFuc > 0 && order) || (validFuc < 0 && !order))
                {
                    // [1] Indica orden ascendente - [0] Indica orden descendente
                    ll_set(this, i, pElement2);
                    ll_set(this, j, pElement1);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Filtra los elementos de un linkedList
 * \param void* Puntero a la funcion filter
 * \param pFunc (*pFunc) Puntero a la funcion filtro
 * \return LinkedList* linkedlist nuevo con los elementos que pasan el filtrado o NULL en el caso de error en parametros
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* filterList = NULL;
    int tam;
    void* pElement = NULL;

    if(this != NULL && pFunc != NULL)
    {
        filterList = ll_newLinkedList();

        if(filterList != NULL)
        {
            tam = ll_len(this);
            for(int i=0; i<tam; i++)
            {
                pElement = ll_get(this,i);
                if(pFunc(pElement)) //para saber si lo tengo que agregar o no
                {
                    if(ll_add(filterList,pElement))
                    {
                        ll_deleteLinkedList(filterList);
                        filterList = NULL;
                        break;
                    }
                }
            }
            pElement = NULL; //para que no quede apuntando.
        }

    }

    return filterList;
}

/** \brief Mapea valores
 *
 * \param void* Puntero a la funcion filter
 * \param pFunc (*pFunc) Puntero a la funcion filtro
 * \return LinkedList* linkedlist nuevo con los elementos que pasan el mapeo o NULL en el caso de error en parametros
 *
 */
LinkedList* ll_map(LinkedList* this, void* (*pFunc) (void*))
{
    LinkedList* nuevaLista = NULL;
    int tam;
    nuevaLista = ll_newLinkedList();

    if(this != NULL && pFunc != NULL)
    {
        nuevaLista = ll_newLinkedList();
        if(nuevaLista != NULL)
        {
            tam = ll_len(this);
            for(int i=0; i<tam; i++)
            {
                ll_add(nuevaLista,pFunc(ll_get(this,i)));
            }
        }
    }
    return nuevaLista;
}

