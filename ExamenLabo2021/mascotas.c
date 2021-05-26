#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "tipos.h"
#include "color.h"
#include "utn.h"


///AGREGAR ELEMENTO EDAD  A LAS MASCOTAS:::::

void inicializarMascota (eMascota lista[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
       lista[i].isEmpty=1;
    }
}


int buscarLibreMascota(eMascota lista[], int len)
{
    int indice=-1;
    for(int i=0; i<len ; i++)
    {
        if(lista[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


int buscarMascota(eMascota lista[], int len,int codigo)
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


int altaMascota(eMascota listaMascota[], int len,int* idMascota, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColor)
{
    int indice;
    eMascota auxMascota;
    int todoOk = -1;
    char name[50];
    int codeType;
    int codeColor;
    int years;


    if(listaMascota!=NULL && idMascota!=NULL && len>0)
    {
        indice=buscarLibreMascota(listaMascota,len);
        if(indice!=-1)
        {
            auxMascota.id=*idMascota;

            utn_getNombre("ingrese el nombre: \n","Error.Ingrese nombre correcto\n", 50 ,name);
            strcpy(auxMascota.nombre,name);

            //mostrar tipo
            mostarTipos(listaTipos,lenTipos);
            utn_getNumero(&codeType,"Ingrese el id del tipo: \n","Error, ingrese nuevamente\n",1000,1004,100);
            auxMascota.idTipo=codeType;

            //mostrar color

            mostarColores(listaColores,lenColor);
            utn_getNumero(&codeColor,"Ingrese el id del color: \n","Error, ingrese nuevamente\n",5000,5004,100);
            auxMascota.idColor=codeColor;

            utn_getNumero(&years,"Ingrese la edad de la mascota: \n", "Error, ingrese nuevamente",0,150,100);
            auxMascota.edad=years;

            auxMascota.isEmpty=0;

            listaMascota[indice] = auxMascota;

            (*idMascota)++;

            todoOk = 1;
        }
        else
        {
            printf("No Hay lugar en el sistema. \n");
        }
    }
    return todoOk;
}


int mostrarMascotas(eMascota listaMascota[],int lenMas, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores)
{
    int retorno=0;

    ordenarMascotasPorNombre(listaMascota,lenMas);

    printf("\n-----------------------Las mascotas son: -------------------------\n\n");
    printf("%-10s|%-15s %-25s %-20s %-10s|\n","ID","NOMBRE","TIPO","COLOR", "EDAD");

    for(int i=0 ; i<lenMas ; i++)
    {
        if(mostrarMascota(listaMascota,lenMas,listaTipos,tamTipos,listaColores,tamColores,i)==1)
        {
            retorno=1;
        }
    }

    return retorno;



}
int mostrarMascota(eMascota listaMascota[],int lenMas, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores, int indice)
{

    int retorno=0;

    char nombreTipo[50];
    char nombreColor[50];



    if(listaMascota[indice].isEmpty==0)
    {
        //cargar nombre Tipo
        cargarNombreTipo(listaMascota[indice].idTipo,listaTipos,tamTipos,nombreTipo);

        //cargar nombre Color
        cargarNombreColor(listaMascota[indice].idColor,listaColores,tamColores,nombreColor);


        printf("%-10d|%-15s %-25s %-20s %-10d|\n",
               listaMascota[indice].id,
               listaMascota[indice].nombre,
               nombreTipo,
               nombreColor,
               listaMascota[indice].edad);

        retorno=1;
    }

    return retorno;



}



int modificarMascotas(eMascota listaMascota[],int lenMas, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores)
{
    int retorno = 0;
    int eleccion;
    int indice;

    if(mostrarMascotas(listaMascota,lenMas,listaTipos,tamTipos,listaColores,tamColores)==1)
    {
        utn_getNumero(&eleccion,"\nIngrese el id de la mascota a modificar\n", "\nError. Ingrese un numero\n", 1000, 2000, 100);

        indice=buscarMascota(listaMascota,lenMas,eleccion);

        if(indice!=-1 && listaMascota!=NULL && listaTipos!=NULL && listaColores!=NULL)
        {
            utn_getNumero(&eleccion,"\nIngrese el dato a modificar:\n1-Tipo.\n2-Color.\n",
                      "\nError. Ingrese un numero correcto\n", 1, 2, 100);
            retorno=modificarMascota(listaMascota,lenMas,listaTipos,tamTipos,listaColores,tamColores,eleccion,indice);
        }
        else
        {
            printf("\nError.\n");
        }
    }
    else
    {
        system("cls");
        printf("\n\nNo hay ninguna mascota cargada.\n");
    }


    return retorno;
}


int modificarMascota(eMascota lista[], int len, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores,int opcion, int indice)
{
    int retorno = 0;

    int codeType;
    int codeColor;

    if(lista!=NULL && listaTipos!=NULL && listaColores!=NULL && opcion>0 && opcion<6)
    {
        switch(opcion)
        {
            case 1:
                mostarTipos(listaTipos,tamTipos);
                utn_getNumero(&codeType,"Ingrese id del tipo nuevo: \n","Error, ingrese nuevamente\n",1000,1004,100);
                lista[indice].idTipo=codeType;
                break;
            case 2:
                mostarColores(listaColores,tamTipos);
                utn_getNumero(&codeColor,"Ingrese id del color nuevo: \n","Error, ingrese nuevamente\n",5000,5004,100);
                lista[indice].idColor=codeColor;
                break;
        }
        retorno=1;
    }
    return retorno;
}


int bajaMascota (eMascota lista[],int lenMas, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores)
{
    int todoOk=0;
    int idMas;
    int indice;
    int respuesta;


    if(mostrarMascotas(lista,lenMas,listaTipos,tamTipos,listaColores,tamColores)==1)
    {
        utn_getNumero(&idMas, "\nSeleccione el id de la mascota a borrar: \n", "\nError ingrese numero valido...\n",0,40000,100);
        indice=buscarMascota(lista,lenMas,idMas);

        if(indice==-1)
        {
            printf("\n Error. No hay ninguna mascota con el id %d .\n",idMas);
        }
        else
        {
            mostrarMascota(lista,lenMas,listaTipos,tamTipos,listaColores,tamColores,indice);
            utn_getNumero(&respuesta,"\nConfirma baja? Ingrese 1 para confirmar, 0 para cancelar:\n",
                          "\nError seleccione opcion valida: 1 para confirmar, 0 para cancelar\n",0,1,100);
            if(respuesta==1)
            {
                lista[indice].isEmpty=1;
                todoOk=1;
            }
            else
            {
                printf("\nBaja cancelada\n");
            }
        }

    }
    else
    {
        system("cls");
        printf("\n\nNo hay ninguna mascota cargada.\n");
    }



    return todoOk;

}



int cargarNombreMascota (int id, eMascota lista[], int tam, char descripcionCargar[])
{
    int todoOk=0;
    int indice;


    if(lista!=NULL && descripcionCargar!=NULL && tam>0)
    {
            indice=buscarMascota(lista,tam,id);
            if(indice!=-1)
            {
                strcpy(descripcionCargar,lista[indice].nombre);
                todoOk=1;
            }

    }

    return todoOk;
}





int ordenarMascotasPorNombre(eMascota lista[], int tam)
{
    int todoOk=0;
    eMascota auxMascota;

    if(lista!=NULL && tam>0)
    {

        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(lista[i].idTipo>lista[j].idTipo || (lista[i].idTipo==lista[j].idTipo && strcmp(lista[i].nombre, lista[j].nombre)>0))
                {
                    auxMascota=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxMascota;
                }
            }
        }
        todoOk=1;
}





    return todoOk;
}
