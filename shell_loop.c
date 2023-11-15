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
	int i, k;
	info->path = info->argv[0];
	if (info->linecount_flag ==1)
	{
		info->line_count++;
		info->linecount_flag == 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
	{
		if(!is_delim(info->arg[i], "\t\n"))
			k++;
	}
	if (!k)
		return;
	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					||info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
	
			fork_cmd(info);
		eles if (*(inf->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}
/**
 * fork_cmd - forks  an exec thread to run cmd
 * @info: the parameter & return info struct
 * Return: void
 */
void fork_cmd(info_t *t)
{
	pid_t child_pid;
	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	
	if (child_pid == 0)
		if(excev(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACESS)
				exit(126);
			ecit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (EIFEXITED(info->status))
		{
			info->sttaus = WECITSTATUS(info->status);
			if(info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}

}
