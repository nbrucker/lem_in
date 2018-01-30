/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_ant	*ft_add_ants(int x)
{
	t_ant	*new;
	t_ant	*start;
	t_ant	*previous;
	int		i;

	start = NULL;
	previous = NULL;
	i = 0;
	while (i < x)
	{
		if ((new = (t_ant*)malloc(sizeof(t_ant))) == NULL)
			ft_error("ERROR");
		new->name = i + 1;
		new->moved = 0;
		new->next = NULL;
		if (start == NULL)
			start = new;
		if (previous)
			previous->next = new;
		new->previous = previous;
		previous = new;
		i++;
	}
	return (start);
}

int		ft_add_room(char *str, t_room **lem, int spec, t_buf *buf)
{
	t_room	*new;
	int		x;
	int		y;

	if (ft_parse_name(str, &x, &y) == -1)
		return (-1);
	if ((new = (t_room*)malloc(sizeof(t_room))) == NULL)
		ft_error("ERROR");
	while (*lem && (*lem)->next)
		*lem = (*lem)->next;
	new->previous = *lem;
	new->next = NULL;
	new->ant = NULL;
	new->x = x;
	new->y = y;
	new->links = NULL;
	new->name = ft_strsub(str, 0, ft_char_index(str, ' '));
	new->spec = spec;
	if (*lem)
		(*lem)->next = new;
	else
		*lem = new;
	ft_putbuf_endl(buf, str);
	return (0);
}

void	ft_link(t_room **lem, t_room **in)
{
	t_room	**new;
	int		i;

	i = 0;
	if ((*lem)->links != NULL)
		while ((*lem)->links[i] != NULL)
			i++;
	if ((new = (t_room**)malloc(sizeof(t_room*) * (i + 2))) == NULL)
		ft_error("ERROR");
	i = 0;
	while ((*lem)->links != NULL && (*lem)->links[i] != NULL)
	{
		new[i] = (*lem)->links[i];
		i++;
	}
	new[i] = *in;
	new[i + 1] = NULL;
	free((*lem)->links);
	(*lem)->links = new;
}

int		ft_add_link(char *str, t_room **lem, t_buf *buf)
{
	t_room	*name1;
	t_room	*name2;
	char	*name;

	name1 = NULL;
	name2 = NULL;
	name = ft_strsub(str, 0, ft_char_index(str, '-'));
	ft_rewind(lem);
	while (*lem)
	{
		if (ft_strcmp((*lem)->name, name) == 0)
			name1 = *lem;
		else if (!ft_strcmp((*lem)->name, str + ft_char_index(str, '-') + 1))
			name2 = *lem;
		if ((*lem)->next == NULL)
			break ;
		*lem = (*lem)->next;
	}
	ft_strdel(&name);
	if (name1 == NULL || name2 == NULL)
		return (-1);
	ft_link(&name1, &name2);
	ft_link(&name2, &name1);
	ft_putbuf_endl(buf, str);
	return (0);
}
