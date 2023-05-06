#include "JeuBonus.h"


void Bonus_Create(PGAME _pBonus)
{
    BonusData* pBonusData = malloc(sizeof (BonusData));
    _pBonus->gameData = pBonusData;
    pBonusData->image[0]= al_load_bitmap("..\\Textures/JeuBonus/field.png");
    pBonusData->image[1]= al_load_bitmap("..\\Textures/JeuBonus/Chassuredroite.png");
    pBonusData->image[2]= al_load_bitmap("..\\Textures/JeuBonus/Chaussuregauche.png");
    pBonusData->image[3]= al_load_bitmap("..\\Textures/JeuBonus/ToucheQ.png");
    pBonusData->image[4]= al_load_bitmap("..\\Textures/JeuBonus/ToucheZ.png");
    pBonusData->image[5]= al_load_bitmap("..\\Textures/JeuBonus/ToucheD.png");
    pBonusData->image[6]= al_load_bitmap("..\\Textures/JeuBonus/Toucheup.png");
    pBonusData->image[7]= al_load_bitmap("..\\Textures/JeuBonus/Toucheleft.png");
    pBonusData->image[8]= al_load_bitmap("..\\Textures/JeuBonus/Toucheright.png");
    pBonusData->image[9]= al_load_bitmap("..\\Textures/JeuBonus/ToucheCTRL.png");
    pBonusData->image[10]= al_load_bitmap("..\\Textures/JeuBonus/ToucheENTER.png");
    pBonusData->image[11]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme11.png");
    pBonusData->image[12]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme12.png");
    pBonusData->image[13]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme13.png");
    pBonusData->image[14]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme11G.png");
    pBonusData->image[15]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme12G.png");
    pBonusData->image[16]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme13G.png");
    pBonusData->image[17]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme21.png");
    pBonusData->image[18]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme22.png");
    pBonusData->image[19]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme23.png");
    pBonusData->image[20]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme21G.png");
    pBonusData->image[21]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme22G.png");
    pBonusData->image[22]= al_load_bitmap("..\\Textures/JeuBonus/bonhomme23G.png");
    pBonusData->image[23]= al_load_bitmap("..\\Textures/JeuBonus/Ballon.png");
    pBonusData->image[24]= al_load_bitmap("..\\Textures/JeuBonus/enervementgrand.png");
    pBonusData->image[25]= al_load_bitmap("..\\Textures/JeuBonus/enervementpetit.png");

    pBonusData->x1=500;
    pBonusData->y1=730;
    pBonusData->x2=1250;
    pBonusData->y2=730;

    pBonusData->xballon=920;
    pBonusData->yballon=400;
    pBonusData->sensbonhomme2=0;
    pBonusData->sensbonhomme1=0;
    pBonusData->deplacementx1=0;
    pBonusData->deplacementx2=0;
    pBonusData->compteursautJ1=0;
    pBonusData->compteursautJ2=0;
    pBonusData->compteurfinsautJ1=0;
    pBonusData->compteurfinsautJ2=0;

    pBonusData->eligibilitesautJ1=0;
    pBonusData->eligibilitesautJ2=0;

    pBonusData->tirJ1=0;
    pBonusData->tirJ2=0;
    pBonusData->compteuranimJ1=0;
    pBonusData->compteuranimJ2=0;
    pBonusData->compteurfinanimJ1=0;
    pBonusData->compteurfinanimJ2=0;
    pBonusData->a=0;
    pBonusData->b=0;
    pBonusData->c=0;
    pBonusData->d=0;

    pBonusData->colision1=0;
    pBonusData->colision2=0;
    pBonusData->colision3=0;
    pBonusData->colision4=0;
    pBonusData->colision5=0;
    pBonusData->colision6=0;

    pBonusData->compteurchoc=0;
    pBonusData->compteurfinchoc=0;
    pBonusData->compteurchoc2=0;
    pBonusData->compteurfinchoc2=0;
    pBonusData->compteurchoc3=0;
    pBonusData->compteurfinchoc3=0;
    pBonusData->compteurchoc4=0;
    pBonusData->compteurfinchoc4=0;

    pBonusData->gravity=0.4;
    pBonusData->friction=0.9;
    pBonusData->speedballon=0;
    pBonusData->compteurfinvit=0;
    pBonusData->speedballonx=0;
}

