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
*  Autores: Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
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

typedef struct LIS_tagLista * TAB_tppLista ;

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

         TAB_CondRetFimTab ,
               /* Foi atingido o fim de lista */

         TAB_CondRetFaltouMemoria,
              /* Faltou mem�ria ao tentar criar um elemento de lista */

		 TAB_CondRetListaVazia
			/* Lista vazia */
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
*
*  $EAE Assertivas de entrada
*	 	H� um ponteiro de ponteiro do tipo TAB_tppLista . Este aponta para um lugar desconhecido na memoria.
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
   
   
   TAB_tpCondRet  TAB_CriarTabuleiro(TAB_tppLista* pLista);


/***********************************************************************
*
*  $FC Fun��o: TAB &Inserir Peca
*
*  $ED Descri��o da fun��o
*     Move uma peca de uma posi��o para outra.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     plista  -	um ponteiro de tipo de um ponteiro.
*	  cor_jogador -	um char da cor da peca a ser inserido.
*	  qtdpeca -	um inteiro da quantidade que se deseja inserir.
*
*  $EAE Assertivas de entrada
*	 	H� um ponteiro que aponta para um tabuleiro .
*	 	H� tambem uma variavel char que armazena a cor da pe�a e uma outra variavel que armazena a quantidade de pecas a ser inserido.
*
*  $EAS Assertivas de sa�da
*	    Caso exista um tabuleiro,sera inserido uma nova pe�a no elemento corrente do tabuleiro a pe�a ser� inserido corretamente.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - Moveu a peca sem problema.
*
*     
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

   TAB_tpCondRet  TAB_InserirPeca(TAB_tppLista pLista,char cor_jogador,int qtdpeca);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Avancar Elemento Corrente
*
*  $ED Descri��o da fun��o
*     Avan�a o elemento corrente do tabuleiro .
*    
*     OBS. n�o existe previs�o para poss�veis falhas de execu��o.
*
*  $EAE Assertivas de entrada
*	 	H� um ponteiro que aponta para um tabuleiro  .
*	 	
*  $EAS Assertivas de sa�da
*	   Caso exista um elementos nesse tabuleiro e se numElem>0, o elemento corrente avan�ar� numElem elementos para fim da lista.
*      Se numElem<0,o elemento corrente avan�ar� numElem elementos para o inicio da lista
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*	  TAB_CondRetFimLista- Fim da lista
*	  TAB_CondRetListaVazia- A lista dos valores de cada elemento do tabul� n�o cont�m elementos
***********************************************************************/

   TAB_tpCondRet TAB_AvancarElementoCorrente(TAB_tppLista pLista,int numElem );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Obter Cor No
*
*  $ED Descri��o da fun��o
*     Obtem o a cor da elemento corrente da lista de pecas do elemeneto corrente do tabuleiro .
*     O par�metro ponteiro para a lista n�o � modificado.
*     Se ocorrer algum erro durante a destrui��o, a lista resultar�
*     estruturalmente incorreta.
*     OBS. n�o existe previs�o para poss�veis falhas de execu��o.
*
*  $EAE Assertivas de entrada
*	 	H� um dado do tipo TAB_tppLista . Este armazena para um tabuleiro.
*	 	H� um ponterio para char que aponta para um endere�o desconhecido da memoria.
*
*  $EAS Assertivas de sa�da
*	   Caso o tabuleiro nao esteja vazia , o ponteiro cor aponta fara para um endere�o de memoria que tenha o dado da cor da pe�a.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   TAB_tpCondRet TAB_ObterCorNo(TAB_tppLista pLista,char *cor );


/***********************************************************************
*
*  $FC Fun��o: TAB  &Ir Tabuleiro
*
*  $ED Descri��o da fun��o
*     Faz com que o elemento corrente do tabuleiro a aponte para a origem da lista .
*     O par�metro ponteiro para a lista n�o � modificado.
*     Se ocorrer algum erro durante a destrui��o, a lista resultar�
*     estruturalmente incorreta.
*     OBS. n�o existe previs�o para poss�veis falhas de execu��o.
*
*  $EAE Assertivas de entrada
*	 	H� um dado do tipo TAB_tppLista . Este armazena um tabuleiro .
*	 	
*  $EAS Assertivas de sa�da
*	   Caso exista um tabuleiro n�o vazio, o elemento corrente ser� o elemento da origem .
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   TAB_tpCondRet TAB_IrInicioTabuleiro(TAB_tppLista pLista);


/***********************************************************************
*
*  $FC Fun��o: TAB  &Excluir Elem Tabuleiro
*
*  $ED Descri��o da fun��o
*    Excluir o elemento corrente da lista que percente ao elemento corrente da lista principal(tabuleiro).
*
*  $EAE Assertivas de entrada
*	 	H� um dado do tipo TAB_tppLista . Este armazena uma lista de tabuleiro .
*	 	
*  $EAS Assertivas de sa�da
*	   Caso exista o elemento corrente da lista que percente ao elemento corrente da lista principal , esse elemento ser� eliminado .
*
*  $FV Valor retornado
*     TAB_CondRetOK    - Excluiu o elemento sem problema.
***********************************************************************/


   TAB_tpCondRet TAB_ExcluirElemTabuleiro(TAB_tppLista pLista);



/***********************************************************************
*
*  $FC Fun��o: TAB  &Imprime tabuleiro
*
*  $ED Descri��o da fun��o
*    Imprimi as pe�as da lista de pe�as que percentence a cada elemento da lista de tabuleiro
*
*  $EAE Assertivas de entrada
*	 	H� um dado do tipo TAB_tppLista . Este armazena uma lista de tabuleiro.
*	 	
*  $EAS Assertivas de sa�da
*	   Caso exista algum tabuleiro com pe�as, ser� imprimido as pe�as para cada n� da lista principal .
*
*  $FV Valor retornado
*     TAB_CondRetOK    - imprimi sem problemas
*
***********************************************************************/

   
   TAB_tpCondRet TAB_Imprime(TAB_tppLista pLista);


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
*	 	H� um ponteiro do tipo TAB_tppLista . Este aponta para um tabuleiro ou NULL.
*	 	
*  $EAS Assertivas de sa�da
*	   Caso exista um tabuleiro que o ponteiro aponte, esse tabuleiro ser� liberado.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   void TAB_DestruirTabuleiro( TAB_tppLista pLista ) ;


   


#undef TABULEIRO_EXT
/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/

#else
#endif
