/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:57:57 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/15 08:48:28 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*boulot_dodo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->input.nbr_philos == 1)
		return (NULL); // return (philo_alone(philo), NULL); A FAIRE
	if (philo->id % 2 == 0)
		ft_usleep(1, philo->data);
	while (1)
	{
		if (philo->data->dead == 1)
			break ;
		spaghetti(philo);
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
	print_action(philo, "is eating");
    ft_usleep(200, philo->data);
}

void	dodo(t_philo *philo)
{
	print_action(philo, "is sleeping");
    ft_usleep(200, philo->data);
}

void	gamberge(t_philo *philo)
{
	print_action(philo, "is thinking");
    ft_usleep(200, philo->data);
}

void	print_action(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    if (!philo->data->dead)
        printf("Philo %d %s\n", philo->id, msg);
    pthread_mutex_unlock(&philo->data->print_mutex);
}
