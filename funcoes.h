#ifndef FUNCOES_PADROES_H
#define FUNCOES_PADROES_H

// Define códigos de cores ANSI para terminais que suportam
#define COR_RESET   "\x1b[0m"
#define COR_VERMELHO "\x1b[31m"
#define COR_VERDE    "\x1b[32m"
#define COR_AMARELO  "\x1b[33m"
#define COR_AZUL     "\x1b[34m"
#define COR_ROXO     "\x1b[35m"
#define COR_CIANO    "\x1b[36m"

void limparTela();
void pausar();
void printColorido(const char* texto, const char* cor);
void tocarSom(int tipo); // 1: acerto, 2: erro, 3: aviso

#endif
