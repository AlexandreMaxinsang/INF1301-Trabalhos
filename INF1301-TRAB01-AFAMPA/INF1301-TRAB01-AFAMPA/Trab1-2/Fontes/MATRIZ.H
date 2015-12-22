#if ! defined( MATRIZ_ )
#define MATRIZ_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Matriz
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   avs   26/08/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar matrizes.
*     A matriz possui uma cabeça que contém uma referência para o primeiro 
*     nó da matriz e outra para um nó corrente da matriz.
*     Ao iniciar a execução do programa não existe matriz.
*     A matriz poderá estar vazia. Neste caso o primeiro nó da matriz 
*     e o nó corrente serão nulos, embora a cabeça esteja definida.
*     O nó corrente será nulo se e somente se a matriz estiver vazia.
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
               /* Não criou Matriz */

         MAT_CondRetMatrizNaoExiste = 2 ,
               /* Matriz não existe */

         MAT_CondRetMatrizVazia = 3,
               /* Matriz está vazia */

         MAT_CondRetFaltouMemoria = 4,
               /* Faltou memória ao alocar dados */

         MAT_CondRetNoInexiste = 5,
               /* Nó da matriz não existe */

		 MAT_CondRetJaExisteLista = 6,
			  /* Lista já existe */

		MAT_CondRetNaoExisteLista =7
			 /* Nao existe Lista  */
   } MAT_tpCondRet ;


typedef struct tgMatriz tpMatriz;


/***********************************************************************
*
*  $FC Função: MAT Criar matriz
*
*  $ED Descrição da função
*     Cria uma nova matriz vazia.
*     Caso já exista uma matriz, esta será destruída.
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
*  $FC Função: MAT Destruir matriz
*
*  $ED Descrição da função
*     Destrói o corpo e a cabeça da matriz, anulando a matriz corrente.
*     Faz nada caso a matriz corrente não exista.
*
*  $EP Parâmetros
*     $P **vtMatriz = ponteiro para a matriz
*
***********************************************************************/

   void MAT_DestruirMatriz( tpMatriz **vtMatriz);


/***********************************************************************
*
*  $FC Função: MAT Inserir Lista
*
*  $ED Descrição da função
*     Insere uma lista na posição corrente de um elemento da matriz
*
*  $EP Parâmetros
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
*  $FC Função: MAT Vai para o nó da matriz
*
*  $EP Parâmetros
*     $P **vtMatriz = ponteiro para a matriz
*     $P linha = número da linha desejada
*     $P coluna = número da coluna desejada
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
   
   void * EndLista(tpMatriz **vtMatriz);
   

#undef MATRIZ_EXT

/********** Fim do módulo de definição: Módulo matriz **********/

#else
#endif
