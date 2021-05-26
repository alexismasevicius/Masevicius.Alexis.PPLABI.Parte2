#include "mascotas.h"
#include "tipos.h"
#include "color.h"
#include "trabajos.h"
#include "servicios.h"


#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

void mostrarMascotasDeTipo(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores);

void mostrarMascotasDeColor(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores);

void mascotasMenorEdad(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores);

void mostarMascotasPorTipo(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores);

void cantidadMascotasPorColorYTipo(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores);

void coloresMasMascotas(eMascota listaMascotas[],int lenMas, eTipos listaTipos[], int lenTipos, eColores listaColores[], int lenColores);

void serviciosPorMascota(eMascota listaMascotas[],int lenMascotas, eTipos listaTipos[], int lenTipos, eColores listaColores[],
                             int lenColores, eTrabajo listaTrabajos[], int lenTrabajos, eServicio listaServicios[], int lenServicios);

void  importeServiciosPorMascota(eMascota listaMascotas[],int lenMascotas, eTipos listaTipos[], int lenTipos, eColores listaColores[],
                             int lenColores, eTrabajo listaTrabajos[], int lenTrabajos, eServicio listaServicios[], int lenServicios);

void  serviciosRealizados(eMascota listaMascotas[],int lenMascotas, eTipos listaTipos[], int lenTipos, eColores listaColores[],
                             int lenColores, eTrabajo listaTrabajos[], int lenTrabajos, eServicio listaServicios[], int lenServicios);

void  serviciosRealizadosPorFecha(eMascota listaMascotas[],int lenMascotas, eTipos listaTipos[], int lenTipos, eColores listaColores[],
                             int lenColores, eTrabajo listaTrabajos[], int lenTrabajos, eServicio listaServicios[], int lenServicios);
/*
int totalTipoPorServicio (eMascota listaMascotas[],int lenMascotas, eTipos listaTipos[], int lenTipos, eColores listaColores[],
                             int lenColores, eTrabajo listaTrabajos[], int lenTrabajos, eServicio listaServicios[], int lenServicios);


int mascotasQueNoTienenTrabajos(eMascota listaMascotas[],int lenMascotas, eTrabajo listaTrabajos[], int lenTrabajos);
*/
