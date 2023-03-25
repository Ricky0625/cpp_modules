# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 16:53:33 by wricky-t          #+#    #+#              #
#    Updated: 2023/03/25 15:21:38 by wricky-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= harl2.0
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98
SRCS		:= main.cpp Harl.cpp
OBJS		:= $(SRCS:.cpp=.o)
INC			:= -I Harl.hpp
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
