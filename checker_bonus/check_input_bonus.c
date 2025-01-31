/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:53:23 by hdazia            #+#    #+#             */
/*   Updated: 2025/01/31 13:23:01 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_print_error_free(char *str, char **pointer)
{
	free_split(pointer);
	ft_putendl_fd_bonus(str, 1);
	exit(-1);
}

static int	ft_is_duplicate(long value, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi_bonus(av[i]) == value)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit_bonus(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_check_empty_input(int ac, char **av)
{
	int	i;
	int	j;
	int	is_empty;

	i = 0;
	while (i < ac)
	{
		j = 0;
		is_empty = 1;
		while (av[i][j] != '\0')
		{
			if (av[i][j] != ' ')
			{
				is_empty = 0;
				break ;
			}
			j++;
		}
		if (is_empty)
			ft_print_error_bonus("Error");
		i++;
	}
}

char	**ft_check_input_bonus(int ac, char **av)
{
	long	value;
	int		i;
	char	**pointer;

	i = 0;
	ft_check_empty_input(ac, av);
	if (ac == 2)
		pointer = ft_split_bouns(av[1], ' ');
	else
		pointer = ft_join_all_argument_bonus(av, ac);
	if (pointer == NULL)
		exit(-1);
	while (pointer[i])
	{
		value = ft_atoi_2_bonus(pointer[i], pointer);
		if (ft_is_number(pointer[i]) == 0)
			ft_print_error_free("Error", pointer);
		if (ft_is_duplicate(value, pointer, i) == 0)
			ft_print_error_free("Error", pointer);
		if (value > INT_MAX || value < INT_MIN)
			ft_print_error_free("Error", pointer);
		i++;
	}
	return (pointer);
}
