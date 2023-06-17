NAME = Minishell

LIBFT = ./libft/


CFLAGS = -Wall -Wextra -Werror

CC = cc

FSANITIZE = -fsanitize=address -g

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
					./srcs/execution/builtin/builtin_utils.c\
					./srcs/execution/builtin/cd_cmd.c\
					./srcs/execution/builtin/echo_cmd.c\
					./srcs/execution/builtin/env_cmd.c\
					./srcs/execution/builtin/exit_cmd.c\
					./srcs/execution/builtin/export_cmd.c\
					./srcs/execution/builtin/pwd_cmd.c\
					./srcs/execution/builtin/unset_cmd.c\
					./srcs/execution/env/change_content.c\
					./srcs/execution/env/count_env.c\
					./srcs/execution/env/env_compatible.c\
					./srcs/execution/env/export_var_env.c\
					./srcs/execution/env/get_content_env.c\
					./srcs/execution/env/get_indice_env.c\
					./srcs/execution/env/print_env.c\
					./srcs/execution/env/print_err_env.c\
					./srcs/execution/env/realloc_var_env.c\
					./srcs/execution/env/set_env_var.c\
					./srcs/execution/env/unset_var_env.c\
					./srcs/execution/env/utils_env.c\
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
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)█\033[0m\c"

$(NAME): compile $(OBJECTS) $(LIBFT)libft.a  done credit
	@$(CC) $(READLINE) $(OBJECTS)  $(LIBFT)libft.a -o  $(NAME)

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
