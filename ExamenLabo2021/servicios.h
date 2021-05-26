#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;
    int isEmpty;
}eServicio;


#endif // SERVICIOS_H_INCLUDED

int mostarServicios(eServicio lista[], int len);
int mostrarServicio(eServicio lista[], int indice);
int buscarServicio(eServicio lista[], int len,int codigo);
int cargarNombreServicio (int id, eServicio lista[], int tam, char descripcionCargar[]);
