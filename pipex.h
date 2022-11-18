/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:17:26 by ccravero          #+#    #+#             */
/*   Updated: 2022/07/17 15:23:55 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include "./libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

//coucou
//main.c
char	*ft_readall(int fd);
int		pipex(t_list *arg, int check);
int		ft_parent(t_list *arg, int *pipefd, pid_t cpid);
void	ft_child(t_list *arg, int *pipefd);

//parsing.c
t_list	*ft_recup(int argc, char **argv);
void	ft_freelist(t_list **arg);
int		ft_checkargs(t_list *args);
int		ft_printcheck(t_list *args);
void	ft_checkcmd(t_list *args, int *check);
int		ft_perror(char *toprint, int ret);

//utils.c
void	ft_printlist(t_list *head);
void	ft_printtabs(char **tab);

//path.c
char	**ft_findpaths(void);
char	*ft_findpath(char *cmd);
void	ft_freesplit(char **split);

//ft_splitpath.c
char	**ft_splitpath(char const *str, char const c);
#endif