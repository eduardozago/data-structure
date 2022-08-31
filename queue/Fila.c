#include "Fila.h"

Fila* iniciaFila() {
    Fila* f = new Fila;
    f->_primeiro = nullptr;
    f->_ultimo = nullptr;
    f->_quantidade = 0;
    return f;
}

void destroiFila(Fila* umaFila) {
    while(umaFila->_quantidade > 0) {
        dequeue(umaFila);
    }

    delete umaFila;
}

bool filaVazia(Fila* umaFila) {
    if(umaFila->_quantidade == 0) {
        return true;
    } else {
        return false;
    }
}

bool contem(Fila* umaFila, void* umDado) {
    if(posicao(umaFila, umDado) != -1) {
        return true;
    } else {
        return false;
    }
}

int posicao(Fila* umaFila, void* umDado) {
    Elemento* e;
    e = umaFila->_primeiro;
    int contador = 1;

    for(int i=0;i<umaFila->_quantidade; i++) {
        if(e->_dado == umDado) {
            return contador;
        }
        e = e->_proximo;
        contador++;
    }

    return -1;
}

void enqueue(Fila* umaFila, void* umDado) {
    Elemento* e = new Elemento;
    if(e == nullptr) {
        throw fila_vazia_exception();
    }

    if(filaVazia(umaFila) == true) {
        umaFila->_primeiro = e;
    } else {
        umaFila->_ultimo->_proximo = e;
    }

    e->_proximo = nullptr;
    e->_dado = umDado;
    umaFila->_ultimo = e;
    umaFila->_quantidade++;
}

void* dequeue(Fila* umaFila) {
    Elemento* saiu;
    void* volta;

    if(filaVazia(umaFila) == true) {
        throw fila_vazia_exception();
    } else {
        saiu = umaFila->_primeiro;
        volta = saiu->_dado;
        umaFila->_primeiro = saiu->_proximo;

        if(umaFila->_quantidade == 1) {
            umaFila->_ultimo = nullptr;
        }

        umaFila->_quantidade--;
        delete saiu;
        return volta;
    }
}
