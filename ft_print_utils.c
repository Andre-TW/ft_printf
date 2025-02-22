/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:24:46 by andsoare          #+#    #+#             */
/*   Updated: 2025/02/22 16:35:23 by andsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printdigit(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_printstr(char *c, int count)
{
	while (*c)
	{
		write(1, c, 1);
		c++;
		count++;
	}
	return (count);
}
