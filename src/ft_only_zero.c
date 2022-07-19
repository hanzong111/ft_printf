/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:54:18 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/17 18:13:36 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_only_zero(t_info *info)
{
	info->wc = info->width;
	info->strlen = ft_strlen((const char *)info->format);
	if (info->width < info->strlen)
		ft_putstr_fd(info->format, 1);
	else
	{
		info->width = info->width - info->strlen;
		while (--info->width > 0)
			write(1, "0", 1);
		ft_putstr_fd(info->format, 1);
	}
}
