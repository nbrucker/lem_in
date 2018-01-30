/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		ft_putbuf_endl(t_buf *buf, char *str)
{
	ft_putbuf(buf, str);
	ft_putbuf(buf, "\n");
	return (0);
}

int		ft_putbuf_int(t_buf *buf, int x)
{
	char	*tmp;

	if ((tmp = ft_itoa(x)) == NULL)
		ft_error("ERROR");
	ft_putbuf(buf, tmp);
	free(tmp);
	return (0);
}

int		ft_putbuf(t_buf *buf, char *str)
{
	char *tmp;

	if ((tmp = ft_strjoin(buf->str, str)) == NULL)
		ft_error("ERROR");
	free(buf->str);
	buf->str = tmp;
	return (0);
}
