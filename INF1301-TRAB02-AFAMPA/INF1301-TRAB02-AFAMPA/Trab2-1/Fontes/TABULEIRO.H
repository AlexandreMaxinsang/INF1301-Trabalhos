#if ! defined( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD Módulo de definição: TAB  Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA
*
*
*  $ED Descrição do módulo
*     Implementa criaçao do tabuleiro.
*     Podem existir n tabuleiros em operação simultaneamente.
*     Os tabuleiros possuem uma cabeça encapsulando o seu estado.
*
*     Cada tabuleiro é homogênea quanto ao tipo dos dados que armazena.
*     Cada elemento do tabuleiro referencia o valor que contém.
*
*     Os ponteiros para os dados são copiados para elementos da lista.
*        Não é copiado o valor apontado por estes ponteiros.
*
*     O controle da destruição do valor de um elemento a ser excluído
*        é realizado por uma função fornecida pelo usuário.
*
*     Cada lista referencia uma função que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A função de liberação dos valores contidos nos elementos deve
*        assegurar a liberação de todos os espaços referênciados pelo
*        valor contido em um elemento.
*        Esta função é chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso não seja necessário desalocar o valor referenciado pelo
*        elemento, o ponteiro para a função de liberação poderá ser NULL .
*        Caso o elemento da lista seja a única âncora do valor referenciado,
*        esta função deve promover a destruição (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/
 
#if defined( TABULEIRO_OWN )
   #define TABULEIRO_EXT
#else
   #define TABULEIRO_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

typedef struct LIS_tagLista * LIS_tppLista ;

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista
*
***********************************************************************/

   typedef enum {

         TAB_CondRetOK ,
               /* Concluiu corretamente */

         TAB_CondRetListaVazia ,
               /* A lista não contém elementos */

         TAB_CondRetFimLista ,
               /* Foi atingido o fim de lista */

         TAB_CondRetFaltouMemoria,
               /* Faltou memória ao tentar criar um elemento de lista */

		 TAB_CondRetNaoTemPeca,
               /* Tentando mover uma peca que não existe */

		 TAB_CondRetLPecasAdversarias,
               /* Possui 2 ou mais pecas adversarias para a posicao que se deseja mover a peca */

		 TAB_CondRetMesmaCasa,
               /* Tentando mover para mesma casa */

		 TAB_CondRetForaTabuleiro
               /* Tentando mover para fora do tabuleiro */

   } TAB_tpCondRet;

/***********************************************************************
*
*  $FC Função: TAB &Criar tabuleiro
*
*  $ED Descrição da função
*     Cria um tabuleiro.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     plista  -    um ponteiro de tipo de um ponteiro.
*     cor1  -    um char para identificar a cor da peca do jogador 1.
*     cor2  -    um char para identificar a cor da peca do jogador 2.
*                     Ver descrição do módulo.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro de ponteiro do tipo LIS_tppLista . Este aponta para um lugar desconhecido na memoria.
*	 	Há tambem duas variaveis char que armazenam as cores desejadas das peças do tabuleiro.
*
*  $EAS Assertivas de saída
*	    Caso não falte memoria durante a criacao do tabuleiro, sera retornado um tabuleiro alocado.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - criou o tabuleiro sem problema.
*	  TAB_CondRetFaltouMemoria - faltou memória para alocar tabuleiro.
*
*     
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

   TAB_tpCondRet  TAB_CriarTabuleiro(LIS_tppLista* pLista, char cor1, char cor2);


/***********************************************************************
*
*  $FC Função: TAB &Mover Peca
*
*  $ED Descrição da função
*     Move uma peca de uma posição para outra.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     plista  -	um ponteiro de tipo de um ponteiro.
*	  pospeca -	um inteiro da posicao da peca a ser movida
*	  qtd -	um inteiro da quantidade que se deseja mover a peca
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo LIS_tppLista . Este aponta para um lugar desconhecido na memoria.
*	 	Há tambem duas variaveis inteiro, uma delas armazena a posição da peça a ser movida e a outra a quantidade de casa que vai ser pulada para mover a peça.
*
*  $EAS Assertivas de saída
*	    Caso a posição da peça fornecida esteja entra 1 e 24 e a quantidade de casa a ser movida ainda estiver dentro do tabuleiro 
*		e a peça puder ser movida de acordo com as regras do jogo do gamão, a peça será movida corretamente.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - Moveu a peca sem problema.
*	  TAB_CondRetLPecasAdversarias - Tentou mover a peca para uma posicao onde tem mais de 2 pecas adversárias
*	  TAB_CondRetNaoTemPeca - Tentou mover uma peca que n existe
*	  TAB_CondRetForaTabuleiro - Tentou mover para fora do tabuleiro
*	  TAB_CondRetMesmaCasa - Tentou mover para a mesma casa da peca a ser movida
*
*     
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

   TAB_tpCondRet TAB_MoverPeca(LIS_tppLista pLista, int pospeca, int qtd);


/***********************************************************************
*
*  $FC Função: TAB  &Destruir tabuleiro
*
*  $ED Descrição da função
*     Destrói o tabuleiro .
*     O parâmetro ponteiro para a lista não é modificado.
*     Se ocorrer algum erro durante a destruição, a lista resultará
*     estruturalmente incorreta.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo LIS_tppLista . Este aponta para um tabuleiro ou NULL.
*	 	
*  $EAS Assertivas de saída
*	   Caso exista um tabuleiro que o ponteiro aponte, esse tabuleiro será liberado.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   void TAB_DestruirTabuleiro( LIS_tppLista pLista ) ;

#undef TABULEIRO_EXT
/********** Fim do módulo de definição: LIS  Lista duplamente encadeada **********/

#else
#endif
