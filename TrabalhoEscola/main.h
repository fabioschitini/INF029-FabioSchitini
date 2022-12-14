#ifndef TEST_H_
#define MAIN_H_

typedef struct alunos {
  char nome[20];
  char sexo;
  char cpf[14];
  char nascimento[20];
  int matricula;
  int disciplinas[20];
} Aluno;

typedef struct disciplinas {
  char nome[20];
  char codigo[20];
  char semestre[14];
  char professor[20];
  int id;
} Disciplina;
#endif