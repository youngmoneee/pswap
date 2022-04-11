/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:38:57 by youngpar          #+#    #+#             */
/*   Updated: 2022/04/11 17:38:59 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cnt_int(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str)
			ret++;
		while (*str && !is_space(*str))
			str++;
	}
	return (ret);
}

static t_ll	get_nbr(char **str)
{
	t_ll	ret;
	t_ll	sign;

	ret = 0;
	sign = 1;
	if (**str == '+' || **str == '-')
		if (*(*str)++ == '-')
			sign = -1;
	while (**str >= '0' && **str <= '9')
	{
		ret = ret * 10 + *(*str)++ - '0';
		if (ret * sign > INT_MAX || ret * sign < INT_MIN)
			return (ERRORCODE);
	}
	if (**str && !is_space(**str))
		return (ERRORCODE);
	return (ret * sign);
}

static int	*arr_alloc(int argc, char **argv)
{
	int	*ret;
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (++idx < argc)
	{
		if (!cnt_int(argv[idx]))
			return (FALSE);
		cnt += cnt_int(argv[idx]);
	}
	ret = (int *)malloc(sizeof(int) * (cnt + 1));
	if (!ret)
		return (FALSE);
	ret[SIZE] = cnt;
	return (ret);
}

t_bool	parse_int(int argc, char **argv, int **arr)
{
	int		idx;
	int		arr_idx;
	t_ll	check;

	idx = 0;
	arr_idx = 0;
	*arr = arr_alloc(argc, argv);
	if (!*arr)
		return (FALSE);
	while (++idx < argc)
	{
		while (*argv[idx])
		{
			while (*argv[idx] && is_space(*argv[idx]))
				argv[idx]++;
			if (*argv[idx])
			{
				check = get_nbr(&argv[idx]);
				if (check == ERRORCODE)
					return (FALSE);
				(*arr)[++arr_idx] = (int)check;
			}
		}
	}
	return (TRUE);
}

t_bool	is_sorted(t_deque *deq, t_bool flag)
{
	t_node	*curr;
	int		val;

	curr = deq->front.next;
	if (curr == &deq->back)
		return (TRUE);
	val = curr->val;
	curr = curr->next;
	while (curr != &deq->back)
	{
		if (flag == A && val > curr->val)
			return (FALSE);
		else if (flag == B && val < curr->val)
			return (FALSE);
		val = curr->val;
		curr = curr->next;
	}
	return (TRUE);
}
