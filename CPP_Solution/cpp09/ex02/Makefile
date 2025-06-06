NAME		=	PmergeMe

CC			=	c++
CCFLAGS		=	-Wall -Wextra -Werror -std=c++11
SRCS		=	main.cpp PmergeMe.cpp
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

test: $(NAME)
	@echo "$(BLUE)Running tests... $(RESET)"
	@echo "Test 1 $(GREEN) A range of 5 elements $(RESET)"
	@./$(NAME) 3 5 9 7 4
	@echo "--------------------------------------------"
	@echo "Test 2 $(GREEN)(LINUX) A range of 3000 elements $(RESET)"
	-@./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`
	@echo "--------------------------------------------"
	@echo "Test 3 $(GREEN) Error $(RESET)"
	-@./$(NAME) "-1" "2"
	@echo "--------------------------------------------"
	@echo "Test 4 $(GREEN) Error $(RESET)"
	-@./$(NAME) 1 2 3 4 5 6
	@echo "--------------------------------------------"
	@echo "Test 5 $(GREEN) Error $(RESET)"
	@./$(NAME) 3 5 j 7 4
	@echo "--------------------------------------------"
	@echo "Test 6 $(GREEN) Error $(RESET)"
	@./$(NAME) 3 -5 9 7 4 6
	@echo "--------------------------------------------"
	@echo "Test 7 $(GREEN) Error $(RESET)"
	@./$(NAME) 3 5 5 9 7 4 6
	@echo "--------------------------------------------"
	@echo "Test 8 $(GREEN) Error $(RESET)"
	@./$(NAME) 3
	@echo "--------------------------------------------"


.PHONY: all clean fclean re test

GREEN = \033[0;32m
RESET = \033[0m
BLUE = \033[34m