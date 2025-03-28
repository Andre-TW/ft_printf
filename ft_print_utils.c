/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:24:46 by andsoare          #+#    #+#             */
/*   Updated: 2025/03/04 16:43:21 by andsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (c == NULL)
		return (write(1, "(null)", 6));
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	ft_printdigit(long n, int base)
{
	int		count;
	char	*sb;

	sb = "0123456789abcdef";
	if (n < 0)
	{
		write (1, "-", 1);
		return (ft_printdigit(-n, base) + 1);
	}
	else if (n < base)
		return (ft_printchar(sb[n]));
	else
	{
		count = ft_printdigit(n / base, base);
		return (count + ft_printchar(sb[n % base]));
	}
}

int	ft_printdigitup(long n, int base)
{
	int		count;
	char	*sb;

	sb = "0123456789ABCDEF";
	if (n < base)
		return (ft_printchar(sb[n]));
	else
	{
		count = ft_printdigitup(n / base, base);
		return (count + ft_printchar(sb[n % base]));
	}
}

int	ft_printpointer(void *p, int base)
{
	int				count;
	unsigned long	ptr;

	ptr = (unsigned long) p;
	count = 0;
	if (p == NULL)
		return (ft_printstr("(nil)"));
	count += ft_printstr("0x");
	count += ft_printteste(ptr, base);
	return (count);
}
