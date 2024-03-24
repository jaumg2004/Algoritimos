#include <iostream>

using namespace std;

// Definição da estrutura de um nó da árvore
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Função para inserir um valor na árvore
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Função para percorrer a árvore em ordem decrescente e adicionar os elementos a um vetor
void percorrerEmOrdemDecrescente(Node* root, int result[], int& index) {
    if (root == nullptr) {
        return;
    }

    // Percorre a subárvore direita (ordem decrescente)
    percorrerEmOrdemDecrescente(root->right, result, index);

    // Adiciona o valor atual ao vetor
    result[index++] = root->data;

    // Percorre a subárvore esquerda (ordem decrescente)
    percorrerEmOrdemDecrescente(root->left, result, index);
}

int main() {
    int num;
    Node* root = nullptr;

    // Leitura dos números e inserção na árvore até que seja lido -1
    cin >> num;
    while (num != -1) {
        root = insert(root, num);
        cin >> num;
    }

    // Inicializa um vetor para armazenar os resultados
    const int MAX_SIZE = 100;  // Tamanho máximo do vetor
    int resultado[MAX_SIZE];
    int index = 0;

    // Percorre a árvore em ordem decrescente e armazena os elementos no vetor
    percorrerEmOrdemDecrescente(root, resultado, index);

    // Exibe a sequência decrescente
    for (int i = 0; i < index; ++i) {
        cout << resultado[i];
        if (i < index - 1) {
            cout << " ";
        }
    }

    return 0;
}
