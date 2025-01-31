/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:57:12 by hdazia            #+#    #+#             */
/*   Updated: 2025/01/31 16:44:42 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_swap_bonus(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_lstsize(*stack) < 2)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}
