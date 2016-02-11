#include <stdlib.h>
#include <SDL2/SDL.h>
#define GL3_PROTOTYPES 1
#include <GLES3/gl3.h>

int	main(int ac, char **av)
{
	SDL_Window		*window = 0;
	SDL_Event		ev;
	SDL_GLContext 	gl;
	int				end = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Unable to start SDL: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (!window)
	{
		printf("Unable to create the window: %s\n", SDL_GetError());
		SDL_Quit();
		return (2);
	}
	gl = SDL_GL_CreateContext(window);
	if (gl == 0)
	{
		printf("Cannot open an openGL context: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (3);
	}
	while (!end) {
		SDL_WaitEvent(&ev);
		if (ev.type == SDL_QUIT)
			end = 1;
	}
	SDL_GL_DeleteContext(gl);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}