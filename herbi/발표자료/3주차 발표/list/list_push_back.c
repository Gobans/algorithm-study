#include "list.h"

void	list_push_back(t_list **begin_list, void *data)
{
	t_list	*newe;
	t_list	*temp;

	newe = create_elem(data);
	temp = *begin_list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newe;
}


//�׽�Ʈ �ڵ�
/*
int main(void)
{
	t_list	*list;

	list = create_elem(strdup("PYTHON"));
	list_push_front(&list, strdup("JAVA"));
	//front ������ �ڵ�

	list_push_back(&list, strdup("C++"));
}
*/