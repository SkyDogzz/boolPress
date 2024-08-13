#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOOL_TAB_SIZE 64

int main(int argc, char **argv)
{
  bool *bool_tab = malloc(sizeof(bool) * BOOL_TAB_SIZE);

  int f = 0, t = 0;
  srand(time(NULL));
  for(int i = 0; i < BOOL_TAB_SIZE; i++)
  {
    bool_tab[i] = rand() % 2;
    if(bool_tab[i] == 0)
      f++;
    else
     t++;
  }
    printf("%d %d\n",t, f);

  return EXIT_SUCCESS;
}
