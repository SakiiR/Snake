//
// Nibbler.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:05:49 2016 Erwan Dupard
// Last update Wed Feb  3 01:29:18 2016 Erwan Dupard
//

#include "Nibbler.hh"

Nibbler::Nibbler() : _direction(RIGHT), _queuedNibbles(0)
{
  this->_nibbler.push_back(new Vector(GAME_WIDTH / 2 - 1, GAME_HEIGHT / 2));
  this->_nibbler.push_back(new Vector(GAME_WIDTH / 2, GAME_HEIGHT / 2));
  this->_nibbler.push_back(new Vector(GAME_WIDTH / 2 + 1, GAME_HEIGHT / 2));
}

Nibbler::~Nibbler()
{
  std::list<Vector *>::iterator		it = this->_nibbler.begin();

  while (it != this->_nibbler.end())
    {
      delete (*it);
      it++;
    }
}

void					Nibbler::updateNibbler()
{
  
}

void					Nibbler::changeLength(int n)
{
  int		i;
  
  i = -1;
  while (++i < ABS(n)) // maybe bug here
    {
      if (n < 0)
	this->_delNibble();
      else
	this->_queuedNibbles++;
    }
}

Nibbler::Direction			Nibbler::getDirection() const
{
  return (this->_direction);
}

void					Nibbler::changeDirection(Nibbler::Direction direction)
{
  this->_direction = direction;
}

void					Nibbler::_delNibble()
{
  this->_nibbler.pop_back();
}

const Vector				&Nibbler::getHead() const
{
  return (**(this->_nibbler.begin()));
}

