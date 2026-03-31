/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:13:01 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/31 13:42:05 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	hello(t_philo *philo)
{
	int id;

	id = philo->id;
	write(1, "Hello, philosopher number ", 26);
	ft_putnbr(id);
	write(1, "\n", 1);
}

void	*boulot_dodo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	hello(philo);
	return (NULL);
}

void	launch_thread(int n)
{
	int i;
	t_philo philo[n];

	i = 0;
	while(i < n)
	{
		philo[i].id = i + 1;
		pthread_create(&philo[i].thread, NULL, boulot_dodo, &philo[i]);
		i++;
	}
	write(1, "END CREATE\n", 11);
	i = 0;
	while(i < n)
		pthread_join(philo[i++].thread, NULL);
	write(1, "END JOIN\n", 9);
}

int	main(int ac, char **av)
{
	int n;

	if (ac <= 2 || !av[1])
		return (1);
	//if (!init(input))
	// return (1);
	n = ft_atoi(av[1]);
	launch_thread(n);
	write(1, "END MAIN\n", 9);
	return (0);
}
