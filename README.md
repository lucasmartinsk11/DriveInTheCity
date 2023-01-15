## How to build  
- `clang++ src/main.cpp -o play -I/opt/homebrew/Cellar/sdl2/2.26.2/include/SDL2/ -I/opt/homebrew/Cellar/sdl2_ttf/2.20.1/include/SDL2 -I/opt/homebrew/Cellar/sdl2_image/2.6.2_1/include/SDL2 -L/opt/homebrew/Cellar/sdl2_ttf/2.20.1/lib -lSDL2_ttf -F/Library/Frameworks -framework SDL2`

- `clang++ src/main.cpp -o play -I/Library/Framework/Headers/SDL.h -I/opt/homebrew/Cellar/sdl2_ttf/2.20.1/include/SDL2 -L/opt/homebrew/Cellar/sdl2_ttf/2.20.1/lib -lSDL2_ttf -F/Library/Frameworks -framework SDL2` 
## How to run
- `./play`