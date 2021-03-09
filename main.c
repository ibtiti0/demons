#include <stdio.h>
#include <stdlib.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
 
 
int main(int argc,char **argv){
// variable
SDL_Surface *screen=NULL;
SDL_Surface *menu=NULL,*button=NULL,*button2=NULL,*button3=NULL,*b1=NULL,*b2=NULL,*b3=NULL,*b4=NULL,*texte=NULL,*button4=NULL;
int running=1;
int continuer_p=1; 
SDL_Rect posmenu,posb1,posb2,posb3,posplay,postxt,posb4,positionClic,posbutton,posbutton2,posbutton3,posbutton4;
SDL_Event event;
 
// couleur 
 
SDL_Color couleurNoire={0,0,0},couleurBlanche ={255,255,255};



 
 
 // intialisation police 
SDL_Init(SDL_INIT_EVERYTHING );
TTF_Init();
TTF_Font *policeBig =NULL,*bpolice=NULL;
// play music
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT ,2,2048)==-1)
{
printf("%s" ,Mix_GetError());
}
Mix_Music *bgm= Mix_LoadMUS("Nouba2.mp3");
Mix_PlayMusic(bgm,-1);

screen=SDL_SetVideoMode(750,426,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 
SDL_WM_SetCaption("GameMenu",NULL);
//game title

/*policeBig=TTF_OpenFont("misty.ttf",75);//grande police
bpolice=TTF_OpenFont("times.ttf",35); // bouton police
texte=TTF_RenderText_Blended(policeBig,"Lost Valley",couleurNoire);
b1=TTF_RenderText_Blended(bpolice,"NewGame",couleurNoire);
b2=TTF_RenderText_Blended(bpolice,"Continue",couleurNoire);
b3=TTF_RenderText_Blended(bpolice,"Options",couleurNoire);
b4=TTF_RenderText_Blended(bpolice,"Quit ",couleurNoire);
postxt.x=220;
postxt.y=50;
posb1.x=300;
posb1.y=210;
posb2.x=310;
posb2.y=310;
posb3.x=320;
posb3.y=410;
posb4.x=340;
posb4.y=510;*/
//ajout image 
menu=IMG_Load("background.bmp");
button=IMG_Load("play1.png");
button2=IMG_Load("settings1.png");
button3=IMG_Load("b0.png");
button4=IMG_Load("b0.png");

posmenu.x=0;
posmenu.y=0;
posbutton.x=500;
posbutton.y=30;
posbutton2.x=500;
posbutton2.y=0;
posbutton3.x=300;
posbutton3.y=400;
posbutton4.x=300;
posbutton4.y=500;


//boucle
while(running){
SDL_WaitEvent(&event);
switch(event.type){
case SDL_QUIT :
running=0;
break;
case SDL_KEYDOWN :
switch(event.key.keysym.sym){

case SDLK_ESCAPE :
running=0;
break;


 
}}

// 
SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
// blits 
SDL_BlitSurface(menu,NULL,screen,&posmenu);
SDL_BlitSurface(button,NULL,screen,&posbutton);
SDL_BlitSurface(button2,NULL,screen,&posbutton2);
SDL_BlitSurface(button3,NULL,screen,&posbutton3);
SDL_BlitSurface(button4,NULL,screen,&posbutton4);
SDL_BlitSurface(texte,NULL,screen,&postxt);
SDL_BlitSurface(b1,NULL,screen,&posb1);
SDL_BlitSurface(b2,NULL,screen,&posb2);
SDL_BlitSurface(b3,NULL,screen,&posb3);
SDL_BlitSurface(b4,NULL,screen,&posb4);


 

SDL_Flip(screen);
 
 
}



//free
SDL_FreeSurface(button);
SDL_FreeSurface(button2);
SDL_FreeSurface(button3);
SDL_FreeSurface(button4);
SDL_FreeSurface(menu);

SDL_FreeSurface(texte); 
SDL_FreeSurface(b1);
SDL_FreeSurface(b2);
SDL_FreeSurface(b3);
SDL_FreeSurface(b4);
Mix_FreeMusic(bgm);

//quit
/*TTF_CloseFont(policeBig);
TTF_CloseFont(bpolice);
TTF_Quit(); 
Mix_Quit();*/
SDL_Quit();
return EXIT_SUCCESS;
 
}
