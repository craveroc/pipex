/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccravero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:54:40 by ccravero          #+#    #+#             */
/*   Updated: 2022/05/04 16:54:30 by ccravero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	libere(char **tab, int i)
{
	int	cpt;

	cpt = 0;
	while (cpt < i)
	{
		free(tab[i]);
		cpt++;
	}
	free(tab);
}

static int	compte_mot(const char *str, char const c)
{
	int	i;
	int	nbmot;
	int	mot;

	mot = 0;
	i = 0;
	nbmot = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
		{
			i++;
			mot = 0;
		}
		if (str[i] && mot == 0)
		{
			nbmot++;
			mot = 1;
		}
		if (str[i])
			i++;
	}
	return (nbmot + 1);
}

static char	*compte_lettre(const char *str, char c, int *j)
{
	int		nblettre;
	char	*mot;
	int		k;
	int		i;

	i = 0;
	k = *j - 1;
	nblettre = 0;
	while (str[(*j) - 1] && str[*j - 1] != c)
	{
		nblettre++;
		*j = *j + 1;
	}
	mot = malloc(sizeof(char) * (nblettre + 1));
	if (!mot)
		return (0);
	while (str[k] && str[k] != c)
	{
		mot[i] = str[k];
		i++;
		k++;
	}
	mot[i] = 0;
	return (mot);
}

char	**ft_split(char const *str, char const c)
{
	char	**tab;
	int		nbmot;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nbmot = compte_mot(str, c);
	tab = malloc(sizeof(char *) * nbmot);
	if (!tab)
		return (0);
	while (i < nbmot - 1)
	{
		if (str[j++] != c)
		{
			tab[i++] = compte_lettre(str, c, &j);
			if (!tab[i - 1])
			{
				libere(tab, i - 1);
				return (0);
			}
		}
	}
	tab[nbmot - 1] = 0;
	return (tab);
}
