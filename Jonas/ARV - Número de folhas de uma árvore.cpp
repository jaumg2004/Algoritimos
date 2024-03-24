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

// Função para contar as folhas da árvore
int contaFolhas(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;  // O nó é uma folha
    }

    // Recursivamente contar as folhas nos subárvores esquerda e direita
    return contaFolhas(root->left) + contaFolhas(root->right);
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

    // Contagem de folhas e exibição do resultado
    cout << contaFolhas(root) << endl;

    return 0;
}
