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
*  Autores: AFAMPA
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

PECA_tppLista pPec[1]={NULL};

/***************************************************************************
*
*  Função: TAB  &Criar tabuleiro
*
***************************************************************************/

   TAB_tpCondRet  TAB_CriarTabuleiro(LIS_tppLista* pLista,char cor1,char cor2)
   {
	   int i ;
	   int Cond;
	   LIS_tpCondRet lis_CondRet;

	   LIS_tppLista Novo=NULL;  //ponteiro para a cabeça da lista de tabuleiro
	   LIS_tppLista pLPeca=NULL;//ponteiro para a cabeça da lista de peças

	   Novo = LIS_CriarLista(TAB_DestruirValor) ;
	   if(Novo==NULL)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }
	   
	   for(i=0;i<NUM;i++)
		{  
			pLPeca=(LIS_tppLista )LIS_CriarLista(PECA_DestruirPeca) ;
			lis_CondRet=LIS_InserirElementoApos(Novo,pLPeca) ;
	    }
			 

		
	   //Adiconar 2 peças pretas na casa 0 do tabuleiro
	    IrInicioLista(Novo);
		pLPeca=(LIS_tppLista )LIS_ObterValor(Novo);
		for(i=0;i<2;i++)
		{  
			Cond=PECA_CriarPeca(pPec,cor1);
			lis_CondRet=LIS_InserirElementoApos(pLPeca,*pPec);
			pPec[0]=NULL;
	    }
		
		//Adiconar 5 peças brancas na casa 5 do tabuleiro
		 LIS_AvancarElementoCorrente(Novo,5);
		 pLPeca=(LIS_tppLista)LIS_ObterValor(Novo);
		 
		for(i=0;i<5;i++)
		{  
			Cond=PECA_CriarPeca(pPec,cor2);
			lis_CondRet=LIS_InserirElementoApos( pLPeca,*pPec );
			pPec[0]=NULL;
	    }
			
	   
		//Adiconar 3 peças pretas na casa 7 do tabuleiro
		 LIS_AvancarElementoCorrente( Novo,2);
		 pLPeca=(LIS_tppLista)LIS_ObterValor(Novo);
		for(i=0;i<3;i++)
		{  
			Cond=PECA_CriarPeca(pPec,cor2);
			lis_CondRet=LIS_InserirElementoApos( pLPeca,*pPec );
			pPec[0]=NULL;
	    }
		//Adiconar 5 peças brancas na casa 11 do tabuleiro
		 LIS_AvancarElementoCorrente( Novo,4);
		 pLPeca=(LIS_tppLista)LIS_ObterValor(Novo);
		for(i=0;i<5;i++)
		{  
			Cond=PECA_CriarPeca(pPec,cor1);
			lis_CondRet=LIS_InserirElementoApos( pLPeca,*pPec );
			pPec[0]=NULL;
	    }
		 //Adiconar 2 peças pretas na casa 12 do tabuleiro
	    LIS_AvancarElementoCorrente( Novo,1);
		pLPeca=(LIS_tppLista)LIS_ObterValor(Novo);
		for(i=0;i<5;i++)
		{  
			Cond=PECA_CriarPeca(pPec,cor1);
			lis_CondRet=LIS_InserirElementoApos( pLPeca,*pPec);
			pPec[0]=NULL;
	    }
		
		//Adiconar 5 peças brancas na casa 16 do tabuleiro
		 LIS_AvancarElementoCorrente(Novo,4);
		 pLPeca=(LIS_tppLista)LIS_ObterValor(Novo);
		for(i=0;i<3;i++)
		{  
			Cond=PECA_CriarPeca(pPec,cor1);
			lis_CondRet=LIS_InserirElementoApos( pLPeca,*pPec);
			pPec[0]=NULL;
	    }
			
	    
		//Adiconar 3 peças pretas na casa 18 do tabuleiro
		 LIS_AvancarElementoCorrente( Novo,2);
		 pLPeca=(LIS_tppLista)LIS_ObterValor(Novo);
		for(i=0;i<5;i++)
		{  
			Cond=PECA_CriarPeca(pPec,cor1);
			lis_CondRet=LIS_InserirElementoApos( pLPeca,*pPec);
			pPec[0]=NULL;
			
	    }
		//Adiconar 5 peças brancas na casa 23 do tabuleiro
		 LIS_AvancarElementoCorrente( Novo,5);
		 pLPeca=(LIS_tppLista)LIS_ObterValor(Novo);
		for(i=0;i<2;i++)
		{  
			Cond=PECA_CriarPeca(pPec,cor2);
			lis_CondRet=LIS_InserirElementoApos( pLPeca,*pPec );
			pPec[0]=NULL;
	    }

		pLista[0]=Novo;

		return TAB_CondRetOK ;
   } /* Fim função: TAB  &Criar tabuleiro */





