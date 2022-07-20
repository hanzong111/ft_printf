/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:01:40 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/20 20:54:45 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_only_minus(t_flags *f, t_info *info, char *c)
{
	if (f->hash || f->plus || f->space)
		ft_putstr_fd(c, 1);
	// if (f->plus || f->space)
	// 	info->wc++;
	if (info->wc >= info->width)
		ft_putstr_fd(info->format, 1);
	else
	{
		ft_putstr_fd(info->format, 1);
		info->strlen = info->wc;
		info->wc = info->width;
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
			write(1, " ", 1);
	}
}
