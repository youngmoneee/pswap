/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:05:37 by youngpar          #+#    #+#             */
/*   Updated: 2022/03/02 01:32:34 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	push_back(t_deque *deq, int value)
{
	t_node 	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (FALSE);
	new->val = value;
	deq->size++;
	if (deq->front.next == &deq->back || deq->size == 1) {
		new->prev = &deq->front;
		deq->front.next = new;
		new->next = &deq->back;
		deq->back.prev = new;
		return (TRUE);
	}
	deq->back.prev->next = new;
	new->prev = deq->back.prev;
	deq->back.prev = new;
	new->next = &deq->back;
	return (TRUE);
}

int 	pop_back(t_deque *deq)
{
	t_node	*tmp;
	int		ret;

	deq->size--;
	tmp = deq->back.prev;
	if (!deq->size)
	{
		deq->back.prev = tmp->prev;
		deq->front.next = &deq->back;
	}
	else
	{
		deq->back.prev = tmp->prev;
		tmp->prev->next = &deq->back;
	}
	ret = tmp->val;
	free(tmp);
	return (ret);
}

int 	back(t_deque *deq)
{
	int ret;

	ret = deq->back.prev->val;
	return (ret);
}

t_bool	empty(t_deque *deq)
{
	if (deq->size)
		return (FALSE);
	return (TRUE);
}