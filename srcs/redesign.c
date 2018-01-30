/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redesign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:58:41 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 12:58:41 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_remove_both(t_room *lem, t_room *in)
{
	ft_removelink(lem, in->name);
	ft_removelink(in, lem->name);
}

void	ft_redesign_next(t_room *lem, t_room *in)
{
	t_room	*save;
	t_room	*start;
	int		nextin;
	int		nextlem;

	start = ft_getstart(lem);
	save = ft_save(start);
	ft_remove_both(in, in->path);
	ft_path(&start);
	nextin = ft_gettotal(start);
	ft_restore(start, save);
	ft_remove_both(lem, lem->path);
	ft_path(&start);
	nextlem = ft_gettotal(start);
	ft_restore(start, save);
	ft_free_save(save);
	if (nextlem < nextin)
	{
		ft_remove_both(lem, lem->path);
		return ;
	}
	ft_remove_both(in, in->path);
}

void	ft_redesign(t_room *lem, t_room *in)
{
	if (lem == NULL)
	{
		ft_removelink(in, in->path->name);
		ft_removelink(in->path, in->name);
	}
	else if (in == NULL)
	{
		ft_removelink(lem, lem->path->name);
		ft_removelink(lem->path, lem->name);
	}
	else
		ft_redesign_next(lem, in);
}
