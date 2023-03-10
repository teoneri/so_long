/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:05:02 by mneri             #+#    #+#             */
/*   Updated: 2022/10/21 12:05:04 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_p(const char*s, const void *l)
{
	uintptr_t	k;

	while (*s == 'p')
	{
		k = (uintptr_t)l;
		write(1, "0x", 2);
		ft_putuinptr(k);
		s++;
	}
	return (0);
}
