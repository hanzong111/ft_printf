/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:02 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/20 17:00:25 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_upper(char *str);
void	ft_hex_nbr_len(t_info *info, unsigned int i);
void	ft_rev_tab(char *tab, int size);
int		ft_nullchecks(t_flags *f, t_info *info, unsigned int i, char *str);

void	ft_convert_hex(t_flags *f, t_info *info, unsigned int i)
{
	char	*str;
	char	*init_ptr;

	ft_hex_nbr_len(info, i);
	str = malloc(sizeof(char) * (info->wc + 1));
	if (!str)
		return ;
	if (ft_nullchecks(f, info, i, str))
		return ;
	init_ptr = str;
	while (i >= 16)
	{
		*str = "0123456789abcdef"[i % 16];
		i = i / 16;
		str++;
	}
	*str = "0123456789abcdef"[i];
	str++;
	*str = '\0';
	ft_rev_tab(init_ptr, info->wc);
	info->format = init_ptr;
}

int	ft_nullchecks(t_flags *f, t_info *info, unsigned int i, char *str)
{
	if ((info->precision == 0 && f->dot) && i == 0)
	{
		*str = '\0';
		info->format = str;
		info->wc = 0;
		return (1);
	}
	if (i == 0 && !f->dot)
	{
		*str = '0';
		info->format = str;
		info->wc = 1;
		return (1);
	}
	return (0);
}


void	ft_hex_nbr_len(t_info *info, unsigned int i)
{
	if (i == 0)
	{
		if (info->precision == 0)
		{
			info->wc = 0;
			return ;
		}
		else
		{
			info->wc = 1;
			return ;
		}	
	}
	while (i >= 16)
	{
		i = i / 16;
		info->wc++;
	}
	info->wc++;
}
