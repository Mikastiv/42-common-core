#include "libft.h"
#include "pswap.h"
#include "parse.h"
#include <stdlib.h>

void	clean_and_exit(t_pswap *stacks)
{
	delete_stack(stacks->a);
	delete_stack(stacks->b);
	delete_stack(stacks->c);
	exit(0);
}

void	rank(t_stack *a, t_stack *c)
{
	int	i;

	i = 0;
	while (i < c->size)
	{
		a->data[i] = (c->size - 1) - find_number(c, a->data[i]);
		++i;
	}
}

int	stack_size(int argc, char **argv)
{
	int		size;
	char	**args;

	size = 0;
	if (argc > 2)
		return (argc - 1);
	args = ft_split(argv[1], ' ');
	if (!args)
		return (-1);
	while (args[size])
		++size;
	free_table(args);
	return (size);
}

void	quit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_pswap	stacks;
	int		size;

	if (argc < 2)
		return (0);
	size = stack_size(argc, argv);
	if (size < 0)
		quit_error();
	stacks.a = new_stack(size);
	stacks.b = new_stack(size);
	stacks.c = new_stack(size);
	if (!stacks.a || !stacks.b || !stacks.c)
		clean_and_exit(&stacks);
	if (!parse_args(argc, argv, stacks.a))
		clean_and_exit(&stacks);
	copy_stack(stacks.c, stacks.a);
	quicksort(stacks.c);
	rank(stacks.a, stacks.c);
	if (size < 6)
		sort_small(&stacks);
	else
		sort_big(&stacks);
	clean_and_exit(&stacks);
}
