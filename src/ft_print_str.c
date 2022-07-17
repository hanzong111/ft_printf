/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:15:19 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/16 16:56:31 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_normal(t_flags *f, char *str, int index, char *args);

void	ft_print_str(t_flags *f, char *str, int index, char *args)
{
	index++;
	if (args == NULL)
	{
		ft_print_null(f, str, index);
		return ;
	}
	if (str[index] == 's')
	{
		ft_s_putstr(f, args);
		f->index = index + 1;
	}
	else if ((f->dot >= 1) && (f->minus >= 1))
		ft_s_minus_dot(f, str, index, args);
	else if (f->dot >= 1)
		ft_s_only_dot(f, str, index, args);
	else if (f->minus >= 1)
		ft_s_only_minus(f, str, index, args);
	else
		ft_s_normal(f, str, index, args);
}

void	ft_s_normal(t_flags *f, char *str, int index, char *args)
{
	ft_precision_width(f, str, index);
	f->strlen = ft_strlen(args);
	if (f->strlen >= f->width)
	{
		ft_putstr_fd(args, 1);
		f->wc = f->strlen;
		while (!ft_typecheck(str[index]))
			index++;
		f->index = index + 1;
	}
	else
	{
		f->wc = f->width;
		f->width = f->width - f->strlen;
		while (--f->width >= 0)
			write(1, " ", 1);
		ft_putstr_fd(args, 1);
		while (!ft_typecheck(str[index]))
			index++;
		f->index = index + 1;
	}
}
