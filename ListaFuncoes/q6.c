#include <stdio.h>
int ler3letras(char *result) {

  printf("Coloque as tres letras \n");
  gets(result);
}
int main(void) {
  char f[3];
  ler3letras(f);
  for (int i = 0; i < 3; i++) {
    printf("\n %c", f[i]);
  }
}