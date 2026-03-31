/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:59:45 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/31 19:18:21 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void launch_thread(t_input *input)
{
	int	i;
	int	n;
	t_philo philo[input->nbr_philos];

	i = 0;
	n = input->nbr_philos;
	while (i < n)
	{
		philo[i].id = i + 1;
		pthread_create(&philo[i].thread, NULL, boulot_dodo, &philo[i]);
		i++;
	}
	write(1, "END CREATE\n", 11);
	i = 0;
	while (i < n)
		pthread_join(philo[i++].thread, NULL);
	write(1, "END JOIN\n", 9);
}

void	init(t_input *input, int ac, char **av)
{
	input->nbr_philos = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eat = ft_atoi(av[3]);
	input->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		input->nb_must_eat = ft_atoi(av[5]);
	else
		input->nb_must_eat = -1;
}

int	verify_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (write(2, "Error: Only 4 or 5 arguments are accepted\n", 38), 0);
	while (i < ac)
	{
		if (is_non_digit(av[i]))
			return (write(2, "Error: only digits are allowed\n", 31), 0);
		if (is_nbr_overflow(av[i]))
			return (write(2, "Error: number out of range\n", 27), 0);
		if (ac == 6 && is_only_zero(av[i]))
			return (write(2, "Error: number cannot be zero except for arg[6]\n", 51), 0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_input input;

	if (!verify_input(ac, av))
		return (1);
	init(&input, ac, av);
	launch_thread(&input);
	write(1, "END MAIN\n", 9);
	return (0);
}
