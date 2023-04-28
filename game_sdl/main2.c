#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "perso.h" 
#include "background.h" 
#include "ennemi.h"

	int main ( int argc, char *argv[] ){
	SDL_Surface *ecran=NULL; 
	 int  d; 
int posint;	
personnage pers; 
personnage pers2;	
Uint32 dt,t_prev;
background b;
int direction2;
TTF_Font *fontTest;
int stat;

SDL_Init(SDL_INIT_VIDEO);
TTF_Init();	
int continuer=1;
	SDL_Event evenement; 

	ecran=SDL_SetVideoMode(1386,500,32,SDL_HWSURFACE); 



initialiser_back(&b);
afficher_background (ecran,&b);








//le personnage
init_perso(&pers,fontTest);

SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY,
SDL_DEFAULT_REPEAT_INTERVAL);	
Enemy e;
e=InitEnemy(e,800,250 );

SDL_Flip(ecran);

while(continuer){
e=AnimateEnemy(e,stat);
AfficherEnemy(e,ecran);
e=MoveEnemy(e,pers.Positionmat,&stat,3);

afficherperso(&pers,ecran);







if(SDL_PollEvent(&evenement))
{
t_prev=SDL_GetTicks();


if(evenement.type==SDL_QUIT)
{
continuer=0;
break;}	

if(evenement.type==SDL_KEYDOWN){

if(evenement.key.keysym.sym==SDLK_ESCAPE)
{
continuer=0;
break;}


else if(evenement.key.keysym.sym==SDLK_LEFT){
	         d=1;
               	  pers.d=1;          


} 
	  else 
	    if (evenement.key.keysym.sym==SDLK_RIGHT){
	          d=0; 
	            pers.d=0;


} 
    else 
	    if (evenement.key.keysym.sym==SDLK_a){

              d=2;
         pers.d=2; 
         if(pers.mat[pers.d][pers.num]== pers.mat[2][3] )   
 {e=diedennemie(e);}

}
 else 
	    if (evenement.key.keysym.sym==SDLK_SPACE)
{

pers.acceleration+=0.005;


}
else if (evenement.key.keysym.sym==SDLK_d)
{    

pers.acceleration-=0.01;

}


else if (evenement.key.keysym.sym==SDLK_DOWN)
{
scrolling(&b,direction2);
}


if(d>=0 && d<=1)
	 {deplacer_perso(d,&pers);

}
movePerso(&pers,dt);         

animateEntity(&pers);




}
}
else {
switch (evenement.type)
{





case SDL_KEYUP:
{if(evenement.key.keysym.sym == SDLK_UP)
 {pers.positionmatRel.x++;

            if(pers.positionmatRel.x>=50)
            {
                pers.positionmatRel.x=-50;
            }
 pers.Positionmat.x = 0;
            pers.Positionmat.y = 250;


            //On calcule la valeur relative de y:
            pers.positionmatRel.y=(-0.04*(pers.positionmatRel.x*pers.positionmatRel.x)+100);

            //On calcule maintenant les valeurs abs
            pers.Positionmat.x = pers.Positionmat.x + pers.positionmatRel.x+50;
            pers.Positionmat.y = pers.Positionmat.y - pers.positionmatRel.y;  
}

break;
}
}
}



SDL_Delay(20);

afficher_background (ecran,&b);

SDL_Flip (ecran);
blitEntity(&pers,ecran);
dt=SDL_GetTicks()-t_prev;
}


SDL_Surface *vie;
        SDL_Surface *score;
//Liberer la memoire


SDL_FreeSurface(e.image[3]);
SDL_FreeSurface(e.image2[3]);
SDL_FreeSurface(e.Hit);
SDL_FreeSurface(e.imageActuel);

SDL_FreeSurface(pers.vie);
SDL_FreeSurface(pers.score);
SDL_FreeSurface(pers.mat[d][pers.num]);
SDL_FreeSurface(pers2.vie);
SDL_FreeSurface(pers2.score);
SDL_FreeSurface(pers2.mat[d][pers2.num]);
SDL_FreeSurface(ecran); 
SDL_FreeSurface(b.background);
	TTF_Quit();
	SDL_Quit();  
	return 0; 
	}
