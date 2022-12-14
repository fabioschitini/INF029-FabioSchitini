#include <stdio.h>


int soma(int num1, int num2) { return num1 + num2; }

int main(void) {
  int num1, num2;

  printf("Numero 1: ");
  scanf("%i", &num1);

  printf("Numero 2: ");
  scanf("%i", &num2);

  printf("A soma eh: %i", soma(num1, num2));
  return 0;
}