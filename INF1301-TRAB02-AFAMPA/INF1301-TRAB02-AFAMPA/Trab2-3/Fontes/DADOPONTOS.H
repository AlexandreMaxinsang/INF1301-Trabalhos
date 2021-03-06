#if ! defined( DADO_ )
#define DADO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: DP  DADOPONTOS
*
*  Arquivo gerado:              DADOPONTOS.h
*  Letras identificadoras:      DP
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA
*
*
*  $ED Descri��o do m�dulo
*     Implementa cria�ao da estrutura de pontos da partida.
*    
*
***************************************************************************/
 
#if defined( DADOPONTOS_OWN )
   #define DADOPONTOS_EXT
#else
   #define DADOPONTOS_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct DP_tagElemDadoPontos * DP_tppDadoPontos ;



/***********************************************************************
*
*  $TC Tipo de dados: LIS Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         DP_CondRetOK, 
               /* Concluiu corretamente */

		 DP_CondRetNExisteDP,
			  /* N�o existe a estrutura */

		 DP_CondRetJogadorErrado,
			  /* Jogador n�o pode dobrar */
		 
		 DP_CondRetJaExisteDP,
			  /* Estrutura j� existe */

		 DP_CondRetFaltouMemoria,
			  /* Falta mem�ria */

		 DP_CondRetPlayerErrado
			  /* Valor do parametro fora do intervalo de [1,2] */

   } DP_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o: PECA &Criar Pontuacao
*
*  $ED Descri��o da fun��o
*     Cria uma estrutura de pontos.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     plista  -    um ponteiro de tipo DP_tppDadoPontos.
*                     Ver descri��o do m�dulo.
*
*   $EAE Assertivas de entrada
*	 	H� um ponteiro de ponteiro do tipo DP_tppDadoPontos . Este aponta para um lugar desconhecido na memoria.
*
*  $EAS Assertivas de sa�da
*	    Caso n�o falte memoria durante a criacao do pe�a, sera retornado uma estrutura do tipo DadoPontos alocada.
*
*  $FV Valor retornado
*     DP_CondRetOK    - criou a estrutura de pontos sem problema.
*	  DP_CondRetFaltouMemoria - faltou memoria para cria�ao da estrutura.
*	  DP_CondRetJaExisteDP	- j� existe uma estrutura criada.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

     DP_tpCondRet DP_Cria(DP_tppDadoPontos * pLista);


/***********************************************************************
*
*  $FC Fun��o: PECA &Dobra valor da partida
*
*  $ED Descri��o da fun��o
*     Dobra a pontuacao da partida.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     plista  -    um ponteiro de tipo DP_tppDadoPontos.
*     player  -    um inteiro.
*                     Ver descri��o do m�dulo.
*
*   $EAE Assertivas de entrada
*	 	H� um ponteiro de ponteiro do tipo DP_tppDadoPontos . Este aponta para um lugar desconhecido na memoria.
*	 	H� tambem uma variavel int que armazena o jogador que deseja dobrar os pontos da partida.
*
*  $EAS Assertivas de sa�da
*	    Caso seja a vez do jogar dobrar a partida, a funcao dobra os pontos da partida.
*
*  $FV Valor retornado
*     DP_CondRetOK    - dobrou os pontos sem problema.
*	  DP_CondRetPlayerErrado - valor do par�metro player fora do intervalo de [1,2].
*	  DP_CondRetMaximoPonto	- chegou ao maximo a pontuacao.
*	  DP_CondRetJogadorErrado	- jogador adversario tentando dobrar a pontucao seguidamente.
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

	 DP_tpCondRet DP_Dobra(DP_tppDadoPontos pLista, int player);

/***********************************************************************
*
*  $FC Fun��o: PECA &Obtem pontuacao atual
*
*  $ED Descri��o da fun��o
*     Obtem pontuacao atual da partida
*
*  $EP Par�metros
*     plista  -    um ponteiro de tipo DP_tppDadoPontos.
*                     Ver descri��o do m�dulo.
*
*  $EAE Assertivas de entrada
*	 	H� um ponteiro do tipo DP_tppDadoPontos . Este aponta para uma estrutura DadoPonto ou para NULL.
*	 	H� tambem um ponteiro de inteiro que aponta para um endere�o mem�ria que possui um inteiro.
*
*  $EAS Assertivas de sa�da
*		Sera armazenada um inteiro no endere�o que o ponteiro *ponto aponta.
*
*  $FV Valor retornado
*     pLista->PontoJogo    - retornou o valor da partida com sucesso.
*	  -1 - n�o existe estrutura criada.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

	 DP_tpCondRet DP_ObterPonto(DP_tppDadoPontos pLista, int *ponto);


/***********************************************************************
*
*  $FC Fun��o: PECA &Destruir
*
*   $EAE Assertivas de entrada
*	 	H� um ponteiro do tipo DP_tppDadoPontos . Este aponta para uma estruturo DadoPonto ou NULL.
*	 	
*  $EAS Assertivas de sa�da
*	   Caso exista uma estrutura DadoPonto que o ponterio aponte, essa estrutura ser� liberada.
*
*  $ED Descri��o da fun��o
*     Destroi estrutura de pontuacao
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

	 void DP_DestruirPonto(DP_tppDadoPontos pLista);



#undef DADOPONTOS_EXT
/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/

#else
#endif