#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define BOOL_TAB_SIZE 64

void boot_tab_init(bool *bool_tab, int size)
{
  srand(time(NULL));
  for(int i = 0; i < BOOL_TAB_SIZE; i++)
  {
    bool_tab[i] = rand() % 2;
  }
}

void print_err(char *str)
{
  fprintf(stderr, str, strlen(str));
}

int main(int argc, char **argv)
{
  bool *bool_tab = malloc(sizeof(bool) * BOOL_TAB_SIZE);
  if(!bool_tab)
  {
    print_err("Memory allocation failed !\n");
    return EXIT_FAILURE;
  }
  boot_tab_init(bool_tab, BOOL_TAB_SIZE);

  free(bool_tab);

  return EXIT_SUCCESS;
}
