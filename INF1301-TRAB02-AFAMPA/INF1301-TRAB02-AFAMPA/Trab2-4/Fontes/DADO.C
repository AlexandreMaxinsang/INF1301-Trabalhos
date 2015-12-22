/**************************************************************************************************
*
*	Módulo de Definição: Módulo Dado
*
*	Nome do arquivo:		DADO.C
*	Letras identificadoras	DADO
*
*	Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto   
*
*	Descrição do Módulo
*		Este módulo implementa conceitualmente dados do gamão.
*		
*		O modulo possui funções para geração de um valor aleatório.
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
*  Função: DADO  &Gera Valor
*  ****/

   DADO_tpCondRet DADO_GeraValor(int *valor)
   {
	    srand( (unsigned)time(NULL));
	    *valor=(rand()%6)+1;
	     
	
		return DADO_CondRetOK;

   } /* Fim função: DADO &Gera valor */