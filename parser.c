#include "shell.h"

/**
 * is_cmd - Determines if a file is an executable command.
 * @info: The info struct.
 * @path: Path to the file.
 *
 * Return: 1 if true, 0 otherwise.
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Duplicates characters.
 * @pathstr: The PATH string.
 * @start: Starting index.
 * @stop: Stopping index.
 *
 * Return: Pointer to the new buffer.
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int k = 0, b = 0;

	for (b = 0, k = start; k < stop; k++)
		if (pathstr[k] != ':')
			buf[b++] = pathstr[k];
	buf[b] = 0;
	return (buf);
}

/**
 * find_path - Finds this cmd in the PATH string.
 * @info: The info struct.
 * @pathstr: The PATH string.
 * @cmd: The cmd to find.
 *
 * Return: Full path of cmd if found, or NULL.
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int k = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[k] || pathstr[k] == ':')
		{
			path = dup_chars(pathstr, curr_pos, k);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[k])
				break;
			curr_pos = k;
		}
		k++;
	}
	return (NULL);
}

