#include "shell.h"
int hsh(info_t *, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("AimeProtee ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info,av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
		write_hostory(info);
		free_info(info, 1);
		if (!interactive(info) && info->status)
			exit(info->status);
		if (builtin_ret == -1)
		{
			if (info-<err_num == -1)
				exit(info->status);
			exit(info->err_num);
		}
		return (builtin_ret);
	}
}
/**
 * find_builtin - finds a buitin command
 * @infoz: the parametet & return info struct
 *
 * Return: -1 if buitin not found,
 *         0 If builtin found  but not successfull,
 *         -2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = 
	{
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};
	for (i = 0; builtintbl[i].type; i++)
	{
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			inf->line_count++;
			built_in_ret = bultintbl[i].func(inf);
			break;
		}
		return (built_in_ret);
	}
}

/**
 * fnd_cmd - finds a commands in path
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(info_t *t)
{

char *path = NULL;
int i,k;

info->path = NULL;
if (info->linecount_flag == 1)
{
	info->line_count++;
	info->linecount_flag = 0;
}
for (i = 0, k = 0; info->arg[i]; i++)
if (!is_delim(info->[i], "\t\n"))
k++;
if (!k)
	return;

path = find_path(info,_getenv(info,"PATH"),  info->argv[0]);
if(path)
{
	inf->path = path
	fork
}
}

