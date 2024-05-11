#include <stdio.h>
#include "include/raylib.h"
#include <stdbool.h>


#define pixel 20
#define pw 40
#define ph 160

void suma(double*h, double *m, double *s,double aux)
{
  *s += aux;
  if((int)*s / 60 == 1){
    *m= 1.0;
    *s = 0.0;
  }
  if((int)*m /60 == 1){
    *h = 1.0;
    *m = 0;
  }
}

void resta(double *h,double *m,double *s,double aux){
  *s -= aux;
  if(*s < 0.0){
    *m -= 1.0;
    *s = 59.0;
  }
  if(*m < 0.0){
    *h -= 1.0;
    *m = 59.0;}
}

void restablecer(double *h,double *m,double *s, bool *corre){
  if(IsKeyPressed(KEY_SPACE)){
    *h = 0.0;
    *m = 15.0;
    *s = (double)0;
    *corre = false;
  }
}
/*
typedef struct Rectangle {
    float x;                // Rectangle top-left corner position x
    float y;                // Rectangle top-left corner position y
    float width;            // Rectangle width
    float height;           // Rectangle height
} Rectangle;
*/
/*{
0 = 1111110
1 = 0000110
2 = 1101101
3 = 1111001
4 = 0110011
5 = 1011011
6 = 1011111
7 = 1110000
8 = 1111111
9 = 1111011
}*/

void colorear (Rectangle p){
  int ccs = p.y;
  int cyu = pw;
  int uyc = pw;
// Espero algún día ser capaz de reirme de este bucle
//    |
//    V

    for(int j = 0; j <= 6; j++){
     if(j == 0 || j == 3 || j == 6){ 
       p.y = ccs;
       p.x = 80;
       p.width = pw * 3;
       p.height = pw;
       DrawRectangleRounded(p,0.9,6,BLACK);
       ccs += 160;
     }
     else{
       if(j == 1 || j == 5){
        p.y += 40;
        p.x = cyu;
        p.width = pw;
        p.height = pw * 3;
        DrawRectangleRounded(p,0.9,6,BLACK);
        cyu += 160;
       }
       else{
        if(j == 2){ 
          p.x = 200;
          p.y = 240;
          DrawRectangleRounded(p,0.9,6,BLACK);
        }
        else{
          p.x = 40;
          uyc = p.y;
          p.y = 400;
          p.width = pw;
          p.height = pw * 3;
          DrawRectangleRounded(p,0.9,6,BLACK);
          p.y = uyc;
        }
       }
     }
     
    }
    p.x = 80;
    p.y = 200;
    //DrawRectangleRounded(p,0.9,6,BLACK);

}

int main()
{
  double h, m, s,aux;
  m = 0.0;
  h = 0.0;
  s = 0.0;
  Rectangle p;
  p.x = 80;
  p.y = 200;
  p.width = 80;
  p.height = 40;
  aux = 0.0;
  bool corre = true;
  bool retrocede = false;
  InitWindow(ph*8, (pw * 2) * 9, "Windows Dfender Trolo");
  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    if((int)aux >= 1){
      if(corre){
        suma(&h, &m, &s,aux);
      } 
      else{

        resta(&h,&m,&s,aux);
      }
      aux = 0;
    }
      ClearBackground(RED);
      restablecer(&h,&m,&s,&corre);
       //printf("%d",corre);
     colorear(p);
    //printf("%f:%f:%f\n",h,m,s);
    aux+= GetFrameTime();
    EndDrawing();
    
  }
  CloseWindow();
}
