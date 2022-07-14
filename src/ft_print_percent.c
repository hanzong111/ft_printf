/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:52:56 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/14 12:01:16 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_minus_zero(t_flags *f, char *str, int index);
void	ft_print_zero(t_flags *f, char *str, int index);

void	ft_print_percent(t_flags *flags, char *str, int index)
{
	index++;
	if (str[index] == '%')
	{
		ft_putchar_fd('%', 1);
		flags->wc = 1;
		flags->index = index + 1;
	}
	else if ((flags->minus && flags->zero) || flags->minus)
		ft_print_minus_zero(flags, str, index);
	else
		ft_print_zero(flags, str, index);
}

void	ft_print_minus_zero(t_flags *f, char *str, int index)
{
	if (f->zero)
		index++;
	index++;
	f->start = index;
	while (ft_concheck3(str[index], f))
		index++;
	f->end = index;
	f->width = ft_atoi(ft_substr(str, f->start, f->end - f->start));
	ft_putchar_fd('%', 1);
	if (f->width == 0)
	f->wc = 1;
	else
		f->wc = f->width;
	while (--f->width > 0)
		ft_putchar_fd(' ', 1);
	f->index = index + 1;
}

void	ft_print_zero(t_flags *f, char *str, int index)
{
	char	c;

	if (f->zero)
		index++;
	f->start = index;
	while (ft_concheck3(str[index], f))
		index++;
	f->end = index;
	f->width = ft_atoi(ft_substr(str, f->start, f->end - f->start));
	f->wc = f->width;
	if (f->zero)
		c = '0';
	else
		c = ' ';
	while (--f->width > 0)
		ft_putchar_fd(c, 1);
	ft_putchar_fd('%', 1);
	f->index = index + 1;
}
