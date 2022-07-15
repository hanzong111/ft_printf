/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:18:36 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/15 17:27:48 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	ft_precision_width()-> To extract the width and precision value .		*/
/*	Example	:	%10.30s														*/
/*				f->width = 10;												*/
/*				f->precision = 30;											*/

void	ft_precision_width(t_flags *f, char *str, int index)
{
	f->start = index;
	while (str[index] != '.')
		index++;
	f->end = index;
	f->substr = ft_substr(str, f->start, f->end - f->start);
	f->width = ft_atoi(f->substr);
	free(f->substr);
	f->start = index + 1;
	while (ft_concheck1(str[index], f))
		index++;
	f->end = index;
	f->substr = ft_substr(str, f->start, f->end - f->start);
	f->precision = ft_atoi(f->substr);
	free(f->substr);
}
