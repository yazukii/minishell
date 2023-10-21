#include "stdio.h"
#include "stdlib.h"
typedef struct s_list_pre
{
	char					*pre_tokken;
	int						size;
	struct s_list_pre		*next;
}	t_list_pre;
void testmoi(t_list_pre **test);

int	main(void)
{
	t_list_pre *test;
	t_list_pre *test1;
	t_list_pre *current;

	test = malloc(sizeof (t_list_pre));
	test1 = malloc(sizeof (t_list_pre));
	test->next = test1;
	test->pre_tokken= "hahah";
	test1->pre_tokken = "test";
	testmoi(&test);
	printf("%s", test->pre_tokken);
	return 0;
}

void testmoi(t_list_pre **test)
{
	*test = (*test)->next;
}