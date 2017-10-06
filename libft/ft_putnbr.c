/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:10:51 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/06/20 10:10:53 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	lngnbr;

	lngnbr = (long)n;
	if (lngnbr < 0)
	{
		ft_putchar('-');
		lngnbr *= -1;
	}
	if (lngnbr >= 10)
	{
		ft_putnbr(lngnbr / 10);
		ft_putnbr(lngnbr % 10);
	}
	else
	{
		ft_putchar(lngnbr + '0');
	}
}
