/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:41:07 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/24 16:15:57 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str_foreach(char *s, void(*f)(char))
{
	while (*s)
	{
		f(*s);
		++s;
	}
}
