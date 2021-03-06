/***************************************************************************
*  $MCI M�dulo de implementa��o: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.c
*  Letras identificadoras:      LIS
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatiza��o dos testes de m�dulos C
*  Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#define LISTA_OWN
#include "LISTA.h"
#undef LISTA_OWN

#ifdef _DEBUG
#include   "Generico.h"
#include   "Conta.h"
#include   "cespdin.h"
#include    "IdTiposEspaco.def"
#endif


/***********************************************************************
*
*  $TC Tipo de dados: LIS Elemento da lista
*
*
***********************************************************************/

typedef struct tagElemLista {

#ifdef _DEBUG

	struct LIS_tagLista * pCabeca ;
	/* Ponteiro para cabeca
	*
	*$ED Descri��o
	*   Todos os n�s da lista devem apontar para a respectiva cabe�a.
	*   Esse ponteiro corresponde a um identificador da �rvore para fins
	*   de verifica��o da integridade. */


	 int tamBytes;
	 //O tamanho em bytes da estrutura apontada pelo n�


#endif


	void * pValor ;
	/* Ponteiro para o valor contido no elemento */

	struct tagElemLista * pAnt ;
	/* Ponteiro para o elemento predecessor */

	struct tagElemLista * pProx ;
	/* Ponteiro para o elemento sucessor */

} tpElemLista ;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor da cabe�a de lista
*
*
***********************************************************************/

typedef struct LIS_tagLista {

	tpElemLista * pOrigemLista ;
	/* Ponteiro para a origem da lista */

	tpElemLista * pFimLista ;
	/* Ponteiro para o final da lista */

	tpElemLista * pElemCorr ;
	/* Ponteiro para o elemento corrente da lista */

	int numElem ;
	/* N�mero de elementos da lista */

	void ( * ExcluirValor ) ( void * pValor ) ;
	/* Ponteiro para a fun��o de destrui��o do valor contido em um elemento */

} LIS_tpLista ;

/*****  Dados encapsulados no m�dulo  *****/

#ifdef _DEBUG

static char EspacoLixo[ 256 ] =
	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" ;
/* Espa�o de dados lixo usado ao testar */

#endif



/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

static void LiberarElemento( LIS_tppLista   pLista ,
	tpElemLista  * pElem   ) ;

#ifdef _DEBUG
	static tpElemLista * CriarElemento( LIS_tppLista pLista , void *pValor , int tam );
#else
	static tpElemLista * CriarElemento( LIS_tppLista pLista , void *pValor ) ;
#endif

static void LimparCabeca( LIS_tppLista pLista ) ;

#ifdef _DEBUG
LIS_tpCondRet VerificarNo( tpElemLista * pNo );

#endif

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: LIS  &Criar lista
*  ****/

LIS_tppLista LIS_CriarLista(void   ( * ExcluirValor ) ( void * pDado ) )
{

	LIS_tpLista * pLista = NULL ;


	pLista = ( LIS_tpLista * ) malloc( sizeof( LIS_tpLista )) ;
	if ( pLista == NULL )
	{
		return NULL ;
	} /* if */

	LimparCabeca( pLista ) ;

	pLista->ExcluirValor = ExcluirValor ;

#ifdef _DEBUG
	CED_DefinirTipoEspaco( pLista , LIS_TipoEspacoCabeca ) ;
#endif

	return pLista ;

} /* Fim fun��o: LIS  &Criar lista */

/***************************************************************************
*
*  Fun��o: LIS  &Destruir lista
*  ****/

void LIS_DestruirLista( LIS_tppLista pLista )
{

#ifdef _DEBUG
	assert( pLista != NULL ) ;
#endif

	LIS_EsvaziarLista( pLista ) ;

	free( pLista ) ;

} /* Fim fun��o: LIS  &Destruir lista */

/***************************************************************************
*
*  Fun��o: LIS  &Esvaziar lista
*  ****/

