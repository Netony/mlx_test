#include "fdf.h"
#include <stdio.h>

void	ft_lstdclear(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

void	print(void *s)
{
	static int	i;

	printf("s[%02d]: %s", i++, s);
}

void	ft_lstprint(t_list *lst)
{
	ft_lstiter(lst, print);
}

void	ft_sptprint(char **spt)
{
	while (*spt)
		print(*(spt++));
}

void	ft_tabprint(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			printf("%2s", tab[i][j]);
			j++;
		}
		i++;
	}
}

int	ft_sptsize(char **spt)
{
	int	len;

	len = 0;
	while (*spt)
	{
		spt++;
		len++;
	}
	return (len);
}

void	ft_sptdel(char **spt)
{
	int	i;

	i = 0;
	while (spt[i])
	{
		free(spt[i]);
		i++;
	}
	free(spt);
}

void	ft_tabdel(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_sptdel(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_taberr(char ***tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(tab[i++]);
	free(tab);
}
