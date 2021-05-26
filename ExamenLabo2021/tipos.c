#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tipos.h"

int mostarTipos(eTipos lista[], int len)
{
    int retorno=0;

    printf("\n --------- Los tipos de mascota son: -------------- \n\n");
    printf("%-10s| %-25s |\n","ID","DESCRIPCION");

    //ORDENAR CLIENTES POR NOMBRE Y APELLIDO

    for(int i=0 ; i<len ; i++)
    {
        if(mostrarTipo(lista, i)==1)
        {
            retorno=1;
        }
    }

    return retorno;
}


//retorna 1 si encontro el empleado y 0 si no lo encontro
int mostrarTipo(eTipos lista[], int indice)
{
    int retorno=0;

    if(lista[indice].isEmpty==0)
    {
        printf("%-10d| %-25s     |\n",
               lista[indice].id,
               lista[indice].descripcion);
        retorno=1;
    }



    return retorno;
}

int buscarTipo(eTipos lista[], int len,int codigo)
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


int cargarNombreTipo(int idTipo, eTipos lista[], int tam, char descripcionCargar[])
{
    int todoOk=0;
    int indice;


    if(lista!=NULL && descripcionCargar!=NULL && tam>0)
    {
            indice=buscarTipo(lista,tam,idTipo);
            if(indice!=-1)
            {
                strcpy(descripcionCargar,lista[indice].descripcion);
                todoOk=1;
            }

    }

    return todoOk;
}


