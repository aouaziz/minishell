/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:38:48 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/18 09:06:42 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
	int 			index;
	struct s_token	*next;
}					t_token;

typedef struct s_mini
{
	t_list			*cmd_list;
	t_token			*token_list;
	char			**cmds;
	int				in;
	int				out;
	int 			doc;
	struct s_mini	*next;
	int				index;
}					t_mini;

typedef struct s_env
{
	char			*env_name;
	int 			status;
	char			*env_value;
	struct s_env	*next;
}					t_env;


typedef struct s_shell
{
	t_mini			*mini;
	int				g_status;
	t_env			*env_list;
	char			**env;
	int				size;
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

//t_

//exec
typedef struct s_exe
{
	char *path;
	int **tube;
	//t_files files;
	int size;
}t_exe;

//parsing
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
void				ft_add_to_the_lst(char **cmd);
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
int					ft_fill_fds(void);
void	ft_doc(void);
void				handle_doc_sigint(int signal);
void 				fill_index(void);
void				fill_env_list_add(char *cmd);
int 				ft_lst_env_size(t_env *lst);
char				**ft_env_list_to_env(void);
int				ft_lstdel_env(t_env **list, char *cmd);
int					ft_env_change_value(char *name , char *value);
char				*ft_get_value(char *name);
char	*ft_replace_c_with_s(char *line, char c, char s);
void                        rl_replace_line(const char *text, int clear_undo);
int her_doc(char *lim, int expander);
void	handle_sigint(int sig);
void	cat_handle_sigint(int sig);
int her_doc(char *lim, int expander);
void	ft_open_fd(t_mini *tmp, t_token *curr);
int is_empty();

//builtin
void env_cmd(char **args);
void cd_cmd(char **args);
void echo_cmd(char **str);
void	export_cmd(char **argv);
void  pwd_cmd(void);
void	unset_cmd(char **argv);
void  exit_cmd(char **str);





//env_manipulation
void  print_env(char **env);
int  count_env(char **env);
int  get_indice_env(char **env, char *path);
char *get_content_env(char **env, char *path);
void  change_content(char **env, int i, char *s1, char *s2);
int  env_compatible(char *str);
void        print_err_env(char *str);
char **unset_var_env(char **env, int index);
char **realloc_env_var(char **env, int count);
char **set_env_var(char **env, int index, char *str);

////var_utils
void  free_double_env(char **str);
void  free_half(char **str, int i);




//utils
int ftt_strlen(char *str);
int  ftt_strncmp(char *s1, char *s2, int n);
char *ftt_strdup(char *str);
char *ftt_strjoin(char *s1, char *s2);
char	*ftt_substr(char *s, unsigned int start, size_t len);
int  ftt_isalpha(char c);
int ftt_isalnum(char c);
int  ftt_isdigit(char c);
int ftt_isspace(char c);
char	*ftt_strrchr(char *s, int c);
int	ftt_search(char *str, char c);
char *ftt_strtrim_space(char *str);
long  ftt_atoi_l(char *str);
char **ftt_strdup_2(char **str);
int	ftt_strcmp(char *s1, char *s2);
int	ft_lstsize_s(t_mini *lst);


  //print
void  ftt_print_fd(int fd, char *str);

//pipat
void    execute_builtin(t_mini *mini);
int builtin_fork_status(char **str);
pid_t   pipe_and_fork(t_exe *exe);
int pathern(t_exe *exe, t_mini *mini);
void    executing(void);
void close_pipes(t_exe *exe);
void  export_element(char *str, int status);
int check_element_validity(char *str);

#endif
//tat3tiha name tatred lik value