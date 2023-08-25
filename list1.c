#include "shell.h"

/**
 * list_len - Determines the length of a linked list.
 * @h: Pointer to the first node of the list.
 *
 * Return: Size of the list.
 */
size_t list_len(const list_t *b);

{
	size_t k = 0;

	while (b)
	{
		b = b->next;
		k++;
	}
	return (k);
}

/**
 * list_to_strings - Converts a linked list of strings to an array of strings.
 * @head: Pointer to the first node of the list.
 *
 * Return: Array of strings.
 */
char **list_to_strings(list_t *head)
{
    // Function implementation goes here
}
	list_t *node = head;
	size_t k = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !k)
		return (NULL);
	strs = malloc(sizeof(char *) * (k + 1));
	if (!strs)
		return (NULL);
	for (k = 0; node; node = node->next, k++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < k; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[k] = str;
	}
	strs[k] = NULL;
	return (strs);
}

/**
 * print_list - Prints all elements of a list_t linked list.
 * @h: Pointer to the first node of the list.
 *
 * Return: Size of the list.
 */
size_t print_list(const list_t *b)
{
    // Function implementation goes here
}

	size_t k = 0;

	while (b)
	{
		_puts(convert_number(b->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(b->str ? b->str : "(nil)");
		_puts("\n");
		b = b->next;
		k++;
	}
	return (k);
}

/**
 * node_starts_with - Returns the node whose string starts with a given prefix.
 * @node: Pointer to the list head.
 * @prefix: String to match as a prefix.
 * @c: The next character after the prefix to match.
 *
 * Return: Matching node or NULL.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - Gets the index of a node in the linked list.
 * @head: Pointer to the list head.
 * @node: Pointer to the node.
 *
 * Return: Index of the node or -1 if not found.
 */

 size_t get_node_index(list_t *head, list_t *node)
{
	size_t k = 0;

	while (head)
	{
		if (head == node)
			return (k);
		head = head->next;
		k++;
	}
	return (-1);
}