void LIS_EsvaziarLista( LIS_tppLista pLista )
{

	tpElemLista * pElem ;
	tpElemLista * pProx ;

#ifdef _DEBUG
	assert( pLista != NULL ) ;
#endif

	pElem = pLista->pOrigemLista ;
	while ( pElem != NULL )
	{
		pProx = pElem->pProx ;
		LiberarElemento( pLista , pElem ) ;
		pElem = pProx ;
	} /* while */

	LimparCabeca( pLista ) ;

} /* Fim fun��o: LIS  &Esvaziar lista */

/***************************************************************************
*
*  Fun��o: LIS  &Inserir elemento antes
*  ****/

#ifdef _DEBUG
LIS_tpCondRet LIS_InserirElementoAntes( LIS_tppLista pLista , void * pValor, int tam)
#else
LIS_tpCondRet LIS_InserirElementoAntes( LIS_tppLista pLista , void * pValor)
#endif
{

	tpElemLista * pElem ;

#ifdef _DEBUG
	assert( pLista != NULL ) ;
#endif

	/* Criar elemento a inerir antes */

#ifdef _DEBUG
	pElem = CriarElemento( pLista , pValor, tam );
#else
	pElem = CriarElemento( pLista , pValor ) ;
#endif

	if ( pElem == NULL )
	{
		return LIS_CondRetFaltouMemoria ;
	} /* if */

	/* Encadear o elemento antes do elemento corrente */

	if ( pLista->pElemCorr == NULL )
	{
		pLista->pOrigemLista = pElem ;
		pLista->pFimLista = pElem ;
	} else
	{
		if ( pLista->pElemCorr->pAnt != NULL )
		{
			pElem->pAnt  = pLista->pElemCorr->pAnt ;
			pLista->pElemCorr->pAnt->pProx = pElem ;
		} else
		{
			pLista->pOrigemLista = pElem ;
		} /* if */

		pElem->pProx = pLista->pElemCorr ;
		pLista->pElemCorr->pAnt = pElem ;
	} /* if */

	pLista->pElemCorr = pElem ;

	return LIS_CondRetOK ;

} /* Fim fun��o: LIS  &Inserir elemento antes */

/***************************************************************************
*
*  Fun��o: LIS  &Inserir elemento ap�s
*  ****/

#ifdef _DEBUG
LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista , void * pValor, int tam)
#else
LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista , void * pValor)
#endif

{

	tpElemLista * pElem ;

#ifdef _DEBUG
	assert( pLista != NULL ) ;
#endif


#ifdef _DEBUG
	pElem = CriarElemento( pLista , pValor, tam );
#else
	pElem = CriarElemento( pLista , pValor ) ;
#endif

	if ( pElem == NULL )
	{
		return LIS_CondRetFaltouMemoria ;
	}

	if ( pLista->pElemCorr == NULL )
	{
		pLista->pOrigemLista = pElem ;
		pLista->pFimLista = pElem ;
	}

	else
	{

		if ( pLista->pElemCorr->pProx != NULL )
		{
			pElem->pProx  = pLista->pElemCorr->pProx ;
			pLista->pElemCorr->pProx->pAnt = pElem ;
		} 

		else
		{
			pLista->pFimLista = pElem ;
		} 


		pElem->pAnt = pLista->pElemCorr ;
		pLista->pElemCorr->pProx = pElem ;


	} 

	pLista->pElemCorr = pElem ;


	return LIS_CondRetOK ;



} /* Fim fun��o: LIS  &Inserir elemento ap�s */

/***************************************************************************
*
*  Fun��o: LIS  &Excluir elemento
*  ****/

LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista )
{

	tpElemLista * pElem ;

#ifdef _DEBUG
	assert( pLista  != NULL ) ;
#endif


	if ( pLista->pElemCorr == NULL )
	{
		return LIS_CondRetListaVazia ;
	} /* if */

	pElem = pLista->pElemCorr ;

	/* Desencadeia � esquerda */

	if ( pElem->pAnt != NULL )
	{
		pElem->pAnt->pProx   = pElem->pProx ;
		pLista->pElemCorr    = pElem->pAnt ;
	} else {
		pLista->pElemCorr    = pElem->pProx ;
		pLista->pOrigemLista = pLista->pElemCorr ;
	} /* if */

	/* Desencadeia � direita */

	if ( pElem->pProx != NULL )
	{
		pElem->pProx->pAnt = pElem->pAnt ;
	} else
	{
		pLista->pFimLista = pElem->pAnt ;
	} /* if */

	LiberarElemento( pLista , pElem ) ;

	return LIS_CondRetOK ;

} /* Fim fun��o: LIS  &Excluir elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Obter refer�ncia para o valor contido no elemento
*  ****/

