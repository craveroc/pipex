/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:57:40 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/02 18:57:53 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	cpt;
	size_t	total;

	total = size * nmemb;
	if (size && total / size != nmemb)
		return (0);
	tab = malloc(total);
	if (tab == 0 || !total)
		return (tab);
	cpt = 0;
	while (cpt < total)
	{
		((char *)tab)[cpt] = 0;
		cpt++;
	}
	return (tab);
}
