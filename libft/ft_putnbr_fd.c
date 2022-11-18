/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:39:04 by ccravero          #+#    #+#             */
/*   Updated: 2022/02/03 20:53:51 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	testnb(int nb, int fd)
{
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return (0);
		}
		write(fd, "-", 1);
		nb = nb * -1;
	}
	return (nb);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int		cpt;
	char	aafficher[10];

	cpt = 0;
	nb = testnb(nb, fd);
	while (nb != 0)
	{
		aafficher[cpt] = nb % 10 + 48;
		nb /= 10;
		cpt += 1;
	}
	cpt -= 1;
	while (cpt >= 0)
	{
		write (fd, &aafficher[cpt], 1);
		cpt -= 1;
	}
}
