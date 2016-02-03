//
// AppleFactory.cpp for AppleFactory.cpp in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Feb  3 11:45:29 2016 Erwan Dupard
// Last update Wed Feb  3 11:45:55 2016 Erwan Dupard
//

#include "AppleFactory.hh"

Apple		*AppleFactory::create() const
{
  return (new Apple());
}
