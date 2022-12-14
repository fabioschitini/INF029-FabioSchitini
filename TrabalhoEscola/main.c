// associar aluno a disciplina, =>imprimir nascimento
// botar no menu
#include "uteis.h"
#include <stdio.h>
#include <string.h>

typedef struct alunos {
  char nome[20];
  char sexo;
  char cpf[14];
  char nascimento[20];
  int matricula;
  int disciplinas[20];
  int contadorDisciplinas;
} Aluno;
typedef struct profesores {
  char nome[20];
  char sexo;
  char cpf[14];
  char nascimento[20];
  int id;
  int disciplinas[20];
} Professor;
typedef struct disciplinas {
  char nome[20];
  int codigo;
  int semestre;
  int professor;
  int id;
  int alunos[20];
  int contadorAlunos;
} Disciplina;

int contadorDisciplina;
int contadorAlunos;
int contadorAluno;
int contadorProf;
Disciplina disciplinas[999];
Aluno alunos[999];
Professor professores[999];


  
int main() {
  contadorDisciplina = 0;
  contadorAlunos=0;
  contadorAluno=0;
  contadorProf=0;  
  printf("\n\n\nMAIN MAIN MAIN MAIN\n\n\n");
  menu();
}

int menu() {
  int opc;
main:
  printf("MENU:\n Selecione a opçao [1 = ALUNOS, 2 = PROFESSORES, 3 = DISCIPLINAS]: ");
  scanf("%i", &opc);
  switch (opc) {
  case 1:
    aluno();
    break;
  case 2:
    professor();
    break;
  case 3:
    disciplina();
    break;
  default:
    printf("Opçao fodase\n");
    goto main;
    break;
  }
}

void imprimirAlunos() {
  if(contadorAluno>0){
     for (int n = 0; n < contadorAluno; n++) {
    printf("\nNome: ");
    puts(alunos[n].nome);
    printf("CPF: ");
    puts(alunos[n].cpf);
    printf("Nascimento: %s", alunos[n].nascimento);
    printf("\nSexo: %c\n", alunos[n].sexo);
    printf("\nMatricula: %i\n\n", n);
  } }
    else{
    printf("\nNao existe alunos cadstrados!\n\n");
    }
  }



void cadastrarAlunos() {
  alunos[contadorAluno].contadorDisciplinas = 0;
  getchar();
  // printf("Nome: \n");
  // fgets(alunos[contador].nome, 40, stdin);
nome:
  printf("Nome: \n");
  fgets(alunos[contadorAluno].nome, 40, stdin);
  if (!validarNome(alunos[contadorAluno].nome))
    goto nome;

nascimento:
  printf("Dia de nascimento [DD/MM/AAAA]: \n");
  fgets(alunos[contadorAluno].nascimento, 40, stdin);
  if (!validarNascimento(alunos[contadorAluno].nascimento))
    goto nascimento;

cpf:
  printf("CPF [XXX.XXX.XXX-XX]: \n");
  fgets(alunos[contadorAluno].cpf, 40, stdin);
  if (!validarCpf(alunos[contadorAluno].cpf))
    goto cpf;

sexo:
  printf("Sexo [Mm/Ff/Oo]: \n");
  scanf("%c", &alunos[contadorAluno].sexo);
  getchar();
  if (!validarSexo(alunos[contadorAluno].sexo))
    goto sexo;

  alunos[contadorAluno].matricula = contadorAluno;
  imprimirAlunos();
  contadorAluno++;
};

void updateAluno() {
  int opc, idOpc;
  printf("\nSelecione a matricula do estudante \n");
  scanf("%d", &idOpc);
  if (idOpc > contadorAluno) {
    printf("\nId do estudante nao existez\n");
  } else {
    while (opc) {
      printf("EDITAR ESTUDANTE: \n Selecione a opçao que voce quer editar:\n [0 = SAIR, "
             "1 = NOME,2 = CPF 3 = NASCIMENTO] 4 = SEXO]\n");
      scanf("%i", &opc);
      switch (opc) {
      case 0:
        break;
      case 1:
        getchar();
        printf("\n Nome: \n");
        fgets(alunos[idOpc].nome, 40, stdin);
        break;
      case 2:
        printf("\nCPF [XXX.XXX.XXX-XX]: \n");
        fgets(alunos[idOpc].cpf, 40, stdin);
        break;
      case 3:
        printf("\nDia de nascimento [DD/MM/AAAA]: \n");
        fgets(alunos[idOpc].nascimento, 40, stdin);
        break;
      case 4:
        printf("\nSexo[M/F]: \n");
        scanf("%c", &alunos[idOpc].sexo);
        break;
      default:
        printf("\nOpçao Invalida\n");
        break;
      }
    }
    imprimirAlunos();
  }
};

