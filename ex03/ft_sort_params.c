#include <unistd.h>

int		str_cmp(char *str1, char *str2);

void	sort_params(int argc, char **argv);

void	display_params(int argc, char **argv);

int	main(int argc, char **argv)
{
	sort_params(argc, argv);
	display_params(argc, argv);
	return (0);
}

int	str_cmp(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

void	sort_params(int argc, char **argv)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (str_cmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	display_params(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (*argv[i])
		{
			write(1, &(*argv[i]), 1);
			argv[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
}
