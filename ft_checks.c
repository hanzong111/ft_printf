/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:34:12 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/13 16:32:06 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_checks(char	*str, int *index, t_con *type, t_flags *flags)
{
	printf("The First Char is %c\n", str[*index]);
	while (ft_concheck(str[*index], type))
	{
		printf("The Char is %c\n", str[*index]);
		ft_flagscheck(str[*index], flags);
		(*index)++;
	}
}
