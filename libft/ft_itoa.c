/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:08:15 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/06/20 10:08:19 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_length(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		len;
	int			wght;
	size_t		car;
	char		*str;

	ft_length(n, &len, &wght);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	car = 0;
	if (n < 0)
	{
		str[car] = '-';
		car++;
	}
	if (n > 0)
		n = -n;
	while (wght >= 1)
	{
		str[car++] = -(n / wght % 10) + 48;
		wght /= 10;
	}
	str[car] = '\0';
	return (str);
}
