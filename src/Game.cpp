#include "Game.hpp"
#include "TextureManager.hpp"

SDL_Texture *playerTexture;
SDL_Rect sourceRect;
SDL_Rect destinationRect;

Game::Game()
{
}
Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Initialised" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            std::cout << "Renderer created" << std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
    
    playerTex = TextureManager::LoadTexture("/src/images/assets/player.png", renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            isRunning = false;
            break;
        default:
            break;
        }
    default:
        break;
    }
}

void Game::update()
{
    cnt++;
    destinationRect.h = 32;
    destinationRect.w = 32;
    destinationRect.x = cnt;
    std::cout << cnt << std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0x00); // Remove after
    SDL_RenderFillRect(renderer, &destinationRect);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // Remove after
    // SDL_RenderCopy(renderer, playerTexture, NULL, &destinationRect);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    // SDL_DestroyTexture(txt);
    // TTF_CloseFont(fnt);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // TTF_Quit();
    SDL_Quit();
}
