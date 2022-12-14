#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int *vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    // se posição é um valor válido {entre 1 e 10}
    if(posicao>10|| posicao<1){
     return retorno = POSICAO_INVALIDA; 
    }  
        posicao--;
     // o tamanho nao pode ser menor que 1
    if(tamanho<1){
      return retorno = TAMANHO_INVALIDO;      
    }
    // a posicao pode já existir estrutura auxiliar?
    if(vetorPrincipal[posicao]!=NULL){
      return retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    } 
    vetorPrincipal[posicao] = (int *) malloc(tamanho*sizeof(int));
    vetorPrincipal[posicao][tamanho]=-104;
    for(int i=0;i<tamanho;i++){      
      vetorPrincipal[posicao][i]=-103;
    }
   //  o tamanho ser muito grande
    if(vetorPrincipal[posicao]==NULL){
      return retorno = SEM_ESPACO_DE_MEMORIA; 
    }
    // deu tudo certo, crie
    //if(retorno==0)
    return retorno = SUCESSO;
    //return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (posicao>10|| posicao<1)
        retorno = POSICAO_INVALIDA;
    else
    {
        --posicao;
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao]!=NULL)
        { 
            for(int i=0;i>-100;i++){
              //printf("valor do vetor==%i\n",vetorPrincipal[posicao][i]);
              if(vetorPrincipal[posicao][i]==-103){
                vetorPrincipal[posicao][i]=valor;
                temEspaco=1;
                i=-103;
                }
              else if(vetorPrincipal[posicao][i]==-104)
                i=-103;
              } 
            //for(int j=0;j<10;j++){
             // printf("Valor do vetor===%i \n",vetorPrincipal[posicao][j]);
            //}
          if (temEspaco)
            {
                //insere
                return retorno = SUCESSO;
            }
            else
            {
                return retorno = SEM_ESPACO;
            }
        }
        else
        {
            return retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;
    int contador=0;
    if(posicao>10|| posicao<1){
     return retorno = POSICAO_INVALIDA; 
      }  
      posicao--;
    if(vetorPrincipal[posicao]==NULL)
      return retorno=SEM_ESTRUTURA_AUXILIAR;
    for(int i=0;i>-100;i++){
      //printf("Valor do vetorPricipal===%i\n",vetorPrincipal[posicao][i]);
    if(vetorPrincipal[posicao][i]==-104||vetorPrincipal[posicao][i]==-103 )
        i=-103;
    else{
         contador++;
      }
      //printf("So vendo se isso nao da infinito \n");
    }
    if(!contador){
      return retorno=ESTRUTURA_AUXILIAR_VAZIA;
    }
    vetorPrincipal[posicao][contador-1]=-103;
    //printf("O contador===%i \n",contador);
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    
    int retorno = SUCESSO;
    int existe=0;
    int tamanhoVetor=0;
    if(posicao>10|| posicao<1){
     return retorno = POSICAO_INVALIDA; 
      }  
      posicao--;
    if(vetorPrincipal[posicao]==NULL)
      return retorno=SEM_ESTRUTURA_AUXILIAR;

    for(int i=0;i>-100;i++){
      if(vetorPrincipal[posicao][i]==-104)
        i=-103;
      else{
            tamanhoVetor++;
          }
      } 
  
    for(int j=0;j<tamanhoVetor;j++){
      if(vetorPrincipal[posicao][j]==valor){
        for(int m=j;m<tamanhoVetor;m++){
          vetorPrincipal[posicao][m]=vetorPrincipal[posicao][m+1];
        }
         vetorPrincipal[posicao][tamanhoVetor-1]=-103;
        existe=1;
      }
    }
    if(!existe)
      return retorno=NUMERO_INEXISTENTE;
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    if(posicao>10|| posicao<1){
     return retorno = POSICAO_INVALIDA; 
      }  
      posicao--;

    if(vetorPrincipal[posicao]==NULL)
      return retorno=SEM_ESTRUTURA_AUXILIAR;
     
      for(int i=0;i>-100;i++){
        if(vetorPrincipal[posicao][i]==-103||vetorPrincipal[posicao][i]==-104){
          i=-103;
        }
        else{
          vetorAux[i]=vetorPrincipal[posicao][i];
        }
      } 

  
      //*(vetorAux+1)=4;
      //*vetorAux=3;
      //printf("Endereco de vetAux===%p \n",vetorAux);
      //printf("Vetor Aux===%i \n",vetorAux[0]);

    return retorno=SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{    
    int retorno = 0;
    int tamanho=0;
    if(posicao>10|| posicao<1){
     return retorno = POSICAO_INVALIDA; 
      }  
      posicao--;

    if(vetorPrincipal[posicao]==NULL)
      return retorno=SEM_ESTRUTURA_AUXILIAR;
  
      for(int i=0;i>-100;i++){
        if(vetorPrincipal[posicao][i]==-103||vetorPrincipal[posicao][i]==-104){
          i=-103;
        }
        else{
          vetorAux[i]=vetorPrincipal[posicao][i];
          tamanho++;
        }
      } 
  
      int aux, i, j;
	    for(j=tamanho-1; j>=1; j--){
		    for(i=0; i<j; i++){
			    if( vetorAux[i]> vetorAux[i+1]){
				      aux= vetorAux[i];
               vetorAux[i]= vetorAux[i+1];
               vetorAux[i+1]=aux;
            }
        }
    }
    
    return retorno=SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int indiceAux=0;
    int retorno = 0;
    int vazia=0;
    //printf("vetorPrincipal[9][0]==%i \n",vetorPrincipal[9][0]);
    for(int i=0;i<10;i++){
      //printf
      if(vetorPrincipal[i]==NULL)
        vazia++;
      else if((vetorPrincipal[i][0]==-103) || (vetorPrincipal[i][0]==-104))
        vazia++;
      else{
        for(int j=0;j>-100;j++){
          if(vetorPrincipal[i][j]!=-103 && vetorPrincipal[i][j]!=-104){
            vetorAux[indiceAux]=vetorPrincipal[i][j];
            indiceAux++;
          }
          else j=-103;
        }
      }
       }
    if(vazia==10)
      return retorno=TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  
    return retorno=SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int indiceAux=0;
    int retorno = 0;
    int vazia=0;
    //printf("vetorPrincipal[9][0]==%i \n",vetorPrincipal[9][0]);
    for(int i=0;i<10;i++){
      //printf
      if(vetorPrincipal[i]==NULL)
        vazia++;
      else if((vetorPrincipal[i][0]==-103) || (vetorPrincipal[i][0]==-104))
        vazia++;
      else{
        for(int j=0;j>-100;j++){
          if(vetorPrincipal[i][j]!=-103 && vetorPrincipal[i][j]!=-104){
            vetorAux[indiceAux]=vetorPrincipal[i][j];
            indiceAux++;
          }
          else j=-103;
        }
      }
       }
    if(vazia==10)
      return retorno=TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

      int aux, i, j;
	    for(j=indiceAux-1; j>=1; j--){
		    for(i=0; i<j; i++){
			    if( vetorAux[i]> vetorAux[i+1]){
				      aux= vetorAux[i];
               vetorAux[i]= vetorAux[i+1];
               vetorAux[i+1]=aux;
            }
        }
    }

    return retorno=SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int tamanho=0;
    int retorno = 0;
    if(posicao>10|| posicao<1){
      return retorno = POSICAO_INVALIDA; 
      }  
      posicao--;
    if(vetorPrincipal[posicao]==NULL)
      return retorno=SEM_ESTRUTURA_AUXILIAR;

   // printf(" antes vetorPrincipal[posicao][0]==%i\n",vetorPrincipal[posicao][0]);
    for(int i=0;i>-100;i++){
      if(vetorPrincipal[posicao][i]==-104){
        i=-103;
        }
      else{
        tamanho++;
        }
      } 
    int tamanhoSomado=novoTamanho+tamanho;
    if(tamanhoSomado<1)
      return retorno=NOVO_TAMANHO_INVALIDO;
  
    vetorPrincipal[posicao][tamanhoSomado]=-104;
    for(tamanho;tamanho<tamanhoSomado;tamanho++){
        vetorPrincipal[posicao][tamanho]=-103;
    }
    //printf("tamanhoSomado==%i\n",tamanhoSomado);
    //printf(" vetorPrincipal[posicao][0]==%i\n",vetorPrincipal[posicao][1]);
    return retorno=SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno=0;
  
    for(int i=0;i>-100;i++){
      if(vetorPrincipal[posicao][i]!=-103 || vetorPrincipal[posicao][i]!=-104){
       i=-103;
      }
      else{
        //printf("a quantidade ja q bugou geral ");
        }
      retorno++;
    } 
    //printf("Quantidade de elementos==%i \n",quantidade);
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
  for(int i=0;i<100;i++){
     vetorPrincipal[i]=NULL;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}