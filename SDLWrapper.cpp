//
// SDLWrapper.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 17:26:37 2016 Erwan Dupard
// Last update Tue Feb  2 18:03:38 2016 Erwan Dupard
//

#include "SDLWrapper.hh"

SDLWrapper::SDLWrapper()
{

  this->_window = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
      SDL_Rect	background;

      this->_window = SDL_CreateWindow(WINDOW_NAME, 100, 100, WINDOW_SIZE_X, WINDOW_SIZE_Y, SDL_WINDOW_SHOWN);
      this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
      SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);

      background.x = 0;
      background.y = 0;
      background.w = WINDOW_SIZE_X;
      background.h = WINDOW_SIZE_Y;
      
      SDL_RenderFillRect(this->_renderer, &background);
      SDL_RenderPresent(this->_renderer); 
    }
}

SDLWrapper::~SDLWrapper()
{
  SDL_DestroyWindow(this->_window);
  SDL_Quit();
}

int		SDLWrapper::MainLoop()
{
  SDL_Event	e;
  bool		quit = false;

  while (!quit)
    {
      while (SDL_PollEvent(&e))
	{
	  switch (e.type)
	    {
	    case SDL_KEYUP:
	      if (e.key.keysym.sym == SDLK_ESCAPE)
		quit = true;
	      break;
	    }
	}
    }
  return (0);
}