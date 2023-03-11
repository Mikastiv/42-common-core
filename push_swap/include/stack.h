/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:30:41 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/14 16:24:28 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

t_stack	*new_stack(int size);
void	delete_stack(t_stack *s);
void	copy_stack(t_stack *dst, t_stack *src);

int		front(t_stack *s);
int		back(t_stack *s);

bool	is_sorted(t_stack *s);
int		find_number(t_stack *s, int n);
int		average(t_stack *s);
int		stack_max(t_stack *s);
int		stack_min(t_stack *s);

void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);
void	push(t_stack *s, int n);
void	push_back(t_stack *s, int n);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *b, t_stack *a);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);
void	rev_rotate_a(t_stack *a);
void	rev_rotate_b(t_stack *b);
void	rev_rotate_ab(t_stack *a, t_stack *b);

void	quicksort(t_stack *s);
bool	contains_smaller(t_stack *s, int max);

#endif