/***************************************************************************
*
*  Função: TAB  &Mover peca
*
***************************************************************************/

   TAB_tpCondRet TAB_MoverPeca(LIS_tppLista pLista, int pospeca, int qtd)
   {
	   //Move pPeca1 para posicao de Ppeca2

	   LIS_tppLista pLPeca1=NULL;
	   LIS_tppLista pLPeca2=NULL;

	   PECA_tppLista pPec1[1]={NULL};
	   PECA_tppLista pPec2[1]={NULL};
	   PECA_tppLista NEW[1]={NULL};
	   char cor1='\0', cor2='\0';
	   int pos=0;

	   pos=pospeca+qtd;
	   
	   if(pos==pospeca)
	   {
		   return TAB_CondRetMesmaCasa;
	   }

	   if( pospeca<0 || pospeca>23 || pos<0 || pos>23 || qtd<=0 || qtd>23 )
	   {
		   return TAB_CondRetForaTabuleiro;
	   }


	   IrInicioLista(pLista);
	   LIS_AvancarElementoCorrente(pLista,pospeca);
	   pLPeca1 = (LIS_tppLista)LIS_ObterValor(pLista); //pLPeca1 aponta para a lista da e posicao do elemento da peca a ser movida

	   IrInicioLista(pLista);
	   LIS_AvancarElementoCorrente(pLista,pos);
	   pLPeca2 = (LIS_tppLista)LIS_ObterValor(pLista); //pLPeca2 aponta para a posicao que se deseja mover pPec1

	   pPec1[0] = (PECA_tppLista)LIS_ObterValor(pLPeca1); //pPec1[0] aponta para a peca a ser movida
	   pPec2[0] = (PECA_tppLista)LIS_ObterValor(pLPeca2); //pPec2[0] aponta para a peca que está na posicao que se deseja mover pPec1

	   
	   if(LIS_AvancarElementoCorrente(pLPeca1,0)==1) //ConRetListaVazia => 1
	   {
		   return TAB_CondRetNaoTemPeca;
	   }

	   PECA_ObterCor(pPec1[0],&cor1);
	   PECA_ObterCor(pPec2[0],&cor2);

	   if( cor1 == cor2 || LIS_ObterValor(pLPeca2)==NULL ) //Cores iguais ou casa vazia
	   {
		   PECA_CriarPeca(NEW,cor1);
		   LIS_InserirElementoApos( pLPeca2, NEW[0] );
		   LIS_ExcluirElemento( pLPeca1 );
	   }
	   else
	   {
		   if( LIS_AvancarElementoCorrente(pLPeca2,-1)==2 ) //Se tiver somente um elemnto na posicao a ser movida e for a peca adversária - LIS_CondRetFimLista => 2
		   {
			   PECA_CriarPeca(pPec1,cor1);
			   LIS_ExcluirElemento( pLPeca2 );
			   LIS_InserirElementoApos( pLPeca2, pPec1[0] );
			   LIS_ExcluirElemento( pLPeca1 );
		   }
		   else
		   {
			   return TAB_CondRetLPecasAdversarias;
		   }
	   }
	   

	   return TAB_CondRetOK;

   }
    


 /* Fim função: TAB  &Mover Peca */




/***************************************************************************
*
*  Função: TAB  &Destruir tabuleiro
*
***************************************************************************/


    void TAB_DestruirTabuleiro(LIS_tppLista pLista)
	{
		LIS_DestruirLista( pLista );
	}


 /* Fim função: TAB  &Destruir tabuleiro */



/**************************************************************************
*
*	Função:	TAB DestruirValor
*
*
**************************************************************************/
void TAB_DestruirValor ( void* pValor )
{

	LIS_DestruirLista((LIS_tppLista)pValor );
}