void * LIS_ObterValor( LIS_tppLista pLista )
{

#ifdef _DEBUG
	assert( pLista != NULL ) ;
#endif



	if ( pLista->pElemCorr == NULL )
	{
		return NULL ;
	} /* if */

	return pLista->pElemCorr->pValor ;

} /* Fim fun��o: LIS  &Obter refer�ncia para o valor contido no elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Ir para o elemento inicial
*  ****/

void IrInicioLista( LIS_tppLista pLista )
{

#ifdef _DEBUG
	assert( pLista != NULL ) ;
#endif


	pLista->pElemCorr = pLista->pOrigemLista ;

} /* Fim fun��o: LIS  &Ir para o elemento inicial */

/***************************************************************************
*
*  Fun��o: LIS  &Ir para o elemento final
*  ****/

void IrFinalLista( LIS_tppLista pLista )
{

#ifdef _DEBUG
	assert( pLista != NULL ) ;
#endif




	pLista->pElemCorr = pLista->pFimLista ;

} /* Fim fun��o: LIS  &Ir para o elemento final */

/***************************************************************************
*
*  Fun��o: LIS  &Avan�ar elemento
*  ****/

LIS_tpCondRet LIS_AvancarElementoCorrente( LIS_tppLista pLista ,int numElem )
{

	int i ;

	tpElemLista * pElem ;

#ifdef _DEBUG
	assert( pLista != NULL ) ;
#endif




	/* Tratar lista vazia */

	if ( pLista->pElemCorr == NULL )
	{

		return LIS_CondRetListaVazia ;

	} /* fim ativa: Tratar lista vazia */

	/* Tratar avan�ar para frente */

	if ( numElem > 0 )
	{

		pElem = pLista->pElemCorr ;
		for( i = numElem ; i > 0 ; i-- )
		{
			if ( pElem == NULL )
			{
				break ;
			} /* if */
			pElem    = pElem->pProx ;
		} /* for */

		if ( pElem != NULL )
		{
			pLista->pElemCorr = pElem ;
			return LIS_CondRetOK ;
		} /* if */

		pLista->pElemCorr = pLista->pFimLista ;
		return LIS_CondRetFimLista ;

	} /* fim ativa: Tratar avan�ar para frente */

	/* Tratar avan�ar para tr�s */

	else if ( numElem < 0 )
	{

		pElem = pLista->pElemCorr ;
		for( i = numElem ; i < 0 ; i++ )
		{
			if ( pElem == NULL )
			{
				break ;
			} /* if */
			pElem    = pElem->pAnt ;
		} /* for */

		if ( pElem != NULL )
		{
			pLista->pElemCorr = pElem ;
			return LIS_CondRetOK ;
		} /* if */

		pLista->pElemCorr = pLista->pOrigemLista ;
		return LIS_CondRetFimLista ;

	} /* fim ativa: Tratar avan�ar para tr�s */

	/* Tratar n�o avan�ar */

	return LIS_CondRetOK ;

} /* Fim fun��o: LIS  &Avan�ar elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Procurar elemento contendo valor
*  ****/

LIS_tpCondRet LIS_ProcurarValor( LIS_tppLista pLista ,void * pValor   )
{

	tpElemLista * pElem ;

#ifdef _DEBUG
	assert( pLista  != NULL ) ;
#endif



	if ( pLista->pElemCorr == NULL )
	{
		return LIS_CondRetListaVazia ;
	} /* if */

	for ( pElem  = pLista->pElemCorr ;
		pElem != NULL ;
		pElem  = pElem->pProx )
	{
		if ( pElem->pValor == pValor )
		{
			pLista->pElemCorr = pElem ;
			return LIS_CondRetOK ;
		} /* if */
	} /* for */

	return LIS_CondRetNaoAchou ;

} /* Fim fun��o: LIS  &Procurar elemento contendo valor */



