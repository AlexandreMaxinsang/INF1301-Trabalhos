/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTDADO.C
*  Letras identificadoras:      TDADO
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto

*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo pe�a. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo pe�a:
*
*     =criarpeca        -chama a fun��o PECA_CriarPeca
*	  =obtercor         -chama a fun�ao PECA_ObterCor
*     =destruirpca		-chama a fun�ao PECA_DestruirPeca

***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "LERPARM.H"
#include    "DADO.H"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     JOGA_DADO_CMD      "=jogadado"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

 
/***********************************************************************
*
*  $FC Fun��o: TARV Efetuar opera��es de teste espec�ficas para pe�a
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

   } /* Fim fun��o: DADO Efetuar opera��es de teste espec�ficas para dado */
     
/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

