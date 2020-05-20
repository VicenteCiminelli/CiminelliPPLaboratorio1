#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"
#include "menu.h"
#include "utn.h"



int alta(int proximoIdNotebook,eNotebook lp[], int tam,eMarca listaM[],int tamM, eTipo listaT[], int tamT)
{
    int todoOk=0;
    int indice= buscarEspacio(lp,tam);
    eNotebook auxiliar;

    system("cls");

    printf("\n***** Alta Notebook *****\n");
    printf("---------------------------\n\n");
    if(indice == -1)
    {
        printf("\nNo hay espacio disponible\n");
    }
    else
    {

            auxiliar.id=proximoIdNotebook;
            utn_getCadena(auxiliar.modelo,1,9999,"Ingrese el modelo: ","\n   Error! ingrese un modelo valido. \n");
            mostrarMs(listaM,tamM);
            utn_getEntero(&auxiliar.idMarca,3,"\nElija una opcion: ","\n  Opcion invalida! \n\n",1000,1003);
            mostrarTipos(listaT,tamT);
            utn_getEntero(&auxiliar.idTipo,3,"\nElija una opcion: ","\n  Opcion invalida! \n\n",5000,5003);
            utn_getFlotante(&auxiliar.precio,3,"Ingrese precio: ","\n  Error! ingrese un Precio valido.",1000,9999999999999);

            auxiliar.isEmpty=0;
            lp[indice]=auxiliar;
            todoOk=1;


    }


    return todoOk;
}

void modificarNotebook(eNotebook lp[], int id, float precio, char modelo[], int tam, int idMarca, int idTipo)
{
    char auxModelo[50];
    float auxPrecio;
    int auxIdMarca;
    int auxIdTipo;
    char opcionSalir;
    eNotebook auxNotebook;
    int encontrado = 0;

    printf("**** Modificacion de Notebook****\n\n");
    for(int i = 0; i < tam; i++)
    {
        if(lp[i].id == id)
        {
            auxNotebook = lp[i];
            do
            {
                fflush(stdin);
                switch(menuModificarNotebook())
                {
                case 1:
                    printf("Ingrese el nuevo modelo: ");
                    scanf("%s", auxModelo);
                    strcpy(auxNotebook.modelo, auxModelo);
                    break;
                case 2:
                    printf("Ingrese el nuevo precio: ");
                    scanf("%f", &auxPrecio);
                    auxNotebook.precio = auxPrecio;
                case 3:
                    printf("Ingrese el id de la marca: ");
                    scanf("%d", &auxIdMarca);
                    if(auxIdMarca < 1000 || auxIdMarca > 1003)
                    {
                        printf("Ingrese el un id de marca valido: ");
                        scanf("%d", &auxIdMarca);
                    }
                    else
                    {
                        auxNotebook.idMarca = auxIdMarca;
                    }

                    break;
                case 4:
                    printf("Ingrese el id del tipo: ");
                    scanf("%d", &auxIdTipo);
                    auxNotebook.idTipo = auxIdTipo;
                    break;
                case 5:
                    printf("Quiere salir? 's' para salir 'n' para quedarse: ");
                    fflush(stdin);
                    scanf("%c", &opcionSalir);
                    break;
                }

            }
            while(opcionSalir != 's');
            lp[i] = auxNotebook;
            encontrado = 1;
            break;
        }
    }
    if(encontrado == 0)
    {
        printf("No se encontro el id buscado");
    }
}

