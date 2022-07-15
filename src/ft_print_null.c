/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:38:51 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/15 16:59:34 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_null(t_flags *f, char *str, int index)
{
	char	*null;

	null = "(null)";
	ft_precision_width(f, str, index);
	if (f->dot)
	{
		while ((f->precision > 0) && (*null != '\0'))
		{
			write(1, null, 1);
			null++;
			f->precision--;
			f->wc++;
		}	
	}
	else
	{
		ft_putstr_fd(null, 1);
		f->wc = 6;
	}
	while (ft_concheck(str[index], f))
		index++;
	f->index = index + 1;
}