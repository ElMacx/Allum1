/*
** gest_key.c for gest_key in /home/dulin_m/rendu/PSU_2013_my_select
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Wed Jan 15 13:37:26 2014 maxime dulin
** Last update Fri Feb 14 15:53:04 2014 maxime dulin
*/

#include "allum.h"
#include "./My_lib/my.h"

void	writestr(char *str)
{
  write(0, str, my_strlen(str));
  my_putchar('\n');
}

int		gest_up(t_list *list)
{
  t_elem	*elem;

  elem = list->current;
  if (list->pos - 1 < 0)
    list->pos = list->len;
  while (list->pipe[list->pos - 1][0] == '\0')
    {
      list->current = elem->back;
      elem = elem->back;
      list->pos--;
      if (list->pos - 1< 0)
	list->pos = list->len;
    }
  list->current = elem->back;
  list->pos--;
  return (0);
}

int		gest_down(t_list *list)
{
  t_elem	*elem;

  elem = list->current;
  if (list->pos >= list->len - 1)
    list->pos = -1;
  while (list->pipe[list->pos + 1][0] == '\0')
    {
      list->current = elem->next;
      elem = elem->next;
      list->pos++;
      if (list->pos >= list->len - 1)
	list->pos = -1;
    }
  list->current = elem->next;
  list->pos++;
  return (0);
}

int	my_round(t_list *list, char **env, char **av)
{
  int	buffer;
  char	*str;

  while (1)
    {
      my_print(list, 1, av);
      buffer = 0;
      read(0, &buffer, sizeof(buffer));
      str = get_env(env, "TERM=");
      analyze(buffer, list, str, av);
      my_print(list, 1, av);
      check_val(list);
    }
  return (0);
}

int	analyze(int buf, t_list *list, char *str, char **av)
{
  if (tgetent(NULL, str) == -1)
    exit(0);
  if (buf == 4283163)
    {
      gest_up(list);
      return (1);
    }
  else if (buf == 4348699)
    {
      gest_down(list);
      return (1);
    }
  else if (buf == 43)
    {
      cheat_code(list);
      return (1);
    }
  check_number(list, buf, av);
  if (buf == 27)
    exit(0);
  return (0);
}
