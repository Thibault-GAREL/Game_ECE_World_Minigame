#include "FB.h"

void FB_Create(PGAME _pFB)
{
    //printf("Creation du jeu...\n");

    pFB_gamedata gamedata = malloc(sizeof (FB_gamedata));

    srand(time(NULL));
    gamedata->Jump = 0;
    gamedata->JumpTimer = 0;
    gamedata->Background = al_load_bitmap("..\\Textures/Flappy Bird/Background FB (Personnalisé).jpg");
    gamedata->Bird = al_load_bitmap("..\\Textures/Flappy Bird/FB_Character (Personnalisé).png");
    gamedata->BirdRotated = al_load_bitmap("..\\Textures/Flappy Bird/FB_Character Rotated (Personnalisé).png");
    gamedata->LightSaber = al_load_bitmap("..\\Textures/Flappy Bird/Light Saber.png");
    gamedata->LightSaberRotated = al_load_bitmap("..\\Textures/Flappy Bird/Light Saber Rotated.png");
    gamedata->font = al_load_ttf_font("..\\Textures/Fonts/StarWars Font.TTF", 90, 0);

    gamedata->Y_Position = 540;
    gamedata->vY_Fall = 4;

    gamedata->PipeRow1_X = -20;
    gamedata->PipeRow2_X = -20;
    gamedata->PipeRow3_X = -20;
    gamedata->PipeRow4_X = -20;
    gamedata->PipeRow5_X = -20;


    gamedata->Top_pipe_Y_1 = 0;
    gamedata->Top_pipe_Y_2 = 0;
    gamedata->Top_pipe_Y_3 = 0;
    gamedata->Top_pipe_Y_4 = 0;
    gamedata->Top_pipe_Y_5 = 0;

    gamedata->BirdSpeed = 2;

    gamedata->Gamemode = 0;

    gamedata->FontTimer = 0;
    gamedata->FontVy = 0.01;
    gamedata->FontY = 200;

    gamedata->Dead = 0;

    gamedata->IntervalTimer = 0;

    gamedata->P1Score = 0;
    gamedata->P2Score = 0;

    _pFB->gameData = gamedata;

    //printf("Jeu cree!\n");
}

void FB_Update(PGAME _pFB)
{
    //printf("pFB de fonction Update...\n");

    if (_pFB->gameData == NULL)
    {
        FB_Create(_pFB);
    }

    pFB_gamedata gamedata = _pFB->gameData;


    if (Get_Touch(_pFB->pEvent, ALLEGRO_KEY_W, 0, 0, 1, 0))
    {
        //printf("WIN !!!!\n");

        FB_Destroy(_pFB);
    }
    if (Get_Touch(_pFB->pEvent, ALLEGRO_KEY_SPACE, 0, 0, 1, 0))
    {
        gamedata->Jump = 1;
    }

    if (Get_Touch(_pFB->pEvent, ALLEGRO_KEY_SPACE, 0, 0, 1, 0) && gamedata->Gamemode == 0)
    {
        gamedata->Gamemode = 1;
    }
    if (Get_Touch(_pFB->pEvent, ALLEGRO_KEY_SPACE, 0, 0, 1, 0) && gamedata->Gamemode == -1)
    {
        gamedata->Gamemode = 2;
    }
    if (Get_Touch(_pFB->pEvent, ALLEGRO_KEY_ENTER, 0, 0, 1, 0) && gamedata->Gamemode == 3)
    {
        FB_Destroy(_pFB);
    }




}

