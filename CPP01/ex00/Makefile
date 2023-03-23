# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 16:53:33 by wricky-t          #+#    #+#              #
#    Updated: 2023/03/22 20:42:49 by wricky-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= BraiiiiiiinnnzzzZ
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98
SRCS		:= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS		:= $(SRCS:.cpp=.o)
INC			:= -I Zombie.hpp
RM			:= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

log: $(NAME)
	./$(NAME) > globalbanksters.log

.PHONY: all clean fclean re
