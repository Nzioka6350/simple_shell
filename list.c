#include "shell.h"
/**
 * add_node - Add a node to the start of a linked list.
 * @head: Address of the pointer to the head node.
 * @str: String field of the new node.
 * @num: Node index used by history.
 *
 * This function is used to add a new node to the start of a linked list.
 * The @head parameter is the address of the
 * pointer to the head node of the list.
 * The @str parameter represents the string
 * field of the new node, and the @num
 * parameter is the node index used for history tracking.
 *
 * The function returns the size of the list after adding the new node.
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}
/**
 * add_node_end - Add a node to the end of a linked list.
 * @head: Address of the pointer to the head node.
 * @str: String field of the new node.
 * @num: Node index used by history.
 *
 * This function is used to add a new node to the end of a linked list.
 * The @head parameter is the address of the
 * pointer to the head node of the list.
 * The @str parameter represents the string
 * field of the new node, and the @num
 * parameter is the node index used for history tracking.
 *
 * The function returns the size of the list after adding the new node.
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
/**
 * print_list_str - Print the string element of each node in a linked list.
 * @h: Pointer to the first node of the linked list.
 *
 * This function is used to print the string
 * element of each node in a linked list.
 * The @h parameter points to the first node of the list.
 * It iterates through the
 * linked list and prints the string element of each node.
 *
 * The function doesn't return a specific value;
 * it primarily serves to display
 * the string elements of the linked list nodes.
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * delete_node_at_index - Delete a node at a given index in a linked list.
 * @head: Address of the pointer to the first node.
 * @index: Index of the node to delete.
 *
 * This function is used to delete a node.
 * at the specified index in a linked list.
 * The @head parameter is the address of
 * the pointer to the first node of the list.
 * The @index parameter indicates the index
 * of the node to be deleted.
 *
 * If the deletion is successful, the function returns 1.
 * If the specified index is
 * out of range or an error occurs during deletion,
 * the function returns 0.
 *
 * Return: 1 on successful deletion, 0 on failure.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}
/**
 * free_list - Free all nodes of a linked list.
 * @head_ptr: Address of the pointer to the head node.
 *
 * This function is used to free all nodes of a linked list.
 * The @head_ptr parameter
 * is the address of the pointer to the head node of the list.
 * The function iterates through the linked list,
 * freeing memory associated with each node, and updates
 * the head pointer accordingly.
 *
 * Return: void.
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
