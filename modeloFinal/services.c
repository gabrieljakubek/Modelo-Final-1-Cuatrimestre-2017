#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fun.h"
#include "arrayList.h"
#include "services.h"

int parserServices(ArrayList* arrayService,FILE* archivo)
{
    int retorno = 0, flag = 0;
    char auxId[6], auxName[34], auxEmail[66];
    eService* service;
    if(arrayService!=NULL && archivo!=NULL)
    {
        if(arrayService->isEmpty(arrayService)==0)
        {
            arrayService->clear(arrayService);
        }
        while(!feof(archivo))
        {
            service = newService();
            if(service!=NULL)
            {
                fscanf(archivo,"%[^;];%[^;];%[^\n]\n",auxId,auxName,auxEmail);
                seterServiceId(service,atoi(auxId));
                seterServiceName(service,auxName);
                seterServiceEmail(service,auxEmail);
                arrayService->add(arrayService,service);
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

eService* newService()
{
    eService* retorno = (eService*)malloc(sizeof(eService));
    return retorno;
}

void seterServiceId(eService* service, int ID)
{
    service->id = ID;
}

void seterServiceName(eService* service, char name[])
{
    strcpy(service->name,name);
}

void seterServiceEmail(eService* service, char email[])
{
    strcpy(service->email,email);
}

int getterServiceId(eService* service)
{
    return service->id;
}

char* getterServiceName(eService* service)
{
    return service->name;
}

char* getterServiceEmail(eService* service)
{
    return service->email;
}
