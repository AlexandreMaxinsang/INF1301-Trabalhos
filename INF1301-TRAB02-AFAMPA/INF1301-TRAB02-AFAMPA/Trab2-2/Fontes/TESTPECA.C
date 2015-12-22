/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTPECA.C
*  Letras identificadoras:      TPECA
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF  1301
*  Gestor:  DI/PUC-Rio
*  Autores: Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto

*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo Peça. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo peça:
*
*     =criarpeca        - chama a função PECA_CriarPeca( )
*	  =obtercor			- chama a função PECA_ObterCor( )
*	  =destruirpeca     - chama a função PECA_DestruirPeca( )
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "LERPARM.H"
#include    "PECA.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_PECA_CMD       "=criarpeca"
#define     OBTER_COR_CMD       "=obtercor"
#define     DESTROI_CMD         "=destruirpeca"



#define DIM_VT_LISTA   10
/*****  Código das funções exportadas pelo módulo  *****/

PECA_tppLista vPeca[DIM_VT_LISTA]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

/***********************************************************************
*
*  $FC Função: TPECA Efetuar operações de teste específicas para peça
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     peça sendo testado.
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

      /* Testar PECA Criar peça */

         if ( strcmp( ComandoTeste , CRIAR_PECA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iic" ,&CondRetEsperada,&index ,&CorEsperada) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PECA_CriarPeca(vPeca+index, CorEsperada) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,"Retorno errado ao criar a peça." );

         } /* fim ativa: Testar PECA Criar peça */

      /* Testar PECA obter a cor da peça */
		 
         if ( strcmp( ComandoTeste , OBTER_COR_CMD ) == 0 )
         {
			
            NumLidos = LER_LerParametros( "iic" ,&CondRetEsperada,&index,&CorEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PECA_ObterCor(vPeca[index],&Cor) ;

			if(CondRetEsperada==1)
				 return TST_CompararInt( CondRetEsperada, CondRetObtido ,"Nao deveria existir a peça." );

			return TST_CompararChar( CorEsperada , Cor ,"Retorno errado da cor da peça." );
	
         }

      /* fim ativa:Testar PECA obter a cor da peça */

		 /* Testar PECA Destruir peça */

         if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,&CondRetEsperada,&index ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PECA_DestruirPeca(vPeca[index]) ;
			vPeca[index]=NULL;
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,"Retorno errado destruir a peça." );

         } /* fim ativa: Testar PECA Destruir peça*/

     return TST_CondRetNaoConhec ;
   } /* Fim função: TPECA Efetuar operações de teste específicas para Peça*/
     
  

/********** Fim do módulo de implementação: Módulo de teste específico **********/

