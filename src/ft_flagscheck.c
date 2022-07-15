/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagscheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:04:33 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/15 07:39:36 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	Kinda similar to ft_concheck() , but this is more straightfoward.		*/
/*	checks for flags , if none is present , it just returns.				*/
/*																			*/
/*	As for '0' flag's checking, we need to check the char in front of it	*/
/*	to determine if it's a '0' flag or just integer 0.						*/
/*																			*/
/*	Example :	%-100c														*/
/*	If we dont check in front, the 0 in 100 will be counted as a '0' flag.	*/

void	ft_flagscheck(char c, char d, t_flags *flags)
{
	if (c == '-')
		flags->minus++;
	else if (c == '0' && !(d >= '0' && d <= '9'))
		flags->zero++;
	else if (c == '.')
		flags->dot++;
	else if (c == '#')
		flags->hash++;
	else if (c == ' ')
		flags->space++;
	else if (c == '+')
		flags->plus++;
	else
		return ;
}
