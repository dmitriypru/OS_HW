#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("Enter n: %d\n\n", &n);

  int* array = (int*) malloc(sizeof(int) * n);
  
  for (int i = 0; i < n; i++)
    array[i] = i;

  for (int i = 0; i < n; i++)
    printf("%d ", i, array[i]);

  free(array);
  
  return 0;
}
