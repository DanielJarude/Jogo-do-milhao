#include <stdio.h>
#include <stdlib.h>
#include "pergunta.h"
#include "jogo.h"

#define ARQ_BINARIO "dados/perguntas.bin"
#define ARQ_CSV "dados/perguntas.csv"
#define ARQ_EXPORT "dados/exportado.csv"

int main() {
    Pergunta *lista = NULL;
    int total = 0;

    lista = carregarBinario(ARQ_BINARIO, &total);
    if (!lista) {
        printf("🔔 Bem-vindo ao jogo! Carregando perguntas do CSV...\n");
        lista = carregarCSV(ARQ_CSV, &total);
    }

    int opcao;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Jogar\n");
        printf("2. Inserir pergunta\n");
        printf("3. Listar perguntas\n");
        printf("4. Pesquisar por nível\n");
        printf("5. Alterar pergunta\n");
        printf("6. Excluir pergunta\n");
        printf("7. Exportar perguntas para CSV\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: iniciarJogo(lista, total); break;
            case 2: lista = inserirPergunta(lista, &total); break;
            case 3: listarPerguntas(lista, total); break;
            case 4: {
                int nivel;
                printf("Nível (1 a 5): ");
                scanf("%d", &nivel);
                pesquisarPorNivel(lista, total, nivel);
                break;
            }
            case 5: alterarPergunta(lista, total); break;
            case 6: lista = excluirPergunta(lista, &total); break;
            case 7: exportarCSV(ARQ_EXPORT, lista, total); break;
            case 0:
                salvarBinario(ARQ_BINARIO, lista, total);
                printf("✅ Dados salvos. Até logo!\n");
                break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    free(lista);
    return 0;
}
