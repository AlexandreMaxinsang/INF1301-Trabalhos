#if ! defined( PECACAPTURADA_ )
#define PECACAPTURADA_
/***************************************************************************
*
*  $MCD Módulo de definição: PECACAPTURADA  peça
*
*  Arquivo gerado:              PECACAPTURADA.h
*  Letras identificadoras:      PECACAPTURADA
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descrição do módulo
*     Implementa criaçao de uma lista duplamente encadeada de peças capturadas.
*     Podem existir n listas  em operação simultaneamente.
*
***************************************************************************/
 
#if defined( PECACAPTURADA_OWN )
   #define PECACAPTURADA_EXT
#else
   #define PECACAPTURADA_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

typedef  struct LIS_tagLista * PECACAPTURADA_tppLista ;

typedef struct PECA_tagElemPeca * PECA_tppPeca ;

/***********************************************************************
*
*  $TC Tipo de dados: PECACAPTURADA Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista
*
***********************************************************************/

   typedef enum {

         PECACAPTURADA_CondRetOK,
               /* Concluiu corretamente */

         PECACAPTURADA_CondRetPecaVazia ,
               /* A peça esta vazia  */

         PECACAPTURADA_CondRetFaltouMemoria
               /* Faltou memória ao tentar criar um elemento de lista */

   } PECACAPTURADA_tpCondRet ;

   /***********************************************************************
*
*  $FC Função: PECACAPTURADA &Criar Peca
*
*  $ED Descrição da função
*     Cria  lista duplamente encadeada de peça capturada.
*
*  $EP Parâmetros
*     pLista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descrição do módulo.
*
*   $EAE Assertivas de entrada
*   Existe um ponteiro  tipo PECACAPTURADA_tppLista que aponta para um lugar desconhecido na memoria.
*
*   $EAS Assertivas de saída
*	Caso nao falte memoria durante a criacao da lista, o ponteiro  apontara para a cabeça da lista duplamente encadeada de peças finalizadas.
*	
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - criou a lista duplamente encadeada de peças sem problema.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

  PECACAPTURADA_tpCondRet PECACAPTURADA_CriarPecaCapturada(PECACAPTURADA_tppLista *pLista);


/***********************************************************************
*
*  $FC Função: PECACAPTURADA  &Destruir Peca 
*
*  $ED Descrição da função
*     Destrói a lista duplamente encadeada de peças capturadas.

*  $EP Parâmetros
*     pLista  -    um tipo de dado PECACAPTURADA_tppLista.
*                     Ver descrição do módulo.
*
*  $EAE Assertivas de entrada
*	 	Existe uma lista duplamente encadeada de peças finalizadas do tipo PECACAPTURADA_tppLista.
*	 	
*  $EAS Assertivas de saída
*	   Libera a lista duplamente encadeada de peças finalizadas.
*
*
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - destroi a lista duplamente encadeada de peças sem problema.
*    
*     Não será dada mais informação quanto ao problema ocorrido.
***********************************************************************/

    PECACAPTURADA_tpCondRet PECACAPTURADA_DestruirPeca( PECACAPTURADA_tppLista pLista );

/***************************************************************************
*
*  $FC Função: PECACAPTURADA &Inserir uma peça capturada 
*
*  $ED Descrição da função
*     Insere uma peça na lista duplamente encadeada de peças.
*
*  $EP Parâmetros
*     plista  -   um  tipo de dado PECACAPTURADA_tppLista.
*                     Ver descrição do módulo.
*	  pPeca     -   um ponterio para uma tipo PECA_tppLista
*
*   $EAE Assertivas de entrada
*	 	Existe uma lista duplamente encadeada de peças finalizadas do tipo PECACAPTURADA_tppLista
*	 	Existe tambem um tipo de dado PECA_tppPeca.
*
*  $EAS Assertivas de saída
*		Será inserido o tipo de dado ,fornecido no parametro da função,na lista duplamente encadeada de peças finalizadas.
*
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - Inseriu a peça sem problema.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*  *******************************************************************/

   PECACAPTURADA_tpCondRet PECACAPTURADA_InserirPecaCapturada(PECACAPTURADA_tppLista pLista,char cor);



   /***************************************************************************
*
*  $FC Função: PECACAPTURADA &Retirar  Peca Capturada
*
*  $ED Descrição da função
*     Retira uma peça da lista duplamente encadeada.
*
*  $EP Parâmetros
*     pLista  -   um tipo de dado PECACAPTURADA_tppLista.
*                     Ver descrição do módulo.
*	  pPeca	  -		um ponteiro para tipo de dado PECA_tppLista
*
*   $EAE Assertivas de entrada
*	    Existe uma lista duplamente encadeada de peças finalizadas do tipo PECACAPTURADA_tppLista.
*	 	Existe tambem um ponteiro do tipo PECA_tppPeca que aponta para um lugar desconhecido na memoria.
*
*  $EAS Assertivas de saída
*		Caso a lista não estaja vazia,o ponteiro do tipo PECA_tppPeca apontará para uma peça.
*
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - retirou a peça sem problema.
*	  PECACAPTURADA_CondRetPecaVazia -A lista duplamente encadeada de peças esta vazia.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*  *******************************************************************/

     PECACAPTURADA_tpCondRet PECACAPTURADA_RetirarPecaCapturada(PECACAPTURADA_tppLista pLista );


/***************************************************************************
*
*  $FC Função: PECACAPTURADA &Quantidade Peças Capturadas
*
*  $ED Descrição da função
*     Retorna a quantidade de peças capturadas na lista.
*
*  $EP Parâmetros
*     pLista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descrição do módulo.
*	  qtd     -   um ponterio de tipo int,em aponta para um dado que armazenará a quantidade de elementos na lista
*
*   $EAE Assertivas de entrada
*	 	Existe um dado do tipo PECACAPTURADA_tppLista.
*	 	Existe um ponteiro do tipo int que aponta para algum lugar desconhecido da memória.
*
*  $EAS Assertivas de saída
*		O ponteiro qtd apontará para um dado que armazena a quantidade de elementos da lista.
*
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - Percorreu a lista sem problemas.
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*  *******************************************************************/

	 PECACAPTURADA_tpCondRet PECACAPTURADA_QuantidadePecaCapturada(PECACAPTURADA_tppLista pLista,int *qtd);



#undef PECACAPTURADA_EXT
/********** Fim do módulo de definição: PECACAPTURADA **********/

#else
#endif