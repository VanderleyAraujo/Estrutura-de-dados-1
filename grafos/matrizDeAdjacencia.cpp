#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>  // Inclua a biblioteca de pilha

class GrafoMatrizAdj {
private:
    int numVertices;
    std::vector<std::vector<int>> matrizAdj;

public:
    GrafoMatrizAdj(int numVertices) {
        this->numVertices = numVertices;
        matrizAdj.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    void carregarDeArquivo(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
            return;
        }

        // Lê o número de vértices
        arquivo >> numVertices;

        // Redimensiona a matriz para o tamanho adequado
        matrizAdj.resize(numVertices, std::vector<int>(numVertices, 0));

        // Lê a matriz de adjacência do arquivo
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                arquivo >> matrizAdj[i][j];
            }
        }

        arquivo.close();
    }

    void imprimirGrafo() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << matrizAdj[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void BFS(int verticeInicial) {
        std::vector<bool> visitado(numVertices, false);
        std::queue<int> fila;

        // Marca o vértice inicial como visitado e o adiciona à fila
        visitado[verticeInicial] = true;
        fila.push(verticeInicial);

        std::cout << "Busca em Largura a partir do vértice " << verticeInicial << ": ";

        while (!fila.empty()) {
            // Desfila o próximo vértice
            int verticeAtual = fila.front();
            fila.pop();
            std::cout << verticeAtual << " ";

            // Encontra todos os vértices adjacentes ao vértice atual
            for (int i = 0; i < numVertices; ++i) {
                // Se houver uma aresta e o vértice não foi visitado
                if (matrizAdj[verticeAtual][i] != 0 && !visitado[i]) {
                    visitado[i] = true;  // Marca como visitado
                    fila.push(i);         // Adiciona à fila
                }
            }
        }
        std::cout << std::endl;
    }

    void DFS(int verticeInicial) {
        std::vector<bool> visitado(numVertices, false);
        std::stack<int> pilha;  // Usando uma pilha para a DFS

        // Adiciona o vértice inicial à pilha
        pilha.push(verticeInicial);
        std::cout << "Busca em Profundidade a partir do vértice " << verticeInicial << ": ";

        while (!pilha.empty()) {
            // Desempilha o próximo vértice
            int verticeAtual = pilha.top();
            pilha.pop();

            // Se o vértice já foi visitado, continue
            if (visitado[verticeAtual]) {
                continue;
            }

            // Marca o vértice atual como visitado e imprime
            visitado[verticeAtual] = true;
            std::cout << verticeAtual << " ";

            // Encontra todos os vértices adjacentes e os adiciona à pilha
            for (int i = 0; i < numVertices; ++i) {
                // Se houver uma aresta e o vértice não foi visitado
                if (matrizAdj[verticeAtual][i] != 0 && !visitado[i]) {
                    pilha.push(i);  // Adiciona à pilha
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    GrafoMatrizAdj grafo(0);
    grafo.carregarDeArquivo("C:/Users/vanderley/Desktop/ATV de ED/grafos/entradas/pcv10.txt");

    std::cout << "Matriz de Adjacência:" << std::endl;
    grafo.imprimirGrafo();

    // Chama a função BFS a partir do vértice 0
    grafo.BFS(5);

    // Chama a função DFS a partir do vértice 0
    grafo.DFS(5);

    return 0;
}
