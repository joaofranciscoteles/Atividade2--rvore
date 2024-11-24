#include "Tree.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

Tree::Tree() : root(nullptr) {}

void Tree::inserir(int v) {
    NO *novo = new NO(v);
    
    if (root == nullptr) {
        root = novo;
    } else {
        NO *atual = root;
        NO *anterior;
        while (true) {
            anterior = atual;
            if (v <= atual->item) {
                atual = atual->esq;
                if (atual == nullptr) {
                    anterior->esq = novo;
                    break;
                }
            } else {
                atual = atual->dir;
                if (atual == nullptr) {
                    anterior->dir = novo;
                    break;
                }
            }
        }
    }

    vector<int> caminho = getCaminhoMaisLongo();
    cout << "Caminho mais longo após inserção de " << v << ": ";
    for (int item : caminho) {
        cout << item << " ";
    }
    cout << endl;
}

void Tree::encontrarCaminhoMaisLongo(NO* no, vector<int>& caminhoAtual, vector<int>& caminhoMaisLongo) {
    if (no == nullptr) return;

    caminhoAtual.push_back(no->item);

    if (no->esq == nullptr && no->dir == nullptr) {
        if (caminhoAtual.size() > caminhoMaisLongo.size()) {
            caminhoMaisLongo = caminhoAtual;
        }
    } else {
        encontrarCaminhoMaisLongo(no->esq, caminhoAtual, caminhoMaisLongo);
        encontrarCaminhoMaisLongo(no->dir, caminhoAtual, caminhoMaisLongo);
    }

    caminhoAtual.pop_back();
}

vector<int> Tree::getCaminhoMaisLongo() {
    vector<int> caminhoAtual, caminhoMaisLongo;
    encontrarCaminhoMaisLongo(root, caminhoAtual, caminhoMaisLongo);
    return caminhoMaisLongo;
}

void Tree::compararArvores() {
    Tree arvoreDesbalanceada;
    Tree arvoreEquilibrada;

    vector<int> insercoesDesbalanceada = {1, 2, 3, 4, 5, 6, 7};
    vector<int> insercoesEquilibrada = {4, 2, 6, 1, 3, 5, 7};

    cout << "Inserindo valores na árvore desbalanceada:" << endl;
    for (int valor : insercoesDesbalanceada) {
        arvoreDesbalanceada.inserir(valor);
    }

    cout << "\nInserindo valores na árvore mais equilibrada:" << endl;
    for (int valor : insercoesEquilibrada) {
        arvoreEquilibrada.inserir(valor);
    }
}
