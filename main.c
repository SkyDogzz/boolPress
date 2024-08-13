#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOOL_TAB_SIZE 64
#define bool_8 char

bool *bool_tab_init(int size) {
  bool *bool_tab = malloc(sizeof(bool) * size);
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    bool_tab[i] = rand() % 2;
  }
  return bool_tab;
}

bool_8 *bool_tab_pressed_init(bool *bool_tab, int size, int *pressed_size) {
  bool_8 *bool_tab_pressed;
  *pressed_size = (sizeof(bool) * 2 * size + 7) / 8;
  bool_tab_pressed = malloc(sizeof(bool_8) * *pressed_size);
  return bool_tab_pressed;
}

void print_err(char *str) { fprintf(stderr, str, strlen(str)); }

int main(int argc, char **argv) {
  int size = BOOL_TAB_SIZE;

  if (argc > 1) {
    size = atoi(argv[1]);
    if (size <= 0) {
      print_err("Invalid size provided, must be a positive integer.\n");
      return EXIT_FAILURE;
    }
  }

  bool *bool_tab = bool_tab_init(size);
  if (!bool_tab) {
    print_err("Memory allocation failed !\n");
    return EXIT_FAILURE;
  }
  printf("The bool array is %d bytes or %d bit.\n", size * 2,
         (int)sizeof(bool) * 16 * size);

  int pressed_size = 0;
  bool_8 *bool_tab_pressed =
      bool_tab_pressed_init(bool_tab, size, &pressed_size);
  if (!bool_tab_pressed) {
    print_err("Memory allocation failed !\n");
    return EXIT_FAILURE;
  }
  printf("The bool_8 array is %d bytes or %d bit.\n", pressed_size,
         pressed_size * 8);

  free(bool_tab);
  free(bool_tab_pressed);

  return EXIT_SUCCESS;
}
