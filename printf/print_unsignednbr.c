/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:43:02 by mateoandre        #+#    #+#             */
/*   Updated: 2025/04/28 12:34:38 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_usigned(unsigned int val, int rtn_val)
{
	int	digit;

	if (9 < val)
	{
		rtn_val++;
		rtn_val = print_int(val / 10, rtn_val++);
		print_int(val % 10, rtn_val);
	}
	else
	{
		digit = 48 + val;
		rtn_val += ft_putchar(digit);
	}
	return (rtn_val);
}
