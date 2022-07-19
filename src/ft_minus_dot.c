/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:25:06 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/19 19:38:00 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_bigger(t_flags *f, t_info *info);
void	ft_precision_smaller(t_flags *f, t_info *info);

void	ft_minus_dot(t_flags *f, t_info *info)
{
	if (f->hash)
		ft_putstr_fd("0x", 1);
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
		while (--info->precision >= info->wc)
			write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}		
	else
	{
		if (f->hash)
			info->strlen = info->strlen + 2;
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
}
