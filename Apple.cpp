//
// Apple.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:19:09 2016 Erwan Dupard
// Last update Thu Feb  4 00:25:32 2016 Erwan Dupard
//

#include "Apple.hh"

Apple::Apple() : AFeed(1, 0, 255, 0)
{
  std::cout << "Spawning Apple !" << std::endl;
}

Apple::~Apple()
{}

