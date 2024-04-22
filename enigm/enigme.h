#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

typedef struct
{
SDL_Surface *backenigme;
SDL_Rect posbackenigme;
SDL_Surface *animation1;
SDL_Surface *animation2;
SDL_Surface *animation3;
SDL_Surface *animation4;
SDL_Surface *animation5;

SDL_Surface *text_e;
SDL_Rect postext_e;
SDL_Surface *text_question;
SDL_Rect postext_question;
SDL_Surface *text_r1;
SDL_Rect postext_r1;
SDL_Surface *text_r2;
SDL_Rect postext_r2;
SDL_Surface *text_r3;
SDL_Rect postext_r3;
TTF_Font *police_e;
SDL_Surface *animPos;
SDL_Rect posanimPos;
SDL_Rect posmessage;
SDL_Rect posmessage1;
SDL_Rect posmessage2;
SDL_Surface *surface_message;
int current_frame;
int frame_counter;
char question[60];
char reponse1[50],reponse2[50],reponse3[50]; 
int right_answer;
}enigme;

void AfficherEnigme(enigme * e,SDL_Surface * screen);
int clickedon(int mousex, int mousey, SDL_Rect image);
void init_enigme(enigme * e,SDL_Surface * screen);
void animerEnigme(enigme * e);
void GenererEnigme(enigme * e);




#endif 

