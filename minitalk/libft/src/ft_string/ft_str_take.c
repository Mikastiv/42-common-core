/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_take.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:20:57 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/16 22:04:33 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_take(t_string *str)
{
	char		*ret;

	ret = str->data;
	str->data = NULL;
	ft_str_free(str);
	return (ret);
}
