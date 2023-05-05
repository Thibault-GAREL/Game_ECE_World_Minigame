#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\Game.h"
#include "..\\..\\Utils\\allegroutils.h"
#include "..\\..\Utils\\Vector.h"

#define CL_PATH ".."
#define PATH CL_PATH


typedef struct _BONUSDATA
{
    Vector2D mouse;
    int click;
}BonusData;


void Bonus_Create(PGAME _pBonus);
void Bonus_Update(PGAME _pBonus);
void Bonus_TimedUpdate(PGAME _pBonus);
void Bonus_Destroy(PGAME _pBonus);




























//
// Created by Antoine on 05/05/2023.
//

#ifndef PROJET_JEUBONUS_H
#define PROJET_JEUBONUS_H

#endif //PROJET_JEUBONUS_H
