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

// Função para buscar um valor na árvore
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (value == root->data) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    int N, X;

    // Leitura do número de elementos
    cin >> N;

    Node* root = nullptr;

    // Leitura e inserção dos elementos na árvore
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        root = insert(root, num);
    }

    // Leitura do número a ser procurado
    cin >> X;

    // Verificação se o número está na árvore e exibição da mensagem correspondente
    if (search(root, X)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}
