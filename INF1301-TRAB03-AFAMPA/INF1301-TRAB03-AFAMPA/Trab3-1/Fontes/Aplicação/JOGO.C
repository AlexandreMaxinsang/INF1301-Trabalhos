/**************************************************************************************************
*
*	Módulo de Definição: Módulo JOGO
*
*	Nome do arquivo:		JOGO.C
*	Letras identificadoras	JOGO
*
*	Autores:   Alessandro Faletti,Alexandre Maxinsang,Pedro Augusto
*
*
*	Descrição do Módulo
*		Este módulo implementa conceitualmente  o jogo do gamao.
*		
*		O modulo possui funções para criação do jogo, destruição do jogo ,fazer uma jogada e savar o jogo , fazer o load de um jogo e imprimir a situação da partida
*
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

char jog1[250];
char jog2[250];

#define LISTA_OWN
#include "LISTA.H"
#undef LISTA_OWN

#define TABULEIRO_OWN
#include "TABULEIRO.H"
#undef TABULEIRO_OWN

#define DADO_OWN
#include "DADO.H"
#undef DADO_OWN

#define DADOPONTOS_OWN
#include "DADOPONTOS.H"
#undef DADOPONTOS_OWN

#define PECACAPTURADA_OWN
#include "PECACAPTURADA.H"
#undef PECACAPTURADA_OWN

#define PECAFINALIZADA_OWN
#include "PECAFINALIZADA.H"
#undef PECAFINALIZADA_OWN

/***********************************************************************
*
*  $TC Tipo de dados: JOGO 
*
*
***********************************************************************/
#define TRUE 1
#define FALSE 0
#define CONDFINAL 15

typedef struct JOGO_tagElemJogo {

	DP_tppDadoPontos		PontosPartida;

	PECACAPTURADA_tppLista	PecCap_player1;

	PECACAPTURADA_tppLista	PecCap_player2;

	TAB_tppLista				Tabuleiro;

	PECAFINALIZADA_tppLista	PecFin_player1;

	PECAFINALIZADA_tppLista	PecFin_player2;

} JOGO_tpElemJogo;

typedef struct JOGO_tagElemJogo* JOGO_tppJogo;




int Jogo_CondicaoFinalizar(JOGO_tppJogo pJogo,PECAFINALIZADA_tppLista PecFin_jogador,char player);
int JOGO_ExistePecaDoTipo(JOGO_tppJogo pJogo,char cor);


/***************************************************************************
*
*  Função: JOGO  &Criar JOGO
*
*
*  ***********************************************************************/

JOGO_tppJogo JOGO_CriarJogo()
{
	JOGO_tpElemJogo * Novo;
	void *aux[1];

	Novo=(JOGO_tpElemJogo *)malloc(sizeof(JOGO_tpElemJogo));
	if(Novo==NULL)
	{	
		printf("Faltou memória \n");
		exit(1);
	}

	DP_Cria((DP_tppDadoPontos*)aux);
	Novo->PontosPartida=(DP_tppDadoPontos)aux[0];
	aux[0]=NULL;

	PECACAPTURADA_CriarPecaCapturada((PECACAPTURADA_tppLista*)aux);
	Novo->PecCap_player1=(PECACAPTURADA_tppLista)aux[0];
	aux[0]=NULL;

	PECACAPTURADA_CriarPecaCapturada((PECACAPTURADA_tppLista*)aux);
	Novo->PecCap_player2=(PECACAPTURADA_tppLista)aux[0];
	aux[0]=NULL;

	TAB_CriarTabuleiro((TAB_tppLista*)aux);
	Novo->Tabuleiro=(TAB_tppLista)aux[0];
	aux[0]=NULL;

	PECAFINALIZADA_CriarPecaFinalizada((PECAFINALIZADA_tppLista*)aux);
	Novo->PecFin_player1=(PECAFINALIZADA_tppLista)aux[0];
	aux[0]=NULL;

	PECAFINALIZADA_CriarPecaFinalizada((PECAFINALIZADA_tppLista*)aux);
	Novo->PecFin_player2=(PECAFINALIZADA_tppLista)aux[0];
	aux[0]=NULL;


	return Novo;


} /* Fim função: JOGO  &Criar jogo */


