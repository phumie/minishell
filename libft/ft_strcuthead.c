/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcuthead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 17:35:35 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/06/30 10:00:20 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcuthead(char **s, int c)
{
	char *temp;

	if (!*s)
		return (NULL);
	if (!(temp = ft_strsub(*s, c, ft_strlen(*s) - c)))
		return (NULL);
	free(*s);
	*s = NULL;
	if (!(*s = (char*)malloc(ft_strlen(temp) + 1)))
		return (NULL);
	ft_bzero((void*)(*s), ft_strlen(temp) + 1);
	ft_strcpy(*s, temp);
	free(temp);
	temp = NULL;
	return (*s);
}
