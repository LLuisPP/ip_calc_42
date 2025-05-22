/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:05:44 by lprieto-          #+#    #+#             */
/*   Updated: 2025/05/22 19:11:38 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ip_calc.h"

void print_usage(const char *prog)
{
    printf("Uso:\n");
    printf("  %s -d <decimal | IP>\n", prog);
    printf("  %s -b <binario | IP binaria>\n", prog);
}
