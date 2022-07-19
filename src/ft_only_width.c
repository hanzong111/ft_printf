/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:13:59 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/18 15:11:30 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_only_width(t_info *info)
{
	info->strlen = ft_strlen((const char *)info->format);
	if (info->width < info->strlen)
	{
		ft_putstr_fd(info->format, 1);
		info->wc = info->strlen;
	}
	else
	{
		info->width = info->width - info->strlen;
		while (--info->width >= 0)
		{
			write(1, " ", 1);
			info->wc++;
		}
		ft_putstr_fd(info->format, 1);
		info->wc = info->wc + info->strlen;
	}
}
