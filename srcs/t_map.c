typedef struct	s_map
{
	t_dot	***dots;
	int		row;
	int		col;
}	t_map;

int	map_row(t_list *line_list)
{
	return (ft_lstsize(line_list));
}

int	map_col(t_list *line_list)
{
	int	col;
	int	cur;

	col = ft_sptsize(line_list->content);
	while (line_list)
	{
		cur = ft_sptsize(line_list->content);
		if (cur != col)
			return (0);
		line_list = line_list->next;
	}
	return (col);
}

int	main(void)
{
	t_map	*map;

}

t_map	*ft_mapnew(int fd)
{

}

t_map	*
