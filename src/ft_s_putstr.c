/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:02:30 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/16 16:04:02 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_putstr(t_flags *f, char *str)
{
	int	strlen;

	strlen = ft_strlen((const char *)str);
	if (f->dot)
	{
		while (--f->precision >= 0)
		{
			write(1, str, 1);
			str++;
			f->wc++;
		}
		return ;
	}
	else
	{
		while (--strlen >= 0)
		{
			write(1, str, 1);
			str++;
			f->wc++;
		}
	}
}
