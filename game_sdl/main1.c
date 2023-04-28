void saut(personnage * pers)
{
    pers->positionmatRel.x++;

    if(pers->positionmatRel.x >= 50)
    {
        pers->positionmatRel.x = -50;
    }

    pers->Positionmat.x = 0;
    pers->Positionmat.y = 250;

    pers->positionmatRel.y = (-0.04 * (pers->positionmatRel.x * pers->positionmatRel.x) + 100);

    pers->Positionmat.x = pers->Positionmat.x + pers->positionmatRel.x + 50;
    pers->Positionmat.y = pers->Positionmat.y - pers->positionmatRel.y;
}

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    int d;
    personnage pers;
    Uint32 dt, t_prev;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    int continuer = 1;
    SDL_Event evenement;

    ecran = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    init_perso(&pers, NULL);

    while (continuer)
    {
        t_prev = SDL_GetTicks();

        SDL_PollEvent(&evenement);
        switch (evenement.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (evenement.key.keysym.sym)
            {
            case SDLK_SPACE:
                saut(&pers);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        animateEntity(&pers);
        blitEntity(&pers, ecran);
        afficherperso(&pers, ecran);

        SDL_Delay(10);

        dt = SDL_GetTicks() - t_prev;

        movePerso(&pers, dt);

        SDL_Flip(ecran);
    }

    SDL_Quit();
    TTF_Quit();
    return 0;
}