#ifdef _DEBUG

/***************************************************************************
*
*  Fun��o:  LIS  &Verificar uma lista
*  ****/

LIS_tpCondRet LIS_VerificarLista( void * pListaParm )
{

	LIS_tpLista * pLista = NULL ;

	if ( LIS_VerificarCabeca( pListaParm ) != LIS_CondRetOK )
	{
		return LIS_CondRetErroEstrutura ;
	} /* if */

	CED_MarcarEspacoAtivo( pListaParm ) ;

	pLista = ( LIS_tpLista * ) ( pListaParm ) ;

	return VerificarNo( pLista->pOrigemLista ) ;

} /* Fim fun��o: LIS  &Verificar uma lista */

#endif


#ifdef _DEBUG

/***************************************************************************
*
*  Fun��o: ARV  &Verificar um n� cabe�a
*
*  **********************************************************/

LIS_tpCondRet LIS_VerificarCabeca( void * pCabecaParm )
{

	LIS_tpLista * pLista= NULL ;

	/* Verifica o tipo do espa�o */


	if ( TST_CompararInt( LIS_TipoEspacoCabeca , CED_ObterTipoEspaco( pCabecaParm ) , "Tipo do espa�o de dados n�o � cabe�a da lista." ) != TST_CondRetOK )
	{
		CNT_CONTAR("LIS_TpEspacoDadoCabecaERRO");
		return LIS_CondRetErroEstrutura ;
	} /* if */
	else
	{
		CNT_CONTAR("LIS_TpEspacoDadoCabecaOK");

	}

	pLista = ( LIS_tpLista * )( pCabecaParm ) ;

	/* Verifica origem da �rvore */

	if ( pLista->pOrigemLista != NULL )
	{
		if ( TST_CompararPonteiro( pCabecaParm , pLista->pOrigemLista->pCabeca ,"N� raiz n�o aponta para cabe�a." ) != TST_CondRetOK )
		{
			CNT_CONTAR("LIS_NoOrigemApontaCabecaERRO");
			return LIS_CondRetErroEstrutura ;
		} /* if */
		else
		{
			CNT_CONTAR("LIS_NoOrigemApontaCabecaOK");
		}

	} 
	else 
	{
		if ( TST_CompararPonteiro( NULL , pLista->pElemCorr ,"Lista vazia tem n� corrente n�o NULL." ) != TST_CondRetOK )
		{
			CNT_CONTAR("LIS_CorrenteNULLERRO");
			return LIS_CondRetErroEstrutura ;
		} /* if */
		else
		{
			CNT_CONTAR("LIS_CorrenteNULLOK");
		}

	} /* if */

	/* Verifica corrente */

	if ( pLista->pElemCorr != NULL )
	{
		if ( TST_CompararPonteiro( pCabecaParm , pLista->pElemCorr->pCabeca ,"N� corrente n�o aponta para cabe�a." ) != TST_CondRetOK )
		{
			CNT_CONTAR("LIS_CorrenteCabecaERRO");
			return LIS_CondRetErroEstrutura ;
		} /* if */
		else
		{
			CNT_CONTAR("LIS_CorrenteCabecaOK");
		}
	} 
	else 
	{
		if ( TST_CompararPonteiro( NULL , pLista->pOrigemLista ,"Lista n�o vazia tem n� corrente NULL." ) != TST_CondRetOK )
		{
			CNT_CONTAR("LIS_ListaNVaziaCorrenteNULLERRO");
			return LIS_CondRetErroEstrutura ;
		} /* if */
		else
		{
			CNT_CONTAR("LIS_ListaNVaziaCorrenteNULLOK");

		}
	} /* if */

	return LIS_CondRetOK ;

} /* Fim fun��o: LIS  &Verificar um n� cabe�a */

#endif


#ifdef _DEBUG

/***************************************************************************
*
*  Fun��o: LIS  &Verificar um n� de estrutura
*
*
* **************************************************************************/

