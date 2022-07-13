/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:52:56 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/13 19:37:57 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_percent(t_flags *flags, char *str, int index)
{
	int	start;
	int	end;
	int	value;

	value = 0;
	start = 0;
	end = 0;
	index++;
	if (str[index] == '%')
		ft_putchar_fd('%', 1);
	else if (flags->minus)
	{
		start = index + 1;
		while (ft_concheck3(str[++index], flags))
		end = index;
		printf("Start : %d\n",start);
		printf("End :%d\n",end);
		value = ft_atoi(ft_substr(str, start, end - start));
		printf("%d\n",value);
		ft_putchar_fd('%', 1);
		while (--value > 0)
			ft_putchar_fd(' ', 1);
		flags->wc = value;
	}
	flags->index = index;
}
