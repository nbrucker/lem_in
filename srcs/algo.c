/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	ft_sendant(t_room *src, t_room *dst, int *print, t_buf *buf)
{
	t_ant	*lem;

	if (ft_nbrants(src) <= 0)
		return ;
	lem = src->ant;
	if (ft_nbrants(dst) >= 1 && dst->spec != 2)
		return ;
	if (lem->moved == 1)
		return ;
	lem->moved = 1;
	src->ant = src->ant->next;
	if (src->ant)
		src->ant->previous = NULL;
	lem->next = dst->ant;
	if (dst->ant)
		dst->ant->previous = lem;
	dst->ant = lem;
	if (*print > 0)
		ft_putbuf(buf, " ");
	ft_putbuf(buf, "L");
	ft_putbuf_int(buf, lem->name);
	ft_putbuf(buf, "-");
	ft_putbuf(buf, dst->name);
	*print += 1;
}

void	ft_empty(t_room *lem, int *print, t_buf *buf)
{
	if (lem->spec == 2)
		return ;
	ft_empty(lem->path, print, buf);
	ft_sendant(lem, lem->path, print, buf);
}

void	ft_setants(t_room *lem)
{
	ft_rewind(&lem);
	while (lem)
	{
		while (lem->ant && lem->ant->previous)
			lem->ant = lem->ant->previous;
		while (lem->ant)
		{
			lem->ant->moved = 0;
			if (lem->ant->next == NULL)
				break ;
			lem->ant = lem->ant->next;
		}
		while (lem->ant && lem->ant->previous)
			lem->ant = lem->ant->previous;
		lem = lem->next;
	}
}

void	ft_empty_start(t_room *lem, int *tab, t_buf *buf)
{
	int	print;
	int	i;

	i = 0;
	print = 0;
	while (tab[i] != -42)
	{
		ft_empty(lem->links[i], &print, buf);
		if (tab[i] > 0)
		{
			tab[i]--;
			ft_sendant(lem, lem->links[i], &print, buf);
		}
		i++;
	}
	if (print > 0)
		ft_putbuf(buf, "\n");
}

void	ft_algo(t_room *lem, t_buf *buf)
{
	int		*tab;
	int		x;
	t_room	*end;

	lem = ft_getstart(lem);
	x = ft_nbrants(lem);
	if (x == 0)
		return ;
	tab = ft_settab(lem, ft_nbrants(lem));
	end = ft_getend(lem);
	while (ft_nbrants(end) != x)
	{
		ft_setants(lem);
		ft_empty_start(lem, tab, buf);
	}
	free(tab);
}
