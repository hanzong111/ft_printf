/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:44:48 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/14 15:02:37 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(t_flags *flags, char *str, int index, va_list args)
{
	va_arg(args, int);
	if (flags->percent)
		ft_print_percent(flags, str, index);
	// else if (flags->c)
	// 	ft_print_char(flags, str, index, va_arg(args, int));
}
