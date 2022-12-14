struct quatnum {
  int num1;
  int num2;
  int num3;
  int num4;
};

struct quatnum ler4Numeros() {
  struct quatnum numeros;

  printf("1° numero: ");
  scanf("%i", &numeros.num1);

  printf("\n2° numero: ");
  scanf("%i", &numeros.num2);

  printf("\n3° numero: ");
  scanf("%i", &numeros.num3);

  printf("\n4° numero: ");
  scanf("%i", &numeros.num4);

  return numeros;
}

int main() {
  struct quatnum numeros;
  numeros = ler4Numeros();
  printf("\n%i", numeros.num1);
  printf("\n%i", numeros.num2);
  printf("\n%i", numeros.num3);
  printf("\n%i", numeros.num4);
  return 0;
}