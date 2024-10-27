/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:23:28 by marvin            #+#    #+#             */
/*   Updated: 2024/10/27 16:23:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_hex(unsigned int n)
{
   
	if (n >= 16)
	{
		ft_convert_hex(n / 16);
		ft_convert_hex(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_char(n + '0');
		else
			ft_print_char(n - 10 + 'a');
	}
}

int	ft_print_hex(unsigned int n)
{
	int	i;

    if (n == 0)
		return (ft_print_char('0'));
	else
		ft_convert_hex(n);
	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}
