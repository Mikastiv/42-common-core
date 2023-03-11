/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:57:41 by mleblanc          #+#    #+#             */
/*   Updated: 2021/10/16 19:04:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ntoa_base(char *b, uint64_t n, size_t len, const char *base)
{
	uint64_t	radix;

	radix = (uint64_t)ft_strlen(base);
	while (len > 0)
	{
		b[--len] = base[n % radix];
		n /= radix;
	}
}

char	*ft_ultoa_base(uint64_t n, const char *base)
{
	char	*ret;
	size_t	len;
	size_t	radix;

	radix = ft_strlen(base);
	len = ft_unumlen(n, (uint64_t)radix);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_ntoa_base(ret, n, len, base);
	return (ret);
}
