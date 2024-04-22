#include <stdio.h>
#include <stdlib.h>
#include "enigme.h"


int clickedon(int mousex, int mousey, SDL_Rect postext) {
    int pos = 0;
    if (mousex >= postext.x && mousex <= postext.x + postext.w &&
        mousey >= postext.y && mousey <= postext.y + postext.h) {
        pos = 1;
    }
    return pos;
}

int main()
{
SDL_Rect postext_r1;SDL_Rect postext_r2;SDL_Rect postext_r3;
    TTF_Font *police_e;
    SDL_Surface*screen=NULL;
    SDL_Event event;
    enigme e;
    


    TTF_Init();
    int keep=1;
    int current_frame=0;
    int animation_delay = 100; // Delay for animation frames in milliseconds

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initilize SDL:%s\n",SDL_GetError());
        return 1;
    }


    screen=SDL_SetVideoMode(830,723,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("unable to set video mode: %s\n",SDL_GetError());
    }
    
    GenererEnigme(&e);
    
    e.animation1 = IMG_Load("anim1.png");
    e.animation2 = IMG_Load("anim2.png");
    e.animation3 = IMG_Load("anim3.png");
    e.animation4=IMG_Load("anim4.png");
    e.animation5=IMG_Load("anim5.png");
    e.posanimPos.x = 0;
    e.posanimPos.y = 0;
    
    if (e.animation1 == NULL || e.animation2 == NULL || e.animation3 == NULL || e.animation4 == NULL || e.animation5 == NULL) {
        printf("Unable to load images: %s\n", IMG_GetError());
        return 1;
        }
        
        e.posmessage.x = 500;
        e.posmessage.y = 300;
    	
	
	SDL_Color red={125,0,0};
	SDL_Color green={0,200,0};
	
	int i,j,verif=0;
    

    init_enigme(&e,screen);


    while (keep)

    {
    	current_frame++;
    	e.posmessage.x = 650;
        e.posmessage.y = 290;
        e.posmessage1.x = 650;
        e.posmessage1.y = 390;
        e.posmessage2.x = 650;
        e.posmessage2.y = 490;
    	
	
	SDL_Color red={255,0,0};
	SDL_Color lime={0,255,0};
	
	int i,j,verif=0;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    keep=0;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE :
                            keep = 0;
                            break;
                        case SDLK_g:
                            if(verif==0){
                                if(e.right_answer!=1)
                                {
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"FAILED",red);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                                else if(e.right_answer==1){
                                    verif=1;
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"GOOD JOB",lime);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                           
                                }
                            }
                            break;
                        case SDLK_h:
                            if(verif==0){
                                if(e.right_answer!=2){
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"FAILED",red);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage1);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                                else if(e.right_answer==2){
                                    verif=1;
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"GOOD JOB",lime);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage1);
                                    SDL_Flip(screen);
                                   SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                            }
                            break;
                        case SDLK_j:
                            if(verif==0){
                                if(e.right_answer!=3){
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"FAILED",red);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage2);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                                else if(e.right_answer==3){
                                    verif=1;
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"GOOD JOB",lime);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage2);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                            }
                            break;
                    }
                    break;
            
            case SDL_MOUSEBUTTONDOWN: {
            int mousex, mousey;
            SDL_GetMouseState(&mousex, &mousey);

            if (event.motion.x > 350 && event.motion.x< 750 && event.motion.y > 240 && event.motion.y < 300) {
            if(verif==0){
                                if(e.right_answer!=1)
                                {
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"FAILED",red);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                                else if(e.right_answer==1){
                                    verif=1;
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"GOOD JOB",lime);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                            }
		 
		break;
            } else if (event.motion.x > 350 && event.motion.x< 750 && event.motion.y > 340 && event.motion.y < 400) {
            if(verif==0){
                                if(e.right_answer!=2){
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"FAILED",red);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage1);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                                else if(e.right_answer==2){
                                    verif=1;
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"GOOD JOB",lime);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage1);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                            }
                break;
            } else if (event.motion.x > 350 && event.motion.x< 750 && event.motion.y > 440 && event.motion.y < 500) {
            	if(verif==0){
                                if(e.right_answer!=3){
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"FAILED",red);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage2);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                                else if(e.right_answer==3){
                                    verif=1;
                                    e.surface_message=TTF_RenderText_Blended(e.police_e,"GOOD JOB",lime);
                                    SDL_BlitSurface(e.surface_message,NULL,screen,&e.posmessage2);
                                    SDL_Flip(screen);
                                    SDL_Delay(800);
    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();
                                }
                            }
            	break;
            }
            break;
        }
            
            
            }
        }
            
   
        AfficherEnigme(&e,screen);
        switch (current_frame % 5) 
        {
            case 0:
                SDL_BlitSurface(e.animation1, NULL, screen,&e.posanimPos);
                SDL_Flip(screen);
                SDL_Delay(animation_delay);
                break;
            case 1:
                SDL_BlitSurface(e.animation2, NULL, screen,&e.posanimPos);
                SDL_Flip(screen);
                SDL_Delay(animation_delay);
                break;
            case 2:
                SDL_BlitSurface(e.animation3, NULL, screen,&e.posanimPos);
                SDL_Flip(screen);
                SDL_Delay(animation_delay);
                break;
                 case 3:
                SDL_BlitSurface(e.animation4, NULL, screen,&e.posanimPos);
                SDL_Flip(screen);
                SDL_Delay(animation_delay);
                break;
                 case 4:
                SDL_BlitSurface(e.animation5, NULL, screen,&e.posanimPos);
                SDL_Flip(screen);
                SDL_Delay(animation_delay);
                break;
        }
        
        AfficherEnigme(&e,screen);
        SDL_Flip(screen);

    }

    SDL_FreeSurface(e.animation1);
    SDL_FreeSurface(e.animation2);
    SDL_FreeSurface(e.animation3);
    SDL_FreeSurface(e.animation4);
    SDL_FreeSurface(e.animation5);
    SDL_FreeSurface(screen);
    TTF_CloseFont(police_e);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

