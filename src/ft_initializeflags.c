/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializeflags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:02:58 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/14 14:16:41 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initializeflags(t_flags *var)
{
	var->minus = 0;
	var->zero = 0;
	var->dot = 0;
	var->hash = 0;
	var->space = 0;
	var->plus = 0;
	var->wc = 0;
	var->width = 0;
	var->index = 0;
	var->c = 0;
	var->s = 0;
	var->p = 0;
	var->d = 0;
	var->i = 0;
	var->u = 0;
	var->x = 0;
	var->capx = 0;
	var->percent = 0;
	var->start = 0;
	var->end = 0;
}
