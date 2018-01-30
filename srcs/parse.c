/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		ft_check_errorx(char *str)
{
	int		x;
	char	*tmp;

	x = ft_atoi(str);
	tmp = ft_itoa(x);
	if (ft_strcmp(str, tmp) != 0)
		ft_error("ERROR");
	ft_strdel(&tmp);
	return (x);
}

int		ft_parse_name(char *str, int *x, int *y)
{
	int		i;
	char	*tmp;

	if ((i = ft_char_index(str, ' ')) < 1)
		return (-1);
	i += 1;
	*x = ft_atoi(str + i);
	tmp = ft_itoa(*x);
	if (ft_strncmp(str + i, tmp, ft_char_index(str + i, ' ')) != 0)
		*x = -1;
	ft_strdel(&tmp);
	if (*x < 0)
		return (-1);
	if ((i += ft_char_index(str + i, ' ')) == -1)
		return (-1);
	i += 1;
	*y = ft_atoi(str + i);
	tmp = ft_itoa(*y);
	if (ft_strcmp(str + i, tmp) != 0)
		*y = -1;
	ft_strdel(&tmp);
	if (*y < 0)
		return (-1);
	return (0);
}

int		ft_choose(char *str, t_room **lem, t_buf *buf)
{
	char	*tmp;
	int		ret;

	ret = -1;
	if (str[0] == '#' && str[1] != '#')
		return (ft_putbuf_endl(buf, str));
	else if (ft_strncmp(str, "##", 2) == 0)
	{
		ft_putbuf_endl(buf, str);
		if (ft_strcmp(str, "##end") != 0 && ft_strcmp(str, "##start") != 0)
			return (0);
		if ((ret = get_next_line(0, &tmp)) == -1)
			ft_error("ERROR");
		if (ft_strcmp(str, "##start") == 0)
			ret = ft_add_room(tmp, lem, 1, buf);
		else if (ft_strcmp(str, "##end") == 0)
			ret = ft_add_room(tmp, lem, 2, buf);
		ft_strdel(&tmp);
	}
	else if (ft_char_index(str, '-') == -1)
		ret = ft_add_room(str, lem, 0, buf);
	else if (ft_char_index(str, '-') != -1)
		ret = ft_add_link(str, lem, buf);
	return (ret);
}

void	ft_start_end(t_room **lem, int x)
{
	int		start;
	int		end;
	t_room	*ptr;

	start = 0;
	end = 0;
	ft_rewind(lem);
	ptr = *lem;
	while (*lem)
	{
		if ((*lem)->spec == 1)
		{
			(*lem)->ant = ft_add_ants(x);
			start++;
		}
		else if ((*lem)->spec == 2)
			end++;
		if ((*lem)->next == NULL)
			break ;
		*lem = (*lem)->next;
	}
	if (end != 1 || start != 1)
		ft_error("ERROR");
	*lem = ptr;
}

t_room	*ft_parse(t_buf *buf)
{
	char	*str;
	t_room	*lem;
	int		x;
	int		ret;
	int		gnl;

	lem = NULL;
	get_next_line(0, &str);
	if ((x = ft_check_errorx(str)) <= 0)
		ft_error("Error");
	ft_putbuf_endl(buf, str);
	ft_strdel(&str);
	while ((gnl = get_next_line(0, &str)) > 0)
	{
		ret = ft_choose(str, &lem, buf);
		ft_strdel(&str);
		if (ret == -1)
			break ;
	}
	ft_strdel(&str);
	if (gnl == -1)
		ft_error("ERROR");
	ft_start_end(&lem, x);
	ft_rewind(&lem);
	return (lem);
}
