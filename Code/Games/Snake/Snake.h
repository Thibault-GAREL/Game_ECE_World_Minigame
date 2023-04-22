#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\\Utils\\Magical.h"
#include "..\\..\\Utils\\UI.h"

#define PART_SIZE 400

typedef struct _SNAKE_PART
{
    struct _SNAKE_PART* previous;
    VECTOR2D_INT direction;
    VECTOR2D_INT position;
}SNAKE_PART, *PSNAKE_PART;

typedef struct _SNAKE
{
    int size;
    int step;
    int speed;
    PSNAKE_PART pHead;
    ALLEGRO_BITMAP* pClone;
}SNAKE, *PSNAKE;

typedef struct _SNAKE_DATA
{
    PSNAKE pSnake;
}SNAKE_DATA, *PSNAKE_DATA;


void SnakeGame_Create(PGAME _pSnake);
void SnakeGame_Update(PGAME _pSnake);
void SnakeGame_TimedUpdate(PGAME _pSnake);
void SnakeGame_Destroy(PGAME _pSnake);

void Snake_Add_Part(PSNAKE_PART* _ppSnakePart, int* _pSize);
void Snake_Destroy_AllParts(PSNAKE_PART _pSnakePart);
void Snake_Draw(PSNAKE_PART _pSnakePart, PSNAKE _pSnake);
void Snake_Move(PSNAKE_PART _pSnakePart, int _speed, int _step);
