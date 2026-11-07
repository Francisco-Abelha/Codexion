/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 15:32:18 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/11/07 16:42:04 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	destroy_dongles(t_simulation *sim, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&sim->dongles[i].lock);
		i++;
	}
	free(sim->dongles);
	sim->dongles = NULL;
}

void	destroy_coders(t_simulation *sim, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&sim->coders[i].compile_info_lock);
		i++;
	}
	free(sim->coders);
	sim->coders = NULL;
}

void	cleanup(t_simulation *sim)
{
	destroy_dongles(sim, sim->rules.number_of_coders);
	destroy_coders(sim, sim->rules.number_of_coders);
	destroy_shared(sim);
}

void	destroy_shared(t_simulation *sim)
{
	pthread_mutex_destroy(&sim->sim_over_lock);
	pthread_mutex_destroy(&sim->print);
}
