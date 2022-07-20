/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:25:06 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/20 20:58:17 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_bigger(t_flags *f, t_info *info);
void	ft_precision_smaller(t_flags *f, t_info *info);

void	ft_minus_dot(t_flags *f, t_info *info, char	*type)
{
	if (f->hash || f->plus || f->space)
		ft_putstr_fd(type, 1);
	if (info->width >= info->precision)
		ft_precision_bigger(f, info);
	else
		ft_precision_smaller(f, info);
}

void	ft_precision_bigger(t_flags *f, t_info *info)
{
	if (info->precision >= info->strlen)
	{
		info->strlen = info->precision;
		while (--info->precision >= info->wc)
			write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
		if (f->hash)
			info->strlen = info->strlen + 2;
		if (f->plus || f->space)
			info->strlen++;
		info->wc = info->width;
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
			write(1, " ", 1);
	}
	else
	{
		ft_putstr_fd(info->format, 1);
		if (f->hash)
			info->strlen = info->strlen + 2;
		if (f->plus || f->space)
			info->strlen++;
		if (info->precision)
			info->wc = info->width;
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
			write(1, " ", 1);
	}	
}

void	ft_precision_smaller(t_flags *f, t_info *info)
{
	if (info->precision >= info->strlen)
	{
		info->strlen = info->precision;
		if (f->hash)
			info->strlen = info->strlen + 2;
		if (f->plus || f->space)
		{
			info->strlen++;
			info->precision++;
		}
		while (--info->precision >= info->wc)
			write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}		
	else
	{
		if (f->hash)
			info->strlen = info->strlen + 2;
		if (f->plus || f->space)
		{
			info->strlen++;
			info->precision++;
		}
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
}
