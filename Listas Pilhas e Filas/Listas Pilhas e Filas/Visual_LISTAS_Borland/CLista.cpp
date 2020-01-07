//---------------------------------------------------------------------------

#include "CLista.h"
#include <stdlib.h>
#include <alloc.h>
#include <iostream.h>

void LISTA::InserirInicio(int e)
{
    Elemento *novo = new Elemento(e);
    novo->proximo = inicio;
    inicio = novo;
}
void LISTA::InserirFim(int e)
{
  Elemento *aux = inicio;
  Elemento *ant = aux;

  if (!inicio)
    InserirInicio(e);
  else {
    for(;aux;) {
      ant = aux;
      aux = aux->proximo;
    }
    Elemento *novo = new Elemento(e);
    ant->proximo = novo;
  }
}
void LISTA::EliminarInicio()
{
   Elemento *aux = inicio;
   if (inicio) {
     inicio = inicio->proximo;
     delete aux;
   }
}
void LISTA::EliminarFim()
{
  if (inicio)
    if (inicio->proximo) {                  // 2 ou + elementos
      Elemento *aux = inicio->proximo;
      Elemento *ultimo = inicio;
      Elemento *penultimo = 0;
      for(;aux;) {
        penultimo = ultimo;
        ultimo = aux;
        aux = aux->proximo;
      }
      penultimo->proximo = 0;
      delete ultimo;
    } else {                                // um elemento
       EliminarInicio();
    }

}

