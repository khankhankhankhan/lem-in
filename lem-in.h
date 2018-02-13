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
	struct s_room *room;
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
	t_room *room;
	struct s_trace *next;
} t_trace;

typedef struct s_trace_set
{
	t_trace *trace;
	struct s_trace_set *last;
	struct s_trace_set *next;
} t_trace_set;

typedef struct s_ant
{
	char **rout;

} t_ant;

typedef struct s_lem
{
	int ant_num;
	t_trace_set *step;
	t_trace **trace;
	t_room *room;
	t_room *last;
	t_room *start;
	t_room *end;
	t_ant **ant;
	int index;
	int error;
} t_lem;

void lem_add_room(char **split, t_lem *lem);
t_connect *new_connect(t_room *room);
void lem_add_connection(t_room *room1, t_room *room2);

void add_step(t_lem *lem);
void append_step(t_trace *trace, t_room *room);

void add_one_trace(t_trace *trace, t_trace_set *set_last, t_room *room);
t_trace_set *copy_trace(t_trace *trace, t_room *room);
t_trace_set *new_trace_set(t_trace *trace);
t_trace *new_trace(t_room *room);

int ft_room_check(char **src);
int ft_connect_check(char **src, t_lem *lem);
int check_in_trace(t_room *last_room, t_trace_set *trace_set);
int check_in_steps(t_room *last_room, t_trace_set *step);

void lem_display_room(t_room *room);
void lem_display(t_lem *lem);
void lem_trace_display(t_lem *lem);
void display_one_trace(t_trace *trace);

void lem_slove(t_lem *lem);
void lem_find_trace(t_lem *lem);
void remove_top_trace(t_trace_set *trace_set);
void get_trace(t_trace_set *trace_set, t_lem *lem);
t_room *get_last_room(t_trace *trace);

void ft_free_doubulechar(char **src, int n);
void free_one_trace_set(t_trace_set *trace_set);
void free_all_trace_set(t_trace_set *trace_set);

t_lem *lem_init(t_lem *lem);
t_trace_set *trace_set_init(t_lem *lem);
void lem_trace_int(t_lem *lem);
void lem_step_init(t_lem *lem);

void get_data_in(char *line, t_lem *lem);
void lem_read(t_lem *lem);
#endif