/***************************************************************************
*
*  Função: JOGO  &Inciar JOGO
*
*  ***********************************************************************/
void JOGO_InciarJogo(JOGO_tppJogo pJogo)
{

	TAB_IrInicioTabuleiro(pJogo->Tabuleiro);
	TAB_InserirPeca(pJogo->Tabuleiro,'p',2);

	TAB_AvancarElementoCorrente(pJogo->Tabuleiro,5);
	TAB_InserirPeca(pJogo->Tabuleiro,'b',5);

	TAB_AvancarElementoCorrente(pJogo->Tabuleiro,2);
	TAB_InserirPeca(pJogo->Tabuleiro,'b',3);

	TAB_AvancarElementoCorrente(pJogo->Tabuleiro,4);
	TAB_InserirPeca(pJogo->Tabuleiro,'p',5);

	TAB_AvancarElementoCorrente(pJogo->Tabuleiro,1);
	TAB_InserirPeca(pJogo->Tabuleiro,'b',5);

	TAB_AvancarElementoCorrente(pJogo->Tabuleiro,4);
	TAB_InserirPeca(pJogo->Tabuleiro,'p',3);

	TAB_AvancarElementoCorrente(pJogo->Tabuleiro,2);
	TAB_InserirPeca(pJogo->Tabuleiro,'p',5);

	TAB_AvancarElementoCorrente(pJogo->Tabuleiro,5);
	TAB_InserirPeca(pJogo->Tabuleiro,'b',2);
}


/***************************************************************************
*
*  Função: JOGO  &Destruir jogo
*
*
*  ***************************************************************************/
void JOGO_DestruirJogo(JOGO_tppJogo pJogo)
{
	DP_DestruirPonto( pJogo->PontosPartida);

	PECACAPTURADA_DestruirPeca(pJogo->PecCap_player1);

	PECACAPTURADA_DestruirPeca(pJogo->PecCap_player2);

	TAB_DestruirTabuleiro(pJogo->Tabuleiro);

	PECAFINALIZADA_DestruirPeca(pJogo->PecFin_player1);

	PECAFINALIZADA_DestruirPeca(pJogo->PecFin_player2);

	free(pJogo);

}

/***************************************************************************
*
*  Função: JOGO  &Existe Peca Do Tipo
*
*
*  ***************************************************************************/
int JOGO_ExistePecaDoTipo(JOGO_tppJogo pJogo,char cor)
{
	char corobtida;
	TAB_ObterCorNo(pJogo->Tabuleiro, &corobtida );
	if(cor==corobtida && corobtida !='\0' )
		return TRUE;

	return FALSE;
}/* Fim função: JOGO  &Destruir jogo */



/***************************************************************************
*
*  Função: Jogo  &Imprime
*
*  ***************************************************************************/

void Jogo_Imprime(JOGO_tppJogo pJogo, int dado1, int dado2, char cor_player)
{
	int ponto;
	system("cls");
	TAB_Imprime(pJogo->Tabuleiro);
	printf("\n\nDado1: %d", dado1);
	printf("\nDado2: %d\n\n", dado2);

	printf("\n\n");
	if(cor_player=='p')
	{
		printf("\n--------------------------------\n");
		printf("RODADA DO JOGADOR 1 -- %s  ", jog1);
		printf("\n--------------------------------\n");
	}
	else
	{
		printf("\n--------------------------------\n");
		printf("RODADA DO JOGADOR 2 -- %s ", jog2);
		printf("\n--------------------------------\n");
	}

}/*FIM :Jogo  &Imprime */


/***************************************************************************
*
*  Função: Jogo &Load
*
*  ***************************************************************************/

