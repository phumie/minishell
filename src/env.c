/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 03:33:56 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/09/22 11:01:34 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_env(void)
{
	int		i;

	i = -1;
	while (g_saved_env[++i])
	{
		ft_putstr("\033[0;32m");
		ft_putstr(g_saved_env[i]);
		ft_putchar('\n');
	}
}

char	**get_env_char(int num)
{
	extern char	**environ;
	int			i;

	i = num;
	while (environ[i])
		i++;
	if (!(g_saved_env = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = -1;
	while (environ[++i])
	{
		g_saved_env[i] = ft_strdup(environ[i]);
	}
	return (g_saved_env);
}

void	get_env(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
		i++;
	if (!(g_saved_env = (char**)malloc(sizeof(char*) * (i + 1))))
		return ;
	i = -1;
	while (environ[++i])
	{
		g_saved_env[i] = ft_strdup(environ[i]);
	}
}

void	reset_oldpath(char *oldpwd)
{
	char	*path;
	int		i;
	char	new_pwd[BUFF_SIZE];
	int		pos;

	pos = 0;
	i = -1;
	if (!(path = (char *)malloc(sizeof(char) * ft_strlen("OLDPWD=") + 1)))
		return ;
	path = "OLDPWD=";
	ft_strcpy(new_pwd, path);
	ft_strcat(new_pwd, oldpwd);
	while (g_saved_env[++i] != 0)
	{
		if ((ft_strncmp(g_saved_env[i], new_pwd, ft_indexof(new_pwd, '=')))
		== 0)
			g_saved_env[i] = replace_env(&pos, new_pwd, g_saved_env[i]);
	}
	free(path);
}
