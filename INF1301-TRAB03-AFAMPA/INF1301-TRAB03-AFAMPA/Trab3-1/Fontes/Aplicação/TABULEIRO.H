#if ! defined( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD Módulo de definição: TAB  Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*
*  Projeto: INF 1301  Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Alessandro Faletti ,Alexandre Maxinsang ,Pedro Augusto
*
*
*  $ED Descrição do módulo
*     Implementa criaçao do tabuleiro.
*     Podem existir n tabuleiros em operação simultaneamente.
*     Os tabuleiros possuem uma cabeça encapsulando o seu estado.
*
*     Cada tabuleiro é homogênea quanto ao tipo dos dados que armazena.
*     Cada elemento do tabuleiro referencia o valor que contém.
*
*     Os ponteiros para os dados são copiados para elementos da lista.
*        Não é copiado o valor apontado por estes ponteiros.
*
*     O controle da destruição do valor de um elemento a ser excluído
*        é realizado por uma função fornecida pelo usuário.
*
*     Cada lista referencia uma função que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A função de liberação dos valores contidos nos elementos deve
*        assegurar a liberação de todos os espaços referênciados pelo
*        valor contido em um elemento.
*        Esta função é chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso não seja necessário desalocar o valor referenciado pelo
*        elemento, o ponteiro para a função de liberação poderá ser NULL .
*        Caso o elemento da lista seja a única âncora do valor referenciado,
*        esta função deve promover a destruição (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/
 
#if defined( TABULEIRO_OWN )
   #define TABULEIRO_EXT
#else
   #define TABULEIRO_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

typedef struct LIS_tagLista * TAB_tppLista ;

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da lista
*
***********************************************************************/

   typedef enum {

		TAB_CondRetOK ,
               /* Concluiu corretamente */

         TAB_CondRetFimTab ,
               /* Foi atingido o fim de lista */

         TAB_CondRetFaltouMemoria,
              /* Faltou memória ao tentar criar um elemento de lista */

		 TAB_CondRetListaVazia
			/* Lista vazia */
   } TAB_tpCondRet;

/***********************************************************************
*
*  $FC Função: TAB &Criar tabuleiro
*
*  $ED Descrição da função
*     Cria um tabuleiro.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     plista  -    um ponteiro de tipo de um ponteiro.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro de ponteiro do tipo TAB_tppLista . Este aponta para um lugar desconhecido na memoria.
*	 	Há tambem duas variaveis char que armazenam as cores desejadas das peças do tabuleiro.
*
*  $EAS Assertivas de saída
*	    Caso não falte memoria durante a criacao do tabuleiro, sera retornado um tabuleiro alocado.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - criou o tabuleiro sem problema.
*	  TAB_CondRetFaltouMemoria - faltou memória para alocar tabuleiro.
*
*     
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/
   
   
   TAB_tpCondRet  TAB_CriarTabuleiro(TAB_tppLista* pLista);


/***********************************************************************
*
*  $FC Função: TAB &Inserir Peca
*
*  $ED Descrição da função
*     Move uma peca de uma posição para outra.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     plista  -	um ponteiro de tipo de um ponteiro.
*	  cor_jogador -	um char da cor da peca a ser inserido.
*	  qtdpeca -	um inteiro da quantidade que se deseja inserir.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro que aponta para um tabuleiro .
*	 	Há tambem uma variavel char que armazena a cor da peça e uma outra variavel que armazena a quantidade de pecas a ser inserido.
*
*  $EAS Assertivas de saída
*	    Caso exista um tabuleiro,sera inserido uma nova peça no elemento corrente do tabuleiro a peça será inserido corretamente.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - Moveu a peca sem problema.
*
*     
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

   TAB_tpCondRet  TAB_InserirPeca(TAB_tppLista pLista,char cor_jogador,int qtdpeca);

/***********************************************************************
*
*  $FC Função: TAB  &Avancar Elemento Corrente
*
*  $ED Descrição da função
*     Avança o elemento corrente do tabuleiro .
*    
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro que aponta para um tabuleiro  .
*	 	
*  $EAS Assertivas de saída
*	   Caso exista um elementos nesse tabuleiro e se numElem>0, o elemento corrente avançará numElem elementos para fim da lista.
*      Se numElem<0,o elemento corrente avançará numElem elementos para o inicio da lista
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*	  TAB_CondRetFimLista- Fim da lista
*	  TAB_CondRetListaVazia- A lista dos valores de cada elemento do tabulç não contém elementos
***********************************************************************/

   TAB_tpCondRet TAB_AvancarElementoCorrente(TAB_tppLista pLista,int numElem );

/***********************************************************************
*
*  $FC Função: TAB  &Obter Cor No
*
*  $ED Descrição da função
*     Obtem o a cor da elemento corrente da lista de pecas do elemeneto corrente do tabuleiro .
*     O parâmetro ponteiro para a lista não é modificado.
*     Se ocorrer algum erro durante a destruição, a lista resultará
*     estruturalmente incorreta.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $EAE Assertivas de entrada
*	 	Há um dado do tipo TAB_tppLista . Este armazena para um tabuleiro.
*	 	Há um ponterio para char que aponta para um endereço desconhecido da memoria.
*
*  $EAS Assertivas de saída
*	   Caso o tabuleiro nao esteja vazia , o ponteiro cor aponta fara para um endereço de memoria que tenha o dado da cor da peça.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   TAB_tpCondRet TAB_ObterCorNo(TAB_tppLista pLista,char *cor );


/***********************************************************************
*
*  $FC Função: TAB  &Ir Tabuleiro
*
*  $ED Descrição da função
*     Faz com que o elemento corrente do tabuleiro a aponte para a origem da lista .
*     O parâmetro ponteiro para a lista não é modificado.
*     Se ocorrer algum erro durante a destruição, a lista resultará
*     estruturalmente incorreta.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $EAE Assertivas de entrada
*	 	Há um dado do tipo TAB_tppLista . Este armazena um tabuleiro .
*	 	
*  $EAS Assertivas de saída
*	   Caso exista um tabuleiro não vazio, o elemento corrente será o elemento da origem .
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   TAB_tpCondRet TAB_IrInicioTabuleiro(TAB_tppLista pLista);


/***********************************************************************
*
*  $FC Função: TAB  &Excluir Elem Tabuleiro
*
*  $ED Descrição da função
*    Excluir o elemento corrente da lista que percente ao elemento corrente da lista principal(tabuleiro).
*
*  $EAE Assertivas de entrada
*	 	Há um dado do tipo TAB_tppLista . Este armazena uma lista de tabuleiro .
*	 	
*  $EAS Assertivas de saída
*	   Caso exista o elemento corrente da lista que percente ao elemento corrente da lista principal , esse elemento será eliminado .
*
*  $FV Valor retornado
*     TAB_CondRetOK    - Excluiu o elemento sem problema.
***********************************************************************/


   TAB_tpCondRet TAB_ExcluirElemTabuleiro(TAB_tppLista pLista);



/***********************************************************************
*
*  $FC Função: TAB  &Imprime tabuleiro
*
*  $ED Descrição da função
*    Imprimi as peças da lista de peças que percentence a cada elemento da lista de tabuleiro
*
*  $EAE Assertivas de entrada
*	 	Há um dado do tipo TAB_tppLista . Este armazena uma lista de tabuleiro.
*	 	
*  $EAS Assertivas de saída
*	   Caso exista algum tabuleiro com peças, será imprimido as peças para cada nó da lista principal .
*
*  $FV Valor retornado
*     TAB_CondRetOK    - imprimi sem problemas
*
***********************************************************************/

   
   TAB_tpCondRet TAB_Imprime(TAB_tppLista pLista);


/***********************************************************************
*
*  $FC Função: TAB  &Destruir tabuleiro
*
*  $ED Descrição da função
*     Destrói o tabuleiro .
*     O parâmetro ponteiro para a lista não é modificado.
*     Se ocorrer algum erro durante a destruição, a lista resultará
*     estruturalmente incorreta.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $EAE Assertivas de entrada
*	 	Há um ponteiro do tipo TAB_tppLista . Este aponta para um tabuleiro ou NULL.
*	 	
*  $EAS Assertivas de saída
*	   Caso exista um tabuleiro que o ponteiro aponte, esse tabuleiro será liberado.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   void TAB_DestruirTabuleiro( TAB_tppLista pLista ) ;


   


#undef TABULEIRO_EXT
/********** Fim do módulo de definição: LIS  Lista duplamente encadeada **********/

#else
#endif
