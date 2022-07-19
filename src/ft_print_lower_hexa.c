/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:05:17 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/19 20:57:23 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_lower_hexa(t_flags *f, t_info *info, unsigned int args)
{
	ft_convert_hex(f, info, (unsigned int)args);
	info->strlen = info->wc;
	if (f->minus && f->dot)
		ft_minus_dot(f, info, "0x");
	else if (f->dot)
		ft_only_dot(f, info, "0x");
	else
		ft_putstr_fd(info->format, 1);
	free(info->format);
}
