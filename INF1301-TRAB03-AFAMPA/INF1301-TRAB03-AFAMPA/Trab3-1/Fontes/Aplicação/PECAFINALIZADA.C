/**************************************************************************************************
*
*	M�dulo de Defini��o: M�dulo Pe�a Finalizada
*
*	Nome do arquivo:		PECAFINALIZADA.C
*	Letras identificadoras	PECAFINALIZADA
*
*	Autores:   Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
*
*	Descri��o do M�dulo
*		Este m�dulo implementa conceitualmente pe�as finalizadas do gam�o.
*		
*		O modulo possui fun��es para cria��o da lista encadeada que vai ter as pe�as fianlizadas, destrui��o dessa lista ,uma fun��o para 
*		inserir as pe�as , para esvaziar as pe�as e para contar a quantidade elementos na lista.
*
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <assert.h>

#define PECAFINALIZADA_OWN
#include "PECAFINALIZADA.h"
#undef PECAFINALIZADA_OWN

#define LISTA_OWN
#include "LISTA.h"
#undef LISTA_OWN

#define PECA_OWN
#include "PECA.h"
#undef PECA_OWN


/*Fun�oes nao exportadas*/

void  PECAFINALIZADA_DestruirValor( void* pValor );
/***************************************************************************
*
*  Fun��o:  PECAFINALIZADA &Criar Cria Peca Finalizada
*
*
**************************************************************************/

   PECAFINALIZADA_tpCondRet PECAFINALIZADA_CriarPecaFinalizada(PECAFINALIZADA_tppLista *pLista)
   {

	   *pLista=(PECAFINALIZADA_tppLista)LIS_CriarLista(PECAFINALIZADA_DestruirValor);
	   if(*pLista==NULL)
		   return PECAFINALIZADA_CondRetFaltouMemoria;

	  
	   return PECAFINALIZADA_CondRetOK;
   } /* Fim fun��o: PECAFINALIZADA  &Criar lista duplamete encadeada de pe�as finalizadas */

/***************************************************************************
*
*  Fun��o:  PECAFINALIZADA  &Destruir Pe�a
*
**************************************************************************/

  PECAFINALIZADA_tpCondRet PECAFINALIZADA_DestruirPeca( PECAFINALIZADA_tppLista pLista )
   {
	   
	   LIS_DestruirLista(pLista);

		return PECAFINALIZADA_CondRetOK;
   } /* Fim fun��o: PECAFINALIZADA &Destruir Lista duplamente encadeada de pe�as finalizadas */


/**************************************************************************
*
*	Fun��o:	PECAFINALIZADA &Inserir Pe�a Finalizada
*
*
**************************************************************************/
    PECAFINALIZADA_tpCondRet PECAFINALIZADA_InserirPecaFinalizada( PECAFINALIZADA_tppLista pLista,char cor)
   {
	    
		PECA_tppLista pPecaFin[1]={NULL};

		PECA_CriarPeca(pPecaFin,cor);
		LIS_InserirElementoApos(pLista ,pPecaFin[0]);
		pPecaFin[0]=NULL;

		return  PECAFINALIZADA_CondRetOK;

   }	/* Fim fun��o:  PECAFINALIZADA &Inserir as pe�as finalizadas */

/**************************************************************************
*
*	Fun��o:	PECAFINALIZADA &Esvaziar Pe�a Finalizada
*
*
**************************************************************************/
   PECAFINALIZADA_tpCondRet PECAFINALIZADA_EsvaziarPecaFinalizada(PECAFINALIZADA_tppLista pLista)
   {

		LIS_EsvaziarLista(pLista);

	   return PECAFINALIZADA_CondRetOK;

   }	/* Fim fun��o: PECACAPTURADA &Retirar as pe�as finalizadas*/


/**************************************************************************
*
*	Fun��o:	 PECAFINALIZADA &Quantidade  Pe�a Finalizadas
*
*
**************************************************************************/
   PECAFINALIZADA_tpCondRet PECAFINALIZADA_QuantidadePecaFinalizada(PECAFINALIZADA_tppLista pLista,int *qtd)
   {
	   
	   QtdElemento( pLista ,qtd);

	   return PECAFINALIZADA_CondRetOK ;
   }	/* Fim fun��o: PECACAPTURADA &Retirar as pe�as finalizadas */


/**************************************************************************
*
*	Fun��o:	 PECAFINALIZADA DestruirValor
*
*

**************************************************************************/
void  PECAFINALIZADA_DestruirValor( void* pValor)
{

	PECA_DestruirPeca( (PECA_tppLista)pValor );
	
}


