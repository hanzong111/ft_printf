/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:52:56 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/14 20:06:25 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_minus_zero(t_flags *f, char *str, int index);
void	ft_print_zero(t_flags *f, char *str, int index);

/*	Seperated the conditions so that we know how to extract the 'Width' */
/*	from the string														*/
/*																		*/
/*	ft_print_minus_zero() -> For when flags - & 0 are present together	*/
/*	Example :	%-010%													*/
/*	ft_print_zero -> For when 0 flag is present and width 				*/
/*	Example :	%010%													*/
/*				%10%													*/

void	ft_print_percent(t_flags *flags, char *str, int index)
{
	index++;
	if (str[index] == '%')
	{
		write(1, "%%", 1);
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
	f->substr = ft_substr(str, f->start, f->end - f->start);
	f->width = ft_atoi(f->substr);
	free(f->substr);
	write(1, "%%", 1);
	if (f->width == 0)
	f->wc = 1;
	else
		f->wc = f->width;
	while (--f->width > 0)
		write(1, " ", 1);
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
	f->substr = ft_substr(str, f->start, f->end - f->start);
	f->width = ft_atoi(f->substr);
	free(f->substr);
	f->wc = f->width;
	if (f->zero)
		c = '0';
	else
		c = ' ';
	while (--f->width > 0)
		write(1, &c, 1);
	write(1, "%%", 1);
	f->index = index + 1;
}
