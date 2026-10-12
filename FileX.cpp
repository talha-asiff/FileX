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
/*#include <fstream>
#include <iostream>
#include <string>
#include <inttypes.h>
#include <thread>
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
int currModeData = 1;
static int sendData(char * nameBuffer){
    WSADATA ws;
    cout<<"Initializing..."<<endl;
	if(WSAStartup(MAKEWORD(2,2), &ws) != 0){
	 	return 1;
	}
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET){
		WSACleanup();
		return 1;
	}
	sockaddr_in ser;
	ser.sin_family = AF_INET;
	ser.sin_port = htons(5555); 
	ser.sin_addr.s_addr = INADDR_ANY;
	bind(sock, (sockaddr*)&ser, sizeof(ser));
    if(listen(sock, 1) == SOCKET_ERROR){
	    closesocket(sock);
	    WSACleanup();
	    return 1;
	}
	else {
    	// DrawText("LISTENING...", 400, 270, 20, BLUE);
	}
	SOCKET acceptsock;
	acceptsock = accept(sock, NULL, NULL);
	if(acceptsock == INVALID_SOCKET){
		closesocket(sock);
		WSACleanup();
		return 1;
	}
	else {
        cout << "sending file"<<endl;
		// DrawText("SENDING FILE", 400, 270, 20, GREEN);
	}
    FILE *data = fopen(nameBuffer, "rb");
    uint8_t byte;
    cout << "recieving file"<<endl;
    while(fread(&byte, 1, 1, data)){
        send(acceptsock, (char *)byte, 1, 0);
    }
    cout << "file transfer done"<<endl;
    WSACleanup();
}

static int recvData(char * nameBuffer, string buff){
    
    WSADATA ws;
	if(WSAStartup(MAKEWORD(2,2), &ws) != 0){
        cout << "1"<<endl;
		return 1;
	}
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET){
        cout << "2"<<endl;
		WSACleanup();
		return 1;
	}
    sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(5555);
    ser.sin_addr.s_addr = inet_addr(buff.c_str());
    if(connect(sock, (sockaddr*)&ser, sizeof(ser)) == SOCKET_ERROR){
        closesocket(sock);
        WSACleanup();
        return 1;
    }
    FILE *data = fopen("downloaded.png", "wb");
    uint8_t byte;
    while(recv(sock, (char *)byte, 1, 0)){  
        cout << " [" << byte << " ] ";
         fwrite(&byte, 1, 1, data);
    }
    WSACleanup();
                    
}
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
                    
                    if(currModeData){
                         thread t(sendData, nameBuffer);
                        t.join();
                        currModeData = 0;
                    }
                    DrawText("FILE TRANSFER COMPLETED", 400, 290, 20, GREEN);
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
                   if(currModeData){
                     string buff;
                    getline(inp, buff);
                    thread t(recvData, nameBuffer, buff);
                    t.join();
                    currModeData = 0;
                   }
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
}*/
#include <fstream>
#include <iostream>
#include <string>
#include <inttypes.h>
#include <thread>

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

// Global state tracking
bool isTransferring = false;
bool transferCompleted = false;

static void sendData(string filePath) {
    isTransferring = true;
    
    WSADATA ws;
    if (WSAStartup(MAKEWORD(2, 2), &ws) != 0) {
        isTransferring = false;
        return;
    }
    
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        WSACleanup();
        isTransferring = false;
        return;
    }

    sockaddr_in ser{};
    ser.sin_family = AF_INET;
    ser.sin_port = htons(5555); 
    ser.sin_addr.s_addr = INADDR_ANY;

    if (::bind(sock, (sockaddr*)&ser, sizeof(ser)) == SOCKET_ERROR) {
        closesocket(sock);
        WSACleanup();
        isTransferring = false;
        return;
    }

    if (listen(sock, 1) == SOCKET_ERROR) {
        closesocket(sock);
        WSACleanup();
        isTransferring = false;
        return;
    }

    SOCKET acceptsock = accept(sock, NULL, NULL);
    if (acceptsock == INVALID_SOCKET) {
        closesocket(sock);
        WSACleanup();
        isTransferring = false;
        return;
    }

    FILE *data = fopen(filePath.c_str(), "rb");
    if (data) {
        uint8_t byte;
        // Fix: Pass pointer to address of byte
        while (fread(&byte, 1, 1, data) > 0) {
            if (send(acceptsock, (char *)&byte, 1, 0) == SOCKET_ERROR) {
                break;
            }
        }
        fclose(data);
        transferCompleted = true;
    }

    closesocket(acceptsock);
    closesocket(sock);
    WSACleanup();
    isTransferring = false;
}

