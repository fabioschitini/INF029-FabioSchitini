#include <stdio.h>
#include <string.h>
struct palavra {
  char palavra1[30];
  char palavra2[30];
  char palavra3[30];
};

struct palavra ler3Palavras() {
  struct palavra palavras;
  printf("1° Palavra: ");
  fgets(palavras.palavra1, 30, stdin);

  printf("\n2° Palavra: ");
  fgets(palavras.palavra2, 30, stdin);

  printf("\n3° Palavra: ");
  fgets(palavras.palavra3, 30, stdin);

  return palavras;
}

int main() {
  struct palavra palavras = ler3Palavras();

  printf("\nPrimeira: %s", palavras.palavra1);
  printf("\nSegunda: %s", palavras.palavra2);
  printf("\nTerceira: %s", palavras.palavra3);

  return 0;
}