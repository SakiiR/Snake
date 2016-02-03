//
// Nibbler.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:05:49 2016 Erwan Dupard
// Last update Wed Feb  3 12:22:10 2016 Erwan Dupard
//

#include "Nibbler.hh"

Nibbler::Nibbler() : _direction(RIGHT), _queuedNibbles(0), _dead(false)
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

void					Nibbler::dump() const
{
  std::cout << "Updating Nib the nibbler !" << std::endl;
  std::cout << "Head : " << std::endl;
  std::cout << "\t x : " << this->getHead().getX() << std::endl;
  std::cout << "\t y : " << this->getHead().getY() << std::endl << std::endl;
}

void					Nibbler::updateNibbler()
{
  std::list<Vector *>::iterator		it = this->_nibbler.begin();
  Vector				*old = new Vector(**it);

  if (this->getDirection() == RIGHT)
    this->_goRight(*it);
  else if (this->getDirection() == LEFT)
    this->_goLeft(*it);
  else if (this->getDirection() == UP)
    this->_goUp(*it);
  else if (this->getDirection() == DOWN)
    this->_goDown(*it);
  it++;
  while (it != this->_nibbler.end())
    {
      (*it)->setX(old->getX());
      (*it)->setY(old->getY());
      *old = **it;
      it++;
    }
  if (this->_queuedNibbles > 0)
    {
      this->_nibbler.push_back(new Vector(*old));
      this->_queuedNibbles--;
    }
  std::cout << "SCORE : " << this->_nibbler.size() << std::endl;
}

void					Nibbler::changeLength(int n)
{
  int					i;
  
  i = 0;
  while (i < ABS(n)) // maybe bug here
    {
      if (n < 0)
	this->_delNibble();
      else if (n > 0)
	this->_queuedNibbles++;
      ++i;
    }
}

Nibbler::Direction			Nibbler::getDirection() const
{
  return (this->_direction);
}

void					Nibbler::changeDirection(Nibbler::Direction direction)
{
  if (
      !(this->getDirection() == RIGHT && direction == LEFT) &&
      !(this->getDirection() == LEFT && direction == RIGHT) &&
      !(this->getDirection() == DOWN && direction == UP) &&
      !(this->getDirection() == UP && direction == DOWN)
      )
    {
      this->_direction = direction;
    }
}

void					Nibbler::_delNibble()
{
  this->_nibbler.pop_back();
}

const Vector				&Nibbler::getHead() const
{
  return (**(this->_nibbler.begin()));
}

void					Nibbler::_goRight(Vector *nibble)
{
  nibble->setX(nibble->getX() + 1);
  if (nibble->getX() > GAME_WIDTH)
    nibble->setX(0);
}

void					Nibbler::_goLeft(Vector *nibble)
{
  nibble->setX(nibble->getX() - 1);
  if (nibble->getX() < 0)
    nibble->setX(GAME_WIDTH);
}

void					Nibbler::_goUp(Vector *nibble)
{
  nibble->setY(nibble->getY() - 1);
  if (nibble->getY() < 0)
    nibble->setY(GAME_HEIGHT);
}

void					Nibbler::_goDown(Vector *nibble)
{
  nibble->setY(nibble->getY() + 1);
  if (nibble->getY() > GAME_HEIGHT)
    nibble->setY(0);
}

bool					Nibbler::isDead() const
{
  return (this->_dead);
}

const std::list<Vector *>		&Nibbler::getNibbles() const
{
  return (this->_nibbler);
}

void					Nibbler::eatFeed(AFeed *feed)
{
  this->changeLength(feed->getPower());
  feed->regenPosition();
}
