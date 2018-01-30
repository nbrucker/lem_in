/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_sortlink(t_room *lem)
{
	int		i;
	int		j;
	t_room	*tmp;

	i = 0;
	while (lem->links[i])
	{
		j = 0;
		while (j < i)
		{
			if (lem->links[j]->best > lem->links[i]->best)
			{
				tmp = lem->links[j];
				lem->links[j] = lem->links[i];
				lem->links[i] = tmp;
			}
			j++;
		}
		i++;
	}
}
