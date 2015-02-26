/*
** my_strcpy.c for my_strcpy in /home/dulin_m/rendu/Piscine-C-lib/my
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Oct  8 22:05:54 2013 maxime dulin
** Last update Wed Feb 12 17:28:53 2014 maxime dulin
*/

char	*my_strcpy(char *dest, char *src)
{
  int	counter;

  counter = 0;
  while (src[counter + 1] != '\0')
    {
      dest[counter] = src[counter];
      counter = counter + 1;
    }
  dest[counter] = '\0';
  return (dest);
}
