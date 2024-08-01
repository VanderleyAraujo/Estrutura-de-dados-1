#include <iostream>
using namespace std;
class ListaSequencial {
private:
    int* dados;
    int tamanhoAtual;
    int tamanhoMaximo;

public:
    // Construtor
    ListaSequencial(int tamanhoMax = 100) {
        tamanhoMaximo = tamanhoMax;
        tamanhoAtual = 0;
        dados = new int[tamanhoMaximo];
    }

    // Destrutor
    ~ListaSequencial() {
        delete[] dados;
    }

    // Método para verificar se a lista está vazia
    bool vazia() const {
        return (tamanhoAtual == 0);
    }

    //Método para verificar se a lista está cheia
    bool cheia() const{
        if(tamanhoAtual == tamanhoMaximo){
            return true;
        }else{
            return false;
        }

    }

    // Método para saber o tamanho da lista
    int tamanho() const{
        return tamanhoAtual;
    }

    //Método para modificar e obter o elemento de uma determinada posição
    int elemento(int pos) const{
        int dado;
        if((pos > tamanhoAtual) || (pos <=0)){
            return -1;
        }
        dado = dados[pos-1];
        return dado;
    }

    //método para inserir um elemento em uma determinada posição
    bool inserir(int pos, int dado){
         if((cheia()) || (pos > (tamanhoAtual+1)) || (pos <=0)){
            return false;
        }
        for(int i = tamanhoAtual; i >= pos; i--){
            dados[i] = dados[i-1];
        }
            dados[pos-1] = dado;
            tamanhoAtual++;
            return true;
    }
    //Método para remover um dado de uma determinada posição
    int remover(int pos){
         if((vazia()) || (pos > (tamanhoAtual+1)) || (pos <=0)){
            return -1;
        }
        int dado = dados[pos -1];
        for(int i = (pos-1); i < tamanhoAtual-1; i++){
            dados[i] = dados[i+1];
        }
        tamanhoAtual--;
        return dado;
    }
};

int main()
{
    ListaSequencial lista;

    lista.inserir(1, 23);
    lista.inserir(2, 67);
    lista.inserir(3, 91);
    lista.inserir(4, 36);

    cout << "Elemento na posicao 2: " << lista.elemento(2) << endl;

    int removido = lista.remover(2);
    if (removido != -1) {
    cout << "Elemento removido na posicao 2: " << removido << endl;
    } else {
        cout << "Erro ao remover elemento na posicao 2." << endl;
    }

    cout << "Elemento na posicao 2 apos remocao: " << lista.elemento(2) << endl;

    return 0;
}

