/*
** my_strncmp.c for my_strncmp in /home/dulin_m/rendu/Piscine-C-lib/my
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Oct  8 22:29:07 2013 maxime dulin
** Last update Thu Jan 16 11:32:31 2014 maxime dulin
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = -1;
  while (s1 && s2 && ++i < n && s1[i] && s2[i])
    {
      if (s1[i] == s2[i])
	++i;
      else if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
    }
  return (0);
}
