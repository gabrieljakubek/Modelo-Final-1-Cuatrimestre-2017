#include "arrayList.h"

typedef struct
{
    int id;
    char name[33];
    char email[65];
} eService;

int parserServices(ArrayList* arrayService,FILE* archivo);

eService* newService();

void seterServiceId(eService* service, int ID);

void seterServiceName(eService* service, char name[]);

void seterServiceEmail(eService* service, char email[]);

int getterServiceId(eService* service);

char* getterServiceName(eService* service);

char* getterServiceEmail(eService* service);
