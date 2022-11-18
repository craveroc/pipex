/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:46:10 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/05 14:39:56 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

static void	ft_revstrint(char	*tab)
{
	int		cpt2;
	int		temp;
	size_t	size;
	int		min;

	min = 0;
	if (tab[0] == '-')
		min++;
	size = ft_strlen(tab);
	cpt2 = size - 1;
	while (min < cpt2)
	{
		temp = tab[min];
		tab[min] = tab[cpt2];
		tab[cpt2] = temp;
		min++;
		cpt2--;
	}
}

char	*ft_itoa(int n)
{
	char	*nb;
	char	temp[15];
	int		taille;

	taille = 0;
	if (n <= 0)
		taille = 1;
	if (n < 0)
		temp[0] = '-';
	else if (n == 0)
		temp[0] = '0';
	while (n)
	{
		temp[taille] = ft_abs((n % 10)) + 48;
		n /= 10;
		taille++;
	}
	nb = ft_calloc(taille + 1, 1);
	if (!nb)
		return (0);
	while (--taille >= 0)
		nb[taille] = temp[taille];
	ft_revstrint(nb);
	return (nb);
}
