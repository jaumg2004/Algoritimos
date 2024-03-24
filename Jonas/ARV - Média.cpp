#include <iostream>
#include <iomanip>

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

// Função para calcular a soma dos elementos da árvore
int soma(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return root->data + soma(root->left) + soma(root->right);
}

// Função para calcular o número de elementos da árvore
int contarElementos(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + contarElementos(root->left) + contarElementos(root->right);
}

// Função para calcular a média dos elementos da árvore
float media(Node* root) {
    int somaValores = soma(root);
    int totalElementos = contarElementos(root);

    if (totalElementos == 0) {
        return 0.0;
    }

    return static_cast<float>(somaValores) / totalElementos;
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

    // Cálculo da média e exibição com 2 casas de precisão
    cout << fixed << setprecision(2);
    cout << "Media: " << media(root) << endl;

    return 0;
}
