/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:29:40 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/19 20:21:33 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bigger(t_flags *f, t_info *info);
void	ft_smaller(t_flags *f, t_info *info);

void	ft_only_dot(t_flags *f, t_info *info)
{
	if (!info->precision)
	{
		if (f->hash)
		{
			info->strlen = info->strlen + 2;
			ft_putstr_fd("0x", 1);
		}
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
		return ;
	}
	if (info->width >= info->precision)
		ft_bigger(f, info);
	else
		ft_smaller(f, info);
}

void	ft_bigger(t_flags *f, t_info *info)
{
	if (info->precision >= info->strlen)
	{
		if (f->hash)
			info->strlen = info->strlen + 2;
		info->precision -= info->wc;
		info->strlen += info->precision;
		info->wc = info->width;
		info->width -= info->strlen;
		while (--info->width >= 0)
			write(1, " ", 1);
		if (f->hash)
			ft_putstr_fd("0x", 1);
		while (--info->precision >= 0)
			write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
	}
	else
	{
		if (f->hash)
			info->strlen = info->strlen + 2;
		info->wc = info->width;
		info->width -= info->strlen;
		while (--info->width >= 0)
			write(1, " ", 1);
		if (f->hash)
			ft_putstr_fd("0x", 1);
		ft_putstr_fd(info->format, 1);
		if (!info->precision)
			info->wc = info->width;
	}	
}

void	ft_smaller(t_flags *f, t_info *info)
{
	if (info->precision >= info->strlen)
	{
		info->strlen = info->precision;
		if (f->hash)
		{
			info->strlen = info->strlen + 2;
			ft_putstr_fd("0x", 1);
		}
		while (--info->precision >= info->wc)
			write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}		
	else
	{
		if (f->hash)
		{
			info->strlen = info->strlen + 2;
			ft_putstr_fd("0x", 1);
		}
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
}
