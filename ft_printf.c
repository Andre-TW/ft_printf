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
		count += ft_printdigit((long)va_arg(ap, int), 10);
	else if (spec == 'p')
	{	
		count += write(1, "0x", 2);
		count += ft_printdigit((long)va_arg(ap, void *), 16);
	}
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
		{	
			count += print_format(*(++arg), ap);
			++arg;
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
#include <stdio.h>

int main() {
    char c = 'A';
    char *str = NULL;
    char str1[] = "test";
    int d = 42;
    unsigned int u = 255;
    int i = -42;
    void *p = &c;

    // Testing the format specifiers
    printf("Character (c): %c\n", c);
    printf("String null (s): %s\n", str);
    printf("string (s); %s\n", str1);
    printf("Decimal (d): %d\n", d);
    printf("Hexadecimal (x): %x\n", u);
    printf("Hexadecimal (X): %X\n", u);
    printf("Percentage (%%): %%\n");
    printf("Integer (i): %i\n", i);
    printf("Pointer (p): %p\n", p);
    printf("Unsigned (u): %u\n", u);


    ft_printf("my ft Character (c): %c\n", c);
    ft_printf("my ft String null (s): %s\n", str);
    ft_printf("my string (s); %s\n", str1);
    ft_printf("my ft Decimal (d): %d\n", d);
    ft_printf("my ft Hexadecimal (x): %x\n", u);
    ft_printf("my ft Hexadecimal (X): %X\n", u);
    ft_printf("my ft Percentage (%%): %%\n");
    ft_printf("my ft Integer (i): %i\n", i);
    ft_printf("my ft Pointer (p): %p\n", p);
    ft_printf("my ft Unsigned (u): %u\n", u);


    return 0;
}


