//
// Koala.cpp for Koala in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Thu Feb  4 00:21:03 2016 Erwan Dupard
// Last update Thu Feb  4 00:25:48 2016 Erwan Dupard
//

#include "Koala.hh"

Koala::Koala() : AFeed(100, 200, 200, 200)
{
  std::cout << "Spawning Koala !" << std::endl;
}

Koala::~Koala()
{}

