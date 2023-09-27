#include "ponto.h" // Inclui a definição do TAD Ponto.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *arquivo; // Ponteiro para o arquivo de entrada.
    int numVertices; // Número de vértices do polígono.
    char nomeArquivo[100]; // Nome do arquivo de entrada.
    float area = 0.0; // Variável para armazenar a área do polígono.

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r"); // Abre o arquivo de entrada para leitura.

    if (arquivo == NULL) { // Verifica se houve erro ao abrir o arquivo.
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Encerra o programa com código de erro.
    }

    fscanf(arquivo, "%d", &numVertices); // Lê o número de vértices do arquivo.
    Ponto vertices[numVertices]; // Declara um array de pontos para armazenar os vértices do polígono.

    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y); // Lê as coordenadas dos vértices.
    }

    fclose(arquivo); // Fecha o arquivo após a leitura.

    // Calcula a área do polígono usando a fórmula de Shoelace.
    for (int i = 0; i < numVertices - 1; i++) {
        area += (vertices[i].X * vertices[i + 1].Y) - (vertices[i + 1].X * vertices[i].Y);
    }

    area += (vertices[numVertices - 1].X * vertices[0].Y) - (vertices[0].X * vertices[numVertices - 1].Y);
    area = 0.5 * fabs(area); // Calcula o valor absoluto da área.

    printf("A área do polígono é %.2f\n", area); // Exibe a área calculada.

    return 0; // Encerra o programa com sucesso.
}

