#include "../../headers/minishell.h"

void echo(t_list_tokken *current)
{
   t_list_arg	*tmp;
   int 			n;

   n = 0;
   if (!(current)->a_head)
	   return ;
   tmp = (current)->a_head;
   if (!ft_strncmp(tmp->arg, "-n", 2))
   {
	   n = 1;
	   tmp = tmp->next;
   }
   while (tmp)
   {
	   printf("%s ", tmp->arg);
	   tmp = tmp->next;
   }
   if (n == 0)
	   printf("\n");
}