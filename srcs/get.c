/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:02:20 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 13:02:20 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_rewind(t_room **lem)
{
	while (*lem && (*lem)->previous)
		*lem = (*lem)->previous;
}

t_room	*ft_getnextbest(t_room *lem)
{
	int x;
	int i;

	x = -1;
	i = 0;
	while (lem->links[i])
	{
		if ((lem->links[i]->best < x || x == -1) && lem->links[i] != lem->path)
			x = i;
		i++;
	}
	return (lem->links[x]);
}

int		ft_gettotal(t_room *lem)
{
	int		*tab;
	t_room	*start;
	int		x;

	start = ft_getstart(lem);
	tab = ft_settab(start, ft_nbrants(start));
	x = ft_total(start, tab);
	free(tab);
	return (x);
}

t_room	*ft_getend(t_room *lem)
{
	ft_rewind(&lem);
	while (lem->spec != 2)
		lem = lem->next;
	return (lem);
}

t_room	*ft_getstart(t_room *lem)
{
	ft_rewind(&lem);
	while (lem->spec != 1)
		lem = lem->next;
	return (lem);
}
