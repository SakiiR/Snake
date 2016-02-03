//
// Nibbler.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:05:49 2016 Erwan Dupard
// Last update Thu Feb  4 00:05:35 2016 Erwan Dupard
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
  std::vector<Vector *>::iterator	it = this->_nibbler.begin();

  while (it != this->_nibbler.end())
    {
      delete (*it);
      it++;
    }
}

void					Nibbler::dump() const
{
  std::vector<Vector *>::const_iterator		it = this->_nibbler.begin();

  std::cout << "Updating Nib the nibbler !" << std::endl;
  std::cout << "Head : " << std::endl;
  std::cout << "\t x : " << this->getHead().getX() << std::endl;
  std::cout << "\t y : " << this->getHead().getY() << std::endl << std::endl;
  while (it != this->_nibbler.end())
    {
      std::cout << "(" << (*it)->getX() << ", " << (*it)->getY() << ") ";
      it++;
    }
  std::cout << std::endl;
}

void					Nibbler::updateNibbler()
{
  Vector				old;
  Vector				tmp;
  size_t				i = 1;

  old = *this->_nibbler[0];
  switch (this->getDirection())
    {
    case RIGHT:
      this->_goRight(*this->_nibbler[0]);
      break;
    case LEFT:
      this->_goLeft(*this->_nibbler[0]);
      break;
    case DOWN:
      this->_goDown(*this->_nibbler[0]);
      break;
    case UP:
      this->_goUp(*this->_nibbler[0]);
      break;
    }
  while (i < this->_nibbler.size())
    {
      tmp = *this->_nibbler[i];
      this->_nibbler[i]->setX(old.getX());
      this->_nibbler[i]->setY(old.getY());
      old = tmp;
      ++i;
    }
  if (this->_queuedNibbles > 0)
    {
      this->_nibbler.push_back(new Vector(old.getX(), old.getY()));
      this->_queuedNibbles--;
    }
  if (this->_checkHead())
    {
      std::cout << "[-] You Lost with score " << this->_nibbler.size() << std::endl;
      //game over
    }
}

int					Nibbler::_checkHead() const
{
  const Vector				&head = this->getHead();
  size_t				i = 1;

  while (i < this->_nibbler.size())
    {
      if (head == *this->_nibbler[i])
	return (1);
      ++i;
    }
  return (0);
}

void					Nibbler::changeLength(int n)
{
  int					i;
  
  i = 0;
  while (i < ABS(n))
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
  return (*(this->_nibbler[0]));
}

void					Nibbler::_goRight(Vector &nibble)
{
  nibble.setX(nibble.getX() + 1);
  if (nibble.getX() > GAME_WIDTH)
    nibble.setX(0);
}

void					Nibbler::_goLeft(Vector &nibble)
{
  nibble.setX(nibble.getX() - 1);
  if (nibble.getX() < 0)
    nibble.setX(GAME_WIDTH);
}

void					Nibbler::_goUp(Vector &nibble)
{
  nibble.setY(nibble.getY() - 1);
  if (nibble.getY() < 0)
    nibble.setY(GAME_HEIGHT);
}

void					Nibbler::_goDown(Vector &nibble)
{
  nibble.setY(nibble.getY() + 1);
  if (nibble.getY() > GAME_HEIGHT)
    nibble.setY(0);
}

bool					Nibbler::isDead() const
{
  return (this->_dead);
}

const std::vector<Vector *>		&Nibbler::getNibbles() const
{
  return (this->_nibbler);
}

void					Nibbler::eatFeed(AFeed *feed)
{
  this->changeLength(feed->getPower());
  feed->regenPosition();
}
