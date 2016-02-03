//
// IFeedFactory.hh for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Feb  3 11:42:52 2016 Erwan Dupard
// Last update Wed Feb  3 12:07:11 2016 Erwan Dupard
//

#ifndef IFEEDFACTORY_HH_
# define IFEEDFACTORY_HH_

# include <vector>

class		IFeedFactory
{
public:
  virtual AFeed	*create() const = 0;
};

typedef std::vector<IFeedFactory *> FeedFactories;

#endif /* ! IFEEDFACTORY_HH_ */
