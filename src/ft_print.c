/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:44:48 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/19 18:53:38 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	Seperate conditions according to results of ft_checks()	*/

void	ft_print(char *str, t_flags *flags, t_info *info, va_list args)
{
	if (*str == '%')
		ft_print_percent(flags, info);
	else if (*str == 'c')
		ft_print_char(flags, info, va_arg(args, int));
	else if (*str == 's')
		ft_print_str(flags, info, va_arg(args, char *));
	else if (*str == 'p')
		ft_print_pointer(flags, info, va_arg(args, unsigned long long));
	else if (*str == 'x')
		ft_print_lower_hexa(flags, info, va_arg(args, unsigned int));
}
