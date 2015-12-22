#if ! defined( DADOPONTOS_ )
#define DADOPONTOS_
/***************************************************************************
*
*  $MCD Módulo de definição: DP  DADOPONTOS
*
*  Arquivo gerado:              DADOPONTOS.h
*  Letras identificadoras:      DP
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA
*
*
*  $ED Descrição do módulo
*     Implementa criaçao da estrutura de pontos da partida.
*    
*
***************************************************************************/
 
#if defined( DADOPONTOS_OWN )
   #define DADOPONTOS_EXT
#else
   #define DADOPONTOS_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

typedef struct DP_tagElemDadoPontos * DP_tppDadoPontos ;



/***********************************************************************
*
*  $TC Tipo de dados: LIS Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista
*
***********************************************************************/

   typedef enum {

         DP_CondRetOK, 
               /* Concluiu corretamente */

		 DP_CondRetNExisteDP,
			  /* Não existe a estrutura */

		 DP_CondRetJogadorErrado,
			  /* Jogador não pode dobrar */
		 
		 DP_CondRetJaExisteDP,
			  /* Estrutura já existe */

		 DP_CondRetFaltouMemoria,
			  /* Falta memória */

		 DP_CondRetPlayerErrado
			  /* Valor do parametro fora do intervalo de [1,2] */

   } DP_tpCondRet ;

/***********************************************************************
*
*  $FC Função: PECA &Criar Pontuacao
*
*  $ED Descrição da função
*     Cria uma estrutura de pontos.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     plista  -    um ponteiro de tipo DP_tppDadoPontos.
*                     Ver descrição do módulo.
*
*   $EAE Assertivas de entrada
*	 	Há um ponteiro de ponteiro do tipo DP_tppDadoPontos . Este aponta para um lugar desconhecido na memoria.
*
*  $EAS Assertivas de saída
*	    Caso não falte memoria durante a criacao do peça, sera retornado uma estrutura do tipo DadoPontos alocada.
*
*  $FV Valor retornado
*     DP_CondRetOK    - criou a estrutura de pontos sem problema.
*	  DP_CondRetFaltouMemoria - faltou memoria para criaçao da estrutura.
*	  DP_CondRetJaExisteDP	- já existe uma estrutura criada.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

     DP_tpCondRet DP_Cria(DP_tppDadoPontos * pLista);


/***********************************************************************
*
*  $FC Função: PECA &Dobra valor da partida
*
*  $ED Descrição da função
*     Dobra a pontuacao da partida.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     plista  -    um ponteiro de tipo DP_tppDadoPontos.
*     player  -    um inteiro.
*                     Ver descrição do módulo.
*
*   $EAE Assertivas de entrada
*	 	Há um ponteiro de ponteiro do tipo DP_tppDadoPontos . Este aponta para um lugar desconhecido na memoria.
*	 	Há tambem uma variavel int que armazena o jogador que deseja dobrar os pontos da partida.
*
*  $EAS Assertivas de saída
*	    Caso seja a vez do jogar dobrar a partida, a funcao dobra os pontos da partida.
*
*  $FV Valor retornado
*     DP_CondRetOK    - dobrou os pontos sem problema.
*	  DP_CondRetPlayerErrado - valor do parâmetro player fora do intervalo de [1,2].
*	  DP_CondRetMaximoPonto	- chegou ao maximo a pontuacao.
*	  DP_CondRetJogadorErrado	- jogador adversario tentando dobrar a pontucao seguidamente.
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

	 DP_tpCondRet DP_Dobra(DP_tppDadoPontos pLista, int player);

/***********************************************************************
*
*  $FC Função: PECA &Obtem pontuacao atual
*
*  $ED Descrição da função
*     Obtem pontuacao atual da partida
*
*  $EP Parâmetros
*     plista  -    um ponteiro de tipo DP_tppDadoPontos.
*                     Ver descrição do módulo.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo DP_tppDadoPontos . Este aponta para uma estrutura DadoPonto ou para NULL.
*	 	Há tambem um ponteiro de inteiro que aponta para um endereço memória que possui um inteiro.
*
*  $EAS Assertivas de saída
*		Sera armazenada um inteiro no endereço que o ponteiro *ponto aponta.
*
*  $FV Valor retornado
*     pLista->PontoJogo    - retornou o valor da partida com sucesso.
*	  -1 - não existe estrutura criada.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

	 DP_tpCondRet DP_ObterPonto(DP_tppDadoPontos pLista, int *ponto);


/***********************************************************************
*
*  $FC Função: PECA &Obtem jogador
*
*  $ED Descrição da função
*     Obtem o jogador atual da partida
*
*  $EP Parâmetros
*     plista  -    um ponteiro de tipo DP_tppDadoPontos.
*                     Ver descrição do módulo.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo DP_tppDadoPontos . Este aponta para uma estrutura DadoPonto ou para NULL.
*	 	Há tambem um ponteiro de inteiro que aponta para um endereço memória que possui um inteiro.
*
*  $EAS Assertivas de saída
*		Sera armazenada um inteiro no endereço que o ponteiro *ponto aponta.
*
*  $FV Valor retornado
*     pLista->Jogador    - retornou o valor da partida com sucesso.
*	  -1 - não existe estrutura criada.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

	 DP_tpCondRet DP_ObterJogador(DP_tppDadoPontos pLista, int *jogador);


/***********************************************************************
*
*  $FC Função: PECA &Add valores
*
*  $ED Descrição da função
*     Adiciona os valores na estrutura
*
*  $EP Parâmetros
*     plista  -    um ponteiro de tipo DP_tppDadoPontos.
*     pontos  -    um inteiro com a pontuacao.
*     jogador  -    um inteiro com o jogador atual.
*                     Ver descrição do módulo.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo DP_tppDadoPontos . Este aponta para uma estrutura DadoPonto ou para NULL.
*
*  $EAS Assertivas de saída
*		Serao armazenados na estrutura os valores passados no parâmetro.
*
*  $FV Valor retornado
*     DP_CondRetOK    - retornou ok.
*	  -1			  - não existe estrutura criada.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/


	DP_tpCondRet DP_Adiciona(DP_tppDadoPontos pLista, int pontos, int jogador);


/***********************************************************************
*
*  $FC Função: PECA &Destruir
*
*   $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo DP_tppDadoPontos . Este aponta para uma estruturo DadoPonto ou NULL.
*	 	
*  $EAS Assertivas de saída
*	   Caso exista uma estrutura DadoPonto que o ponterio aponte, essa estrutura será liberada.
*
*  $ED Descrição da função
*     Destroi estrutura de pontuacao
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

	 void DP_DestruirPonto(DP_tppDadoPontos pLista);



#undef DADOPONTOS_EXT
/********** Fim do módulo de definição: LIS  Lista duplamente encadeada **********/

#else
#endif