int Jogo_Load(JOGO_tppJogo pJogo, char *jogador1, char *jogador2, int *NewGame)
{
	
	FILE *fp;
	int qtd, cont, pontos, jog;
	char cor, save[100];

	printf("Digite o nome do save(arquivo): ");
	scanf("%s", save);

	fp = fopen (save, "r");
	if (fp == NULL) {
		return 0;
	}

	*NewGame=FALSE;

	TAB_IrInicioTabuleiro(pJogo->Tabuleiro);

	for(cont=0;cont<24;cont++)
	{
		fscanf(fp, "%d\n", &qtd);
		fscanf(fp, "%c\n", &cor);
					
		if(qtd!=0)
		{
			TAB_InserirPeca(pJogo->Tabuleiro,cor,qtd);
		}
		TAB_AvancarElementoCorrente(pJogo->Tabuleiro,1);
	}

	fscanf(fp, "%d\n", &qtd);
	fscanf(fp, "%c\n", &cor);
	cont=0;
	while(cont<qtd)
	{
		PECAFINALIZADA_InserirPecaFinalizada(pJogo->PecFin_player1, cor);
		cont++;
	}

	fscanf(fp, "%d\n", &qtd);
	fscanf(fp, "%c\n", &cor);
	cont=0;
	while(cont<qtd)
	{
		PECAFINALIZADA_InserirPecaFinalizada(pJogo->PecFin_player2, cor);
		cont++;
	}

	fscanf(fp, "%d\n", &qtd);
	fscanf(fp, "%c\n", &cor);
	cont=0;
	while(cont<qtd)
	{
		PECACAPTURADA_InserirPecaCapturada(pJogo->PecCap_player1, cor);
		cont++;
	}

	fscanf(fp, "%d\n", &qtd);
	fscanf(fp, "%c\n", &cor);
	cont=0;
	while(cont<qtd)
	{
		PECACAPTURADA_InserirPecaCapturada(pJogo->PecCap_player2, cor);
		cont++;
	}

	fscanf(fp, "%c\n", jogador1);
	fscanf(fp, "%c\n", jogador2);

	fscanf(fp, "%d\n", &pontos);
	fscanf(fp, "%d\n", &jog);

	fscanf(fp, "%s\n", jog1);
	fscanf(fp, "%s\n", jog2);

	DP_Adiciona(pJogo->PontosPartida, pontos, jog);

	printf("\nJogo carregado com sucesso!\n");
	fclose(fp);

	return 1;

}/*FIM :Jogo  &Load */



/***************************************************************************
*
*  Função: Jogo  &Save
*
*  ***************************************************************************/

void Jogo_Save(JOGO_tppJogo pJogo, char jogador1, char jogador2)
{
	
	int qtd=0, cont=0, ponto=0, jog=0;
	char save[100];
	char cor='\0';
	FILE *fp;

	printf("Digite o nome do save(arquivo): ");
	scanf("%s", save);

	fp = fopen (save, "w");
	if (fp == NULL) {
		printf ("Houve um erro ao abrir o arquivo.\n");
		exit(1);
	}
	IrInicioLista(pJogo->Tabuleiro);
	for(cont=0;cont<24;cont++)
	{
		TAB_ObterCorNo(pJogo->Tabuleiro, &cor);
		QtdElemento((TAB_tppLista)LIS_ObterValor(pJogo->Tabuleiro), &qtd);
		fprintf(fp, "%d\n", qtd);
		if(cor == NULL)
			fprintf(fp, "x\n");
		else
			fprintf(fp, "%c\n", cor);
		TAB_AvancarElementoCorrente(pJogo->Tabuleiro, 1);
	}

	PECAFINALIZADA_QuantidadePecaFinalizada(pJogo->PecFin_player1, &qtd);
	fprintf(fp, "%d\n", qtd);
	fprintf(fp, "%c\n", 'p');

	PECAFINALIZADA_QuantidadePecaFinalizada(pJogo->PecFin_player2, &qtd);
	fprintf(fp, "%d\n", qtd);
	fprintf(fp, "%c\n", 'b');

	PECACAPTURADA_QuantidadePecaCapturada(pJogo->PecCap_player1, &qtd);
	fprintf(fp, "%d\n", qtd);
	fprintf(fp, "%c\n", 'p');

	PECACAPTURADA_QuantidadePecaCapturada(pJogo->PecCap_player2, &qtd);
	fprintf(fp, "%d\n", qtd);
	fprintf(fp, "%c\n", 'b');

	fprintf(fp, "%c\n", jogador1);
	fprintf(fp, "%c\n", jogador2);

	DP_ObterPonto(pJogo->PontosPartida, &ponto);
	fprintf(fp, "%d\n", ponto);

	DP_ObterJogador(pJogo->PontosPartida, &jog);
	fprintf(fp, "%d\n", jog);

	fprintf(fp, "%s\n", jog1);

	fprintf(fp, "%s\n", jog2);

	printf("\nJogo salvo com sucesso!\n");
	fclose(fp);

}/*FIM :Jogo  &Save */


/***************************************************************************
*
*  Função: Jogo  &DobraPts
*
*  ***************************************************************************/

