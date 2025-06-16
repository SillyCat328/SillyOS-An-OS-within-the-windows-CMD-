#ifndef MEMORY_H
#define MEMORY_H
#include "config.h"
#include <stdio.h>

#define RAM_F "ram.txt"
#define ROM_F "rom.txt"
#define ClearMemBuffer fopen(RAM_F, "w");
#define MemBuffer 1024
// Was going to write it as one whole function; the only problem with it is that it becomes a fucking mess.


void WriteToMem(const char* data){   
    

    FILE *pFile = fopen(RAM_F, "a");
    if(pFile != NULL){
        fprintf(pFile, "%s\n", data);
        fclose(pFile);
    }
    
    
}

void CallFromMem(unsigned int MemNum){

    char MemFunctions[MemBuffer] = 
    {'s', 'l', 'h', // 0, 1, 2
        '_A', '_SP', '_MS', '_PC', '_S_IDE', // 3, 4, 5, 6, 7
        '_s ', '_BC', '_FC', '_SE', // 8, 9, 10, 11
        '_BIOS', '_CR', '_RR', '_CS'}; // 12, 13, 14, 15


    switch (MemFunctions[MemNum])
    {
    case  0:
        STARTUP();
        break;
    case 1:
        LOGINSCREEN();
        break;
    case 2:
        HOMESCREEN();
        break;
    case 3:
        _Applications();
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        _SETTINGS();
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        _BIOS_Settings();
        break;
    case 13:
        break;
    case 14:
        break;
    case 15:
        break;
    
    default:
        printf("Not a valid call value");
        break;
    }
}

#endif // MEMORY_H