#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
int main() {
    InitWindow(800, 450, "FileX - LAN File Transfer System");
    SetTargetFPS(60);
    int clickCount = 0;
    Image img = LoadImage("logo.png");
    ImageResize(&img, 360, 180);
    Texture2D texture = LoadTextureFromImage(img);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(texture, 70, 120, WHITE);
            DrawText("PLEASE SELECT THE FILE TRANSFER MODE", 40, 40, 20, RAYWHITE); 
            if (GuiButton((Rectangle){400 , 150, 160, 40 }, "SEND FILES")) {
                clickCount++;
            }
            if (GuiButton((Rectangle){400 , 210, 160, 40 }, "RECIVE FILES")) {
                clickCount++;
            }
            
        EndDrawing();
    }
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}