void Jogo_DobraPts(JOGO_tppJogo pJogo, char jogador1)
{
	
	int h=-1;
	if(jogador1=='p')
	{
		h = DP_Dobra(pJogo->PontosPartida, 1);
	}
	else if (jogador1=='b')
	{
		h = DP_Dobra(pJogo->PontosPartida, 2);
	}

	system("cls");

	if(h==0)
	{
		if(jogador1=='p')
			printf("\nPontos dobrados com sucesso pelo jogador 1!\n");
		else
			printf("\nPontos dobrados com sucesso pelo jogador 2!\n");
	}
	else
	{
		printf("Nao e sua vez de dobrar a partida!\n");
	}

}/*FIM :Jogo  &DobraPts */




/***************************************************************************
*
*  Função: JOGO  &Fazer jogada
*
*  *************************************************************************/
int JOGO_FazerJogada(JOGO_tppJogo pJogo,char cor_player,char cor_adversario,PECACAPTURADA_tppLista PecCap_player,PECAFINALIZADA_tppLista PecFin_player)
{
	int dado1,dado2,dado1_aux,dado2_aux,dado_resultante;
	int qtdandar,peca1,peca2;
	int Opçaovalida=FALSE;
	int qtdpecacap,qtdinimiga,qtdfinalizada,inicial;
	int cond2, flag=0;
	char cor;
	TAB_tpCondRet Cond;
	PECACAPTURADA_tppLista Adversario;

	DADO_GeraValor(&dado1); 
	DADO_GeraValor(&dado2); 

	QtdElemento(PecCap_player,&qtdpecacap);
	if(pJogo->PecCap_player1==PecCap_player)
		Adversario=pJogo->PecCap_player2;
	else
		Adversario=pJogo->PecCap_player1;


	if(cor_player=='p')
	{
		inicial=0;
		dado1_aux=dado1;
		dado2_aux=dado2;
	}
	else
	{
		inicial=24;
		dado1_aux=-dado1;
		dado2_aux=-dado2;
	}

	Jogo_Imprime(pJogo,dado1,dado2,cor_player);

	if(dado1==dado2)
		dado_resultante=2*(dado1+dado2);
	else
		dado_resultante=(dado1+dado2);
	

	if(qtdpecacap>=2)
	{
		while(dado_resultante>0)
		{
			Opçaovalida=FALSE;
			while(Opçaovalida==FALSE)
			{
				printf("Existe pecas capturas\n");
				printf("Quanto que  peca caturada vai andar? \n");
				scanf("%d",&qtdandar);
				if(dado1==dado2)
					cond2=(qtdandar%dado1==0 && qtdandar>=dado1 && qtdandar<=dado_resultante);
				else
					cond2=(dado_resultante-qtdandar==dado1 || dado_resultante-qtdandar==dado2 || dado_resultante-qtdandar==0);

				switch(cond2)
				{

				case 1:
					{
						TAB_IrInicioTabuleiro( pJogo->Tabuleiro);
						if(cor_player=='p')
							TAB_AvancarElementoCorrente( pJogo->Tabuleiro,inicial+qtdandar-1);
						else
							TAB_AvancarElementoCorrente( pJogo->Tabuleiro,inicial-qtdandar);

						TAB_ObterCorNo(pJogo->Tabuleiro,&cor);
						if(cor==cor_player || cor=='\0')
						{
							TAB_InserirPeca(pJogo->Tabuleiro,cor_player,1);
							PECACAPTURADA_RetirarPecaCapturada(PecCap_player);
							dado_resultante-=qtdandar;
							Jogo_Imprime(pJogo,dado1,dado2,cor_player);
							printf("Movimento concluido\n");
						}
						else
						{
							QtdElemento((LIS_tppLista)LIS_ObterValor(pJogo->Tabuleiro),&qtdinimiga);
							if(qtdinimiga==1)
							{
								TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
								PECACAPTURADA_InserirPecaCapturada(Adversario,cor_adversario);
								dado_resultante-=qtdandar;
								Jogo_Imprime(pJogo,dado1,dado2,cor_player);
								printf("Capturou uma peca adversaria\n");
							}
							else
							{
								printf("Existe mais de uma peca adversaria,mova outra peca\n");
								break;
							}
						}
						Opçaovalida=TRUE;
						break;

					}
				default:
					printf("Opcao Invalida \n");
				}
			}
		}

	}
	else
	{
		if(qtdpecacap==1)
		{
			while(Opçaovalida==FALSE)
			{
				printf("Quanto a peca capturada deve ser movimentada? \n");
				scanf("%d",&qtdandar);
				if(dado1==dado2)
					cond2=(qtdandar%dado1==0 && qtdandar>=dado1 && qtdandar<=dado_resultante);
				else
					cond2=(dado_resultante-qtdandar==dado1 || dado_resultante-qtdandar==dado2 || dado_resultante-qtdandar==0);

				switch(cond2)
				{
				case 1:
					{
						TAB_IrInicioTabuleiro( pJogo->Tabuleiro);

						if(cor_player=='p')
							TAB_AvancarElementoCorrente( pJogo->Tabuleiro,inicial+qtdandar-1);
						else
							TAB_AvancarElementoCorrente( pJogo->Tabuleiro,inicial-qtdandar);

						TAB_ObterCorNo(pJogo->Tabuleiro,&cor);

						if(cor==cor_player || cor=='\0')
						{
							TAB_InserirPeca(pJogo->Tabuleiro,cor_player,1);
							PECACAPTURADA_RetirarPecaCapturada(PecCap_player);
							dado_resultante-=qtdandar;
							Jogo_Imprime(pJogo,dado1,dado2,cor_player);
							printf("Movimento concluido\n");
						}
						else
						{
							QtdElemento((LIS_tppLista)LIS_ObterValor(pJogo->Tabuleiro),&qtdinimiga);
							if(qtdinimiga==1)
							{
								TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
								PECACAPTURADA_InserirPecaCapturada(Adversario,cor_adversario);
								TAB_InserirPeca(pJogo->Tabuleiro,cor_player,1);
								dado_resultante-=qtdandar;
								Jogo_Imprime(pJogo,dado1,dado2,cor_player);
								printf("Capturou uma peca adversaria\n");
							}
							else
							{
								printf("Existe mais de uma peca adversaria,faca outro movimento\n ");
								break;

							}
						}

						while(dado_resultante>0)
						{
							Opçaovalida=FALSE;
							while(Opçaovalida==FALSE)
							{
								printf("Qual peca a ser movimentada do tabuleiro?<1-24>\n");
								scanf("%d",&peca1);

								TAB_IrInicioTabuleiro( pJogo->Tabuleiro);
								Cond=TAB_AvancarElementoCorrente( pJogo->Tabuleiro,peca1-1);
								cond2=((peca1>=1 && peca1<=24) && JOGO_ExistePecaDoTipo(pJogo,cor_player));
								switch (cond2)
								{
								case 1:
									{
										printf("Quanto essa peca deve ser movimentada? \n");
										scanf("%d",&qtdandar);
										if(dado1==dado2)
											cond2=(qtdandar%dado1==0 && qtdandar>=dado1 && qtdandar<=dado_resultante);
										else
											cond2=(dado_resultante-qtdandar==dado1 || dado_resultante-qtdandar==dado2 || dado_resultante-qtdandar==0);
										switch(cond2)
										{

										case 1:
											{
												TAB_IrInicioTabuleiro( pJogo->Tabuleiro);
												if(cor_player=='p')
													TAB_AvancarElementoCorrente( pJogo->Tabuleiro,peca1+qtdandar-1);
												else
													TAB_AvancarElementoCorrente( pJogo->Tabuleiro,peca1-qtdandar-1);
												if(Cond==TAB_CondRetFimTab && Jogo_CondicaoFinalizar(pJogo,PecFin_player,cor_player)==TRUE)
												{
													TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
													PECAFINALIZADA_InserirPecaFinalizada(PecFin_player,cor_player);
													QtdElemento(PecFin_player,&qtdfinalizada);
													dado_resultante-=qtdandar;
													if(qtdfinalizada==CONDFINAL)
														return 1;//venceu
													Jogo_Imprime(pJogo,dado1,dado2,cor_player);
													printf("Uma peca finalizada\n");
												}
												else
												{
													if((Cond==TAB_CondRetFimTab))
													{
														printf("Condicao de finalizar ainda nao foi satisfeita, mova outra peca \n");
														break;
													}

													TAB_ObterCorNo(pJogo->Tabuleiro,&cor);
													if(cor==cor_player || cor=='\0')
													{
														TAB_InserirPeca(pJogo->Tabuleiro,cor_player,1);
														if(cor_player=='p')
															TAB_AvancarElementoCorrente( pJogo->Tabuleiro,-qtdandar);
														else
															TAB_AvancarElementoCorrente( pJogo->Tabuleiro,qtdandar);
														TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
														dado_resultante-=qtdandar;
														Jogo_Imprime(pJogo,dado1,dado2,cor_player);
														printf("Movimento concluido\n");
													}
													else
													{
														QtdElemento((LIS_tppLista)LIS_ObterValor(pJogo->Tabuleiro),&qtdinimiga);
														if(qtdinimiga==1)
														{
															TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
															TAB_InserirPeca(pJogo->Tabuleiro,cor_player,1);
															if(cor_player=='p')
																TAB_AvancarElementoCorrente( pJogo->Tabuleiro,-qtdandar);
															else
																TAB_AvancarElementoCorrente( pJogo->Tabuleiro,qtdandar);
															TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
															PECACAPTURADA_InserirPecaCapturada(Adversario,cor_adversario);
															dado_resultante-=qtdandar;
															Jogo_Imprime(pJogo,dado1,dado2,cor_player);
															printf("Capturou uma peca adversaria\n");
														}
														else
														{
															printf("Nao consegue mover a peca, mova outra peca\n");
															break;
														}

													}
												}

												Opçaovalida=TRUE;
												break;
											}
										default:
											printf("Opcao invalida\n");

										}///termina o switch de dentro

										Opçaovalida=TRUE;		
										break;
									}
								default:
									printf("Opcao invalida\n");
								}/// termina o switch de fora
							}

						}
						Opçaovalida=TRUE;		
						break;
					}
				default:
					printf("Opcao invalida\n");
				}
			}
		}
		else
		{
			while(dado_resultante>0)
			{
				Opçaovalida=FALSE;
				while(Opçaovalida==FALSE)
				{
					printf("Qual peca a ser movimentada do tabuleiro?<1-24>\n");
					scanf("%d",&peca1);

					TAB_IrInicioTabuleiro( pJogo->Tabuleiro);
					TAB_AvancarElementoCorrente( pJogo->Tabuleiro,peca1-1);
					cond2=((peca1>=1 && peca1<=24) && JOGO_ExistePecaDoTipo(pJogo,cor_player));
					switch (cond2)
					{
					case 1:
						{
							printf("Quanto essa peca deve ser movimentada? \n");
							scanf("%d",&qtdandar);
							if(dado1==dado2)
								cond2=(qtdandar%dado1==0 && qtdandar>=dado1 && qtdandar<=dado_resultante);
							else
								cond2=(dado_resultante-qtdandar==dado1 || dado_resultante-qtdandar==dado2 || dado_resultante-qtdandar==0);
							switch(cond2)
							{

							case 1:
								{
									TAB_IrInicioTabuleiro( pJogo->Tabuleiro);
									if(cor_player=='p')
										Cond=TAB_AvancarElementoCorrente( pJogo->Tabuleiro,peca1+qtdandar-1);
									else
										Cond=TAB_AvancarElementoCorrente( pJogo->Tabuleiro,peca1-qtdandar-1);
									if(Cond==TAB_CondRetFimTab && Jogo_CondicaoFinalizar(pJogo,PecFin_player,cor_player)==TRUE)
									{
										TAB_IrInicioTabuleiro( pJogo->Tabuleiro);
										TAB_AvancarElementoCorrente( pJogo->Tabuleiro,peca1-1);
										TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
										PECAFINALIZADA_InserirPecaFinalizada(PecFin_player,cor_player);
										QtdElemento(PecFin_player,&qtdfinalizada);
										dado_resultante-=qtdandar;
										if(qtdfinalizada==CONDFINAL)
											return 1;//venceu
										Jogo_Imprime(pJogo,dado1,dado2,cor_player);
										printf("Uma peca finalizada\n");
									}
									else
									{
										if((Cond==TAB_CondRetFimTab))
										{
											printf("Condicao de finalizar ainda nao foi satisfeita, mova outra peca \n");
											break;
										}

										TAB_ObterCorNo(pJogo->Tabuleiro,&cor);
										if(cor==cor_player || cor=='\0')
										{
											TAB_InserirPeca(pJogo->Tabuleiro,cor_player,1);
											if(cor_player=='p')
												TAB_AvancarElementoCorrente( pJogo->Tabuleiro,-qtdandar);
											else
												TAB_AvancarElementoCorrente( pJogo->Tabuleiro,qtdandar);
											TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
											dado_resultante-=qtdandar;
											Jogo_Imprime(pJogo,dado1,dado2,cor_player);
											printf("Movimento concluido\n");
										}
										else
										{
											QtdElemento((LIS_tppLista)LIS_ObterValor(pJogo->Tabuleiro),&qtdinimiga);
											if(qtdinimiga==1)
											{
												TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
												TAB_InserirPeca(pJogo->Tabuleiro,cor_player,1);
												if(cor_player=='p')
													TAB_AvancarElementoCorrente( pJogo->Tabuleiro,-qtdandar);
												else
													TAB_AvancarElementoCorrente( pJogo->Tabuleiro,qtdandar);
												TAB_ExcluirElemTabuleiro(pJogo->Tabuleiro);
												PECACAPTURADA_InserirPecaCapturada(Adversario,cor_adversario);
												dado_resultante-=qtdandar;
												Jogo_Imprime(pJogo,dado1,dado2,cor_player);
												printf("Capturou uma peca adversaria\n");
											}
											else
											{
												printf("Nao consegue mover a peca, mova outra peca\n");
												break;
											}

										}
									}

									Opçaovalida=TRUE;
									break;
								}
							default:
								printf("Opcao invalida\n");

							}///termina o switch de dentro

							Opçaovalida=TRUE;		
							break;
						}
					default:
						printf("Opcao invalida\n");
					}/// termina o switch de fora
				}

			}

		}
	}
	return 0;
}/* Fim função: JOGO  &Fazer Jogado */

