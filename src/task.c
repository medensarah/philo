/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:57:57 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/14 09:51:28 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*boulot_dodo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->input.nbr_philos == 1)
		return (philo_alone(philo));
	if (philo->id % 2 == 0)
		ft_usleep(1, philo->data);
	while (1)
	{
		if (philo->data->dead == 1)
			break ;
		spagetti(philo);
		if (philo->data->dead == 1)
			break ;
		dodo(philo);
		if (philo->data->dead == 1)
			break ;
		gamberge(philo);
	}
	return (NULL);
}

void	spaghetti(t_philo *philo)
{
	write(1, "eat\n", 4);
}

void	dodo(t_philo *philo)
{
	write(1, "sleep\n", 4);
}

void	gamberge(t_philo *philo)
{
	write(1, "think\n", 4);
}
