/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:47:28 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/05 14:44:06 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		cpt;
	int		len1;

	if (!s1 || !s2)
		return (0);
	cpt = 0;
	len1 = ft_strlen(s1);
	str = ft_calloc(len1 + ft_strlen(s2) + 1, 1);
	if (!str)
		return (0);
	while (s1[cpt])
	{
		str[cpt] = s1[cpt];
		cpt++;
	}
	cpt = 0;
	while (s2[cpt])
	{
		str[cpt + len1] = s2[cpt];
		cpt++;
	}
	return (str);
}
