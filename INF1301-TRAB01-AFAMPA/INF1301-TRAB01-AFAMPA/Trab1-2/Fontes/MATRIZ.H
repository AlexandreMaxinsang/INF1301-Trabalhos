#if ! defined( MATRIZ_ )
#define MATRIZ_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Matriz
*
*  Arquivo gerado:              MATRIZ.H
*  Letras identificadoras:      MAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   avs   26/08/2015 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar matrizes.
*     A matriz possui uma cabe�a que cont�m uma refer�ncia para o primeiro 
*     n� da matriz e outra para um n� corrente da matriz.
*     Ao iniciar a execu��o do programa n�o existe matriz.
*     A matriz poder� estar vazia. Neste caso o primeiro n� da matriz 
*     e o n� corrente ser�o nulos, embora a cabe�a esteja definida.
*     O n� corrente ser� nulo se e somente se a matriz estiver vazia.
*
***************************************************************************/
 
#if defined( MATRIZ_OWN )
   #define MATRIZ_EXT
#else
   #define MATRIZ_EXT extern
#endif



/***********************************************************************
*
*  $TC Tipo de dados: MAT Condicoes de retorno
*
***********************************************************************/

   typedef enum {

         MAT_CondRetOK = 0 ,
               /* Executou correto */

		 MAT_CondRetNaoCriouMatriz = 1 ,
               /* N�o criou Matriz */

         MAT_CondRetMatrizNaoExiste = 2 ,
               /* Matriz n�o existe */

         MAT_CondRetMatrizVazia = 3,
               /* Matriz est� vazia */

         MAT_CondRetFaltouMemoria = 4,
               /* Faltou mem�ria ao alocar dados */

         MAT_CondRetNoInexiste = 5,
               /* N� da matriz n�o existe */

		 MAT_CondRetJaExisteLista = 6,
			  /* Lista j� existe */

		MAT_CondRetNaoExisteLista =7
			 /* Nao existe Lista  */
   } MAT_tpCondRet ;


typedef struct tgMatriz tpMatriz;


/***********************************************************************
*
*  $FC Fun��o: MAT Criar matriz
*
*  $ED Descri��o da fun��o
*     Cria uma nova matriz vazia.
*     Caso j� exista uma matriz, esta ser� destru�da.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetFaltouMemoria
*	  MAT_CondRetNaoCriouMatriz
*
***********************************************************************/

   MAT_tpCondRet MAT_CriarMatriz( tpMatriz **pMatriz, int linhas, int colunas );


/***********************************************************************
*
*  $FC Fun��o: MAT Destruir matriz
*
*  $ED Descri��o da fun��o
*     Destr�i o corpo e a cabe�a da matriz, anulando a matriz corrente.
*     Faz nada caso a matriz corrente n�o exista.
*
*  $EP Par�metros
*     $P **vtMatriz = ponteiro para a matriz
*
***********************************************************************/

   void MAT_DestruirMatriz( tpMatriz **vtMatriz);


/***********************************************************************
*
*  $FC Fun��o: MAT Inserir Lista
*
*  $ED Descri��o da fun��o
*     Insere uma lista na posi��o corrente de um elemento da matriz
*
*  $EP Par�metros
*     $P **vtMatriz = ponteiro para a matriz
*     $P *pLista = ponteiro para a lista
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetJaExisteLista
*
***********************************************************************/

   MAT_tpCondRet MAT_InserirLista(tpMatriz **vtMatriz, void *pLista);


/***********************************************************************
*
*  $FC Fun��o: MAT Vai para o n� da matriz
*
*  $EP Par�metros
*     $P **vtMatriz = ponteiro para a matriz
*     $P linha = n�mero da linha desejada
*     $P coluna = n�mero da coluna desejada
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNoInexiste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrPara (tpMatriz **vtMatriz,int linha, int coluna);


/***********************************************************************
*
*  $FC Fun��o: MAT retorna o endere�o da lista
*			   de um elemento da matriz
*
*  $EP Par�metros
*     $P **vtMatriz = ponteiro para a matriz
*
*  $FV Valor retornado
*    endere�o da lista de um elemento da matriz
*
***********************************************************************/
   
   void * EndLista(tpMatriz **vtMatriz);
   

#undef MATRIZ_EXT

/********** Fim do m�dulo de defini��o: M�dulo matriz **********/

#else
#endif
