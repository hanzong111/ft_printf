/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializeflags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:02:58 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/13 16:44:40 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initializeflags(t_flags *var)
{
	(*var).minus = 0;
	(*var).zero = 0;
	(*var).dot = 0;
	(*var).hash = 0;
	(*var).space = 0;
	(*var).plus = 0;
	(*var).wc = 0;
	(*var).width = 0;
}
