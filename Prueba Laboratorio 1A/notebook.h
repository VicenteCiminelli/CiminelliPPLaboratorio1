#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;

}eNotebook;

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

typedef struct
{
    int id;
    char descripcion[20];
    int precio;

}eServicio;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    int fecha;
    int isEmpty;

}eTrabajo;

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

#endif // NOTEBOOK_H_INCLUDED

int alta(int proximoIdNotebook,eNotebook lp[], int tam,eMarca listaM[],int tamM, eTipo listaT[], int tamT);

void modificarNotebook(eNotebook lp[], int id, float precio, char modelo[], int tam, int idMarca, int idTipo);

int removeNotebook(eNotebook* lp, int tam, int id);

void hardcodeoMarca(eMarca listaM[4], int tamM);

void hardcodeoServicios (eServicio listaS[4], int tamS);

void hardcodeoTipo(eTipo listaT[4], int tamT);

void printNotebook(eNotebook* lp,int tam, char modelo[20], float precio, int idMarca, int idTipo, int id);

int findNotebookById(eNotebook* lp, int tam, int id);

void printTrabajo(eTrabajo* lt,int id, int idNotebook, int idServicio,int fecha, int tamTr);

void altaTrabajo(eTrabajo* lt,int id, int idNotebook, int idServicio,int fecha, int tamTr);

int inicializarNotebook(eNotebook* lp,int tam);

int buscarEspacio(eNotebook* lp, int tam);
