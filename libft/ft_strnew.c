/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:59:29 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/06/30 09:59:26 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *sz;

	if (!(sz = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(sz, '\0', size + 1);
	return (sz);
}
