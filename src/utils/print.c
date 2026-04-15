/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 09:23:00 by smedenec          #+#    #+#             */
/*   Updated: 2026/04/15 13:25:28 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print(t_philo *philo, char *msg)
{
    long    now;

    pthread_mutex_lock(&philo->data->print_mutex);
    if (!philo->data->dead)
    {
        now = get_time() - philo->data->start_time; 
        printf("%ld %d %s\n", now, philo->id, msg);
    }
    pthread_mutex_unlock(&philo->data->print_mutex);
}