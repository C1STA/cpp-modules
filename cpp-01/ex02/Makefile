RED			= \033[1;31m
GREEN		= \033[1;32m
BLUE		= \033[1;34m
CYAN		= \033[1;36m
WHITE		= \033[0;37m

NAME		= reference
CC			= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp
RM			= rm -rf

all : $(NAME)

OBJDIR	= .config/obj/
OBJ			= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

$(OBJDIR)%.o: %.cpp
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling$(WHITE) $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(CYAN)Linking$(WHITE) $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Done$(WHITE)"

clean :
	@echo "$(RED)Cleaning$(WHITE) $(NAME)..."
	@$(RM) .config
	@echo "$(GREEN)Done$(WHITE)"

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re