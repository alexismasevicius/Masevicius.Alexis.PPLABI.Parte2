#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "servicios.h"


int mostarServicios(eServicio lista[], int len)
{
    int retorno=0;

    printf("\n -------------- Los servicios son: -------------- \n\n");
    printf("%-10s| %-25s| %-10s|\n","ID","DESCRIPCION", "PRECIO");


    for(int i=0 ; i<len ; i++)
    {
        if(mostrarServicio(lista, i)==1)
        {
            retorno=1;
        }
    }

    return retorno;
}


//retorna 1 si encontro el empleado y 0 si no lo encontro
int mostrarServicio(eServicio lista[], int indice)
{
    int retorno=0;

    if(lista[indice].isEmpty==0)
    {
        printf("%-10d| %-25s| %-10.02f|\n",
               lista[indice].id,
               lista[indice].descripcion,
               lista[indice].precio);
        retorno=1;
    }



    return retorno;
}


int buscarServicio(eServicio lista[], int len,int codigo)
{
    int indice=-1;

    for(int i=0 ; i<len ; i ++)
    {
        if(lista[i].id == codigo && lista[i].isEmpty==0)
        {
           indice=i;
           break;
        }
    }
    return indice;

}


int cargarNombreServicio (int id, eServicio lista[], int tam, char descripcionCargar[])
{
    int todoOk=0;
    int indice;


    if(lista!=NULL && descripcionCargar!=NULL && tam>0)
    {
            indice=buscarServicio(lista,tam,id);
            if(indice!=-1)
            {
                strcpy(descripcionCargar,lista[indice].descripcion);
                todoOk=1;
            }

    }

    return todoOk;
}

