/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:57:57 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/31 14:02:31 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*boulot_dodo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	hello(philo);
	return (NULL);
}

void	hello(t_philo *philo)
{
	int id;

	id = philo->id;
	write(1, "Hello, philosopher number ", 26);
	ft_putnbr(id);
	write(1, "\n", 1);
}
