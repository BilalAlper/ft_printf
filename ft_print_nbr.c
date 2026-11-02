/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balper <balper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 00:01:02 by balper            #+#    #+#             */
/*   Updated: 2026/11/02 00:38:56 by balper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	digit_count(int num)
{
	int	digit;

	digit = 0;
	if (num == 0)
		return (1);
	else if (num > 0)
	{
		while (num > 0)
		{
			digit++;
			num = num / 10;
		}
	}
	else
	{
		digit++;
		while (num < 0)
		{
			digit++;
			num = num / 10;
		}
	}
	return (digit);
}

static char	*ft_itoa(int num)
{
	char	*num_str;
	int		i;

	i = digit_count(num);
	num_str = malloc(sizeof(char) * i + 1);
	if (!num_str)
		return (NULL);
	num_str[i--] = '\0';
	if (num == 0)
		num_str[i] = '0';
	while (num > 0)
	{
		num_str[i--] = '0' + num % 10;
		num = num / 10;
	}
	if (num < 0)
		num_str[0] = '-';
	while (num < 0)
	{
		num_str[i--] = '0' - num % 10;
		num = num / 10;
	}
	return (num_str);
}

int	ft_print_nbr(int num)
{
	char	*str;
	int		return_value;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	return_value = write(1, str, ft_strlen(str));
	free(str);
	return (return_value);
}
