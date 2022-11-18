/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <ccravero@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:07:50 by ccravero          #+#    #+#             */
/*   Updated: 2022/07/17 15:25:58 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_findpaths(void)
{
	char	**paths;
	int		cpt;

	cpt = 0;
	if (!__environ[0])
		return (NULL);
	while (__environ[cpt])
	{
		if (__environ[cpt][0] == 'P' && __environ[cpt][1] == 'A' &&
			__environ[cpt][2] == 'T' && __environ[cpt][3] == 'H' &&
			__environ[cpt][4] == '=')
			break ;
		cpt++;
	}
	if (!__environ[cpt])
		return (NULL);
	paths = ft_splitpath(__environ[cpt] + 5, ':');
	return (paths);
}

char	*ft_findpath(char *cmd)
{
	int		fd;
	char	**paths;
	char	*path;
	int		cpt;

	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	paths = ft_findpaths();
	path = 0;
	cpt = 0;
	fd = 1;
	while (paths && fd && paths[cpt])
	{
		free(path);
		path = ft_strjoin(paths[cpt], cmd);
		fd = access(path, X_OK);
		cpt++;
	}
	ft_freesplit(paths);
	if (fd == -1)
	{
		free(path);
		return (NULL);
	}
	return (path);
}

void	ft_freesplit(char **split)
{
	int	cpt;

	if (!split)
		return ;
	cpt = 0;
	while (split[cpt])
	{
		free(split[cpt]);
		cpt++;
	}
	free(split[cpt]);
	free (split);
}
