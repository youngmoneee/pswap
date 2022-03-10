#include "../include/push_swap.h"

void	sa(t_deques *deq)
{
	int 	first;
	int 	second;

	if (deq->a.size < 2)
		return ;
	first = pop_front(&deq->a);
	second = pop_front(&deq->a);
	push_front(&deq->a, first);
	push_front(&deq->a, second);
	write(1, "sa\n", 3);
}

void	sb(t_deques *deq)
{
	int 	first;
	int 	second;

	if (deq->b.size < 2)
		return ;
	first = pop_front(&deq->b);
	second = pop_front(&deq->b);
	push_front(&deq->b, first);
	push_front(&deq->b, second);
	write(1, "sb\n", 3);
}

void	pa(t_deques *deq)
{
	if (!deq->b.size)
		return ;
	push_front(&deq->a, pop_front(&deq->b));
	write(1, "pa\n", 3);
}

void	pb(t_deques *deq)
{
	if (!deq->a.size)
		return ;
	push_front(&deq->b, pop_front(&deq->a));
	write(1, "pb\n", 3);
}

int		max(t_deque *deq)
{
	int 	max_val;
	t_node	*curr;

	curr = deq->front.next;
	max_val = curr->val;
	while (curr != &deq->back)
	{
		if (max_val < curr->val)
			max_val = curr->val;
		curr = curr->next;
	}
	return (max_val);
}