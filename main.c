/*
** main.c for main in /home/dulin_m/rendu/my_select
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Jan 14 11:19:38 2014 maxime dulin
** Last update Fri Feb 14 14:34:57 2014 maxime dulin
*/

#include "./My_lib/my.h"
#include "allum.h"

void		create(t_list *list)
{
  list->first = NULL;
  list->current = NULL;
  list->len = 0;
}

int		check_empty(t_list *list)
{
  int		i;
  t_elem	*elem;

  i = 0;
  elem = list->current;
  while (i < list->len - 1)
    {
      if (list->pipe[i++][0] == '\0')
	elem->next = list->current->next;
    }
  return (0);
}

int		complete(char *str, t_list *list)
{
  t_elem	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(0);
  elem->value = str;
  if (list->first == NULL)
    {
      list->first = elem;
      list->current = elem;
      elem->back = elem;
      elem->next = elem;
    }
  else
    {
      elem->back = list->first->back;
      list->first->back->next = elem;
      list->first->back = elem;
      elem->next = list->first;
    }
  list->len++;
  list->current = list->first;
  return (0);
}

int		my_print(t_list *list, int ret, char **av)
{
  t_elem	*tmp;
  t_pam		pam;

  pam.ct = 0;
  pam.i = -1;
  pam.j = my_getnbr(av[1]);
  my_clear();
  tmp = list->first;
  putstr_modif();
  while (++pam.i < list->len)
    {
      pam.ln = pam.j - pam.ct;
      my_put_nbr(my_strlen(list->pipe[pam.i]));
      if (my_strlen(list->pipe[pam.i]) < 10)
	  my_putstr("   ");
      else
	my_putstr("  ");
      while (pam.ln-- > 0)
	my_putchar(' ');
      gest_print(tmp, list, ret);
      tmp = tmp->next;
      pam.ct++;
    }
  player_stat(list);
  return (0);
}

int			main(int ac, char **av, char **env)
{
  t_list		list;
  int			i;
  struct termios	*t;

  list.score1 = 0;
  list.score2 = 0;
  menu(&list, ac, av);
  if ((t = malloc(sizeof(*t))) == NULL)
    exit(0);
  if (tcgetattr(0, t) == -1)
    return (1);
  i = -1;
  create(&list);
  list.pos = 0;
  list.player = 0;
  list.pipe = create_pipe(my_getnbr(av[1]), &list);
  while (++i < my_getnbr(av[1]))
    complete(list.pipe[i], &list);
  t->c_lflag &= ~ICANON;
  t->c_lflag &= ~ECHO;
  if (tcsetattr(0, TCSANOW, t) == -1)
    return (1);
  my_round(&list, env, av);
  return (0);
}
