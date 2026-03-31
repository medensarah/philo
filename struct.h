/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:21:24 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/31 13:18:08 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_input
{
	int	number_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_must_eat;
}	t_input;

typedef struct s_philo
{
	int	id;
	pthread_t thread;
}	t_philo;

#endif
