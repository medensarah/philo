/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 08:49:17 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/14 09:07:13 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long	get_time(void)
{
	struct timeval	v;

	gettimeofday(&v, NULL);
	return (v.tv_sec * 1000 + v.tv_usec / 1000);
}

void	ft_usleep(long milisec, t_data *data)
{
	long	start;

	start = get_time();
	while (!data->dead)
	{
		if (get_time() - start >= milisec)
			break ;
		usleep(100);
	}
}
