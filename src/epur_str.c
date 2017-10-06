/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:25:42 by pnevhuta          #+#    #+#             */
/*   Updated: 2017/09/22 15:36:45 by pnevhuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_epur_str(const char *s)
{
	char	*str;
	int		i;
	int		j;
	int		b;

	str = ft_strnew(sizeof(s));
	i = 0;
	j = 0;
	b = 0;
	while (s != NULL && ft_strlen(s) > 0 && s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == '\t')
		{
			b = 1;
			i++;
		}
		if (b == 1)
			str[j++] = ' ';
		if (s[i] != ' ' || s[i] != '\t')
		{
			str[j++] = s[i++];
			b = 0;
		}
	}
	return (ft_strtrim(str));
}