void deletarAluno() {
  int idDeletar = 0;
  contadorAluno = 2;
  printf("\nColoque a matricula do estudante que voce quer deletar: \n ");
  scanf("%d", &idDeletar);
  if (idDeletar < contadorAluno) {
    for (idDeletar; idDeletar < contadorAluno; idDeletar++) {
      alunos[idDeletar] = alunos[idDeletar + 1];
    }
    contadorAluno--;
  } else {
    printf("\nMatricula nao existe \n");
  }
}

int aluno() {
  int opc = 10;
  while (opc) {
    printf("ALUNO:\n Selecione a opçao:\n [0=SAIR,1 = CADASTRAR, 2 = IMPRIMIR,3 = EDITAR, "
           "4 = DELETAR :\n");
    scanf("%i", &opc);
    switch (opc) {
    case 0:
      break;
    case 1:
      cadastrarAlunos(alunos, contadorAluno);
      break;
    case 2:
      imprimirAlunos();
      ;
      break;
    case 3:
      updateAluno(alunos, contadorAluno);
      break;
    case 4:
      deletarAluno(alunos, contadorAluno);
      break;
    default:
      printf("Opçao Invalida");
      break;
    }
  }
  menu();
  return 0;
}

void imprimirProf() {
  for (int n = 0; n < contadorProf; n++) {
    printf("\nNome: ");
    puts(professores[n].nome);
    printf("CPF: ");
    puts(professores[n].cpf);
    printf("Nascimento: %s", professores[n].nascimento);
    printf("\nSexo: %c\n", professores[n].sexo);
    printf("\nID: %i\n", n);
    printf("\nDisciplinas: ");
    for (int i = 0; i < contadorDisciplina; i++){
      if (disciplinas[i].professor == n)
        printf("\n%s", disciplinas[i].nome);
    }
  }
};

void cadastrarProf() {
  getchar();
nomeprof:
  printf("Nome: \n");
  fgets(professores[contadorProf].nome, 40, stdin);
  if (!validarNome(professores[contadorProf].nome))
    goto nomeprof;
nascimentoprof:
  printf("Dia de nascimento [DD/MM/AAAA]: \n");
  fgets(professores[contadorProf].nascimento, 40, stdin);
  if (!validarNascimento(professores[contadorProf].nascimento))
    goto nascimentoprof;
cpfprof:
  printf("CPF [XXX.XXX.XXX-XX]: \n");
  fgets(professores[contadorProf].cpf, 40, stdin);
  if (!validarCpf(professores[contadorProf].cpf))
    goto cpfprof;

sexoprof:
  printf("Sexo [Mm/Ff/Oo]: \n");
  scanf("%c", &professores[contadorProf].sexo);
  getchar();
  if (!validarSexo(professores[contadorProf].sexo))
    goto sexoprof;

  professores[contadorProf].id = contadorProf;
  imprimirProf();
  contadorProf++;
};

void updateProf() {
  int opc, idOpc;
  printf("\nSelecione o id do professor: \n");
  scanf("%d", &idOpc);
  if (idOpc > contadorProf) {
    printf("\nID do professor nao existe.\n");
  } else {
    while (opc) {
      printf("EDITAR PROFESSOR:\nSelecione a opçao que voce quer editar:\n [0 = SAIR, "
             "1 = NOME,2 = CPF 3 = NASCIMENTO] 4 = SEXO]");
      scanf("%i", &opc);
      switch (opc) {
      case 0:
        break;
      case 1:
        getchar();
        printf("\nNome: \n");
        fgets(professores[idOpc].nome, 40, stdin);
        break;
      case 2:
        printf("\nCPF [XXX.XXX.XXX-XX]: \n");
        fgets(professores[idOpc].cpf, 40, stdin);
        break;
      case 3:
        printf("\nDia de nascimento [DD/MM/AAAA]: \n");
        fgets(professores[idOpc].nascimento, 40, stdin);
        break;
      case 4:
        printf("\nSexo[M/F]: \n");
        scanf("%c", &professores[idOpc].sexo);
        break;
      default:
        printf("\nOpçao Invalida\n");
        break;
      }
    }
    imprimirProf(professores, contadorProf);
  }
};

void deletarProf() {
  int idDeletar = 0;
  printf("\nColoque a ID a ser deletada: \n");
  scanf("%d", &idDeletar);
  if (idDeletar < contadorProf) {
    for (idDeletar; idDeletar < contadorProf; idDeletar++) {
      professores[idDeletar] = professores[idDeletar + 1];
    }
    contadorProf--;
  } else {
    printf("\nID Não existe!\n");
  }
}

int professor() {
  int opc = 10;

  while (opc) {
    printf("PROFESSORES:\n Selecione a opçao:\n [0=SAIR,1 = CADASTRAR, 2 = IMPRIMIR,3 = EDITAR, "
           "4 = DELETAR :");
    scanf("%i", &opc);
    switch (opc) {
    case 0:
      break;
    case 1:
      cadastrarProf(professores, contadorProf);
      break;
    case 2:
      imprimirProf(professores, contadorProf);
      break;
    case 3:
      updateProf(professores, contadorProf);
      break;
    case 4:
      deletarProf(professores, contadorProf);
      break;
    default:
      printf("Opçao Invalida");
      break;
    }
  }
  menu();

  return 0;
}

