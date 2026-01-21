#include <iostream>
#include "include/raylib.h"

bool TabellonePieno(int c1,int c2,int c3,int c4,int c5,int c6,int c7,int c8,int c9) {
    return (c1!=0 && c2!=0 && c3!=0 &&
            c4!=0 && c5!=0 && c6!=0 &&
            c7!=0 && c8!=0 && c9!=0);
}


// ================= VITTORIA =================
int vittoria(int c1,int c2,int c3,int c4,int c5,int c6,int c7,int c8,int c9)
{
    if (c1==c2 && c2==c3 && c1!=0) return c1;
    if (c1==c4 && c4==c7 && c1!=0) return c1;
    if (c1==c5 && c5==c9 && c1!=0) return c1;
    if (c2==c5 && c5==c8 && c2!=0) return c2;
    if (c3==c6 && c6==c9 && c3!=0) return c3;
    if (c4==c5 && c5==c6 && c4!=0) return c4;
    if (c7==c5 && c5==c3 && c7!=0) return c7;
    if (c7==c8 && c8==c9 && c7!=0) return c7;
    return 0;
}

// ================= COMPUTER =================
void Computer(int& c1,int& c2,int& c3,int& c4,int& c5,
              int& c6,int& c7,int& c8,int& c9,int simboloC)
{
    if(TabellonePieno(c1,c2,c3,c4,c5,c6,c7,c8,c9))return;
    bool mossa = false;
    while(!mossa)
    {
        int scelta = rand() % 9 + 1;
        if(scelta==1 && c1==0) {
            c1=simboloC;
            mossa=true;
        }
        if(scelta==2 && c2==0) {
            c2=simboloC;
            mossa=true;
        }
        if(scelta==3 && c3==0) {
            c3=simboloC;
            mossa=true;
        }
        if(scelta==4 && c4==0) {
            c4=simboloC;
            mossa=true;
        }
        if(scelta==5 && c5==0) {
            c5=simboloC;
            mossa=true;
        }
        if(scelta==6 && c6==0) {
            c6=simboloC;
            mossa=true;
        }
        if(scelta==7 && c7==0) {
            c7=simboloC;
            mossa=true;
        }
        if(scelta==8 && c8==0) {
            c8=simboloC;
            mossa=true;
        }
        if(scelta==9 && c9==0) {
            c9=simboloC;
            mossa=true;
        }
    }
}
void ComputerHard (int& c1,int& c2,int& c3,int& c4,int& c5,
              int& c6,int& c7,int& c8,int& c9,int simboloC, int simbolop) {
    if(TabellonePieno(c1,c2,c3,c4,c5,c6,c7,c8,c9))return;
    if(c1==simboloC && c2==simboloC && c3==0) {
        c3=simboloC;
    }
    if(c1==simboloC && c3==simboloC && c2==0) {
        c2=simboloC;
    }
    if(c2==simboloC && c3==simboloC && c1==0) {
        c1=simboloC;
    }

    if(c4==simboloC && c5==simboloC && c6==0) {
        c6=simboloC;
    }
    if(c4==simboloC && c6==simboloC && c5==0) {
        c5=simboloC;
    }
    if(c5==simboloC && c6==simboloC && c4==0) {
        c4=simboloC;
    }

    if(c7==simboloC && c8==simboloC && c9==0) {
        c9=simboloC;
    }
    if(c7==simboloC && c9==simboloC && c8==0) {
        c8=simboloC;
    }
    if(c8==simboloC && c9==simboloC && c7==0) {
        c7=simboloC;
    }

    if(c1==simboloC && c4==simboloC && c7==0) {
        c7=simboloC;
    }
    if(c1==simboloC && c7==simboloC && c4==0) {
        c4=simboloC;
    }
    if(c4==simboloC && c7==simboloC && c1==0) {
        c1=simboloC;
    }

    if(c2==simboloC && c5==simboloC && c8==0) {
        c8=simboloC;
    }
    if(c2==simboloC && c8==simboloC && c5==0) {
        c5=simboloC;
    }
    if(c5==simboloC && c8==simboloC && c2==0) {
        c2=simboloC;
    }

    if(c3==simboloC && c6==simboloC && c9==0) {
        c9=simboloC;
    }
    if(c3==simboloC && c9==simboloC && c6==0) {
        c6=simboloC;
    }
    if(c6==simboloC && c9==simboloC && c3==0) {
        c3=simboloC;
    }

    if(c1==simboloC && c5==simboloC && c9==0) {
        c9=simboloC;
    }
    if(c1==simboloC && c9==simboloC && c5==0) {
        c5=simboloC;
    }
    if(c5==simboloC && c9==simboloC && c1==0) {
        c1=simboloC;
    }

    if(c3==simboloC && c5==simboloC && c7==0) {
        c7=simboloC;
    }
    if(c3==simboloC && c7==simboloC && c5==0) {
        c5=simboloC;
    }
    if(c5==simboloC && c7==simboloC && c3==0) {
        c3=simboloC;
    }

    if(c1==simbolop && c2==simbolop && c3==0) {
        c3=simboloC;
    }
    if(c1==simbolop && c3==simbolop && c2==0) {
        c2=simboloC;
    }
    if(c2==simbolop && c3==simbolop && c1==0) {
        c1=simboloC;
    }

    if(c4==simbolop && c5==simbolop && c6==0) {
        c6=simboloC;
    }
    if(c4==simbolop && c6==simbolop && c5==0) {
        c5=simboloC;
    }
    if(c5==simbolop && c6==simbolop && c4==0) {
        c4=simboloC;
    }

    if(c7==simbolop && c8==simbolop && c9==0) {
        c9=simboloC;
    }
    if(c7==simbolop && c9==simbolop && c8==0) {
        c8=simboloC;
    }
    if(c8==simbolop && c9==simbolop && c7==0) {
        c7=simboloC;
    }

    if(c1==simbolop && c4==simbolop && c7==0) {
        c7=simboloC;
    }
    if(c1==simbolop && c7==simbolop && c4==0) {
        c4=simboloC;
    }
    if(c4==simbolop && c7==simbolop && c1==0) {
        c1=simboloC;
    }

    if(c2==simbolop && c5==simbolop && c8==0) {
        c8=simboloC;
    }
    if(c2==simbolop && c8==simbolop && c5==0) {
        c5=simboloC;
    }
    if(c5==simbolop && c8==simbolop && c2==0) {
        c2=simboloC;
    }

    if(c3==simbolop && c6==simbolop && c9==0) {
        c9=simboloC;
    }
    if(c3==simbolop && c9==simbolop && c6==0) {
        c6=simboloC;
    }
    if(c6==simbolop && c9==simbolop && c3==0) {
        c3=simboloC;
    }

    if(c1==simbolop && c5==simbolop && c9==0) {
        c9=simboloC;
    }
    if(c1==simbolop && c9==simbolop && c5==0) {
        c5=simboloC;
    }
    if(c5==simbolop && c9==simbolop && c1==0) {
        c1=simboloC;
    }

    if(c3==simbolop && c5==simbolop && c7==0) {
        c7=simboloC;
    }
    if(c3==simbolop && c7==simbolop && c5==0) {
        c5=simboloC;
    }
    if(c5==simbolop && c7==simbolop && c3==0) {
        c3=simboloC;
    }

    bool mossa = false;
    while(!mossa)
    {
        int scelta = rand() % 9 + 1;
        if(scelta==1 && c1==0) {
            c1=simboloC;
            mossa=true;
        }
        if(scelta==2 && c2==0) {
            c2=simboloC;
            mossa=true;
        }
        if(scelta==3 && c3==0) {
            c3=simboloC;
            mossa=true;
        }
        if(scelta==4 && c4==0) {
            c4=simboloC;
            mossa=true;
        }
        if(scelta==5 && c5==0) {
            c5=simboloC;
            mossa=true;
        }
        if(scelta==6 && c6==0) {
            c6=simboloC;
            mossa=true;
        }
        if(scelta==7 && c7==0) {
            c7=simboloC;
            mossa=true;
        }
        if(scelta==8 && c8==0) {
            c8=simboloC;
            mossa=true;
        }
        if(scelta==9 && c9==0) {
            c9=simboloC;
            mossa=true;
        }
    }
}

