//
// Vector.hh for Vector in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:06:36 2016 Erwan Dupard
// Last update Tue Feb  2 18:09:39 2016 Erwan Dupard
//

#ifndef VECTOR_HH_
# define VECTOR_HH_

class		Vector
{
public:
  Vector(int x = 0, int y = 0);
  ~Vector();
  int		getX() const;
  int		getY() const;
  void		setX(int);
  void		setY(int);
private:
  int		_x;
  int		_y;
};

#endif /* ! VECTOR_HH_ */
