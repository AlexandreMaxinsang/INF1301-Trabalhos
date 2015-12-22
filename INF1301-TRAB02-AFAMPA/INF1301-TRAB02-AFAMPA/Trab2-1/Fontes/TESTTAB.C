/***************************************************************************
*  $MCI Módulo de implementação: TTAB Teste Tabuleiro do Gamão
*
*  Arquivo gerado:              TestTAB.c
*  Letras identificadoras:      TTAB
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
#include    "TABULEIRO.h"
#include    "PECA.H"
#include    "Lista.H"

#define CRIAR_TAB_CMD   "=criartab" 
#define RESET_TAB_CMD   "=reset"
#define DESTRUIR_TAB_CMD  "=destruirtab"
#define	MOVER_TAB_CMD	"=moverpeca"

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_LISTA   10
#define DIM_VALOR     100

LIS_tppLista  vtTabuleiro[ DIM_VT_LISTA ] ;
PECA_tppLista p;
/***** Protótipos das funções encapuladas no módulo *****/

   static int ValidarInxLista( int inxLista) ;

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TTAB &Testar Tabuleiro
*
*  $ED Descrição da função
*     Podem ser criadas até 10 tabuleiros, identificadas pelos índices 0 a 10
*
*     Comandos disponíveis:
*
*     =reset - anula o vetor de tabuleiro. Provoca vazamento de memória
*     =criartab		- cria um tabuleiro
*     =destruirtab   - destroi um tabuleiro
*     =moverpeca   - move uma peca de uma posicao para outra
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	  TAB_tpCondRet CondRetObtido   = TAB_CondRetOK ;
      TAB_tpCondRet CondRetEsperada = TAB_CondRetFaltouMemoria ;

      int inxTab  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1  ;

      int ValEsp = -1 ;
      int i ;
      int numElem = -1 ;


      /* Efetuar reset de teste de tabuleiro */

         if ( strcmp( ComandoTeste , RESET_TAB_CMD ) == 0 )
         {

            for( i = 0 ; i < DIM_VT_LISTA ; i++ )
            {
               vtTabuleiro[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de tabuleiro */

      /* Testar TAB_CriarTabuleiro*/

         else if ( strcmp( ComandoTeste , CRIAR_TAB_CMD ) == 0 )
         {
            numLidos = LER_LerParametros( "ii" ,&CondRetEsperada ,&inxTab ) ;

            if ( ( numLidos != 2 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =TAB_CriarTabuleiro((vtTabuleiro+inxTab),'b','p');

            return TST_CompararInt(CondRetEsperada ,CondRetObtido,"Retorno errado ao criar o tabuleiro. " );

         } /* fim ativa: Testar TAB_CriarTabuleiro */


		 /* Testar TAB_MoverPeca*/

         else if ( strcmp( ComandoTeste , MOVER_TAB_CMD ) == 0 )
         {
			int pos1=0, qtd=0;
            numLidos = LER_LerParametros( "iiii" ,&CondRetEsperada ,&inxTab, &pos1, &qtd ) ;

            if ( ( numLidos != 4 )|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = TAB_MoverPeca( vtTabuleiro[inxTab], pos1-1, qtd );

            return TST_CompararInt(CondRetEsperada ,CondRetObtido, "Retorno errado ao mover a peca no tabuleiro. " );

         } /* fim ativa: Testar TAB_MoverPeca */

		 /* Testar TAB_DestruirTabuleiro */

         else if ( strcmp( ComandoTeste , DESTRUIR_TAB_CMD ) == 0 )
         {
			 numLidos = LER_LerParametros( "i" ,&inxTab ) ;

            if ( ( numLidos != 1)|| ( ! ValidarInxLista( inxTab)))
            {
               return TST_CondRetParm ;
            } /* if */
       

			TAB_DestruirTabuleiro(vtTabuleiro[inxTab]);

            return TST_CondRetOK;

         } /* fim ativa: Testar TAB_DestruirTabuleiro */


      return TST_CondRetNaoConhec ;

   } /* Fim função: TLIS &Testar lista */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TTAB -Validar indice de tabuleiro
*
***********************************************************************/

   int ValidarInxLista( int inxLista)
   {

      if ( ( inxLista <  0 )|| ( inxLista >= DIM_VT_LISTA ))
      {
         return FALSE ;
      } /* if */
      return TRUE ;

   } /* Fim função: TTAB -Validar indice de tabuleiro */

/********** Fim do módulo de implementação: TTAB Teste Tabuleiro de símbolos **********/

