/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_add_trace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:06:34 by huakang           #+#    #+#             */
/*   Updated: 2018/02/08 19:06:38 by huakang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void add_one_trace(t_trace *trace, t_trace_set *set_last, t_room *room)
{
  set_last->last->next = copy_trace(trace, room);
  display_one_trace(set_last->last->trace);
  set_last->last = set_last->last->next;
  display_one_trace(set_last->last->trace);
}

t_trace_set *copy_trace(t_trace *trace, t_room *room)
{
  t_trace *tmp;
  t_trace *copy;
  t_trace *tmp_copy;
  t_trace_set *trace_set;

  tmp = trace;
  copy = new_trace(tmp->room);
  tmp_copy = copy;
  tmp = tmp->next;
  while (tmp)
  {
    tmp_copy->next = new_trace(tmp->room);
    tmp_copy = tmp_copy->next;
    tmp = tmp->next;
  }
  tmp_copy->next = new_trace(room);
  tmp_copy = tmp_copy->next;
  trace_set = new_trace_set(tmp_copy);
  return (trace_set);
}

t_trace_set *new_trace_set(t_trace *trace)
{
  t_trace_set *trace_set;

  trace_set = (t_trace_set*)malloc(sizeof(t_trace_set));
  trace_set->trace = trace;
  trace_set->last = trace_set;
  trace_set->next = NULL;
  return (trace_set);
}

t_trace *new_trace(t_room *room)
{
  t_trace *new;

  new = (t_trace*)malloc(sizeof(t_trace));
  new->room = room;
  new->next = NULL;
  return (new);
}