void Bonus_Update(PGAME _pBonus)
{
    if (!_pBonus->gameData)
    {
        Bonus_Create(_pBonus);
    }
    BonusData* pBonusData = _pBonus->gameData;
    if (_pBonus->pEvent->type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        pBonusData->mouse.x = _pBonus->pEvent->mouse.x*1.25;
        pBonusData->mouse.y = _pBonus->pEvent->mouse.y*1.25;
    }
    if ( _pBonus->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        pBonusData->click=1;
    }
    if (_pBonus->pEvent->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {
        pBonusData->click=0;
    }
    if (_pBonus->pEvent->keyboard.keycode == ALLEGRO_KEY_Q){
        pBonusData->sensbonhomme1 = 1;
        pBonusData->deplacementx1=-1;
    }
    if (_pBonus->pEvent->keyboard.keycode == ALLEGRO_KEY_D){
        pBonusData->sensbonhomme1 = 0;
        pBonusData->deplacementx1=1;
    }
    if (_pBonus->pEvent->keyboard.keycode == ALLEGRO_KEY_RIGHT){
        pBonusData->sensbonhomme2 = 1;
        pBonusData->deplacementx2=1;
    }
    if (_pBonus->pEvent->keyboard.keycode == ALLEGRO_KEY_LEFT){
        pBonusData->sensbonhomme2 = 0;
        pBonusData->deplacementx2=-1;
    }



    if (pBonusData->colision1==0 && pBonusData->colision2==0 && pBonusData->colision3==0){
        pBonusData->deplacementx1 = Get_Touch(_pBonus->pEvent,ALLEGRO_KEY_D,pBonusData->deplacementx1,1,0,pBonusData->deplacementx1);
    }
    if(pBonusData->colision4==0 && pBonusData->colision5==0 && pBonusData->colision6==0){
        pBonusData->deplacementx1 = Get_Touch(_pBonus->pEvent,ALLEGRO_KEY_Q,pBonusData->deplacementx1,-1,0,pBonusData->deplacementx1);
    }
    if (pBonusData->colision1==0 && pBonusData->colision2==0 && pBonusData->colision3==0){
        pBonusData->deplacementx2 = Get_Touch(_pBonus->pEvent,ALLEGRO_KEY_LEFT,pBonusData->deplacementx2,-1,0,pBonusData->deplacementx2);
    }
    if (pBonusData->colision4==0 && pBonusData->colision5==0 && pBonusData->colision6==0){
        pBonusData->deplacementx2 = Get_Touch(_pBonus->pEvent,ALLEGRO_KEY_RIGHT,pBonusData->deplacementx2,1,0,pBonusData->deplacementx2);
    }

    if (pBonusData->colision1==1 && pBonusData->deplacementx2==-1){
        pBonusData->deplacementx2=0;
    }
    if (pBonusData->colision1==1 && pBonusData->deplacementx1==1){
        pBonusData->deplacementx1=0;
    }
    if (pBonusData->colision2==1 && pBonusData->deplacementx2==-1){
        pBonusData->deplacementx2=0;
    }
    if (pBonusData->colision2==1 && pBonusData->deplacementx1==1){
        pBonusData->deplacementx1=0;
    }
    if (pBonusData->colision3==1 && pBonusData->deplacementx2==-1){
        pBonusData->deplacementx2=0;
    }
    if (pBonusData->colision3==1 && pBonusData->deplacementx1==1){
        pBonusData->deplacementx1=0;
    }
    if (pBonusData->colision4==1 && pBonusData->deplacementx2==1){
        pBonusData->deplacementx2=0;
    }
    if (pBonusData->colision4==1 && pBonusData->deplacementx1==-1){
        pBonusData->deplacementx1=0;
    }
    if (pBonusData->colision5==1 && pBonusData->deplacementx2==1){
        pBonusData->deplacementx2=0;
    }
    if (pBonusData->colision5==1 && pBonusData->deplacementx1==-1){
        pBonusData->deplacementx1=0;
    }
    if (pBonusData->colision6==1 && pBonusData->deplacementx2==1){
        pBonusData->deplacementx2=0;
    }
    if (pBonusData->colision6==1 && pBonusData->deplacementx1==-1){
        pBonusData->deplacementx1=0;
    }



    if (_pBonus->pEvent->keyboard.keycode == ALLEGRO_KEY_Z && pBonusData->eligibilitesautJ1==0){
        pBonusData->compteursautJ1 = 1;
        pBonusData->eligibilitesautJ1=1;
    }
    if (_pBonus->pEvent->keyboard.keycode == ALLEGRO_KEY_UP && pBonusData->eligibilitesautJ2==0){
        pBonusData->compteursautJ2 = 1;
        pBonusData->eligibilitesautJ2=1;
    }
    pBonusData->tirJ1= Get_Touch(_pBonus->pEvent,ALLEGRO_KEY_SPACE,pBonusData->tirJ1,1,pBonusData->tirJ1,pBonusData->tirJ1);
    if (_pBonus->pEvent->keyboard.keycode == ALLEGRO_KEY_RCTRL){
        pBonusData->tirJ2=1;
    }

}

void gestionbordurebonhommes(PGAME _pBonus){
    BonusData *pBonusData = _pBonus->gameData;
    if (pBonusData->sensbonhomme1 == 0){
        if (pBonusData->x1 + 188 >= 1660){
            pBonusData->x1=1660-188;
        }
    }
    if (pBonusData->sensbonhomme1 == 1){
        if (pBonusData->x1 + 33 <= 260){
            pBonusData->x1 = 260-33;
        }
    }
    if (pBonusData->sensbonhomme2 == 0){
        if (pBonusData->x2+8 <= 260){
            pBonusData->x2 = 260-8;
        }
    }
    if (pBonusData->sensbonhomme2 == 1){
        if (pBonusData->x2+213 >= 1660){
            pBonusData->x2=1660-213;
        }
    }
}

void affichagebonhommes(PGAME _pBonus){
    BonusData *pBonusData = _pBonus->gameData;
    pBonusData->x1 += pBonusData->deplacementx1 * 8;
    pBonusData->x2 += pBonusData->deplacementx2 * 8;
    if (pBonusData->y1 <= 730 && pBonusData->compteursautJ1==0){
        pBonusData->y1+=8;
    }
    if (pBonusData->y2 <= 730 && pBonusData->compteursautJ2==0){
        pBonusData->y2+=8;
    }
    if (pBonusData->compteursautJ1 == 1){
        pBonusData->y1 -= 30;
        pBonusData->compteurfinsautJ1++;
        if (pBonusData->compteurfinsautJ1 >= 12){
            pBonusData->compteursautJ1 = 0;
            pBonusData->compteurfinsautJ1=0;
        }
    }
    if (pBonusData->compteursautJ2 == 1){
        pBonusData->y2 -= 30;
        pBonusData->compteurfinsautJ2++;
        if (pBonusData->compteurfinsautJ2 >= 12){
            pBonusData->compteursautJ2 = 0;
            pBonusData->compteurfinsautJ2=0;
        }
    }
    gestionbordurebonhommes(_pBonus);
    if (pBonusData->y1 >= 730){
        pBonusData->eligibilitesautJ1 = 0;
    }
    if (pBonusData->y2 >= 730){
        pBonusData->eligibilitesautJ2 = 0;
    }
    if (pBonusData->sensbonhomme1 == 0){
        if (pBonusData->tirJ1==0){
            al_draw_bitmap(pBonusData->image[11],pBonusData->x1,pBonusData->y1-230,0);
        }
        if (pBonusData->tirJ1==1 && pBonusData->a==0){
            if (pBonusData->compteuranimJ1 <= 3){
                al_draw_bitmap(pBonusData->image[11],pBonusData->x1,pBonusData->y1-230,0);
            }
            if (pBonusData->compteuranimJ1 > 3 && pBonusData->compteuranimJ1 <= 6){
                al_draw_bitmap(pBonusData->image[12],pBonusData->x1,pBonusData->y1-230-14,0);
            }
            if (pBonusData->compteuranimJ1 > 6 && pBonusData->compteuranimJ1 <= 9){
                al_draw_bitmap(pBonusData->image[13],pBonusData->x1,pBonusData->y1-230-1,0);
            }
            pBonusData->compteuranimJ1++;
            if (pBonusData->compteuranimJ1 > 10){
                pBonusData->compteuranimJ1=0;
                pBonusData->a=1;
            }
        }
        if (pBonusData->tirJ1 == 1 && pBonusData->compteuranimJ1 == 0){
            if (pBonusData->compteurfinanimJ1 >= 10){
                pBonusData->tirJ1 = 0;
                pBonusData->compteurfinanimJ1=0;
                pBonusData->a=0;
            }
            pBonusData->compteurfinanimJ1++;
        }
    }
    if (pBonusData->sensbonhomme1 == 1){
        if (pBonusData->tirJ1==0){
            al_draw_bitmap(pBonusData->image[14],pBonusData->x1,pBonusData->y1-230,0);
        }
        if (pBonusData->tirJ1==1 && pBonusData->b==0){
            if (pBonusData->compteuranimJ1 <= 3){
                al_draw_bitmap(pBonusData->image[14],pBonusData->x1,pBonusData->y1-230,0);
            }
            if (pBonusData->compteuranimJ1 > 3 && pBonusData->compteuranimJ1 <= 6){
                al_draw_bitmap(pBonusData->image[15],pBonusData->x1,pBonusData->y1-230-14,0);
            }
            if (pBonusData->compteuranimJ1 > 6 && pBonusData->compteuranimJ1 <= 9){
                al_draw_bitmap(pBonusData->image[16],pBonusData->x1,pBonusData->y1-230-1,0);
            }
            pBonusData->compteuranimJ1++;
            if (pBonusData->compteuranimJ1 > 10){
                pBonusData->compteuranimJ1=0;
                pBonusData->b=1;
            }
        }
        if (pBonusData->tirJ1 == 1 && pBonusData->compteuranimJ1 == 0){
            if (pBonusData->compteurfinanimJ1 >= 10){
                pBonusData->tirJ1 = 0;
                pBonusData->compteurfinanimJ1=0;
                pBonusData->b=0;
            }
            pBonusData->compteurfinanimJ1++;
        }
    }
    if (pBonusData->sensbonhomme2 == 0){
        if (pBonusData->tirJ2==0){
            al_draw_bitmap(pBonusData->image[20],pBonusData->x2,pBonusData->y2-230,0);
        }
        if (pBonusData->tirJ2 == 1 && pBonusData->c==0){
            if (pBonusData->compteuranimJ2 <= 3){
                al_draw_bitmap(pBonusData->image[20],pBonusData->x2,pBonusData->y2-230,0);
            }
            if (pBonusData->compteuranimJ2 > 3 && pBonusData->compteuranimJ2 <= 6){
                al_draw_bitmap(pBonusData->image[21],pBonusData->x2,pBonusData->y2-16-230,0);
            }
            if (pBonusData->compteuranimJ2 > 6 && pBonusData->compteuranimJ2 <= 9){
                al_draw_bitmap(pBonusData->image[22],pBonusData->x2,pBonusData->y2-230-15,0);
            }
            pBonusData->compteuranimJ2++;
            if (pBonusData->compteuranimJ2 > 10){
                pBonusData->compteuranimJ2=0;
                pBonusData->c=1;
            }
        }
        if (pBonusData->tirJ2==1 && pBonusData->compteuranimJ2 == 0){
            if (pBonusData->compteurfinanimJ2 >= 10){
                pBonusData->tirJ2=0;
                pBonusData->compteurfinanimJ2=0;
                pBonusData->c=0;
            }
            pBonusData->compteurfinanimJ2++;
        }
    }
    if (pBonusData->sensbonhomme2 == 1){
        if (pBonusData->tirJ2==0){
            al_draw_bitmap(pBonusData->image[17],pBonusData->x2,pBonusData->y2-230,0);
        }
        if (pBonusData->tirJ2==1 && pBonusData->d==0){
            if (pBonusData->compteuranimJ2 <= 3){
                al_draw_bitmap(pBonusData->image[17],pBonusData->x2,pBonusData->y2-230,0);
            }
            if (pBonusData->compteuranimJ2 > 3 && pBonusData->compteuranimJ2 <= 6){
                al_draw_bitmap(pBonusData->image[18],pBonusData->x2,pBonusData->y2-230-16,0);
            }
            if (pBonusData->compteuranimJ2 > 6 && pBonusData->compteuranimJ2 <= 9){
                al_draw_bitmap(pBonusData->image[19],pBonusData->x2,pBonusData->y2-230-15,0);
            }
            pBonusData->compteuranimJ2++;
            if (pBonusData->compteuranimJ2 > 10){
                pBonusData->compteuranimJ2=0;
                pBonusData->d=1;
            }
        }
        if (pBonusData->tirJ2==1 && pBonusData->compteuranimJ2 == 0){
            if (pBonusData->compteurfinanimJ2 >= 10){
                pBonusData->tirJ2=0;
                pBonusData->compteurfinanimJ2=0;
                pBonusData->d=0;
            }
            pBonusData->compteurfinanimJ2++;
        }
    }
}

void gestioncolisions(PGAME _pBonus){
    BonusData *pBonusData = _pBonus->gameData;
    if (pBonusData->sensbonhomme1==0 && pBonusData->sensbonhomme2==0){
        if (((pBonusData->x1+188 >= pBonusData->x2+8 && pBonusData->x1+188 < pBonusData->x2+108) || (pBonusData->x2+8 <= pBonusData->x1+188 && pBonusData->x2+8 >pBonusData->x1+108)) && ((pBonusData->y1-222 >= pBonusData->y2-194 && pBonusData->y1-222 < pBonusData->y2-35) || (pBonusData->y2-194 >= pBonusData->y1-222 && pBonusData->y2-194 < pBonusData->y1-11))){
            pBonusData->colision1=1;
            if (pBonusData->tirJ1 == 1){
                pBonusData->compteurchoc=1;
            }
            if (pBonusData->tirJ2 == 1){
                pBonusData->compteurchoc2=1;
            }
        }
        else {
            pBonusData->colision3=0;
            pBonusData->colision2=0;
            pBonusData->colision1=0;
            pBonusData->colision4=0;
            pBonusData->colision5=0;
            pBonusData->colision6=0;
        }
    }
    if (pBonusData->sensbonhomme1==1 && pBonusData->sensbonhomme2==0){
        if(((pBonusData->x1+146 >= pBonusData->x2+8+20 && pBonusData->x1+146 < pBonusData->x2+38) || (pBonusData->x2+8 <= pBonusData->x1+146-20 && pBonusData->x2+8 >pBonusData->x1+146-38)) && ((pBonusData->y1-222 >= pBonusData->y2-194 && pBonusData->y1-222 < pBonusData->y2-35) || (pBonusData->y2-194 >= pBonusData->y1-222 && pBonusData->y2-194 < pBonusData->y1-11))){
            pBonusData->colision2=1;
            if (pBonusData->tirJ2 == 1){
                pBonusData->compteurchoc2=1;
            }
        }
        else if (pBonusData->x2+80 < pBonusData->x1+33){
            if ((pBonusData->x1+33 <= pBonusData->x2+151 && pBonusData->x1+33 > pBonusData->x2+8) && ((pBonusData->y1-222 >= pBonusData->y2-194 && pBonusData->y1-222 < pBonusData->y2-35) || (pBonusData->y2-194 >= pBonusData->y1-222 && pBonusData->y2-194 < pBonusData->y1-11)) ){
                pBonusData->colision5=1;
                if (pBonusData->tirJ1==1){
                    pBonusData->compteurchoc3=1;
                }
            }
            else {
                pBonusData->colision5=0;
            }
        }
        else {
            pBonusData->colision3=0;
            pBonusData->colision2=0;
            pBonusData->colision1=0;
            pBonusData->colision4=0;
            pBonusData->colision5=0;
            pBonusData->colision6=0;
        }
    }
    if (pBonusData->sensbonhomme1==0 && pBonusData->sensbonhomme2==1){
        if(((pBonusData->x1+188 >= pBonusData->x2+37+20 && pBonusData->x1+188 < pBonusData->x2+38) || (pBonusData->x2+37 <= pBonusData->x1+188-20 && pBonusData->x2+37 >pBonusData->x1+188-38)) && ((pBonusData->y1-222 >= pBonusData->y2-194 && pBonusData->y1-222 < pBonusData->y2-35) || (pBonusData->y2-194 >= pBonusData->y1-222 && pBonusData->y2-194 < pBonusData->y1-11))){
            pBonusData->colision3=1;
            if (pBonusData->tirJ1==1){
                pBonusData->compteurchoc=1;
            }
        }
        else if (pBonusData->x1+100 > pBonusData->x2 +213){
            if (((pBonusData->x2+213 >= pBonusData->x1+68 && pBonusData->x2+213 < pBonusData->x1+188)) && ((pBonusData->y1-222 >= pBonusData->y2-194 && pBonusData->y1-222 < pBonusData->y2-35) || (pBonusData->y2-194 >= pBonusData->y1-222 && pBonusData->y2-194 < pBonusData->y1-11))){
                pBonusData->colision4=1;
                if (pBonusData->tirJ2==1){
                    pBonusData->compteurchoc4=1;
                }
            }
            else {
                pBonusData->colision4=0;
            }
        }
        else {
            pBonusData->colision3=0;
            pBonusData->colision2=0;
            pBonusData->colision1=0;
            pBonusData->colision4=0;
            pBonusData->colision5=0;
            pBonusData->colision6=0;
        }
    }
    if (pBonusData->sensbonhomme2==1 && pBonusData->sensbonhomme1==1){
        if (pBonusData->x1+33 > pBonusData->x2+64){
            if ((pBonusData->x1+33 <= pBonusData->x2+213 && pBonusData->x1+33 > pBonusData->x2+64) && ((pBonusData->y1-222 >= pBonusData->y2-194 && pBonusData->y1-222 < pBonusData->y2-35) || (pBonusData->y2-194 >= pBonusData->y1-222 && pBonusData->y2-194 < pBonusData->y1-11))){
                pBonusData->colision6=1;
                if (pBonusData->tirJ1==1){
                    pBonusData->compteurchoc3=1;
                }
                if (pBonusData->tirJ2==1){
                    pBonusData->compteurchoc4=1;
                }
            }
            else {
                pBonusData->colision6=0;
                pBonusData->colision3=0;
                pBonusData->colision2=0;
                pBonusData->colision1=0;
                pBonusData->colision4=0;
                pBonusData->colision5=0;
            }
        }
        else {
            pBonusData->colision6=0;
            pBonusData->colision3=0;
            pBonusData->colision2=0;
            pBonusData->colision1=0;
            pBonusData->colision4=0;
            pBonusData->colision5=0;
        }
    }
    if (pBonusData->compteurchoc==1){
        pBonusData->x2+=10;
        if (pBonusData->sensbonhomme2==0){
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+32,pBonusData->y2-199+53,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+89,pBonusData->y2-199+119,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+45,pBonusData->y2-199+148,0);
        }
        if (pBonusData->sensbonhomme2==1){
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+128,pBonusData->y2-199+50,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+79,pBonusData->y2-199+108,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+115,pBonusData->y2-199+150,0);
        }
        if (pBonusData->sensbonhomme2==0){
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+32,pBonusData->y2-199+53,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+89,pBonusData->y2-199+119,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+45,pBonusData->y2-199+148,0);
        }
        if (pBonusData->sensbonhomme2==1){
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+128,pBonusData->y2-199+50,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+79,pBonusData->y2-199+108,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+115,pBonusData->y2-199+150,0);
        }
        if (pBonusData->x2+151 >= 1660){
            pBonusData->x2 = 1660-151;
        }
        pBonusData->compteurfinchoc++;
        if (pBonusData->compteurfinchoc >= 30){
            pBonusData->compteurchoc=0;
            pBonusData->compteurfinchoc=0;
        }
    }
    if (pBonusData->compteurchoc2==1){
        pBonusData->x1-=10;
        if (pBonusData->x1+68 <= 260){
            pBonusData->x1 = 260-68;
        }
        if (pBonusData->sensbonhomme1==0){
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+102,pBonusData->y1-199+7,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+36,pBonusData->y1-199+94,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+78,pBonusData->y1-199+136,0);
        }
        if (pBonusData->sensbonhomme1==1){
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+68,pBonusData->y1-199+17,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+133,pBonusData->y1-199+104,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+96,pBonusData->y1-199+128,0);
        }
        if (pBonusData->sensbonhomme1==0){
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+102,pBonusData->y1-199+7,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+36,pBonusData->y1-199+94,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+78,pBonusData->y1-199+136,0);
        }
        if (pBonusData->sensbonhomme1==1){
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+68,pBonusData->y1-199+17,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+133,pBonusData->y1-199+104,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+96,pBonusData->y1-199+128,0);
        }
        pBonusData->compteurfinchoc2++;
        if (pBonusData->compteurfinchoc2 >= 30){
            pBonusData->compteurfinchoc2=0;
            pBonusData->compteurchoc2=0;
        }
    }
    if (pBonusData->compteurchoc3==1){
        pBonusData->x2-=10;
        if (pBonusData->x2+8 <= 260){
            pBonusData->x2=260-8;
        }
        if (pBonusData->sensbonhomme2==0){
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+32,pBonusData->y2-199+53,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+89,pBonusData->y2-199+119,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+45,pBonusData->y2-199+148,0);
        }
        if (pBonusData->sensbonhomme2==1){
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+128,pBonusData->y2-199+50,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+79,pBonusData->y2-199+108,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x2+115,pBonusData->y2-199+150,0);
        }
        if (pBonusData->sensbonhomme2==0){
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+32,pBonusData->y2-199+53,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+89,pBonusData->y2-199+119,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+45,pBonusData->y2-199+148,0);
        }
        if (pBonusData->sensbonhomme2==1){
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+128,pBonusData->y2-199+50,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+79,pBonusData->y2-199+108,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x2+115,pBonusData->y2-199+150,0);
        }
        pBonusData->compteurfinchoc3++;
        if (pBonusData->compteurfinchoc3 >= 30){
            pBonusData->compteurfinchoc3=0;
            pBonusData->compteurchoc3=0;
        }
    }
    if (pBonusData->compteurchoc4==1){
        pBonusData->x1+=10;
        if (pBonusData->x1+188 >= 1660){
            pBonusData->x1=1660-188;
        }
        if (pBonusData->sensbonhomme1==0){
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+102,pBonusData->y1-199+7,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+36,pBonusData->y1-199+94,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+78,pBonusData->y1-199+136,0);
        }
        if (pBonusData->sensbonhomme1==1){
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+68,pBonusData->y1-199+17,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+133,pBonusData->y1-199+104,0);
            al_draw_bitmap(pBonusData->image[24],pBonusData->x1+96,pBonusData->y1-199+128,0);
        }
        if (pBonusData->sensbonhomme1==0){
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+102,pBonusData->y1-199+7,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+36,pBonusData->y1-199+94,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+78,pBonusData->y1-199+136,0);
        }
        if (pBonusData->sensbonhomme1==1){
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+68,pBonusData->y1-199+17,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+133,pBonusData->y1-199+104,0);
            al_draw_bitmap(pBonusData->image[25],pBonusData->x1+96,pBonusData->y1-199+128,0);
        }
        pBonusData->compteurfinchoc4++;
        if (pBonusData->compteurfinchoc4 >= 30){
            pBonusData->compteurchoc4=0;
            pBonusData->compteurfinchoc4=0;
        }
    }
    //printf("1:%d\n2:%d\n3:%d\n4:%d\n5:%d\n6:%d\n",pBonusData->colision1,pBonusData->colision2,pBonusData->colision3,pBonusData->colision4,pBonusData->colision5,pBonusData->colision6);
}

