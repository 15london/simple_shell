#include "shell.h"

/**
 * **strtow - Splits a string into words. Repeat delimiters are ignored.
 * @str: The input string.
 * @d: The delimiter string.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */

char **strtow(char *str, char *f)
{
	int k, j, b, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!f)
		f = " ";
	for (k = 0; str[k] != '\0'; k++)
		if (!is_delim(str[k], f) && (is_delim(str[k + 1], f) || !str[k + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (k = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[k], f))
			i++;
		b = 0;
		while (!is_delim(str[k + b], f) && str[k + b])
			b++;
		s[j] = malloc((b + 1) * sizeof(char));
		if (!s[j])
		{
			for (b = 0; b < j; b++)
				free(s[b]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < b; n++)
			s[j][n] = str[k++];
		s[j][n] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - Splits a string into words.
 * @str: The input string.
 * @d: The delimiter.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */

char **strtow2(char *str, char d)
{
	int k, j, b, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (k = 0; str[k] != '\0'; k++)
		if ((str[k] != d && str[k + 1] == d) ||
				    (str[k] != d && !str[k + 1]) || str[k + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (k = 0, j = 0; j < numwords; j++)
	{
		while (str[k] == d && str[k] != d)
			k++;
		k = 0;
		while (str[k + b] != d && str[k + b] && str[k + b] != d)
			b++;
		s[j] = malloc((b + 1) * sizeof(char));
		if (!s[j])
		{
			for (b = 0; b < j; b++)
				free(s[b]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < b; n++)
			s[j][n] = str[k++];
		s[j][n] = 0;
	}
	s[j] = NULL;
	return (s);
}

