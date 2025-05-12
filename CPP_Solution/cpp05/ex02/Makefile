# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 16:43:11 by pchennia          #+#    #+#              #
#    Updated: 2024/11/29 11:17:50 by pchennia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := forms
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS := $(SRCS:.cpp=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)Created $(NAME)$(RESET)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJS) *_shrubbery
	@echo "$(YELLOW)Removed Object files and <target>_shrubbery$(RESET)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(YELLOW)Removed $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
