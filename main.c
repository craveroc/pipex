/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:16:55 by ccravero          #+#    #+#             */
/*   Updated: 2022/07/17 15:41:41 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "pipex.h"
#include <fcntl.h>
#include <errno.h>

int	main(int argc, char *argv[])
{
	t_list	*arg;
	int		check;

	arg = ft_recup(argc, argv);
	if (!arg)
	{
		ft_putstr_fd("invalid number of arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	check = ft_checkargs(arg);
	if (check == 127)
	{
		ft_freelist(&arg);
		exit(127);
	}
	pipex(arg, check);
	return (check);
}

int	pipex(t_list *arg, int check)
{
	int		pipefd[2];
	pid_t	cpid;

	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	cpid = fork();
	if (cpid == -1)
		exit(EXIT_FAILURE);
	if (cpid == 0)
	{
		if (check != 127)
			ft_child(arg, pipefd);
		ft_freelist(&arg);
		exit(127);
	}
	else
	{
		if (check != -1)
			ft_parent(arg, pipefd, cpid);
		ft_freelist(&arg);
		exit(EXIT_SUCCESS);
	}
}

int	ft_parent(t_list *arg, int *pipefd, pid_t cpid)
{
	char	*path;
	int		fd;

	fd = open(arg->content, O_RDONLY);
	path = ft_findpath(((char **)arg->next->content)[0]);
	if (fd == -1 || !path)
	{
		free(path);
		return (!access(arg->content, F_OK));
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	if (!path)
		return (0);
	execve(path, arg->next->content, __environ);
	close(pipefd[1]);
	close(fd);
	waitpid(cpid, NULL, 0);
	free(path);
	ft_lstclear(&arg, &free);
	return (0);
}

void	ft_child(t_list *arg, int *pipefd)
{
	char	*path;
	int		fd;

	path = ft_findpath(((char **) arg->next->next->content)[0]);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	fd = open(ft_lstlast(arg)->content, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1 || !path)
	{
		free (path);
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	if (!access(path, X_OK))
		execve(path, arg->next->next->content, __environ);
	close(fd);
	close(pipefd[0]);
	free(path);
	return ;
}
