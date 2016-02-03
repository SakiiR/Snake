//
// KoalaFactory.cpp for Koala in /home/dupard_e/rendus/Nibbler
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Thu Feb  4 00:19:34 2016 Erwan Dupard
// Last update Thu Feb  4 00:22:16 2016 Erwan Dupard
//

#include "KoalaFactory.hh"

Koala		*KoalaFactory::create() const
{
  return (new Koala());
}
