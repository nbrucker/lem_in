/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	ft_free_ants(t_room *lem)
{
	t_ant *next;

	while (lem->ant && lem->ant->previous)
		lem->ant = lem->ant->previous;
	while (lem->ant)
	{
		next = lem->ant->next;
		free(lem->ant);
		lem->ant = next;
	}
}

void	ft_free_rooms(t_room *lem)
{
	t_room *next;

	ft_rewind(&lem);
	while (lem)
	{
		next = lem->next;
		ft_free_ants(lem);
		free(lem->name);
		free(lem->links);
		free(lem);
		lem = next;
	}
}

int		main(void)
{
	t_room	*lem;
	t_buf	buf;

	if ((buf.str = ft_strnew(1)) == NULL)
		ft_error("ERROR");
	lem = ft_parse(&buf);
	ft_putbuf(&buf, "\n");
	ft_path(&lem);
	ft_rewind(&lem);
	ft_algo(lem, &buf);
	ft_free_rooms(lem);
	write(1, buf.str, ft_strlen(buf.str));
	free(buf.str);
	return (0);
}
