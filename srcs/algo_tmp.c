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