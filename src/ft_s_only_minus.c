/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_only_minus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:48:49 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/16 16:52:32 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_only_minus(t_flags *f, char *str, int index, char *args)
{
	while (--f->minus >= 0)
		index++;
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
		ft_putstr_fd(args, 1);
		f->wc = f->width;
		f->width = f->width - f->strlen;
		while (--f->width >= 0)
			write(1, " ", 1);
		while (!ft_typecheck(str[index]))
			index++;
		f->index = index + 1;
	}
}
