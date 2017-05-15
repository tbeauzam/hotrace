/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hotrace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:57:39 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/05/14 16:24:21 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned long		hash_djb(char *s)
{
	unsigned long	hash;
	int				c;

	hash = HASH_CONST;
	while ((c = *s++))
		hash = ((hash << 5) + (hash >> 2)) + c;
	return (hash);
}

int			prepare_memory(t_data *d)
{
	if (!(d->mem_dic = (t_dic *)malloc(sizeof(t_dic) * (d->nb_duo >> 1))))
		return (0);
	if (!(d->mem_value = (char *)malloc(sizeof(char) * d->value_size)))
		return (0);
	ft_bzero(d->mem_dic, sizeof(t_dic) * (d->nb_duo >> 1));
	ft_bzero(d->mem_value, sizeof(char) * (d->value_size));
	return (1);
}

int					main(void)
{
	t_data			d;
	t_dic			*table[HASH_SIZE];

	ft_bzero(table, sizeof(table));
	d.nb_duo = 0;
	d.end_duo = 0;
	d.value_size = 0;
	d.mem_dic = NULL;
	d.mem_value = NULL;
	d.index_mem_dic = 0;
	d.index_mem_value = 0;
	d.hash = 0;
	d.value = NULL;
	d.total = 0;
	d.buff_index = 0;
	ft_bzero(d.buffer, sizeof(d.buffer));
	read_stdin(&d);
	if (!(prepare_memory(&d)))
		return (1);
	hash_keys(&d, table);
	treat_requests(&d, table);
//	printf("Heya : \n");
//	ft_putstr(d.data);
//	printf("nb lignes : %d\nDebut requetes : %d\nTaille totale values : %d\n", d.nb_duo, d.end_duo, d.value_size);
//	printf("sizeof t_dic : %lU\n", sizeof(t_dic));
/*	t_dic *tmp;
	for (int i = 0; i < HASH_SIZE; i++)
	{
		tmp = table[i];
		while (tmp)
		{
			printf(" --> Hash : %lu | value : %s", tmp->key_hash, tmp->value);
			fflush(NULL);
			tmp = tmp->next;
		}
		printf("\n");
	}
*/	return (0);
}
