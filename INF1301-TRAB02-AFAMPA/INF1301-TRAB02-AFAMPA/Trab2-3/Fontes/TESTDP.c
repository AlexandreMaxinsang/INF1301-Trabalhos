/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTDP.C
*  Letras identificadoras:      TPONTO
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo dadopontos. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo dadopontos:
*
* =criarponto		- chama a função DP_Cria
* =obterponto		- chama a função DP_ObterPonto
* =destruirpontuacao		- chama a função DP_DestruirPonto
* =dobrarponto		- chama a função DP_Dobra
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "LERPARM.H"
#include    "DADOPONTOS.H"


#define		DIM_V_PONTO  1
#define		FALSE   0
#define		TRUE  1
/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_PONTO_CMD      "=criarponto"
#define     OBTER_PONTO_CMD      "=obterponto"
#define     DESTROI_CMD          "=destruirpontuacao"
#define     DOBRAR_PONTO_CMD     "=dobrarponto"


DP_tppDadoPontos vDADOP[DIM_V_PONTO];

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPONTO Efetuar operações de teste específicas para peça
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

	  DP_tpCondRet CondRetObtido   = DP_CondRetOK ;
      DP_tpCondRet CondRetEsperada = DP_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;
	  int  Ponto= -1;
	  int  PontoEsp= 0;
	  int  Jogador= 0;
      int  NumLidos = -1 ;

	  int Indice = -1;

      /* Testar PONTO Criar pontuacao */

         if ( strcmp( ComandoTeste , CRIAR_PONTO_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,&CondRetEsperada) ;
            if ( NumLidos != 1  )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DP_Cria(vDADOP);

            return TST_CompararInt(CondRetEsperada ,CondRetObtido, "Retorno errado ao criar a pontuacao. " );

         } /* fim ativa: Testar PONTO Criar pontuacao */


      /* Testar PONTO obter a pontuacao do jogo */
		 else if ( strcmp( ComandoTeste , OBTER_PONTO_CMD ) == 0 )
         {

			 NumLidos = LER_LerParametros( "ii" , &CondRetEsperada, &PontoEsp);
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */
			
            CondRetObtido = DP_ObterPonto(*vDADOP, &Ponto);

			if( Ponto == PontoEsp )
			{
				return TST_CondRetOK;
			}
			
            return TST_CompararInt( CondRetEsperada,  CondRetObtido, " Retorno do ponto de jogo diferente do esperado. " );

         } /* fim ativa: Testar PONTO obter a pontuacao do jogo */


      /* Testar PONTO destruir a estrutura de pontuacao */
		   else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {
			DP_DestruirPonto(*vDADOP) ;
			*vDADOP=NULL;
            return TST_CondRetOK ;
         } /* fim ativa: Testar PONTO destruir a estrutura de pontuacao */


	 /* Testar PONTO dobrar pontuacao do jogo */
		 else if ( strcmp( ComandoTeste , DOBRAR_PONTO_CMD ) == 0 )
         {

			 NumLidos = LER_LerParametros( "ii" , &Jogador, &CondRetEsperada) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */
			
            CondRetObtido = DP_Dobra(*vDADOP, Jogador);
			
            return TST_CompararInt( CondRetEsperada,  CondRetObtido, " Condicao de retorno diferente do esperado. " );

         } /* fim ativa: Testar PONTO dobrar pontuacao do jogo */


     return TST_CondRetNaoConhec ;
   } /* Fim função: TPONTO Efetuar operações de teste específicas para módulo DADOPONTOS */


/********** Fim do módulo de implementação: Módulo de teste específico **********/

