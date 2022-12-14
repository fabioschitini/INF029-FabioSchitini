#include <stdio.h>
int ler3Numeros(int *result) {
  int a, b, c, resultado[3];
  printf("Coloque o valor do primeiro numero \n");
  scanf("%d", &a);
  printf(" \n Coloque o valor do segundo numeron \n");
  scanf("%d", &b);
  printf(" \nColoque o valor do terceiro numero \n");
  scanf("%d", &c);
  result[0] = a;
  result[1] = b;
  result[2] = c;
}
int main(void) {
  int f[3];
  ler3Numeros(f);
  for (int i = 0; i < 3; i++) {
    printf("\n %d", f[i]);
  }
}