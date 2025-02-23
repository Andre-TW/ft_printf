/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andsoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:24:18 by andsoare          #+#    #+#             */
/*   Updated: 2025/02/23 15:21:15 by andsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> 
# include <unistd.h>
# include <stdarg.h>

int		ft_printchar(int c);
int		ft_printstr(char *c);
int		ft_printdigit(long n, int base);
int		ft_printdigitup(long n, int base);

#endif
