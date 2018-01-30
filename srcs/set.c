/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:07:28 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 12:07:29 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lookfor(t_room *lem)
{
	int i;
	int x;

	i = 0;
	x = 0;
	lem->visited = 1;
	while (lem->links[i] && x == 0)
	{
		if (lem->links[i] != lem->path)
			x = ft_searchstart(lem->links[i]);
		i++;
	}
	lem->visited = 0;
	if (x == 0)
	{
		lem->path = ft_getnextbest(lem);
		lem->best = lem->path->best + 1;
	}
}

void	ft_setpath(t_room *lem)
{
	ft_rewind(&lem);
	ft_setvisited(lem);
	while (lem)
	{
		if (lem->links == NULL || lem->links[0] == NULL ||
			lem->spec == 2 || lem->spec == 1)
		{
			lem = lem->next;
			continue ;
		}
		ft_lookfor(lem);
		lem = lem->next;
	}
}

void	ft_setminus(t_room *lem)
{
	ft_rewind(&lem);
	while (lem)
	{
		lem->best = -1;
		lem->path = NULL;
		lem = lem->next;
	}
}

void	ft_setvisited(t_room *lem)
{
	ft_rewind(&lem);
	while (lem)
	{
		lem->visited = 0;
		if (lem->next == NULL)
			break ;
		lem = lem->next;
	}
}

void	ft_setbest(t_room *lem)
{
	int i;

	if (lem->visited == 1 || lem->spec == 1)
		return ;
	i = 0;
	lem->visited = 1;
	while (lem->links[i])
	{
		if (lem->links[i]->best == -1 ||
			lem->links[i]->best > lem->best + 1)
		{
			lem->links[i]->best = lem->best + 1;
			lem->links[i]->path = lem;
			lem->links[i]->visited = 0;
		}
		i++;
	}
	i = 0;
	while (lem->links[i])
	{
		ft_setbest(lem->links[i]);
		i++;
	}
}
