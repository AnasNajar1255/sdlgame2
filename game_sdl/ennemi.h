
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
 #include <unistd.h>


typedef struct Enemy
{
  SDL_Surface *image[3];
  SDL_Surface *image2[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int frame;
  int direction;
  int died;

}Enemy;

Enemy InitEnemy(Enemy Ennemie,int x, int y);
void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen);
Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage,int *stat,int mouvment);
Enemy AnimateEnemy(Enemy Ennemie,int stat);
Enemy diedennemie(Enemy Ennemie);


