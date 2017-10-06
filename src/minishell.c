/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 03:20:35 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/09/22 17:22:24 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_command(char **command)
{
	if (command[0] != NULL)
	{
		if (ft_strcmp(command[0], "exit") == 0)
			ft_exit_mini();
		else if (ft_strcmp(command[0], "echo") == 0)
			ft_echo(command);
		else if (ft_strcmp(command[0], "cd") == 0)
			ft_cd(command);
		else if (ft_strcmp(command[0], "env") == 0)
			print_env();
		else if (ft_strcmp(command[0], "setenv") == 0)
			ft_setenv(command + 1);
		else if (ft_strcmp(command[0], "unsetenv") == 0)
			ft_unsetenv(command + 1);
		else if (search_paths(command) > 0)
			ft_putstr("Command not found\n");
	}
	else
		ft_putstr("There is no command to run\n");
}

int		find_builtin(char **command)
{
	if (ft_strstr(command[0], "/"))
	{
		run_bin(command);
		return (-1);
	}
	return (0);
}

void	get_prompt(void)
{
	ft_putstr("\033[1;34mPHUMIE ");
	ft_putstr("\33[1m\033[31m");
	ft_putstr("$> ");
	ft_putstr("\033[0;33m");
}

int		loop_buffer(char *str)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (*str)
	{
		if (ft_isprint(*str) == 1)
			s++;
		else
			i++;
		str++;
	}
	if (s > 0)
		return (s);
	else
		return (0);
}

int		main(void)
{
	char	*buffer;
	char	**command;
	int		i;

	i = 0;
	get_env();
	while (1)
	{
		get_prompt();
		signal(SIGINT, signal_handler);
		if (get_next_line(0, &buffer) < 0)
			return (-1);
		if (!ft_strequ(buffer, "") && (loop_buffer(buffer) > 0))
		{
			command = ft_split(ft_strtrim(buffer));
			if (!find_builtin(command))
				execute_command(command);
		}
		free(command);
		command = NULL;
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
