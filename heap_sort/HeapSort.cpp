#include "AbstractSort.h"
#include <math.h>

//implemente AQUI as funcoes sort e max_heapify do HeapSort
//você DEVE utilizar a função swap para trocar dois elementos de posição

void sort(Elemento** umVetor, int quantidadeDeElementos){
    construirHeapMax(umVetor, quantidadeDeElementos);

    for(int i = quantidadeDeElementos - 1; i > 0; i--){
        swap(0, i, umVetor);
        max_heapify(umVetor, i, 0);
    }
}

void max_heapify(Elemento ** umVetor, int quantidadeDeElementos, int i){
    if(i >= quantidadeDeElementos || i < 0) {
        throw posicao_invalida_exception();
    }

    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int max = i;

    if(left < quantidadeDeElementos && umVetor[left]->_chave > umVetor[i]->_chave) {
        max = left;
    }

    if(right < quantidadeDeElementos && umVetor[right]->_chave > umVetor[max]->_chave) {
        max = right;
    }

    if(max != i) {
        swap(i, max, umVetor);
        max_heapify(umVetor, quantidadeDeElementos, max);
    }
}

void construirHeapMax(Elemento ** umVetor, int tamanho){
    int n = floor(tamanho / 2) - 1;
    for(int i = n; i >= 0; i--) {
        max_heapify(umVetor, tamanho, i);
    }
}
