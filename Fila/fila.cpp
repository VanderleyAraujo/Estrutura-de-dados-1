#include <iostream>
using namespace std;

class Fila
{
private:
    int* dados;
    int tamanhoMaximo;
    int inicio;
    int fim;
    int nElementos;
public:   
    Fila(int tamanhoMax = 100){
        tamanhoMaximo = tamanhoMax;
        dados = new int[tamanhoMaximo];
        inicio = 0;
        fim = -1;
        nElementos = 0;
}
bool vazia(){
    if (nElementos == 0)
    {
        return true;
    }else{
        return false;
    }
}
bool cheia(){
    if (nElementos == tamanhoMaximo)
    {
        return true;
    }else{
        return false;
    }
}
int consultarInicio(){
    if(vazia()){
        return -1;
    }

    return dados[inicio];

}
bool inserir(int dado){
    if (cheia())
    {
        return false;
    }
    
    fim = (fim + 1) % tamanhoMaximo;
    dados[fim] = dado;
    nElementos++;
    return true;
}

int remover(){
    if (vazia())
    {
        return -1;
    }
    
    int dado = dados[inicio];
    inicio = (inicio + 1) % tamanhoMaximo;
    nElementos--;
    return dado;
}
};
int main(){

    Fila fila;
    
    fila.inserir(5);
    fila.inserir(7);
    fila.inserir(3);
    fila.inserir(50);

    cout << "Inicio da fila: " << fila.consultarInicio() << endl;

    cout << "removendo o elemento ..." << endl;

    fila.remover();

    cout << "Novo inicio da fila: " << fila.consultarInicio() << endl;

    return 0;
}