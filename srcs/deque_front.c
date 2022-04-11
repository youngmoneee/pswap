/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_front.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:05:37 by youngpar          #+#    #+#             */
/*   Updated: 2022/03/02 01:32:34 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	push_front(t_deque *deq, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (FALSE);
	new->val = value;
	deq->size++;
	if (deq->front.next == &deq->back)
	{
		new->prev = &deq->front;
		deq->front.next = new;
		new->next = &deq->back;
		deq->back.prev = new;
		return (TRUE);
	}
	deq->front.next->prev = new;
	new->next = deq->front.next;
	deq->front.next = new;
	new->prev = &deq->front;
	return (TRUE);
}

int	pop_front(t_deque *deq)
{
	t_node	*tmp;
	int		ret;

	deq->size--;
	tmp = deq->front.next;
	if (!deq->size)
	{
		deq->front.next = &deq->back;
		deq->back.prev = &deq->front;
	}
	else
	{
		deq->front.next = tmp->next;
		tmp->next->prev = &deq->front;
	}
	ret = tmp->val;
	free(tmp);
	return (ret);
}

int	front(t_deque *deq)
{
	int	ret;

	ret = deq->front.next->val;
	return (ret);
}

int	second(t_deque *deq)
{
	int	ret;

	ret = deq->front.next->next->val;
	return (ret);
}

int	find(t_deque *deq, int value)
{
	int		idx;
	t_node	*cur;

	idx = 0;
	cur = deq->front.next;
	while (cur != &deq->back)
	{
		if (cur->val == value)
			return (idx);
		idx++;
		cur = cur->next;
	}
	return (-1);
}
