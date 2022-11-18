/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:54:22 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/05 14:41:22 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_in(char const s1, char const *set)
{
	int	cpt;

	cpt = 0;
	while (set[cpt])
	{
		if (set[cpt] == s1)
			return (1);
		cpt++;
	}
	return (0);
}

static int	comptechar(char const *s1, char const *set)
{
	int		nbc;
	int		cpt;

	nbc = 0;
	cpt = 0;
	while (s1[cpt] && (ft_is_in(s1[cpt], set)))
	{
		nbc += 1;
		cpt++;
	}
	if ((size_t)cpt == ft_strlen(s1))
		return (-1);
	cpt = ft_strlen(s1) - 1;
	while (ft_is_in(s1[cpt], set))
	{
		nbc += 1;
		cpt--;
	}
	return (nbc);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		nbc;
	size_t	cpt;
	int		ending;
	char	*str;

	if (!s1 || !set)
		return (0);
	cpt = 0;
	nbc = comptechar(s1, set);
	if (nbc == -1)
		return (ft_calloc(1, 1));
	str = ft_calloc(ft_strlen(s1) - nbc + 1, 1);
	if (!str)
		return (0);
	if (ft_strlen(s1) - nbc + 1 == 1)
		return (str);
	while (ft_is_in(s1[cpt], set) && s1[cpt++])
		nbc--;
	ending = cpt;
	while (s1[cpt] && cpt < (ft_strlen(s1) - nbc))
	{
		str[cpt - ending] = s1[cpt];
		cpt++;
	}
	return (str);
}
