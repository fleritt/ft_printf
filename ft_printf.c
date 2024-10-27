/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:15:23 by marvin            #+#    #+#             */
/*   Updated: 2024/10/27 11:15:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char const str, va_list args)
{
	int i;
	if (str == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (str == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (str == 'd' || str == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	if (str == 'u')
		return (ft_print_unsig(va_arg(args, unsigned int)));
	if (str == 'x')
		return (ft_print_hex(va_arg(args, unsigned int)));
	if (str == '%')
		return (ft_print_char('%'));
}
int	ft_printf(char const *str, ...)
{
    va_list	args;
    int		i;
	int		size;

	i = 0;
	size = 0;
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			size += ft_check_format(str[i], args);
		}
		else
		{
			size += ft_print_char(str[i]);
		}
		i++;
	}
	va_end(args);
	return (size);
}

int main (void)
{
	unsigned int i;

	i = 23424;
	printf("%x\n", i);
	ft_printf("%x", i);
	return (0);
}