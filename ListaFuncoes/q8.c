#include <stdio.h>
int cadastrarCliente(char *result) {
  printf("Coloque o nome do cliente \n");
  gets(result[0]);
}
int main(void) {
  char f[4][99];
  cadastrarCliente(f);
  puts(f)
}