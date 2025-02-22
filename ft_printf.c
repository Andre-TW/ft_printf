/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:33:08 by andsoare          #+#    #+#             */
/*   Updated: 2025/02/22 16:57:21 by andsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int	count;

	va_start(ap,arg);
	count = 0;
	while (*arg)
	{
		if (*arg == '%')
			count +=print_format(*(++arg), ap);
		else
			count += write(1, arg, 1);
			arg++;
	}
	va_end(ap);
	return count;

}
