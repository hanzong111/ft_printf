/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:42:00 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/20 20:46:24 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prefix(t_flags *f, t_info *info, int i);
void	ft_convert_nbr(t_info *info, int i);

void	ft_print_nbr(t_flags *f, t_info *info, int i)
{
	ft_convert_nbr(info, i);
	info->strlen = ft_strlen((const char *)info->format);
	info->wc += info->strlen;
	ft_prefix(f, info, i);
	if (f->minus && f->dot)
		ft_minus_dot(f, info, info->prefix);
	else if (f->dot)
		ft_only_dot(f, info, info->prefix);
	else if (f->minus)
		ft_only_minus(f, info, info->prefix);
	else if (f->zero)
		ft_only_zero(f, info, info->prefix);
	else if (info->width)
		ft_only_width(f, info, info->prefix);
	else
	{
		if (i < 0)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(info->format, 1);
	}
	if (i >= 0)
		free(info->format);
	else
		free(info->format - 1);
	free(info->prefix);
}

void	ft_convert_nbr(t_info *info, int i)
{
	char	*s;

	s = ft_itoa(i);
	if (i < 0)
	{
		s++;
		info->wc++;
	}
	info->format = s;
}

void	ft_prefix(t_flags *f, t_info *info, int i)
{
	char	*s;

	s = malloc(sizeof(char) * 2);
	info->prefix = s;
	if (i >= 0)
	{
		if (f->plus)
			*s = '+';
		else if (f->space)
			*s = ' ';
		else
			*s = '\0';
	}
	else
	{
		*s = '-';
		f->space = 1;
	}
	s++;
	*s = '\0';
	return ;
}
