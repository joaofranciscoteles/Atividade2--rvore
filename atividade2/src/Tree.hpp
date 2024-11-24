#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
using namespace std;

// Estrutura para o nó da árvore
struct NO {
    int item;
    NO *esq;
    NO *dir;
    NO(int valor) : item(valor), esq(nullptr), dir(nullptr) {} // Construtor para inicializar o nó
};

// Classe para a árvore binária
class Tree {
private:
    NO *root; // Raiz da árvore

    // Função recursiva para encontrar o caminho mais longo
    void encontrarCaminhoMaisLongo(NO* no, vector<int>& caminhoAtual, vector<int>& caminhoMaisLongo);

public:
    // Construtor para inicializar a árvore vazia
    Tree();

    // Função para inserir um valor na árvore
    void inserir(int v);

    // Função para obter o caminho mais longo da raiz até a folha mais distante
    vector<int> getCaminhoMaisLongo();

    // Função para calcular o nível máximo da árvore
    int calculaNivelMaximo(NO *no);

    // Função para comparar duas árvores com diferentes ordens de inserção
    static void compararArvores();
};

#endif // TREE_HPP
