//
// Vector.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:08:37 2016 Erwan Dupard
// Last update Wed Feb  3 01:56:07 2016 Erwan Dupard
//

#include "Vector.hh"

Vector::Vector(int x, int y) : _x(x), _y(y)
{}

Vector::~Vector()
{}

Vector::Vector(const Vector &other) : _x(other.getX()), _y(other.getY())
{}

Vector		&Vector::operator=(const Vector &other)
{
  if (this != &other)
    {
      this->setX(other.getX());
      this->setY(other.getY());
    }
  return (*this);
}

bool		Vector::operator==(const Vector &other)
{
  return (
	  (this->getX() == other.getX()) && 
	  (this->getY() == other.getY())
	  );
}

int		Vector::getX() const
{
  return (this->_x);
}

int		Vector::getY() const
{
  return (this->_y);
}

void		Vector::setX(int x)
{
  this->_x = x;
}

void		Vector::setY(int y)
{
  this->_y = y;
}
