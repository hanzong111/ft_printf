/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:59:02 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/19 20:18:45 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_upper(char *str);
void	ft_hex_nbr_len(t_info *info, unsigned int i);
void	ft_rev_tab(char *tab, int size);

void	ft_convert_hex(t_info *info, unsigned int i)
{
	char	*str;
	char	*init_ptr;

	ft_hex_nbr_len(info, i);
	str = malloc(sizeof(char) * (info->wc + 1));
	if (!str)
		return ;
	if (i == 0)
	{
		*str = '\0';
		info->format = str;
		return ;
	}
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

void	ft_hex_nbr_len(t_info *info, unsigned int i)
{
	if (i == 0)
	{
		info->wc = 0;
		return ;
	}
	while (i >= 16)
	{
		i = i / 16;
		info->wc++;
	}
	info->wc++;
}
