/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:18:36 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/16 17:35:23 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(t_flags *f, char *str, int index);
void	ft_width(t_flags *f, char *str, int index);
void	ft_no_precision_width(t_flags *f, char *str, int index);

/*	ft_precision_width()-> To extract the width and precision value .		*/
/*	Example	:	%10.30s														*/
/*				f->width = 10;												*/
/*				f->precision = 30;											*/

void	ft_precision_width(t_flags *f, char *str, int index)
{
	if (f->dot)
	{
		if (str[index] == '.')
		{
			f->width = 0;
			ft_precision(f, str, index);
		}
		else
		{
			ft_width(f, str, index);
			if (ft_typecheck(str[f->end + 1]))
				f->precision = 0;
			else
				ft_precision(f, str, f->end);
		}
	}
	else
		ft_no_precision_width(f, str, index);
}

void	ft_width(t_flags *f, char *str, int index)
{
	while (str[index] == '-')
		index++;
	f->start = index;
	while (str[index] != '.')
		index++;
	f->end = index;
	f->substr = ft_substr(str, f->start, f->end - f->start);
	f->width = ft_atoi(f->substr);
	free(f->substr);
}

void	ft_precision(t_flags *f, char *str, int index)
{
	f->start = index + 1;
	while (!ft_typecheck(str[index]))
		index++;
	f->end = index;
	f->substr = ft_substr(str, f->start, f->end - f->start);
	f->precision = ft_atoi(f->substr);
	free(f->substr);
}

void	ft_no_precision_width(t_flags *f, char *str, int index)
{
	while (str[index] == '-')
		index++;
	f->start = index;
	while (!ft_typecheck(str[index]))
		index++;
	f->end = index;
	f->substr = ft_substr(str, f->start, f->end - f->start);
	f->width = ft_atoi(f->substr);
	free(f->substr);
}
