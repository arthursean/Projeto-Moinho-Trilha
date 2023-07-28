#include <stdio.h>
#include <stdlib.h>

void abrirMapa(char mapa[][24])
{
    FILE *arquivo = fopen("mapa.txt", "r");
    for (int i = 0; i < 11; i++)
    {
        fscanf(arquivo, "%s", mapa[i]);
    }
    fclose(arquivo);
}
void imprimirMapa(char mapa[][24])
{
    for (int i = 0; i < 11; i++)
    {
        printf("%s\n", mapa[i]);
    }
}
int ehPosicaoValida(char mapa[][24], int l, int c)
{
    return mapa[l][c] == 'O';
}
void posicionamentoDasPecas(char mapa[][24], int vez)
{
    printf("Agora, vocês irão se alternar para posicionar suas peças nos pontos do tabuleiro\n");
    int l, c;
    scanf("%d %d", &l, &c);
    while (!ehPosicaoValida(mapa, l, c))
    {
        printf("Posicao inválida, por favor, escolha uma posicao válida\n");
        scanf("%d %d", &l, &c);
    }
    system("clear");
    mapa[l][c] = vez % 2 == 0 ? 'X' : 'Y';
    imprimirMapa(mapa);
}
int main()
{
    printf("Bem vindo(a) ao jogo do Moinho, para começar, escolha sua peça\n");
    char mapa[11][24];
    abrirMapa(mapa);
    int escolhaDeJogador = -1;
    while (escolhaDeJogador != 0 && escolhaDeJogador != 1)
    {
        system("clear");
        printf("0 - 'X'\n1 - 'Y'\n");
        printf("Obs: o 'X' começa primeiro\n");
        scanf("%d", &escolhaDeJogador);
    }
    system("clear");
    int vez = 0;
    while (vez < 18)
    {
        posicionamentoDasPecas(mapa, vez);
        vez += 1;
    }
    system("clear");
    imprimirMapa(mapa);
}