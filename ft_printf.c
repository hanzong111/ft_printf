/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:33:41 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/15 10:08:43 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(char *str, int index, t_flags *flags, va_list args);

/*	Keeps looping through the string until we hit a Null character	*/
/*	ft_print_conversions()-> To deal with the % stuffs.				*/
/*	when no % is present in the string, it just keeps printing the 	*/
/*	string character by character.									*/

int	ft_printf(char	*str, ...)
{
	va_list	args;
	t_flags	flags;
	int		index;
	int		wc;

	wc = 0;
	index = 0;
	va_start(args, str);
	while (str[index])
	{
		ft_initializeflags(&flags);
		if (str[index] == '%')
			index = ft_print_conversion(str, index, &flags, args);
		else
		{
			write(1, &str[index], 1);
			index++;
			flags.wc++;
		}
		wc += flags.wc;
	}
	va_end(args);
	return (wc);
}

int	ft_print_conversion(char *str, int index, t_flags *flags, va_list args)
{
	ft_checks(str, index, flags);
	ft_print(flags, str, index, args);
	return (flags->index);
}
