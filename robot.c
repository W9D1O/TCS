//#include <windows.h>
#include <stdio.h>
#include "include/raylib.h"
#define h 80
#define w 40
void colorear(Rectangle *p){
  p->x = h;
  p->y = h;
  for(int i = 0; i <= 5; i++){
    p->y =p->x + h; 
    for(int j = 0; j <= 6; j++){
      p->x=p->y + w;
      if(j == 0 || j == 3 || j == 6){
        printf("LA CONCHA DE TU MADRE PERALTA. ESTÄ ES PARA VOS");
        p->height = h * 2;
        p->width =w;
        DrawRectangleRounded(*p, 0.9, 6, RED);
     // WaitTime(1);
      }
    } 
  }
}

int main(){
    Rectangle p;
    p.x = 80;
    p.y = 200;
    p.width = 40;
    p.height = 40;
    InitWindow(w *32, w * 18, "Ave");
  while(!WindowShouldClose()){
      BeginDrawing();
      ClearBackground(BLACK);
      colorear(&p);
      EndDrawing();
      }
  CloseWindow();
      }
