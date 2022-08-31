#include "Pilha.h"

Pilha* iniciaPilha() {
    return iniciaListaEncadeada();
}

void destroiPilha(Pilha* umaPilha) {
    destroiListaEncadeada(umaPilha);
}

bool pilhaVazia(Pilha* umaPilha) {
    if(listaVazia(umaPilha) == true) {
        return true;
    } else {
        return false;
    }
}

void* pop(Pilha* umaPilha) {
    return retiraDoInicio(umaPilha);
}

void push(Pilha* umaPilha, void* umDado){
    adicionaNoInicio(umaPilha, umDado);
}
