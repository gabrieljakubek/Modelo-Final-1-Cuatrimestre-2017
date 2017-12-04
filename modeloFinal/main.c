#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
#include "arrayList.h"
#include "General.h"

int main()
{
    //system("mode con: cols=120 lines=30");
    system("color 2");
    int opcion;
    int auxInt;
    char seguir = 's';

    ArrayList* listaServices;
    ArrayList* listaLogEntry;

    listaServices = al_newArrayList();
    listaLogEntry = al_newArrayList();

    if(listaServices!=NULL && (listaLogEntry!=NULL))
    {
        do
        {
            opcion=mostrarMenu("1- Leer Log\
                              \n2- Procesar Informacion\
                              \n3- Listar\
                              \n4- Salir");
            switch(opcion)
            {
            case 1:
                auxInt=cargarLogs(listaServices,listaLogEntry);
                if(auxInt!=0)
                {
                    printf("Se cargaron los datos!!!");
                }
                else
                {
                    printf("\nNo se pudieron cargar los datos!!!");
                }
                borrarPantalla();
                break;

            case 2:
                if(listaServices->isEmpty(listaServices) == 0 && listaLogEntry->isEmpty(listaLogEntry) == 0)
                {
                    auxInt=procesarInfo(listaServices, listaLogEntry);
                    if(auxInt!=0)
                    {
                        printf("Se pudo procesar la informacion!!!");
                    }
                    else
                    {
                        printf("\nNo se pudo procesar la informacion!!!");
                    }
                }
                else
                {
                    printf("Lea los logs primero!!");
                }
                borrarPantalla();
                break;

            case 3:
                if(listaServices->isEmpty(listaServices) == 0 && listaLogEntry->isEmpty(listaLogEntry) == 0)
                {
                    mostrarEstadistica(listaServices,listaLogEntry);
                }
                else
                {
                    printf("Lea los logs primero!!");
                }
                borrarPantalla();
                break;

            case 4:
                seguir = 'n';
                printf("Chau Chau!!!!!");
                break;

            default:
                printf("Opcion inexistente!!!\n");
                borrarPantalla();
                break;
            }
        }
        while(seguir=='s');
    }

    return 0;
}
