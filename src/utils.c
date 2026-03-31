/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:20:29 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/31 13:39:56 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_a_space(const char *str, int i)
{
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	num;

	num = 0;
	sign = 1;
	i = 0;
	i = is_a_space(str, i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1 ;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num;
		num = num + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

void	ft_putnbr(int n)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}
