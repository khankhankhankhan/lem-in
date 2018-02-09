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

#include "lem-in"

t_trace_set *add_one_trace(t_trace_set *trace_set, t_trace *trace)
{

}

t_trace_set *new_trace_set(t_trace *trace, t_trace *last)
{
  t_trace_set *new;

  new = (t_trace_set*)malloc(sizeof(t_trace_set));
  new->trace = trace;
  new->last = last;
  new->next = NULL;
  return (new);
}
