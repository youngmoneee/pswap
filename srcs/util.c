#include "../include/push_swap.h"

void	print_error(char *msg)
{
	while(*msg)
		write(2, msg++, 1);
	exit(1);
}

t_bool	is_space(char c)
{
	if (c == 0x20
	|| c == 0x09
	|| c == 0x0a
	|| c == 0x0b
	|| c == 0x0c
	|| c == 0x0d)
		return (TRUE);
	return (FALSE);
}

void	init_deq(t_deque *deq)
{
	deq->front.next = &deq->back;
	deq->front.prev = 0;
	deq->back.prev = &deq->front;
	deq->back.next = 0;
	deq->size = 0;
}

void	error_exit(t_deques *deqs, char *msg)
{
	while (deqs->a.size)
		pop_front(&deqs->a);
	while (deqs->b.size)
		pop_front(&deqs->b);
	if (deqs->ordered)
		free(deqs->ordered);
	print_error(msg);
}

t_bool	check_sort(int *arr)
{
	int 	i;
	int		j;
	int 	tmp;

	i = -1;
	while (++i < arr[SIZE])
	{
		j = 1;
		while (++j <= arr[SIZE] - i)
			if (arr[j] == arr[j - 1])
				return (FALSE);
			else if (arr[j - 1] > arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
	}
	return (TRUE);
}