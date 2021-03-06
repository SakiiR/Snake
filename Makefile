##
## Makefile for Nibbler in /home/dupard_e/rendus/Nibbler
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Tue Feb  2 17:25:34 2016 Erwan Dupard
## Last update Thu Feb  4 00:17:35 2016 Erwan Dupard
##

CC		= g++

RM 		= rm -f

CXXFLAGS 	+= -Werror -Wall -Wextra

LDXXFLAGS	+= -lSDL2

SRCS		= SDLWrapper.cpp	\
		  main.cpp		\
		  Nibbler.cpp		\
		  Vector.cpp		\
		  AFeed.cpp		\
		  Apple.cpp		\
		  AppleFactory.cpp	\
		  Koala.cpp		\
		  KoalaFactory.cpp	\


OBJS		= $(SRCS:.cpp=.o)

NAME		= Nibbler

all: 		$(NAME)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CXXLAGS) $(LDXXFLAGS)

clean : 
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean  all

.PHONY: 	clean fclean all re
