# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 14:58:20 by pchennia          #+#    #+#              #
#    Updated: 2024/09/16 13:17:17 by pchennia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondTrap

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = $(addsuffix .cpp, main ClapTrap ScavTrap FragTrap DiamondTrap)
OBJS = $(SRCS:.cpp=.o)

GREEN=\033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all : $(NAME)

$(NAME): $(OBJS)
		$(COMPILER) $(FLAGS) -o $@ $^
		@echo "$(GREEN)Created $(NAME)$(RESET)"

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJS)
	@echo "$(YELLOW)Removed object files$(RESET)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(YELLOW)Removed $(NAME)$(RESET)"

re : fclean all

.PHONY: all clean fclean re