/***************************************************************************
*
*  Função: Jogo  &Condiçao finalizar
*
*  ***************************************************************************/

int Jogo_CondicaoFinalizar(JOGO_tppJogo pJogo,PECAFINALIZADA_tppLista PecFin_jogador,char player)
{
	int i=0,qtd=0,soma=0;
	char cor;
	TAB_IrInicioTabuleiro(pJogo->Tabuleiro);
	if(player=='p')
		TAB_AvancarElementoCorrente(pJogo->Tabuleiro,18);

	while(i<=5)
	{
		TAB_ObterCorNo(pJogo->Tabuleiro,&cor);
		if(cor==player)
		{
			QtdElemento((LIS_tppLista)LIS_ObterValor(pJogo->Tabuleiro),&qtd);
			soma+=qtd;
		}
		TAB_AvancarElementoCorrente(pJogo->Tabuleiro,1);
		i++;
	}
	QtdElemento(PecFin_jogador,&qtd);
	soma+=qtd;

	if(soma==CONDFINAL)
		return TRUE;
	else
		return FALSE;
}/*FIM :Jogo  &Condiçao finalizar */



int main(void)
{
	JOGO_tppJogo pJogo;
	int qtdpecasfinalizadas_player1,qtdpecasfinalizadas_player2;
	char player1='p';
	char player2='b';
	char jogador1,jogador2;
	PECACAPTURADA_tppLista PecCap_jogador;
	PECAFINALIZADA_tppLista PecFin_jogador;
	int OpecaoValida=FALSE, NewGame=TRUE;

	int op=-1, op2=-1;

	system ("color 1A");

	while(op!=3)
	{
		printf("-----------GAMAO-----------\n");
		printf("1-New Game\n");
		printf("2-Load Game\n");
		printf("3-Exit\n");
		printf("---------------------------\n");
		scanf("%d", &op);
		if(op==1 || op==2)
		{
			system("cls");
			pJogo=JOGO_CriarJogo();

			jogador1=player1;
			jogador2=player2;

			if(op==2)
			{
				int cond=-1;
				cond = Jogo_Load(pJogo, &jogador1, &jogador2, &NewGame);
				if(cond == 0)
				{
					JOGO_InciarJogo(pJogo);
					NewGame=TRUE;
					printf ("\nHouve um erro ao abrir o save. Iniciando um novo jogo.\nAperte 'Enter' para continuar.\n");
					getchar();
					getchar();
				}
			}
			else
			{
				JOGO_InciarJogo(pJogo);
			}

			if(NewGame==TRUE)
			{
				int dado1, dado11, dado2, dado22;

				printf("\nDigite seu nome jogador 1: ");
				scanf("%s", jog1);
				printf("\nDigite seu nome jogador 2: ");
				scanf("%s", jog2);

				do
				{
					DADO_GeraValor(&dado1);
					DADO_GeraValor(&dado11);
					DADO_GeraValor(&dado2);
					DADO_GeraValor(&dado22);
					system("cls");

					printf("\nJogador 1 jogou os dados e obteve os valores: %d, %d \n", dado1, dado11);
					printf("\nJogador 2 jogou os dados e obteve os valores: %d, %d \n", dado2, dado22);

				}
				while( (dado1+dado11) == (dado2+dado22) );

				if((dado1+dado11) > (dado2+dado22))
				{
					printf("\nJogador 1 comeca jogando!\n");
				}
				else
				{
					jogador1=player2;
					jogador2=player1;
					printf("\nJogador 2 comeca jogando!\n");
				}
			}

			NewGame=TRUE;

			QtdElemento(pJogo->PecFin_player1,&qtdpecasfinalizadas_player1);
			QtdElemento(pJogo->PecFin_player2,&qtdpecasfinalizadas_player2);

			if(jogador1=='p')
			{
				PecCap_jogador=pJogo->PecCap_player1;
				PecFin_jogador=pJogo->PecFin_player1;
			}
			else
			{
				PecCap_jogador=pJogo->PecCap_player2;
				PecFin_jogador=pJogo->PecFin_player2;
			}

			TAB_Imprime(pJogo->Tabuleiro);

			while(op2!=4)
			{
				int ponto;

				DP_ObterPonto(pJogo->PontosPartida, &ponto);
				printf("\nPONTUACAO DA PARTIDA: %d\n\n", ponto);

				printf("\n-----------GAMAO-----------\n");
				printf("1-Fazer Jogada\n");
				printf("2-Salvar Jogo\n");
				printf("3-Dobrar pontos da partida\n");
				printf("4-Voltar para o Menu\n");
				printf("---------------------------\n");

				printf("\n\n %c Jogador 1 tem a peca da cor preta\n %c Jogador 2 tem a peca da cor branca \n", 1, 2);

				printf("\n\n");
				if(jogador1==player1)
				{
					printf("\n--------------------------------\n");
					printf("RODADA DO JOGADOR 1 -- %s  ", jog1);
					printf("\n--------------------------------\n");
				}
				else
				{
					printf("\n--------------------------------\n");
					printf("RODADA DO JOGADOR 2 -- %s ", jog2);
					printf("\n--------------------------------\n");
				}

				scanf("%d", &op2);

				if(op2==1)
				{
					int venceu=0;

					venceu=JOGO_FazerJogada(pJogo,jogador1,jogador2,PecCap_jogador,PecFin_jogador);

					if(PecFin_jogador==pJogo->PecFin_player1)
						PecFin_jogador=pJogo->PecFin_player2;
					else
						PecFin_jogador=pJogo->PecFin_player1;

					if(PecCap_jogador==pJogo->PecCap_player1)
						PecCap_jogador=pJogo->PecCap_player2;
					else
						PecCap_jogador=pJogo->PecCap_player1;

					if(jogador1==player1)
						jogador1=player2;
					else
						jogador1=player1;

					if(jogador2==player1)
						jogador2=player2;
					else
						jogador2=player1;

					if(venceu==1)
					{
						if(jogador1==player1)
							printf("\nPARABENS, O %s VENCEU!\n", jog2);
						else
							printf("\nPARABENS, O %s VENCEU!\n", jog1);
						
						printf("Aperte 'enter' para voltar ao menu.");

						getchar();
						getchar();
						op2=4;
					}

					printf("\nAperte enter para continuar...\n");
					getchar();
					getchar();
					system("cls");
				}
				else if(op2==2)
				{
					system("cls");
					Jogo_Save(pJogo, jogador1, jogador2);
				}
				else if(op2==3)
				{
					
					Jogo_DobraPts(pJogo, jogador1);

				}
				else if(op2==4)
				{
					system("cls");
					JOGO_DestruirJogo(pJogo);
				}
				else
				{
					system("cls");
				}
			}
			op2=-1;
		}
		else
		{
			system("cls");
		}
	}
	return 0;
}