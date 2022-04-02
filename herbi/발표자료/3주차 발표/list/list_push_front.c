#include "list.h"

void	list_push_front(t_list **begin_list, void *data)
{
	t_list	*temp;

	temp = create_elem(data);
	temp->next = *begin_list;
	*begin_list = temp;
}

/*
//테스트코드
int main(void)
{
	t_list	*list;

	list = create_elem(strdup("PYTHON"));
	list_push_front(&list, strdup("JAVA"));
}
*/