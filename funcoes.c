#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "funcoespadroes.h"

void limparTela() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar(); // espera ENTER
}

void printColorido(const char* texto, const char* cor) {
    printf("%s%s%s", cor, texto, COR_RESET);
}

void tocarSom(int tipo) {
    switch (tipo) {
        case 1: printf("\a"); break; // beep simples (acerto)
        case 2: printf("\a\a"); break; // dois beeps (erro)
        case 3: printf("\a\a\a"); break; // três beeps (aviso)
        default: break;
    }
    fflush(stdout);
    #ifdef _WIN32
        Sleep(300);
    #else
        usleep(300000);
    #endif
}
