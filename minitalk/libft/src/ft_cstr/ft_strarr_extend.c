/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_extend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:21:06 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/13 15:09:25 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strarr_extend(char **arr, char *back_str)
{
	size_t	i;
	char	**new;

	i = ft_strarr_size(arr);
	new = malloc((i + 2) * sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		new[i] = arr[i];
		arr[i] = NULL;
		++i;
	}
	new[i++] = back_str;
	new[i] = NULL;
	ft_strarr_free(arr);
	return (new);
}
