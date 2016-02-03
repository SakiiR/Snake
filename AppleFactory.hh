//
// AppleFactory.hh for Nibbler in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Feb  3 11:44:15 2016 Erwan Dupard
// Last update Wed Feb  3 12:00:48 2016 Erwan Dupard
//

#ifndef APPLEFACTORY_HH_
# define APPLEFACTORY_HH_

# include <map>
# include "Apple.hh"
# include "IFeedFactory.hh"

class		AppleFactory : public IFeedFactory
{
public:
  Apple		*create() const;
};

#endif /* ! APPLEFACTORY_HH_ */
