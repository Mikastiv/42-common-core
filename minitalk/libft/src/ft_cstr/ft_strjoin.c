/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:35:02 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/13 15:11:37 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = malloc(size * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, size * sizeof(char));
	ft_strlcat(newstr, s2, size * sizeof(char));
	return (newstr);
}
