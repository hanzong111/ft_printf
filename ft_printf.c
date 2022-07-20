/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:33:41 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/20 16:39:35 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_format(char *str, t_flags *flags, t_info *info, va_list args);
void	ft_print(char *str, t_flags *flags, t_info *info, va_list args);

/*	Keeps looping through the string until we hit a Null character	*/
/*	ft_print_conversions()-> To deal with the % stuffs.				*/
/*	when no % is present in the string, it just keeps printing the 	*/
/*	string character by character.									*/


void	ft_print(char *str, t_flags *flags, t_info *info, va_list args)
{
	if (*str == '%')
		ft_print_percent(flags, info);
	else if (*str == 'c')
		ft_print_char(flags, info, va_arg(args, int));
	else if (*str == 's')
		ft_print_str(flags, info, va_arg(args, char *));
	else if (*str == 'p')
		ft_print_pointer(flags, info, va_arg(args, unsigned long long));
	else if (*str == 'x')
		ft_print_lower_hexa(flags, info, va_arg(args, unsigned int));
	else if (*str == 'X')
		ft_print_upper_hexa(flags, info, va_arg(args, unsigned int));
	else if (*str == 'd' || *str == 'i')
		ft_print_nbr(flags, info, va_arg(args, int));
}

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
