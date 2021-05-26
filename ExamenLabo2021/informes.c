#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"
#include "mascotas.h"
#include "tipos.h"
#include "color.h"
#include "trabajos.h"
#include "servicios.h"
#include "utn.h"


void mostrarMascotasDeColor(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores)
{
    char auxColor[50];
    int idColor;

    mostarColores(listaColores,lenColores);
    utn_getNumero(&idColor,"Ingrese el id del color: \n","Error, ingrese nuevamente\n",5000,5004,100);

    cargarNombreColor(idColor,listaColores,lenColores,auxColor);
    printf("\n------------Las mascotas del color %s son: -----------\n", auxColor);
    for(int i=0; i<lenMas; i++)
    {
        if(listaMascotas[i].isEmpty==0 && listaMascotas[i].idColor==idColor)
        {
            mostrarMascota(listaMascotas,lenMas,listaTipos,lenTipos,listaColores,lenColores,i);
        }
    }

}



void mostrarMascotasDeTipo(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores)
{
    char auxTipo[50];
    int idTipo;

    mostarTipos(listaTipos,lenTipos);
    utn_getNumero(&idTipo,"Ingrese el id del tipo: \n","Error, ingrese nuevamente\n",1000,1004,100);

    cargarNombreTipo(idTipo,listaTipos,lenTipos,auxTipo);
    printf("\n------------Las mascotas del tipo %s son: -----------\n", auxTipo);
    for(int i=0; i<lenMas; i++)
    {
        if(listaMascotas[i].isEmpty==0 && listaMascotas[i].idTipo==idTipo)
        {
            mostrarMascota(listaMascotas,lenMas,listaTipos,lenTipos,listaColores,lenColores,i);
        }
    }

}

void mascotasMenorEdad(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores)
{
    int auxEdad;
    int flag=0;

    for(int i=0; i<lenMas; i++)
    {
        if(listaMascotas[i].isEmpty==0)
        {
            if(flag==0 || listaMascotas[i].edad<auxEdad)
            {
                auxEdad=listaMascotas[i].edad;
                flag=1;
            }
        }

    }
    printf("\n----La o las mascotas de menor edad son: ------\n");

    for(int i=0; i<lenMas; i++)
    {
        if(listaMascotas[i].isEmpty==0)
        {
            if(listaMascotas[i].edad==auxEdad)
            {
                printf("\n%s, %d anios\n",listaMascotas[i].nombre, listaMascotas[i].edad);
            }
        }
    }



}


void mostarMascotasPorTipo(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores)
{
    int flag=0;

    for(int i=0; i<lenTipos; i++)
    {
        flag=0;
        if(listaTipos[i].isEmpty==0)
        {

            printf("\n--------Las mascotas del tipo %s son :----------\n", listaTipos[i].descripcion);
            for(int j=0; j<lenMas;j++)
            {
                if(listaMascotas[j].idTipo==listaTipos[i].id && listaMascotas[j].isEmpty==0)
                {
                    mostrarMascota(listaMascotas,lenMas,listaTipos,lenTipos,listaColores,lenColores,j);
                    flag=1;
                }
            }
            if(flag==0)
            {
                printf("No hay mascotas de este tipo\n");
            }
        }
    }


}


void cantidadMascotasPorColorYTipo(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores)
{
    char auxColor[50];
    int idColor;
    char auxTipo[50];
    int idTipo;
    int contador=0;

    mostarColores(listaColores,lenColores);
    utn_getNumero(&idColor,"Ingrese el id del color: \n","Error, ingrese nuevamente\n",5000,5004,100);
    mostarTipos(listaTipos,lenTipos);
    utn_getNumero(&idTipo,"Ingrese el id del tipo: \n","Error, ingrese nuevamente\n",1000,1004,100);


    cargarNombreTipo(idTipo,listaTipos,lenTipos,auxTipo);
    cargarNombreColor(idColor,listaColores,lenColores,auxColor);

    for(int i=0; i<lenMas; i++)
    {
        if(listaMascotas[i].isEmpty==0 && listaMascotas[i].idTipo==idTipo && listaMascotas[i].idColor==idColor)
        {
            contador++;
        }
    }
        printf("\n------------La cantidad de mascotas del tipo %s y color %s son: %d -----------\n", auxTipo, auxColor, contador);

}

///Mostrar el o los colores con mas cantidad de mascotas

void coloresMasMascotas(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores)
{
    int contadorColores[lenColores];//contador por cada juego para ver cual es el mas alquilado
    int colorMasMascotas;
    int flag=0;

    for(int i=0; i<lenColores;i++)
    {
        contadorColores[i]=0;
    }


    for(int i=0; i<lenColores;i++)
    {
        if(listaColores[i].isEmpty==0)
        {
            for(int j=0; j<lenMas; j++)
            {
                if(listaMascotas[j].isEmpty==0 && listaMascotas[j].idColor==listaColores[i].id)
                {
                    (contadorColores[i])++;
                }
            }
        }

    }

    for(int i=0; i<lenColores;i++)
    {
        if(flag==0 || contadorColores[i]>colorMasMascotas)
        {
            colorMasMascotas=contadorColores[i];
            flag=1;
        }
    }

    printf("\n-----El o los colores con mas mascotas son: ---\n");
    for(int i=0; i<lenColores;i++)
    {
        if(contadorColores[i]==colorMasMascotas)
        {
            printf("%s\n", listaColores[i].nombreColor);
        }
    }


}


///7- Pedir una mascota y mostrar todos los trabajos que se le hicieron a la misma.

