/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:56:53 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/05 14:42:28 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	cpt;

	if (!s)
		return ;
	cpt = 0;
	while (s[cpt])
	{
		(*f)(cpt, &(s[cpt]));
		cpt++;
	}
}
