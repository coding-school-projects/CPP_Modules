NAME		=	btc

CC			=	c++
CCFLAGS		=	-Wall -Wextra -Werror -std=c++11
SRCS		=	main.cpp BitcoinExchange.cpp Utils.cpp
OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

%.o : %.cpp
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $< $(RESET)"

$(NAME): $(OBJS)
	@echo "--------------------------------------------"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "[$(NAME)] $(BLUE)Built target $(NAME)$(RESET)"
	@echo "--------------------------------------------"

clean:
	@rm -rf $(OBJS)
	@echo "[$(NAME)] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[$(NAME)] Everything deleted."

re: fclean all
	@echo "[$(NAME)] Everything rebuilt."

.PHONY: all clean fclean re

GREEN = \033[0;32m
RESET = \033[0m
BLUE = \033[34m