void FB_TimedUpdate(PGAME _pFB)
{
    //printf("pFB de fonction TimedUpdate...\n");

    pFB_gamedata gamedata = _pFB->gameData;


    if (gamedata->Gamemode == 0){
        al_draw_bitmap(gamedata->Background,0,0,0);
        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 960,gamedata->FontY,1, "Flappy Bird");
        al_draw_bitmap(gamedata->Bird, Bird_X, 540,0);
        Allegro_play_Sample(_pFB->SampleAlManager->pSampleInstance->FBMenu);
    }

    if (gamedata->Gamemode == 1){
        Allegro_Stop_Sample(_pFB->SampleAlManager->pSampleInstance->FBMenu);
        Allegro_play_Sample(_pFB->SampleAlManager->pSampleInstance->FBGame);

        Generate_Pipes(_pFB);

        if (Check_pipes_collisions(_pFB)){
            gamedata->Dead = 1;
            Allegro_play_Sample(_pFB->SampleAlManager->pSampleInstance->FBDeath);
        }

        gamedata->BirdSpeed += 0.0001;

        gamedata->PipeRow1_X -= gamedata->BirdSpeed;
        gamedata->PipeRow2_X -= gamedata->BirdSpeed;
        gamedata->PipeRow3_X -= gamedata->BirdSpeed;
        gamedata->PipeRow4_X -= gamedata->BirdSpeed;
        gamedata->PipeRow5_X -= gamedata->BirdSpeed;

        if (gamedata->Jump == 1){
            if (gamedata->JumpTimer < 10){
                gamedata->JumpTimer ++;
                gamedata->Y_Position -= 10;
            }
            else if(gamedata->JumpTimer == 10){
                gamedata->Jump = 0;
                //printf("condit 2");
                gamedata->JumpTimer = 0;
            }
        }
        if (gamedata->Jump == 0){
            gamedata->Y_Position += gamedata->vY_Fall;
            gamedata->vY_Fall += 0.00001;
        }

        //printf("%d", gamedata->JumpTimer);

        al_draw_bitmap(gamedata->Background,0,0,0);

        if (gamedata->Dead == 0){
            al_draw_bitmap(gamedata->Bird,Bird_X,gamedata->Y_Position,0);
        }
        else if (gamedata->Dead == 1){
            al_draw_bitmap(gamedata->BirdRotated,Bird_X,gamedata->Y_Position,0);
            gamedata->Y_Position +=10;

            if (gamedata->Y_Position >1080){
                gamedata->Gamemode = -1;
            }
        }

        gamedata->P1Score ++;
        sprintf(gamedata->p1Score, "%d",(int)(gamedata->P1Score /100));

        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow1_X, gamedata->Top_pipe_Y_1,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow1_X,gamedata->Top_pipe_Y_1 + Distance_btw_2_pipes,0);

        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow2_X, gamedata->Top_pipe_Y_2,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow2_X,gamedata->Top_pipe_Y_2 + Distance_btw_2_pipes,0);

        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow3_X, gamedata->Top_pipe_Y_3,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow3_X,gamedata->Top_pipe_Y_3 + Distance_btw_2_pipes,0);

        //printf("%d .. %d \n", gamedata->PipeRow3_X, gamedata->PipeRow3_X );


        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow4_X, gamedata->Top_pipe_Y_4,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow4_X,gamedata->Top_pipe_Y_4 + Distance_btw_2_pipes,0);

        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow5_X, gamedata->Top_pipe_Y_5,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow5_X,gamedata->Top_pipe_Y_5 + Distance_btw_2_pipes,0);

        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 960,gamedata->FontY,1, "Flappy Bird");
        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 1850,150,1, gamedata->p1Score);
        gamedata->FontY -= 5;
    }

    if (gamedata->Gamemode == -1){
        al_draw_bitmap(gamedata->Background,0,0,0);
        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 960,gamedata->FontY,1, "Player 2");
        al_draw_bitmap(gamedata->Bird, Bird_X, 540,0);

        gamedata->Y_Position = 540;
        gamedata->vY_Fall = 4;

        gamedata->FontY = 200;

        gamedata->PipeRow1_X = -20;
        gamedata->PipeRow2_X = -20;
        gamedata->PipeRow3_X = -20;
        gamedata->PipeRow4_X = -20;
        gamedata->PipeRow5_X = -20;


        gamedata->Top_pipe_Y_1 = 0;
        gamedata->Top_pipe_Y_2 = 0;
        gamedata->Top_pipe_Y_3 = 0;
        gamedata->Top_pipe_Y_4 = 0;
        gamedata->Top_pipe_Y_5 = 0;

        gamedata->BirdSpeed = 2;
        gamedata->Dead = 0;
    }

    if (gamedata->Gamemode == 2){
        Generate_Pipes(_pFB);

        if (Check_pipes_collisions(_pFB)){
            gamedata->Dead = 1;
            Allegro_play_Sample(_pFB->SampleAlManager->pSampleInstance->FBDeath);
        }

        gamedata->BirdSpeed += 0.0001;

        gamedata->PipeRow1_X -= gamedata->BirdSpeed;
        gamedata->PipeRow2_X -= gamedata->BirdSpeed;
        gamedata->PipeRow3_X -= gamedata->BirdSpeed;
        gamedata->PipeRow4_X -= gamedata->BirdSpeed;
        gamedata->PipeRow5_X -= gamedata->BirdSpeed;

        if (gamedata->Jump == 1){
            if (gamedata->JumpTimer < 10){
                gamedata->JumpTimer ++;
                gamedata->Y_Position -= 10;
            }
            else if(gamedata->JumpTimer == 10){
                gamedata->Jump = 0;
                //printf("condit 2");
                gamedata->JumpTimer = 0;
            }
        }
        if (gamedata->Jump == 0){
            gamedata->Y_Position += gamedata->vY_Fall;
            gamedata->vY_Fall += 0.00001;
        }

        //printf("%d", gamedata->JumpTimer);

        al_draw_bitmap(gamedata->Background,0,0,0);

        if (gamedata->Dead == 0){
            al_draw_bitmap(gamedata->Bird,Bird_X,gamedata->Y_Position,0);
        }
        else if (gamedata->Dead == 1){
            al_draw_bitmap(gamedata->BirdRotated,Bird_X,gamedata->Y_Position,0);
            gamedata->Y_Position +=10;

            if (gamedata->Y_Position >1080){
                gamedata->Gamemode = 3;
            }
        }

        gamedata->P2Score ++;
        sprintf(gamedata->p2Score, "%d",(int)(gamedata->P2Score /100));

        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow1_X, gamedata->Top_pipe_Y_1,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow1_X,gamedata->Top_pipe_Y_1 + Distance_btw_2_pipes,0);

        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow2_X, gamedata->Top_pipe_Y_2,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow2_X,gamedata->Top_pipe_Y_2 + Distance_btw_2_pipes,0);

        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow3_X, gamedata->Top_pipe_Y_3,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow3_X,gamedata->Top_pipe_Y_3 + Distance_btw_2_pipes,0);

        //printf("%d .. %d \n", gamedata->PipeRow3_X, gamedata->PipeRow3_X );


        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow4_X, gamedata->Top_pipe_Y_4,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow4_X,gamedata->Top_pipe_Y_4 + Distance_btw_2_pipes,0);

        al_draw_bitmap(gamedata->LightSaber, gamedata->PipeRow5_X, gamedata->Top_pipe_Y_5,0);
        al_draw_bitmap(gamedata->LightSaberRotated,gamedata->PipeRow5_X,gamedata->Top_pipe_Y_5 + Distance_btw_2_pipes,0);

        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 960,gamedata->FontY,1, "Flappy Bird");
        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 1850,150,1, gamedata->p2Score);
        gamedata->FontY -= 5;
    }

    if (gamedata->Gamemode == 3){
        al_draw_bitmap(gamedata->Background,0,0,0);
        al_draw_text(gamedata->font, al_map_rgb(255,255,255),960, 200,1,"Scores");

        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 500,400,1, _pFB->pPlayers[0]->name);
        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 500,600,1, _pFB->pPlayers[1]->name);

        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 960,400,1, gamedata->p1Score);
        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 960,600,1, gamedata->p2Score);

        al_draw_text(gamedata->font, al_map_rgb(255,255,255), 960,900,1, "Press ENTER To Quit");
    }
}

