/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTPECA.C
*  Letras identificadoras:      TPECA
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF  1301
*  Gestor:  DI/PUC-Rio
*  Autores: Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto

*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo Pe�a. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo pe�a:
*
*     =criarpeca        - chama a fun��o PECA_CriarPeca( )
*	  =obtercor			- chama a fun��o PECA_ObterCor( )
*	  =destruirpeca     - chama a fun��o PECA_DestruirPeca( )
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "LERPARM.H"
#include    "PECA.H"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_PECA_CMD       "=criarpeca"
#define     OBTER_COR_CMD       "=obtercor"
#define     DESTROI_CMD         "=destruirpeca"



#define DIM_VT_LISTA   10
/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

PECA_tppLista vPeca[DIM_VT_LISTA]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

/***********************************************************************
*
*  $FC Fun��o: TPECA Efetuar opera��es de teste espec�ficas para pe�a
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     pe�a sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/
	
	TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

	  PECA_tpCondRet CondRetObtido   = PECA_CondRetOK ;
      PECA_tpCondRet CondRetEsperada = PECA_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;
	  char Cor='\0';
	  char CorEsperada='\0';
	  
      int  NumLidos = -1 ;

	  int index=-1;

      /* Testar PECA Criar pe�a */

         if ( strcmp( ComandoTeste , CRIAR_PECA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iic" ,&CondRetEsperada,&index ,&CorEsperada) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PECA_CriarPeca(vPeca+index, CorEsperada) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,"Retorno errado ao criar a pe�a." );

         } /* fim ativa: Testar PECA Criar pe�a */

      /* Testar PECA obter a cor da pe�a */
		 
         if ( strcmp( ComandoTeste , OBTER_COR_CMD ) == 0 )
         {
			
            NumLidos = LER_LerParametros( "iic" ,&CondRetEsperada,&index,&CorEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PECA_ObterCor(vPeca[index],&Cor) ;

			if(CondRetEsperada==1)
				 return TST_CompararInt( CondRetEsperada, CondRetObtido ,"Nao deveria existir a pe�a." );

			return TST_CompararChar( CorEsperada , Cor ,"Retorno errado da cor da pe�a." );
	
         }

      /* fim ativa:Testar PECA obter a cor da pe�a */

		 /* Testar PECA Destruir pe�a */

         if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,&CondRetEsperada,&index ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PECA_DestruirPeca(vPeca[index]) ;
			vPeca[index]=NULL;
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,"Retorno errado destruir a pe�a." );

         } /* fim ativa: Testar PECA Destruir pe�a*/

     return TST_CondRetNaoConhec ;
   } /* Fim fun��o: TPECA Efetuar opera��es de teste espec�ficas para Pe�a*/
     
  

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

