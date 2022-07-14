/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:44:48 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/14 17:44:25 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	Seperate conditions according to results of ft_checks()	*/

void	ft_print(t_flags *flags, char *str, int index, va_list args)
{
	if (flags->percent)
		ft_print_percent(flags, str, index);
	else if (flags->c)
		ft_print_char(flags, str, index, va_arg(args, int));
}
