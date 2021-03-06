/**************************************************************************************************
*
*	M�dulo de Defini��o: M�dulo Pe�a
*
*	Nome do arquivo:		PECA.C
*	Letras identificadoras	PECA
*
*	Autores:  Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
*	Descri��o do M�dulo
*		Este m�dulo implementa conceitualmente pe�as do gam�oo.	
*		Cada Pe�a s� possui o atributo cor.
*		O modulo possui fun��es para cria��o de pe�a, destrui��o e obten��o da cor de uma pe�a
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
               /* A cor da pe�a  */

   } PECA_tpElemPeca;

/***************************************************************************
*
*  Fun��o: TAB  &Criar Pe�a
*  ****/

   PECA_tpCondRet PECA_CriarPeca(PECA_tppPeca* pLista,char cor)
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

   } /* Fim fun��o: TAB  &Criar tabuleiro */

/***************************************************************************
*
*  Fun��o: PECA  &Destruir pe�a
*  ****/

   PECA_tpCondRet PECA_DestruirPeca( PECA_tppPeca pLista )
   {
	   free( pLista);
  
		return PECA_CondRetOK;
   } /* Fim fun��o: PECA  &Destruir pe�a */

   /***************************************************************************
*
*  Fun��o: PECA  &Destruir pe�a
*  ****/

   PECA_tpCondRet PECA_ObterCor(PECA_tppPeca pLista, char * cor)
   {
	  if(pLista!=NULL)
	  {
		  *cor=pLista->cor;

		  return PECA_CondRetOK ;
	  }
      
	  return  PECA_CondRetPecaVazia;
    
   } /* Fim fun��o: PECA  &Destruir pe�a */

