/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:34:12 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/14 12:40:59 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checks(char	*str, int index, t_flags *flags)
{
	index++;
	while (ft_concheck(str[index], flags))
	{
		ft_flagscheck(str[index], str[index - 1], flags);
		index++;
	}
}
