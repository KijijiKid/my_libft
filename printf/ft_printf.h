/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:19:34 by mateoandre        #+#    #+#             */
/*   Updated: 2025/04/28 11:48:46 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		print_str(char *str);
int		print_ptr(unsigned long ptr);
size_t	ft_strlen(const char *str);
int		hexa_lowercase(unsigned long val, int rtn_val);
int		hexa_uppercase(unsigned long val, int rtn_val);
int		print_int(int val, int rtn_val);
int		print_usigned(unsigned int val, int rtn_val);
int		*get_error(void);
void	set_error(int new_status);
int		ft_putchar(char c);

#endif