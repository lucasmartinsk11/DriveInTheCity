#include <SDL.h>
#include <SDL_ttf.h>
#include <cassert>
#include <iostream>
// sdl2
// sdl2_image
// sdl2_ttf



int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window* win = SDL_CreateWindow("Hello World!",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         600, 800, SDL_WINDOW_SHOWN
                      );

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    
    TTF_Font *fnt = TTF_OpenFont("/src/fonts/Roboto-Regular.ttf", 20);
    // std::cout << "-->" << fnt;
    assert(fnt != NULL);
    SDL_Color clr = {0xFF, 0x00, 0x00, 0xFF};
    SDL_Surface *sfc = TTF_RenderText_Blended(fnt, "ola mundo", clr);
    assert(sfc != NULL);
    SDL_Texture *txt = SDL_CreateTextureFromSurface(ren, sfc);
    assert(txt != NULL);
    SDL_FreeSurface(sfc);

    /* EXECUÇÃO */
    bool is_running = true;
    SDL_Event event;
    //TTF
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_Rect r = { 50,50, 200,80 };
    SDL_RenderCopy(ren, txt, NULL, &r);
    SDL_RenderPresent(ren);

    //
    while (is_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_running = false;
            }
        }
        SDL_Delay(16);
    }

    /* FINALIZACAO */
    SDL_DestroyTexture(txt);
    TTF_CloseFont(fnt);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
}