#include <iostream>
#include <stdlib.h>
using namespace std;

class No {
    private:
        int dados;
        No* proximo;

    public:
        No() {
            proximo = nullptr;
        }

    int getNo() {
        return dados;
    }

    void setNo(int dado) {
        dados = dado;
    }

    No* getProximo() {
        return proximo;
    }

    void setProximo(No* prox) {
        proximo = prox;
    }
};

class Lista {
    private:
        No* head;
        int tamanho;    

    public:
        Lista() {
            head = nullptr;
            tamanho = 0;
        }

    bool vazia() {
        return (tamanho == 0);
    }
    
    int tamanhoLista() {
        return tamanho;
    }

    int elemento(int pos) {
        No* aux = head;
        int count = 1;

        if (vazia()) {
            return -1;
        }
        if ((pos < 1) || (pos > tamanho)) {
            return -1;
        }

        while (count < pos) {
            aux = aux->getProximo();
            count++;
        }

        return aux->getNo();
    }

    int posicao(int dado) {
        No* aux = head;

        if (vazia()) {
            return -1;
        }

        for (int i = 0; i < tamanho; i++) {
            if (dado == aux->getNo()) {
                return i + 1;
            } else {
                aux = aux->getProximo();
            }
        }

        return -1;
    }

    bool inserirNoInicio(int dado) {
        No* novoNo = new No();
        novoNo->setNo(dado);
        novoNo->setProximo(head);
        head = novoNo;
        tamanho++;
        return true;
    }

    bool inserirNoMeio(int pos, int dado) {
        int cont = 1;
        No* novoNo = new No();
        novoNo->setNo(dado);
        No* aux = head;

        while ((cont < pos - 1) && (aux != nullptr)) {
            aux = aux->getProximo();
            cont++;
        }

        if (aux == nullptr) {
            return false;
        }

        novoNo->setProximo(aux->getProximo());
        aux->setProximo(novoNo);
        tamanho++;
        return true;
    }

    bool inserirNoFim(int dado) {
        No* novoNo = new No();
        novoNo->setNo(dado);
        No* aux = head;

        if (aux == nullptr) { // Caso para lista vazia
            head = novoNo;
        } else {
            while (aux->getProximo() != nullptr) {
                aux = aux->getProximo();
            }
            aux->setProximo(novoNo);
        }
        
        tamanho++;
        return true;
    }

    bool insere(int pos, int dado) {
        if ((vazia()) && (pos != 1)) {
            return false;
        } 
        if (pos == 1) { 
            return inserirNoInicio(dado);
        } else if (pos == tamanho + 1) { // inserção no fim
            return inserirNoFim(dado);
        } else { // inserção no meio da lista
            return inserirNoMeio(pos, dado);
        }
    }

    int removeDoInicio() {
        if (vazia()) {
            return -1;
        }

        No* aux = head;
        int dado = aux->getNo();
        head = aux->getProximo();
        tamanho--;
        delete aux;
        return dado;
    }

    int removeDoMeio(int pos) {
        if (vazia() || pos < 1 || pos > tamanho) {
            return -1;
        }

        int cont = 1;
        int dado;
        No* atual = head;
        No* antecessor = nullptr;

        while ((cont < pos) && (atual != nullptr)) {   
            antecessor = atual;
            atual = atual->getProximo();
            cont++;
        }

        if (atual == nullptr) {
            return -1;
        }
        dado = atual->getNo();
        antecessor->setProximo(atual->getProximo());
        tamanho--;

        delete atual;
        return dado;
    }

    int remove(int pos) {
        if (vazia()) 
            return -1; // Lista vazia
        if (pos == 1) {
            return removeDoInicio();
        } else {
            return removeDoMeio(pos);
        }
    }
};

int main() {
    Lista lista;

    // Inserindo elementos na lista
    lista.insere(1, 10);
    lista.insere(2, 20);
    lista.insere(3, 30);
    lista.insere(2, 25); // Inserir no meio

    // Imprimir os elementos da lista
    cout << "Elementos na lista:" << endl;
    for (int i = 1; i <= lista.tamanhoLista(); i++) {
        cout << lista.elemento(i) << " ";
    }
    cout << endl;

    // Remover um elemento do início
    cout << "Removendo elemento do inicio: " << lista.remove(1) << endl;

    // Remover um elemento do meio
    cout << "Removendo elemento da posicao 2: " << lista.remove(2) << endl;

    // Imprimir os elementos da lista após remoções
    cout << "Elementos na lista apos remocoes:" << endl;
    for (int i = 1; i <= lista.tamanhoLista(); i++) {
        cout << lista.elemento(i) << " ";
    }
    cout << endl;

    return 0;
}
