/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:19:35 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/02 18:56:05 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isprint(int str)
{
	if (str >= ' ' && str < 127)
		return (1);
	else
		return (0);
}