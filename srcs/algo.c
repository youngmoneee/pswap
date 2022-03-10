#include "../include/push_swap.h"

int		*lis(t_deque *deq)
{
	int 	*ret;

	ret = (int *)malloc(sizeof(int) * (deq->size + 1));
	if (!ret)
		return (0);
	return (0);
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

/*
void	quick_a(t_deques *deq, int start, int end)
{
	int median;
	int cnt;
	int racnt;
	int pbcnt;

	median = (start + end) / 2;
	cnt = deq->a.size;
	racnt = 0;
	pbcnt = 0;
	if (end - start == 1)
		return ;
	while (cnt--)
	{
		if (deq->ordered[median] <= front(&deq->a))
		{
			ra(deq);
			racnt++;
		}
		else
		{
			pb(deq);
			pbcnt++;
		}
	}
	while(racnt--)
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
	//quick_a(deq, median, end);
	//smallest(deq);
	quick_a(deq, median + 1, end);
	quick_b(deq, start, median - 1);
}

void	quick_b(t_deques *deq, int start, int end)
{
	int median;
	int cnt;
	int rbcnt;

	median = (start + end) / 2;
	cnt = deq->b.size;
	rbcnt = 0;
	if (deq->b.size == 1)
	{
		pa(deq);
		return ;
	}
	while (--cnt)
	{
		if (deq->ordered[median] <= front(&deq->b))
		{
			rb(deq);
			rbcnt++;
		}
		else
		{
			pa(deq);
		}
	}
	while(rbcnt--)
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
	quick_a(deq, start, median - 1);
	quick_b(deq, median + 1, end);
}
*/

void	ab(t_deques deq, )

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
	//else
		//quick_a(deq, 1, deq->ordered[SIZE]);
		//quick_b(deq, 1, deq->ordered[SIZE]);
}