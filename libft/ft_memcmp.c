/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:40:11 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/02 18:52:34 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;	

	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while (i < n && *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
	{
		i++;
	}
	if (i == n)
		i--;
	return ((int)*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
