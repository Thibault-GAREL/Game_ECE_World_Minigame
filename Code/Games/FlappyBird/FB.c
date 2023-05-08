#include "FB.h"

void FB_Create(PGAME _pFB)
{
    printf("Creation du jeu...\n");

    pFB_gamedata gamedata = malloc(sizeof (FB_gamedata));

    gamedata->Jump = 0;
    gamedata->JumpTimer = 0;
    gamedata->Background = al_load_bitmap("..\\Textures/Flappy Bird/Background FB (Personnalisé).jpg");
    gamedata->Bird = al_load_bitmap("..\\Textures/Flappy Bird/FB_Character (Personnalisé).png");
    gamedata->LightSaber = al_load_bitmap("..\\Textures/Flappy Bird/Light Saber.png");
    gamedata->LightSaberRotated = al_load_bitmap("..\\Textures/Flappy Bird/Light Saber Rotated.png");

    gamedata->Y_Position = 540;
    gamedata->vY_Fall = 2;

    gamedata->PipeRow1_X = -20;
    gamedata->PipeRow2_X = -20;

    gamedata->Top_pipe_Y_1 = 0;
    gamedata->Top_pipe_Y_2 = 0;

    gamedata->BirdSpeed = 2;

    _pFB->gameData = gamedata;

    printf("Jeu cree!\n");
}

void FB_Update(PGAME _pFB)
{
    printf("pFB de fonction Update...\n");

    if (_pFB->gameData == NULL)
    {
        FB_Create(_pFB);
    }

    pFB_gamedata gamedata = _pFB->gameData;


    if (Get_Touch(_pFB->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        printf("WIN !!!!\n");

        FB_Destroy(_pFB);
    }
    if (Get_Touch(_pFB->pEvent, ALLEGRO_KEY_SPACE, 0, 0, 1, 0))
    {
        gamedata->Jump = 1;
    }

    printf("\n");
}

void FB_TimedUpdate(PGAME _pFB)
{
    printf("pFB de fonction TimedUpdate...\n");

    pFB_gamedata gamedata = _pFB->gameData;

    Generate_Pipes(_pFB);

    gamedata->BirdSpeed += 0.0001;

    gamedata->PipeRow1_X -= gamedata->BirdSpeed;
    gamedata->PipeRow2_X -= gamedata->BirdSpeed;

    if (gamedata->Jump == 1){
        if (gamedata->JumpTimer < 10){
            gamedata->JumpTimer ++;
            gamedata->Y_Position -= 10;
        }
        else if(gamedata->JumpTimer == 10){
            gamedata->Jump = 0;
            printf("condit 2");
            gamedata->JumpTimer = 0;
        }
    }
    if (gamedata->Jump == 0){
        gamedata->Y_Position += gamedata->vY_Fall;
        gamedata->vY_Fall += 0.00001;
    }

    printf("%d", gamedata->JumpTimer);

    al_draw_bitmap(gamedata->Background,0,0,0);
    al_draw_bitmap(gamedata->Bird,200,gamedata->Y_Position,0);

    al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow1_X, gamedata->Top_pipe_Y_1,0);
    al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow1_X,gamedata->Top_pipe_Y_1 + Distance_btw_2_pipes,0);


    al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow2_X, gamedata->Top_pipe_Y_2,0);
    al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow2_X,gamedata->Top_pipe_Y_2 + Distance_btw_2_pipes,0);

}

void Generate_Pipes(PGAME _pFB){
    pFB_gamedata gamedata = _pFB->gameData;

    if (gamedata->PipeRow1_X < 0){
        gamedata->PipeRow1_X = rand()% 500 + 1920;
        gamedata->Top_pipe_Y_1 = (-1)*(rand()%500+600);
    }
    if (gamedata->PipeRow2_X < 0){
        gamedata->PipeRow2_X = rand()% 500 + 1920;
        gamedata->Top_pipe_Y_2 = (-1)*(rand()%500+600);
    }
}

void FB_Destroy(PGAME _pFB)
{
    printf("Destruction du jeu...\n");

    pFB_gamedata gamedata = _pFB->gameData;

    free(_pFB->gameData);
    _pFB->gameData = NULL;

    printf("Jeu detruit\n");

    *_pFB->pCurrentGameId = GAME_NONE;

    printf("Etat du jeu actuel mis a GAME_NONE");
}
