/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:28:51 by ccravero          #+#    #+#             */
/*   Updated: 2022/07/06 08:07:27 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_printlist(t_list *head)
{
	ft_putendl_fd(head->content, 1);
	head = head->next;
	while (head ->next)
	{
		ft_printtabs(head->content);
		head = head->next;
	}
	ft_putendl_fd(head->content, 1);
}

void	ft_printtabs(char **tab)
{
	int	cpt;

	cpt = 0;
	while (tab[cpt])
	{
		ft_putendl_fd(tab[cpt], 1);
		cpt++;
	}
}

//coucou