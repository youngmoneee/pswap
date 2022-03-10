/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:41:46 by youngpar          #+#    #+#             */
/*   Updated: 2022/03/02 01:36:28 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_deques	deqs;
	int 		*arr;

	init_deq(&deqs.a);
	init_deq(&deqs.b);
	if (!parse_int(argc, argv, &deqs.ordered))
		error_exit(&deqs, "Error\n");
	arr = deqs.ordered;
	/*
	 * 스택 A에 입력값 넣음
	 */
	for (int i = 1; i <= arr[0]; i++)
		push_back(&deqs.a, arr[i]);
	/*
	 * 선정렬
	 */
	if (!check_sort(arr))
		error_exit(&deqs, "Error\n");
	//if (is_sorted(&deqs.a))
	//	printf("정렬 여부 o\n");
	//else
	//	printf("정렬 여부 x\n");
	push_swap(&deqs);
	//for (int i = 0; i < arr[0]; i++)
	//	printf("%d\n", pop_front(&deqs.a));
	free(arr);
	return (0);
}