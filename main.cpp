#include "include/raylib.h"
#include <stdlib.h>
#include <time.h>

int main(void) {

    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Ping Pong");
    SetTargetFPS(60);

	srand(time(NULL));

    int pagina = 1;
    int hardMode = 0, modalitaInfinito = 0, puntiVittoria = 11, regolaBattuta = 0;
    float ballX = 300, ballY = 300, ballSpeedX = 0, ballSpeedY = 0;
    float playerX = 265, playerY = 500, playerW = 70, playerH = 15;
    float cpuX = 265, cpuY = 85, cpuW = 70, cpuH = 15;
    int scorePlayer = 0, scoreCPU = 0, turnoBattuta = 1, puntiTotaliSegnati = 0;
    float timerBattutaCpu = 0.0f;

    while (!WindowShouldClose()) {
        // --- COLORI DEFAULT ---
        Color colG = DARKBLUE;   Color txtG = BLACK;   // Pagina 1
        Color colE = GREEN;      Color txtE = WHITE;   // Easy
        Color colH = RED;        Color txtH = WHITE;   // Hard
        Color colP = YELLOW;     Color txtP = WHITE;   // Punti e Battuta
        Color colInf = PURPLE;   Color txtInf = WHITE; // Infinito


        if (pagina == 1) {
            Rectangle rectG = { 80, 300, 450, 150 };
            if (CheckCollisionPointRec(GetMousePosition(), rectG)) {
                colG = BLUE; txtG = WHITE; // Più chiaro, testo bianco
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) pagina = 2;
            }
        }
        else if (pagina == 2) {
            Rectangle rectE = { 100, 220, 400, 100 };
            Rectangle rectH = { 100, 350, 400, 100 };
            if (CheckCollisionPointRec(GetMousePosition(), rectE)) {
                colE = DARKGREEN; txtE = BLACK;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { hardMode = 0; pagina = 3; }
            }
            if (CheckCollisionPointRec(GetMousePosition(), rectH)) {
                colH = MAROON; txtH = BLACK;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { hardMode = 1; pagina = 3; }
            }
        }
        else if (pagina == 3) {
            Rectangle r7 = { 100, 120, 400, 60 }, r11 = { 100, 200, 400, 60 }, r21 = { 100, 280, 400, 60 }, rInf = { 100, 360, 400, 60 };
            // Logica hover per i rettangoli gialli (punti) e viola (infinito)
            if (CheckCollisionPointRec(GetMousePosition(), r7))  { if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { puntiVittoria = 7; pagina = 4; } }
            if (CheckCollisionPointRec(GetMousePosition(), r11)) { if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { puntiVittoria = 11; pagina = 4; } }
            if (CheckCollisionPointRec(GetMousePosition(), r21)) { if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { puntiVittoria = 21; pagina = 4; } }
            if (CheckCollisionPointRec(GetMousePosition(), rInf)) {
                colInf = Color{ 128, 0, 128, 255 }; txtInf = BLACK;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { modalitaInfinito = 1; pagina = 4; }
            }
        }
        else if (pagina == 4) {
            // Qui i rettangoli gialli diventano più scuri (GOLD/ORANGE) e scritte nere al passaggio
            if (CheckCollisionPointRec(GetMousePosition(), { 100, 150, 400, 70 })) { if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { regolaBattuta = 0; pagina = 5; } }
            if (CheckCollisionPointRec(GetMousePosition(), { 100, 250, 400, 70 })) { if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { regolaBattuta = 1; pagina = 5; } }
            if (CheckCollisionPointRec(GetMousePosition(), { 100, 350, 400, 70 })) { if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) { regolaBattuta = 2; pagina = 5; } }
        }
        else if (pagina == 5) {

            playerX = GetMouseX() - playerW/2;
            if (playerX < 150) playerX = 150; if (playerX > 450 - playerW) playerX = 450 - playerW;
            playerY = GetMouseY() - playerH/2;
            if (playerY < 310) playerY = 310; if (playerY > 540) playerY = 540;

            float vCpu = (hardMode == 1) ? 5.2f : 3.5f;
            if (ballX > cpuX + cpuW/2) cpuX += vCpu; else cpuX -= vCpu;
            if (cpuX < 150) cpuX = 150; if (cpuX > 450 - cpuW) cpuX = 450 - cpuW;

            if (ballSpeedY == 0.0f) {
                if (turnoBattuta == 1) { if (IsKeyPressed(KEY_SPACE)) { ballSpeedY = -4.0f; ballSpeedX = (ballX > 300) ? -3.0f : 3.0f; } }
                else { timerBattutaCpu += GetFrameTime(); if (timerBattutaCpu > 1.5f) { ballSpeedY = 4.0f; ballSpeedX = (ballX > 300) ? -3.0f : 3.0f; timerBattutaCpu = 0.0f; } }
            }
            ballX += ballSpeedX; ballY += ballSpeedY;
            if (ballX < 160 || ballX > 440) ballSpeedX *= -1;

            if (ballSpeedY > 0 && CheckCollisionCircleRec({ballX, ballY}, 10, {playerX, playerY, playerW, playerH})) { ballSpeedY *= -1.1f; ballY = playerY - 11; ballSpeedX += (ballX - (playerX + playerW/2)) / 7; }
            if (ballSpeedY < 0 && CheckCollisionCircleRec({ballX, ballY}, 10, {cpuX, cpuY, cpuW, cpuH})) { ballSpeedY *= -1.1f; ballY = cpuY + cpuH + 11; ballSpeedX += (ballX - (cpuX + cpuW/2)) / 7; }

            bool puntoFatto = false;
int chiHaSegnato = 0; // 1 = giocatore, 2 = CPU

// Controllo chi ha segnato prima di resettare la palla
if (ballY < 50) {
    scorePlayer++;
    chiHaSegnato = 1;
    puntoFatto = true;
}
else if (ballY > 550) {
    scoreCPU++;
    chiHaSegnato = 2;
    puntoFatto = true;
}

// Se qualcuno ha fatto punto, reset palla e gestisci turno
if (puntoFatto) {
    ballX = 300;
    ballY = 300;
    ballSpeedX = 0;
    ballSpeedY = 0;
    timerBattutaCpu = 0.0f;
    puntiTotaliSegnati++;

    if (regolaBattuta == 0) turnoBattuta = chiHaSegnato;
    else if (regolaBattuta == 1) turnoBattuta = ((puntiTotaliSegnati / 2) % 2 == 0) ? 1 : 2;
    else if (regolaBattuta == 2) turnoBattuta = ((puntiTotaliSegnati / 5) % 2 == 0) ? 1 : 2;

    if (modalitaInfinito == 0 && (scorePlayer >= puntiVittoria || scoreCPU >= puntiVittoria)) {
        pagina = 1;
        scorePlayer = 0;
        scoreCPU = 0;
        puntiTotaliSegnati = 0;
    }
}

        }


        BeginDrawing();
        ClearBackground(BLACK);

        if (pagina == 1) {
            DrawText("PING PONG", 80, 70, 80, BLUE);
            DrawRectangle(80, 300, 450, 150, colG);
            DrawText("GIOCHIAMO", 170, 350, 60, txtG);
        }
        else if (pagina == 2) {
            DrawRectangle(100, 220, 400, 100, colE); DrawText("FACILE", 225, 255, 35, txtE);
            DrawRectangle(100, 350, 400, 100, colH); DrawText("DIFFICILE", 205, 385, 35, txtH);
        }
        else if (pagina == 3) {

            Color c7 = (CheckCollisionPointRec(GetMousePosition(), {100, 120, 400, 60})) ? GOLD : YELLOW;
            Color t7 = (CheckCollisionPointRec(GetMousePosition(), {100, 120, 400, 60})) ? BLACK : WHITE;
            DrawRectangle(100, 120, 400, 60, c7); DrawText("7 PUNTI", 230, 135, 30, t7);

            Color c11 = (CheckCollisionPointRec(GetMousePosition(), {100, 200, 400, 60})) ? GOLD : YELLOW;
            Color t11 = (CheckCollisionPointRec(GetMousePosition(), {100, 200, 400, 60})) ? BLACK : WHITE;
            DrawRectangle(100, 200, 400, 60, c11); DrawText("11 PUNTI", 225, 215, 30, t11);

            Color c21 = (CheckCollisionPointRec(GetMousePosition(), {100, 280, 400, 60})) ? GOLD : YELLOW;
            Color t21 = (CheckCollisionPointRec(GetMousePosition(), {100, 280, 400, 60})) ? BLACK : WHITE;
            DrawRectangle(100, 280, 400, 60, c21); DrawText("21 PUNTI", 225, 295, 30, t21);

            DrawRectangle(100, 360, 400, 60, colInf); DrawText("INFINITO", 220, 375, 30, txtInf);
        }
        else if (pagina == 4) {
            DrawText("REGOLA BATTUTA", 140, 50, 35, WHITE);

            Color r0 = (CheckCollisionPointRec(GetMousePosition(), {100, 150, 400, 70})) ? GOLD : YELLOW;
            Color rt0 = (CheckCollisionPointRec(GetMousePosition(), {100, 150, 400, 70})) ? BLACK : WHITE;
            DrawRectangle(100, 150, 400, 70, r0); DrawText("CHI SEGNA BATTE", 160, 175, 25, rt0);

            Color r1 = (CheckCollisionPointRec(GetMousePosition(), {100, 250, 400, 70})) ? GOLD : YELLOW;
            Color rt1 = (CheckCollisionPointRec(GetMousePosition(), {100, 250, 400, 70})) ? BLACK : WHITE;
            DrawRectangle(100, 250, 400, 70, r1); DrawText("OGNI 2 PUNTI", 200, 275, 25, rt1);

            Color r2 = (CheckCollisionPointRec(GetMousePosition(), {100, 350, 400, 70})) ? GOLD : YELLOW;
            Color rt2 = (CheckCollisionPointRec(GetMousePosition(), {100, 350, 400, 70})) ? BLACK : WHITE;
            DrawRectangle(100, 350, 400, 70, r2); DrawText("OGNI 5 PUNTI", 200, 375, 25, rt2);
        }
        else if (pagina == 5) {
            DrawRectangle(150, 50, 300, 500, Color{ 15, 15, 45, 255 });
            DrawRectangleLines(150, 50, 300, 500, WHITE); DrawLine(150, 300, 450, 300, GRAY);
            DrawCircle((int)ballX, (int)ballY, 10, YELLOW);
            DrawRectangle((int)playerX, (int)playerY, (int)playerW, (int)playerH, GREEN);
            DrawRectangle((int)cpuX, (int)cpuY, (int)cpuW, (int)cpuH, RED);
            DrawText(TextFormat("%i", scoreCPU), 50, 270, 60, RED);
            DrawText(TextFormat("%i", scorePlayer), 510, 270, 60, GREEN);
			if (ballSpeedY == 0.0f) {
    if (turnoBattuta == 1) {
        DrawText("PREMI SPAZIO PER BATTERE", 155, 320, 20, YELLOW);
    } else {
        DrawText("L'AVVERSARIO STA PER BATTERE...", 140, 320, 20, YELLOW);
    }
}

        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}