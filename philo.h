/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:10:59 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/31 18:51:39 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "struct.h"

//main
void	launch_thread(t_input *input);
void	init(t_input *input, int ac, char **av);
int		verify_input(int ac, char **av);

//task
void	*boulot_dodo(void *arg);
void	hello(t_philo *philo);

//utils_nbr
int		ft_atoi(char *str);
void	ft_putnbr(int n);
int		is_non_digit(char *str);
int		is_nbr_overflow(char *str);
int		is_only_zero(char *str);

#endif
