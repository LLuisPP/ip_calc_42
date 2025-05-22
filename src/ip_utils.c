/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:05:55 by lprieto-          #+#    #+#             */
/*   Updated: 2025/05/22 19:10:35 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ip_calc.h"

int is_valid_octet_decimal(const char *str)
{
    int i = 0;
    int num = 0;

    while (str[i])
    {
        if (!isdigit(str[i]))
            return (0);
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num >= 0 && num <= 255);
}

int is_valid_octet_binary(const char *str)
{
    int i = 0;

    if (strlen(str) != 8)
        return (0);
    while (str[i])
    {
        if (str[i] != '0' && str[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

int count_dots(const char *str)
{
    int count = 0;

    while (*str)
    {
        if (*str == '.')
            count++;
        str++;
    }
    return (count);
}

int is_valid_decimal_ip(const char *str)
{
    char temp[100];
    char *token;
    int count = 0;

    strncpy(temp, str, sizeof(temp));
    token = strtok(temp, ".");
    while (token)
    {
        if (!is_valid_octet_decimal(token))
            return (0);
        token = strtok(NULL, ".");
        count++;
    }
    return (count == 4);
}

int is_valid_binary_ip(const char *str)
{
    char temp[200];
    char *token;
    int count = 0;

    strncpy(temp, str, sizeof(temp));
    token = strtok(temp, ".");
    while (token)
    {
        if (!is_valid_octet_binary(token))
            return (0);
        token = strtok(NULL, ".");
        count++;
    }
    return (count == 4);
}

