/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializeflags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:02:58 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/17 12:23:51 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	Just to initialize all the variables to use in the future	*/

void	ft_initializeflags(t_flags *var, t_info *info)
{
	var->minus = 0;
	var->zero = 0;
	var->dot = 0;
	var->hash = 0;
	var->space = 0;
	var->plus = 0;
	info->wc = 0;
	info->width = 0;
	info->precision = 0;
	info->strlen = 0;
}
