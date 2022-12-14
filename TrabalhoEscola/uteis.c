#include <string.h>
#include <stdio.h>
#include "uteis.h"

char validarNascimento(char *data) {
  if (strlen(data) > 11) {
    printf("ATENÇÃO! Número de caracteres maior do que o permitido.\n");
    return 0;
  }

  if ((data[0] > 47 && data[0] < 58) && (data[1] > 47 && data[1] < 58) &&
      (data[2] == 47) && (data[3] > 47 && data[3] < 58) &&
      (data[4] > 47 && data[4] < 58) && (data[5] == 47) &&
      (data[6] > 47 && data[6] < 58) && (data[7] > 47 && data[7] < 58) &&
      (data[8] > 47 && data[8] < 58) && (data[9] > 47 && data[9] < 58)) {
    return 1;
  }

  printf("ATENÇÃO! Formato inválido (dd/mm/aaaa), tente novamente.\n");
  return 0;
}
char validarCpf(char *cpf) {
  if (strlen(cpf) > 16) {
    printf("ATENÇÃO! Número de caracteres maior do que o permitido.\n");
    return 0;
  }
  if ((cpf[0] > 47 && cpf[0] < 58) && (cpf[1] > 47 && cpf[1] < 58) &&
      (cpf[2] > 47 && cpf[2] < 58) && (cpf[4] > 47 && cpf[4] < 58) &&
      (cpf[5] > 47 && cpf[5] < 58) && (cpf[6] > 47 && cpf[6] < 58) &&
      (cpf[8] > 47 && cpf[8] < 58) && (cpf[9] > 47 && cpf[9] < 58) &&
      (cpf[10] > 47 && cpf[10] < 58) && (cpf[12] > 47 && cpf[12] < 58) &&
      (cpf[13] > 47 && cpf[13] < 58) && (cpf[3] == 46) && (cpf[7] == 46) &&
      (cpf[11] == 45)) {
    return 1;
  }
  printf("ATENÇÃO! O formato esta invalido, tente: [XXX.XXX.XXX-XX]\n");
  return 0;
}
char validarSexo(char sexo) {
  // if (strlen(sexo) > 2) {
  //  printf("ATENÇÃO! Número de caracteres maior do que o permitido.\n");
  //  return 0;
  //}

  if (sexo == 70 || sexo == 77 || sexo == 79 || sexo == 102 || sexo == 109 ||
      sexo == 111) {
    return 1;
  }

  printf("ATENÇÃO! O formato esta invalido, tente: [X ou x]\n");
  return 0;
}

char validarNome(char *nome) {
  if (strlen(nome) > 22) {
    printf("ATENÇÃO! Número de caracteres maior do que o permitido(20).\n");
    return 0;
  }
  return 1;
}