/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:54:18 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/20 19:57:15 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_only_zero(t_flags *f, t_info *info, char *c)
{
	info->strlen = ft_strlen((const char *)info->format);
	if (f->hash || f->plus || f->space)
	{
		if (f->hash)
			info->strlen = info->strlen + 2;
		if (f->plus || f->space)
			info->strlen++;
		ft_putstr_fd(c, 1);
	}
	if (info->width < info->strlen)
	{
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
	else
	{
		info->wc = info->width;
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
			write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
	}
}
