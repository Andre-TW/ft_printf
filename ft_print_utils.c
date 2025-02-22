/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:24:46 by andsoare          #+#    #+#             */
/*   Updated: 2025/02/22 17:27:50 by andsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printchar(char c)
{
	int	count;

	count = 0;
	write(1, &c, 1);
	count++;
	return(count);
}

int	ft_printstr(char *c)
{
	int	count;

	count = 0;
	while(*c != '\0')
	{
		write(1, c, 1);
		c++;
		count++;
	}
	return(count);
}

int ft_printdigit
