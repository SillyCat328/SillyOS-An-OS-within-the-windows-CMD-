#ifndef MEMORY_H
#define MEMORY_H
#include "config.h"
#include <stdio.h>

#define RAM_F "ram.txt"
#define ROM_F "rom.txt"
#define ClearMemBuffer fopen(RAM_F, "w");

// Was going to write it as one whole function; the only problem with it is that it becomes a fucking mess.


void WriteToMem(const char* data){   
    

    FILE *pFile = fopen(RAM_F, "a");
    if(pFile != NULL){
        fprintf(pFile, "%s\n", data);
        fclose(pFile);
    }
    
    
}

void CallFromMem(char data, unsigned int TypeOfScene){

    //unsigned int Sc = scenes;
    switch (data)
    {
    case 's':
        TypeOfScene = 0;
        break;
    case 'l':
        TypeOfScene = 1;
        break;
    case 'h':
        TypeOfScene = 2;
        break;
    default:
        printf("No such scene exists or is defined.");
        break;
    }
}

#endif // MEMORY_H