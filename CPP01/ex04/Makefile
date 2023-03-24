# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 16:53:33 by wricky-t          #+#    #+#              #
#    Updated: 2023/03/24 20:24:08 by wricky-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= sed_is_for_losers
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
SRCS		:= main.cpp
OBJS		:= $(SRCS:.cpp=.o)
INC			:= 
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
