/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:51:30 by lprieto-          #+#    #+#             */
/*   Updated: 2025/05/30 21:46:20 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ip_calc.h"

void convert_single_octet_decimal(const char *input)
{
    int num = atoi(input);
    char buffer[9];
    decimal_to_binary(num, buffer);
    printf("Binario - %s\n", buffer);
}

void convert_single_octet_binary(const char *input)
{
    int num = binary_to_decimal(input);
    printf("Decimal - %d\n", num);
}

void convert_decimal_ip(const char *input)
{
    char temp[100];
    char *token;
    char result[100] = "";
    char buffer[9];
    int count = 0;

    strncpy(temp, input, sizeof(temp));
    token = strtok(temp, ".");
    while (token)
    {
        if (count > 0)
            strcat(result, ".");
        int num = atoi(token);
        decimal_to_binary(num, buffer);
        strcat(result, buffer);
        count++;
        token = strtok(NULL, ".");
    }
    printf("Binario - %s\n", result);
}

void convert_binary_ip(const char *input)
{
    char temp[200];
    char *token;
    char result[100] = "";
    int count = 0;

    strncpy(temp, input, sizeof(temp));
    token = strtok(temp, ".");
    while (token)
    {
        if (count > 0)
            strcat(result, ".");
        int num = binary_to_decimal(token);
        char dec_str[4];
        sprintf(dec_str, "%d", num);
        strcat(result, dec_str);
        count++;
        token = strtok(NULL, ".");
    }
    printf("Decimal - %s\n", result);
}

int main(int argc, char **argv)
{
    char    input[200];
    int     cidr;

    if (argc != 3)
    {
        print_usage(argv[0]);
        return (1);
    }

    strncpy(input, argv[2], sizeof(input));
    input[sizeof(input) - 1] = '\0';
    
    if (strcmp(argv[1], "-d") == 0)
    {
        printf("Resultado:\n");
        printf("Decimal - %s\n", input);
        if (is_valid_decimal_ip(input))
        {
            convert_decimal_ip(input);
            cidr = count_ones_in_mask(input);
            printf("CIDR - /%d\n", cidr);
        }
        else if (is_valid_octet_decimal(input))
            convert_single_octet_decimal(input);
        else
            printf("Error: decimal no válido\n");
    }
    else if (strcmp(argv[1], "-b") == 0)
    {
        printf("Resultado:\n");
        printf("Binario - %s\n", input);
        if (is_valid_binary_ip(input))
            convert_binary_ip(input);
        else if (is_valid_octet_binary(input))
            convert_single_octet_binary(input);
        else
            printf("Error: binario no válido\n");
    }
    else
    {
        print_usage(argv[0]);
    }
    return (0);
}
