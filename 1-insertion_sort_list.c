#include "sort.h"
/**
  *get_list_length-get the length of the doubly linked list
  *@list: pointer to the head of the list
  @Return: length of the list
  */
int get_list_length(listint_t **list)
{
	int len;
	listint_t *ptr;

	if (list == NULL || (*list) == NULL)
		return (0);
	ptr = *list;
	len = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		len = len + 1;
	}
	return (len);
}
/**
  *swap_node-swap two nodes in a doubly linked list
  *@list: the list
  *@l_node: the first node to be compared
  *@r_node: the second node to be compared
  *Return: void
  */
void swap_node(listint_t **list, listint_t *l_node, listint_t *r_node)
{
	if (l_node->prev == NULL)
	{
		*list = r_node;
		r_node->prev = NULL;
	}
	else
	{
		l_node->prev->next = r_node;
		r_node->prev = l_node->prev;
	}
	if (r_node->next == NULL)
	{
		l_node->next = NULL;
	}
	else
	{
		r_node->next->prev = l_node;
		l_node->next = r_node->next;
	}
	l_node->prev = r_node;
	r_node->next = l_node;
}
/**
  *insertion_sort_list-sorts a doubly linked list  of integers in ascending
  *@list: pointer to list
  *Return: void
  */
void insertion_sort_list(listint_t **list)
{
	int list_len;
	listint_t *current;

	list_len = get_list_length(list);
	if (list_len < 2)
		return;
	current = *list;
	while (current->next != NULL)
	{
		if (current->n > current->next->n)
		{
			swap_node(list, current, current->next);
			print_list(*list);
			current = *list;
		}
		else
		{
			current = current->next;
		}
	}
}
