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


//테스트 코드
/*
int main(void)
{
	t_list	*list;

	list = create_elem(strdup("PYTHON"));
	list_push_front(&list, strdup("JAVA"));
	//front 까지의 코드

	list_push_back(&list, strdup("C++"));
}
*/