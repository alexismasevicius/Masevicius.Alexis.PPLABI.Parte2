#include "tipos.h"
#include "color.h"
#include "mascotas.h"
#include "servicios.h"

#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED


typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    int idServicio;
    int idMascota;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJOS_H_INCLUDED

void inicializarTrabajos (eTrabajo lista[], int tam);
int buscarLibreTrabajo(eTrabajo lista[], int len);
int buscarTrabajo(eTrabajo lista[], int len,int codigo);
int altaTrabajo(eTrabajo listaTrabajo[], int len,int* idTrabajo, eMascota listaMascotas[], int lenMasc, eServicio listaServicio[], int lenServicio, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores);
int mostrarTrabajos(eTrabajo listaTrabajo[], int len, eMascota listaMascotas[], int lenMasc, eServicio listaServicio[], int lenServicio);
int mostrarTrabajo(eTrabajo listaTrabajo[], int len, eMascota listaMascotas[], int lenMasc, eServicio listaServicio[], int lenServicio, int indice);


