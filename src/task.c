/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:57:57 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/14 08:17:36 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*boulot_dodo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	check_death(philo);
	return (NULL);
}

void	check_death(t_philo *philo)
{
	int	id;

	id = philo->id;

	ft_putnbr(id);
	write(1, "\n", 1);
}
