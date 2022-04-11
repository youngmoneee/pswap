/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:41:46 by youngpar          #+#    #+#             */
/*   Updated: 2022/04/11 17:37:15 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_deques	deqs;
	int			*arr;
	int			i;

	init_deq(&deqs.a);
	init_deq(&deqs.b);
	if (!parse_int(argc, argv, &deqs.ordered))
		error_exit(&deqs, "Error\n");
	arr = deqs.ordered;
	i = 0;
	while (++i <= arr[0])
		push_back(&deqs.a, arr[i]);
	if (!check_sort(arr))
		error_exit(&deqs, "Error\n");
	push_swap(&deqs);
	free(arr);
	return (0);
}
