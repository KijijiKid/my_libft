/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_lowercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:32:30 by mandre            #+#    #+#             */
/*   Updated: 2025/04/28 14:49:09 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_lowercase(unsigned long val, int rtn_val)
{
	char	digit;

	rtn_val++;
	if (15 < val)
	{
		rtn_val = hexa_lowercase(val / 16, rtn_val);
		hexa_lowercase(val % 16, rtn_val);
	}
	else
	{
		if (val < 10)
			digit = '0' + val;
		else
			digit = (val - 10) + 'a';
		ft_putchar(digit);
	}
	return (rtn_val);
}

// int main(void)
// {
// 	unsigned int *tmp = 78200909;
//     printf("%p\n", tmp);
//     hexa_lowercase((unsigned long)tmp);
// }