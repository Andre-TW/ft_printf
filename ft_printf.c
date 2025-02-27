/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:33:08 by andsoare          #+#    #+#             */
/*   Updated: 2025/02/25 15:15:26 by andsoare         ###   ########.fr       */
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
		return (ft_printdigit((long)va_arg(ap, unsigned int), 16));
	else if (spec == '%')
		return (write(1, "%", 1));
	else if (spec == 'X')
		return (ft_printdigitup((long)va_arg(ap, unsigned int), 16));
	else if (spec == 'i' || spec == 'd')
		return (ft_printdigit((long)va_arg(ap, int), 10));
	else if (spec == 'p')
		return (ft_printpointer((long)va_arg(ap, void *), 16));
	else if (spec == 'u')
		return (ft_printdigit((long)va_arg(ap, unsigned int), 10));
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

int main() 
{
	int count;
    char c = 'A';
    char *str = NULL;
    char str1[] = "test";
    int d = 2147483647;
    unsigned int u = 255;
    int i = -42;
    void *p = NULL;
	
	count = 0;
    // Testing the format specifiers
    printf("%d\n", printf("%%\n", p));
	/* printf("%d\n", printf("%s\n", str));
	printf("string null %s\n", str);
    printf("normal string %s\n", str1);
    printf("Decimal (d): %d\n", d);
    printf("Hexadecimal (x): %x\n", u);
    printf("Hexadecimal (X): %X\n", u);
    printf("Percentage (%%): %%\n");
    printf("Integer (i): %i\n", i);
    printf("Pointer (p): %p\n", p);
    printf("Unsigned (u): %u\n", u);*/


    ft_printf("%d\n", ft_printf("%%\n"));
   /* ft_printf("string in null%s\n", str);	
    ft_printf("normal string %s\n", str1);
	ft_printf("my ft Decimal (d): %d\n", d);
    ft_printf("my ft Hexadecimal (x): %x\n", u);
    ft_printf("my ft Hexadecimal (X): %X\n", u);
    ft_printf("my ft Percentage (%%): %%\n");
    ft_printf("my ft Integer (i): %i\n", i);
    ft_printf("my ft Pointer (p): %p\n", p);
    ft_printf("my ft Unsigned (u): %u\n", u);
	

	printf("%");
	printf("hola%");
	printf("%hola");

	ft_printf("%");
	ft_printf("hola%");
	ft_printf("%hola");
	*/


    return 0;
}
