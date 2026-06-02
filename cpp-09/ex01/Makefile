RED			= \033[1;31m
GREEN		= \033[1;32m
BLUE		= \033[1;34m
CYAN		= \033[1;36m
WHITE		= \033[0;37m

NAME		= RPN
CXX			= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
INC			= -I inc/
SRCPATH = src/
SRC			= main.cpp RPN.cpp
RM			= rm -rf

OBJDIR	= .config/obj/
OBJ			= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

DEPDIR	= .config/dep/
DEP			= $(addprefix $(DEPDIR), $(SRC:.cpp=.d))

all : $(NAME)

$(OBJDIR)%.o: $(SRCPATH)%.cpp
	@mkdir -p $(@D) $(DEPDIR)
	@printf "$(BLUE)Compiling$(WHITE) $<...\n"
	@$(CXX) $(CXXFLAGS) $(INC) -MMD -MP -MF $(DEPDIR)$*.d -c $< -o $@

$(NAME): $(OBJ)
	@printf "$(CYAN)Linking$(WHITE) $(NAME)...\n"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)Done$(WHITE)\n"

-include $(DEP)

clean :
	@printf "$(RED)Cleaning$(WHITE) $(NAME)...\n"
	@$(RM) .config
	@printf "$(GREEN)Done$(WHITE)\n"

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re