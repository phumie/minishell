/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 03:51:09 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/09/22 03:51:28 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_del_env(int *check, char **environ, int index)
{
	*check = 1;
	while (environ[index])
	{
		ft_strdel(&environ[index]);
		if (environ[index + 1])
			environ[index] = ft_strdup(environ[index + 1]);
		index++;
	}
}

int		ft_unsetenv(char **args)
{
	int	check;
	int	i;
	int	j;

	i = -1;
	check = 0;
	while (args[++i])
	{
		j = -1;
		while (g_saved_env[++j])
		{
			if (ft_strncmp(g_saved_env[j], args[i],
						ft_indexof(g_saved_env[j], '=')) == 0)
				ft_del_env(&check, g_saved_env, j);
		}
	}
	return (check);
}
