/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:20:28 by mleblanc          #+#    #+#             */
/*   Updated: 2021/10/18 20:21:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strarr_last(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] && arr[i + 1])
		++i;
	return (arr[i]);
}
