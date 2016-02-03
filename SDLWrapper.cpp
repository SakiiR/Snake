//
// SDLWrapper.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 17:26:37 2016 Erwan Dupard
// Last update Wed Feb  3 03:00:31 2016 Erwan Dupard
//

#include "SDLWrapper.hh"

SDLWrapper::SDLWrapper()
{

  this->_window = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
      this->_window = SDL_CreateWindow(WINDOW_NAME, 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
      this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
      this->_cleanScreen();
    }
}

SDLWrapper::~SDLWrapper()
{
  SDL_DestroyWindow(this->_window);
  SDL_Quit();
}

void		SDLWrapper::_cleanScreen() const
{
  SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);
  SDL_RenderClear(this->_renderer); // fill the scene with white
}

int		SDLWrapper::MainLoop()
{
  SDL_Event	e;
  bool		quit = false;
  Nibbler	nibbler;

  while (!quit)
    {
      while (SDL_PollEvent(&e))
	{
	  switch (e.type)
	    {
	    case SDL_KEYUP:
	      if (e.key.keysym.sym == SDLK_ESCAPE)
		quit = true;
	      if (e.key.keysym.sym == SDLK_LEFT)
		nibbler.changeDirection(Nibbler::LEFT);
	      if (e.key.keysym.sym == SDLK_RIGHT)
		nibbler.changeDirection(Nibbler::RIGHT);
	      if (e.key.keysym.sym == SDLK_UP)
		nibbler.changeDirection(Nibbler::UP);
	      if (e.key.keysym.sym == SDLK_DOWN)
		nibbler.changeDirection(Nibbler::DOWN);
	      break;
	    case SDL_QUIT:
	      quit = true;
	      break;
	    }
	}
      nibbler.updateNibbler();
      this->drawNibbler(nibbler);
      SDL_Delay(REFRESH_TIME);
      this->_cleanScreen();
    }
  return (0);
}

void		SDLWrapper::drawNibbler(const Nibbler &nib)
{
  std::list<Vector *>::const_iterator it = nib.getNibbles().begin();

  while(it != nib.getNibbles().end())
    {
      this->_drawRect((*it)->getX(), (*it)->getY());
      it++;
    }
}

void		SDLWrapper::_drawRect(int x, int y) const
{
  SDL_Rect rect;
  
  SDL_SetRenderDrawColor(this->_renderer, 153, 102, 153, 0);
  rect.x = x * UNIT_SIZE;
  rect.y = y * UNIT_SIZE;
  rect.w = UNIT_SIZE;
  rect.h = UNIT_SIZE;
  SDL_RenderFillRect(this->_renderer, &rect);
  SDL_RenderPresent(this->_renderer);
}
