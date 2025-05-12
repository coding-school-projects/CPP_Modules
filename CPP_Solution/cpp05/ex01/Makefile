# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 15:12:09 by pchennia          #+#    #+#              #
#    Updated: 2024/11/29 10:05:42 by pchennia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := form
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp Bureaucrat.cpp Form.cpp
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
	rm -rf $(OBJS)
	@echo "$(YELLOW)Removed Object files$(RESET)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(YELLOW)Removed $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