LIS_tpCondRet LIS_VerificarNo( void * pNoParm )
{

	tpElemLista * pNo     = NULL ;
	LIS_tpLista  * pLista = NULL ;

	/* Verificar se � n� estrutural */
	if ( TST_CompararInt(LIS_TipoEspacoNo ,CED_ObterTipoEspaco( pNoParm ) ,"Tipo do espa�o de dados n�o � n� de lista." ) != TST_CondRetOK )
	{
		CNT_CONTAR("LIS_TpEspacoDadosListaERRO");
		return LIS_CondRetErroEstrutura ;
	} /* if */
	else
	{
		CNT_CONTAR("LIS_TpEspacoDadosListaOK");
	}

	pNo     = ( tpElemLista * )( pNoParm ) ;
	pLista = pNo->pCabeca ;

	/*verificar cabeca*/

	if(pLista==NULL || TST_CompararPonteiro( pLista ,pLista->pOrigemLista->pCabeca ,"O n� nao pertence a mesma lista " ) != TST_CondRetOK )
	{
		CNT_CONTAR("LIS_NoPCabecaERRO");
		return LIS_CondRetErroEstrutura ;
	}
	else
	{
		CNT_CONTAR("LIS_NoPCabecaOK");
	}

	/* Verificar n� */
	if( pNo->tamBytes == 0)
	{
		CNT_CONTAR("LIS_TamanhoErradoNo");
		return LIS_CondRetErroEstrutura ;
	}
	else
	{
		CNT_CONTAR("LIS_TamanhoCertoNo");
	}


	/* Verificar n� */
	if( pNo->pValor == NULL)
	{
		CNT_CONTAR("LIS_TpListaSemValor");
		return LIS_CondRetErroEstrutura ;
	}
	else
	{
		CNT_CONTAR("LIS_TpListaComValor");
	}


	if(pNo->pAnt!=NULL && pNo->pProx!=NULL)
	{
		if ( TST_CompararPonteiro( pNo , pNo->pProx->pAnt ,"O n� anterior nao � este n� " ) != TST_CondRetOK || TST_CompararPonteiro( pNo , pNo->pAnt->pProx ,"O n� sucessor n�o � este n�" ) != TST_CondRetOK)
		{
			CNT_CONTAR("LIS_NoAntouSucERRO");
			return LIS_CondRetErroEstrutura ;
		} /* if */
		else
		{

			CNT_CONTAR("LIS_NoAntouSucOK");

		}
	}
	else
	{

		if(pNo->pAnt==NULL)
		{
			if ( TST_CompararPonteiro( pNo,pLista->pOrigemLista ,"N� n�o � n� origem." ) != TST_CondRetOK)
			{
				CNT_CONTAR("LIS_NoNOrigemERRO");
				return LIS_CondRetErroEstrutura ;
			} /* if */
			else
			{
				CNT_CONTAR("LIS_NoNOrigemOK");
			}
		}
		else
		{
			if ( TST_CompararPonteiro( pNo,pLista->pFimLista ,"N� n�o � n� fim." ) != TST_CondRetOK)
			{
				CNT_CONTAR("LIS_NoNFimERRO");
				return LIS_CondRetErroEstrutura ;
			} /* if */
			else
			{
				CNT_CONTAR("LIS_NoNFimOK");
			}

		}

	}



	return LIS_CondRetOK ;

} /* Fim fun��o: LIS  &Verificar um n� de estrutura */

#endif



#ifdef _DEBUG
/***************************************************************************
*
*  Fun��o: LIS  &Deturpar lista
*  
*****************************************************************************/

