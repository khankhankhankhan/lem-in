/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:23:23 by hkang             #+#    #+#             */
/*   Updated: 2018/02/05 10:23:25 by hkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

//# include "libft.h"
# include "get_next_line.h"
# include "print/ft_printf.h"

typedef struct s_connect
{
	char *name;
	struct s_connect *next;
} t_connect;

typedef struct s_room
{
	char *name;
	//int  *empty;
	int  isstart;
	int  isend;
	t_connect *connect;
	t_connect *last_con;
	struct s_room *next;
} t_room;

typedef struct s_trace
{
	char *room;
	struct s_trace *next;
} t_trace;

typedef struct s_trace_set
{
	t_trace *trace;
	struct s_trace_set *next;
	struct s_trace_set *last;
} t_trace_set;

typedef struct s_ant
{
	char **rout;

} t_ant;

typedef struct s_lem
{
	int ant_num;
	t_trace_set *step;
	t_room *room;
	t_room *last;
	t_room *start;
	t_room *end;
	t_ant **ant;
	int error;
} t_lem;

void lem_add_room(char **split, t_lem *lem);
void lem_add_connection(t_room *room1, t_room *room2);

int ft_room_check(char **src);
int ft_connect_check(char **src, t_lem *lem);

void lem_display_room(t_room *room);
void lem_display(t_lem *lem);

void ft_free_doubulechar(char **src, int n);
t_lem *lem_init(t_lem *lem);

void get_data_in(char *line, t_lem *lem);
void lem_read(t_lem *lem);
#endif
