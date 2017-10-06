/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_aa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 10:09:49 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/06/20 10:09:52 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_aa(void *s1, const void *s2, size_t n)
{
	char		*cur1;
	char		*cur2;

	if (n == 0 || s1 == s2)
		return (s1);
	cur1 = (char *)s1;
	cur2 = (char *)s2;
	while (n--)
	{
		cur1[n] = cur2[n];
	}
	return (s1);
}
