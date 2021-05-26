#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascotas.h"
#include "trabajos.h"


static char nombres[10][30]={
            "Donato",
            "German",
            "Damian",
            "Gaston",
            "Alex",
            "Andrea",
            "Daniel",
            "Candela",
            "Georgina",
            "Juan"
            };

static int colores[10]={5002, 5000, 5000, 5001, 5003,5000,5004,5003,5001,5003};

static int tipos[10]={1004, 1000, 1002, 1003, 1000,1004, 1003, 1002, 1003, 1000};

static int edades[10]={10, 5, 25, 11,7, 2, 5, 6, 2, 7};

static int servicios[10]={20001, 20000, 20000, 20002, 20001,20002, 20002, 20001, 20000, 20002};

static int mascotas[10]={1004, 1000, 1001, 1008, 1004,1004, 1002, 1002, 1009, 1000};

static eFecha fechas[10]={{10,6,2021}, {25,8,2021}, {25,12,2020}, {25,5,2020}, {25,5,2020}, {20,10,2020}, {13,11,2021}, {25,5,2020}, {12,3,2020}, {11,1,2020}};

int harcodearMascotas(eMascota lista[], int tam, int cant, int* pCodigo)
{
    int cantidad = 0;

    if(lista!=NULL && tam>0 && cant>=0 && cant<=tam && pCodigo!=NULL)
    {

        for(int i=0; i<cant; i++)
        {
            lista[i].id=*pCodigo;
            (*pCodigo)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].idColor=colores[i];
            lista[i].idTipo=tipos[i];
            lista[i].edad=edades[i];
            lista[i].isEmpty=0;
            cantidad++;
        }
    }
    return cantidad;

}


int harcodearTrabajos(eTrabajo lista[], int tam, int cant, int* pCodigo)
{
    int cantidad = 0;

    if(lista!=NULL && tam>0 && cant>=0 && cant<=tam && pCodigo!=NULL)
    {

        for(int i=0; i<cant; i++)
        {
            lista[i].id=*pCodigo;
            (*pCodigo)++;
            lista[i].idServicio=servicios[i];
            lista[i].idMascota=mascotas[i];
            lista[i].fecha=fechas[i];
            lista[i].isEmpty=0;
            cantidad++;
        }
    }
    return cantidad;

}
