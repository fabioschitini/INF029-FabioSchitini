int fatorial(int num) {
  int fatorial = 1;

  if (num > 0) {
    for (int i = 0; i < num; i++) {
      fatorial *= num - i;
    }

    printf("Fatorial: %i", fatorial);
  }

  else
    printf("Erro!");
}

int main() {
  int num;

  printf("Insira o numero: ");
  scanf("%i", &num);

  fatorial(num);
  return 0;
}