/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:53:22 by ccravero          #+#    #+#             */
/*   Updated: 2022/02/09 13:11:14 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	cpt;
	unsigned int	cpt2;

	cpt = 0;
	cpt2 = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[cpt] != 0)
	{
		if (size && cpt < size -1)
		{	
			dest[cpt] = src[cpt];
			cpt2++;
		}
		cpt++;
	}
	dest[cpt2] = 0;
	return (cpt);
}
