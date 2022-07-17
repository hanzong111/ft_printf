/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_only_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:31:16 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/16 17:36:45 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_args_bigger(t_flags *f, char *str, int index, char *args);
void	ft_args_smaller(t_flags *f, char *str, int index, char *args);

void	ft_s_only_dot(t_flags *f, char *str, int index, char *args)
{
	ft_precision_width(f, str, index);
	f->strlen = ft_strlen((const char *)args);
	if (f->strlen >= f->width)
		ft_args_bigger(f, str, index, args);
	else if (f->strlen < f->width)
		ft_args_smaller(f, str, index, args);
}

void	ft_args_bigger(t_flags *f, char *str, int index, char *args)
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
		while (--f->width >= 0)
		{
			write(1, " ", 1);
			f->wc++;
		}
		ft_s_putstr(f, args);
		while (!ft_typecheck(str[index]))
			index++;
		f->index = index + 1;
		return ;
	}
}

void	ft_args_smaller(t_flags *f, char *str, int index, char *args)
{
	if (f->precision >= f->strlen)
	{
		f->width = f->width - f->strlen;
		f->wc = f->width;
		while (--f->width >= 0)
			write(1, " ", 1);
		ft_putstr_fd(args, 1);
		f->wc = f->wc + f->strlen;
		while (!ft_typecheck(str[index++]))
		f->index = index + 1;
	}
	else
	{
		f->width = f->width - f->precision;
		f->wc = f->width;
		while (--f->width >= 0)
			write(1, " ", 1);
		while (--f->precision >= 0)
		{
			write(1, args++, 1);
			f->wc++;
		}
		while (!ft_typecheck(str[index++]))
		f->index = index + 1;
	}	
}
