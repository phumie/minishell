/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 03:50:12 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/09/22 12:17:16 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*replace_env(int *check, char *command, char *g_saved_env)
{
	char	*temp;

	*check = 1;
	temp = ft_strdup(command);
	return (temp);
}

void		free_env(char **env)
{
	int i;

	i = -1;
	while (env[++i])
	{
		free(env[i]);
		env[i] = NULL;
	}
	free(env);
}

char		**add_env(char *command)
{
	char	**temp;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (g_saved_env[len] != 0)
		len++;
	temp = (char**)malloc(sizeof(char*) * (len + 2));
	temp[len + 1] = 0;
	while (++i < len)
		temp[i] = ft_strdup(g_saved_env[i]);
	temp[len] = ft_strdup(command);
	free_env(g_saved_env);
	return (temp);
}

void		ft_setenv(char **command)
{
	int		i;
	int		pos;
	int		j;

	j = -1;
	i = -1;
	while (command[++i])
	{
		pos = 0;
		if (ft_strchr(command[i], '=') != NULL)
		{
			while (g_saved_env[++j] != 0)
			{
				if ((ft_strncmp(g_saved_env[j], command[i],
								ft_indexof(command[i], '='))) == 0)
					g_saved_env[j] =
					replace_env(&pos, command[i], g_saved_env[j]);
			}
			if (!pos)
				g_saved_env = add_env(command[i]);
		}
	}
}
