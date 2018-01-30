/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:02:10 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 13:02:11 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	ft_free_save(t_room *lst)
{
	t_room *next;

	while (lst->previous)
		lst = lst->previous;
	while (lst)
	{
		next = lst->next;
		if (lst->links)
			free(lst->links);
		free(lst);
		lst = next;
	}
}

void	ft_restore(t_room *lst, t_room *save)
{
	int		i;

	ft_rewind(&lst);
	while (save->previous)
		save = save->previous;
	while (save)
	{
		i = 0;
		while (save->links[i])
		{
			lst->links[i] = save->links[i];
			i++;
		}
		lst->links[i] = save->links[i];
		lst->path = save->path;
		lst = lst->next;
		save = save->next;
	}
}

void	ft_savelinks(t_room *dst, t_room *src)
{
	int i;

	if (src->links == NULL)
		return ;
	if ((dst->links = (t_room**)malloc(sizeof(t_room*) *
		(ft_nbrlinks(src) + 1))) == NULL)
		ft_error("ERROR");
	i = 0;
	while (src->links[i])
	{
		dst->links[i] = src->links[i];
		i++;
	}
	dst->links[i] = src->links[i];
}

t_room	*ft_save(t_room *lst)
{
	t_room	*start;
	t_room	*new;
	t_room	*previous;

	start = NULL;
	previous = NULL;
	ft_rewind(&lst);
	while (lst)
	{
		if ((new = (t_room*)malloc(sizeof(t_room))) == NULL)
			ft_error("ERROR");
		if (start == NULL)
			start = new;
		new->next = NULL;
		new->previous = previous;
		if (previous)
			previous->next = new;
		new->links = NULL;
		ft_savelinks(new, lst);
		new->path = lst->path;
		previous = new;
		lst = lst->next;
	}
	return (start);
}