Elemento * LISTA::GetInicio()
{
  return inicio;
}
void LISTA::ListarLista()
{
  Elemento *aux;
  aux = inicio;
  cout << endl << "Listar" << endl;
  for(;aux;) {
    cout << aux->info << endl;
    aux = aux->proximo;
  }
}
bool LISTA::Vazia()
{
  return (inicio == 0);
}
void LISTA::InserirOrdenado(int e)
{
  /*
  Em primeiro lugar vamos determinar onde ficar� o novo n�
  que ir� ser adicionado � lista, para conter o valor
  especificado. Para isso vamos determinar qual o n� que
  fica antes do novo e qual o n� que fica depois.
  */

  /*
  Partimos do princ�pio que o novo n� vai ficar antes de
  todos os outros da lista, portanto antes dele n�o h�
  nenhum e depois dele vem o primeiro.
  */
  Elemento * anterior = 0;
  Elemento * seguinte = inicio;

  /*
  E agora vamos procurar a posi��o exacta do novo n�. Para
  tal vamos deslocar-nos para a frente na lista enquanto
  n�o chegarmos ao fim desta (se j� chegamos ao fim da
  lista, isto � se seguinte � NULL, � porque o novo n�
  fica depois de todos os outros) e enquanto o valor que
  andamos � procura for maior que o valor do n� que deve
  ficar a seguir (O valor do n� que fica a seguir do novo
  n� dever� ser sempre maior que o valor contido no novo
  n�).
  */
  while(seguinte != NULL && seguinte->info < e) {
    /*
    Vamos ent�o deslocar-nos para a frente. O n�
    anterior ao novo passa a ser aquele que � agora
    o seguinte e o seguinte passa a ser aquele que
    est� � frente daquele que � actualmente o
    seguinte.
    */
    anterior = seguinte;
    seguinte = seguinte->proximo;
  }

  /*
  Uma vez encontrada a posi��o do novo n�, vamos ent�o
  cri�-lo e colocar no atributo valor o valor que
  pretendemos que ele guarde.
  */
  Elemento * novo = new Elemento;
  novo->info = e;

  /*
  Resta-nos agora introduzi-lo na lista. Se antes do nosso
  novo n� n�o existe nenhum, ele passa a ser o primeiro,
  logo o ponteiro primeiro deve apontar para o nosso novo
  n�. Sen�o temos que indicar que o n� que vem a seguir ao
  n� que fica antes do nosso novo n� � precisamente o novo
  n�.
  */
  if (anterior == 0)
    inicio = novo;
  else
    anterior->proximo = novo;

  /*
  Para acabar de ligar o novo n� � lista temos ainda que
  indicar que o n� que vem a seguir ao novo � aquele que
  j� t�nhamos determinado previamente como vindo depois do
  novo n�.
  */
  novo->proximo = seguinte;
}
void LISTA::EliminarElemento(int e)
{
  /*
  Para retirarmos um valor da lista, ao contr�rio do que
  acontecia nas pilhas e nas filas, temos de especificar
  qual o valor a retirar. Ent�o o primeiro passo para
  removermos um dado valor na lista ser� o de procurarmos
  o n� (a apagar) que cont�m esse mesmo valor.
  */

  /*
  Partimos do princ�pio que o n� a apagar � o primeiro.
  Portanto antes dele n�o h� nenhum.
  */
  Elemento * anterior = 0;
  Elemento * actual   = inicio;

  /*
  E agora vamos procurar a posi��o exacta do n� a apagar.
  Para tal vamos deslocar-nos para a frente na lista
  enquanto n�o chegarmos ao fim desta (se j� chegamos ao
  fim da lista, isto � se actual � NULL, � porque n�o
  existe um n� com o valor especificado) e enquanto o
  valor que andamos � procura for maior que o valor do n�
  actual (Se o n� actual tem um valor maior ou igual
  �quele que andamos � procura ent�o ou j� encontramos o
  n� contendo o valor que andamos � procura ou n�o existe
  nenhum n� na lista com esse valor (n�o nos podemos
  esquecer que a lista est� ordenada)).
  */
  while(actual != NULL && actual->info < e) {
    anterior = actual;
    actual   = actual->proximo;
  }

  // se encontramos o elemento a apagar (actual)
  if (actual != NULL && actual->info == e) {
    /*
    se � n� a apagar � o primeiro, o primeiro dever�
    passar a ser aquele que vem depois do n� que
    vamos apagar. Sen�o o n� que vem depois do n�
    que est� antes do que vamos apagar passa a ser
    aquele que vem depois do que vamos apagar.
    */
    if (anterior == 0)          // if (actual == primeiro)
      inicio = actual->proximo;
    else
      anterior->proximo = actual->proximo;

    /*
    Podemos apagar agora o n�, uma vez que j�
    estabelecemos as liga��es entre o n� que estava
    antes deste e o que vinha depois.
    */
    delete actual;
  }
}
void LISTA::EliminarElementos(int e)
{
}
void LISTA::EliminarDeUmElementoAteFim(int e)
{
}
void LISTA::EliminarDoInicioAteElemento(int e)
{
}
void LISTA::EliminarRepetidos()
{
}
int LISTA::ContarElememto(int e)
{
}
int LISTA::Tamanho()
{
  int c = 0;
  Elemento *aux = inicio ;
  while (aux != 0) {
    aux = aux->proximo;
    c++;
  }
  return c;
}


/*
    Vamos apagar o primeiro elemento, mas antes
    guardamos o elemento que vem depois
    do primeiro, j� que este passar�, depois de
    apagarmos aquele que � o primeiro, a ser o
    primeiro.
*/
LISTA::~LISTA()
{

  while (inicio != 0) {
    Elemento * segundo = inicio->proximo;
    delete inicio;
    inicio = segundo;
  }
}

/*
int *v= (int *) malloc(100 * sizeof(int));
free(v);

int *v2 = new int[100];
delete [] v2;*/




/*void LISTA::InserirOrdenado(int e)
{
  Elemento * seguinte = inicio;
  while((seguinte != 0) && (seguinte->info < e))
    seguinte = seguinte->proximo;
  Elemento * novo = new Elemento(e);
  novo->proximo = seguinte;
  if (seguinte == NULL) {   // ins fim
    novo->anterior = fim;
    fim = novo;
  } else {
    novo->anterior = seguinte->anterior;
    seguinte->anterior = novo;
  }
  El emento * ant = novo->anterior;
  if (ant == NULL)
    inicio = novo;
  else
    ant->proximo = novo;
} */

