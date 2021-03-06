//
// Vector.hh for Vector in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:06:36 2016 Erwan Dupard
// Last update Wed Feb  3 13:19:29 2016 Erwan Dupard
//

#ifndef VECTOR_HH_
# define VECTOR_HH_

class		Vector
{
public:
  Vector(int x = 0, int y = 0);
  ~Vector();
  Vector(const Vector &);

  Vector	&operator=(const Vector &);
  int		getX() const;
  int		getY() const;
  void		setX(int);
  void		setY(int);
  void		dump() const;
private:
  int		_x;
  int		_y;
};

bool		operator==(const Vector &, const Vector &);


#endif /* ! VECTOR_HH_ */
