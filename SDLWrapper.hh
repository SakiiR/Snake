//
// SDLWrapper.hh for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 17:26:01 2016 Erwan Dupard
// Last update Wed Feb  3 02:31:32 2016 Erwan Dupard
//

#ifndef SDLWRAPPER_HH_
# define SDLWRAPPER_HH_

# include <SDL2/SDL.h>
# include "Nibbler.hh"
# include "ressources.hh"

class		SDLWrapper
{
public:
  SDLWrapper();
  ~SDLWrapper();
  SDL_Window	*getWindow() const;
  int		MainLoop();
  void		drawNibbler(const Nibbler &nib);
private:
  SDL_Window	*_window;
  SDL_Renderer	*_renderer;
  void		_drawRect(int x, int y) const;
  void		_cleanScreen() const;
};

#endif /* ! SDLWRAPPER_HH_ */
