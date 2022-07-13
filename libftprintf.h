/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:02:49 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/13 18:55:51 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include"libft/libft.h"
# include <stdio.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	wc;
	int	width;
	int	index;
	int	c;
	int	s;
	int	p;
	int	d;
	int	i;
	int	u;
	int	x;
	int	capx;
	int	percent;
}	t_flags;

void	ft_initializeflags(t_flags *var);

void	ft_checks(char	*str, int index, t_flags *flags);
int		ft_concheck(char c, t_flags *type);
int		ft_concheck1(char c, t_flags *type);
int		ft_concheck2(char c, t_flags *type);
int		ft_concheck3(char c, t_flags *type);
void	ft_flagscheck(char c, t_flags *flags);
void	ft_print(t_flags *flags, char *str, int index);
void	ft_print_percent(t_flags *flags, char *str, int index);

#endif