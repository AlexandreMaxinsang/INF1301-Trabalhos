/***************************************************************************
*  $MCI Módulo de implementação: Módulo Matriz
*
*  Arquivo gerado:              MATRIZ.C
*  Letras identificadoras:      MAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      1.00   avs   26/08/2015 Início do desenvolvimento
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>

#define MATRIZ_OWN
#include "MATRIZ.H"
#undef MATRIZ_OWN


/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor do nó da matriz
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/

   typedef struct tgNoMatriz {

         struct tgNoMatriz * pNoEC ;
               /* Ponteiro para Esquerda Cima
               *
               *$EED Assertivas estruturais
               *   É NULL sse não há adjacente */

		 struct tgNoMatriz * pNoC ;
               /* Ponteiro para Cima
               *
               *$EED Assertivas estruturais
               *   É NULL sse não há adjacente */

		 struct tgNoMatriz * pNoDC ;
               /* Ponteiro para Direita Cima
               *
               *$EED Assertivas estruturais
               *   É NULL sse não há adjacente */

		 struct tgNoMatriz * pNoD ;
               /* Ponteiro para Direita
               *
               *$EED Assertivas estruturais
               *   É NULL sse não há adjacente */

		 struct tgNoMatriz * pNoDB ;
               /* Ponteiro para Direita Baixo
               *
               *$EED Assertivas estruturais
               *   É NULL sse não há adjacente */

		 struct tgNoMatriz * pNoB ;
               /* Ponteiro para Baixo
               *
               *$EED Assertivas estruturais
               *   É NULL sse não há adjacente */

		 struct tgNoMatriz * pNoEB ;
               /* Ponteiro para Esquerda Baixo
               *
               *$EED Assertivas estruturais
               *   É NULL sse não há adjacente */

		 struct tgNoMatriz * pNoE ;
               /* Ponteiro para Esquerda
               *
               *$EED Assertivas estruturais
               *   É NULL sse não há adjacente */


         void * pLista ;
               /* Ponteiro para a lista */

   } tpNoMatriz ;


   /***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor da cabeça de uma Matriz
*
*
*  $ED Descrição do tipo
*     A cabe‡a da matriz é o ponto de acesso para uma determinada matriz.
*     Por intermédio da referência para o nó corrente e do ponteiro
*     raiz pode-se navegar a matriz sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a matriz em forma de co-rotina.
*
***********************************************************************/

   typedef struct tgMatriz {

         tpNoMatriz * pNoPrim ;
               /* Ponteiro para a raiz da matriz */

         tpNoMatriz * pNoCorr ;
               /* Ponteiro para o nó corrente da matriz */

   } tpMatriz ;


 /*****  Dados encapsulados no módulo  *****/
	  void DestroiMatriz( tpNoMatriz * pNo );

	  void Liga_Matriz(tpMatriz *pMatriz, int linhas, int colunas );


/***************************************************************************
*
*  Função: MAT Criar Cabeca da matriz
*
*  ************************************************************************/

   MAT_tpCondRet MAT_CriarCabeca(tpMatriz **vtMatriz)
   {
	   
      if (vtMatriz[0] != NULL )
      {
         MAT_DestruirMatriz(vtMatriz) ;
      } /* if */

      vtMatriz[0] = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
      if ( vtMatriz[0] == NULL )
      {
         return MAT_CondRetFaltouMemoria ;
      } /* if */

      vtMatriz[0]->pNoPrim = NULL ;
      vtMatriz[0]->pNoCorr = NULL ;

      return MAT_CondRetOK ;

   } /* Fim função: MAT Criar Cabeca da matriz */


   /***************************************************************************
*
*  Função: MAT Destruir matriz
*  ****/

   void MAT_DestruirMatriz( tpMatriz **vtMatriz)
   {

      if ( vtMatriz[0] != NULL )
      {
         if ( vtMatriz[0]->pNoPrim != NULL )
         {
            DestroiMatriz( vtMatriz[0]->pNoPrim ) ;
         } /* if */
         free(vtMatriz[0] ) ;
		 vtMatriz[0]= NULL ;
      } /* if */

   } /* Fim função: MAT Destruir matriz */



   
