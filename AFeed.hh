//
// Feed.hh for Feed in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:11:21 2016 Erwan Dupard
// Last update Thu Feb  4 00:13:42 2016 Erwan Dupard
//

#ifndef FEED_HH_
# define FEED_HH_

# include <cstdlib>
# include "ressources.hh"
# include "Vector.hh"

class		AFeed
{
public:
  AFeed(int power, int r, int g, int b);
  ~AFeed();
  int		getPower() const;
  void		regenPosition() const;
  int		getPositionX() const;
  int		getPositionY() const;
  int		getR() const;
  int		getG() const;
  int		getB() const;
  const Vector	&getPosition() const;
private:
  int		_power;
  Vector	*_position;
  int		_r;
  int		_g;
  int		_b;
};

#endif /* ! FEED_HH_ */