void DisegnaSimbolo(int valore,int col,int row,int inizioX,int inizioY,int cella)
{
    int cx=inizioX+col*cella+cella/2;
    int cy=inizioY+row*cella+cella/2;

    if(valore==1)
        DrawCircleLines(cx,cy,cella/3,BLUE);
    else if(valore==2)
    {
        int s=cella/2;
        DrawRectangleLines(cx-s/2,cy-s/2,s,s,RED);
    }
}


int main()
{
    const int screenWidth=800;
    const int screenHeight=800;
    const int cella=200;
    const int campo=600;

    int inizioX=(screenWidth-campo)/2;
    int inizioY=(screenHeight-campo)/2;

    InitWindow(screenWidth,screenHeight,"TRIS");
    SetTargetFPS(60);


    Rectangle contornogiochiamo={140,400,510,150};
    Rectangle contornohard={500,300,200,150};
    Rectangle contornoeasy={100,300,200,150};


    bool primapagina=true;
    bool secondapagina=false;
    bool terzapagina=false;
    bool quartapagina=false;

    bool easy=false,hard=false;
    bool cerchio=false,quadrato=false;


    int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0;
    int simbolop=0,simboloc=0;
    int turno=1;
    int vincitore=0;

    while(!WindowShouldClose())
    {
        // ===== COLORI =====
        Color colGiochiamo=BLUE;
        Color coloreTesto = BLACK;
        Color colHard=RED;
        Color colEasy=GREEN;
        Color colCerchio=BLUE;
        Color colQuadrato=BLUE;

        // ===== TRANSIZIONI =====
        if(primapagina){
            if(CheckCollisionPointRec(GetMousePosition(),contornogiochiamo)){
                colGiochiamo=DARKBLUE;
                coloreTesto = WHITE;
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    primapagina=false;
                    secondapagina=true;
                }
            }
        }
        else if(secondapagina){
            if(CheckCollisionPointRec(GetMousePosition(),contornohard)) {
                colHard=MAROON;
            if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    hard=true;
                    secondapagina=false;
                    terzapagina=true;
                }
            }
            else if(CheckCollisionPointRec(GetMousePosition(),contornoeasy)){
                colEasy=DARKGREEN;
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    easy=true;
                    secondapagina=false;
                    terzapagina=true;
                }
            }
        }
        else if(terzapagina){
            if(CheckCollisionPointRec(GetMousePosition(),contornohard)){
                colCerchio=DARKBLUE;
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    cerchio=true;
                    simbolop=1;
                    simboloc=2;
                    terzapagina=false;
                    quartapagina=true;
                }
            }
            else if(CheckCollisionPointRec(GetMousePosition(),contornoeasy)){
                colQuadrato=DARKBLUE;
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
                    quadrato=true;
                    simbolop=2;
                    simboloc=1;
                    terzapagina=false;
                    quartapagina=true;
                }
            }
        }

        if (easy) {
            if(quartapagina && vincitore==0 && turno==1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                Vector2 m=GetMousePosition();
                if(m.x>=inizioX && m.x<inizioX+campo && m.y>=inizioY && m.y<inizioY+campo) {
                    int colonne=(m.x-inizioX)/cella;
                    int righe=(m.y-inizioY)/cella;

                    if(righe==0 && colonne==0 && c1==0) c1=simbolop;
                    if(righe==0 && colonne==1 && c2==0) c2=simbolop;
                    if(righe==0 && colonne==2 && c3==0) c3=simbolop;
                    if(righe==1 && colonne==0 && c4==0) c4=simbolop;
                    if(righe==1 && colonne==1 && c5==0) c5=simbolop;
                    if(righe==1 && colonne==2 && c6==0) c6=simbolop;
                    if(righe==2 && colonne==0 && c7==0) c7=simbolop;
                    if(righe==2 && colonne==1 && c8==0) c8=simbolop;
                    if(righe==2 && colonne==2 && c9==0) c9=simbolop;
                    turno = 2;
                }
            }

            if(quartapagina && vincitore==0 && turno==2)
            {
                Computer(c1,c2,c3,c4,c5,c6,c7,c8,c9,simboloc);
                turno=1;
            }

            vincitore=vittoria(c1,c2,c3,c4,c5,c6,c7,c8,c9);
        }else if (hard) {
            if(quartapagina && vincitore==0 && turno==1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                Vector2 m=GetMousePosition();
                if(m.x>=inizioX && m.x<inizioX+campo && m.y>=inizioY && m.y<inizioY+campo) {
                    int colonne=(m.x-inizioX)/cella;
                    int righe=(m.y-inizioY)/cella;

                    if(righe==0 && colonne==0 && c1==0) c1=simbolop;
                    if(righe==0 && colonne==1 && c2==0) c2=simbolop;
                    if(righe==0 && colonne==2 && c3==0) c3=simbolop;
                    if(righe==1 && colonne==0 && c4==0) c4=simbolop;
                    if(righe==1 && colonne==1 && c5==0) c5=simbolop;
                    if(righe==1 && colonne==2 && c6==0) c6=simbolop;
                    if(righe==2 && colonne==0 && c7==0) c7=simbolop;
                    if(righe==2 && colonne==1 && c8==0) c8=simbolop;
                    if(righe==2 && colonne==2 && c9==0) c9=simbolop;
                    turno = 2;
                }
            }

            if(quartapagina && vincitore==0 && turno==2){
                ComputerHard(c1,c2,c3,c4,c5,c6,c7,c8,c9,simboloc, simbolop);
                turno=1;
            }
            vincitore=vittoria(c1,c2,c3,c4,c5,c6,c7,c8,c9);
            if(vincitore == 0 && TabellonePieno(c1,c2,c3,c4,c5,c6,c7,c8,c9)) {
                vincitore = -1; // -1 indica pareggio
            }
        }

        // ===== DISEGNO =====
        BeginDrawing();
        ClearBackground(BLACK);

        if(primapagina)
        {
            DrawText("TRIS", 135, 70, 200, BLUE);
            DrawRectangleRounded(contornogiochiamo, 0.2, 10, colGiochiamo);
            DrawTriangle({ 180, 435 }, { 180, 515 }, { 240, 475 }, coloreTesto);
            DrawText("GIOCHIAMO", 260, 445, 65, coloreTesto);
            DrawText("Made by Baresi and Meloni", 500, 750, 20, BLUE);
        }
        else if(secondapagina)
        {
            DrawText("Scegli la difficolta",80,70,70,BLUE);
            DrawRectangleRounded(contornohard,0.2,10,colHard);
            DrawText("HARD",535,355,40,WHITE);
            DrawRectangleRounded(contornoeasy,0.2,10,colEasy);
            DrawText("EASY",135,355,40,WHITE);
        }
        else if(terzapagina)
        {
            DrawText("Scegli il simbolo",140,70,70,BLUE);
            DrawRectangleRounded(contornohard,0.2,10,colCerchio);
            DrawCircle(600,375,40,WHITE);
            DrawRectangleRounded(contornoeasy,0.2,10,colQuadrato);
            DrawRectangle(150,325,100,100,WHITE);
        }
        else if(quartapagina)
        {
            if(vincitore!=0)
            {
                if(vincitore==simbolop) {
                    DrawText("HAI VINTO!",220,40,60,GREEN);
                } else if (vincitore == simboloc){
                    DrawText("HAI PERSO!",220,40,60,RED);
                } else if (vincitore == -1){
                    DrawText("PAREGGIO!",220,40,60,ORANGE);
                }

                // --- Pulsante RESET ---
                Rectangle btnReset = {300, 700, 200, 60}; // posizionato sotto il testo
                Color colReset = DARKGRAY;

                if(CheckCollisionPointRec(GetMousePosition(), btnReset))
                {
                    colReset = GRAY;
                    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                    {
                        // --- Reset delle celle ---
                        c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = c9 = 0;
                        turno = 1;
                        vincitore = 0;

                        primapagina = false;
                        secondapagina = true;
                        terzapagina = quartapagina = false;
                        easy = hard = false;
                        cerchio = quadrato = false;
                        simbolop = simboloc = 0;
                    }
                }

                DrawRectangleRec(btnReset, colReset);
                DrawText("RESET", btnReset.x + 50, btnReset.y + 15, 30, WHITE);
            }

            // --- Griglia ---
            for(int i=0;i<=3;i++)
            {
                DrawLine(inizioX+i*cella,inizioY,inizioX+i*cella,inizioY+campo,GRAY);
                DrawLine(inizioX,inizioY+i*cella,inizioX+campo,inizioY+i*cella,GRAY);
            }

            // --- Simboli ---
            DisegnaSimbolo(c1,0,0,inizioX,inizioY,cella);
            DisegnaSimbolo(c2,1,0,inizioX,inizioY,cella);
            DisegnaSimbolo(c3,2,0,inizioX,inizioY,cella);
            DisegnaSimbolo(c4,0,1,inizioX,inizioY,cella);
            DisegnaSimbolo(c5,1,1,inizioX,inizioY,cella);
            DisegnaSimbolo(c6,2,1,inizioX,inizioY,cella);
            DisegnaSimbolo(c7,0,2,inizioX,inizioY,cella);
            DisegnaSimbolo(c8,1,2,inizioX,inizioY,cella);
            DisegnaSimbolo(c9,2,2,inizioX,inizioY,cella);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}