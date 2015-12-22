/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTMAT.C
*  Letras identificadoras:      TMAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Alessandro Faletti, Alexandre Maxinsang, Pedro Augusto
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo matriz. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
***************************************************************************/

#include    <string.h>
#include    <stdlib.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "matriz.h"
#include    "LISTA.H"



#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_LISTA   10
#define DIM_VALOR     100

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_MAT_CMD       "=criar"
#define     IR_PARA_CMD         "=ir"
#define     DESTROI_CMD         "=destruir"
#define     INSERIR_LISTA_CMD   "=inserirlista"

#define		CRIAR_LISTA_CMD     "=criarlista"
#define		INS_ELEM_ANTES_CMD  "=inselemantes"
#define		INS_ELEM_APOS_CMD   "=inselemapos"
#define     OBTER_VALOR_CMD     "=obterlista"
#define		IR_INICIO_CMD		"=iriniciolista"
#define		IR_FIM_CMD			"=irfinallista"
#define		AVANCAR_ELEM_CMD	"=avancarlista"


tpMatriz  * vtMatriz[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
LIS_tppLista pLista=NULL;


/*****  Código das funções exportadas pelo módulo  *****/

 void DestruirValor( char pValor );

/***********************************************************************
*
*  $FC Função: TARV Efetuar operações de teste específicas para matriz
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     matriz sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	  
      MAT_tpCondRet CondRetObtido   = MAT_CondRetOK ;
      MAT_tpCondRet CondRetEsperada = MAT_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */
	  LIS_tpCondRet CondRet, CondRetEsp;
	  
      char pDado     = '\0' ;
	  int  numElem=0;
      int  NumLidos = -1 ;
	  int  linha = 0;
	  int  coluna = 0;
	  int indice = 0;
		
      /* Testar MAT Criar matriz */

         if ( strcmp( ComandoTeste , CRIAR_MAT_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iiii" ,&indice, &linha, &coluna, &CondRetEsperada ) ;
            if ( NumLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_CriarMatriz((vtMatriz+indice),linha, coluna);

            return TST_CompararInt( CondRetEsperada , CondRetObtido , "Retorno errado ao criar matriz." );

         } /* fim ativa: Testar MAT Criar Matriz */

      /* Testar MAT ir para posição */

		 else if ( strcmp( ComandoTeste , IR_PARA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iiii" ,&indice, &linha , &coluna , &CondRetEsperada ) ;
            if ( NumLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = MAT_IrPara((vtMatriz+indice),linha, coluna);

            return TST_CompararInt( CondRetEsperada , CondRetObtido , "Retorno errado ao ir para a posicao.");

         } /* fim ativa: Testar MAT ir para posição */


		 /* Testar MAT destruir matriz com a lista */
         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {
			
			NumLidos = LER_LerParametros( "i" ,&indice) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			LIS_DestruirLista(( LIS_tppLista)EndLista((vtMatriz+indice))) ;
            MAT_DestruirMatriz((vtMatriz+indice)) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar MAT destruir matriz com a lista */

		 /* Testar CriarLista */
		 else if ( strcmp( ComandoTeste , CRIAR_LISTA_CMD ) == 0 )
         {

			NumLidos = LER_LerParametros( "i" , &CondRetEsp) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
			 if(pLista!=NULL)
			 {
				 LIS_DestruirLista(pLista );
			 }

			pLista = LIS_CriarLista(DestruirValor);

            return TST_CompararInt( CondRetEsp , LIS_CondRetOK , "Retorno errado ao criar lista.");

         } /* fim ativa: Testar CriarLista */


		 /* Testar inserir elemento antes */
         else if ( strcmp( ComandoTeste , INS_ELEM_ANTES_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" , &pDado , &CondRetEsp ) ;

            if ( ( NumLidos != 2 ) )
            {
               return TST_CondRetParm ;
            } /* if */


            CondRet = LIS_InserirElementoAntes( pLista , pDado ) ;

            return TST_CompararInt( CondRetEsp , CondRet , "Condicao de retorno errada ao inserir antes." ) ;

         } /* fim ativa: Testar inserir elemento antes */


      /* Testar inserir elemento apos */

         else if ( strcmp( ComandoTeste , INS_ELEM_APOS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" , &pDado , &CondRetEsp ) ;

            if ( ( NumLidos != 2 ) )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet = LIS_InserirElementoApos( pLista , pDado ) ;

            return TST_CompararInt( CondRetEsp , CondRet , "Condicao de retorno errada ao inserir apos."  ) ;

         } /* fim ativa: Testar inserir elemento apos */
		 
		 /* Testar inserir Lista na Matriz */

         else if ( strcmp( ComandoTeste , INSERIR_LISTA_CMD ) == 0 )
         {
            NumLidos = LER_LerParametros( "ii" , &indice , &CondRetEsperada ) ;

            if ( ( NumLidos != 2 ) )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_InserirLista((vtMatriz+indice),pLista);
			pLista=NULL;
            return TST_CompararInt( CondRetEsperada , CondRetObtido , "Condicao de retorno errada inserir lista na matriz."  ) ;

         } /* fim ativa: Testar inserir Lista na matriz */

		 /* Testar obter valor do elemento corrente da lista antes de ser ligado a matriz*/

         else if ( strcmp( ComandoTeste , OBTER_VALOR_CMD ) == 0 )
         {
			char valor;
            NumLidos = LER_LerParametros( "ci" , &pDado , &CondRetEsp ) ;

            if ( ( NumLidos != 2 ) )
            {
               return TST_CondRetParm ;
            } /* if */

			valor = LIS_ObterValor( pLista );
            if ( CondRetEsp == 0 )
            {
               return TST_CompararChar( pDado , ' ' , "Valor não deveria existir." ) ;
            } /* if */

            if ( pDado == ' ' )
            {
               return TST_CompararInt(1  , CondRetEsp , "Dado tipo um deveria existir." ) ;
            } /* if */

            return TST_CompararChar(  valor, pDado , "Valor do elemento errado." ) ;

         } /* fim ativa: Testar obter valor do elemento corrente da lista antes de ser ligado a matriz */
		 
      /* Testar ir para o elemento inicial da lista antes de ser ligada a matriz */

         else if ( strcmp( ComandoTeste , IR_INICIO_CMD ) == 0 )
         {

            IrInicioLista( pLista ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar ir para o elemento inicial */

      /* LIS  &Ir para o elemento final da lista antes de ser ligada a matriz */

         else if ( strcmp( ComandoTeste , IR_FIM_CMD ) == 0 )
		 {
            IrFinalLista(pLista ) ;

            return TST_CondRetOK ;

         } /* fim ativa: LIS  &Ir para o elemento final da lista antes de ser ligada a matriz */

      /* LIS  &Avançar elemento da lista antes de ser ligada a matriz*/

         else if ( strcmp( ComandoTeste , AVANCAR_ELEM_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , &numElem ,&CondRetEsp ) ;

            if ( ( NumLidos != 2 ))
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararInt( CondRetEsp ,LIS_AvancarElementoCorrente(pLista , numElem ),"Condicao de retorno errada ao avancar" ) ;

         } /* fim ativa: LIS  &Avançar elemento da lista antes de ser ligada a matriz */

     
      return TST_CondRetNaoConhec ;

   } /* Fim função: TMAT Efetuar operações de teste específicas para matriz */

/********** Fim do módulo de implementação: Módulo de teste específico **********/


/***********************************************************************
*
*  $FC Função: TLIS -Destruir valor
*
***********************************************************************/

   void DestruirValor( char pValor )
   {

   } /* Fim função: TLIS -Destruir valor */