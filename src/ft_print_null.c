/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:38:51 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/20 15:37:46 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_null(t_flags *f, t_info *info)
{
	char	*null;

	null = "(null)";
	if (f->dot)
	{
		while ((info->precision > 0) && (*null != '\0'))
		{
			write(1, null, 1);
			null++;
			info->precision--;
			info->wc++;
		}
	}
	else if (info->width >= 6)
	{
		info->format = null;
		ft_only_width(f, info, " ");
	}
	else
	{
		ft_putstr_fd(null, 1);
		info->wc = 6;
	}
}
