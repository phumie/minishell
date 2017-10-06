/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 03:33:12 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/09/22 11:09:07 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		count_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	env_dir(char **args)
{
	char	*path;

	ft_putstr(args[0]);
	if (args[0] == NULL)
	{
		if (!(path = (char *)malloc(sizeof(char)
		* ft_strlen(getenv_path("HOME") + 1))))
			return ;
		path = getenv_path("HOME");
		if (chdir(path) != 0)
			ft_putstr("Command not found\n");
	}
	else if (ft_strcmp(args[0], "-") == 0)
	{
		if (!(path = (char *)malloc(sizeof(char)
		* ft_strlen(getenv_path("OLDPWD") + 1))))
			return ;
		path = getenv_path("OLDPWD");
		if (chdir(path) != 0)
			ft_putstr("Command not found\n");
	}
	free(path);
}

void	ft_cd2(char **args)
{
	char	path[BUFF_SIZE];
	char	cwd[BUFF_SIZE];
	char	*env;

	if ((ft_strcmp(args[1], "-") == 0) && args[1][1] == '\0')
	{
		env = getenv_path("OLDPWD");
	}
	else if (args[1] != NULL)
	{
		ft_strcpy(path, args[1]);
		getcwd(cwd, sizeof(cwd));
		env = cwd;
		ft_strcat(cwd, "/");
		ft_strcat(cwd, path);
		if (chdir(cwd) != 0)
			ft_putstr("Command not found\n");
	}
	else if (ft_strcmp(args[0], "cd") == 0)
		env_dir(args + 1);
}

void	ft_cd(char **args)
{
	char	path[BUFF_SIZE];
	char	cwd[BUFF_SIZE];
	char	*env;

	if ((count_args(args) == 1) ||
	((ft_strcmp(args[1], "~") == 0) && args[1][1] == '\0'))
	{
		env = getenv_path("HOME");
		if (chdir(env) != 0)
			ft_putstr("path not found\n");
	}
	else if (count_args(args) == 1 || (args[1][0] == '~' && args[1][1] == '/'))
	{
		env = ft_strjoin(getenv_path("HOME"), "/");
		env = ft_strjoin(env, ft_strchr(args[1], '/'));
		if (chdir(env) != 0)
			ft_putstr("path not found\n");
	}
	else if (count_args(args) > 1)
		ft_cd2(args);
}
