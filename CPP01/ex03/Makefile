# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 16:53:33 by wricky-t          #+#    #+#              #
#    Updated: 2023/03/24 14:14:09 by wricky-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= unnecessary_violence
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98
SRCS		:= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS		:= $(SRCS:.cpp=.o)
INC			:= -I HumanA.hpp -I HumanB.hpp -I Weapon.hpp
RM			:= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
