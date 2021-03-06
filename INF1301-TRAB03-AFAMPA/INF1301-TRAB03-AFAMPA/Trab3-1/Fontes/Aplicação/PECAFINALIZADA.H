#if ! defined( PECAFINALIZADA_ )
#define PECAFINALIZADA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: PECAFINALIZADA  pe�a
*
*  Arquivo gerado:              PECAFINALIZADA.h
*  Letras identificadoras:      PECAFINALIZADA
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descri��o do m�dulo
*     Implementa cria�ao de uma lista duplamente encadeada de pe�as finalizadas.
*     Podem existir n listas  em opera��o simultaneamente.
*
***************************************************************************/
 
#if defined( PECAFINALIZADA_OWN )
   #define PECAFINALIZADA_EXT
#else
   #define PECAFINALIZADA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef  struct LIS_tagLista * PECAFINALIZADA_tppLista ;
typedef struct PECA_tagElemPeca * PECA_tppLista ;
   

/***********************************************************************
*
*  $TC Tipo de dados: PECAFINALIZADA Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         PECAFINALIZADA_CondRetOK,
               /* Concluiu corretamente */

         PECAFINALIZADA_CondRetFaltouMemoria
               /* Faltou mem�ria ao tentar criar um elemento de lista */

   } PECAFINALIZADA_tpCondRet ;

   /***********************************************************************
*
*  $FC Fun��o: PECAFINALIZADA &Criar Cria Peca Finalizada
*  $ED Descri��o da fun��o
*     Cria  lista duplamente encadeada de pe�a finalizadas.
*
*  $EP Par�metros
*     pLista  -    um ponteiro de tipo PECAFINALIZADA_tppLista.
*                     Ver descri��o do m�dulo.
*
*    $EAE Assertivas de entrada
*		Existe um ponteiro do tipo PECAFINALIZADA_tppLista e que aponta para alguma parte desconhecidad da mem�ria.
*    $EAS Assertivas de sa�da 
*	   Caso n�o falte mem�ria,o ponteiro passado passado pelo paramentro apontar� para lista duplamente encadeada de pe�as finalizadas.
*
*  $FV Valor retornado
*     PECAFINALIZADA_CondRetOK    - criou alista duplamente encadeada sem problema.
*     PECAFINALIZADA_CondRetFaltouMemoria	-faltou memoria para criar a lista 
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

 PECAFINALIZADA_tpCondRet PECAFINALIZADA_CriarPecaFinalizada(PECAFINALIZADA_tppLista *pLista);


/***********************************************************************
*
*  $FC Fun��o: PECAFINALIZADA  &Destruir Pe�a
*
*  $ED Descri��o da fun��o
*     Destr�i uma lista duplamente encadeada de pe�as finalizadas

*  $EP Par�metros
*     pLista  -    um dado do tipo PECA_tppLista.
*                     Ver descri��o do m�dulo.
*
*  $EAE Assertivas de entrada
*	 	Existe um dado do tipo PECAFINALIZADA_tppLista.
*	 	
*  $EAS Assertivas de sa�da
*	    Ser� liberado o conteudo apontado pelo ponteiro que foi passado pelo par�metro.
*
*
*  $FV Valor retornado
*     PECAFINALIZADA_CondRetOK    - destroi a lista duplamente encadeada sem problema.
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
***********************************************************************/

   PECAFINALIZADA_tpCondRet PECAFINALIZADA_DestruirPeca( PECAFINALIZADA_tppLista pLista );

/***************************************************************************
*
*  $FC Fun��o: PECAFINALIZADA &Inserir Pe�a Finalizada
*
*  $ED Descri��o da fun��o
*     Inseri uma pe�a finalizada na lista.
*
*  $EP Par�metros
*     pLista  -    um ponteiro de tipo PECAFINALIZADA_tppLista.
*                     Ver descri��o do m�dulo.
*	   pPeca   -   um dado do tipo PECA_tppLista
*
*   $EAE Assertivas de entrada
*	 	Existe um dado do tipo PECAFINALIZADA_tppLista.
*	 	Existe um dado do tipo PECA_tppLista("pe�a").
*
*  $EAS Assertivas de sa�da
*		Insere a pe�a com sucesso na lista.
*
*  $FV Valor retornado
*     PECAFINALIZADA_CondRetOK    - Inseriu a pe�a na lista sem problemas.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*  *******************************************************************/

  PECAFINALIZADA_tpCondRet PECAFINALIZADA_InserirPecaFinalizada( PECAFINALIZADA_tppLista pLista,char cor );


   /***************************************************************************
*
*  $FC Fun��o: PECAFINALIZADA &Esvaziar Pe�a Finalizada
*
*  $ED Descri��o da fun��o
*     Esvazia a lista duplamente encadeada de pe�as finalizadas.
*
*  $EP Par�metros
*     pLista  -    um dado de tipo PECAFINALIZADA_tppLista.
*                     Ver descri��o do m�dulo.
*
*   $EAE Assertivas de entrada
*		Existe um dado do tipo PECAFINALIZADA_tppLista.
*
*  $EAS Assertivas de sa�da
*		Ser� esvaziada a lista corretamente.
*
*  $FV Valor retornado
*     PECA_CondRetOK    - Esvaziou a lista sem problemas.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*  *******************************************************************/

    PECAFINALIZADA_tpCondRet PECAFINALIZADA_EsvaziarPecaFinalizada(PECAFINALIZADA_tppLista pLista);

  /***************************************************************************
*
*  $FC Fun��o: PECAFINALIZADA &Quantidade  Pe�a Finalizadas
*
*  $ED Descri��o da fun��o
*     Retorna a quantidade de pe�as finalizadas na lista.
*
*  $EP Par�metros
*     pLista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descri��o do m�dulo.
*	  qtd     -   um ponterio de tipo int,em aponta para um dado que armazenar� a quantidade de elementos na lista
*
*   $EAE Assertivas de entrada
*	 	Existe um dado do tipo PECAFINALIZADA_tppLista.
*	 	Existe um ponteiro do tipo int que aponta para algum lugar desconhecido da mem�ria.
*
*  $EAS Assertivas de sa�da
*		O ponteiro qtd apontar� para um dado que armazena a quantidade de elementos da lista.
*
*  $FV Valor retornado
*     PECA_CondRetOK    - Percorreu a lista sem problemas.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*  *******************************************************************/
	PECAFINALIZADA_tpCondRet PECAFINALIZADA_QuantidadePecaFinalizada(PECAFINALIZADA_tppLista pLista,int *qtd);


#undef PECAFINALIZADA_EXT
/********** Fim do m�dulo de defini��o: PECAFINALIZADA **********/

#else
#endif