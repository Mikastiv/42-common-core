/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:09:27 by mleblanc          #+#    #+#             */
/*   Updated: 2021/10/17 02:34:53 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, size_t start, size_t len)
{
	size_t	strlen;
	size_t	size;
	char	*substr;

	strlen = ft_strlen(s);
	size = 1;
	if (strlen > start)
		size += ft_strnlen(s + start, len);
	else
		start = strlen;
	substr = ft_calloc(size, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, size * sizeof(char));
	return (substr);
}
