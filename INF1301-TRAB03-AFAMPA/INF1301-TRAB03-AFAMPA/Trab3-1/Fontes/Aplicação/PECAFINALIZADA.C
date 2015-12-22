/**************************************************************************************************
*
*	Módulo de Definição: Módulo Peça Finalizada
*
*	Nome do arquivo:		PECAFINALIZADA.C
*	Letras identificadoras	PECAFINALIZADA
*
*	Autores:   Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
*
*	Descrição do Módulo
*		Este módulo implementa conceitualmente peças finalizadas do gamão.
*		
*		O modulo possui funções para criação da lista encadeada que vai ter as peças fianlizadas, destruição dessa lista ,uma função para 
*		inserir as peças , para esvaziar as peças e para contar a quantidade elementos na lista.
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


/*Funçoes nao exportadas*/

void  PECAFINALIZADA_DestruirValor( void* pValor );
/***************************************************************************
*
*  Função:  PECAFINALIZADA &Criar Cria Peca Finalizada
*
*
**************************************************************************/

   PECAFINALIZADA_tpCondRet PECAFINALIZADA_CriarPecaFinalizada(PECAFINALIZADA_tppLista *pLista)
   {

	   *pLista=(PECAFINALIZADA_tppLista)LIS_CriarLista(PECAFINALIZADA_DestruirValor);
	   if(*pLista==NULL)
		   return PECAFINALIZADA_CondRetFaltouMemoria;

	  
	   return PECAFINALIZADA_CondRetOK;
   } /* Fim função: PECAFINALIZADA  &Criar lista duplamete encadeada de peças finalizadas */

/***************************************************************************
*
*  Função:  PECAFINALIZADA  &Destruir Peça
*
**************************************************************************/

  PECAFINALIZADA_tpCondRet PECAFINALIZADA_DestruirPeca( PECAFINALIZADA_tppLista pLista )
   {
	   
	   LIS_DestruirLista(pLista);

		return PECAFINALIZADA_CondRetOK;
   } /* Fim função: PECAFINALIZADA &Destruir Lista duplamente encadeada de peças finalizadas */


/**************************************************************************
*
*	Função:	PECAFINALIZADA &Inserir Peça Finalizada
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

   }	/* Fim função:  PECAFINALIZADA &Inserir as peças finalizadas */

/**************************************************************************
*
*	Função:	PECAFINALIZADA &Esvaziar Peça Finalizada
*
*
**************************************************************************/
   PECAFINALIZADA_tpCondRet PECAFINALIZADA_EsvaziarPecaFinalizada(PECAFINALIZADA_tppLista pLista)
   {

		LIS_EsvaziarLista(pLista);

	   return PECAFINALIZADA_CondRetOK;

   }	/* Fim função: PECACAPTURADA &Retirar as peças finalizadas*/


/**************************************************************************
*
*	Função:	 PECAFINALIZADA &Quantidade  Peça Finalizadas
*
*
**************************************************************************/
   PECAFINALIZADA_tpCondRet PECAFINALIZADA_QuantidadePecaFinalizada(PECAFINALIZADA_tppLista pLista,int *qtd)
   {
	   
	   QtdElemento( pLista ,qtd);

	   return PECAFINALIZADA_CondRetOK ;
   }	/* Fim função: PECACAPTURADA &Retirar as peças finalizadas */


/**************************************************************************
*
*	Função:	 PECAFINALIZADA DestruirValor
*
*

**************************************************************************/
void  PECAFINALIZADA_DestruirValor( void* pValor)
{

	PECA_DestruirPeca( (PECA_tppLista)pValor );
	
}


