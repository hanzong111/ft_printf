/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_concheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:11:36 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/13 16:41:18 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	char	*str = "%10#23.45d";
	char	c;
	int		index = 0;
	t_con	type;
	t_flags flags;

	ft_initializecon(&type);
	ft_initializeflags(&flags);
	printf("Before :value of 'index' is %d\n", index);
	ft_checks(str, &index, &type, &flags);
	printf("After :value of 'index' is %d\n", index);
	printf("Value of '0' is %d\n", flags.zero);
	printf("Value of '#' is %d\n", flags.hash);
	printf("Value of '.' is %d\n", flags.dot);
	printf("Value of '+' is %d\n", flags.plus);
	printf("Value of 'space' is %d\n", flags.space);
	printf("Value of '-' is %d\n", flags.minus);
	return (0);
}
