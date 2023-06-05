NAME = Minishell

LIBFT = ./libft/


CFLAGS = -Wall -Wextra -Werror

CC = cc

#FSANITIZE = -fsanitize=address -g

SOURCES =			./srcs/minishell.c \
					./srcs/ft_lexer.c \
					./srcs/ft_add_space.c \
					./srcs/ft_check.c \
					./srcs/ft_check_two.c \
					./srcs/ft_lst.c \
					./srcs/ft_list_two.c \
					./srcs/ft_env.c \
					./srcs/expanding.c \
					./srcs/ft_lst_three.c


NC			= \033[0m
B_RED		= \033[1;31m
RED 		= \033[0;31m
PURPLE		= \033[0;35m
B_PURPLE	= \033[1;35m
BLUE	= \033[1;34m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m

READLINE = -lreadline

OBJECTS = $(SOURCES:.c=.o)

BOBJECTS = $(BSOURCES:.c=.o)

all : $(NAME)

%.o: %.c
#	@echo "$(B_GREEN)Compiling: $(GREEN)$(notdir $<) 🔨$(NC)"
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)█\033[0m\c"

$(NAME): compile $(OBJECTS) $(LIBFT)libft.a  done credit
	@$(CC)  $(READLINE) $(OBJECTS)  $(LIBFT)libft.a -o  $(NAME)

$(LIBFT)libft.a :
	@make bonus -C $(LIBFT)

clean :
	@rm -f $(OBJECTS)
	@rm -f $(BOBJECTS)
	@echo "\033[0;33m•\033[0;33m\c"
	@echo "$(B_RED)🧹 Cleaning: $(RED) Minishell object files $(NC)"
	@make clean -C $(LIBFT)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BNAME)
	@echo "\033[0;33m••\033[0;33m\c"
	@echo "$(B_RED)🧹 Cleaning: $(RED) $(NAME) $(NC)"
	@make fclean -C $(LIBFT)

re : fclean all

compile	:
			@echo "\n$(YELLOW)[X] Compiling $(GREEN)Minishell$(NC)\n"

done	:
			@echo "$(GREEN) => 100%$(NC)\n"

credit:
	@echo "$(GREEN)███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
	@echo "$(GREEN)████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
	@echo "$(GREEN)██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
	@echo "$(GREEN)██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
	@echo "$(GREEN)██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
	@echo "$(GREEN)╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝$(NC)"
