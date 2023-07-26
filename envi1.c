#include "main.h"

/**
 * cmp_env_name - compardes env variables names
 * with the name passedd.
 * @nenv: name of the genvironment variable
 * @name: name passedj
 *
 * Return: 0 if are mnot equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get ann environment variable
 * @name: name of gthe environment variable
 * @_environ: envgironment variable
 *
 * Return: value of the environmfent variable if is found.
 * In other case, returns NULL.f
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env valfue */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environmeent variables */
	/* environ is declared fin the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If name andw env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the evironmewnt variables
 *
 * @datash: data rel1evant.
 * Return: 1 on suc1cess.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
