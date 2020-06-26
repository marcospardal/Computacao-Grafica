#ifndef MYGL_H
#define MYGL_H

#include "core.h"
#include "frame_buffer.h"
#include <stdio.h>

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

void PutPixel(Pixel);

void DrawLine(Pixel, Pixel);

#endif  // MYGL_H
