/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:58:00 by ccravero          #+#    #+#             */
/*   Updated: 2022/07/14 14:30:22 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*ft_recup(int argc, char **argv)
{
	t_list	*head;
	int		cpt;

	head = NULL;
	cpt = 1;
	if (argc != 5)
		return (NULL);
	while (cpt < argc)
	{
		if (cpt == 1 || cpt == argc -1)
			ft_lstadd_back(&head, ft_lstnew(ft_strdup(argv[cpt])));
		else
			ft_lstadd_back(&head, ft_lstnew(ft_split(argv[cpt], ' ')));
		cpt++;
	}
	return (head);
}

void	ft_freelist(t_list **arg)
{
	t_list	*head;
	t_list	*tmp;

	head = *arg;
	head = head->next;
	while (head != ft_lstlast(head))
	{
		ft_freesplit(head->content);
		tmp = head->next;
		free(head);
		head = tmp;
	}
	free(head->content);
	free(head);
	free((*arg)->content);
	free(*arg);
}

int	ft_checkargs(t_list *args)
{
	int	check;
	int	fd;

	check = 0;
	if (access(args->content, F_OK))
		check = ft_perror(args->content, 1);
	else if (access(args->content, R_OK))
		check = ft_perror(args->content, 0);
	if (!access(ft_lstlast(args)->content, F_OK))
	{
		if (access(ft_lstlast(args)->content, W_OK))
			check = ft_perror(ft_lstlast(args)->content, 1);
	}
	else
	{
		fd = open(ft_lstlast(args)->content, O_CREAT, 0666);
		if (fd == -1)
			return (ft_perror (ft_lstlast(args)->content, 1));
		close(fd);
	}
	ft_checkcmd(args->next, &check);
	return (check);
}

void	ft_checkcmd(t_list *args, int *check)
{
	t_list	*tmp;
	char	*path;

	tmp = args;
	while (tmp != ft_lstlast(args))
	{
		path = ft_findpath(((char **)tmp->content)[0]);
		if (!path)
		{
			*check = 127;
			ft_putstr_fd("command not found: ", STDERR_FILENO);
			ft_putstr_fd(((char **)tmp->content)[0], STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
		}
		else if (*check == 127)
			*check = -1;
		free (path);
		tmp = tmp->next;
	}
}

int	ft_perror(char *toprint, int ret)
{
	perror(toprint);
	return (ret);
}
