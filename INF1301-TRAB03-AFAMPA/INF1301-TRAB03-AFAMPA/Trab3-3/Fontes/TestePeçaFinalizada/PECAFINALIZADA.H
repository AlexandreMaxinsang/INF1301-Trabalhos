#if ! defined( PECAFINALIZADA_ )
#define PECAFINALIZADA_
/***************************************************************************
*
*  $MCD Módulo de definição: PECAFINALIZADA  peça
*
*  Arquivo gerado:              PECAFINALIZADA.h
*  Letras identificadoras:      PECAFINALIZADA
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descrição do módulo
*     Implementa criaçao de uma lista duplamente encadeada de peças finalizadas.
*     Podem existir n listas  em operação simultaneamente.
*
***************************************************************************/
 
#if defined( PECAFINALIZADA_OWN )
   #define PECAFINALIZADA_EXT
#else
   #define PECAFINALIZADA_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

typedef  struct LIS_tagLista * PECAFINALIZADA_tppLista ;
typedef struct PECA_tagElemPeca * PECA_tppLista ;
   

/***********************************************************************
*
*  $TC Tipo de dados: PECAFINALIZADA Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista
*
***********************************************************************/

   typedef enum {

         PECAFINALIZADA_CondRetOK,
               /* Concluiu corretamente */

         PECAFINALIZADA_CondRetFaltouMemoria
               /* Faltou memória ao tentar criar um elemento de lista */

   } PECAFINALIZADA_tpCondRet ;

   /***********************************************************************
*
*  $FC Função: PECAFINALIZADA &Criar Cria Peca Finalizada
*  $ED Descrição da função
*     Cria  lista duplamente encadeada de peça finalizadas.
*
*  $EP Parâmetros
*     pLista  -    um ponteiro de tipo PECAFINALIZADA_tppLista.
*                     Ver descrição do módulo.
*
*    $EAE Assertivas de entrada
*		Existe um ponteiro do tipo PECAFINALIZADA_tppLista e que aponta para alguma parte desconhecidad da memória.
*    $EAS Assertivas de saída 
*	   Caso não falte memória,o ponteiro passado passado pelo paramentro apontará para lista duplamente encadeada de peças finalizadas.
*
*  $FV Valor retornado
*     PECAFINALIZADA_CondRetOK    - criou alista duplamente encadeada sem problema.
*     PECAFINALIZADA_CondRetFaltouMemoria	-faltou memoria para criar a lista 
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

 PECAFINALIZADA_tpCondRet PECAFINALIZADA_CriarPecaFinalizada(PECAFINALIZADA_tppLista *pLista);


/***********************************************************************
*
*  $FC Função: PECAFINALIZADA  &Destruir Peça
*
*  $ED Descrição da função
*     Destrói uma lista duplamente encadeada de peças finalizadas

*  $EP Parâmetros
*     pLista  -    um dado do tipo PECA_tppLista.
*                     Ver descrição do módulo.
*
*  $EAE Assertivas de entrada
*	 	Existe um dado do tipo PECAFINALIZADA_tppLista.
*	 	
*  $EAS Assertivas de saída
*	    Será liberado o conteudo apontado pelo ponteiro que foi passado pelo parâmetro.
*
*
*  $FV Valor retornado
*     PECAFINALIZADA_CondRetOK    - destroi a lista duplamente encadeada sem problema.
*    
*     Não será dada mais informação quanto ao problema ocorrido.
***********************************************************************/

   PECAFINALIZADA_tpCondRet PECAFINALIZADA_DestruirPeca( PECAFINALIZADA_tppLista pLista );

/***************************************************************************
*
*  $FC Função: PECAFINALIZADA &Inserir Peça Finalizada
*
*  $ED Descrição da função
*     Inseri uma peça finalizada na lista.
*
*  $EP Parâmetros
*     pLista  -    um ponteiro de tipo PECAFINALIZADA_tppLista.
*                     Ver descrição do módulo.
*	   pPeca   -   um dado do tipo PECA_tppLista
*
*   $EAE Assertivas de entrada
*	 	Existe um dado do tipo PECAFINALIZADA_tppLista.
*	 	Existe um dado do tipo PECA_tppLista("peça").
*
*  $EAS Assertivas de saída
*		Insere a peça com sucesso na lista.
*
*  $FV Valor retornado
*     PECAFINALIZADA_CondRetOK    - Inseriu a peça na lista sem problemas.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*  *******************************************************************/

  PECAFINALIZADA_tpCondRet PECAFINALIZADA_InserirPecaFinalizada( PECAFINALIZADA_tppLista pLista,char cor );


   /***************************************************************************
*
*  $FC Função: PECAFINALIZADA &Esvaziar Peça Finalizada
*
*  $ED Descrição da função
*     Esvazia a lista duplamente encadeada de peças finalizadas.
*
*  $EP Parâmetros
*     pLista  -    um dado de tipo PECAFINALIZADA_tppLista.
*                     Ver descrição do módulo.
*
*   $EAE Assertivas de entrada
*		Existe um dado do tipo PECAFINALIZADA_tppLista.
*
*  $EAS Assertivas de saída
*		Será esvaziada a lista corretamente.
*
*  $FV Valor retornado
*     PECA_CondRetOK    - Esvaziou a lista sem problemas.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*  *******************************************************************/

    PECAFINALIZADA_tpCondRet PECAFINALIZADA_EsvaziarPecaFinalizada(PECAFINALIZADA_tppLista pLista);

  /***************************************************************************
*
*  $FC Função: PECAFINALIZADA &Quantidade  Peça Finalizadas
*
*  $ED Descrição da função
*     Retorna a quantidade de peças finalizadas na lista.
*
*  $EP Parâmetros
*     pLista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descrição do módulo.
*	  qtd     -   um ponterio de tipo int,em aponta para um dado que armazenará a quantidade de elementos na lista
*
*   $EAE Assertivas de entrada
*	 	Existe um dado do tipo PECAFINALIZADA_tppLista.
*	 	Existe um ponteiro do tipo int que aponta para algum lugar desconhecido da memória.
*
*  $EAS Assertivas de saída
*		O ponteiro qtd apontará para um dado que armazena a quantidade de elementos da lista.
*
*  $FV Valor retornado
*     PECA_CondRetOK    - Percorreu a lista sem problemas.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*  *******************************************************************/
	PECAFINALIZADA_tpCondRet PECAFINALIZADA_QuantidadePecaFinalizada(PECAFINALIZADA_tppLista pLista,int *qtd);


#undef PECAFINALIZADA_EXT
/********** Fim do módulo de definição: PECAFINALIZADA **********/

#else
#endif