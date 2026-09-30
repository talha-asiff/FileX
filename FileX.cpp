// #include <fstream>
// #include <iostream>
// #include <string>
// #define WIN32_LEAN_AND_MEAN
// #include <winsock2.h>
// #include <ws2tcpip.h>
// #include "raylib.h"
// #define RAYGUI_IMPLEMENTATION
// #include "raygui.h"
// using namespace std;
// // #pragma comment(lib, "ws2_32.lib")
#include <fstream>
#include <iostream>
#include <string>

// Windows Sockets setup
#define WIN32_LEAN_AND_MEAN
#define NOGDI             // Prevents wingdi.h from defining Rectangle and other GDI macros
#define NOUSER            // Avoids user32 macro conflicts if needed
#include <winsock2.h>
#include <ws2tcpip.h>

// Undefine conflicting Windows macros explicitly to safeguard Raylib
#ifdef Rectangle
  #undef Rectangle
#endif
#ifdef CloseWindow
  #undef CloseWindow
#endif
#ifdef ShowCursor
  #undef ShowCursor
#endif

// Raylib and Raygui setup
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

using namespace std;
int main() {
    ofstream out("C:\\FileX\\Data\\info.txt");
    ifstream inp("C:\\FileX\\Data\\info.txt");
    string line;
    while(getline(inp, line)){}
    InitWindow(800, 450, "FileX - LAN File Transfer System");
    SetTargetFPS(60);
    int clickCount = 0;
    int mode = 0;
    int mode2 = 0;
    if(line == ""){
        mode2 = 1;
    }
    Image img = LoadImage("logo.png");
    ImageResize(&img, 360, 180);
    Texture2D texture = LoadTextureFromImage(img);
    char nameBuffer[64] = "";
    bool textBoxEditMode = false;
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(texture, 70, 120, WHITE);
            DrawText("LAN FILE TRANSFER PANAL - MADE BY TALHA ASIF", 40, 40, 20, RAYWHITE); 
            if(mode == 1){
                DrawText("SEND MODE - LIVE AT PORT 5555", 400, 130, 20, RAYWHITE);
                DrawText("ENTER FILE PATH TO SEND", 400, 150, 10, RAYWHITE);
                if (GuiTextBox((Rectangle){ 400, 190, 300, 50 }, nameBuffer, 64, textBoxEditMode)) {
                    textBoxEditMode = !textBoxEditMode;
                }
                if (GuiButton((Rectangle){400 , 240, 160, 40 }, "SEND")) {
                    
                }
            } else if (mode == 2) {
                DrawText("RECV MODE", 400, 130, 20, RAYWHITE);
                if(mode == 0){
                    DrawText("SERVER IP", 400, 150, 10, RAYWHITE);
                if (GuiTextBox((Rectangle){ 400, 190, 300, 50 }, nameBuffer, 64, textBoxEditMode)) {
                    textBoxEditMode = !textBoxEditMode;
                }
                if (GuiButton((Rectangle){400 , 240, 160, 40 }, "CONNECT AND SAVE")) {
                    out << nameBuffer;
                    mode = 1;
                }
                } else {
                    DrawText("DOWNLOADING HOSTED FILE", 400, 150, 10, RAYWHITE);
                }

            } else {
                if (GuiButton((Rectangle){400 , 150, 160, 40 }, "SEND FILES")) {
                    mode = 1;
                }
                if (GuiButton((Rectangle){400 , 210, 160, 40 }, "RECIVE FILES")) {
                    mode = 2;
                }
            }
            
        EndDrawing();
    }
    UnloadImage(img);
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}