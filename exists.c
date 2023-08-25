#include "shell.h"
/**
 * _strncpy - Copy a string with limited length
 * @dest: The destination buffer to copy to
 * @src: The source string to copy from
 * @n: The maximum number of characters to copy
 * 
 * Description: This function copies up to @n characters from the @src string
 * to the @dest buffer. If the @src string is shorter than @n characters,
 * null bytes are appended to @dest to ensure a total of @n characters are written.
 * 
 * Return: Pointer to the destination buffer @dest.

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - Concatenates two strings with a length limit
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of characters to append from @src
 * 
 * Return: A pointer to the resulting string @dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - Locates a character in a string
 * @s: The string to be searched
 * @c: The character to be located
 * 
 * Return: A pointer to the first occurrence of character @c in string @s,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

