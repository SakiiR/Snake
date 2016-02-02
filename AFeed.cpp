//
// AFeed.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:14:15 2016 Erwan Dupard
// Last update Tue Feb  2 18:16:08 2016 Erwan Dupard
//

#include "AFeed.hh"

AFeed::AFeed(int power) : _power(power)
{
  std::cout << "Popping Feed!" << std::endl;
}

AFeed::~AFeed()
{
  std::cout << "Unpop Feed!" << std::endl;
}

int		AFeed::getPower() const
{
  return (this->_power);
}
