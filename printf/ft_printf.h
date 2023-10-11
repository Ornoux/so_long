/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:21:23 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/04 09:21:25 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_printstr(char *str);
int				ft_printnbr(int nb);
int				ft_printunsnbr(unsigned int nb);
void			ft_putchar(char c);
int				ft_printhexbnbr(unsigned long long nb);
int				ft_printhexlnbr(unsigned long long nb);
int				ft_printchar(char c);

#endif