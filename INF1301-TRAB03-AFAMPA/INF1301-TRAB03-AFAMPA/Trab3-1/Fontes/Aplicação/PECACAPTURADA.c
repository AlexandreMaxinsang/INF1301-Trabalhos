/**************************************************************************************************
*
*	M�dulo de Defini��o: M�dulo Pe�a Capturada
*
*	Nome do arquivo:		PECACAPTURADA.C
*	Letras identificadoras	PECACAPTURADA
*
*	Autores:   Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
*
*	Descri��o do M�dulo
*		Este m�dulo implementa conceitualmente uma lista duplamente encadeadas de pe�as capturadas do gam�o.
*		
*		O modulo possui fun��es para cria��o da lista encadeada que vai ter as pe�as capturadas, destrui��o dessa lista ,uma fun��o para 
*		inserir as pe�as e para retirar as pe�as da lista.
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
*  Fun��o: PECACAPTURADA &Criar Peca
*
*


**************************************************************************/

   PECACAPTURADA_tpCondRet PECACAPTURADA_CriarPecaCapturada(PECACAPTURADA_tppLista *pLista)
   {

	   *pLista=(PECACAPTURADA_tppLista)LIS_CriarLista(PECACAPTURADA_DestruirValor);
	   if(*pLista==NULL)
		   return PECACAPTURADA_CondRetFaltouMemoria;

	   return PECACAPTURADA_CondRetOK;
   } /* Fim fun��o:PECACAPTURADA  &Criar lista duplamete encadeada de pe�as capturadas */

/***************************************************************************
*
*  Fun��o:  PECACAPTURADA  &Destruir Peca 
*
*


**************************************************************************/

   PECACAPTURADA_tpCondRet PECACAPTURADA_DestruirPeca( PECACAPTURADA_tppLista pLista )
   {
	   
	   LIS_DestruirLista(pLista);

		return PECACAPTURADA_CondRetOK;
   } /* Fim fun��o: PECACAPTURADA &Destruir Lista duplamente encadeada de pe�as capturadas */


/**************************************************************************
*
*	Fun��o:PECACAPTURADA &Inserir uma pe�a capturada 
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

   }	/* Fim fun��o: PECACAPTURADA &Inserir as pe�as capturadas */

/**************************************************************************
*
*	Fun��o:	PECACAPTURADA &Retirar  Peca Capturada
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

   }	/* Fim fun��o: PECACAPTURADA &Retirar as pe�as capturadas */


/**************************************************************************
*
*	Fun��o:	 PECACAPTURADA &Quantidade Pe�as Capturadas
*
**************************************************************************/
   PECACAPTURADA_tpCondRet PECACAPTURADA_QuantidadePecaCapturada(PECACAPTURADA_tppLista pLista,int *qtd)
   {
	   
	   QtdElemento( pLista ,qtd);

	   return PECACAPTURADA_CondRetOK ;
   }	/* Fim fun��o: PECACAPTURADA &Quantidade Pe�as Capturadas */


/**************************************************************************
*
*	Fun��o:	PECACAPTURADA DestruirValor
*
*
*
**************************************************************************/
void PECACAPTURADA_DestruirValor ( void* pValor )
{

	PECA_DestruirPeca( (PECA_tppPeca)pValor );
}