void LIS_Deturpar( void * pListaParm ,LIS_tpModosDeturpacao ModoDeturpar )
{

	LIS_tpLista * pLista = NULL ;
	LIS_tpLista * aux=NULL;

	if ( pListaParm == NULL )
	{
		return ;
	} /* if */

	pLista = ( LIS_tpLista * )( pListaParm ) ;

	switch ( ModoDeturpar ) {

		/* Eliminar o n� corrente */

	case DeturpaEliminaCorrente :
		{
			if(pLista->pElemCorr->pAnt!=NULL && pLista->pElemCorr->pProx!=NULL){
				pLista->pElemCorr->pAnt->pProx = NULL;
				pLista->pElemCorr->pProx->pAnt = NULL;
			}
			else if(pLista->pElemCorr->pAnt!=NULL && pLista->pElemCorr->pProx==NULL)
			{
				pLista->pElemCorr->pAnt->pProx = NULL;
			}
			else if(pLista->pElemCorr->pAnt==NULL && pLista->pElemCorr->pProx!=NULL)
			{
				pLista->pElemCorr->pProx->pAnt = NULL;
			}

			free(pLista->pElemCorr);
			pLista->pElemCorr = NULL;

			break ;


		} /* fim ativa: Eliminar o n� corrente */

		/*N� proximo do n� corrente recebe nulo */

	case DeturpaProxNulo :
		{

			pLista->pElemCorr->pProx = NULL;

			break ;

		} /* fim ativa: N� proximo  do n� corrente recebe nulo */

		/*  N� anterior do n� corrente recebe nulo  */

	case DeturpaAntNulo :
		{

			pLista->pElemCorr->pAnt = NULL;
			break ;

		} /* fim ativa:N� anterior do n� corrente recebe nulo  */


		/*  N� proximo do n� corrente aponta para lixo  */

	case DeturpaProxLixo :
		{

			pLista->pElemCorr->pProx= (tpElemLista *)( EspacoLixo );
			break ;

		} /* fim ativa: N� proximo  do n� corrente aponta para lixo  */


		/*  N� anterior do n� corrente aponta para lixo  */
	case DeturpaAntLixo :
		{

			pLista->pElemCorr->pAnt= (tpElemLista *)( EspacoLixo );
			break ;

		} /* fim ativa: N� anterior do n� corrente aponta para lixo  */



		/* O valor do n� corrente recebe nulo  */

	case DeturpaValorNulo :
		{

			pLista->pElemCorr->pValor = NULL;
			break ;

		} /* fim ativa: O valor do n� corrente recebe nulo  */


		/*Modificar o tipo de estrutura apontada  */

	case DeturpaTipo :
		{

			CED_DefinirTipoEspaco( pLista->pElemCorr, CED_ID_TIPO_VALOR_NULO ) ;
			break ;

		} /* fim ativa: Modificar o tipo de estrutura apontada  */


		/* Desencadeia n� sem liber�-lo com free  */

	case DeturpaDesencadearNo :
		{
			tpElemLista * pElem=pLista->pElemCorr ;

			/* Desencadeia � esquerda */

         if ( pElem->pAnt != NULL )
         {
            pElem->pAnt->pProx   = pElem->pProx ;
            pLista->pElemCorr    = pElem->pAnt ;
         } else {
            pLista->pElemCorr    = pElem->pProx ;
            pLista->pOrigemLista = pLista->pElemCorr ;
         } /* if */

      /* Desencadeia � direita */

         if ( pElem->pProx != NULL )
         {
            pElem->pProx->pAnt = pElem->pAnt ;
         } else
         {
            pLista->pFimLista = pElem->pAnt ;
         } /* if */

			break ;

		} /* fim ativa: Desencadeia n� sem liber�-lo com free  */

		/*Atribui NULL ao ponteiro corrente */

	case DeturpaElemCorrNulo :
		{

			pLista->pElemCorr = NULL;

			break ;

		} /* fim ativa: Atribui NULL ao ponteiro corrente */
		/*Atribui NULL ao ponteiro origem */

	case DeturpaElemOrigNulo :
		{

			pLista->pOrigemLista = NULL;

			break ;

		} /* fim ativa: Atribui NULL ao ponteiro origem */


		/* Anula ponteiro cabe�a */

	case DeturpaPtCabecaNulo :
		{

			pLista->pElemCorr->pCabeca = NULL ;

			break ;

		} /* fim ativa: Anula ponteiro cabe�a */

		/* Faz ponteiro cabe�a apontar para lixo */

	case DeturpaPtCabecaLixo :
		{

			pLista->pElemCorr->pCabeca = ( LIS_tpLista * )( EspacoLixo ) ;

			break ;

		} /* fim ativa: Faz ponteiro cabe�a apontar para lixo */

	case DeturpaTipoCabeca :
		{

			CED_DefinirTipoEspaco( pLista->pElemCorr->pCabeca, CED_ID_TIPO_VALOR_NULO ) ;
			break ;

		} /* fim ativa: Modificar o tipo de estrutura apontada  */

		case DeturpaTamNo :
		{

			pLista->pElemCorr->tamBytes = 0;
			break;

		} /* fim ativa: Modificar o tamanho de bytes que o no armazena */



	} /* fim seleciona: Raiz de  LIS  &Deturpar lista */

} /* Fim fun��o: LIS  &Deturpar lista */

