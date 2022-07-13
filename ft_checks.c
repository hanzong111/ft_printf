/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:34:12 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/13 18:54:45 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_checks(char	*str, int index, t_flags *flags)
{
	while (ft_concheck(str[index], flags))
	{
		ft_flagscheck(str[index], flags);
		index++;
	}
}
