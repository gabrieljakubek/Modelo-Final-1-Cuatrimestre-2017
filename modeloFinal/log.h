#include "arrayList.h"

typedef struct
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];
} eLogEntry;

int parserLogEntry(ArrayList* arrayLogEntry,FILE* archivo);

eLogEntry* newLogEntry();

void seterLogEntryDate(eLogEntry* logEntry, char date[]);

void seterLogEntryTime(eLogEntry* logEntry, char time[]);

void seterLogEntryServiceId(eLogEntry* logEntry, int ServId);

void seterLogEntryGravedad(eLogEntry* logEntry, int gravedad);

void seterLogEntryMessage(eLogEntry* logEntry, char message[]);

char* getterLogEntryDate(eLogEntry* logEntry);

char* getterLogEntryTime(eLogEntry* logEntry);

int getterLogEntryServiceId(eLogEntry* logEntry);

int getterLogEntryGravedad(eLogEntry* logEntry);

char* getterLogEntryMessage(eLogEntry* logEntry);
