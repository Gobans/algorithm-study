#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct s_list
{
	struct s_list	*next;
	void		*data;
}t_list;

t_list	*create_elem(void *data);
void	list_push_front(t_list **begin_list, void *data);
void	list_push_back(t_list **begin_list, void *data);