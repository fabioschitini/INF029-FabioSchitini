#include <stdio.h>
float subtrai(float a, float b, float c, float resultado) {
  resultado = a - b - c;
  return resultado;
}
int main(void) {
  float a, b, c, resultado;
  printf("Coloque o valor do primeiro numero \n");
  scanf("%f", &a);
  printf(" \n Coloque o valor do segundo numeron \n");
  scanf("%f", &b);
  printf(" \nColoque o valor do terceiro numero \n");
  scanf("%f", &c);
  printf("O resultado é:%.2f", subtrai(a, b, c, resultado));
  return 0;
}