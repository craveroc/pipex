/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:43:06 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/04 16:47:32 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	taille;
	size_t	cpt;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	taille = ft_strlen(s + start);
	if (taille < len)
		str = ft_calloc(taille + 1, 1);
	else
		str = ft_calloc(len + 1, 1);
	if (!str)
		return (str);
	cpt = 0;
	while (s[cpt + start] && cpt < len)
	{
		str[cpt] = s[cpt + start];
		cpt++;
	}
	str[cpt] = 0;
	return (str);
}
