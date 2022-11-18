/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:56:22 by ccravero          #+#    #+#             */
/*   Updated: 2022/06/29 10:40:26 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if ((*(lst))->next)
	{
		ft_lstclear(&((*(lst))->next), del);
	}
	del((*(lst))->content);
	free(*lst);
	*lst = 0;
}
