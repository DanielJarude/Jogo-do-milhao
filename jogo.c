#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"

void embaralhar(int *vetor, int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void iniciarJogo(Pergunta *lista, int total) {
    int perguntasNecessarias[15] = {
        1, 1, // muito fácil
        2, 2, // fácil
        3, 3, 3, 3, // médio
        4, 4, 4, 4, // difícil
        5, 5, 5 // muito difícil
    };

    int acertou = 1;
    srand(time(NULL));

    for (int i = 0; i < 15 && acertou; i++) {
        int nivel = perguntasNecessarias[i];
        int indices[total], cont = 0;

        for (int j = 0; j < total; j++) {
            if (lista[j].dificuldade == nivel) {
                indices[cont++] = j;
            }
        }

        if (cont == 0) {
            printf("Não há perguntas do nível %d.\n", nivel);
            continue;
        }

        embaralhar(indices, cont);
        Pergunta p = lista[indices[0]];

        printf("\nPergunta %d - Nível %d\n", i+1, nivel);
        printf("%s\n", p.enunciado);
        for (int j = 0; j < 4; j++) {
            printf("%c) %s\n", 'A'+j, p.alternativas[j]);
        }

        char resposta;
        printf("Sua resposta: ");
        scanf(" %c", &resposta);

        if (resposta == p.correta) {
            printf("✅ Correto!\n");
        } else {
            printf("❌ Errado! Resposta certa: %c\n", p.correta);
            acertou = 0;
        }
    }

    if (acertou) {
        printf("🎉 Parabéns! Você venceu o jogo!\n");
    } else {
        printf("💥 Você perdeu. Tente novamente!\n");
    }
}
