#include <stdio.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"

void AfficherEnigme(enigme * e,SDL_Surface * screen)
{   
SDL_BlitSurface(e->backenigme,NULL,screen,NULL);
SDL_BlitSurface(e->text_e,NULL,screen,&e->postext_e);
SDL_BlitSurface(e->text_question,NULL,screen,&e->postext_question);
SDL_BlitSurface(e->text_r1,NULL,screen,&e->postext_r1);
SDL_BlitSurface(e->text_r2,NULL,screen,&e->postext_r2);
SDL_BlitSurface(e->text_r3,NULL,screen,&e->postext_r3);
}

void init_enigme(enigme * e,SDL_Surface * screen)
{
    SDL_Color white = {255, 255, 255};
    SDL_Color black = {0, 0, 0};


    e->backenigme = IMG_Load("enigm.png");
    e->posbackenigme.x = 0;
    e->posbackenigme.y = 0;
    e->posbackenigme.w = 0;
    e->posbackenigme.h = 0;

    if (e->backenigme == NULL)
    {
        printf("Unable to set enigme background: %s\n", SDL_GetError());
    }


    e->police_e = TTF_OpenFont("font.ttf", 30);
    if (e->police_e == NULL)
    {
        printf("Unable to load font: %s\n", TTF_GetError());
    }


    e->text_e = TTF_RenderText_Blended(e->police_e, "every humain has a right ", black);
    if (e->text_e == NULL)
    {
        printf("Unable to render text: %s\n", TTF_GetError());
    }


    e->postext_e.x = 5;
    e->postext_e.y = 5;

    e->postext_question.x = 260;
    e->postext_question.y = 50;

    e->postext_r1.x = 350;
    e->postext_r1.y = 240;
    e->postext_r1.w = 100;
    e->postext_r1.h = 50;

    e->postext_r2.x = 350;
    e->postext_r2.y = 340;
    e->postext_r2.w = 100;
    e->postext_r2.h = 50;

    e->postext_r3.x = 350;
    e->postext_r3.y = 440;
    e->postext_r3.w = 100;
    e->postext_r3.h = 50;
    


    e->text_question = TTF_RenderText_Blended(e->police_e, e->question, white);
    
    if (e->text_question == NULL)
    {
        printf("Unable to render text: %s\n", TTF_GetError());
    }

    e->text_r1 = TTF_RenderText_Blended(e->police_e, e->reponse1, white);
    if (e->text_r1 == NULL)
    {
        printf("Unable to render text: %s\n", TTF_GetError());
    }

    e->text_r2 = TTF_RenderText_Blended(e->police_e, e->reponse2, white);
    if (e->text_r2 == NULL)
    {
        printf("Unable to render text: %s\n", TTF_GetError());
    }

    e->text_r3 = TTF_RenderText_Blended(e->police_e, e->reponse3, white);
    if (e->text_r3 == NULL)
    {
        printf("Unable to render text: %s\n", TTF_GetError());
    }
//TTF_CloseFont(police);
}

/*void animerEnigme(enigme *e, SDL_Surface *screen) {
    int i;
    char filename[50];
    SDL_Surface *temp_surface = NULL; // Temporary surface

    for (i = 1; i <= 5; i++) {
        sprintf(filename, "anim%d.png", i);
        temp_surface = IMG_Load(filename); // Load the image into a temporary surface

        if (temp_surface == NULL) {
            printf("Error loading image: %s\n", SDL_GetError());
            break;
        }

        SDL_BlitSurface(temp_surface, NULL, screen, &e->animPos); // Display the image on the screen
        SDL_Flip(screen); // Refresh the screen
        SDL_Delay(20); // Delay between each image

        SDL_FreeSurface(temp_surface);
        temp_surface = NULL; // Reset the temporary surface
    }
}*/


void GenererEnigme(enigme * e)
{
char nomfichier[10];
FILE *f;
int j;
srand(time(NULL));

j= rand() % 3;
sprintf(nomfichier,"quest%d.txt",j);
f=fopen(nomfichier,"r");
fscanf(f,"%s %s %s %s %d",e->question,e->reponse1,e->reponse2,e->reponse3,&e->right_answer);
fclose(f);
}
/*int genererEnigme() {
    srand(time(NULL));
    int i = (rand() % 3) ; // Generates a random number between 1 and 3
    return i;
}*/


