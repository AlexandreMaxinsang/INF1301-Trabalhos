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

#include <stdio.h>
#include <stdlib.h>


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
	   
	    DP_tpElemDadoPontos *NEW;
		if(*pLista!=NULL){
			return DP_CondRetJaExisteDP;
		}

		NEW = (DP_tpElemDadoPontos *) malloc (sizeof(DP_tpElemDadoPontos));
		if(NEW==NULL){
			return DP_CondRetFaltouMemoria;
		}

		NEW->PontoJogo=1;
		NEW->Jogador=0;

		*pLista = NEW;

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
*  Função: DADO  &Destroi estrutura de pontuacao
*
*  ************************************************************************/

  void DP_DestruirPonto(DP_tppDadoPontos pLista)
   {
	    free(pLista);
   } /* Fim função: DADO  &Destroi estrutura de pontuacao */