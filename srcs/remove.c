/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	ft_removealone(t_room *lem)
{
	ft_rewind(&lem);
	while (lem)
	{
		if (ft_nbrlinks(lem) == 1 && lem->spec != 2 && lem->spec != 1)
		{
			ft_removealllink(lem);
			ft_rewind(&lem);
		}
		else
			lem = lem->next;
	}
}

void	ft_removelink(t_room *lem, char *str)
{
	t_room	*last;
	int		i;

	i = 0;
	while (lem->links[i] != NULL)
		i++;
	if (ft_strcmp(lem->links[i - 1]->name, str) == 0)
	{
		lem->links[i - 1] = NULL;
		return ;
	}
	last = lem->links[i - 1];
	lem->links[i - 1] = NULL;
	i = 0;
	while (ft_strcmp(lem->links[i]->name, str) != 0)
		i++;
	lem->links[i] = last;
}

void	ft_removealllink(t_room *lem)
{
	int i;

	i = 0;
	if (lem->links == NULL)
		return ;
	while (lem->links[i] != NULL)
	{
		ft_removelink(lem->links[i], lem->name);
		i++;
	}
	while (lem->links[0] != NULL)
		ft_removelink(lem, lem->links[0]->name);
}

void	ft_removeminus(t_room *lem)
{
	ft_rewind(&lem);
	while (lem)
	{
		if (lem->best == -1)
			ft_removealllink(lem);
		lem = lem->next;
	}
}
