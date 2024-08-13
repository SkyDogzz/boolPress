#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOOL_TAB_SIZE 64
#define bool_8 char

bool *bool_tab_init(void) {
  bool *bool_tab = malloc(sizeof(bool) * BOOL_TAB_SIZE);
  srand(time(NULL));
  for (int i = 0; i < BOOL_TAB_SIZE; i++) {
    bool_tab[i] = rand() % 2;
  }

  return bool_tab;
}

bool_8 *bool_tab_pressed_init(bool *bool_tab, int size)
{
  bool_8 *bool_tab_pressed;
  int pressed_size = (sizeof(bool) * 16 * BOOL_TAB_SIZE) / 8;
  if((sizeof(bool) * 16 * BOOL_TAB_SIZE) % 8 != 0)
    size++;
  bool_tab_pressed = malloc(sizeof(bool_8) * pressed_size);
  return bool_tab_pressed;
}

void print_err(char *str) { fprintf(stderr, str, strlen(str)); }

int main(int argc, char **argv) {
  bool *bool_tab = bool_tab_init();
  if (!bool_tab) {
    print_err("Memory allocation failed !\n");
    return EXIT_FAILURE;
  }
  printf("The Boolean Array is %d bytes or %d bit.\n", BOOL_TAB_SIZE * 2,
         (int)sizeof(bool) * 16 * BOOL_TAB_SIZE);

  bool_8 *bool_tab_pressed = bool_tab_pressed_init(bool_tab, BOOL_TAB_SIZE);
  if (!bool_tab_pressed) {
    print_err("Memory allocation failed !\n");
    return EXIT_FAILURE;
  }

  free(bool_tab);
  free(bool_tab_pressed);

  return EXIT_SUCCESS;
}
