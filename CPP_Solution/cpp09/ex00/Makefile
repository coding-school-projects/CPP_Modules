# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 12:14:56 by pchennia          #+#    #+#              #
#    Updated: 2025/03/20 12:18:56 by pchennia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := btc
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp BitcoinExchange.cpp
OBJS := $(SRCS:.cpp=.o)

RM = rm -rf

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
	$(RM) $(OBJS)
	@echo "$(YELLOW)Removed Object files$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(YELLOW)Removed $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re