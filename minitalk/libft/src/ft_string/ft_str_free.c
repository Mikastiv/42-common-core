/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:53:31 by mleblanc          #+#    #+#             */
/*   Updated: 2021/08/30 19:49:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_str_free(t_string *str)
{
	if (str)
	{
		free(str->data);
		str->data = NULL;
		str->len = 0;
		str->cap = 0;
	}
}
