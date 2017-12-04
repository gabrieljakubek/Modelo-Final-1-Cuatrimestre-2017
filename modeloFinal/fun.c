#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "fun.h"


char mostrarMenu(char texto[])
{
    char opcion [2];
    int auxResp, respuesta;
    printf("%s", texto);
    printf("\nIngrese la opcion a usar: ");
    fflush(stdin);
    gets(opcion);
    auxResp = chequeoNumero(opcion);
    if(auxResp!=1)
    {
        respuesta = 0;
    }
    else
    {
        respuesta=atoi(opcion);
    }
    return respuesta;
}

void borrarPantalla()
{
    system("pause");
    system("cls");
}

int chequeoNumero(char num[])
{
    int i = 0;
    int flag = 1;
    while (num[i]!='\0')
    {
        if(!isdigit(num[i]))
        {
            flag=0;
            break;
        }
        i++;
    }
    return flag;
}

int chequeoFloat(char num[])
{
    int i = 0, cont, contPunt = 0;
    int flag = 0;
    cont = strlen(num);
    while(i<cont && flag == 0)
    {
        if(isdigit(num[i])!=0)
        {
            i++;
        }
        else if(num[i]== '.' && contPunt <1)
        {
            i++;
            contPunt++;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}

char* charDyn(char buffer[] )
{
    char* returnAux;
    char* texto;
    texto = (char*)malloc(sizeof(char)*strlen(buffer)+1);
    if(texto!=NULL)
    {
        strcpy(texto,buffer);
        returnAux = texto;
    }
    return returnAux;
}


