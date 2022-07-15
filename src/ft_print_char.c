/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:27:27 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/15 07:44:44 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_minus_width(t_flags *f, char *str, int index, int c);
void	ft_print_normal(t_flags *f, char *str, int index, int c);

void	ft_print_char(t_flags *f, char *str, int index, int c)
{
	index++;
	if (str[index] == 'c')
	{
		write(1, &c, 1);
		f->wc = 1;
		f->index = index + 1;
	}
	else if (f->minus >= 1)
		ft_print_minus_width(f, str, index, c);
	else
		ft_print_normal(f, str, index, c);
}

void	ft_print_minus_width(t_flags *f, char *str, int index, int c)
{
	while (--f->minus >= 0)
		index++;
	f->start = index;
	while (ft_concheck1(str[index], f))
		index++;
	f->end = index;
	f->substr = ft_substr(str, f->start, f->end - f->start);
	f->width = ft_atoi(f->substr);
	free(f->substr);
	f->wc = f->width;
	if (f->wc == 0)
		f->wc = 1;
	write(1, &c, 1);
	while (--f->width > 0)
		write(1, " ", 1);
	f->index = index + 1;
}

void	ft_print_normal(t_flags *f, char *str, int index, int c)
{
	f->start = index;
	while (ft_concheck1(str[index], f))
		index++;
	f->end = index;
	f->substr = ft_substr(str, f->start, f->end - f->start);
	f->width = ft_atoi(f->substr);
	free(f->substr);
	f->wc = f->width;
	while (--f->width > 0)
		write(1, " ", 1);
	write(1, &c, 1);
	f->index = index + 1;
}
