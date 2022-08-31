#include "ListaEncadeada.h"

ListaEncadeada* iniciaListaEncadeada() {
    ListaEncadeada* lista = new ListaEncadeada;
    lista->_primeiro = nullptr;
    lista->_quantidade = 0;
    return lista;
}

void destroiListaEncadeada(ListaEncadeada* umaLista) {
    while(umaLista->_quantidade > 0) {
        retiraDoInicio(umaLista);
    }

    delete umaLista;
}

bool listaVazia(ListaEncadeada* umaLista) {
    if(umaLista->_quantidade == 0) {
        return true;
    } else {
        return false;
    }
}

int posicao(ListaEncadeada* umaLista, void* umDado) {
    Elemento* e;
    e = umaLista->_primeiro;
    int contador = 1;

    for(int i=0;i<umaLista->_quantidade; i++) {
        if(e->_dado == umDado) {
            return contador;
        }
        e = e->_proximo;
        contador++;
    }

    return -1;
}

bool contem(ListaEncadeada* umaLista, void* umDado) {
    if(posicao(umaLista, umDado) != -1) {
        return true;
    } else {
        return false;
    }
}

void adicionaNoInicio(ListaEncadeada* umaLista, void* umDado) {
    Elemento* novo = new Elemento;

    if(novo != nullptr) {
        novo->_proximo = umaLista->_primeiro;
        novo->_dado = umDado;
        umaLista->_primeiro = novo;
        umaLista->_quantidade++;
    }

}

void adicionaNaPosicao(ListaEncadeada* umaLista, void* umDado, int umaPosicao) {
    Elemento* novo;
    Elemento* anterior;

    if(umaPosicao > umaLista->_quantidade + 1) {
        throw posicao_invalida_exception();
    } else {
        if(umaPosicao == 1){
            adicionaNoInicio(umaLista, umDado);
        } else {
            novo = new Elemento;
            if(novo != nullptr) {
                anterior = umaLista->_primeiro;
                for(int i = 0; i < umaPosicao - 2; i++) {
                    anterior = anterior->_proximo;
                }
                novo->_proximo = anterior->_proximo;
                novo->_dado = umDado;
                anterior->_proximo = novo;
                umaLista->_quantidade++;
            }
        }
    }
}

void adicionaNoFim(ListaEncadeada* umaLista, void* umDado) {
    adicionaNaPosicao(umaLista, umDado, umaLista->_quantidade + 1);
}

void* retiraDoInicio(ListaEncadeada* umaLista) {
    Elemento* saiu;
    void* volta;
    if(listaVazia(umaLista) == true) {
        throw lista_encadeada_vazia_exception();
    } else {
        saiu = umaLista->_primeiro;
        volta = saiu->_dado;
        umaLista->_primeiro = saiu->_proximo;
        umaLista->_quantidade--;
    }
    delete saiu;
    return volta;
}

void* retiraDaPosicao(ListaEncadeada* umaLista, int umaPosicao) {
    Elemento* eliminar = new Elemento;
    Elemento* anterior;
    void* volta;
    if(umaPosicao > umaLista->_quantidade) {
        throw posicao_invalida_exception();
    } else {
        if(umaPosicao == 1) {
            retiraDoInicio(umaLista);
        } else {
            anterior = umaLista->_primeiro;
            for(int i = 0; i < umaPosicao - 2; i++) {
                anterior = anterior->_proximo;
            }
            eliminar = anterior->_proximo;
            volta = eliminar->_dado;
            anterior->_proximo = eliminar->_proximo;
            umaLista->_quantidade--;
            return volta;
        }
        return nullptr;
    }
}

void* retiraDoFim(ListaEncadeada* umaLista) {
    return retiraDaPosicao(umaLista, umaLista->_quantidade);
}

void* retiraEspecifico(ListaEncadeada* umaLista, void* umDado) {
    int p = posicao(umaLista, umDado);
    if(p == -1) {
        throw posicao_invalida_exception();
    } else {
        return retiraDaPosicao(umaLista, p);
    }

}
