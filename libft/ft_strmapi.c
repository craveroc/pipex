/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:56:53 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/05 14:43:14 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		cpt;

	if (!s || !f)
		return (0);
	cpt = 0;
	str = ft_calloc(ft_strlen(s) + 1, 1);
	if (!str)
		return (0);
	while (s[cpt])
	{
		str[cpt] = (*f)(cpt, s[cpt]);
		cpt++;
	}
	return (str);
}
