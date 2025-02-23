/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:33:08 by andsoare          #+#    #+#             */
/*   Updated: 2025/02/23 16:05:15 by andsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_printchar(va_arg(ap, int));
	else if (spec == 's')
		count += ft_printstr(va_arg(ap, char *));
	else if (spec == 'd')
		count += ft_printdigit((long)va_arg(ap, int), 10);
	else if (spec == 'x')
		count += ft_printdigit((long)va_arg(ap, unsigned int), 16);
	else if (spec == '%')
		count += write(1, "%", 1);
	else if (spec == 'X')
		count += ft_printdigitup((long)va_arg(ap, unsigned int), 16);
	else if (spec == 'i')
		count += ft_printdigit((long)va_arg(ap, unsigned int), 10);
	else if (spec == 'p')
		count += ft_printdigit((long)va_arg(ap, unsigned int), 16);
	else if (spec == 'u')
		count += ft_printdigit((long)va_arg(ap, unsigned int), 10);
	else
		count += write (1, &spec, 1);
	return (count);
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
			count += print_format(*(++arg), ap);
		else
		{
			count += write(1, arg, 1);
			arg++;
		}
	}
	va_end(ap);
	return (count);
}

int main()
{
	int count;
	char *tst;

	tst = "ab";
	count = 14121415;

	ft_printf("aqui sei la %X\n", count);

}
