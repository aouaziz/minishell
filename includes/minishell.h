/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:38:48 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/09 08:22:10 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "mini.h"
# include "../libft/includes/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <dirent.h>

enum				e_TOKEN_ENUM
{
	IN,
	OUT,
	DOC,
	APD,
};

typedef struct s_token
{
	int				type;
	char			*file;
	struct s_token	*next;
}					t_token;

typedef struct s_mini
{
	t_list			*cmd_list;
	t_token			*token_list;
	char			**cmds;
	int				in;
	int				out;
	struct s_mini	*next;
}					t_mini;

typedef struct s_env
{
	char			*env_name;
	char			*env_value;
	struct s_env	*next;
}					t_env;

typedef struct s_shell
{
	t_mini			*mini;
	int				g_status;
	t_env			*env_list;
	char			**env;
}					t_shell;

t_shell				*shell;

typedef struct s_space
{
	char			*output;
	char			*input;
	char			c;
	int				output_len;
	int				input_len;
	int				i;
}					t_space;

//exec
typedef struct s_exe
{
	int **tube;
	int size;
}t_exe;

//

char				*ft_replace_c_with_s_in_quotes(char *line, char c, char s);
char				*add_spaces(char *input);
int					skip_whitespace(char *str, int i);
int					check_brackets(char *str);
int					check_quotes(char *str);
int					ft_check(char *line);
int					check_pipe(char *str);
int					row_check(char *str);
t_mini				*ft_minilstnew(char **content);
t_list				*add_cmd_to_list(t_list *cmd_list, char *cmd);
t_token				*add_token_to_list(t_token *token_list, int type,
						char *content);
void				ft_token_list_add_back(t_token **lst, t_token *new);
t_token				*ft_token_lst_last(t_token *lst);
void				ft_mini_list_print(t_mini *lst);
void				ft_miniadd_back(t_mini **list, t_mini *new);
void				ft_add_to_the_lst(char **cmd, t_mini *mini);
char				**ft_fix_c_in_qoutes(char **cmds);
void				ft_fill_cmds(t_mini *tmp);
void				ft_lexer(char *cmd);
t_mini				*ft_mini_lst_last(t_mini *lst);
t_env				*fill_env_list(char **cmd, t_env *env_list);
void				ft_env_lstadd_back(t_env **lst, t_env *new);
t_env				*ft_env_lstlast(t_env *lst);
t_env				*ft_env_lst_new(void *content, void *content_value);
void				print_env_list(t_env *env_list, char **env);
char				*ft_fix_env(char *line);
void				env_fix_c(char *line, t_space *l);
char				*str_fill_up(char *line, t_space *l, char *c);
char				*get_name(char *line, t_space *l);
char				*get_value(char *name);
char				*remove_quotes(char *str);
void				ft_lst_fix(t_mini *lst);
char				ft_riplice(char c, int a);
void				ft_check_operator(t_space *s, char *input);
void				ft_check_operator_two(t_space *s, char *input);
char				*ft_get_env_value(char *s);
char				*ft_get_env_name(char *s);
void				remove_quotes_two(t_space *l, char c, int i);
void				ft_lstdel(t_list **list, char c);
void				ft_fill_cmds(t_mini *tmp);
void				ft_free_env(t_env **head);
void				ft_free_cmd(t_list *a);
void				ft_free_mini(t_mini **mini);
void				ft_free_token(t_token *token_list);
int					ft_fill_fds(t_mini *tmp);
int					ft_doc(char *doc);
void	handle_doc_sigint(int signal);
#endif
