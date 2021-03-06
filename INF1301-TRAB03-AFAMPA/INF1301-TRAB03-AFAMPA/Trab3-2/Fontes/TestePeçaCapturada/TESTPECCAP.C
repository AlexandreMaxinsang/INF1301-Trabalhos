/***************************************************************************
*  $MCI M�dulo de implementa��o: TPECCAP Teste Tabuleiro do Gam�o
*
*  Arquivo gerado:              TESTPECCAP.C
*  Letras identificadoras:      TPECCAP
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
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
#include    "PECACAPTURADA.h"
#include    "PECA.H"

#define CRIAR_PECACAPTURADA_CMD     "=criarpecacap" 
#define QTD_PECACAPTURADA_CMD		"=qtdpecacap"
#define DESTRUIR_PECACAPTURADA_CMD  "=destruirpecacap"
#define INSERIR_PECACAPTURADA_CMD   "=inserirpecacap"
#define RETIRAR_PECACAPTURADA_CMD   "=retirarpecacap"

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_LISTA   10
#define DIM_VALOR     100

PECACAPTURADA_tppLista  vtPecaCapturada[ DIM_VT_LISTA ] ;
/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static int ValidarInxLista( int inxLista) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o:  TPECCAP &Testar Lista duplamente encadeada de pe�as
*
*  $ED Descri��o da fun��o
*     Podem ser criadas at� 10 listas duplamente encadeadas de pe�as capturadas , identificadas pelos �ndices 0 a 10
*
*     Comandos dispon�veis:
*
*     =criarpecacap		- cria uma lista duplamente encadeada de pe�as 
*     =destruirpecacap  - destroi uma lista duplamente encadeada de pe�as
*     =inserirpecacap   - insere uma pe�a na lista
	  =qtdpecacap		- informa a quantidade de elementos da lista
	  =retirarpecacap   - retira uma pe�a na lista
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	  PECACAPTURADA_tpCondRet CondRetObtido   = PECACAPTURADA_CondRetOK ;
      PECACAPTURADA_tpCondRet CondRetEsperada = PECACAPTURADA_CondRetFaltouMemoria ;

      int inxTab  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1  ;

      int ValEsp = -1 ;
      int numElem = -1 ;


 
      /* Testar PECACAPTURADA_CriarPecaCapturada*/

          if ( strcmp( ComandoTeste , CRIAR_PECACAPTURADA_CMD ) == 0 )
         {
            numLidos = LER_LerParametros( "ii" ,&CondRetEsperada ,&inxTab ) ;

            if ( ( numLidos != 2 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =PECACAPTURADA_CriarPecaCapturada((vtPecaCapturada+inxTab));

            return TST_CompararInt(CondRetEsperada ,CondRetObtido,"Retorno errado ao criar a lista duplamente encadeada de pe�as. " );

         } /* fim ativa: Testar PECACAPTURADA_CriarPecaCapturada */


		   /* Testar PECACAPTURADA_DestruirPeca*/

          else if ( strcmp( ComandoTeste , DESTRUIR_PECACAPTURADA_CMD ) == 0 )
         {
            numLidos = LER_LerParametros( "ii" ,&CondRetEsperada ,&inxTab ) ;

            if ( ( numLidos != 2 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =PECACAPTURADA_DestruirPeca(vtPecaCapturada[inxTab]);

            return TST_CompararInt(CondRetEsperada ,CondRetObtido," ");

         } /* fim ativa: Testar PECACAPTURADA_InserirPecaCapturada */

		    /* Testar PECACAPTURADA_InserirPecaCapturada*/
		    else if ( strcmp( ComandoTeste , INSERIR_PECACAPTURADA_CMD ) == 0 )
         {
			 PECA_tppPeca vtPeca[1]={NULL};
			 char cor='\0';
            numLidos = LER_LerParametros( "iic" ,&CondRetEsperada ,&inxTab,&cor) ;

            if ( ( numLidos != 3 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

			PECA_CriarPeca(vtPeca,'p');
            CondRetObtido =PECACAPTURADA_InserirPecaCapturada(vtPecaCapturada[inxTab],cor);

            return TST_CompararInt(CondRetEsperada ,CondRetObtido,"Retorno errado ao inserir a pe�a na lista " );

         } /* fim ativa: Testar PECACAPTURADA_InserirPecaCapturada */

		     /* Testar PECACAPTURADA_RetirarPecaCapturada*/

		    else if ( strcmp( ComandoTeste , RETIRAR_PECACAPTURADA_CMD ) == 0 )
         {
			 PECA_tppPeca vtPeca[1]={NULL};
            numLidos = LER_LerParametros( "ii" ,&CondRetEsperada ,&inxTab ) ;

            if ( ( numLidos != 2 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =PECACAPTURADA_RetirarPecaCapturada(vtPecaCapturada[inxTab]);

            return TST_CompararInt(CondRetEsperada ,CondRetObtido,"Retorno errado ao retirar a pe�a na lista. " );

         } /* fim ativa: Testar PECACAPTURADA_RetirarPecaCapturada */
		    
			/* Testar PECACAPTURADA_QuantidadePecaCapturada*/
		    else if ( strcmp( ComandoTeste , QTD_PECACAPTURADA_CMD ) == 0 )
         {
			 PECA_tppPeca vtPeca[1]={NULL};
			 int qtdobtido=0,qtdesperado=0;
            numLidos = LER_LerParametros( "iii" ,&CondRetEsperada ,&inxTab,&qtdesperado ) ;

            if ( ( numLidos != 3 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

			
            CondRetObtido =PECACAPTURADA_QuantidadePecaCapturada(vtPecaCapturada[inxTab],&qtdobtido);

            return TST_CompararInt(qtdesperado ,qtdobtido,"Retorno errado da quantidade de elementos de uma lista. " );

         } /* fim ativa: Testar PECACAPTURADA_QuantidadePecaCapturada */
      
      return TST_CondRetNaoConhec ;

   } /* Fim fun��o:  TPECCAP &Testar lista duplamente encadeada de pe�as capturas*/


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o:  TPECCAP -Validar indice da vetor de listas duplamente encadeada de pe�as capturadas
*
***********************************************************************/

   int ValidarInxLista( int inxLista)
   {

      if ( ( inxLista <  0 )|| ( inxLista >= DIM_VT_LISTA ))
      {
         return FALSE ;
      } /* if */
      return TRUE ;

   } /* Fim fun��o:  TPECCAP -Validar indice da vetor de listas duplamente encadeada de pe�as capturadas */

/********** Fim do m�dulo de implementa��o: TPECCAP Teste  lista duplamente encadeada de pe�as capturas de s�mbolos **********/

