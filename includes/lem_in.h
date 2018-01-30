/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:24:15 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/03 10:24:15 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_buf
{
	char	*str;
}				t_buf;

typedef struct	s_ant
{
	int				name;
	int				moved;
	struct s_ant	*next;
	struct s_ant	*previous;
}				t_ant;

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_ant	*ant;
	int				spec;
	int				visited;
	struct s_room	*next;
	struct s_room	*previous;
	struct s_room	**links;
	struct s_room	*path;
	int				best;
}				t_room;

t_room			*ft_parse(t_buf *buf);
int				ft_add_room(char *str, t_room **lem, int spec, t_buf *buf);
int				ft_add_link(char *str, t_room **lem, t_buf *buf);
int				ft_parse_name(char *str, int *x, int *y);
void			ft_sortlink(t_room *lem);
t_ant			*ft_add_ants(int x);
void			ft_path(t_room **lem);
void			ft_removealllink(t_room *lem);
void			ft_removelink(t_room *lem, char *str);
void			ft_algo(t_room *lem, t_buf *buf);
void			ft_rewind(t_room **lem);
int				ft_nbrlinks(t_room *lem);
int				ft_nbrants(t_room *lem);
int				*ft_settab(t_room *lem, int ants);
void			ft_setvisited(t_room *lem);
t_room			*ft_getend(t_room *lem);
t_room			*ft_getstart(t_room *lem);
void			ft_removeminus(t_room *lem);
int				ft_total(t_room *lem, int *tab);
void			ft_redesign(t_room *lem, t_room *in);
void			ft_setpath(t_room *lem);
void			ft_setminus(t_room *lem);
void			ft_setbest(t_room *lem);
t_room			*ft_getnextbest(t_room *lem);
int				ft_searchstart(t_room *lem);
void			ft_restore(t_room *lst, t_room *save);
t_room			*ft_save(t_room *lst);
int				ft_gettotal(t_room *lem);
void			ft_removealone(t_room *lem);
int				ft_putbuf(t_buf *buf, char *str);
int				ft_putbuf_int(t_buf *buf, int x);
int				ft_putbuf_endl(t_buf *buf, char *str);
void			ft_free_save(t_room *lst);

#endif
