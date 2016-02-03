//
// main.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 17:34:24 2016 Erwan Dupard
// Last update Wed Feb  3 11:26:33 2016 Erwan Dupard
//

#include <cstdlib>
#include <ctime>
#include "SDLWrapper.hh"

int		main()
{
  SDLWrapper	sdl;

  std::srand(std::time(0));
  sdl.MainLoop();
  return (0);
}
