#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
int main() {
    InitWindow(800, 450, "FileX - LAN File Transfer System");
    SetTargetFPS(60);
    int clickCount = 0;
    int mode = 0;
    Image img = LoadImage("logo.png");
    ImageResize(&img, 360, 180);
    Texture2D texture = LoadTextureFromImage(img);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(texture, 70, 120, WHITE);
            DrawText("LAN FILE TRANSFER PANAL", 40, 40, 20, RAYWHITE); 
            if(mode == 1){
                DrawText("SEND MODE", 400, 130, 20, RAYWHITE);
            } else if (mode == 2) {
                DrawText("RECV MODE", 400, 130, 20, RAYWHITE);
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
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}