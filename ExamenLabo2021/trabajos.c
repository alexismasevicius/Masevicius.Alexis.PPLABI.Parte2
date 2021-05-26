
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajos.h"
#include "mascotas.h"
#include "tipos.h"
#include "color.h"
#include "utn.h"

void inicializarTrabajos (eTrabajo lista[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
       lista[i].isEmpty=1;
    }
}


int buscarLibreTrabajo(eTrabajo lista[], int len)
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


int buscarTrabajo(eTrabajo lista[], int len,int codigo)
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


int altaTrabajo(eTrabajo listaTrabajo[], int len,int* idTrabajo, eMascota listaMascotas[], int lenMasc, eServicio listaServicio[], int lenServicio, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores)
{
    int indice;
    //int indiceMascotas;
    eTrabajo auxTrabajo;
    int todoOk = 0;
    int codePet;
    int codeServ;
    int day;
    int month;
    int year;



    if(listaTrabajo!=NULL && listaMascotas!=NULL && idTrabajo!=NULL && len>0)
    {
        indice=buscarLibreTrabajo(listaTrabajo,len);

        //SI hay lugar para el trabajo y hay mascotas cargadas
        if(indice!=-1 && mostrarMascotas(listaMascotas,lenMasc,listaTipos,tamTipos,listaColores,tamColores)==1)
        {
            utn_getNumero(&codePet,"Ingrese el id de la mascota: \n","Error, ingrese nuevamente\n",1000,10000,100);
            auxTrabajo.idMascota=codePet;

            //SI hay servicios cargados
            if(mostarServicios(listaServicio,lenServicio)==1)
            {
                utn_getNumero(&codeServ,"Ingrese el id del servicio: \n","Error, ingrese nuevamente\n",20000,20004,100);
                auxTrabajo.idServicio=codeServ;

                auxTrabajo.id=*idTrabajo;

                utn_getNumero(&day,"Ingrese el dia del trabajo: \n","Error, ingrese nuevamente\n",1,31,100);
                auxTrabajo.fecha.dia=day;

                utn_getNumero(&month,"Ingrese el mes del trabajo: \n","Error, ingrese nuevamente\n",1,12,100);
                auxTrabajo.fecha.mes=month;

                utn_getNumero(&year,"Ingrese el anio del trabajo: \n","Error, ingrese nuevamente\n",2021,2030,100);
                auxTrabajo.fecha.anio=year;

                auxTrabajo.isEmpty=0;

                listaTrabajo[indice] = auxTrabajo;

                (*idTrabajo)++;

                todoOk = 1;
            }
            else
            {
                system("cls");
                printf("\nError. no hay servicios cargados\n");
            }

        }
        else
        {
            system("cls");
            printf("\nNo Hay lugar en el sistema o no hay ninguna mascota cargada. \n");
        }
    }
    return todoOk;
}


int mostrarTrabajos(eTrabajo listaTrabajo[], int len, eMascota listaMascotas[], int lenMasc, eServicio listaServicio[], int lenServicio)
{
    int retorno=0;


    printf("\n---------Los trabajos son: --------------\n\n");
    printf("%-10s| %-15s %-25s %-15s|\n","ID","MASCOTA","SERVICIO","FECHA");

    for(int i=0 ; i<len ; i++)
    {
        if(mostrarTrabajo(listaTrabajo,len,listaMascotas,lenMasc,listaServicio,lenServicio,i)==1)
        {
            retorno=1;
        }
    }

    return retorno;



}

int mostrarTrabajo(eTrabajo listaTrabajo[], int len, eMascota listaMascotas[], int lenMasc, eServicio listaServicio[], int lenServicio, int indice)
{

    int retorno=0;

    char nombreMascota[50];
    char nombreServicio[50];



    if(listaTrabajo[indice].isEmpty==0)
    {
        //cargar nombre Mascota
        cargarNombreMascota(listaTrabajo[indice].idMascota,listaMascotas,lenMasc,nombreMascota);
        //cargar nombre Servicio
        cargarNombreServicio(listaTrabajo[indice].idServicio,listaServicio,lenServicio,nombreServicio);


        printf("%-10d| %-15s %-25s %02d/%02d/%d     |\n",
               listaTrabajo[indice].id,
               nombreMascota,
               nombreServicio,
               listaTrabajo[indice].fecha.dia,
               listaTrabajo[indice].fecha.mes,
               listaTrabajo[indice].fecha.anio);

        retorno=1;
    }

    return retorno;



}

