/**************************************************************************************************
*
*	M�dulo de Defini��o: M�dulo DadoPontos
*
*	Nome do arquivo:		DADOPONTOS.C
*	Letras identificadoras	DP
*
*	Autores:   Alessandro Faletti, Alexandre Maxinsang, Pedro Augusto
*
*
*	Descri��o do M�dulo
*		Este m�dulo implementa conceitualmente dados pontos do gam�o.
*		
*		O modulo possui fun��es para gera�ao de um dado ponto.
*
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define DADOPONTOS_OWN
#include "DADOPONTOS.H"
#undef DADOPONTOS_OWN


/***********************************************************************
*
*  $TC Tipo de dados: DADOPONTOS Elemento da lista de Peca
*
*
***********************************************************************/

   typedef struct DP_tagElemDadoPontos {

	     int PontoJogo;

		 int Jogador;
		 
         
   } DP_tpElemDadoPontos;



/***************************************************************************
*
*  Fun��o: DADO  &Cria Pontuacao
*
*  ************************************************************************/

   DP_tpCondRet DP_Cria(DP_tppDadoPontos * pLista)
   {
	   
	    DP_tpElemDadoPontos *novo;

		novo = (DP_tpElemDadoPontos *) malloc (sizeof(struct DP_tagElemDadoPontos));
		if(novo==NULL){
			return DP_CondRetFaltouMemoria;
		}

		novo->PontoJogo=1;
		novo->Jogador=0;

		*pLista = novo;

		return DP_CondRetOK;

   } /* Fim fun��o: DADO  &Cria Pontuacao */


/***************************************************************************
*
*  Fun��o: DADO  &Dobra Pontuacao
*
*  ************************************************************************/

  DP_tpCondRet DP_Dobra(DP_tppDadoPontos pLista, int player)
   {
	    if(player<1 || player>2){
			return DP_CondRetPlayerErrado;
		}

		if(pLista->Jogador==0 || pLista->Jogador==player){
			pLista->PontoJogo = ( pLista->PontoJogo * 2 );
			if(player==1){
				pLista->Jogador = 2;
			}else{
				pLista->Jogador = 1;
			}
			return DP_CondRetOK;
		}

		return DP_CondRetJogadorErrado;

   } /* Fim fun��o: DADO  &Dobra Pontuacao */


/***************************************************************************
*
*  Fun��o: DADO  &Obtem valor ad pontuacao
*
*  ************************************************************************/

  DP_tpCondRet DP_ObterPonto(DP_tppDadoPontos pLista, int *ponto)
   {
	    if(pLista!=NULL)
		{
			*ponto = pLista->PontoJogo;
			return DP_CondRetOK;
		}

		return DP_CondRetNExisteDP;

   } /* Fim fun��o: DADO  &Obtem valor ad pontuacao */


/***************************************************************************
*
*  Fun��o: DADO  &Obtem jogador
*
*  ************************************************************************/

  DP_tpCondRet DP_ObterJogador(DP_tppDadoPontos pLista, int *jogador)
   {
	    if(pLista!=NULL)
		{
			*jogador = pLista->Jogador;
			return DP_CondRetOK;
		}

		return DP_CondRetNExisteDP;

   } /* Fim fun��o: DADO  &Obtem jogador */



/***************************************************************************
*
*  Fun��o: DADO  &Add valores
*
*  ************************************************************************/

  DP_tpCondRet DP_Adiciona(DP_tppDadoPontos pLista, int pontos, int jogador)
   {
	    if(pLista!=NULL)
		{
			pLista->PontoJogo = pontos;
			pLista->Jogador = jogador;
			return DP_CondRetOK;
		}

		return DP_CondRetNExisteDP;

   } /* Fim fun��o: DADO  &Add valores */


/***************************************************************************
*
*  Fun��o: DADO  &Destroi estrutura de pontuacao
*
*  ************************************************************************/

  void DP_DestruirPonto(DP_tppDadoPontos pLista)
   {
	  
	    free(pLista);
		pLista=NULL;
   } /* Fim fun��o: DADO  &Destroi estrutura de pontuacao */