#endif


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: LIS  -Liberar elemento da lista
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados pelo valor do elemento e o
*     pr�prio elemento.
*
***********************************************************************/

void LiberarElemento( LIS_tppLista   pLista , tpElemLista  * pElem   )
{

	if ( ( pLista->ExcluirValor != NULL )
		&& ( pElem->pValor != NULL        ))
	{
		pLista->ExcluirValor( pElem->pValor ) ;
	} /* if */

	free( pElem ) ;

	pLista->numElem-- ;

} /* Fim fun��o: LIS  -Liberar elemento da lista */


/***********************************************************************
*
*  $FC Fun��o: LIS  -Criar o elemento
*
***********************************************************************/

#ifdef _DEBUG
	tpElemLista * CriarElemento( LIS_tppLista pLista ,void * pValor, int tam )
#else
	tpElemLista * CriarElemento( LIS_tppLista pLista ,void * pValor )
#endif
{

	tpElemLista * pElem ;

	pElem = ( tpElemLista * ) malloc( sizeof( tpElemLista )) ;
	if ( pElem == NULL )
	{
		return NULL ;
	} /* if */

#ifdef _DEBUG
	CED_DefinirTipoEspaco( pElem , LIS_TipoEspacoNo ) ;
	pElem->pCabeca = pLista ;
	pElem->tamBytes=tam;
#endif

	pElem->pValor = pValor ;
	pElem->pAnt   = NULL  ;
	pElem->pProx  = NULL  ;

	pLista->numElem ++ ;

	return pElem ;

} /* Fim fun��o: LIS  -Criar o elemento */


/***********************************************************************
*
*  $FC Fun��o: LIS  -Limpar a cabe�a da lista
*
***********************************************************************/

void LimparCabeca( LIS_tppLista pLista )
{

	pLista->pOrigemLista = NULL ;
	pLista->pFimLista = NULL ;
	pLista->pElemCorr = NULL ;
	pLista->numElem   = 0 ;

} /* Fim fun��o: LIS  -Limpar a cabe�a da lista */


#ifdef _DEBUG


/***********************************************************************
*
*  $FC Fun��o: LIS  -Explorar verificando os n�s de uma lista
*
*  $ED Descri��o da fun��o
*     Percorre recursivamente a lista verificando os n�s � medida que forem
*     visitados. Caso seja encontrado alguma falha, a verifica��o ser�
*     suspensa. Portanto, no caso de falha, � poss�vel que nem todos
*     os n�s da lista sejam visitados.
*
***********************************************************************/

LIS_tpCondRet VerificarNo( tpElemLista * pNo )
{

	LIS_tpCondRet CondErro = LIS_CondRetOK ;

	if ( pNo == NULL )
	{
		return LIS_CondRetOK ;
	} /* if */

	CED_MarcarEspacoAtivo( pNo ) ;

	CondErro = LIS_VerificarNo( pNo ) ;

	if ( CondErro == LIS_CondRetOK )
	{
		CondErro = VerificarNo( pNo->pProx) ;
	} /* if */


	return CondErro ;

} /* Fim fun��o:  LIS  -Explorar verificando os n�s de uma lista */

#endif

/********** Fim do m�dulo de implementa��o: LIS  Lista duplamente encadeada **********/