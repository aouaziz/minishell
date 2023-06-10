/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:25:25 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 15:56:39 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_F
#define MINI_F

#include "minishell.h"

//builtin
//#define LONG_MIN (-2147483647L - 1)
//#define LONG_MAX 2147483647L

//builtin
void env_cmd(t_shell *shell, char **args);
void cd_cmd(char **args, t_shell *shell);
void cmd_echo(char **str, t_shell *shell);
void  export_cmd(t_shell *shell, char **argv);
void  pwd_cmd(t_shell *shell, char **args);
void  unset_cmd(t_shell *shell, char **argv);
void  exit_cmd(char **str, t_shell *shell);





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
char *ftt_strtrim_space(char *str);
long  ftt_atoi_l(char *str);
char **ftt_strdup_2(char **str);

  //print
void  ftt_print_fd(int fd, char *str);

//pipat
void    execute_builtin(t_shell *shell, char **dupli, int status);
int builtin_fork_status(char **str);
pid_t   pipe_and_fork(t_shell *shell, t_exe *exe);
char *solide_path(t_mini *mini, t_exe *exe);
int pathern(t_exe *exe, t_mini *mini);
void    executing(t_shell *shell);


#endif