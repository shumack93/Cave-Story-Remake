#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <map>

using std::map;

class Input
{
	private:
		//Holds all keys that are being held.
		map<SDL_Scancode, bool> _heldKeys;

		//Holds all keys that have been pressed/released in the current frame.
		map<SDL_Scancode, bool> _pressedKeys;
		map<SDL_Scancode, bool> _releasedKeys;

	public:
		//Called at the beginning of every new frame.
		void beginNewFrame();

		//Called when a key is released.
		void keyUpEvent(const SDL_Event& event);

		//Called when a key is pressed.
		void keyDownEvent(const SDL_Event& event);

		//Any key can be passed to these functions, and they will
		//return whether or not it has been pressed/released.
		bool wasKeyPressed(SDL_Scancode key);
		bool wasKeyReleased(SDL_Scancode key);

		//Any key can be passed to this function, and it will
		//return whether or not it is currently being held down.
		bool isKeyHeld(SDL_Scancode key);
};

#endif

