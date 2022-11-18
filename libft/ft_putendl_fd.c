/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <clement.cravero@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:21:43 by ccravero          #+#    #+#             */
/*   Updated: 2022/02/06 10:50:41 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int	cpt;

	if (!str)
		return ;
	cpt = 0;
	while (str[cpt] != 0)
	{
		write(fd, &str[cpt], 1);
		cpt++;
	}
	write(fd, "\n", 1);
}
