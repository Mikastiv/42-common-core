/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_new_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:53:57 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/15 16:56:11 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_string	*ft_str_dup(t_string *dst, const char *cstr)
{
	char	*copy;

	copy = ft_strdup(cstr);
	if (!copy)
		return (false);
	ft_str_free(dst);
	dst->data = copy;
	dst->len = ft_strlen(copy);
	dst->cap = dst->len + 1;
	return (dst);
}
