/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:13:59 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/20 20:30:22 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_only_width(t_flags *f, t_info *info, char *c)
{
	info->strlen = ft_strlen((const char *)info->format);
	if (f->hash)
		info->strlen += 2;
	if (f->plus || f->space)
		info->strlen++;
	if (info->width < info->strlen)
	{
		if (f->hash || f->plus || f->space)
			ft_putstr_fd(c, 1);
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
	else
	{
		info->wc = info->width;
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
			write(1, " ", 1);
		if (f->hash || f->plus || f->space)
			ft_putstr_fd(c, 1);
		ft_putstr_fd(info->format, 1);
	}
}