static void recvData(string ipAddress) {
    isTransferring = true;

    WSADATA ws;
    if (WSAStartup(MAKEWORD(2, 2), &ws) != 0) {
        isTransferring = false;
        return;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        WSACleanup();
        isTransferring = false;
        return;
    }

    sockaddr_in ser{};
    ser.sin_family = AF_INET;
    ser.sin_port = htons(5555);
    ser.sin_addr.s_addr = inet_addr(ipAddress.c_str());

    if (connect(sock, (sockaddr*)&ser, sizeof(ser)) == SOCKET_ERROR) {
        closesocket(sock);
        WSACleanup();
        isTransferring = false;
        return;
    }

    FILE *data = fopen("downloaded.png", "wb");
    if (data) {
        uint8_t byte;
        // Fix: Pass pointer to address of byte
        while (recv(sock, (char *)&byte, 1, 0) > 0) {
            fwrite(&byte, 1, 1, data);
        }
        fclose(data);
        transferCompleted = true;
    }

    closesocket(sock);
    WSACleanup();
    isTransferring = false;
}

int main() {
    // Read cached IP address if available
    string savedIp = "";
    ifstream inp("C:\\FileX\\Data\\info.txt");
    if (inp.is_open()) {
        getline(inp, savedIp);
        inp.close();
    }

    InitWindow(800, 450, "FileX - LAN File Transfer System");
    SetTargetFPS(60);

    int mode = 0; // 0 = Home, 1 = Send, 2 = Recv
    char nameBuffer[64] = "";
    bool textBoxEditMode = false;

    Image img = LoadImage("logo.png");
    Texture2D texture = { 0 };
    if (img.data != NULL) {
        ImageResize(&img, 360, 180);
        texture = LoadTextureFromImage(img);
        UnloadImage(img);
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            
            if (texture.id > 0) {
                DrawTexture(texture, 70, 120, WHITE);
            }
            DrawText("LAN FILE TRANSFER PANEL - MADE BY TALHA ASIF", 40, 40, 20, RAYWHITE); 

            if (mode == 1) { // SEND MODE
                DrawText("SEND MODE - LIVE AT PORT 5555", 400, 130, 20, RAYWHITE);
                DrawText("ENTER FILE PATH TO SEND", 400, 160, 10, RAYWHITE);

                if (GuiTextBox((Rectangle){ 400, 180, 300, 40 }, nameBuffer, 64, textBoxEditMode)) {
                    textBoxEditMode = !textBoxEditMode;
                }

                if (!isTransferring && GuiButton((Rectangle){ 400, 230, 160, 40 }, "SEND")) {
                    transferCompleted = false;
                    thread t(sendData, string(nameBuffer));
                    t.detach(); // Allow async processing without locking main GUI thread
                }

                if (isTransferring) {
                    DrawText("WAITING FOR RECIPIENT...", 400, 280, 18, YELLOW);
                } else if (transferCompleted) {
                    DrawText("FILE TRANSFER COMPLETED", 400, 280, 18, GREEN);
                }

            } else if (mode == 2) { // RECEIVE MODE
                DrawText("RECEIVE MODE", 400, 130, 20, RAYWHITE);

                if (savedIp.empty()) {
                    DrawText("SERVER IP", 400, 160, 10, RAYWHITE);
                    if (GuiTextBox((Rectangle){ 400, 180, 300, 40 }, nameBuffer, 64, textBoxEditMode)) {
                        textBoxEditMode = !textBoxEditMode;
                    }

                    if (GuiButton((Rectangle){ 400, 230, 160, 40 }, "CONNECT AND SAVE")) {
                        savedIp = string(nameBuffer);
                        ofstream out("C:\\FileX\\Data\\info.txt");
                        if (out.is_open()) {
                            out << savedIp;
                            out.close();
                        }
                    }
                } else {
                    DrawText(TextFormat("TARGET IP: %s", savedIp.c_str()), 400, 160, 14, GREEN);

                    if (!isTransferring && GuiButton((Rectangle){ 400, 200, 160, 40 }, "START RECEIVE")) {
                        transferCompleted = false;
                        thread t(recvData, savedIp);
                        t.detach();
                    }

                    if (isTransferring) {
                        DrawText("RECEIVING FILE...", 400, 250, 18, YELLOW);
                    } else if (transferCompleted) {
                        DrawText("DOWNLOAD COMPLETED", 400, 250, 18, GREEN);
                    }
                }

            } else { // MAIN MENU (mode 0)
                if (GuiButton((Rectangle){ 400, 150, 160, 40 }, "SEND FILES")) {
                    mode = 1;
                }
                if (GuiButton((Rectangle){ 400, 210, 160, 40 }, "RECEIVE FILES")) {
                    mode = 2;
                }
            }
            
        EndDrawing();
    }

    if (texture.id > 0) {
        UnloadTexture(texture);
    }
    CloseWindow();
    return 0;
}