void  serviciosPorMascota(eMascota listaMascotas[],int lenMascotas, eTipos listaTipos[], int lenTipos, eColores listaColores[],
                             int lenColores, eTrabajo listaTrabajos[], int lenTrabajos, eServicio listaServicios[], int lenServicios)
{
    int idMascota;
    int indice;
    char auxServicio[50];
    int flag=0;

    mostrarMascotas(listaMascotas,lenMascotas,listaTipos,lenTipos,listaColores,lenColores);
    utn_getNumero(&idMascota,"\nIngrese el id de la mascota para mostrar sus servicios\n", "\nError. Ingrese un numero\n", 1000, 2000, 100);

    indice=buscarMascota(listaMascotas,lenMascotas,idMascota);

    printf("\nA la mascota %s se le hicieron los siguientes servicios:\n",listaMascotas[indice].nombre);
    for(int i=0;i<lenTrabajos;i++)
    {
        if(listaTrabajos[i].isEmpty==0 && listaTrabajos[i].idMascota==listaMascotas[indice].id)
        {
            cargarNombreServicio(listaTrabajos[i].idServicio,listaServicios,lenServicios,auxServicio);
            printf("%s\n", auxServicio);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("La mascota no tiene servicios cargados\n");
    }


}



///8- Pedir una mascota e informar la suma de los importes de los servicios que se le hicieron a la misma.
void  importeServiciosPorMascota(eMascota listaMascotas[],int lenMascotas, eTipos listaTipos[], int lenTipos, eColores listaColores[],
                             int lenColores, eTrabajo listaTrabajos[], int lenTrabajos, eServicio listaServicios[], int lenServicios)
{
    int idMascota;
    int indice;
    float contador=0;

    mostrarMascotas(listaMascotas,lenMascotas,listaTipos,lenTipos,listaColores,lenColores);
    utn_getNumero(&idMascota,"\nIngrese el id de la mascota para mostrar el importe por servicios\n", "\nError. Ingrese un numero\n", 1000, 2000, 100);

    indice=buscarMascota(listaMascotas,lenMascotas,idMascota);

    for(int i=0;i<lenTrabajos;i++)
    {
        if(listaTrabajos[i].isEmpty==0 && listaTrabajos[i].idMascota==listaMascotas[indice].id)
        {
            for(int j=0;j<lenServicios;j++)
            {
                if(listaTrabajos[i].idServicio==listaServicios[j].id)
                {
                    contador=contador+listaServicios[j].precio;
                }
            }

        }
    }

    printf("\nLa mascota %s pago por servicios: %.02f $$\n",listaMascotas[indice].nombre,contador);


}
///9- Pedir un servicio y mostrar las mascotas a las que se les realizo ese servicio y la fecha.

void  serviciosRealizados(eMascota listaMascotas[],int lenMascotas, eTipos listaTipos[], int lenTipos, eColores listaColores[],
                             int lenColores, eTrabajo listaTrabajos[], int lenTrabajos, eServicio listaServicios[], int lenServicios)
{
    int idServ;
    char auxNombreServicio[50];
    char auxNombre[50];
    int auxId;

    mostarServicios(listaServicios,lenServicios);
    utn_getNumero(&idServ,"\nIngrese el id del servicio para mostar mascotas y fecha\n", "\nError. Ingrese un numero\n", 20000, 20002, 100);

    cargarNombreServicio(idServ,listaServicios,lenServicios,auxNombreServicio);
    printf("-----El servicio %s se le realizo:---\n", auxNombreServicio);

    for(int i=0; i<lenTrabajos; i++)
    {
        if(listaTrabajos[i].isEmpty==0)
        {
            auxId=listaTrabajos[i].idServicio;
            if(auxId==idServ)
            {
                cargarNombreMascota(listaTrabajos[i].idMascota,listaMascotas,lenMascotas,auxNombre);
                printf("A la mascota %s el dia: %d/%d/%d \n", auxNombre,
                                                            listaTrabajos[i].fecha.dia,
                                                            listaTrabajos[i].fecha.mes,
                                                            listaTrabajos[i].fecha.anio);
            }
        }

    }





}

///10- Pedir una fecha y mostrar todos los servicios realizados en la misma.

void  serviciosRealizadosPorFecha(eMascota listaMascotas[],int lenMascotas, eTipos listaTipos[], int lenTipos, eColores listaColores[],
                             int lenColores, eTrabajo listaTrabajos[], int lenTrabajos, eServicio listaServicios[], int lenServicios)
{
    int day;
    int month;
    int year;
    int flag=0;
    int auxServ;
    char nombreServ[50];


    utn_getNumero(&day,"Ingrese el dia del trabajo: \n","Error, ingrese nuevamente\n",1,31,100);

    utn_getNumero(&month,"Ingrese el mes del trabajo: \n","Error, ingrese nuevamente\n",1,12,100);

    utn_getNumero(&year,"Ingrese el anio del trabajo: \n","Error, ingrese nuevamente\n",2019,2030,100);


    printf("\n-----En la fecha %d/%d/%d se realizaron los siguientes servicios:---\n", day,month,year);

    for(int i=0; i<lenTrabajos; i++)
    {
        if(listaTrabajos[i].isEmpty==0)
        {
            if(listaTrabajos[i].fecha.dia==day && listaTrabajos[i].fecha.mes==month && listaTrabajos[i].fecha.anio==year)
            {
                auxServ=listaTrabajos[i].idServicio;
                cargarNombreServicio(auxServ,listaServicios,lenServicios,nombreServ);
                printf("%s .\n",nombreServ);
                flag=1;
            }
        }

    }

    if(flag==0)
    {
        printf("No hay servicios para la fecha seleccionada");
    }



}
