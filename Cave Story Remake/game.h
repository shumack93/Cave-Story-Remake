#ifndef GAME_H
#define GAME_H

class Graphics;

class Game
{
	private:
		//Contains the loop that will run the game.
		void gameLoop();

		void draw(Graphics &graphics);
		void update(float elapsedTime);

	public:
		//Constructor will initialize everything via SDL_INIT_EVERYTHING.
		Game();
		~Game();
};

#endif