/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:05:32 by lprieto-          #+#    #+#             */
/*   Updated: 2025/05/30 21:40:56 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ip_calc.h"

int binary_to_decimal(const char *bin)
{
    int result = 0;
    int i = 0;

    while (bin[i])
    {
        result = result * 2;
        if (bin[i] == '1')
            result = result + 1;
        i++;
    }
    return (result);
}

void decimal_to_binary(int num, char *buffer)
{
    int i = 7;
    while (i >= 0)
    {
        if (num & (1 << i))
            buffer[7 - i] = '1';
        else
            buffer[7 - i] = '0';
        i--;
    }
    buffer[8] = '\0';
}

int count_ones_in_mask(const char *ip)
{
    char temp[100];
    char *token;
    int total_ones = 0;

    strncpy(temp, ip, sizeof(temp));
    token = strtok(temp, ".");
    while (token)
    {
        int octet = atoi(token);
        for (int i = 7; i >= 0; i--)
        {
            if (octet & (1 << i))
                total_ones++;
        }
        token = strtok(NULL, ".");
    }
    return total_ones;
}