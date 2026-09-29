#include "raylib.h"

int main() {
    InitWindow(800, 450, "Raylib VS Code Setup");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Raylib is running!", 280, 200, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}