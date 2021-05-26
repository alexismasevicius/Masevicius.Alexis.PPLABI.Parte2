#include "tipos.h"
#include "color.h"


#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct{
    int id;
    char nombre[51];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
}eMascota;

#endif // MASCOTAS_H_INCLUDED
void inicializarMascota (eMascota lista[], int tam);
int buscarLibreMascota(eMascota lista[], int len);
int buscarMascota(eMascota lista[], int len,int codigo);
int altaMascota(eMascota listaMascota[], int len,int* idMascota, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColor);
int mostrarMascotas(eMascota listaMascota[],int lenMas, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores);
int mostrarMascota(eMascota listaMascota[],int lenMas, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores, int indice);
int modificarMascotas(eMascota listaMascota[],int lenMas, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores);
int modificarMascota(eMascota lista[], int len, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores,int opcion, int indice);
int bajaMascota (eMascota lista[],int lenMas, eTipos listaTipos[], int tamTipos, eColores listaColores[], int tamColores);
int cargarNombreMascota (int id, eMascota lista[], int tam, char descripcionCargar[]);
int ordenarMascotasPorNombre(eMascota lista[], int tam);
