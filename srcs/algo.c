#include "../include/push_swap.h"

int		*lis(t_deque *deq)
{
	int 	*ret;

	ret = (int *)malloc(sizeof(int) * (deq->size + 1));
	if (!ret)
		return (0);
	return (0);
}

int		median(t_deque *deq)
{
	int	*arr;
	int	idx;

	arr = (int *)malloc(sizeof(int) * deq->size);
	if (!arr)
		return (0);
	idx = -1;
	while (++idx < deq->size)
	{
		arr[idx] = pop_front(deq);
		push_back(deq, arr[idx]);
	}
	check_sort(arr);
	idx = arr[idx / 2];
	free(arr);
	return (idx);
}

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
		if (front(&deq->a) == deq->ordered[1]
		|| front(&deq->a) == deq->ordered[deq->ordered[0]])
			pb(deq);
		else
			ra(deq);
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

void	ab(t_deques *deq, int size)
{
	int	cnt;
	int	racnt;
	int	pbcnt;
	int	pivot;
	int	tmp;

	if (&deq->a.size <= (t_u)3)
	{
		smallest(deq);
		return ;
	}
	cnt = deq->a.size;
	pivot = median(&deq->a);
	racnt = 0;
	pbcnt = 0;

	while (size--)
	{
		if (front(&deq->a) > pivot)
			racnt += ra(deq);
		else
			pbcnt += pb(deq);
	}
	tmp = racnt;
	while (tmp--)
		rra(deq);
	printf("-------- A ---------\n");
	for (t_u i = 0; i < deq->a.size; i++) {
		printf("%d\n", front(&deq->a));
		push_back(&deq->a, pop_front(&deq->a));
	}
	printf("\n-------- B ---------\n");
	for (t_u i = 0; i < deq->b.size; i++) {
		printf("%d\n", front(&deq->b));
		push_back(&deq->b, pop_front(&deq->b));
	}
	ab(deq, racnt);
	ba(deq, pbcnt);
}

void	ba(t_deques *deq, int size)
{
	int cnt;
	int rbcnt;
	int pacnt;
	int pivot;
	int tmp;

	if (size == 1)
	{
		pa(deq);
		return ;
	}
	cnt = size;
	pivot = median(&deq->b);
	rbcnt = 0;
	pacnt = 0;
	while (cnt--)
	{
		if (front(&deq->a) < pivot)
			rbcnt += rb(deq);
		else
			pacnt += pa(deq);
	}
	tmp = rbcnt;
	while (tmp--)
		rrb(deq);
	printf("-------- A ---------\n");
	for (t_u i = 0; i < deq->a.size; i++) {
		printf("%d\n", front(&deq->a));
		push_back(&deq->a, pop_front(&deq->a));
	}
	printf("\n-------- B ---------\n");
	for (t_u i = 0; i < deq->b.size; i++) {
		printf("%d\n", front(&deq->b));
		push_back(&deq->b, pop_front(&deq->b));
	}
	ab(deq, pacnt);
	ba(deq, rbcnt);
}

void	push_swap(t_deques *deq)
{
	if (is_sorted(&deq->a))
		return ;
	if (FALSE)
		smaller(deq);
	//if (deq->ordered[SIZE] <= 3)
	//	smallest(deq);
	//else if (deq->ordered[SIZE] <= 5)
	//	smaller(deq);
	else
		ab(deq, deq->a.size);
}
