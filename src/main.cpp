/*****************************************************************************
* Filename : main.cpp
* Date : 4-7-2020
* Author : Ram
* Email : ramkalath@gmail.com
* Breif Description : First attempts to build a game engine.
* Detailed Description : 1) lets build a renderer to load models
							- this requires modelloading; lighting and texturing
*****************************************************************************/

#include<iostream>
#include<SDL2/SDL.h>
#include<chrono>
#include"../include/gamesettings.h"

// measure time
		//auto start1 = std::chrono::high_resolution_clock::now(); 
		//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start1).count(); 
		//std::cout << duration << std::endl;

int main()
{
	unsigned int window_height =1920, window_width = 1080;
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
	SDL_Event event;
	bool quit_event = 0; /* TODO(ram): toggling this to 1 quits the game for now; 
						  but have to make something more interactive; 
						  save game state etc should be implemented */

	unsigned int tmp_fps = 0, fps = 0;  

    if(SDL_Init( SDL_INIT_VIDEO) < 0) 
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	else 
	{
        window = SDL_CreateWindow("Groot Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_height, window_width, SDL_WINDOW_SHOWN);
        if( window == NULL )
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
	}

	screenSurface = SDL_GetWindowSurface( window );

	auto start = std::chrono::high_resolution_clock::now(); 

	while(!quit_event)
	{

		/* here is where we blit stuff on the screen */
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x0E, 0x0E, 0x0E));
		SDL_UpdateWindowSurface(window);

		/* static object renderer */


		/* TODO(ram): 1) quit event handling implemented
				   2) other keyboard events should be handled */
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT) quit_event=1;
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) quit_event=1; // for now this initiates the quit sequence

		/* fps calculation */
		calculate_fps(&start, &tmp_fps, &fps); /* be sure to pass two unsigned ints by reference */
		//if(fps) std::cout << fps << std::endl; [> print fps out <]
	}

    SDL_DestroyWindow(window);
    SDL_Quit();
	return 0;
}
