#include <stdio.h>
#include <raylib.h>

#define h 80
#define w 40
void colorear(struct Rectangle p){ // Lo que yo necesito es que por cada iteracion de i los segmentos verticales y horizontales se muevan en el ejeX
  for(int i = 0; i = 6; ++i){
    for(int j = 0; i = 6; ++j){ 
      if(j == 0 || j == 3 || j == 6){
        p.width = 120;
        p.height = 40;
        DrawRectangleRounded(p,0.9,6,RED);
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
    SetTargetFPS(60);
 SetWindowMaxSize(1980,1080); 
  while(!WindowShouldClose()){
      BeginDrawing();
      ClearBackground(BLACK);
<<<<<<< HEAD
      colorear(&p);
=======
      colorear(p);
>>>>>>> be4ca667b676fdfef4c2dfab7942eee5ea22269b
      EndDrawing();
      }
  CloseWindow();
      }
