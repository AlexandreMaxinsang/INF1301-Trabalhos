#if ! defined( DADO_ )
#define DADO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: DADO  DADO
*
*  Arquivo gerado:              DADO.h
*  Letras identificadoras:      DADO
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores:  AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descri��o do m�dulo
*     Esse m�dulo retorna um valor aleat�rio entre 1 e 6.
*
***************************************************************************/
 
#if defined( DADO_OWN )
   #define DADO_EXT
#else
   #define DADO_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/***********************************************************************
*
*  $TC Tipo de dados: DADO Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         DADO_CondRetOK 
               /* Concluiu corretamente */

   } DADO_tpCondRet ;

   /***********************************************************************
*
*  $FC Fun��o: DADO &Gera valor
*
*  $ED Descri��o da fun��o
*    Retorna um valor 
*
*  $EP Par�metros
*     valor  -    um ponteiro para um inteiro

*  $EAE Assertivas de entrada
*	 	H� um ponteiro do tipo int . Este aponta para um lugar desconhecido na memoria,
		tal lugar posteriomente sera ocupado por um valor inteiro de 1 a 6
*	 	
*  $EAS Assertivas de sa�da
*	     Sera armazenado um valor inteiro de 1 a 6 na memoria que o ponteiro *valor referencia.
*                     
*  $FV Valor retornado
*     PECA_CondRetOK    - retornou o valor sem problema
*     
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

    DADO_tpCondRet DADO_GeraValor(int *valor);




#undef DADO_EXT
/********** Fim do m�dulo de defini��o: DADO  DADO.H **********/

#else
#endif