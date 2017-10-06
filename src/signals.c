/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 03:21:54 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/09/22 17:15:38 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_c(int signum)
{
	(void)signum;
	if (g_pid > 0)
	{
		ft_putchar('\n');
		signal(g_pid, signal_c);
	}
	else
		ft_putstr("\nUse exit command to quit\n");
}

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, proc_signal_handler);
	}
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		get_prompt();
		signal(SIGINT, signal_handler);
	}
	if (signo == SIGQUIT)
	{
		ft_putstr("\n...exiting...\n");
		exit(1);
	}
}
