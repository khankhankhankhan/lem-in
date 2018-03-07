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
	t_trace *last;
	struct s_trace_set *next;
} t_trace_set;

typedef struct s_lem
{
	int ant_num;
	t_trace_set *step;
	t_trace_set *step_start;
	t_trace_set *trace_set;
	t_trace_set *set_last;
	t_trace **trace;
	t_room *room;
	t_room *last;
	t_room *start;
	t_room *end;
	char *file;
	int index;
	int error;
} t_lem;

void lem_add_room(char **split, t_lem *lem);
t_connect *new_connect(t_room *room);
void lem_add_connection(t_room *room1, t_room *room2);

void add_step(t_lem *lem);
void append_step(t_trace *trace, t_room *room);

void add_one_trace(t_trace_set *trace_set, t_trace_set *set_last, t_lem *lem);
t_trace_set *copy_trace(t_trace_set	*set_last, t_trace *trace, t_room *room);
t_trace_set *new_trace_set(t_trace *trace);
t_trace *new_trace(t_room *room);

int		ft_room_check(char *line, t_lem *lem);
int		ft_connect_check(char *line, t_lem *lem);
int check_in_trace(t_room *last_room, t_trace_set *trace_set);
int check_in_steps(t_room *last_room, t_trace_set *step);
int check_one_trace(t_lem *lem);
int check_step_full(t_trace_set *step, t_room *room);

int  lem_display_useage(void);
int lem_display_format(void);
int lem_display_error(void);
void	lem_display_room(t_trace **trace, int i, int *flag);
void lem_final_display(t_lem *lem);

//void lem_slove(t_lem *lem);
void lem_find_trace(t_lem *lem);
void	get_trace(t_trace_set *trace_set, t_lem *lem);
t_trace *get_last_trace(t_trace *trace);
t_trace_set *get_step(t_trace_set	*step, t_trace *trace);

void lem_free_all(t_lem *lem);
void ft_free_doubulechar(char **src, int n);
void free_one_trace_set(t_trace_set *trace_set);
void free_all_trace_set(t_trace_set *trace_set);
void free_room(t_lem *lem);

t_lem *lem_init(t_lem *lem);
void trace_set_init(t_lem *lem);
void lem_trace_int(t_lem *lem);
void lem_step_init(t_lem *lem);
t_trace_set	*step_init(t_lem *lem);

//void get_data_in(char *line, t_lem *lem);
void lem_get_room(char **line, t_lem *lem);
void	lem_get_link(char **line, t_lem *lem);
int  ft_count_char(char *src, char c);
void lem_read(t_lem *lem);
void get_start_end_room(char *line, char *temp, t_lem *lem);
void ft_appendline(t_lem *lem, char *src);
int check_new_line(char **line, t_lem *lem);
void get_number(t_lem *lem);
void check_all_digit(char *src, t_lem *lem);
#endif
