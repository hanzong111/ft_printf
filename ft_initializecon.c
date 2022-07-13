/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializecon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:35 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/13 16:37:46 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initializecon(t_con *var)
{
	(*var).c = 0;
	(*var).s = 0;
	(*var).p = 0;
	(*var).d = 0;
	(*var).i = 0;
	(*var).u = 0;
	(*var).x = 0;
	(*var).capx = 0;
}