int findNotebookById(eNotebook* lp, int tam, int id)
{
	int indice = -1;
	for(int i = 0; i < tam; i++)
	{
		if( lp[i].id == id )
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int removeNotebook(eNotebook* lp, int tam, int id)
{
	int isOk = -1;
	eNotebook emptyNotebook;
	emptyNotebook.id = 0;
	emptyNotebook.isEmpty = 1;
	emptyNotebook.modelo[0] = '\0';
	emptyNotebook.precio = 0;
	emptyNotebook.idMarca = 0;
	emptyNotebook.idTipo = 0;

	int indice = findNotebookById(lp,tam,id);

				if(indice == -1 && lp == NULL)
				{
					printf("\nID incorrecto\n\n");
				}
				else
				{
				    lp[indice] = emptyNotebook;
                    printf("Empleado removido con exito.\n\n");
					isOk = 0;
				}

	return isOk;
}

void altaTrabajo(eTrabajo* lt,int id, int idNotebook, int idServicio,int fecha, int tamTr)
{
    id = 0;
    eTrabajo auxTrabajo;

            for(int i = 0; i < tamTr; i++)
            {
                    auxTrabajo.fecha = fecha;
                    auxTrabajo.id = id;
                    auxTrabajo.idNotebook = idNotebook;
                    auxTrabajo.idServicio = idServicio;
                    lt[i] = auxTrabajo;
                    id++;
                    break;
            }
}

void printNotebook(eNotebook* lp,int tam, char modelo[20], float precio, int idMarca, int idTipo, int id)
{

    printf("**** Listado de Notebook ****\n\n");
    printf(" Id                      modelo               precio            Marca      \n\n");

    for(int i = 0; i < tam; i++)
    {
        if(lp[i].isEmpty == 1)
            {
                printf("%d           %20s                 %2.f            %d  \n", lp[i].id, lp[i].modelo, lp[i].precio, lp[i].idMarca);
            }

    }
}

void printTrabajo(eTrabajo* lt,int id, int idNotebook, int idServicio,int fecha, int tamTr)
{

    printf("**** Listado de Notebook ****\n\n");
    printf(" Id                      idNotebook             idServicio            fecha      \n\n");

    for(int i = 0; i < tamTr; i++)
    {
        if(lt[i].id != 0)
            {
                printf("%d           %20s                   %2.f            %d  \n", lt[i].id, lt[i].idNotebook, lt[i].idServicio, lt[i].fecha);
            }

    }
}

int inicializarNotebook(eNotebook* lp,int tam)
{
	int inNo = -1;
	if(lp != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			lp[i].isEmpty = 1;
			inNo = 0;
		}
	}
	return inNo;

}

int buscarEspacio(eNotebook* lp, int tam)
{
	int indice = -1;
		for(int i = 0; i < tam; i++)
		{
			if(lp[i].isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	return indice;
}

int cargarDescripcionMarca(char descripcion[], int id, eMarca listaM[], int tamM)
{
    int todoOk= 0;

    for(int i=0; i<tamM; i++)
    {
        if(listaM[i].id == id)
        {
            strncpy(descripcion,listaM[i].descripcion,20);
            todoOk= 1;
        }
    }
    return todoOk;
}

int cargarDescripcionTipo(char descripcion[], int id, eTipo listaT[], int tamT)
{
    int todoOk= 0;

    for(int i=0; i<tamT; i++)
    {
        if(listaT[i].id== id)
        {
            strncpy(descripcion,listaT[i].descripcion,20);
            todoOk= 1;
        }
    }
    return todoOk;
}

void inicializarTrabajo(eTrabajo lt[], int tamS)
{
    for(int i=0; i<tamS; i++)
    {
        lt[i].isEmpty =1;
    }
}

int buscarLibreTrabajo(eTrabajo lt[], int tamS)
{
    int indice = -1;

    for(int i=0; i<tamS; i++)
    {
        if(lt[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int altaTrabajo(int proximoId,eTrabajo lt[], int tamT,eNotebook lp[], int tam, eServicio listaS[], int tamS)
{
    int todoOk=0;
    int indice= buscarLibreTrabajo(lt,tamT);
    int id;
    int existeIdNote;
    eTrabajo auxiliar;

    system("cls");

    printf("\n***** Alta Trabajo *****\n");
    printf("---------------------------\n\n");
    if(indice == -1)
    {
        printf("\nSistema Completo\n");
    }
    else
    {

        auxiliar.id=proximoId;
        mostrarNotebooksParaTrabajo(lp,tam);
        utn_getEntero(&id,3,"\nIngrese el id de lp: ","\n Id ingresado no es valido!! \n\n",1,100);
        existeIdNote=buscarIdNotebook(id,lp,tam);

        if(existeIdNote == -1)
        {
            printf("\n\n ESE ID NO EXISTE.");

        }
        else
        {
            auxiliar.idNotebook=id;

            mostrarServicios(listaS,tamS);
            utn_getEntero(&auxiliar.idServicio,3,"\nElija una opcion: ","\n  Opcion ingresada no es valida! \n\n",20000,20003);

            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxiliar.fechas.dia, &auxiliar.fechas.mes, &auxiliar.fechas.anio);


            auxiliar.isEmpty=0;
            lt[indice]=auxiliar;
            todoOk=1;
        }
    }
    return todoOk;
}

void listarTrabajo(eTrabajo lt, eNotebook lp[], int tam,eServicio listaS[], int tamS)
{
    char nombreNotebook[20];
    char nombreServicio[20];

    cargarDescripcionNotebook(nombreNotebook,lt.idNotebook,lp, tam);
    cargarDescripcionServicio(nombreServicio,lt.idServicio,listaS,tamS);
    printf("  %d   | %-10s  |   %-15s  |  %02d/%02d/%d    \n",lt.id,nombreNotebook,nombreServicio,lt.fechas.dia,lt.fechas.mes,lt.fechas.anio);

}


void listarTrabajos(eTrabajo lt[], int tamT,eNotebook lp[],int tam, eServicio listaS[], int tamS)
{
    int flag=0;
    system("cls");


    system("cls");
    printf("\n              ***** Listado de Trabajos *****\n");
    printf("   Id    |  Notebook   |      Servicio      |     Fecha     \n");
    printf("-----------------------------------------------------------\n");
    for(int i=0; i<tam; i++)
    {
        if(lt[i].isEmpty == 0)
        {
            listarTrabajo(lt[i],lp,tam,listaS,tamS);
            flag=1;

        }
    }
    if(flag==0)
    {
        printf("\n   No hay Trabajo que mostrar\n\n");
    }
}

int cargarDescripcionNotebook(char descripcion[], int id, eNotebook lp[], int tam)
{
    int todoOk= 0;

    for(int i=0; i<tam; i++)
    {
        if(lp[i].id == id)
        {
            strncpy(descripcion,lp[i].modelo,20);
            todoOk= 1;
        }
    }
    return todoOk;
}
int cargarDescripcionServicio(char descripcion[], int id, eServicio listaS[], int tamS)
{
    int todoOk= 0;

    for(int i=0; i<tamS; i++)
    {
        if(listaS[i].id == id)
        {
            strncpy(descripcion,listaS[i].descripcion,20);
            todoOk= 1;
        }
    }
    return todoOk;
}

int cargarPrecioDeServicio(float*  mostrarPrecio,int id, eServicio listaS[], int tamS )
{
   int todoOk = 0;

   for(int i=0;i<tamS;i++)
   {
       if(listaS[i].id == id)
       {
          *  mostrarPrecio = listaS[i].precio;
           todoOk=1;
       }
   }
   return todoOk;
}

void mostrarNotebooksParaTrabajo(eNotebook lp[], int tam)
{



    printf("** Listado de Notebooks \n");
    printf(" Id   |       Modelo    \n");
    printf("--------------------------\n");

    for(int i=0; i<tam; i++)
    {
        if(lp[i].isEmpty ==0)
        {
        printf("  %03d |  %-15s \n",lp[i].id,lp[i].modelo);

        }
    }

}
