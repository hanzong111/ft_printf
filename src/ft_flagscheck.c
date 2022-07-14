/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagscheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:04:33 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/14 12:00:20 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagscheck(char c, char d, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '0' && !(d >= '0' && d <= '9'))
		flags->zero = 1;
	else if (c == '.')
		flags->dot = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == ' ')
		flags->space++;
	else if (c == '+')
		flags->plus = 1;
	else
		return ;
}