void Generate_Pipes(PGAME _pFB){
    pFB_gamedata gamedata = _pFB->gameData;

    if (gamedata->PipeRow1_X < 0){
        gamedata->PipeRow1_X = 1920;
        gamedata->Top_pipe_Y_1 = (-1)*(rand()%500+600)+200;
    }
    if (gamedata->PipeRow2_X < 0){
        gamedata->PipeRow2_X = gamedata->PipeRow1_X + 350;
        gamedata->Top_pipe_Y_2 = (-1)*(rand()%500+600);
    }
    if (gamedata->PipeRow3_X < 0){
        gamedata->PipeRow3_X = gamedata->PipeRow2_X + 350;
        gamedata->Top_pipe_Y_3 = (-1)*(rand()%500+600);
    }
    if (gamedata->PipeRow4_X < 0){
        gamedata->PipeRow4_X = gamedata->PipeRow3_X + 350;
        gamedata->Top_pipe_Y_4 = (-1)*(rand()%500+600);
    }
    if (gamedata->PipeRow5_X < 0){
        gamedata->PipeRow5_X = gamedata->PipeRow4_X + 350;
        gamedata->Top_pipe_Y_5 = (-1)*(rand()%500+600);
    }
}

bool Check_pipes_collisions(PGAME _pFB){

    pFB_gamedata gamedata = _pFB->gameData;

    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position}, (Vector2D){gamedata->PipeRow1_X ,gamedata->Top_pipe_Y_1 }, (Vector2D){gamedata->PipeRow1_X + al_get_bitmap_width(gamedata->LightSaber),gamedata->Top_pipe_Y_1 + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //colisions Top Right


    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position + al_get_bitmap_height(gamedata->Bird)}, (Vector2D){gamedata->PipeRow1_X ,gamedata->Top_pipe_Y_1 + Distance_btw_2_pipes }, (Vector2D){gamedata->PipeRow1_X + al_get_bitmap_width(gamedata->LightSaberRotated),gamedata->Top_pipe_Y_1 + Distance_btw_2_pipes + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //Colisions Bottom Right

    //First Row


    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position}, (Vector2D){gamedata->PipeRow2_X ,gamedata->Top_pipe_Y_2 }, (Vector2D){gamedata->PipeRow2_X + al_get_bitmap_width(gamedata->LightSaber),gamedata->Top_pipe_Y_2 + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //colisions Top Right


    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position + al_get_bitmap_height(gamedata->Bird)}, (Vector2D){gamedata->PipeRow2_X ,gamedata->Top_pipe_Y_2 + Distance_btw_2_pipes }, (Vector2D){gamedata->PipeRow2_X + al_get_bitmap_width(gamedata->LightSaberRotated),gamedata->Top_pipe_Y_2 + Distance_btw_2_pipes + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //Colisions Bottom Right

    //second Row


    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position}, (Vector2D){gamedata->PipeRow3_X ,gamedata->Top_pipe_Y_3 }, (Vector2D){gamedata->PipeRow3_X + al_get_bitmap_width(gamedata->LightSaber),gamedata->Top_pipe_Y_3 + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //colisions Top Right


    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position + al_get_bitmap_height(gamedata->Bird)}, (Vector2D){gamedata->PipeRow3_X ,gamedata->Top_pipe_Y_3 + Distance_btw_2_pipes }, (Vector2D){gamedata->PipeRow3_X + al_get_bitmap_width(gamedata->LightSaberRotated),gamedata->Top_pipe_Y_3 + Distance_btw_2_pipes + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //Colisions Bottom Right


    //Third Row

    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position}, (Vector2D){gamedata->PipeRow4_X ,gamedata->Top_pipe_Y_4 }, (Vector2D){gamedata->PipeRow4_X + al_get_bitmap_width(gamedata->LightSaber),gamedata->Top_pipe_Y_4 + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //colisions Top Right


    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position + al_get_bitmap_height(gamedata->Bird)}, (Vector2D){gamedata->PipeRow4_X ,gamedata->Top_pipe_Y_4 + Distance_btw_2_pipes }, (Vector2D){gamedata->PipeRow4_X + al_get_bitmap_width(gamedata->LightSaberRotated),gamedata->Top_pipe_Y_4 + Distance_btw_2_pipes + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //Colisions Bottom Right

    //Fourth Row


    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position}, (Vector2D){gamedata->PipeRow5_X ,gamedata->Top_pipe_Y_5 }, (Vector2D){gamedata->PipeRow5_X + al_get_bitmap_width(gamedata->LightSaber),gamedata->Top_pipe_Y_5 + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //colisions Top Right


    if(Point_In_Rectangle((Vector2D){Bird_X + al_get_bitmap_width(gamedata->Bird),gamedata->Y_Position + al_get_bitmap_height(gamedata->Bird)}, (Vector2D){gamedata->PipeRow5_X ,gamedata->Top_pipe_Y_5 + Distance_btw_2_pipes }, (Vector2D){gamedata->PipeRow5_X + al_get_bitmap_width(gamedata->LightSaberRotated),gamedata->Top_pipe_Y_5 + Distance_btw_2_pipes + al_get_bitmap_height(gamedata->LightSaber)})){
        return true;
    }   //Colisions Bottom Right

    //Fifth Row


    if(gamedata->Y_Position < 0 || gamedata->Y_Position >1080){
        return true;
    }

    return false;
}
void FB_Destroy(PGAME _pFB)
{

    pFB_gamedata gamedata = _pFB->gameData;

    al_destroy_bitmap(gamedata->Bird);
    al_destroy_bitmap(gamedata->BirdRotated);
    al_destroy_bitmap(gamedata->Background);
    al_destroy_bitmap(gamedata->LightSaber);
    al_destroy_bitmap(gamedata->LightSaberRotated);

    al_destroy_font(gamedata->font);

    Allegro_Stop_Sample(_pFB->SampleAlManager->pSampleInstance->FBGame);

    if (gamedata->P1Score > gamedata->P2Score){
        _pFB->pPlayers[0]->tickets ++;
    }
    if (gamedata->P1Score < gamedata->P2Score){
        _pFB->pPlayers[1]->tickets ++;
    }
    if (gamedata->P1Score == gamedata->P2Score){
        _pFB->pPlayers[0]->tickets ++;
        _pFB->pPlayers[1]->tickets ++;
    }

    free(_pFB->gameData);
    _pFB->gameData = NULL;

    *_pFB->pCurrentGameId = GAME_MAP;

}
