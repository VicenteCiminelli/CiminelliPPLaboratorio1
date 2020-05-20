#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "notebook.h"
#include "utn.h"

void menu()
{
    printf("MENU DE OPCIONES\n\n\n\n");
    printf("1. ALTA NOTEBOOK\n");
    printf("2. MODIFICAR NOTEBOOK\n");
    printf("3. BAJA NOTEBOOK\n");
    printf("4. LISTAR NOTEBOOKS\n");
    printf("5. LISTAR MARCAS\n");
    printf("6. LISTAR TIPOS\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. Salir\n");
}

int menuModificarNotebook()
{
    system("cls");
    int opcion;

    printf("\n\nQue desea modificar?:");
    printf("\n1.Modelo");
    printf("\n2.Precio");
    printf("\n3.Marca");
    printf("\n4.Tipo");
    printf("\n5.No quiero modificar nada");
    printf("\nIngrese la opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarTipos(eTipo listaT[], int tamT)
{
    printf("\n\nid        descripcion\n");

    for(int i = 0; i < tamT; i++)
    {
    printf("TIPOS\n\n");
    printf("%d        %s", listaT[i].id, listaT[i].descripcion);
    }
}

void mostrarMs(eMarca listaM[], int tamM)
{
    printf("\n\nid        descripcion\n");

    for(int i = 0; i < tamM; i++)
    {
    printf("Marcas\n\n");
    printf("%d        %s", listaM[i].id, listaM[i].descripcion);
    }
}


void mostrarServicios(eServicio listaS[], int tamS)
{
    printf("\n\nid        descripcion      precio\n");
        for(int i = 0; i < tamS; i++)
    {
    printf("Servicios\n\n");
    printf("%d        %s               %d", listaS[i].id, listaS[i].descripcion, listaS[i].precio);
    }
}


