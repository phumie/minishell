/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 03:51:55 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/09/22 15:37:58 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# define BUFF_SIZE 1024

char **g_saved_env;

pid_t		g_pid;

int			get_next_line(const int fd, char **line);
void		ft_exit_mini();
static void	echo_string(char *str);
void		get_prompt();
int			main(void);
void		execute_command(char **command);
int			find_builtin(char **command);
void		ft_echo(char **line);
void		ft_cd(char **args);
void		append_args(char *str1, char *str2);
void		change_dir(char *args);
void		signal_c(int signum);
void		print_env(void);
void		get_env(void);
void		ft_setenv(char **command);
char		**add_env(char *command);
void		free_env(char **env);
char		*replace_env(int *check, char *command, char *saved_env);
int			ft_unsetenv(char **args);
void		ft_del_env(int *check, char **environ, int index);
void		run_bin(char **command);
void		run_builtin(char *path, char **command);
int			search_paths(char **command);
char		*getenv_path(char *find_path);
void		proc_signal_handler(int signo);
void		signal_handler(int signo);
void		env_dir(char **args);
void		reset_oldpath(char *oldpwd);
char		*ft_epur_str(const char *s);
char		**ft_split(char *str);

#endif
