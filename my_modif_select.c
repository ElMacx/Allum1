/*
** my_modif_select.c for my_select in /home/dulin_m/rendu/PSU_2013_my_select
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Thu Jan 16 21:38:55 2014 maxime dulin
** Last update Wed Feb 12 15:13:18 2014 maxime dulin
*/

#include "./My_lib/my.h"
#include "allum.h"

int	my_under()
{
  char	*str;

  str = tgetstr("us", NULL);
  my_putstr(str);
  return (0);
}

int	my_under_end()
{
  char	*str;

  str = tgetstr("ue", NULL);
  my_putstr(str);
  return (0);
}

int	my_clear()
{
  char	*str;

  str = tgetstr("cl", NULL);
  my_putstr(str);
  return (0);
}
