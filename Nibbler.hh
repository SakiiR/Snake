//
// Nibbler.hh for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:04:32 2016 Erwan Dupard
// Last update Thu Feb  4 00:39:34 2016 Erwan Dupard
//

#ifndef NIBBLER_HH_
# define NIBBLER_HH_

# include <vector>
# include "AFeed.hh"
# include "Vector.hh"
# include "ressources.hh"

# define ABS(c) ((c >= 0 ? c : -c))

class				Nibbler
{
public:
  enum				Direction
    {
      LEFT,
      RIGHT,
      UP,
      DOWN
    };
  Nibbler();
  ~Nibbler();
  int				updateNibbler();
  void				changeLength(int);
  const Vector			&getHead() const;
  void				changeDirection(Direction);
  Direction			getDirection() const;
  bool				isDead() const;
  const std::vector<Vector *>	&getNibbles() const;
  void				dump() const;
  void				eatFeed(AFeed *);

private:
  int				_checkHead() const;
  void				_delNibble();
  void				_addQueuedNibble();
  void				_goRight(Vector &);
  void				_goLeft(Vector &);
  void				_goUp(Vector &);
  void				_goDown(Vector &);
  std::vector<Vector *>		_nibbler;
  Direction			_direction;
  int				_queuedNibbles;
  bool				_dead;
};

#endif /* ! NIBBLER_HH_ */
