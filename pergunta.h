#ifndef PERGUNTA_H
#define PERGUNTA_H

#define TAM_ENUNCIADO 256
#define TAM_ALTERNATIVA 100

typedef struct {
    char enunciado[TAM_ENUNCIADO];
    char alternativas[4][TAM_ALTERNATIVA];
    char correta; // 'A', 'B', 'C' ou 'D'
    int dificuldade; // 1 a 5
} Pergunta;

// Carregamento de dados
Pergunta* carregarCSV(const char *arquivo, int *total);
Pergunta* carregarBinario(const char *arquivo, int *total);
void salvarBinario(const char *arquivo, Pergunta *lista, int total);

// CRUD
Pergunta* inserirPergunta(Pergunta *lista, int *total);
void listarPerguntas(Pergunta *lista, int total);
void pesquisarPorNivel(Pergunta *lista, int total, int nivel);
void alterarPergunta(Pergunta *lista, int total);
Pergunta* excluirPergunta(Pergunta *lista, int *total);

// Exportar CSV
void exportarCSV(const char *arquivo, Pergunta *lista, int total);

#endif
