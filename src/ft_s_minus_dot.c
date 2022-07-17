/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_minus_dot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:08:52 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/16 17:39:06 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_args_bigger(t_flags *f, char *str, int index, char *args);

void	ft_s_minus_dot(t_flags *f, char *str, int index, char *args)
{
	while (--f->dot >= 0)
		index++;
	ft_precision_width(f, str, index);
	f->strlen = ft_strlen((const char *)args);
	if (f->strlen >= f->width)
		ft_minus_args_bigger(f, str, index, args);
	else if (f->strlen < f->width)
		ft_minus_args_smaller(f, str, index, args);
}

void	ft_minus_args_bigger(t_flags *f, char *str, int index, char *args)
{
	if (f->precision >= f->strlen)
	{
		ft_putstr_fd(args, 1);
		f->wc = f->strlen;
		while (!ft_typecheck(str[index]))
			index++;
		f->index = index + 1;
		return ;
	}
	else
	{
		f->width = f->width - f->precision;
		ft_s_putstr(f, args);
		while (--f->width >= 0)
		{
			write(1, " ", 1);
			f->wc++;
		}
		while (!ft_typecheck(str[index]))
			index++;
		f->index = index + 1;
		return ;
	}
}

void	ft_minus_args_smaller(t_flags *f, char *str, int index, char *args)
{
	if (f->precision >= f->strlen)
	{
		f->width = f->width - f->strlen;
		f->wc = f->width;
		ft_putstr_fd(args, 1);
		while (--f->width >= 0)
			write(1, " ", 1);
		f->wc = f->wc + f->strlen;
		while (ft_concheck1(str[index++], f))
		f->index = index + 1;
	}
	else
	{
		f->width = f->width - f->precision;
		f->wc = f->width;
		while (--f->precision >= 0)
		{
			write(1, args++, 1);
			f->wc++;
		}
		while (--f->width >= 0)
			write(1, " ", 1);
		while (ft_concheck1(str[index++], f))
		f->index = index + 1;
	}	
}
