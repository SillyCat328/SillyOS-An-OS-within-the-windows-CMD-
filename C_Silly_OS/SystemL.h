#ifndef SystemL_H
#define SystemL_H
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "config.h"

// UI-defnitions.
#define HomeUI "Home.UI"
#define ApplicationUI "Application.UI"
#define SettingsUI "Settings.UI"
#define BIOS_SettingsUI "BIOS_Settings.UI"
//----------------------------------------------------------------------------------------//
enum { // Unsigned int.
    START_UP,
    LOGIN_SCREEN,
    HOME_SCREEN, // Anything with the field H_ is a sub-catagory of SETTINGS.
    SETTINGS, // Anything with the field S_ is a sub-catagory of SETTINGS.
    S_CONTROLS,
    S_BACKGROUND_CHANGE,

} typedef E_Scenes;
unsigned int scenes = 0;
E_Scenes Scene;
//----------------------------------------------------------------------------------------//
void            STARTUP(void); // Remove the static keyword from these functions, as it will interfere with memory.h
void        LOGINSCREEN(void);
void         HOMESCREEN(void);
void      _Applications(void);
void          _SETTINGS(void);
void     _BIOS_Settings(void);
static int          basic_login(char password[]);
void                TextLoad(char text[], unsigned int spaces, bool newline); // unsigned int size_of_text
void                Console_ColourBuffer(char colour[]);

//----------------------------------------------------------------------------------------//
void screenRALF(){ // Screen Renderer.And.Logic.Function 

    // Screen Logic(rendering scenes/inputs)
  
    bool systemrunning = true;

    switch (scenes){
        case  START_UP: // Scene 0
                scenes = 0;
                STARTUP();
                break;
        case LOGIN_SCREEN: // Scene 1;
                scenes = 1;
                LOGINSCREEN();
                break;
        case HOME_SCREEN: // Scene 2
                scenes = 2; 
                HOMESCREEN();
                break;
        case SETTINGS: // Scene 3 
                scenes = 3;
                _SETTINGS();
            break;
         default:
            break;
        }
    
    
}

//----------------------------------------------------------------------------------------//
void STARTUP(){ // Loaded to memory with: s 
    system("cls");
    WriteToMem("s");
    Sleep(1000);
    //printf("Scene: %d", scenes);
    Sleep(2000); // Makes program sleep for 2 seconds.
    char S_OS[] = "Silly OS";
   
    TextLoad(S_OS, 56, false);
    Sleep(2000);
    system("cls");
    Sleep(2000);
    LOGINSCREEN();

}
//----------------------------------------------------------------------------------------//
// TODO: Later make a full admin/user system.
void LOGINSCREEN(){ // Loaded to memory with: l 
    r:
    WriteToMem("l");// Scene 1
    Console_ColourBuffer("1E");
    
    char input[10];
    printf("Enter password Penis: ");
    scanf("%s", &input);

    int Login_Result = basic_login(input);

    if(Login_Result == 1){
        HOMESCREEN();
    }
    
    while (Login_Result != 1){
        goto r;
    }
}
//----------------------------------------------------------------------------------------//
void HOMESCREEN(){ // Loaded to memory with: h
    
    system("cls");
    WriteToMem("h"); 
    //printf("Penis");
    UIload(HomeUI);

    bool SystemIsRunning = false;


    while (!SystemIsRunning)
    {
       int x;
       printf("Input: ");
       scanf("%d", &x);
       switch (x)
       {
       case 1: 
            _Applications();
            SystemIsRunning = false;
            break;
       case 2:
            _BIOS_Settings();
            SystemIsRunning = false;
            break;
       case 3:
            _SETTINGS();
            SystemIsRunning = false;
            break;
       case 4:
            exit(0);
            break;
       default:
            break;
       }
    }

    //_SETTINGS();  
}
//----------------------------------------------------------------------------------------//
void _Applications(){
    system("cls");
    WriteToMem("_A");

    UIload(ApplicationUI);
    bool ApplicationsIsRunning = false;

    while (!ApplicationsIsRunning)
    {
       int x;
       printf("Input: ");
       scanf("%d", &x);
       switch (x)
       {
       case 1:
           WriteToMem("_SP");
            ApplicationsIsRunning = false;
            break;
       case 2:
            WriteToMem("_MS");
            ApplicationsIsRunning = false;
            break;
       case 3:
            WriteToMem("_PC");
            ApplicationsIsRunning = false;
            break;
       case 4:
            WriteToMem("_S_IDE");
            ApplicationsIsRunning = false;
            break;
       case 5:
            HOMESCREEN();
            ApplicationsIsRunning = false;
            break;
       default:
            break;
       }
    }
}
//----------------------------------------------------------------------------------------//
void _SETTINGS(){ // Loaded to memory with: _s
    system("cls");
    WriteToMem("_s");    

    UIload(SettingsUI);

    bool _SETTINGSIsRunning = false;

    while (!_SETTINGSIsRunning)
    {
       int x;
       printf("Input: ");
       scanf("%d", &x);
       switch (x)
       {
       case 1:
            WriteToMem("_BC");
            CallFromMem(0);
            break;
       case 2:
            WriteToMem("_FC");
            break;
       case 3:
            WriteToMem("_SE");
            break;
       case 4:
            HOMESCREEN();
            _SETTINGSIsRunning = false;
            break;

       default:
            break;
       }
    }
}
//----------------------------------------------------------------------------------------//
void _BIOS_Settings(){
    system("cls");
    WriteToMem("_BIOS"); 
    
    UIload(BIOS_SettingsUI);

    bool _BIOSIsRunning = false;

    while (!_BIOSIsRunning)
    {
       int x;
       printf("Input: ");
       scanf("%d", &x);
       switch (x)
       {
       case 1:
            WriteToMem("_CR");
            break;
       case 2:
            WriteToMem("_RR");
            break;
       case 3:
            WriteToMem("_CS");
            break;
       case 4:
            HOMESCREEN();
            _BIOSIsRunning = false;
            break;
       default:
            break;
       }
    }

}
//----------------------------------------------------------------------------------------//
void TextLoad(char text[], unsigned int spaces, bool newline){ // unsigned int size_of_text. Arrays turn into pointers. 

    // -- Allows spaces -- 
    if(newline == true){
        for (int i = 0; i < spaces; i++){
            printf("%s\n"," ");
        }
    }
    else{
        for (int i = 0; i < spaces; i++){
            printf("%s"," ");
        }
    }
    ///////////////////////////////////////////////////////////////////
    for (int i = 0; i < strlen(text); i++){
        Sleep(100);
        printf("%c",text[i]); 
    }
}

void Console_ColourBuffer(char colour[]){ // Colour buffer.
    char command[10]; // ("COLOR %s", colour) is added to the variable
    sprintf(command, "COLOR %s", colour); 
    system(command);
}


int basic_login(char password[]) {
    // Predefined username and password
    char storedPassword[] = "Penis";

    if (strcmp(password, storedPassword) == 0) {
        return 1; 
    } else {
        return 0; 
    }
}

#endif // SystemL