#ifndef FILE_SYSTEMS_H
#define FILE_SYSTEMS_H
#include "config.h"

#define UI_BUFFER_SIZE 225

void UIload(const char* F_UI){
    FILE *pFile;

    pFile = fopen(F_UI, "r");

    if(pFile == NULL){
        perror("Error opening file, file doesn't exist or is corrupt.");
    }
    
    char UI[UI_BUFFER_SIZE];

    while(fgets(UI, UI_BUFFER_SIZE, pFile) != NULL) {
        printf("%s", UI);
    }

    fclose(pFile);

}

#endif // FILE_SYSTEMS_H q