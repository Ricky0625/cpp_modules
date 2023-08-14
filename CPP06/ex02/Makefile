# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 16:53:33 by wricky-t          #+#    #+#              #
#    Updated: 2023/08/07 21:50:21 by wricky-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= identify
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD

ifeq ($(DEBUG), 1)
	CXXFLAGS += -fsanitize=address -g3
endif

SRCS_DIR	:= srcs
OBJS_DIR	:= objs
INC_DIR		:= includes
SRCS		:= $(wildcard $(SRCS_DIR)/*.cpp)
OBJS		:= $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)
INC			:= -I$(INC_DIR)
RM			:= rm -rf

BL			:= \033[1;34m
DF			:= \033[0m

all: $(NAME)

ifeq ($(DEBUG), 1)
	@echo "$(BL)DEBUG MODE$(DF)"
endif

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) $^ -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re env debug
