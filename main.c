#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	get_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] > 9)
	{
		str[i] /= 10;
		i++;
	}
	return (i);
}

int	check_list(char *str)
{
	int	i;
	int	res;
	int	add;

	add = 0;
	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		add = get_nbr(str + i);
		res = ft_atoi(str + add + i);
	printf("%d\n", res);	
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	ret;

	ret = 0;
	if (argc != 2)
		return (-1);
		//ft_error(-1);
	printf("%s\n", argv[1]);
	ret = check_list(argv[1]);
	if (ret == -1)
		ft_error(-1);
	return (0);
}

//xrandr --output eDP --mode 2560x1440