#if ! defined( DADO_ )
#define DADO_
/***************************************************************************
*
*  $MCD Módulo de definição: DADO  DADO
*
*  Arquivo gerado:              DADO.h
*  Letras identificadoras:      DADO
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores:  AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descrição do módulo
*     Esse módulo retorna um valor aleatório entre 1 e 6.
*
***************************************************************************/
 
#if defined( DADO_OWN )
   #define DADO_EXT
#else
   #define DADO_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/***********************************************************************
*
*  $TC Tipo de dados: DADO Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista
*
***********************************************************************/

   typedef enum {

         DADO_CondRetOK 
               /* Concluiu corretamente */

   } DADO_tpCondRet ;

   /***********************************************************************
*
*  $FC Função: DADO &Gera valor
*
*  $ED Descrição da função
*    Retorna um valor 
*
*  $EP Parâmetros
*     valor  -    um ponteiro para um inteiro

*  $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo int . Este aponta para um lugar desconhecido na memoria,
		tal lugar posteriomente sera ocupado por um valor inteiro de 1 a 6
*	 	
*  $EAS Assertivas de saída
*	     Sera armazenado um valor inteiro de 1 a 6 na memoria que o ponteiro *valor referencia.
*                     
*  $FV Valor retornado
*     PECA_CondRetOK    - retornou o valor sem problema
*     
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

    DADO_tpCondRet DADO_GeraValor(int *valor);




#undef DADO_EXT
/********** Fim do módulo de definição: DADO  DADO.H **********/

#else
#endif