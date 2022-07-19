/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:51:26 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/19 19:02:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_upper(char *str);
void	ft_ptr_nbr_len(t_info *info, unsigned long long i);
void	ft_rev_tab(char *tab, int size);

void	ft_convert_ptr(t_info *info, char type, unsigned long long i)
{
	char	*str;
	char	*init_ptr;

	ft_ptr_nbr_len(info, i);
	str = malloc(sizeof(char) * (info->wc + 1));
	if (!str)
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
	if (type == 'X')
	{
		ft_str_upper(init_ptr);
		info->format = init_ptr;
	}
	else
		info->format = init_ptr;
}

void	ft_str_upper(char *str)
{
	while (*str != '\0')
	{
		*str = (char)ft_toupper((int)*str);
		str++;
	}
}

void	ft_ptr_nbr_len(t_info *info, unsigned long long i)
{
	while (i >= 16)
	{
		i = i / 16;
		info->wc++;
	}
	info->wc++;
}

void	ft_rev_tab(char *tab, int size)
{
	int	i;
	int	temporary;

	i = 0;
	while (i < (size / 2))
	{
		temporary = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temporary;
		i++;
	}
}
