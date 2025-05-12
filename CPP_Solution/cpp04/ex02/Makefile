# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 10:48:35 by pchennia          #+#    #+#              #
#    Updated: 2024/10/15 12:53:28 by pchennia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  animals

COMPILER = c++
FLAGS = -Wall -Werror -Wextra -std=c++11

SRC = $(addsuffix .cpp, main AAnimal Dog Cat WrongCat WrongAnimal Brain)
OBJ = $(SRC:.cpp=.o)

GREEN=\033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all : $(NAME)

$(NAME) : $(OBJ)
		$(COMPILER) $(FLAGS) -o $@ $^
		@echo "$(GREEN) Created $(NAME) $(RESET)"

%o : %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean : 
		rm -rf $(OBJ)
		@echo "$(YELLOW) Removed object files $(RESET)"

fclean : clean
		rm -rf $(NAME)
		@echo "$(YELLOW) Removed $(NAME)$(RESET)"

re: fclean all

.PHONY : all clean fclean re
