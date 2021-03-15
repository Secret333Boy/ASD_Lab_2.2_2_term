#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
	double data;
	struct linked_list * next_p;
	struct linked_list * prev_p;
} l_list;

l_list * l_list_init(double item)
{
	l_list *l_p;
	l_p = malloc(sizeof(struct linked_list));

	l_p->data = item;
	l_p->next_p = l_p;
	l_p->prev_p = NULL;
	return l_p;
}

l_list * get_last_node(l_list *l_p)
{
	l_list *this_p = l_p;
	while(this_p->prev_p)
	{
		this_p = this_p->prev_p;
	}
	return this_p;
}

l_list * add_node(l_list *l_p, double item)
{
	l_list *node_p;
	node_p = malloc(sizeof(struct linked_list));
	l_p->next_p = node_p;

	node_p->data = item;
	node_p->next_p = get_last_node(l_p);
	node_p->prev_p = l_p;
	return node_p;
}

//remove node from begining
l_list * unshift_node(l_list *l_p)
{
	l_list *new_l_p = l_p->prev_p;
	new_l_p->next_p = l_p->next_p;
	free(l_p);
	return new_l_p;
}

//remove node from end
l_list * pop_node(l_list *l_p)
{
	if (l_p->next_p != l_p)
	{
		l_list *last_node = l_p->next_p;

		last_node->next_p->prev_p = NULL;

		l_p->next_p = last_node->next_p;

		free(last_node);
		return l_p;
	} else {
		free(l_p);
		return NULL;
	}
}

int main()
{
	system("cls");
	unsigned int n = 0;

	while(n <= 0 || n % 2 != 0)
	{
		printf("n (n %% 2 = 0; n > 0): ");
		scanf("%u", &n);
	}

	l_list *list_p;
	for (unsigned int i = n; i >= 1; i--)
	{
		double a;
		printf("a%u: ", i);
		scanf("%lf", &a);

		if (i == n)
		{
			//initialization
			list_p = l_list_init(a);
		} else {
			//fulfilling
			list_p = add_node(list_p, a);
		}
	}
	
	//operations
	double result = 0;
	while (list_p) {
		result += 2 * (list_p->data) * (list_p->next_p->data);
		list_p = unshift_node(list_p);
		list_p = pop_node(list_p);
	}

	printf("Result: %lf\n", result);
	system("pause");
	return 0;
}		