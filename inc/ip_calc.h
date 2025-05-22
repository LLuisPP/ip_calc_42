/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_calc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:23:36 by lprieto-          #+#    #+#             */
/*   Updated: 2025/05/22 19:18:40 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IP_CALC_H
# define IP_CALC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*********** ip_calc.c ************/

void    convert_single_octet_decimal(const char *input);
void    convert_single_octet_binary(const char *input);
void    convert_decimal_ip(const char *input);
void    convert_binary_ip(const char *input);

/*********** ip_convert.c ************/

int     binary_to_decimal(const char *bin);
void    decimal_to_binary(int num, char *buffer);

/*********** ip_prints.c ************/

void    print_usage(const char *prog);

/*********** ip_utils.c ************/

int     is_valid_octet_decimal(const char *str);
int     is_valid_octet_binary(const char *str);
int     count_dots(const char *str);
int     is_valid_decimal_ip(const char *str);
int     is_valid_binary_ip(const char *str);

#endif