/***********************************************
** The Graphics class contains all information 
** dealing with graphics for the game.
************************************************/

#include "graphics.h"
#include <SDL.h>

Graphics::Graphics()
{
	//Creates a 640x480 window for the game.
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);

	//Just adds a title at the top of the window.
	SDL_SetWindowTitle(this->_window, "Cave Story Remake");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
}