/**************************************************************************************************
*
*	Módulo de Definição: Módulo Peça
*
*	Nome do arquivo:		PECA.C
*	Letras identificadoras	PECA
*
*	Autores:   Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
*
*	Descrição do Módulo
*		Este módulo implementa conceitualmente peças do gamãoo.
*		
*		Cada Peça só possui o atributo cor.
*		O modulo possui funções para criação de peça, destruição e obtenção da cor de uma peça
*
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define PECA_OWN
#include "PECA.H"
#undef PECA_OWN


/***********************************************************************
*
*  $TC Tipo de dados: PECA Elemento da lista de Peca
*
*
***********************************************************************/

   typedef struct PECA_tagElemPeca {

         char cor ;
               /* A cor da peça  */

   } PECA_tpElemPeca;

/***************************************************************************
*
*  Função: TAB  &Criar Peça
*  ****/

   PECA_tpCondRet PECA_CriarPeca(PECA_tppLista* pLista,char cor)
   {
	   PECA_tpElemPeca *Peca;
	   if(pLista[0]!=NULL)
	   {
		   PECA_DestruirPeca(pLista[0]);
	   }
	   Peca=(PECA_tpElemPeca *)malloc(sizeof(PECA_tpElemPeca));
	   if(Peca==NULL)
		  return PECA_CondRetFaltouMemoria;

	   Peca->cor=cor;

	   pLista[0]=Peca;
	   return PECA_CondRetOK;

   } /* Fim função: TAB  &Criar tabuleiro */

/***************************************************************************
*
*  Função: PECA  &Destruir peça
*  ****/

   PECA_tpCondRet PECA_DestruirPeca( PECA_tppLista pLista )
   {
	   free( pLista);
  
		return PECA_CondRetOK;
   } /* Fim função: PECA  &Destruir peça */

   /***************************************************************************
*
*  Função: PECA  &Destruir peça
*  ****/

   PECA_tpCondRet PECA_ObterCor(PECA_tppLista pLista, char * cor)
   {
	  if(pLista!=NULL)
	  {
		  *cor=pLista->cor;

		  return PECA_CondRetOK ;
	  }
      
	  return  PECA_CondRetPecaVazia;
    
   } /* Fim função: PECA  &Destruir peça */

