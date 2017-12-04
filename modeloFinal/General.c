#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fun.h"
#include "arrayList.h"
#include "log.h"
#include "services.h"

int cargarLogs(ArrayList* arrayService, ArrayList* arrayLogEntry)
{
    int retorno = 0, auxResp1, auxResp2;
    FILE* logEntry;
    FILE* services;
    services=fopen("services.txt","r");
    logEntry=fopen("log.txt","r");
    if(services!=NULL&&logEntry!=NULL)
    {
        auxResp1=parserServices(arrayService,services);
        auxResp2=parserLogEntry(arrayLogEntry,logEntry);
        if(auxResp1!=0&&auxResp2!=0)
        {
            retorno=1;
        }
        fclose(services);
        fclose(logEntry);
    }
    return retorno;
}

int procesarInfo(ArrayList* arrayService, ArrayList* arrayLogEntry)
{
    int retorno = 0;
    int i,j,auxLogServiceId,auxServiceId,auxGravedad;
    char auxDate[11],auxTime[6],auxName[33], auxMessage[65], auxEmail[65];
    eService* service;
    eLogEntry* logEntry;
    FILE* warning;
    FILE* errors;
    warning = fopen("warning.txt","w");
    errors = fopen("errors.txt","w");
    if(arrayService!=NULL && (arrayLogEntry!=NULL) && errors!=NULL && (warning!=NULL))
    {
        service = newService();
        logEntry = newLogEntry();
        if(service!=NULL && (logEntry!=NULL))
        {
            system("cls");
            printf("%s;%s;%s;%s;%s\n","Fecha","Hora","Nombre servicio","Mensage","Gravedad");
            for(i=0; i<arrayLogEntry->len(arrayLogEntry); i++)
            {
                logEntry=arrayLogEntry->get(arrayLogEntry,i);
                auxGravedad = getterLogEntryGravedad(logEntry);
                auxLogServiceId = getterLogEntryServiceId(logEntry);
                strcpy(auxMessage,getterLogEntryMessage(logEntry));
                strcpy(auxDate,getterLogEntryDate(logEntry));
                strcpy(auxTime,getterLogEntryTime(logEntry));
                if(auxGravedad==3 && auxLogServiceId!=45)
                {
                    for(j=0; j<arrayService->len(arrayService); j++)
                    {
                        service=arrayService->get(arrayService,j);
                        auxServiceId = getterServiceId(service);
                        if(auxServiceId==auxLogServiceId)
                        {
                            strcpy(auxName,getterServiceName(service));
                            strcpy(auxEmail,getterServiceEmail(service));
                            break;
                        }
                    }
                    fprintf(warning,"%s;%s;%s;%s;%s\n",auxDate,auxTime,auxName,auxMessage,auxEmail);
                }
                else if(auxGravedad>=4 && auxGravedad<=7)
                {
                    for(j=0; j<arrayService->len(arrayService); j++)
                    {
                        service=arrayService->get(arrayService,j);
                        auxServiceId = getterServiceId(service);
                        if(auxServiceId==auxLogServiceId)
                        {
                            strcpy(auxName,getterServiceName(service));
                            strcpy(auxEmail,getterServiceEmail(service));
                            break;
                        }
                    }
                    printf("%s;%s;%s;%s;%d\n",auxDate,auxTime,auxName,auxMessage,auxGravedad);
                }
                else if(auxGravedad>7)
                {
                    for(j=0; j<arrayService->len(arrayService); j++)
                    {
                        service=arrayService->get(arrayService,j);
                        auxServiceId = getterServiceId(service);
                        if(auxServiceId==auxLogServiceId)
                        {
                            strcpy(auxName,getterServiceName(service));
                            strcpy(auxEmail,getterServiceEmail(service));
                            break;
                        }
                    }
                    fprintf(errors,"%s;%s;%s;%s;%s\n",auxDate,auxTime,auxName,auxMessage,auxEmail);
                }
            }
            retorno = 1;
        }
    }
    return retorno;
}

void mostrarEstadistica(ArrayList* arrayService, ArrayList* arrayLogEntry)
{
    int i,j,auxServiceId, auxLogServiceId, maxCant, flag = 0,auxGravedad;
    int cantService = arrayService->len(arrayService);
    int vectService[cantService], cantGravedad[4] = {};
    char auxName[33];
    eService* service;
    eLogEntry* logEntry;
    if(arrayService!=NULL && (arrayLogEntry!=NULL))
    {
        service=newService();
        logEntry=newLogEntry();
        for(i=0; i<cantService; i++)
        {
            service=arrayService->get(arrayService,i);
            auxServiceId = getterServiceId(service);
            for(j=0;j<arrayLogEntry->len(arrayLogEntry);j++)
            {
                logEntry=arrayLogEntry->get(arrayLogEntry,j);
                auxLogServiceId = getterLogEntryServiceId(logEntry);
                if(auxServiceId==auxLogServiceId)
                {
                    vectService[i]++;
                }
            }
            if(flag==0)
            {
                maxCant = vectService[i];
                flag = 1;
            }
            else if(vectService[i]>maxCant)
            {
                maxCant = vectService[i];
            }
        }
        for(i=0; i<cantService; i++)
        {
            if(maxCant == vectService[i])
            {
                service=arrayService->get(arrayService,i);
                strcpy(auxName,getterServiceName(service));
                printf("El servicio con mas fallos es el de: %s\n",auxName);
            }
        }
        for(i=0;i<arrayLogEntry->len(arrayLogEntry);i++)
        {
            logEntry=arrayLogEntry->get(arrayLogEntry,i);
            auxGravedad=getterLogEntryGravedad(logEntry);
            if(auxGravedad<3)
            {
                cantGravedad[0]++;
            }
            else if(auxGravedad==3)
            {
                cantGravedad[1]++;
            }
            else if(auxGravedad>=4 && auxGravedad<=7)
            {
                cantGravedad[2]++;
            }
            else
            {
                cantGravedad[3]++;
            }
        }
        printf("La cantidad de fallos de gravedad menor a 3 es de:%d\n",cantGravedad[0]);
        printf("La cantidad de fallos de gravedad 3 es de:%d\n",cantGravedad[1]);
        printf("La cantidad de fallos de gravedad entre 4 y 7 es de:%d\n",cantGravedad[2]);
        printf("La cantidad de fallos de gravedad mayor a 7 es de:%d\n",cantGravedad[3]);
    }
}
