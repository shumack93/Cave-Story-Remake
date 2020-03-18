/***********************************************
** The Game class holds all information for
** the main game loop.
************************************************/

#include <SDL.h>
#include <algorithm>
#include "game.h"
#include "graphics.h"
#include "input.h"

using std::min;

//Limites framerates.
namespace
{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game()
{
	//Initializes all subsystems (audio, video, timer, controller, joystick, etc.).
	SDL_Init(SDL_INIT_EVERYTHING);

	this->gameLoop();
}

//gameLoop is called via the constructor.
void Game::gameLoop()
{
	//Graphics object will create the game window and renderer (via constructor in grapics.cpp).
	Graphics grapics;
	
	//Declare an input object so we can use the input functions defined in input.cpp.
	Input input;

	//Holds whatever event happens during current frame.
	SDL_Event event;

	//Stores the number of milliseconds it has been since SDL_Init (not important until used in game loop below).
	int LAST_UPDATE_TIME = SDL_GetTicks();

	//Starts the game loop
	while (true)
	{
		//Clear inputs at the start of every new frame (pressed keys, released keys, etc.).
		input.beginNewFrame();
		
		//SDL_PollEvent polls to see if there are any current pending events (key press, exit, etc.).
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				//Makes sure this isn't a repeat key press.
				if (event.key.repeat == 0)
				{
					//If it isn't, call the keyDownEvent function to add key to the correct maps (_heldKeys/_pressedKeys).
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP)
				//Call the keyUpEvent to add key to the correct map (_releasedKeys).
				input.keyUpEvent(event);
			else if (event.type == SDL_QUIT)
				//Return if the X (close button) is pressed.
				return;
		}

		//If escape key is pressed, close the window.
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
			return;

		//Stores the time again since the SDL_Init so that we can calculate how long the loop took.
		const int CURRENT_TIME_MS = SDL_GetTicks();

		//Calculates how long the loop took.
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

		//Passes the smaller of the elapsed time of our loop and the MAX_FRAME_TIME to our update function.
		this->update(min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

		//Updates the last update time so that the next loop calculation is based on correct times.
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void Game::draw(Graphics &graphics)
{

}

void Game::update(float elapsedTime)
{

}

Game::~Game()
{

}