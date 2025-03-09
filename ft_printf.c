/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:33:08 by andsoare          #+#    #+#             */
/*   Updated: 2025/03/09 14:45:44 by andsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char spec, va_list ap)
{
	if (spec == 'c')
		return (ft_printchar(va_arg(ap, int)));
	else if (spec == 's')
		return (ft_printstr(va_arg(ap, char *)));
	else if (spec == 'x')
		return (ft_printdigit(va_arg(ap, unsigned int), 16));
	else if (spec == '%')
		return (write(1, "%", 1));
	else if (spec == 'X')
		return (ft_printdigitup(va_arg(ap, unsigned int), 16));
	else if (spec == 'i' || spec == 'd')
		return (ft_printdigit(va_arg(ap, int), 10));
	else if (spec == 'p')
		return (ft_printpointer(va_arg(ap, void *), 16));
	else if (spec == 'u')
		return (ft_printdigit(va_arg(ap, unsigned int), 10));
	else
		return (write (1, &spec, 1));
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, arg);
	count = 0;
	while (*arg)
	{
		if (*arg == '%')
		{
			if ((*(++arg)) == '\0')
				return (-1);
			else
			{
				count += print_format(*arg, ap);
				arg++;
			}
		}
		else
		{
			count += write(1, arg, 1);
			arg++;
		}
	}
	va_end(ap);
	return (count);
}
