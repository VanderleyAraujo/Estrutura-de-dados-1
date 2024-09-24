#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <queue>  // Para a BFS
#include <stack>  // Para a DFS

class GrafoListaAdj {
private:
    int numVertices;
    std::vector<std::list<int>> listaAdj;

public:
    GrafoListaAdj(int numVertices) {
        this->numVertices = numVertices;
        listaAdj.resize(numVertices);
    }

    void adicionarAresta(int origem, int destino) {
        listaAdj[origem].push_back(destino);
        // Para grafo não direcionado, descomente a linha abaixo:
        // listaAdj[destino].push_back(origem);
    }

    void carregarDeArquivo(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
            return;
        }

        // Lê o número de vértices
        arquivo >> numVertices;

        // Redimensiona a lista de adjacência para o tamanho adequado
        listaAdj.resize(numVertices);

        // Lê a matriz de adjacência do arquivo
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                int peso;
                arquivo >> peso;

                // Se houver uma aresta (peso != 0), adiciona na lista de adjacência
                if (peso != 0) {
                    adicionarAresta(i, j);
                }
            }
        }

        arquivo.close();
    }

    void imprimirGrafo() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << i << ":";
            for (auto adj : listaAdj[i]) {
                std::cout << " -> " << adj;
            }
            std::cout << std::endl;
        }
    }

    void BFS(int verticeInicial) {
        std::vector<bool> visitado(numVertices, false);
        std::queue<int> fila;  // Usando uma fila para a BFS

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
            for (auto adj : listaAdj[verticeAtual]) {
                // Se o vértice não foi visitado
                if (!visitado[adj]) {
                    visitado[adj] = true;  // Marca como visitado
                    fila.push(adj);        // Adiciona à fila
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
            for (auto adj : listaAdj[verticeAtual]) {
                if (!visitado[adj]) {
                    pilha.push(adj);  // Adiciona à pilha
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    GrafoListaAdj grafo(0);
    grafo.carregarDeArquivo("C:/Users/vanderley/Desktop/ATV de ED/grafos/entradas/pcv10.txt");

    std::cout << "Lista de Adjacência:" << std::endl;
    grafo.imprimirGrafo();

    // Chama a função BFS a partir do vértice 0
    grafo.BFS(5);

    // Chama a função DFS a partir do vértice 0
    grafo.DFS(5);

    return 0;
}