void imprimirDisc() {
  for (int n = 0; n < contadorDisciplina; n++) {
    printf("\nNome: %s\n", disciplinas[n].nome);
    printf("\nCódigo: %d\n ", disciplinas[n].codigo);
    printf("\nID: %i\n", n);
    printf("\nProfessor: %s\n", professores[disciplinas[n].professor].nome);
  }
}
void cadastrarDisc() {
  getchar();
  printf("Nome: \n");
  fgets(disciplinas[contadorDisciplina].nome, 40, stdin);

  printf("Código [123]: \n");
  scanf("%d", &disciplinas[contadorDisciplina].codigo);
prof:
  if (contadorProf == 0) {
    printf("\nNao Existe Professores Cadastrados!\n");
  }

  else {
    printf("Id do Professor abaixo: \n");
    imprimirProf();
    scanf("%d", &disciplinas[contadorDisciplina].professor);
    if (disciplinas[contadorDisciplina].professor > contadorProf) {
      printf("Valor Invalido,tente Novamente");
      goto prof;
    }
  }

  disciplinas[contadorDisciplina].id = contadorDisciplina;
   imprimirDisc();
  contadorDisciplina++;
}

void updateDisc() {
  int opc, idOpc;
  printf("EDITAR DISCIPLINA:\nSelecione a ID da disciplina: \n");
  scanf("%d", &idOpc);
  if (idOpc > contadorDisciplina) {
    printf("\nID da disciplina não existe.\n");
  } else {
    while (opc) {
      printf("EDITAR DISCIPLINA:\nSelecione a opçao que voce quer editar:\n [0 = SAIR, 1 = NOME, 2 "
             "=Professor, 3=CÓDIGO]\n");
      scanf("%i", &opc);
      switch (opc) {
      case 0:
        break;
      case 1:
        getchar();
        printf("\nNome: \n");
        fgets(disciplinas[idOpc].nome, 40, stdin);
        break;
      case 2:
        printf("\nProfessor\n");
        scanf("%d", &disciplinas[idOpc].professor);
        break;
      case 3:
        printf("\nCÓDIGO [123]: \n");
        scanf("%d", &disciplinas[idOpc].codigo);
        break;
      default:
        printf("\nOpçao Invalida\n");
        break;
      }
    }
    imprimirDisc(disciplinas, contadorDisciplina);
  }
}

void deletarDisc() {
  int idDeletar = 0;
  printf("\nColoque a ID a ser deletada: \n");
  scanf("%d", &idDeletar);
  if (idDeletar < contadorDisciplina) {
    for (idDeletar; idDeletar < contadorDisciplina; idDeletar++) {
      disciplinas[idDeletar] = disciplinas[idDeletar + 1];
    }
    contadorDisciplina--;
  } else {
    printf("\nID Não existe!\n");
  }
}

void alunoDisciplina() {
  int opc, aluno;

alunodisc:
  printf("\nSelecione o ID da disciplina: \n");
  // BOTAR PARA IMPRIMIR AS DISCIPLINAS
  scanf("Opção: %i", &opc);

  if (opc > contadorDisciplina) {
    printf("\nOPÇÃO INVÁLIDA!\n");
    goto alunodisc;
  }

  printf("\nSelecione o ID do aluno para inserir nessa disciplina: \n");
  // BOTAR PARA IMPRIMIR OS ALUNOS
  scanf("Opção: %i", &aluno);
  alunos[aluno].disciplinas[alunos[aluno].contadorDisciplinas] = opc;
  alunos[aluno].contadorDisciplinas++;
  disciplinas[opc].alunos[disciplinas[opc].contadorAlunos] = aluno;
  disciplinas[opc].contadorAlunos++;
}

int disciplina() {
  int opc = 10;

  while (opc) {
    printf("\nDISCIPLINA:\n Selecione a opçao:\n [0=SAIR,1 = CADASTRAR, 2 = IMPRIMIR,3 = EDITAR, "
           "4 = DELETAR, 5 = ASSOCIAR]:\n ");
    scanf("%i", &opc);
    switch (opc) {
    case 0:
      break;
    case 1:
      cadastrarDisc(disciplinas, contadorDisciplina);
      break;
    case 2:
      imprimirDisc(disciplinas, contadorDisciplina);
      break;
    case 3:
      updateDisc(disciplinas, contadorDisciplina);
      break;
    case 4:
      deletarDisc(disciplinas, contadorDisciplina);
      break;
    case 5:
      alunoDisciplina();
      break;
    default:
      printf("\nOpçao Invalida\n");
      break;
    }
  }
  menu();

  return 0;
}
