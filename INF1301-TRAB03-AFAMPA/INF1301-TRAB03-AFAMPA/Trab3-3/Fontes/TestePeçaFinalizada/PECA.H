#if ! defined( PECA_ )
#define PECA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: PECA  pe�a
*
*  Arquivo gerado:              PECA.h
*  Letras identificadoras:      PECA
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descri��o do m�dulo
*     Implementa cria�ao do pe�a.
*     Podem existir n pe�as em opera��o simultaneamente.
*
*     Cada pe�a � homog�nea quanto ao tipo dos dados que armazena.
*     Cada pe�a referencia o valor que cont�m.
***************************************************************************/
 
#if defined( PECA_OWN )
   #define PECA_EXT
#else
   #define PECA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct PECA_tagElemPeca * PECA_tppLista ;


/***********************************************************************
*
*  $TC Tipo de dados: PECA Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         PECA_CondRetOK,
               /* Concluiu corretamente */

         PECA_CondRetPecaVazia ,
               /* Nao existe a pe�a  */

         PECA_CondRetFaltouMemoria
               /* Faltou mem�ria ao tentar criar um elemento de lista */

   } PECA_tpCondRet ;

   /***********************************************************************
*
*  $FC Fun��o: PECA &Criar pe�a
*
*  $ED Descri��o da fun��o
*     Cria uma pe�a.
*
*  $EP Par�metros
*     plista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descri��o do m�dulo.
*
*   $EAE Assertivas de entrada
*	 	H� um ponteiro de ponteiro do tipo PECA_tppLista . Este aponta para um lugar desconhecido na memoria.
*	 	H� tambem uma variavel char que armazena a cor desejada da pe�a.
*
*  $EAS Assertivas de sa�da
*	    Caso falte memoria durante a criacao do pe�a, sera retornado uma pe�a com uma determinada cor.
*
*  $FV Valor retornado
*     PECA_CondRetOK    - criou o pe�a sem problema.
*	  PECA_CondRetFaltouMemoria -faltou memoria para cria�ao da pe�a.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

   PECA_tpCondRet PECA_CriarPeca(PECA_tppLista *pLista,char cor);


/***********************************************************************
*
*  $FC Fun��o: PECA  &Destruir pe�a
*
*  $ED Descri��o da fun��o
*     Destr�i o Pe�a.

*  $EP Par�metros
*     plista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descri��o do m�dulo.
*
*  $EAE Assertivas de entrada
*	 	H� um ponteiro do tipo PECA_tppLista . Este aponta para uma pe�a ou NULL.
*	 	
*  $EAS Assertivas de sa�da
*	   Caso exista uma pe�a que o ponterio aponte,essa pe�a ser� liberada.
*
*
*  $FV Valor retornado
*     PECA_CondRetOK    - destroi a pe�a sem problema.
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
***********************************************************************/

   PECA_tpCondRet PECA_DestruirPeca( PECA_tppLista pLista ) ;

/***************************************************************************
*
*  $FC Fun��o: PECA &Obtercor da pe�a
*
*  $ED Descri��o da fun��o
*     Obtem a cor da pe�a.
*
*  $EP Par�metros
*     plista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descri��o do m�dulo.
*	  cor     -   um ponterio para char,em que armazena a cor da pe�a
*
*   $EAE Assertivas de entrada
*	 	H� um ponteiro do tipo PECA_tppLista . Este aponta para uma pe�a ou para NULL.
*	 	H� tambem um ponteiro de caracter que aponta para um endere�o mem�ria que possui um caracter.
*
*  $EAS Assertivas de sa�da
*		Sera armazenada um caracter no endere�o que o ponteiro *cor aponta.
*
*  $FV Valor retornado
*     PECA_CondRetOK    - criou o pe�a sem problema.
*	  PECA_CondRetPecaVazia -Nao existe a pe�a.
*     
*    
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*  *******************************************************************/

   PECA_tpCondRet PECA_ObterCor(PECA_tppLista pLista, char * cor);




#undef PECA_EXT
/********** Fim do m�dulo de defini��o: PECA **********/

#else
#endif