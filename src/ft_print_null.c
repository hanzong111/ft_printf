/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:38:51 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/16 17:15:48 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_dot_null(t_flags *f, char	*null);
void	ft_print_width_null(t_flags *f, char *null);

void	ft_print_null(t_flags *f, char *str, int index)
{
	char	*null;

	null = "(null)";
	ft_precision_width(f, str, index);
	if (f->dot)
		ft_print_dot_null(f, null);
	else
		ft_print_width_null(f, null);
	while (ft_concheck(str[index], f))
		index++;
	f->index = index + 1;
}

void	ft_print_width_null(t_flags *f, char *null)
{
	if (f->width >= 6)
	{
		f->wc = f->width;
		f->width = f->width - 6;
		while (--f->width >= 0)
			write(1, " ", 1);
		ft_putstr_fd(null, 1);
	}
	else
	{
		ft_putstr_fd(null, 1);
		f->wc = 6;
	}
}

void	ft_print_dot_null(t_flags *f, char	*null)
{
	while ((f->precision > 0) && (*null != '\0'))
	{
		write(1, null, 1);
		null++;
		f->precision--;
		f->wc++;
	}
}
