//
// Nibbler.hh for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:04:32 2016 Erwan Dupard
// Last update Wed Feb  3 01:26:37 2016 Erwan Dupard
//

#ifndef NIBBLER_HH_
# define NIBBLER_HH_

# include <list>
# include "Vector.hh"
# include "SDLWrapper.hh"

# define ABS(c) ((c >= 0 ? c : -c))

class			Nibbler
{
public:
  enum Direction
    {
      LEFT,
      RIGHT,
      UP,
      DOWN
    };
  Nibbler();
  ~Nibbler();
  void			updateNibbler();
  void			changeLength(int);
  const Vector		&getHead() const;
  void			changeDirection(Direction);
  Direction		getDirection() const;
private:
  std::list<Vector *>	_nibbler;
  Direction		_direction;
  void			_delNibble();
  void			_addQueuedNibble();
  int			_queuedNibbles;
};

#endif /* ! NIBBLER_HH_ */
