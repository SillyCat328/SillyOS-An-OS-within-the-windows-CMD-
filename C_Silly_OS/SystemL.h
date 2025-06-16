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

static void            STARTUP(void); // Remove the static keyword from these functions, as it will interfere with memory.h
static void        LOGINSCREEN(void);
static void         HOMESCREEN(void);
static void      _Applications(void);
static void          _SETTINGS(void);
static void     _BIOS_Settings(void);
static int          basic_login(char password[]);
void                TextLoad(char text[], unsigned int spaces, bool newline); // unsigned int size_of_text
void                Console_ColourBuffer(char colour[]);


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


void STARTUP(){ // Loaded to memory with: s 
    WriteToMem("s");
    Sleep(2000);
    //printf("Scene: %d", scenes);
    Sleep(2000); // Makes program sleep for 2 seconds.
    char S_OS[] = "Silly OS";
   
    TextLoad(S_OS, 56, false);
    Sleep(2000);
    system("cls");
    Sleep(2000);
    LOGINSCREEN();

}
// TODO: Later make a full admin/user system.
static void LOGINSCREEN(){ // Loaded to memory with: l 
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

static void HOMESCREEN(){ // Loaded to memory with: h
    
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
            break;
       case 2:
            _BIOS_Settings();
            break;
       case 3:
            _SETTINGS();
            break;
       case 4:
            SystemIsRunning = false;
            break;
       default:
            break;
       }
    }

    //_SETTINGS();  
}

static void _Applications(){
    system("cls");
    WriteToMem("_A");

    UIload(ApplicationUI);
}

static void _SETTINGS(){ // Loaded to memory with: _s
    system("cls");
    WriteToMem("_s");    

    UIload(SettingsUI);
}

static void _BIOS_Settings(){
    system("cls");
    WriteToMem("_BIOS"); 
    
    UIload(BIOS_SettingsUI);

}

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