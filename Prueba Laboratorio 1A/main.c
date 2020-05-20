#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"
#include "menu.h"
#include "utn.h"

#define tam 10
#define tamT 4
#define tamM 4
#define tamS 4
#define tamTr 10




int main()
{

    eNotebook lp[50];
    eTrabajo lt[50];
    inicializarNotebook(lp,tam);

    eMarca listaM[4] = {{1000,"Compaq"},{1001,"Asus"},{1002,"Acer"},{1003,"HP"} };
    eTipo listaT[4] = {{5000,"Gamer"},{5001,"Disenio"},{5002,"Ultrabook"},{5003,"Normalita"} };
    eServicio listaS[4] = {{20000,"Bateria",250},{20001,"Antivirus",300},{20002,"Actualizacion",400},{20003,"Fuente",600}};

    int id = 0;
    char modelo[20];
    int idMarca = 0;
    int idTipo = 0;
    float precio = 0;
    int opcion;
    int idNotebook;
    int idServicio;
    int fecha;
    int proximoIdNotebook;




    do
    {
        system("cls");
        menu();
        scanf("%d", &opcion);

        switch(opcion)
        {

            case 1:

                system("cls");
                printf("\n\n*****Alta Empleados*****\n");
                alta(proximoIdNotebook, lp, tam, listaM, tamM, listaT, tamT);
                break;

            case 2:
                system("cls");
                printf("ingrese el id de la notebook que desea modificar: ");
                scanf("%d", &id);
                modificarNotebook(lp, id, precio, modelo, tam, idMarca, idTipo);
                system("pause");
                break;

            case 3:

                system("cls");
                printf("Ingrese la id de la Notebook que desea dar de baja: ");
                scanf("%d",&id);
                removeNotebook(lp, tam, id);
                break;

            case 4:

                system("cls");
                printf("-*-*-*-*-*-*Listar Notebooks*-*-*-*-*-*-");
                printNotebook(lp, tam, modelo, precio, idMarca, idTipo, id);
                system("pause");
                break;

            case 5:
                system("cls");
                printf("-*-*-*-*-*-*Listar Marcas*-*-*-*-*-*-");
                mostrarMs(listaM, tamM);
                system("pause");
                break;

            case 6:
                system("cls");
                printf("-*-*-*-*-*-*Listar Tipos*-*-*-*-*-*-");
                mostrarTipos(listaT, tamT);
                system("pause");
                break;



            case 7:
                system("cls");
                printf("-*-*-*-*-*-*Listar Servicios*-*-*-*-*-*-");
                mostrarServicios(listaS, tamS);
                system("pause");
                break;

            case 8:
                system("cls");
                printf("\n\n*****Alta Trabajo*****\n");

                system("cls");
                printf("\n\n*****Alta Trabajo*****\n");
                printf("selecione una notebook por id");

                printf("\n\n");
                scanf("%d", &idNotebook);
                printf("\n\n*****Alta Trabajo*****\n");
                printf("\nseleccione un servicio por id: ");
                scanf("%d", &idServicio);
                system("cls");

                printf("\n\n*****Alta Trabajo*****\n");
                printf("ingrese una fecha: ");
                scanf("%d", &fecha);

                altaTrabajo(lt, id, idNotebook, idServicio, fecha, tamTr);
                break;

            case 9:
                system("cls");
                printf("-*-*-*-*-*-*Listar Trabajos*-*-*-*-*-*-");
                printTrabajo(lt, id, idNotebook, idServicio, fecha, tamTr);
                system("pause");
                break;


            case 10:
                system("cls");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-Hasta La Proxima-*-*-*-*-*-*-*-*-*-*-*\n");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
                break;

            default:
                printf("ingrese una opcion  valida");
                system("pause");


        }

    }while(opcion != 10);

    return 0;
}
