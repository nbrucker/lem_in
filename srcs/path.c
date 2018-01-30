/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		ft_checkpath(t_room *lem, t_room *in)
{
	t_room	*lemvious;
	t_room	*previnus;
	t_room	*startin;

	startin = in;
	lemvious = NULL;
	while (lem)
	{
		previnus = NULL;
		in = startin;
		while (in)
		{
			if (in == lem && in->spec != 2)
			{
				ft_redesign(lemvious, previnus);
				return (1);
			}
			previnus = in;
			in = in->path;
		}
		lemvious = lem;
		lem = lem->path;
	}
	return (0);
}

void	ft_makepath(t_room *lem)
{
	int		*tab;
	int		i;
	int		j;
	int		x;

	tab = ft_settab(lem, ft_nbrants(lem));
	i = 0;
	x = 0;
	while (tab[i] != -42 && x == 0)
	{
		j = 0;
		while (j < i && tab[i] > 0 && x == 0)
		{
			x = ft_checkpath(lem->links[i], lem->links[j]);
			j++;
		}
		i++;
	}
	free(tab);
	if (x == 1)
		ft_path(&lem);
}

int		ft_searchstart(t_room *lem)
{
	int i;

	if (lem->spec == 1)
		return (1);
	if (lem->spec == 2)
		return (0);
	if (lem->visited == 1)
		return (0);
	lem->visited = 1;
	i = 0;
	while (lem->links[i])
	{
		if (ft_searchstart(lem->links[i]) == 1)
		{
			lem->visited = 0;
			return (1);
		}
		i++;
	}
	lem->visited = 0;
	return (0);
}

void	ft_path(t_room **lem)
{
	t_room	*end;
	t_room	*start;

	ft_removealone(*lem);
	ft_rewind(lem);
	ft_setminus(*lem);
	ft_setvisited(*lem);
	end = ft_getend(*lem);
	start = ft_getstart(*lem);
	if (ft_nbrlinks(end) == 0 || ft_nbrlinks(start) == 0)
		ft_error("Error");
	start->visited = 1;
	end->best = 0;
	end->path = NULL;
	ft_setbest(end);
	start->best = -2;
	start->path = NULL;
	ft_sortlink(start);
	ft_setpath(*lem);
	ft_removeminus(*lem);
	ft_makepath(start);
}
