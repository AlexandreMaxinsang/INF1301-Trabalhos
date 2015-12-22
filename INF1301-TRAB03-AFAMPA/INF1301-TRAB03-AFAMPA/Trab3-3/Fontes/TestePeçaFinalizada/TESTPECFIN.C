/***************************************************************************
*  $MCI Módulo de implementação: TPECAFINALIZADA Teste Tabuleiro do Gamão
*
*  Arquivo gerado:              TESTPECFIN.c
*  Letras identificadoras:      TPECAFINALIZADA
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"
#include    "Generico.h"
#include    "LerParm.h"
#include    "PECA.H"
#include    "PECAFINALIZADA.H"

#define CRIAR_PECAFINALIZADA_CMD     "=criarpecafin" 
#define DESTRUIR_PECAFINALIZADA_CMD  "=destruirpecafin"
#define INSERIR_PECAFINALIZADA_CMD   "=inserirpecafin"
#define ESVAZIAR_PECAFINALIZADA_CMD   "=esvaziarpecafin"
#define QUANTIDADE_PECAFINALIZADA_CMD "=quantidadepecafin"

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_LISTA   10
#define DIM_VALOR     100

 PECAFINALIZADA_tppLista  vtPecaFinalizadas[ DIM_VT_LISTA ] ;
/***** Protótipos das funções encapuladas no módulo *****/

   static int ValidarInxLista( int inxLista) ;

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPECACAPTURADA &Testar Lista duplamente encadeada de peças finalizadas
*
*  $ED Descrição da função
*     Podem ser criadas até 10 listas duplamente encadeadas de peças , identificadas pelos índices 0 a 10
*
*     Comandos disponíveis:
*
*     =criarpecafin		- cria uma lista duplamente encadeada de peças de finalizadas
*     =destruirpecafin  - destroi uma lista duplamente encadeada de peças de finalizadas
*     =inserirpecafin   - insere uma peça na lista de peças finalizadas
	  =esvaziarpecafin   - esvazia  na lista de peças finalizadas
*	  =quantidadepecafin - informa a quantidade de elementos da lista de pecas finalizadas
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	  PECAFINALIZADA_tpCondRet CondRetObtido   = PECAFINALIZADA_CondRetOK ;
      PECAFINALIZADA_tpCondRet CondRetEsperada = PECAFINALIZADA_CondRetFaltouMemoria ;

      int inxTab  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1  ;

      int ValEsp = -1 ;
      int numElem = -1 ;


 
      /* Testar PECAFINALIZADA_CriarPecaFinalizada*/

          if ( strcmp( ComandoTeste , CRIAR_PECAFINALIZADA_CMD ) == 0 )
         {
            numLidos = LER_LerParametros( "ii" ,&CondRetEsperada ,&inxTab ) ;

            if ( ( numLidos != 2 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =PECAFINALIZADA_CriarPecaFinalizada((vtPecaFinalizadas+inxTab));

            return TST_CompararInt(CondRetEsperada ,CondRetObtido,"Retorno errado ao criar a lista duplamente encadeada de peças finalziadas. " );

         } /* fim ativa: Testar PECAFINALIZADA_CriarPecaFinalizada */


		   /* Testar PECAFINALIZADA_DestruirPeca*/

          else if ( strcmp( ComandoTeste , DESTRUIR_PECAFINALIZADA_CMD ) == 0 )
         {
            numLidos = LER_LerParametros( "ii" ,&CondRetEsperada ,&inxTab ) ;

            if ( ( numLidos != 2 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =PECAFINALIZADA_DestruirPeca(vtPecaFinalizadas[inxTab]);

            return TST_CompararInt(CondRetEsperada ,CondRetObtido," ");

         } /* fim ativa: Testar PECAFINALIZADA_InserirPecaFinalizada */

		    /* Testar PECAFINALIZADA_InserirPecaFinalizada*/
		    else if ( strcmp( ComandoTeste , INSERIR_PECAFINALIZADA_CMD ) == 0 )
         {
			 PECA_tppLista vtPeca[1]={NULL};
			 char cor='\0';
            numLidos = LER_LerParametros( "iic" ,&CondRetEsperada ,&inxTab,&cor) ;

            if ( ( numLidos != 3 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

			PECA_CriarPeca(vtPeca,'p');
            CondRetObtido =PECAFINALIZADA_InserirPecaFinalizada(vtPecaFinalizadas[inxTab],cor);

            return TST_CompararInt(CondRetEsperada ,CondRetObtido,"Retorno errado ao inserir a peça finzalizada na lista " );

         } /* fim ativa: Testar PECAFINALIZADA_InserirPecaFinalizada */

		     /* Testar PECAFINALIZADA_EsvaziarPecaFinalizada*/

		    else if ( strcmp( ComandoTeste , ESVAZIAR_PECAFINALIZADA_CMD ) == 0 )
         {
			
            numLidos = LER_LerParametros( "ii" ,&CondRetEsperada ,&inxTab ) ;

            if ( ( numLidos != 2 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

			
            CondRetObtido =PECAFINALIZADA_EsvaziarPecaFinalizada(vtPecaFinalizadas[inxTab]);

            return TST_CompararInt(CondRetEsperada ,CondRetObtido,"Retorno errado ao esvaziar a peça na lista. " );

         } /* fim ativa: Testar PECAFINALIZADA_EsvaziarPecaFinalizada */

			/* Testar PECAFINALIZADA_QuantidadePecaFinalizada*/
			
			 else if ( strcmp( ComandoTeste , QUANTIDADE_PECAFINALIZADA_CMD ) == 0 )
         {
			int qtdesperado,qtdobtido;
            numLidos = LER_LerParametros( "iii" ,&CondRetEsperada ,&inxTab,&qtdesperado) ;

            if ( ( numLidos != 3 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */
			
            CondRetObtido =PECAFINALIZADA_QuantidadePecaFinalizada(vtPecaFinalizadas[inxTab],&qtdobtido);

            return TST_CompararInt(qtdesperado ,qtdobtido,"Retorno errado da quantidade de elementos na lista");

         } /* fim ativa: Testar PECAFINALIZADA_QuantidadePecaFinalizada */
      
      return TST_CondRetNaoConhec ;

   } /* Fim função: TLIS &Testar lista duplamente encadeada de peças finalizadas*/


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TPECAFINALIZADA -Validar indice da vetor de listas duplamente encadeada de peças finalizadas
*
***********************************************************************/

   int ValidarInxLista( int inxLista)
   {

      if ( ( inxLista <  0 )|| ( inxLista >= DIM_VT_LISTA ))
      {
         return FALSE ;
      } /* if */
      return TRUE ;

   } /* Fim função: TPECAFINALIZADA -Validar indice da vetor de listas duplamente encadeada de peças finalizadas */

/********** Fim do módulo de implementação: TPECAFINALIZADAS Teste  lista duplamente encadeada de peças finalizadas de símbolos **********/

