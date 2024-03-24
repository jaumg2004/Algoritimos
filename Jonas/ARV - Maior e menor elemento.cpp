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

// Função para encontrar o maior elemento da árvore
int maior(Node* root) {
    if (root == nullptr) {
        cerr << "Erro: Árvore vazia." << endl;
        return -1;  // Retorna um valor inválido para indicar erro
    }

    while (root->right != nullptr) {
        root = root->right;
    }

    return root->data;
}

// Função para encontrar o menor elemento da árvore
int menor(Node* root) {
    if (root == nullptr) {
        cerr << "Erro: Árvore vazia." << endl;
        return -1;  // Retorna um valor inválido para indicar erro
    }

    while (root->left != nullptr) {
        root = root->left;
    }

    return root->data;
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

    // Encontrar o menor e o maior elemento e exibir o resultado
    cout << menor(root) << " e " << maior(root) << endl;

    return 0;
}
