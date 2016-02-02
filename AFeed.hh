//
// Feed.hh for Feed in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Feb  2 18:11:21 2016 Erwan Dupard
// Last update Tue Feb  2 18:16:49 2016 Erwan Dupard
//

#ifndef FEED_HH_
# define FEED_HH_

# include <iostream>

# include "Vector.hh"

class		AFeed
{
public:
  AFeed(int power);
  ~AFeed();
  int		getPower() const;
private:
  int		_power;
  Vector	*_position;
};

#endif /* ! FEED_HH_ */
