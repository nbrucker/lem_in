/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		ft_total(t_room *lem, int *tab)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (tab[i] != -42)
	{
		if (tab[i] > 0 && lem->links[i]->best > 0)
		{
			if (lem->links[i]->best + tab[i] > x)
				x = lem->links[i]->best + tab[i];
		}
		i++;
	}
	return (x);
}

int		*ft_initializetab(t_room *lem)
{
	int	*tab;
	int	i;

	if ((tab = (int*)malloc(sizeof(int) * (ft_nbrlinks(lem) + 1))) == NULL)
		ft_error("ERROR");
	i = 0;
	while (i < ft_nbrlinks(lem))
	{
		tab[i] = 0;
		i++;
	}
	tab[i] = -42;
	return (tab);
}

int		ft_findbest(t_room *lem, int *tab)
{
	int x;
	int i;
	int n;

	i = 0;
	n = -1;
	x = 0;
	while (tab[i] != -42)
	{
		if (lem->links[i]->best != -1)
		{
			tab[i]++;
			if (ft_total(lem, tab) < n || n == -1)
			{
				n = ft_total(lem, tab);
				x = i;
			}
			tab[i]--;
		}
		i++;
	}
	return (x);
}

int		*ft_settab(t_room *lem, int ants)
{
	int	*tab;

	lem = ft_getstart(lem);
	tab = ft_initializetab(lem);
	while (ants > 0)
	{
		tab[ft_findbest(lem, tab)]++;
		ants--;
	}
	return (tab);
}
