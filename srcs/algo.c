/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:57:00 by youngpar          #+#    #+#             */
/*   Updated: 2022/04/11 18:32:06 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	smallest(t_deques *deq)
{
	if (deq->a.size == 1)
		return ;
	if (deq->a.size == 3)
	{
		if (front(&deq->a) == max(&deq->a))
			ra(deq);
		else if (second(&deq->a) == max(&deq->a))
			rra(deq);
	}
	if (front(&deq->a) > second(&deq->a))
		sa(deq);
}

static void	smaller(t_deques *deq)
{
	while (deq->b.size < 2)
	{
		if (front(&deq->a) == deq->ordered[1]
			|| front(&deq->a) == deq->ordered[deq->ordered[0]])
			pb(deq);
		else
			ra(deq);
	}
	smallest(deq);
	while (!empty(&deq->b))
		pa(deq);
	if (front(&deq->a) == max(&deq->a))
		ra(deq);
	else
	{
		sa(deq);
		ra(deq);
	}
}

void	ab(t_deques *deq)
{
	int	cnt;
	int	size;
	int	pivot;
	int	pivot2;

	cnt = 0;
	size = deq->ordered[0];
	while (deq->a.size)
	{
		pivot = pivoting(deq, cnt);
		pivot2 = pivoting(deq, \
				cnt + (int)(0.000000053 * size * size + 0.03 * size + 14.5));
		if (front(&deq->a) <= pivot)
			cnt += pb(deq);
		else if (pivot < front(&deq->a) && front(&deq->a) <= pivot2)
		{
			cnt += pb(deq);
			rb(deq);
		}
		else
			ra(deq);
	}
	ba(deq);
}

void	ba(t_deques *deq)
{
	int	pivot;

	while (deq->b.size)
	{
		pivot = max(&deq->b);
		if (find(&deq->b, pivot) == 1 && front(&deq->b) > back(&deq->b))
			sb(deq);
		else if (find(&deq->b, pivot) <= (int)deq->b.size / 2)
		{
			while (front(&deq->b) != pivot)
			{
				if (second(&deq->b) == pivot && front(&deq->b) > back(&deq->b))
					sb(deq);
				else
					rb(deq);
			}
		}
		else
		{
			while (front(&deq->b) != pivot)
				rrb(deq);
		}
		pa(deq);
	}
}

void	push_swap(t_deques *deq)
{
	if (is_sorted(&deq->a, A))
		return ;
	if (deq->ordered[SIZE] <= 3)
		smallest(deq);
	else if (deq->ordered[SIZE] <= 5)
		smaller(deq);
	else
		ab(deq);
}
