/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:33:41 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/18 18:02:03 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_format(char *str, t_flags *flags, t_info *info, va_list args);

/*	Keeps looping through the string until we hit a Null character	*/
/*	ft_print_conversions()-> To deal with the % stuffs.				*/
/*	when no % is present in the string, it just keeps printing the 	*/
/*	string character by character.									*/

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	t_info	info;
	int		wc;

	wc = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		ft_initializeflags(&flags, &info);
		if (*str == '%')
			str = ft_print_format((char *)str, &flags, &info, args);
		else
		{
			write(1, str, 1);
			str++;
			info.wc++;
		}
		wc += info.wc;
	}
	va_end(args);
	return (wc);
}

char	*ft_print_format(char *str, t_flags *flags, t_info *info, va_list args)
{
	ft_checks(str, flags);
	ft_precision_width(str, flags, info);
	ft_print(info->str, flags, info, args);
	return (info->str + 1);
}
