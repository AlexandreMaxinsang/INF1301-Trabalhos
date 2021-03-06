#if ! defined( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: TAB  Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA
*
*
*  $ED Descri��o do m�dulo
*     Implementa cria�ao do tabuleiro.
*     Podem existir n tabuleiros em opera��o simultaneamente.
*     Os tabuleiros possuem uma cabe�a encapsulando o seu estado.
*
*     Cada tabuleiro � homog�nea quanto ao tipo dos dados que armazena.
*     Cada elemento do tabuleiro referencia o valor que cont�m.
*
*     Os ponteiros para os dados s�o copiados para elementos da lista.
*        N�o � copiado o valor apontado por estes ponteiros.
*
*     O controle da destrui��o do valor de um elemento a ser exclu�do
*        � realizado por uma fun��o fornecida pelo usu�rio.
*
*     Cada lista referencia uma fun��o que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A fun��o de libera��o dos valores contidos nos elementos deve
*        assegurar a libera��o de todos os espa�os refer�nciados pelo
*        valor contido em um elemento.
*        Esta fun��o � chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso n�o seja necess�rio desalocar o valor referenciado pelo
*        elemento, o ponteiro para a fun��o de libera��o poder� ser NULL .
*        Caso o elemento da lista seja a �nica �ncora do valor referenciado,
*        esta fun��o deve promover a destrui��o (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/
 
#if defined( TABULEIRO_OWN )
   #define TABULEIRO_EXT
#else
   #define TABULEIRO_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct LIS_tagLista * LIS_tppLista ;

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         TAB_CondRetOK ,
               /* Concluiu corretamente */

         TAB_CondRetListaVazia ,
               /* A lista n�o cont�m elementos */

         TAB_CondRetFimLista ,
               /* Foi atingido o fim de lista */

         TAB_CondRetFaltouMemoria,
               /* Faltou mem�ria ao tentar criar um elemento de lista */

		 TAB_CondRetNaoTemPeca,
               /* Tentando mover uma peca que n�o existe */

		 TAB_CondRetLPecasAdversarias,
               /* Possui 2 ou mais pecas adversarias para a posicao que se deseja mover a peca */

		 TAB_CondRetMesmaCasa,
               /* Tentando mover para mesma casa */

		 TAB_CondRetForaTabuleiro
               /* Tentando mover para fora do tabuleiro */

   } TAB_tpCondRet;

/***********************************************************************
*
*  $FC Fun��o: TAB &Criar tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria um tabuleiro.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     plista  -    um ponteiro de tipo de um ponteiro.
*     cor1  -    um char para identificar a cor da peca do jogador 1.
*     cor2  -    um char para identificar a cor da peca do jogador 2.
*                     Ver descri��o do m�dulo.
*
*  $EAE Assertivas de entrada
*	 	H� um ponteiro de ponteiro do tipo LIS_tppLista . Este aponta para um lugar desconhecido na memoria.
*	 	H� tambem duas variaveis char que armazenam as cores desejadas das pe�as do tabuleiro.
*
*  $EAS Assertivas de sa�da
*	    Caso n�o falte memoria durante a criacao do tabuleiro, sera retornado um tabuleiro alocado.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - criou o tabuleiro sem problema.
*	  TAB_CondRetFaltouMemoria - faltou mem�ria para alocar tabuleiro.
*
*     
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

   TAB_tpCondRet  TAB_CriarTabuleiro(LIS_tppLista* pLista, char cor1, char cor2);


/***********************************************************************
*
*  $FC Fun��o: TAB &Mover Peca
*
*  $ED Descri��o da fun��o
*     Move uma peca de uma posi��o para outra.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     plista  -	um ponteiro de tipo de um ponteiro.
*	  pospeca -	um inteiro da posicao da peca a ser movida
*	  qtd -	um inteiro da quantidade que se deseja mover a peca
*
*  $EAE Assertivas de entrada
*	 	H� um ponteiro do tipo LIS_tppLista . Este aponta para um lugar desconhecido na memoria.
*	 	H� tambem duas variaveis inteiro, uma delas armazena a posi��o da pe�a a ser movida e a outra a quantidade de casa que vai ser pulada para mover a pe�a.
*
*  $EAS Assertivas de sa�da
*	    Caso a posi��o da pe�a fornecida esteja entra 1 e 24 e a quantidade de casa a ser movida ainda estiver dentro do tabuleiro 
*		e a pe�a puder ser movida de acordo com as regras do jogo do gam�o, a pe�a ser� movida corretamente.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - Moveu a peca sem problema.
*	  TAB_CondRetLPecasAdversarias - Tentou mover a peca para uma posicao onde tem mais de 2 pecas advers�rias
*	  TAB_CondRetNaoTemPeca - Tentou mover uma peca que n existe
*	  TAB_CondRetForaTabuleiro - Tentou mover para fora do tabuleiro
*	  TAB_CondRetMesmaCasa - Tentou mover para a mesma casa da peca a ser movida
*
*     
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

   TAB_tpCondRet TAB_MoverPeca(LIS_tppLista pLista, int pospeca, int qtd);


/***********************************************************************
*
*  $FC Fun��o: TAB  &Destruir tabuleiro
*
*  $ED Descri��o da fun��o
*     Destr�i o tabuleiro .
*     O par�metro ponteiro para a lista n�o � modificado.
*     Se ocorrer algum erro durante a destrui��o, a lista resultar�
*     estruturalmente incorreta.
*     OBS. n�o existe previs�o para poss�veis falhas de execu��o.
*
*  $EAE Assertivas de entrada
*	 	H� um ponteiro do tipo LIS_tppLista . Este aponta para um tabuleiro ou NULL.
*	 	
*  $EAS Assertivas de sa�da
*	   Caso exista um tabuleiro que o ponteiro aponte, esse tabuleiro ser� liberado.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   void TAB_DestruirTabuleiro( LIS_tppLista pLista ) ;

#undef TABULEIRO_EXT
/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/

#else
#endif
