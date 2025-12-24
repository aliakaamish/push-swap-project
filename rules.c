/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzahredd <nzahredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:00:30 by nzahredd          #+#    #+#             */
/*   Updated: 2025/12/24 20:28:35 by nzahredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*t_node *delete_head(t_node *head)
{
	if (head == NULL)
		return NULL;
	t_node *temp = head;
	head = head->next;
	free(temp);
	return (head);
}

int pop_node(t_stack *stack)
{
	t_node *temp;
	int value;
	
	if (stack->top == NULL)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	
	if (stack->top != NULL)
		stack->top->previous = NULL;
	free(temp);
	return (value);
}

void sa(t_node *a)
{
	int temp;

	if (a == NULL || a->next == NULL)
		return ;
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
	write(1,"sa\n",3);
}

void sb(t_stack *b)
{
	int temp;

	if (b->top == NULL || b->top->next == NULL)
		return ;
	temp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = temp;
	write(1,"sb\n",3);

}
void ss(t_node *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1,"ss\n",3);

}

void pa(t_node *a, t_node *b)
{
	t_node *temp;
	
	if (b == NULL)
		return ;
	temp = b;
	b = b->next;
	b->previous = NULL;
	temp->next = a;
	a->previous = temp;
	temp->previous = NULL;
	a = temp;
	write(1,"pa\n",3);

}

void pb(t_node *a, t_node *b)
{
	t_node *temp;
	
	if (a == NULL)
		return ;
	temp = a;
	a = a->next;
	a->previous = NULL;
	temp->next = b;
	b->previous = temp;
	temp->previous = NULL;
	b = temp;
	write(1,"pb\n",3);

}

void ra(t_stack *a)
{	
	int value;
	t_node *temp;
	t_node *new_node;
	
	if(a->top == NULL || a->top->next == NULL)
		return ;
	value = pop_node(a);
	a->top = delete_head(a->top);
	temp = a->top;
	while (temp->next != NULL)
		temp = temp->next;
	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = temp;
	temp->next = new_node;
	write(1,"ra\n",3);
	
}

void rb(t_stack *b)
{	
	int value;
	t_node *temp;
	t_node *new_node;
	
	if(b->top == NULL || b->top->next == NULL)
		return ;
	value = pop_node(b);
	b->top = delete_head(b->top);
	temp = b->top;
	while (temp->next != NULL)
		temp = temp->next;
	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = temp;
	temp->next = new_node;
	write(1,"rb\n",3);

}

void rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1,"rr\n",3);

}
void rra(t_stack *a)
{
	t_node *temp;

	if (a->top == NULL)
		return ;
	temp = a->top;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = a->top;
	temp->previous->next = NULL;
	temp->previous = NULL;
	write(1,"rra\n",3);

}

void rrb(t_stack *b)
{
	t_node *temp;

	if (b->top == NULL)
		return ;
	temp = b->top;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = b->top;
	temp->previous->next = NULL;
	temp->previous = NULL;
	write(1,"rrb\n",3);

}

void rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1,"rrr\n",3);

}

void ft_simple_strategy(t_node *a)
{
    t_node *ptr;
    t_node *b;
    t_node *result;

    result = NULL;
    b = NULL; // b is empty at the start
    if (a == NULL)
        return ;
    ptr = a;

    while (ptr != result)
    {
        while (ptr->next != result && ptr->next != NULL)
        {
            // Only swap if next exists
            if (ptr->next && ptr->next->value < ptr->value)
                sa(ptr);

            ptr = ptr->next;

            // pb: push only if ptr->previous is valid
            if (ptr && ptr->previous)
                pb(ptr->previous, b);
        }

        result = ptr;

        // pa: push back while b is not empty
        while (b)
            pa(b, ptr);

        // Move result backwards safely
        if (result)
            result = result->previous;
    }
}

#include <stdio.h>




===== helpers ===== */

/*t_node *new_node(int value)
{
	t_node *n = malloc(sizeof(t_node));
	n->value = value;
	n->next = NULL;
	n->previous = NULL;
	return n;
}

void print_list(t_node *a)
{
	while (a)
	{
		printf("%d ", a->value);
		a = a->next;
	}
	printf("\n");
}



int main(void)
{
	t_node *a = new_node(3);
	t_node *n2 = new_node(1);
	t_node *n3 = new_node(2);

	a->next = n2;
	n2->previous = a;
	n2->next = n3;
	n3->previous = n2;

	printf("Before: ");
	print_list(a);

	ft_simple_strategy(a);

	printf("After:  ");
	print_list(a);

	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_node
{
    int value;
    struct t_node *next;
    struct t_node *previous;
} t_node;

/* ===== Operations ===== */

void sa(t_node *a)
{
    int temp;
    if (a == NULL || a->next == NULL)
        return;
    temp = a->value;
    a->value = a->next->value;
    a->next->value = temp;
    write(1, "sa\n", 3);
}

void pa(t_node **b, t_node **a)
{
    t_node *temp;
    if (*b == NULL)
        return;
    temp = *b;
    *b = (*b)->next;
    if (*b)
        (*b)->previous = NULL;
    temp->next = *a;
    if (*a)
        (*a)->previous = temp;
    temp->previous = NULL;
    *a = temp;
    write(1, "pa\n", 3);
}

void pb(t_node **a, t_node **b)
{
    t_node *temp;
    if (*a == NULL)
        return;
    temp = *a;
    *a = (*a)->next;
    if (*a)
        (*a)->previous = NULL;
    temp->next = *b;
    if (*b)
        (*b)->previous = temp;
    temp->previous = NULL;
    *b = temp;
    write(1, "pb\n", 3);
}

/* ===== Strategy ===== */
void ft_simple_strategy(t_node **a)
{
    t_node *ptr;
    int swapped;

    if (!a || !*a)
        return;

    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        ptr = *a;
        while (ptr->next != NULL)
        {
            if (ptr->value > ptr->next->value)
            {
                sa(ptr);
                swapped = 1;
            }
            ptr = ptr->next;
        }
    }
}


/* ===== Helpers ===== */

t_node *new_node(int value)
{
    t_node *n = malloc(sizeof(t_node));
    n->value = value;
    n->next = NULL;
    n->previous = NULL;
    return n;
}

void print_list(t_node *a)
{
    while (a)
    {
        printf("%d ", a->value);
        a = a->next;
    }
    printf("\n");
}

/* ===== Main ===== */

int main(void)
{
    t_node *a = new_node(3);
    t_node *n2 = new_node(1);
    t_node *n3 = new_node(2);
    t_node *n4 = new_node(2);
    t_node *n5 = new_node(2);
    t_node *n3 = new_node(2);


    a->next = n2;
    n2->previous = a;
    n2->next = n3;
    n3->previous = n2;

    printf("Before: ");
    print_list(a);

    ft_simple_strategy(&a);

    printf("After:  ");
    print_list(a);

    return 0;
}

