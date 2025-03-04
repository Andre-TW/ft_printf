/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:37:22 by andsoare          #+#    #+#             */
/*   Updated: 2025/03/04 16:42:51 by andsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printteste(unsigned long n, int base)
{
	int		count;
	char	*sb;

	sb = "0123456789abcdef";
	if (n < (unsigned int) base)
		return (ft_printchar(sb[n]));
	else
	{
		count = ft_printdigit(n / base, base);
		return (count + ft_printchar(sb[n % base]));
	}
}
