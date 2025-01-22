/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_elemrnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:28:23 by hdazia            #+#    #+#             */
/*   Updated: 2025/01/21 19:44:30 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     calculat_cost_b(int pos, int    size_stack)
{
    if(pos <= size_stack / 2)
        return (pos);
    else
        pos = pos - size_stack;
    return (pos);
}
int     calculat_cost_a(int target_pos, int    size_stack)
{
    if (target_pos <= size_stack / 2)
        return (target_pos);
    else
       return (target_pos - size_stack);
}
void cost_element(t_stack **stack_a, t_stack    **stack_b)
{
    int size_a;
    int size_b;

    
    size_a = ft_lstsize(*stack_a);
    size_a = ft_lstsize(*stack_b);
    t_stack *head_b = *stack_b;
    while (head_b)
    {
        head_b->cost_b = calculat_cost_b(head_b->pos, size_b);
        head_b->cost_a = calculat_cost_a(head_b->target_pos, size_a);
        head_b = head_b->next;
    }
}