/***********************************************************************
*
*  $FC Função: MAT Destruir a estrutura da matriz
*
*  $EAE Assertivas de entradas esperadas
*     pNoMatriz != NULL
*
***********************************************************************/

   void DestroiMatriz( tpNoMatriz * pNo )
   {
	   tpNoMatriz *First;
	  while(pNo->pNoB!=NULL){
		  First = pNo->pNoB;
		  while(pNo->pNoD != NULL){
			  pNo = pNo->pNoD;
			  free(pNo->pNoE);
		  }
		  free(pNo);
		  pNo = First;
	  }
	  while(pNo->pNoD != NULL){
			  pNo = pNo->pNoD;
			  free(pNo->pNoE);
	  }
	   free( pNo ) ;

   } /* Fim função: MAT Destruir a estrutura da Matriz */



/***********************************************************************
*
*  $FC Função: MAT Criar nó da matriz
*
*  $FV Valor retornado
*     Ponteiro para o nó criado.
*     Será NULL caso a memória tenha se esgotado.
*     Os ponteiros do nó criado estarão nulos e o valor é igual ao do
*     parâmetro.
*
***********************************************************************/

   tpNoMatriz * CriarNo( void )
   {

      tpNoMatriz * pNo ;

      pNo = ( tpNoMatriz * ) malloc( sizeof( tpNoMatriz )) ;
      if ( pNo == NULL )
      {
         return NULL ;
      } /* if */

      pNo->pNoEC = NULL ;
      pNo->pNoC  = NULL ;
	  pNo->pNoDC = NULL ;
	  pNo->pNoD  = NULL ;
	  pNo->pNoDB = NULL ;
	  pNo->pNoB  = NULL ;
	  pNo->pNoEB = NULL ;
	  pNo->pNoE  = NULL ;
	  pNo->pLista= NULL ;
      return pNo ;

   } /* Fim função: MAT Criar nó da matriz */


/***********************************************************************
*
*  $FC Função: MAT Criar Matriz
*
*  $EAE Assertivas de entradas esperadas
*     $P **vtMatriz = ponteiro para a matriz
*     linha = número da linha desejada
*     coluna = número da coluna desejada
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetFaltouMemoria
*     MAT_CondRetNaoCriouMatriz
*
***********************************************************************/

   MAT_tpCondRet MAT_CriarMatriz(tpMatriz **vtMatriz,int linhas, int colunas  )
   {

      MAT_tpCondRet CondRet ;
      tpNoMatriz * pNo, *First;
	  int lin, col;

      if (vtMatriz[0]== NULL )
      {
         CondRet = MAT_CriarCabeca(vtMatriz) ;

         if ( CondRet != MAT_CondRetOK )
         {
            return CondRet ;
         } /* if */

      } /* if */


      if ( vtMatriz[0]->pNoPrim == NULL )
      {

		  pNo = CriarNo() ;
          if ( pNo == NULL )
          {
             return MAT_CondRetFaltouMemoria ;
          } /* if */
		  vtMatriz[0]->pNoPrim = pNo ;
          vtMatriz[0]->pNoCorr = pNo ;
		  First = pNo;

		  for(lin=0;lin<linhas;lin++){

			  for(col=1;col<colunas;col++){			/* Começa do 1, pois já existe o primeiro sempre */

				  pNo = CriarNo();					/* Cria um nó */
				  vtMatriz[0]->pNoCorr->pNoD = pNo;		/* Nó corrente aponta para o próximo nó criado à direita */
				  pNo->pNoE = vtMatriz[0]->pNoCorr;		/* Nó criado aponta para o nó corrente à esquerda */
				  vtMatriz[0]->pNoCorr = pNo;			/* Nó criado vira o nó corrente */


			  }
			  if(lin<linhas-1){
				  pNo = CriarNo();						/* Cria um nó */
				  vtMatriz[0]->pNoCorr = First;				/* Corrente aponta para o primeiro da linha */
				  First->pNoB = pNo;					/* Primeiro da linha aponta para o primeiro da próxima linha */
				  pNo->pNoC = First;					/* Primeiro da próxima linha aponta para o primeiro da linha de cima */
				  First = pNo;							/* O primeiro da linha vira o primeiro da próxima linha */
				  vtMatriz[0]->pNoCorr = First;				/* O corrente aponta para o novo nó criado */
			  }
		  }
		  Liga_Matriz(vtMatriz[0],linhas, colunas);

	   if (vtMatriz[0]->pNoCorr == NULL)
		   return MAT_CondRetMatrizVazia;

         return MAT_CondRetOK ;
      } /* if */

      return MAT_CondRetNaoCriouMatriz ;

   } /* Fim função: MAT Cria Matriz */

   /***********************************************************************
*
*  $FC Função: MAT Liga todos os ponteiros da matriz
*
*  $EAE Assertivas de entradas esperadas
*     $P **vtMatriz = ponteiro para a matriz
*     linha = número da linha desejada
*     coluna = número da coluna desejada
*
***********************************************************************/


   void Liga_Matriz(tpMatriz *pMatriz, int linhas, int colunas )
   {
	   int lin, col;
	   tpNoMatriz *l1, *l2, *First;

	   if(pMatriz->pNoPrim->pNoB != NULL && pMatriz->pNoPrim->pNoD != NULL){

		    First = pMatriz->pNoPrim;
			l1 = pMatriz->pNoPrim;
			l2 = pMatriz->pNoPrim->pNoB;

			for(lin=1;lin<linhas;lin++){
				for(col=0;col<colunas;col++){

					l1->pNoEB = l2->pNoE;
					l1->pNoB = l2;
					l1->pNoDB = l2->pNoD;

					l2->pNoEC = l1->pNoE;
					l2->pNoC = l1;
					l2->pNoDC = l1->pNoD;

					if (l1->pNoD != NULL && l2->pNoD != NULL){
						l1 = l1->pNoD;
						l2 = l2->pNoD;
					}
				}

				l1 = First->pNoB;
				l2 = l1->pNoB;

			}
	   }
	   
   } /* Fim função: MAT Liga todos os ponteiros da matriz */


