/***************************************************************************
*  $MCI Módulo de implementação: TAB  TABULEIRO
*
*  Arquivo gerado:              TABULEIRO.c
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
* 
*  Projeto: INF 1301  Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#define NUM 24
#define LISTA_OWN
#define TABULEIRO_OWN
#define PECA_OWN
#include "LISTA.H"
#include "PECA.H"
#include "TABULEIRO.H"
#undef PECA_OWN
#undef TABULEIRO_OWN
#undef LISTA_OWN

void TAB_DestruirValor ( void* pValor );
void PECA_DestruirValor( void * pValor );

/***************************************************************************
*
*  Função: TAB  &Criar tabuleiro
*
***************************************************************************/

   TAB_tpCondRet  TAB_CriarTabuleiro(TAB_tppLista* pLista)
   {
	   int i ;

	   TAB_tppLista Novo=NULL;  //ponteiro para a cabeça da lista de tabuleiro
	   TAB_tppLista pLPeca=NULL;//ponteiro para a cabeça da lista de peças

	   Novo = LIS_CriarLista(TAB_DestruirValor) ;
	   if(Novo==NULL)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }
	   
	   for(i=0;i<NUM;i++)
		{  
			pLPeca=(TAB_tppLista )LIS_CriarLista(PECA_DestruirValor) ;
			LIS_InserirElementoApos(Novo,pLPeca) ;
	    }
			
		pLista[0]=Novo;

		return TAB_CondRetOK ;
   } /* Fim função: TAB  &Criar tabuleiro */

/***************************************************************************
*
*  Função: TAB  &Inserir Peca
*
***************************************************************************/
   TAB_tpCondRet  TAB_InserirPeca(TAB_tppLista pLista,char cor_jogador,int qtdpeca)
   {
	   int i=0;
	   TAB_tppLista pLPeca=NULL;
	   PECA_tppPeca pPec[1]={NULL};

	   pLPeca=(TAB_tppLista)LIS_ObterValor(pLista);
	   for(i=0;i< qtdpeca;i++)
		{
			 PECA_CriarPeca(pPec,cor_jogador);
			 LIS_InserirElementoApos(pLPeca,*pPec);
			 pPec[0]=NULL;
	   }

	  return TAB_CondRetOK;
   }/* Fim função: TAB  &Inserir Peca*/
 /***************************************************************************
*
*  Função: TAB  &Ir inicio tabuleiro
*
***************************************************************************/


   TAB_tpCondRet TAB_IrInicioTabuleiro(TAB_tppLista pLista)
	{
		
		IrInicioLista(pLista) ;

		return TAB_CondRetOK;

	}/* Fim função: TAB  &Ir Inicio Tabuleiro */

/***************************************************************************
*
*  Função: TAB  &Avançar elemento corrente do tabuleiro
*
***************************************************************************/


   TAB_tpCondRet TAB_AvancarElementoCorrente(TAB_tppLista pLista,int numElem )
	{
		TAB_tpCondRet Cond;
		Cond=(TAB_tpCondRet)LIS_AvancarElementoCorrente(pLista , numElem ) ;
		if(Cond==LIS_CondRetFimLista)
			return TAB_CondRetFimTab;
		else
			if(Cond==LIS_CondRetListaVazia)
				return TAB_CondRetListaVazia;

		return TAB_CondRetOK;

	}/* Fim função: TAB  &Avançar elemento corrente do tabuleiro */

 /***************************************************************************
*
*  Função: TAB  &Obter Cor No 
*
***************************************************************************/


   TAB_tpCondRet TAB_ObterCorNo(TAB_tppLista pLista,char *cor )
	{
		LIS_tppLista pLPeca=NULL;
		int qtd;

		pLPeca=(TAB_tppLista)LIS_ObterValor(pLista);
		QtdElemento(pLPeca,&qtd);
		if(qtd!=0)
			PECA_ObterCor((PECA_tppPeca)LIS_ObterValor(pLPeca),cor);
		else
			*cor='\0';
		
		return TAB_CondRetOK;
	}/* Fim função: TAB  &Obter Cor No  */
  /***************************************************************************
*
*  Função: TAB  &Destruir tabuleiro
*
***************************************************************************/


   TAB_tpCondRet TAB_ExcluirElemTabuleiro(TAB_tppLista pLista)
	{
		TAB_tpCondRet Cond;
		TAB_tppLista pLPeca=NULL;
		pLPeca=(TAB_tppLista)LIS_ObterValor(pLista);
		Cond=(TAB_tpCondRet)LIS_ExcluirElemento(pLPeca);

		if(Cond==LIS_CondRetListaVazia)
			return TAB_CondRetListaVazia;

		return TAB_CondRetOK;

	}/* Fim função: TAB  &Destruir tabuleiro */



   
/***************************************************************************
*
*  Função: TAB  &Destruir tabuleiro
*
***************************************************************************/


   void TAB_DestruirTabuleiro(LIS_tppLista pLista)
	{


		LIS_DestruirLista( pLista );


	}/* Fim função: TAB  &Destruir tabuleiro */


/***************************************************************************
*
*  Função: TAB  &Imprimir tabuleiro
*
***************************************************************************/


    TAB_tpCondRet TAB_Imprime(TAB_tppLista pLista)
	{
		int i=0;
		TAB_tppLista pLPeca=NULL;
		PECA_tppPeca pPec[1]={NULL};
		char cor;

		if (pLista==NULL)
		{
			return TAB_CondRetListaVazia;
		}
		
		printf("\n\n/////////////////////////////////////\n");
		IrInicioLista(pLista);
		for(i=0;i<24;i++)
		{
			if(i+1<10)
			{
				printf("%d-  ", i+1);
			}
			else
			{
				printf("%d- ", i+1);
			}
			pLPeca = (LIS_tppLista)LIS_ObterValor(pLista);
			IrInicioLista(pLPeca);
			do
			{
				pPec[0] = (PECA_tppPeca)LIS_ObterValor(pLPeca);
				PECA_ObterCor(pPec[0],&cor);

				if(cor=='b') printf("%c", 2);
				
				if(cor=='p') printf("%c", 1);

			}
			while(LIS_AvancarElementoCorrente(pLPeca,1)<1);
			cor='\0';
			printf("\n");
			LIS_AvancarElementoCorrente(pLista,1);
			if(i+1==6 || i+1==12 || i+1==18)
			{
				printf("--------------------\n");
			}
		}

		printf("/////////////////////////////////////\n\n");
		return TAB_CondRetOK;

	}/* Fim função: TAB  &Imprime Tabuleiro  */



/**************************************************************************
*
*	Função:	TAB DestruirValor
*
*
**************************************************************************/
void TAB_DestruirValor ( void* pValor )
{

	LIS_DestruirLista((TAB_tppLista)pValor );
}
void PECA_DestruirValor( void * pValor )
 {

      PECA_DestruirPeca((PECA_tppPeca)pValor) ;

 } /* Fim função: TLIS -Destruir valor */

