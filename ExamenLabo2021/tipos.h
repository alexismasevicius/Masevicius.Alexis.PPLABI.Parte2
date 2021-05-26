#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct{
    int id;
    char descripcion[50];
    int isEmpty;
}eTipos;

#endif // TIPOS_H_INCLUDED

int mostarTipos(eTipos lista[], int len);
int mostrarTipo(eTipos lista[], int indice);
int buscarTipo(eTipos lista[], int len,int codigo);
int cargarNombreTipo(int idTipo, eTipos lista[], int tam, char descripcionCargar[]);
