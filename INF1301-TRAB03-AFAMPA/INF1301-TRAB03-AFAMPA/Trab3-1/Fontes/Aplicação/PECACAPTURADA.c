/**************************************************************************************************
*
*	Módulo de Definição: Módulo Peça Capturada
*
*	Nome do arquivo:		PECACAPTURADA.C
*	Letras identificadoras	PECACAPTURADA
*
*	Autores:   Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
*
*	Descrição do Módulo
*		Este módulo implementa conceitualmente uma lista duplamente encadeadas de peças capturadas do gamão.
*		
*		O modulo possui funções para criação da lista encadeada que vai ter as peças capturadas, destruição dessa lista ,uma função para 
*		inserir as peças e para retirar as peças da lista.
*
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define PECACAPTURADA_OWN
#define LISTA_OWN
#define PECA_OWN
#include "PECA.H"
#include "LISTA.H"
#include "PECACAPTURADA.H"
#undef PECA_OWN
#undef	LISTA_OWN
#undef PECACAPTURADA_OWN


void PECACAPTURADA_DestruirValor ( void* pValor );

/***************************************************************************
*
*  Função: PECACAPTURADA &Criar Peca
*
*


**************************************************************************/

   PECACAPTURADA_tpCondRet PECACAPTURADA_CriarPecaCapturada(PECACAPTURADA_tppLista *pLista)
   {

	   *pLista=(PECACAPTURADA_tppLista)LIS_CriarLista(PECACAPTURADA_DestruirValor);
	   if(*pLista==NULL)
		   return PECACAPTURADA_CondRetFaltouMemoria;

	   return PECACAPTURADA_CondRetOK;
   } /* Fim função:PECACAPTURADA  &Criar lista duplamete encadeada de peças capturadas */

/***************************************************************************
*
*  Função:  PECACAPTURADA  &Destruir Peca 
*
*


**************************************************************************/

   PECACAPTURADA_tpCondRet PECACAPTURADA_DestruirPeca( PECACAPTURADA_tppLista pLista )
   {
	   
	   LIS_DestruirLista(pLista);

		return PECACAPTURADA_CondRetOK;
   } /* Fim função: PECACAPTURADA &Destruir Lista duplamente encadeada de peças capturadas */


/**************************************************************************
*
*	Função:PECACAPTURADA &Inserir uma peça capturada 
*
*


**************************************************************************/
   PECACAPTURADA_tpCondRet PECACAPTURADA_InserirPecaCapturada(PECACAPTURADA_tppLista pLista,char cor )
   {
		PECA_tppPeca pPecaCap[1]={NULL};
		
		PECA_CriarPeca(pPecaCap,cor);

		LIS_InserirElementoApos(pLista , pPecaCap[0]);
		pPecaCap[0]=NULL;

		return PECACAPTURADA_CondRetOK;

   }	/* Fim função: PECACAPTURADA &Inserir as peças capturadas */

/**************************************************************************
*
*	Função:	PECACAPTURADA &Retirar  Peca Capturada
*
*


**************************************************************************/
   PECACAPTURADA_tpCondRet PECACAPTURADA_RetirarPecaCapturada(PECACAPTURADA_tppLista pLista )
   {

		PECA_tppPeca pPecaCap;
		char cor;

	    pPecaCap=(PECA_tppPeca) LIS_ObterValor((LIS_tppLista)pLista);

		if(pPecaCap==NULL)
			return PECACAPTURADA_CondRetPecaVazia;

	    PECA_ObterCor(pPecaCap, &cor);
		LIS_ExcluirElemento(pLista );

	   return PECACAPTURADA_CondRetOK;

   }	/* Fim função: PECACAPTURADA &Retirar as peças capturadas */


/**************************************************************************
*
*	Função:	 PECACAPTURADA &Quantidade Peças Capturadas
*
**************************************************************************/
   PECACAPTURADA_tpCondRet PECACAPTURADA_QuantidadePecaCapturada(PECACAPTURADA_tppLista pLista,int *qtd)
   {
	   
	   QtdElemento( pLista ,qtd);

	   return PECACAPTURADA_CondRetOK ;
   }	/* Fim função: PECACAPTURADA &Quantidade Peças Capturadas */


/**************************************************************************
*
*	Função:	PECACAPTURADA DestruirValor
*
*
*
**************************************************************************/
void PECACAPTURADA_DestruirValor ( void* pValor )
{

	PECA_DestruirPeca( (PECA_tppPeca)pValor );
}


