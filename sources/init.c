/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:58:44 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/11/07 16:41:44 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_dongles(t_simulation *sim)
{
	int			n;
	int			i;
	t_dongle	*arr;

	n = sim->rules.number_of_coders;
	arr = malloc(n * sizeof(t_dongle));
	if (!arr)
		return (0);
	sim->dongles = arr;
	i = 0;
	while (i < n)
	{
		sim->dongles[i].taken = 0;
		sim->dongles[i].released_at = 0;
		if (pthread_mutex_init(&sim->dongles[i].lock, NULL) != 0)
			return (destroy_dongles(sim, i), 0);
		i++;
	}
	return (1);
}

int	init_coders(t_simulation *sim)
{
	int		n;
	int		i;
	t_coder	*coders;

	n = sim->rules.number_of_coders;
	coders = malloc(n * sizeof(t_coder));
	if (!coders)
		return (0);
	sim->coders = coders;
	i = 0;
	while (i < n)
	{
		sim->coders[i].id = i + 1;
		sim->coders[i].num_compiles = 0;
		sim->coders[i].last_compile_start_value = 0;
		sim->coders[i].left_dongle = &sim->dongles[(i - 1 + n) % n];
		sim->coders[i].right_dongle = &sim->dongles[i];
		sim->coders[i].simulation = sim;
		if (pthread_mutex_init(&sim->coders[i].compile_info_lock, NULL) != 0)
			return (destroy_coders(sim, i), 0);
		i++;
	}
	return (1);
}

int	init_simulation(t_simulation *sim)
{
	int	n;

	n = sim->rules.number_of_coders;
	sim->dongles = NULL;
	sim->coders = NULL;
	if (pthread_mutex_init(&sim->sim_over_lock, NULL) != 0)
		return (0);
	sim->sim_over_bool = 0;
	if (pthread_mutex_init(&sim->print, NULL) != 0)
		return (pthread_mutex_destroy(&sim->sim_over_lock), 0);
	if (!init_dongles(sim))
		return (destroy_shared(sim), 0);
	if (!init_coders(sim))
		return (destroy_dongles(sim, n), destroy_shared(sim), 0);
	return (1);
}
