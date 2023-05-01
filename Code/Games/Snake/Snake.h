#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\\Utils\\Magical.h"
#include "..\\..\\Utils\\UI.h"

#define CLONE_ORIGINAL_SIZE 400
#define CLONE_SIZE 40

#define FOOD_ORIGINAL_SIZE 600
#define FOOD_SIZE 50
#define FOOD_COUNT_MAX 10
#define FOOD_PROBA 100

#define GAME_STATE_RUNNING 0
#define GAME_STATE_GO 1

#define SNAKE_SPEED_START 10
#define SNAKE_SPEED_INCREASE 0.1f
#define SNAKE_STEP_TIME 100

typedef struct _SNAKE_PART
{
    struct _SNAKE_PART* previous;
    VECTOR2D_INT position;
    float directionAngle;
}SNAKE_PART, *PSNAKE_PART;

typedef struct _SNAKE
{
    int size;
    int step;
    int speed;
    VECTOR2D_INT direction;
    PSNAKE_PART pHead;
    ALLEGRO_BITMAP* pClone;
}SNAKE, *PSNAKE;

typedef struct _FOOD
{   
    VECTOR2D_INT foodPos;
}FOOD, *PFOOD;

typedef struct _SNAKE_DATA
{
    PSNAKE pSnake;
    int foodCount;
    FOOD foods[FOOD_COUNT_MAX];
    ALLEGRO_BITMAP* pFood1;
    int currentPlayer;
    int gameState;
    ALLEGRO_FONT* pScoreFont;
}SNAKE_DATA, *PSNAKE_DATA;


void SnakeGame_Create(PGAME _pSnake);
void SnakeGame_Update(PGAME _pSnake);
void SnakeGame_TimedUpdate(PGAME _pSnake);
void SnakeGame_Destroy(PGAME _pSnake);

void Snake_Add_Part(PSNAKE_PART* _ppSnakePart, int* _pSize);
void Snake_Destroy_AllParts(PSNAKE_PART _pSnakePart);
void Snake_Draw(PSNAKE_PART _pSnakePart, PSNAKE _pSnake);
void Snake_Move(PSNAKE_PART _pSnakePart, VECTOR2D_INT _position);
int Snake_EatSelf(PSNAKE_PART _pSnakePart, VECTOR2D_INT _headPosition);

void Food_Generation(PGAME _pSnake);
void Food_CheckCollision(PGAME _pSnake);

void Draw_UI(SNAKE_DATA _snakeData);
void NextPlayer(PGAME _pSnake);