//
// SDLWrapper.hh for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 17:26:01 2016 Erwan Dupard
// Last update Tue Feb  2 17:55:26 2016 Erwan Dupard
//

#ifndef SDLWRAPPER_HH_
# define SDLWRAPPER_HH_

# include <SDL2/SDL.h>

# define WINDOW_SIZE_X			(800)
# define WINDOW_SIZE_Y			(640)

# define WINDOW_NAME			("SakiiR's Nibbler ! SuckZ my C4T !")

class		SDLWrapper
{
public:
  SDLWrapper();
  ~SDLWrapper();
  SDL_Window	*getWindow() const;
  int		MainLoop();
private:
  SDL_Window	*_window;
  SDL_Renderer	*_renderer;
};

#endif /* ! SDLWRAPPER_HH_ */