void gestionballe(PGAME _pBonus){
    BonusData *pBonusData = _pBonus->gameData;
    pBonusData->yballon+=pBonusData->speedballon;
    pBonusData->yballon+=2*pBonusData->gravity;
    pBonusData->xballon+=pBonusData->speedballonx*0.80;
    if (pBonusData->speedballon >= 40){
        pBonusData->speedballon=40;
    }
    if (pBonusData->speedballon <= -40){
        pBonusData->speedballon=-40;
    }
    if (pBonusData->speedballonx >= 40){
        pBonusData->speedballonx=40;
    }
    if (pBonusData->speedballonx <= -40){
        pBonusData->speedballonx=-40;
    }
    if (pBonusData->xballon+70 >= 1660){
        pBonusData->xballon=1660-70;
        pBonusData->speedballonx*=-1;
    }
    if (pBonusData->xballon+9 <= 260){
        pBonusData->xballon=260-9;
        pBonusData->speedballonx*=-1;
    }
    if (pBonusData->yballon+4 <= 0){
        pBonusData->yballon=0-4;
        pBonusData->speedballon*=-1;
    }
    if(pBonusData->compteurfinvit==0){
        pBonusData->speedballon+=pBonusData->gravity;
    }
    else {
        pBonusData->speedballon=0;
        pBonusData->friction=0;
    }
    if (pBonusData->yballon >= 730){
        pBonusData->speedballon=-pBonusData->speedballon*pBonusData->friction;
        pBonusData->yballon=730;
    }
    if (pBonusData->yballon<=680){
        pBonusData->compteurchutteballon=0;
    }
    else {
        pBonusData->compteurchutteballon++;
    }
    if (pBonusData->compteurchutteballon>=10){
        pBonusData->compteurfinvit=1;
    }
    if (pBonusData->sensbonhomme1==0){
        if (pBonusData->xballon+9 <= pBonusData->x1+188 && pBonusData->xballon+9 > pBonusData->x1+100){
            if (pBonusData->yballon+39 <= pBonusData->y1 && pBonusData->yballon+39 > pBonusData->y1+174-232){
                if (pBonusData->tirJ1==1){
                    pBonusData->speedballonx+=10;
                    pBonusData->speedballonx *= 2;
                    pBonusData->speedballon *= -3;
                }
                else {
                    pBonusData->speedballonx+=10;
                    pBonusData->speedballonx *= 1;
                    pBonusData->speedballon *= -1;
                }
            }

        }
        if (pBonusData->xballon+70 >= pBonusData->x1+68 && pBonusData->xballon+70 < pBonusData->x1){

        }
    }
    al_draw_rectangle(pBonusData->x1+100,pBonusData->y1+232-232,pBonusData->x1+188,pBonusData->y1+174-232, al_map_rgb(255,0,0),5);
    al_draw_rectangle(pBonusData->xballon+9,pBonusData->yballon+39,pBonusData->xballon+9+5,pBonusData->yballon+39+5,
                      al_map_rgb(255,0,0),5);
}

void Bonus_TimedUpdate(PGAME _pBonus) {
    BonusData *pBonusData = _pBonus->gameData;
    al_draw_bitmap(pBonusData->image[0],0,0,0);
    al_draw_bitmap(pBonusData->image[1],1500,950,0);
    al_draw_bitmap(pBonusData->image[2],500,950,0);
    al_draw_bitmap(pBonusData->image[9],1550,950,0);
    al_draw_bitmap(pBonusData->image[10],450,950,0);
    al_draw_bitmap(pBonusData->image[3],250,950,0);
    al_draw_bitmap(pBonusData->image[4],300,900,0);
    al_draw_bitmap(pBonusData->image[5],350,950,0);
    al_draw_bitmap(pBonusData->image[6],1700,900,0);
    al_draw_bitmap(pBonusData->image[7],1650,950,0);
    al_draw_bitmap(pBonusData->image[8],1750,950,0);
    affichagebonhommes(_pBonus);
    gestioncolisions(_pBonus);
    gestionballe(_pBonus);
    al_draw_bitmap(pBonusData->image[23],pBonusData->xballon,pBonusData->yballon,0);

}

void Bonus_Destroy(PGAME _pBonus){
    free(_pBonus->gameData);
    _pBonus->gameData = NULL;
}