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
        '_s', '_BC', '_FC', '_SE', // 8, 9, 10, 11
        '_BIOS', '_CR', '_RR', '_CS'}; // 12, 13, 14, 15


    switch (MemFunctions[MemNum])
    {
    case  's':
        STARTUP();
        break;
    case 'l':
        LOGINSCREEN();
        break;
    case 'h':
        HOMESCREEN();
        break;
    case '_A':
        _Applications();
        break;
    case '_SP':
        break;
    case '_MS':
        break;
    case '_PC':
        break;
    case '_S_IDE':
        break;
    case '_s':
        _SETTINGS();
        break;
    case '_BC':
        break;
    case '_FC':
        break;
    case '_SE':
        break;
    case '_BIOS':
        _BIOS_Settings();
        break;
    case '_CR':
        break;
    case '_RR':
        break;
    case '_CS':
        break;
    
    default:
        printf("Not a valid call value");
        break;
    }
}

#endif // MEMORY_H