/*
** get_env.c for get_env in /home/dulin_m/rendu/PSU_2013_my_select
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Wed Jan 15 21:17:18 2014 maxime dulin
** Last update Wed Feb 12 15:12:54 2014 maxime dulin
*/

#include "allum.h"
#include "./My_lib/my.h"

char	*get_env(char **env, char *str)
{
  int	i;
  int	j;
  int	k;
  char	*ret;

  i = -1;
  k = -1;
  j = my_strlen(str) - 1;
  while (env[++i])
    {
      if ((my_strncmp(env[i], str, my_strlen(str))) == 0)
	{
	  if ((ret = malloc(my_strlen(env[i]) - j + 1)) == NULL)
	    exit(0);
	  while (env[i][j])
	    ret[++k] = env[i][++j];
	  return (ret);
	}
    }
  return (0);
}
