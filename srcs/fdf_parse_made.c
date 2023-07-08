#include "fdf.h"

int	ft_lstadd(t_list **lst, void *content);

t_list	*get_line_list(int fd)
{
	t_list	*line;
	char	*buf;

	line = NULL;
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		if (ft_lstadd(&line, buf) < 0)
		{
			ft_lstclear(&line, free);
			return (NULL);
		}
	}
	return (line);
}

int	ft_lstadd(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new == NULL)
		return (-1);
	ft_lstadd_back(lst, new);
	return (0);
}

char	**list_to_chrp(t_list *line)
{
	int		n;
	int		i;
	char	**chrp;

	n = ft_lstsize(line);
	i = 0;
	chrp = (char **)malloc(sizeof(char *) * (n + 1));
	if (chrp == NULL)
		return (NULL);
	while (i < n)
	{
		chrp[i++] = line->content;
		line = line->next;
	}
	return (chrp);
}

char	***arr_split(char **arr)
{
	int		n;
	int		i;
	char	***tab;

	n = ft_sptsize(arr);
	i = 0;
	tab = (char ***)malloc(sizeof(char **) * (n + 1));
	if (tab == NULL)
		return (NULL);
	while (i < n)
	{
		tab[i] = ft_split(arr[i], ' ');
		if (tab[i] == NULL)
		{
			ft_taberr(tab, i);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

int	ft_tab_rowsize(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_tab_colsize(char ***tab)
{
	int	i;
	int	size;
	int	check;

	i = 0;
	while (tab[i])
	{
		size = ft_sptsize(tab[i]);
		if (i == 0)
			check = size;
		else
		{
			if (check != size)
				return (-1);
		}
		i++;
	}
	return (size);
}
