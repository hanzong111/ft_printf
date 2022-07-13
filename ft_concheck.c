/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:52:03 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/13 16:38:09 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_concheck(char c, t_con *type)
{	
	int	x;
	int	y;
	int	z;

	x = ft_concheck1(c, type);
	y = ft_concheck2(c, type);
	z = ft_concheck3(c, type);
	if (x == y)
	{
		if (y == z)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	ft_concheck1(char c, t_con *type)
{
	if (c == 'c')
	{
		(*type).c = 1;
		return (0);
	}
	else if (c == 's')
	{
		(*type).s = 1;
		return (0);
	}
	else if (c == 'p')
	{
		(*type).p = 1;
		return (0);
	}
	else
		return (1);
}

int	ft_concheck2(char c, t_con *type)
{	
	if (c == 'd')
	{
		(*type).d = 1;
		return (0);
	}
	else if (c == 'i')
	{
		(*type).i = 1;
		return (0);
	}
	else if (c == 'u')
	{
		(*type).u = 1;
		return (0);
	}
	else
		return (1);
}

int	ft_concheck3(char c, t_con *type)
{	
	if (c == 'x')
	{
		(*type).x = 1;
		return (0);
	}
	else if (c == 'X')
	{
		(*type).capx = 1;
		return (0);
	}
	else
		return (1);
}
