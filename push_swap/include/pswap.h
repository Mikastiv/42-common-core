/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:02:46 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/15 14:37:03 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include "stack.h"

typedef struct s_pswap
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;
}	t_pswap;

void	split_a_lower(t_pswap *s, int mid);
void	split_b_higher(t_pswap *s, int mid);
void	sort_big(t_pswap *s);
void	sort_small(t_pswap *s);
void	sort_b(t_pswap *s);

#endif