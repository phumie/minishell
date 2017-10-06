/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 11:36:15 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/09/22 14:10:51 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_builtin(char *path, char **command)
{
	int		status;

	g_pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (g_pid == 0)
	{
		ft_putstr("\033[0;32m");
		if (execve(path, command, g_saved_env) == -1)
			ft_putstr("Command not found\n");
		exit(1);
	}
	else
	{
		waitpid(g_pid, &status, WUNTRACED);
		g_pid = 0;
	}
}

void	run_bin(char **command)
{
	char	**tab;
	char	*path;
	int		len;

	tab = ft_strsplit(command[0], '/');
	len = 0;
	path = ft_strdup(command[0]);
	while (tab[len])
		len++;
	ft_strdel(&command[0]);
	command[0] = ft_strdup(tab[len - 1]);
	run_builtin(path, command);
	ft_strdel(tab);
}

char	*getenv_path(char *find_path)
{
	int		i;

	i = -1;
	while (g_saved_env[++i])
	{
		if (ft_strstr(g_saved_env[i], find_path) != NULL)
			return (&g_saved_env[i][ft_strlen(find_path) + 1]);
	}
	return (NULL);
}

int		search_paths(char **command)
{
	char			**paths;
	int				i;
	DIR				*dirp;
	struct dirent	*read_dir;
	char			*str;

	(!(paths = ft_strsplit(getenv_path("PATH"), ':'))) ?
		ft_putstr("Command is unavailable\n") : 0;
	i = 0;
	while (paths[i] && (dirp = opendir(paths[i])))
	{
		while ((read_dir = readdir(dirp)) != NULL)
			if (strcmp(read_dir->d_name, command[0]) == 0)
			{
				str = ft_strjoin(paths[i], "/");
				run_builtin(ft_strjoin(str, read_dir->d_name), command);
				return (0);
			}
		closedir(dirp);
		i++;
	}
	free(paths);
	return (1);
}
