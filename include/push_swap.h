/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:43:50 by youngpar          #+#    #+#             */
/*   Updated: 2022/03/10 19:33:47 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

# define ERRORCODE	10987654321
# define TRUE		1
# define FALSE		0
# define A			0
# define B			1
# define SIZE		0
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef unsigned int	t_u;
typedef long long		t_ll;
typedef unsigned int 	t_bool;
typedef struct s_deque	t_deque;
typedef struct s_node	t_node;
typedef struct s_deques t_deques;

struct s_node
{
	int		val;
	t_node	*next;
	t_node	*prev;
};

struct s_deque
{
	t_u		size;
	t_node	front;
	t_node	back;
};

struct s_deques
{
	int 	*ordered;
	t_deque	a;
	t_deque	b;
};

/*
 * Program Method
 */

t_bool	sa(t_deques *deq);
t_bool	sb(t_deques *deq);
t_bool	pa(t_deques *deq);
t_bool	pb(t_deques *deq);
t_bool	ra(t_deques *deq);
t_bool	rb(t_deques *deq);
t_bool	rra(t_deques *deq);
t_bool	rrb(t_deques *deq);

/*
 * util.c
 */
t_bool	is_space(char c);
void	init_deq(t_deque *deq);
void	error_exit(t_deques* deqs, char* msg);
void	print_error(char* msg);
t_bool	check_sort(int* arr);

/*
 * parse.c
 */
//int*	arr_alloc(int argc, char **argv);
t_bool	parse_int(int argc, char **argv, int **arr);
int 	cnt_int(char *str);

/*
 * algorithm
 */

void	push_swap(t_deques *deq);

/*
 * deque.c
 */
t_bool	push_front(t_deque *deq, int value);
t_bool	push_back(t_deque *deq, int value);
int 	pop_front(t_deque *deq);
int 	pop_back(t_deque *deq);
int		front(t_deque *deq);
int 	back(t_deque *deq);
int 	second(t_deque *deq);
t_bool 	empty(t_deque *deq);
int 	max(t_deque *deq);
int 	min(t_deque *deq);

/*
 * optimizing	- No plan
 */
t_bool	is_sorted(t_deque *deq);
void	quick_a(t_deques *deq, int start, int end);
void	quick_b(t_deques *deq, int start, int end);
int		median(t_deque *deq);
void	ab(t_deques *deq, int size);
void	ba(t_deques *deq, int size);

//int		*lis(t_deque *deq);

#endif
