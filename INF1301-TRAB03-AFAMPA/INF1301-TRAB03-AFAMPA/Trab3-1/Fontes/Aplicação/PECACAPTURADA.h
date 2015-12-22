#if ! defined( PECACAPTURADA_ )
#define PECACAPTURADA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: PECACAPTURADA  pe�a
*
*  Arquivo gerado:              PECACAPTURADA.h
*  Letras identificadoras:      PECACAPTURADA
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descri��o do m�dulo
*     Implementa cria�ao de uma lista duplamente encadeada de pe�as capturadas.
*     Podem existir n listas  em opera��o simultaneamente.
*
***************************************************************************/
 
#if defined( PECACAPTURADA_OWN )
   #define PECACAPTURADA_EXT
#else
   #define PECACAPTURADA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef  struct LIS_tagLista * PECACAPTURADA_tppLista ;

typedef struct PECA_tagElemPeca * PECA_tppPeca ;

/***********************************************************************
*
*  $TC Tipo de dados: PECACAPTURADA Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         PECACAPTURADA_CondRetOK,
               /* Concluiu corretamente */

         PECACAPTURADA_CondRetPecaVazia ,
               /* A pe�a esta vazia  */

         PECACAPTURADA_CondRetFaltouMemoria
               /* Faltou mem�ria ao tentar criar um elemento de lista */

   } PECACAPTURADA_tpCondRet ;

   /***********************************************************************
*
*  $FC Fun��o: PECACAPTURADA &Criar Peca
*
*  $ED Descri��o da fun��o
*     Cria  lista duplamente encadeada de pe�a capturada.
*
*  $EP Par�metros
*     pLista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descri��o do m�dulo.
*
*   $EAE Assertivas de entrada
*   Existe um ponteiro  tipo PECACAPTURADA_tppLista que aponta para um lugar desconhecido na memoria.
*
*   $EAS Assertivas de sa�da
*	Caso nao falte memoria durante a criacao da lista, o ponteiro  apontara para a cabe�a da lista duplamente encadeada de pe�as finalizadas.
*	
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - criou a lista duplamente encadeada de pe�as sem problema.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

  PECACAPTURADA_tpCondRet PECACAPTURADA_CriarPecaCapturada(PECACAPTURADA_tppLista *pLista);


/***********************************************************************
*
*  $FC Fun��o: PECACAPTURADA  &Destruir Peca 
*
*  $ED Descri��o da fun��o
*     Destr�i a lista duplamente encadeada de pe�as capturadas.

*  $EP Par�metros
*     pLista  -    um tipo de dado PECACAPTURADA_tppLista.
*                     Ver descri��o do m�dulo.
*
*  $EAE Assertivas de entrada
*	 	Existe uma lista duplamente encadeada de pe�as finalizadas do tipo PECACAPTURADA_tppLista.
*	 	
*  $EAS Assertivas de sa�da
*	   Libera a lista duplamente encadeada de pe�as finalizadas.
*
*
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - destroi a lista duplamente encadeada de pe�as sem problema.
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
***********************************************************************/

    PECACAPTURADA_tpCondRet PECACAPTURADA_DestruirPeca( PECACAPTURADA_tppLista pLista );

/***************************************************************************
*
*  $FC Fun��o: PECACAPTURADA &Inserir uma pe�a capturada 
*
*  $ED Descri��o da fun��o
*     Insere uma pe�a na lista duplamente encadeada de pe�as.
*
*  $EP Par�metros
*     plista  -   um  tipo de dado PECACAPTURADA_tppLista.
*                     Ver descri��o do m�dulo.
*	  pPeca     -   um ponterio para uma tipo PECA_tppLista
*
*   $EAE Assertivas de entrada
*	 	Existe uma lista duplamente encadeada de pe�as finalizadas do tipo PECACAPTURADA_tppLista
*	 	Existe tambem um tipo de dado PECA_tppPeca.
*
*  $EAS Assertivas de sa�da
*		Ser� inserido o tipo de dado ,fornecido no parametro da fun��o,na lista duplamente encadeada de pe�as finalizadas.
*
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - Inseriu a pe�a sem problema.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*  *******************************************************************/

   PECACAPTURADA_tpCondRet PECACAPTURADA_InserirPecaCapturada(PECACAPTURADA_tppLista pLista,char cor);



   /***************************************************************************
*
*  $FC Fun��o: PECACAPTURADA &Retirar  Peca Capturada
*
*  $ED Descri��o da fun��o
*     Retira uma pe�a da lista duplamente encadeada.
*
*  $EP Par�metros
*     pLista  -   um tipo de dado PECACAPTURADA_tppLista.
*                     Ver descri��o do m�dulo.
*	  pPeca	  -		um ponteiro para tipo de dado PECA_tppLista
*
*   $EAE Assertivas de entrada
*	    Existe uma lista duplamente encadeada de pe�as finalizadas do tipo PECACAPTURADA_tppLista.
*	 	Existe tambem um ponteiro do tipo PECA_tppPeca que aponta para um lugar desconhecido na memoria.
*
*  $EAS Assertivas de sa�da
*		Caso a lista n�o estaja vazia,o ponteiro do tipo PECA_tppPeca apontar� para uma pe�a.
*
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - retirou a pe�a sem problema.
*	  PECACAPTURADA_CondRetPecaVazia -A lista duplamente encadeada de pe�as esta vazia.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*  *******************************************************************/

     PECACAPTURADA_tpCondRet PECACAPTURADA_RetirarPecaCapturada(PECACAPTURADA_tppLista pLista );


/***************************************************************************
*
*  $FC Fun��o: PECACAPTURADA &Quantidade Pe�as Capturadas
*
*  $ED Descri��o da fun��o
*     Retorna a quantidade de pe�as capturadas na lista.
*
*  $EP Par�metros
*     pLista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descri��o do m�dulo.
*	  qtd     -   um ponterio de tipo int,em aponta para um dado que armazenar� a quantidade de elementos na lista
*
*   $EAE Assertivas de entrada
*	 	Existe um dado do tipo PECACAPTURADA_tppLista.
*	 	Existe um ponteiro do tipo int que aponta para algum lugar desconhecido da mem�ria.
*
*  $EAS Assertivas de sa�da
*		O ponteiro qtd apontar� para um dado que armazena a quantidade de elementos da lista.
*
*  $FV Valor retornado
*     PECACAPTURADA_CondRetOK    - Percorreu a lista sem problemas.
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*  *******************************************************************/

	 PECACAPTURADA_tpCondRet PECACAPTURADA_QuantidadePecaCapturada(PECACAPTURADA_tppLista pLista,int *qtd);



#undef PECACAPTURADA_EXT
/********** Fim do m�dulo de defini��o: PECACAPTURADA **********/

#else
#endif