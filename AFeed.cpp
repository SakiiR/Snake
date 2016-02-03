//
// AFeed.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:14:15 2016 Erwan Dupard
// Last update Wed Feb  3 12:12:45 2016 Erwan Dupard
//

#include "AFeed.hh"

AFeed::AFeed(int power) : _power(power)
{
  std::cout << "Popping Feed!" << std::endl;
  this->_position = new Vector(std::rand() % GAME_WIDTH, std::rand() % GAME_HEIGHT);
}

AFeed::~AFeed()
{
  std::cout << "Unpop Feed!" << std::endl;
}

int		AFeed::getPower() const
{
  return (this->_power);
}

void		AFeed::regenPosition() const
{
  this->_position->setX(std::rand() % GAME_WIDTH);
  this->_position->setY(std::rand() % GAME_HEIGHT);
}

int		AFeed::getPositionX() const
{
  return (this->_position->getX());
}

int		AFeed::getPositionY() const
{
  return (this->_position->getY());
}

const Vector	&AFeed::getPosition() const
{
  return (*this->_position);
}
