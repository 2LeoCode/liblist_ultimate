#include <list.h>
#include <stdio.h>

int main(void) {
	t_list	*lst = lst_new();
	int		ret = 0;
	
	if (!lst) return (-1);
	for (int i = 0; i < 5; i++)
		if (lst_push_front(lst, "foo", 4)) {
			ret = -1;
			break ;
		}
	printf("NORMAL\n");
	for (t_list *it = lst->next; it != lst; it = it->next)
		printf("%s\n", it->data);
	printf("INVERSED\n");
	for (t_list *it = lst->prev; it != lst; it = it->prev)
		printf("%s\n", it->data);
	lst_destroy(lst);
	return (ret);
}