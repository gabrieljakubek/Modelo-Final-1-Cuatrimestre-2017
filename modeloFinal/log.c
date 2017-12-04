#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fun.h"
#include "arrayList.h"
#include "log.h"

int parserLogEntry(ArrayList* arrayLogEntry,FILE* archivo)
{
    int retorno = 0, flag = 0;
    char auxDate[11], auxTime[6], auxServiceId[3], auxGravedad[2], auxMessage[66];
    eLogEntry* logEntry;
    if(arrayLogEntry!=NULL && archivo!=NULL)
    {
        if(arrayLogEntry->isEmpty(arrayLogEntry)==0)
        {
            arrayLogEntry->clear(arrayLogEntry);
        }
        while(!feof(archivo))
        {
            logEntry = newLogEntry();
            if(logEntry!=NULL)
            {
                fscanf(archivo,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxDate,auxTime,auxServiceId,auxGravedad,auxMessage);
                seterLogEntryDate(logEntry,auxDate);
                seterLogEntryTime(logEntry,auxTime);
                seterLogEntryServiceId(logEntry,atoi(auxServiceId));
                seterLogEntryGravedad(logEntry,atoi(auxGravedad));
                seterLogEntryMessage(logEntry,auxMessage);
                arrayLogEntry->add(arrayLogEntry,logEntry);
                flag = 1;
            }
        }
    }
    if(flag!=0)
    {
        retorno = 1;
    }
    return retorno;
}

eLogEntry* newLogEntry()
{
    eLogEntry* retorno = (eLogEntry*) malloc(sizeof(eLogEntry));
    return retorno;
}

void seterLogEntryDate(eLogEntry* logEntry, char date[])
{
    strcpy(logEntry->date,date);
}

void seterLogEntryTime(eLogEntry* logEntry, char time[])
{
    strcpy(logEntry->time,time);
}

void seterLogEntryServiceId(eLogEntry* logEntry, int ServId)
{
    logEntry->serviceId = ServId;
}

void seterLogEntryGravedad(eLogEntry* logEntry, int gravedad)
{
    logEntry->gravedad = gravedad;
}

void seterLogEntryMessage(eLogEntry* logEntry, char message[])
{
    strcpy(logEntry->msg,message);
}

char* getterLogEntryDate(eLogEntry* logEntry)
{
    return logEntry->date;
}

char* getterLogEntryTime(eLogEntry* logEntry)
{
    return logEntry->time;
}

int getterLogEntryServiceId(eLogEntry* logEntry)
{
    return logEntry->serviceId;
}

int getterLogEntryGravedad(eLogEntry* logEntry)
{
    return logEntry->gravedad;
}

char* getterLogEntryMessage(eLogEntry* logEntry)
{
    return logEntry->msg;
}
