#include "mygl.h"
#include <GL/glut.h> 
#include <math.h>
#include <time.h>
#include "main.h"

typedef struct{
   int x, y;
   float R,G,B,A;
}Pixel;

typedef struct{
    Pixel a,b,c;
}Triangle;

void PutPixel(Pixel a){
    int w = glutGet(GLUT_INIT_WINDOW_WIDTH);
    int offset = a.x*4+a.y*w*4;
    fb_ptr[offset] = a.R;
    fb_ptr[offset+1] = a.G;
    fb_ptr[offset+2] = a.B;
    fb_ptr[offset+3] = a.A;
}

void DrawLine(Pixel a, Pixel b){
    int dx = b.x - a.x;
    int dy = b.y - a.y;

    int d;
    int incr_e;
    int incre_ne;
    int incr_n = 2 * abs(dx);

    float Rcor, Gcor, Bcor;

    if(abs(dy) > abs(dx)){
        d = 2 * abs(dx) - abs(dy);
        incr_e = 2 * abs(dx);
        incre_ne = 2 * (abs(dx) - abs(dy));
    }else{
        d = 2 * abs(dy) - abs(dx);
        incr_e = 2 * abs(dy);
        incre_ne = 2 * (abs(dy) - abs(dx));
    }

    Pixel toPut = a;

    float distance = sqrt(pow(dx,2.0) + pow(dy,2.0));
        Rcor = (b.R - toPut.R) / distance;
        Gcor = (b.G - toPut.G) / distance;
        Bcor = (b.B - toPut.B) / distance;
    
    PutPixel(toPut);

    if(dx == 0){
        
        while(toPut.y != b.y){
            if(dy > 0)
                toPut.y++;
            else
                toPut.y--;

            PutPixel(toPut);
            toPut.R += Rcor;
            toPut.G += Gcor;
            toPut.B += Bcor;
            
        }
    }else if(abs(dy) > abs(dx)){
        while(toPut.x != b.x){
            if(d <= 0){
                d += incr_n;
                if(dy > 0)
                    toPut.y++;
                else
                    toPut.y--;
            }else{
                d += incre_ne;
                if(dx > 0)
                    toPut.x++;
                else
                    toPut.x--;
                
                if(dy > 0)
                    toPut.y++;
                else
                    toPut.y--;
            }

            PutPixel(toPut);
            toPut.R += Rcor;
            toPut.G += Gcor;
            toPut.B += Bcor;
        }
    }else{
        while(toPut.x != b.x){
            if(d <= 0){
                d += incr_e;
                if(dx > 0)
                    toPut.x++;
                else
                    toPut.x--;
            }else{
                d += incre_ne;
                if(dx > 0)
                    toPut.x++;
                else
                    toPut.x--;

                if(dy > 0)
                    toPut.y++;
                else  
                    toPut.y--;
            }

            PutPixel(toPut);
            toPut.R += Rcor;
            toPut.G += Gcor;
            toPut.B += Bcor;
        }
    }
    
}

void DrawTriangle(Pixel a, Pixel b, Pixel c){
    int dx = b.x - a.x;
    int dy = b.y - a.y;

    int d;
    int incr_e;
    int incre_ne;
    int incr_n = 2 * abs(dx);

    if(abs(dy) > abs(dx)){
        d = 2 * abs(dx) - abs(dy);
        incr_e = 2 * abs(dx);
        incre_ne = 2 * (abs(dx) - abs(dy));
    }else{
        d = 2 * abs(dy) - abs(dx);
        incr_e = 2 * abs(dy);
        incre_ne = 2 * (abs(dy) - abs(dx));
    }

    Pixel toPut = a;
    
    PutPixel(toPut);
    DrawLine(toPut, c);

    float Rcor, Gcor, Bcor;
    float distance = sqrt(pow(dx,2.0) + pow(dy,2.0));

    Rcor = (b.R - toPut.R) / distance;
    Gcor = (b.G - toPut.G) / distance;
    Bcor = (b.B - toPut.B) / distance;

    if(dx == 0){
        
        Rcor = (b.R - toPut.R) / distance;
        Gcor = (b.G - toPut.G) / distance;
        Bcor = (b.B - toPut.B) / distance;
        while(toPut.y != b.y){
            if(dy > 0)
                toPut.y++;
            else
                toPut.y--;

            PutPixel(toPut);
            DrawLine(toPut, c);
            toPut.R += Rcor;
            toPut.G += Gcor;
            toPut.B += Bcor;
            
        }
    }else if(abs(dy) > abs(dx)){
        while(toPut.x != b.x){
            if(d <= 0){
                d += incr_n;
                if(dy > 0)
                    toPut.y++;
                else
                    toPut.y--;
            }else{
                d += incre_ne;
                if(dx > 0)
                    toPut.x++;
                else
                    toPut.x--;
                
                if(dy > 0)
                    toPut.y++;
                else
                    toPut.y--;
            }

            PutPixel(toPut);
            DrawLine(toPut, c);
            toPut.R += Rcor;
            toPut.G += Gcor;
            toPut.B += Bcor;
        }
    }else{
       
        while(toPut.x != b.x){
            if(d <= 0){
                d += incr_e;
                if(dx > 0)
                    toPut.x++;
                else
                    toPut.x--;
            }else{
                d += incre_ne;
                if(dx > 0)
                    toPut.x++;
                else
                    toPut.x--;

                if(dy > 0)
                    toPut.y++;
                else  
                    toPut.y--;
            }

            PutPixel(toPut);
            DrawLine(toPut,c);
            toPut.R += Rcor;
            toPut.G += Gcor;
            toPut.B += Bcor;
        }
    }
}

Pixel RotatePixel(Pixel a, Pixel b, double angle){

    Pixel d = b;
    d.x = a.x+ (b.x-a.x)*cos(angle) - (b.y-a.y)*sin(angle);
    d.y = a.y+ (b.x-a.x)*sin(angle) + (b.y-a.y)*cos(angle);


    return d;
}

void DrawCircle(Pixel centro, Pixel raio){
    double angle = 0;
    Pixel toPut = raio;

    while(angle < 6.28){
        PutPixel(toPut);
        toPut = RotatePixel(centro, toPut, angle);
        angle += 0.005;    
    }
}


// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    Pixel a = {.x = 100, .y = 255, .R = 255, .G = 0, .B = 0, .A = 0};
    Pixel b = {.x = 400, .y = 255, .R = 0, .G = 0, .B = 255, .A = 0};
    Pixel c = {.x = 250, .y = 105, .R = 72, .G = 209, .B = 204, .A = 0};
    Pixel centro = {.x = 255, .y = 255, .R = 72, .G = 209, .B = 204, .A = 0};
    Pixel raio = {.x = 455, .y = 255, .R = 72, .G = 209, .B = 204, .A = 0};

    //desenha o circulo na tela
    DrawCircle(centro, raio);

    //define o struct triangulo
    Triangle triangulo = {.a = a, .b = b, .c = c};

    //envia os pontos do triangulo pra função
    DrawTriangle(triangulo.a , triangulo.b, triangulo.c);
    

}
