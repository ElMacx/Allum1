/*
** my_putstr.c for my_putstr in /home/dulin_m/rendu/Piscine-C-lib/my
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Oct  8 21:58:28 2013 maxime dulin
** Last update Fri Feb 14 13:39:21 2014 maxime dulin
*/

#include <stdlib.h>

int	my_putstr(char *str)
{
  int i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != 0)
	{
	  my_putchar(str[i]);
	  i = i + 1;
	}
    }
  return (0);
}
