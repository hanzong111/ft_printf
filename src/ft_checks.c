/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:34:12 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/17 13:14:12 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	Main function of ft_checks() is to assign values to the struct 		*/
/*	flags , so that we know what flags are inside the string.			*/
/*																		*/
/*	ft_concheck()-> To check for what type of conversion do we need to 	*/
/*	do, also giving back a value of 1 or 0 to Tell the while loop when 	*/
/*	to stop looping.													*/
/*																		*/
/*	ft_flagscheck()-> To check for what flags are available				*/
/*	Example :	%-0100%													*/
/*																		*/
/*	After ft_checks(), now flags.minus and flags.zero are equal to 1.	*/
/*	Also , flags.percent is also 1.										*/

void	ft_checks(char	*str, t_flags *flags)
{
	str++;
	while (ft_typecheck(*str))
	{
		ft_flagscheck(*str, *(str - 1), flags);
		str++;
	}
}
