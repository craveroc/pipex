/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:35:10 by ccravero          #+#    #+#             */
/*   Updated: 2022/02/08 17:22:14 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	init(char *dest, const char *src, size_t size, size_t *lendest)
{
	size_t	res;
	size_t	lensrc;

	lensrc = 0;
	res = 0;
	*lendest = 0;
	while (dest[*lendest] != 0)
		*lendest = (*lendest) + 1;
	while (src[lensrc] != 0)
		lensrc++;
	res = lensrc;
	if (size <= *lendest)
		res += size;
	else
		res += (*lendest);
	return (res);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lendest;
	size_t	cpt2;
	size_t	res;

	lendest = 0;
	cpt2 = 0;
	res = init (dest, src, size, &lendest);
	while (src[cpt2] && ((lendest) + cpt2 + 1) < size)
	{
		dest[lendest + cpt2] = src[cpt2];
		cpt2++;
	}
	dest[lendest + cpt2] = 0;
	return (res);
}
