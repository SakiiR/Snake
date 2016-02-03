//
// Vector.cpp for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:08:37 2016 Erwan Dupard
// Last update Wed Feb  3 13:20:33 2016 Erwan Dupard
//

#include <iostream>
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

void		Vector::dump() const
{
  std::cout << "(" << this->getX() << ", " << this->getY() << ")" << std::endl;;
}

bool		operator==(const Vector &a, const Vector &b)
{
  return ((a.getX() == b.getX()) && (a.getY() == b.getY()));
}
