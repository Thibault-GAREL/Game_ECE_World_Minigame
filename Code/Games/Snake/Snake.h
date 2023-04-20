#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"


typedef struct _SNAKE_DATA
{
    
}SNAKE_DATA, *PSNAKE_DATA;


void Snake_Create(PGAME _pSnake);
void Snake_Update(PGAME _pSnake);
void Snake_TimedUpdate(PGAME _pSnake);
void Snake_Destroy(PGAME _pSnake);
