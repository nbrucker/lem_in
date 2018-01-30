/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_nbrlinks(t_room *lem)
{
	int i;

	if (lem->links == NULL)
		return (0);
	i = 0;
	while (lem->links[i])
		i++;
	return (i);
}

int		ft_nbrants(t_room *lem)
{
	int i;

	if (lem->ant == NULL)
		return (0);
	while (lem->ant->previous)
		lem->ant = lem->ant->previous;
	i = 0;
	while (lem->ant)
	{
		i++;
		if (lem->ant->next == NULL)
			break ;
		lem->ant = lem->ant->next;
	}
	while (lem->ant->previous)
		lem->ant = lem->ant->previous;
	return (i);
}
