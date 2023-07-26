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
    for (int i = 0; i < 11; i++)
    {
        printf("%s\n", mapa[i]);
    }
}
int main()
{
    char mapa[11][24];
    abrirMapa(mapa);
}