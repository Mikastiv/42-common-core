/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:52:33 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/15 15:37:57 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "parse.h"
#include <limits.h>
#include <stdlib.h>

static bool	is_not_digit(char c)
{
	return (!ft_isdigit(c));
}

static int	*lst_find(t_list *lst, int n)
{
	int	*ptr;

	while (lst)
	{
		ptr = (int *)lst->content;
		if (*ptr == n)
			return (ptr);
		lst = lst->next;
	}
	return (NULL);
}

static bool	add_elem(t_stack *s, t_list **lst, char *num)
{
	t_list	*tmp;
	long	*n;

	n = (long *)ft_calloc(1, sizeof(long));
	if (!n)
		return (false);
	*n = ft_atol(num);
	if (num[0] == '-' || num[0] == '+')
		num++;
	if (lst_find(*lst, (int)*n) || ft_str_any(num, is_not_digit)
		|| *n > (long)INT_MAX || *n < (long)INT_MIN)
	{
		free(n);
		return (false);
	}
	tmp = ft_lstnew(n);
	if (!tmp)
	{
		free(n);
		return (false);
	}
	ft_lstadd_front(lst, tmp);
	push_back(s, *n);
	return (true);
}

static bool	parse_split(char *arg, t_stack *a)
{
	t_list	*lst;
	char	**nums;
	int		i;

	lst = NULL;
	nums = ft_split(arg, ' ');
	if (!nums)
		return (false);
	i = 0;
	while (nums[i])
	{
		if (!add_elem(a, &lst, nums[i]))
		{
			ft_lstclear(&lst, free);
			free_table(nums);
			ft_putendl_fd("Error", 2);
			return (false);
		}
		++i;
	}
	free_table(nums);
	ft_lstclear(&lst, free);
	return (true);
}

bool	parse_args(int argc, char **argv, t_stack *a)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = 1;
	if (argc == 2)
		return (parse_split(argv[1], a));
	while (i < argc)
	{
		if (!add_elem(a, &lst, argv[i]))
		{
			ft_lstclear(&lst, free);
			ft_putendl_fd("Error", 2);
			return (false);
		}
		++i;
	}
	ft_lstclear(&lst, free);
	return (true);
}
