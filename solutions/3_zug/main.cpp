#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 5;
  int &ptr_a = a;

  printf("Wert hinter dem Pointer ptr_a  %p\n", &ptr_a);
  printf("Pointer ptr_a                  %d\n", ptr_a);
  return EXIT_SUCCESS;
}
