//
// KoalaFactory.hh for KoalaFactory.hh in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Thu Feb  4 00:18:04 2016 Erwan Dupard
// Last update Thu Feb  4 00:19:16 2016 Erwan Dupard
//

#ifndef KOALAFACTORY_HH_
# define KOALAFACTORY_HH_

# include "Koala.hh"
# include "IFeedFactory.hh"

class		KoalaFactory : public IFeedFactory
{
public:
  Koala		*create() const;
};

#endif /* ! KOALAFACTORY_HH_ */
