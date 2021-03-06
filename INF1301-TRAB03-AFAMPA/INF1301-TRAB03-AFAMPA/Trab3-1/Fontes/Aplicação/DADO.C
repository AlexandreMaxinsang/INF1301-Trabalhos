/**************************************************************************************************
*
*	M�dulo de Defini��o: M�dulo Dado
*
*	Nome do arquivo:		DADO.C
*	Letras identificadoras	DADO
*
*	Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto   
*
*	Descri��o do M�dulo
*		Este m�dulo implementa conceitualmente dados do gam�o.
*		
*		O modulo possui fun��es para gera��o de um valor aleat�rio.
*
**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PECA_OWN
#include "DADO.H"
#undef PECA_OWN

/***************************************************************************
*
*  Fun��o: DADO  &Gera Valor
*  ****/

   DADO_tpCondRet DADO_GeraValor(int *valor)
   {
	   int adicional=rand();
	    srand( (unsigned)time(NULL));

	    *valor=((rand()+adicional)%6)+1;
	     
	
		return DADO_CondRetOK;

   } /* Fim fun��o: DADO &Gera valor */