#if ! defined( PECA_ )
#define PECA_
/***************************************************************************
*
*  $MCD Módulo de definição: PECA  peça
*
*  Arquivo gerado:              PECA.h
*  Letras identificadoras:      PECA
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: AFAMPA - Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descrição do módulo
*     Implementa criaçao do peça.
*     Podem existir n peças em operação simultaneamente.
*
*     Cada peça é homogênea quanto ao tipo dos dados que armazena.
*     Cada peça referencia o valor que contém.
***************************************************************************/
 
#if defined( PECA_OWN )
   #define PECA_EXT
#else
   #define PECA_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

typedef struct PECA_tagElemPeca * PECA_tppLista ;


/***********************************************************************
*
*  $TC Tipo de dados: PECA Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista
*
***********************************************************************/

   typedef enum {

         PECA_CondRetOK,
               /* Concluiu corretamente */

         PECA_CondRetPecaVazia ,
               /* Nao existe a peça  */

         PECA_CondRetFaltouMemoria
               /* Faltou memória ao tentar criar um elemento de lista */

   } PECA_tpCondRet ;

   /***********************************************************************
*
*  $FC Função: PECA &Criar peça
*
*  $ED Descrição da função
*     Cria uma peça.
*
*  $EP Parâmetros
*     plista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descrição do módulo.
*
*   $EAE Assertivas de entrada
*	 	Há um ponteiro de ponteiro do tipo PECA_tppLista . Este aponta para um lugar desconhecido na memoria.
*	 	Há tambem uma variavel char que armazena a cor desejada da peça.
*
*  $EAS Assertivas de saída
*	    Caso falte memoria durante a criacao do peça, sera retornado uma peça com uma determinada cor.
*
*  $FV Valor retornado
*     PECA_CondRetOK    - criou o peça sem problema.
*	  PECA_CondRetFaltouMemoria -faltou memoria para criaçao da peça.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

   PECA_tpCondRet PECA_CriarPeca(PECA_tppLista *pLista,char cor);


/***********************************************************************
*
*  $FC Função: PECA  &Destruir peça
*
*  $ED Descrição da função
*     Destrói o Peça.

*  $EP Parâmetros
*     plista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descrição do módulo.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo PECA_tppLista . Este aponta para uma peça ou NULL.
*	 	
*  $EAS Assertivas de saída
*	   Caso exista uma peça que o ponterio aponte,essa peça será liberada.
*
*
*  $FV Valor retornado
*     PECA_CondRetOK    - destroi a peça sem problema.
*    
*     Não será dada mais informação quanto ao problema ocorrido.
***********************************************************************/

   PECA_tpCondRet PECA_DestruirPeca( PECA_tppLista pLista ) ;

/***************************************************************************
*
*  $FC Função: PECA &Obtercor da peça
*
*  $ED Descrição da função
*     Obtem a cor da peça.
*
*  $EP Parâmetros
*     plista  -    um ponteiro de tipo PECA_tppLista.
*                     Ver descrição do módulo.
*	  cor     -   um ponterio para char,em que armazena a cor da peça
*
*   $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo PECA_tppLista . Este aponta para uma peça ou para NULL.
*	 	Há tambem um ponteiro de caracter que aponta para um endereço memória que possui um caracter.
*
*  $EAS Assertivas de saída
*		Sera armazenada um caracter no endereço que o ponteiro *cor aponta.
*
*  $FV Valor retornado
*     PECA_CondRetOK    - criou o peça sem problema.
*	  PECA_CondRetPecaVazia -Nao existe a peça.
*     
*    
*     Não será dada mais informação quanto ao problema ocorrido.
*  *******************************************************************/

   PECA_tpCondRet PECA_ObterCor(PECA_tppLista pLista, char * cor);




#undef PECA_EXT
/********** Fim do módulo de definição: PECA **********/

#else
#endif