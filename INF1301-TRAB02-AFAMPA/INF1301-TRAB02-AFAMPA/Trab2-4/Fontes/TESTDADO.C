/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTDADO.C
*  Letras identificadoras:      TDADO
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto

*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo peça. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo peça:
*
*     =criarpeca        -chama a função PECA_CriarPeca
*	  =obtercor         -chama a funçao PECA_ObterCor
*     =destruirpca		-chama a funçao PECA_DestruirPeca

***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "LERPARM.H"
#include    "DADO.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     JOGA_DADO_CMD      "=jogadado"

/*****  Código das funções exportadas pelo módulo  *****/

 
/***********************************************************************
*
*  $FC Função: TARV Efetuar operações de teste específicas para peça
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

	  DADO_tpCondRet CondRetObtido   = DADO_CondRetOK ;
      DADO_tpCondRet CondRetEsperada;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;

	  int  valor=-1;
      int  NumLidos = -1 ;
	  int  inxTab=-1; 


      /*  Testar DADO Gera valor */

         if ( strcmp( ComandoTeste , JOGA_DADO_CMD ) == 0 )
         {
			 NumLidos = LER_LerParametros( "i" ,&CondRetEsperada ) ;

            if ( ( NumLidos != 1 ))
            {
               return TST_CondRetParm ;
            } /* if */
            
            CondRetObtido = DADO_GeraValor(&valor) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,"Retorno errado ao jogar dado." );

         } /* fim ativa: Testar DADO Gera valor*/
     
		 return TST_CondRetNaoConhec ;

   } /* Fim função: DADO Efetuar operações de teste específicas para dado */
     
/********** Fim do módulo de implementação: Módulo de teste específico **********/

