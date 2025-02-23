/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:24:46 by andsoare          #+#    #+#             */
/*   Updated: 2025/02/23 15:53:13 by andsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	int	count;

	count = 0;
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_printstr(char *c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
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
		count += 1;
		return (ft_printdigit(-n, base));
	}
	else if (n < base)
		count += ft_printchar(sb[n]);
	else
	{
		count += ft_printdigit(n / base, base);
		count += ft_printchar(sb[n % base]);
	}
	return (count);
}

int	ft_printdigitup(long n, int base)
{
	int		count;
	char	*sb;

	sb = "0123456789ABCDEF";
	if (n < 0)
	{
		write (1, "-", 1);
		count += 1;
		return (ft_printdigit(-n, base));
	}
	else if (n < base)
		count += ft_printchar(sb[n]);
	else
	{
		count += ft_printdigit(n / base, base);
		count += ft_printchar(sb[n % base]);
	}
	return (count);
}
