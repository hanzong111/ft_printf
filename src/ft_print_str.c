/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:15:19 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/15 17:34:59 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(t_flags *f, char *args);
void	ft_args_bigger(t_flags *f, char *str, int index, char *args);
void	ft_args_smaller(t_flags *f, char *str, int index, char *args);

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
		ft_putstr(f, args);
		f->index = index + 1;
	}
	else if ((f->dot >= 1) && (f->minus >= 1))
	{
	}
	else if (f->dot >= 1)
		ft_s_only_dot(f, str, index, args);
}
