/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append_cstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:46:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/26 18:57:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static bool	grow_buffer(t_string *str, size_t newsize)
{
	char	*buf;
	size_t	nextcap;

	if (str->cap > LONG_MAX / 2)
		nextcap = LONG_MAX;
	else
		nextcap = str->cap * 2;
	if (newsize < nextcap)
		newsize = nextcap;
	if (!str->data)
	{
		buf = malloc(newsize * sizeof(char));
		*buf = '\0';
	}
	else
		buf = ft_realloc(str->data, str->cap * sizeof(char), newsize * sizeof(char));
	if (!buf)
		return (false);
	str->data = buf;
	str->cap = newsize;
	return (true);
}

t_string	*ft_str_append(t_string *dst, const char *src)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst->cap - dst->len <= src_len)
	{
		if (!grow_buffer(dst, src_len + dst->len + 1))
			return (NULL);
	}
	ft_strlcat(dst->data, src, dst->cap);
	dst->len += src_len;
	return (dst);
}
