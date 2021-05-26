#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
    int isEmpty;
}eColores;

#endif // COLOR_H_INCLUDED

int mostarColores(eColores lista[], int len);
int mostrarColor(eColores lista[], int indice);
int buscarColor(eColores lista[], int len,int codigo);
int cargarNombreColor (int id, eColores lista[], int tam, char descripcionCargar[]);