/***********************************************************************
*
*  $FC Função: MAT Vai para o nó da matriz
*
*  $EAE Assertivas de entradas esperadas 
*     $P **vtMatriz = ponteiro para a matriz
*     linha = número da linha desejada
*     coluna = número da coluna desejada
*
*  $FV Valor retornado
*     MAT_CondRetOK
*	  MAT_CondRetNoInexiste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrPara (tpMatriz **vtMatriz,int linha, int coluna) {

	   int conta_linha;
	   int conta_coluna;

	   if (vtMatriz[0]==NULL){
		   return MAT_CondRetMatrizNaoExiste;
	   }

	   vtMatriz[0]->pNoCorr = vtMatriz[0]->pNoPrim; /* Corrente aponta para a raiz da matriz. */

	   for(conta_linha = 1; conta_linha < linha && vtMatriz[0]->pNoCorr != NULL; conta_linha ++)
	   {
		   vtMatriz[0]->pNoCorr = vtMatriz[0]->pNoCorr->pNoB;/* Corrente aponta para o próximo direita. */
	   }
	   for(conta_coluna = 1; conta_coluna < coluna && vtMatriz[0]->pNoCorr != NULL; conta_coluna ++)
	   {
		   vtMatriz[0]->pNoCorr = vtMatriz[0]->pNoCorr->pNoD; /* Corrente aponta para o próximo a baixo. */
	   }
	   if (vtMatriz[0]->pNoCorr == NULL)
		   return MAT_CondRetNoInexiste;

	   return MAT_CondRetOK;
	}



/***********************************************************************
*
*  $FC Função: MAT Insere Lista no nó corrente
*
*  $EAE Assertivas de entradas esperadas
*     **vtMatriz = A matriz apontada
*     *pLista = Endereço do ponteiro lista
*
*  $FV Valor retornado
*     Ponteiro para o nó desejado
*	  Será NULL caso o nó não exista
*
***********************************************************************/


   MAT_tpCondRet MAT_InserirLista(tpMatriz **vtMatriz, void *pLista){

		if(pLista==NULL)
			return  MAT_CondRetNaoExisteLista;

	   if(vtMatriz[0]==NULL){
		   return MAT_CondRetMatrizNaoExiste;
	   }

	   if(vtMatriz[0]->pNoCorr->pLista!=NULL){
		   return MAT_CondRetJaExisteLista;
	   }

	   vtMatriz[0]->pNoCorr->pLista = pLista;

	
	   return MAT_CondRetOK;
   }



/***********************************************************************
*
*  $FC Função: MAT retorna o endereço da lista
*			   de um elemento da matriz
*
*  $EP Parâmetros
*     $P **vtMatriz = ponteiro para a matriz
*
*  $FV Valor retornado
*    endereço da lista de um elemento da matriz
*
***********************************************************************/
   
   void * EndLista(tpMatriz **vtMatriz){
	   if(vtMatriz[0]->pNoPrim==NULL){
		   return NULL;
	   }
	   if(vtMatriz[0]->pNoCorr==NULL){
		   return NULL;
	   }
	   return	vtMatriz[0]->pNoCorr->pLista;
   }
   
   /*-------------------------------------------------------------------------------------//------------------------------------------------------------------------------------------------*/

   

