NAME = minishell

LIBFT = ./libft/


CFLAGS = -Wall -Wextra -Werror  

CC = cc 


SOURCES =			./srcs/parsing/minishell.c \
					./srcs/parsing/ft_lexer.c \
					./srcs/parsing/ft_add_space.c \
					./srcs/parsing/ft_check.c \
					./srcs/parsing/ft_check_two.c \
					./srcs/parsing/ft_lst.c \
					./srcs/parsing/ft_list_two.c \
					./srcs/parsing/ft_env.c \
					./srcs/parsing/expanding.c \
					./srcs/parsing/ft_lst_three.c \
					./srcs/parsing/heredoc.c \
					./srcs/parsing/ft_help.c \
					./srcs/parsing/fd.c \
					./srcs/parsing/ft_free.c \
					./srcs/execution/builtin/builtin_utils.c\
					./srcs/execution/builtin/cd_cmd.c\
					./srcs/execution/builtin/echo_cmd.c\
					./srcs/execution/builtin/env_cmd.c\
					./srcs/execution/builtin/exit_cmd.c\
					./srcs/execution/builtin/export_cmd.c\
					./srcs/execution/builtin/pwd_cmd.c\
					./srcs/execution/builtin/unset_cmd.c\
					./srcs/execution/piping/execve_path.c\
					./srcs/execution/piping/main_execution.c\
					./srcs/execution/piping/pipe_fork.c\
					./srcs/execution/utils/ftt_aoi_l.c\
					./srcs/execution/utils/ftt_isalnum.c\
					./srcs/execution/utils/ftt_isdigit.c\
					./srcs/execution/utils/ftt_print_fd.c\
					./srcs/execution/utils/ftt_strdup.c\
					./srcs/execution/utils/ftt_strlen.c\
					./srcs/execution/utils/ftt_strtrim_space.c\
					./srcs/execution/utils/ftt_dup_ds.c\
					./srcs/execution/utils/ftt_isalpha.c\
					./srcs/execution/utils/ftt_isspace.c\
					./srcs/execution/utils/ftt_strchr.c\
					./srcs/execution/utils/ftt_strjoin.c\
					./srcs/execution/utils/ftt_strncmp.c\
					./srcs/execution/utils/ftt_substr.c \
					./srcs/execution/utils/ft_lstsize_s.c \
					./srcs/execution/utils/ftt_search.c \
					./srcs/execution/builtin/export_cmd2.c \
					./srcs/execution/builtin/export_cmd3.c \
					./srcs/execution/utils/get_content_env.c \

NC			= \033[0m
B_RED		= \033[1;31m
RED 		= \033[0;31m
PURPLE		= \033[0;35m
B_PURPLE	= \033[1;35m
BLUE	= \033[1;34m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m

READLINE = -lreadline -I/Users/${USER}/Desktop/readline/include/ -L /Users/${USER}/Desktop/readline -lcurses

OBJECTS = $(SOURCES:.c=.o)

BOBJECTS = $(BSOURCES:.c=.o)

all : $(NAME)

%.o: %.c
#	@echo "$(B_GREEN)Compiling: $(GREEN)$(notdir $<) 🔨$(NC)"
	@$(CC) $(FSANITIZE) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)█\033[0m\c"

$(NAME): compile $(OBJECTS) $(LIBFT)libft.a  done credit
	@$(CC) $(FSANITIZE) $(READLINE) $(OBJECTS) $(LIBFT)libft.a -o  $(NAME)
	@stty -echoctl

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
