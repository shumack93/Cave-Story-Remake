#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

//Graphics class only contains window and renderer member variables, and a constructor/destructor.
class Graphics
{
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;

	public:
		Graphics();
		~Graphics();
};

#endif