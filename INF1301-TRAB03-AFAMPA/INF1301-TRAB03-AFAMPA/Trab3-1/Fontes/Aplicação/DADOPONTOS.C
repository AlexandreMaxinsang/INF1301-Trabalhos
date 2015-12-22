/**************************************************************************************************
*
*	Módulo de Definição: Módulo DadoPontos
*
*	Nome do arquivo:		DADOPONTOS.C
*	Letras identificadoras	DP
*
*	Autores:   Alessandro Faletti, Alexandre Maxinsang, Pedro Augusto
*
*
*	Descrição do Módulo
*		Este módulo implementa conceitualmente dados pontos do gamão.
*		
*		O modulo possui funções para geraçao de um dado ponto.
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
*  Função: DADO  &Cria Pontuacao
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

   } /* Fim função: DADO  &Cria Pontuacao */


/***************************************************************************
*
*  Função: DADO  &Dobra Pontuacao
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

   } /* Fim função: DADO  &Dobra Pontuacao */


/***************************************************************************
*
*  Função: DADO  &Obtem valor ad pontuacao
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

   } /* Fim função: DADO  &Obtem valor ad pontuacao */


/***************************************************************************
*
*  Função: DADO  &Obtem jogador
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

   } /* Fim função: DADO  &Obtem jogador */



/***************************************************************************
*
*  Função: DADO  &Add valores
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

   } /* Fim função: DADO  &Add valores */


/***************************************************************************
*
*  Função: DADO  &Destroi estrutura de pontuacao
*
*  ************************************************************************/

  void DP_DestruirPonto(DP_tppDadoPontos pLista)
   {
	  
	    free(pLista);
		pLista=NULL;
   } /* Fim função: DADO  &Destroi estrutura de pontuacao */