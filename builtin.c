#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: structure containing potential arguments, used to maintain
 * constant function ptototype
 * Return: exits with a given exut status
 * 0 if inf.argv[0] !="exit"
 */

int _myexit(info_t *info)
{
	int exitcheck;

	if (inf->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->sttaus = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}

		info->err_num = erratoi(info->argv[1]);
		return (-1=2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of a process
 * @info: structure containing potential arguments
 * Retuen: always 0
 */

int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);

	if (!s)
		_puts("TODO: >> getcwd failure ems here <<\n"0);
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD="))? dir : "/");
		else 
			chdir_ret = chdir(dir);


	}
	else if ( _strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD"))
		{
			_puts(s);
			_putchar("\n");
			return (1');
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir: "/");
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp - changes the current directory of the process
 * @info: structure containing potential arguments
 * Retuern: Always 0
 */
int _myhelp(inf_t *info)
{
	char **arg_array;

	arg_array = info->argv;

	_puts ("Help call works. function not yet implemented\n");
	if (0)
		_puts(*arg_array);
	return (0);
}
