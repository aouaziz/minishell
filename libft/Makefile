NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SOURCES = 			./srcs/ft_isalpha.c \
					./srcs/ft_isdigit.c \
					./srcs/ft_isalnum.c \
					./srcs/ft_isascii.c \
					./srcs/ft_isprint.c \
					./srcs/ft_strlen.c \
					./srcs/ft_memset.c \
					./srcs/ft_bzero.c \
					./srcs/ft_memcpy.c \
					./srcs/ft_memmove.c \
					./srcs/ft_strlcpy.c \
					./srcs/ft_toupper.c \
					./srcs/ft_tolower.c \
					./srcs/ft_strchr.c \
					./srcs/ft_strlcat.c \
					./srcs/ft_strrchr.c \
					./srcs/ft_strncmp.c \
					./srcs/ft_memchr.c \
					./srcs/ft_memcmp.c \
					./srcs/ft_strnstr.c \
					./srcs/ft_atoi.c \
					./srcs/ft_calloc.c \
					./srcs/ft_strdup.c \
					./srcs/ft_substr.c \
					./srcs/ft_strjoin.c \
					./srcs/ft_strtrim.c \
					./srcs/ft_split.c \
					./srcs/ft_itoa.c \
					./srcs/ft_strmapi.c \
					./srcs/ft_striteri.c \
					./srcs/ft_putchar_fd.c \
					./srcs/ft_putstr_fd.c \
					./srcs/ft_putnbr_fd.c \
					./srcs/ft_putendl_fd.c \
					./srcs/get_next_line.c \
					./srcs/get_next_line_utils.c \
					./srcs/ft_free.c \
					./srcs/ft_strncpy.c \

BSOURCES = 			./bonus/ft_lstadd_front.c \
					./bonus/ft_lstnew.c \
					./bonus/ft_lstsize.c \
					./bonus/ft_lstlast.c \
					./bonus/ft_lstadd_back.c \

NC			:= \033[0m
B_RED		:= \033[1;31m
RED 		:= \033[0;31m
B_GREEN		:= \033[1;32m
GREEN 		:= \033[1;32m
B_BLUE 		:= \033[1;34m
BLUE 		:= \033[0;34m
PURPLE		:= \033[0;35m
B_PURPLE	:= \033[1;35m

OBJECTS = $(SOURCES:.c=.o)

BOBJECTS = $(BSOURCES:.c=.o)

all: $(NAME)


%.o: %.c
#	@echo "$(B_GREEN)Compiling: $(GREEN)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)█\033[0m\c"

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)

bonus: all $(BOBJECTS)
	@ar rc $(NAME) $(BOBJECTS)

clean:
	@rm -f $(OBJECTS) $(BOBJECTS)
	@echo "\033[0;33m•\033[0;33m\c"
	@echo "$(B_RED)🧹 Cleaning: $(RED) libft object files $(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;33m••\033[0;33m\c"
	@echo "$(B_RED)🧹 Cleaning: $(RED) $(NAME) $(NC)"

re: fclean all
